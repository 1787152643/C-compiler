#include<stdlib.h>
#include<stdio.h>
#include"util.h"
#include"absyn.h"
#include"symbol.h"
#include"prabsyn.h"
#include"types.h"

#define UNUSED 0
#define USED 1
#define TEMP 2

typedef int reg;

static reg regArray[32] = {};

struct binding_{
    Ty_ty type;
    reg reg;
};

typedef struct binding_ *binding;

static reg findFree(void);
static int transStmts(FILE *out, S_table venv, S_table tenv, A_stmts stmts);
static int transStmt(FILE *out, S_table venv, S_table tenv, A_stmt stmt);
static reg transExp(FILE *out, S_table venv, S_table tenv, A_exp exp);

static binding Binding(Ty_ty type, reg reg){
    binding p = checked_malloc(sizeof(*p));
    p->type=type;
    p->reg=reg;
    return p;
}

static reg findFree(void)
{
    for(reg i = 16;i<32;++i){
        if(regArray[i]==UNUSED)
            return i;
    }
    printf("No free register.\n");
    return -1;
}

int translate(FILE *out, A_stmts stmts)
{
    S_table venv = S_empty();
    S_table tenv = S_empty();
    S_enter(tenv, S_Symbol("int"), Ty_Int());
    transStmts(out, venv, tenv, stmts);
    for(int i=16;i<32;++i){
        printf("%d ", regArray[i]);
    }
}

static int transStmts(FILE *out, S_table venv, S_table tenv, A_stmts stmts)
{
    if(stmts==0)
        return 0;
    transStmt(out, venv, tenv, stmts->head);
    transStmts(out, venv, tenv, stmts->tail);
    return 0;
}

static int transDec(FILE* out, S_table venv, S_table tenv, A_dec dec){
            switch(dec->kind){
                case A_functionDec:
                    printf("No nested function!\n");
                    break;
                case A_varDec:
                    reg r = findFree();
                    if(r==-1)return r;
                    regArray[r] = USED;
                    Ty_ty ty = S_look(tenv, dec->u.var.typ);
                    S_enter(venv, dec->u.var.var, Binding(ty, r));
                    fprintf(out, "/* %s in x%d */\n", S_name(dec->u.var.var), r);
                    if(dec->u.var.init){
                        if(dec->u.var.init->kind==A_intExp){
                            fprintf(out, "li x%d, %d\n", r, dec->u.var.init->u.intt);
                        }else{
                        reg ir = transExp(out, venv, tenv, dec->u.var.init);
                        fprintf(out, "add x%d, x%d, x0\n", r, ir);
                        if(regArray[ir]==TEMP)regArray[ir]=UNUSED;
                        }
                    }
                    break;
                case A_typeDec:
                default:printf("No implementation.\n");break;
            }
    return 0;
}

static int transStmt(FILE *out, S_table venv, S_table tenv, A_stmt stmt)
{
    switch(stmt->kind){
        case A_decStmt:
            transDec(out, venv, tenv, stmt->u.dec);
            break;
        case A_expStmt:
            A_exp exp = stmt->u.exp;
            reg r = transExp(out, venv, tenv, exp);
            if(regArray[r]==TEMP)regArray[r]=UNUSED;
            break;
        case A_ifStmt:
        default: printf("No implementation in transStmt.\n");break;
    }
    return 0;
}

static reg transOpExp(FILE *out, S_table venv, S_table tenv, A_exp exp)
{
    A_oper op = exp->u.op.oper;
    A_exp left = exp->u.op.left;
    A_exp right = exp->u.op.right;
    reg r = findFree();
    if(r==-1)return r;
    regArray[r]=TEMP;
    if(left->kind==A_intExp&&left->kind==A_intExp){
        fprintf(out, "addi x%d, x0, %d\n", r, left->u.intt+right->u.intt);
    }else if(left->kind==A_intExp){
        reg ir = transExp(out, venv, tenv, right);
        fprintf(out, "addi x%d, x%d, %d\n", r, ir, left->u.intt);
        if(regArray[ir]==TEMP)regArray[ir]=UNUSED;
    }else if(right->kind==A_intExp){
        reg ir = transExp(out, venv, tenv, left);
        fprintf(out, "addi x%d, x%d, %d\n", r, ir, right->u.intt);
        if(regArray[ir]==TEMP)regArray[ir]=UNUSED;
    }else{
        reg r1 = transExp(out, venv, tenv, left), r2 = transExp(out, venv, tenv, right);
        fprintf(out, "add x%d, x%d, x%d\n", r, r1, r2);
        if(regArray[r1]==TEMP)regArray[r1]=UNUSED;
        if(regArray[r2]==TEMP)regArray[r2]=UNUSED;
    }
    return r;
}

static reg transExp(FILE *out, S_table venv, S_table tenv, A_exp exp)
{
    binding b;
    reg r, ir;
    switch(exp->kind){
        case A_varExp:
            b = S_look(venv, exp->u.var->u.simple);
            if(!b){printf("Undefined variable: %s\n", S_name(exp->u.var->u.simple)); return -1;}
            return b->reg;
        case A_opExp:
            r = transOpExp(out, venv, tenv, exp);
            return r;
        case A_assignExp:
            b = S_look(venv, exp->u.var->u.simple);
            if(!b){printf("Undefined variable: %s\n", S_name(exp->u.var->u.simple)); return -1;}
            r = b->reg;
            ir = transExp(out, venv, tenv, exp->u.assign.exp);
            fprintf(out, "addi x%d, x%d, x0\n", r, ir);
            if(regArray[ir]==TEMP)regArray[ir]=UNUSED;
            return r;
        default:
            printf("No implementation in transExp.\n");
    }
}