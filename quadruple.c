
#include "quadruple.h"
#include "util.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

quadrupleList end;
quadrupleList begin;

int nextquad = 1;

static struct Q_type_ qtyint = {Q_int};

Q_type Q_Int(void){return &qtyint;}

Q_type Q_Pointer(Q_type inner){
    Q_type p = checked_malloc(sizeof(*p));
    p->kind = Q_pointer;
    p->u.points = inner;
    return p;
}

int Q_typeEqual(Q_type t1, Q_type t2){
    if(t1==t2)
        return 1;
    if(t1->kind==Q_pointer && t2->kind==Q_pointer)
        return Q_typeEqual(t1->u.points, t2->u.points);
    else
        return 0;
}

Q_declarator Q_Declarator(char* name, Q_type type){
    Q_declarator p = checked_malloc(sizeof(*p));
    p->name = name;
    p->type = type;
    return p;
}

Q_operand Q_VarOperand(char* name, Q_addr addr){
    Q_operand op = checked_malloc(sizeof(*op));
    op->kind = Q_varOp;
    op->type = Q_Int();
    op->u.var.name = name;
    op->u.var.addr = addr;
    return op;
}

/*
Q_operand Q_TempOperand(int id, Q_addr addr){
    Q_operand op = checked_malloc(sizeof(*op));
    op->kind = Q_tempOp;
    op->u.temp.id = id;
    op->u.temp.addr = addr;
    return op;
}
*/

Q_operand Q_TempOperand(){
    static int next_id = 1;
    Q_operand op = checked_malloc(sizeof(*op));
    op->kind = Q_tempOp;
    op->type = Q_Int();
    op->u.temp.id = next_id++;
    op->u.temp.addr = find_free();
    return op;
}

Q_operand Q_ImmOperand(int value){
    Q_operand op = checked_malloc(sizeof(*op));
    op->kind = Q_immOp;
    op->type = Q_Int();
    op->u.imm.value = value;
    return op;
}

Q_operand Q_RefOperand(Q_operand mem_addr, Q_type type){
    Q_operand op = checked_malloc(sizeof(*op));
    op->kind = Q_refOp;
    op->type = type;
    //op->u.ref.value = 0;
    op->u.ref.mem_addr = mem_addr;
    op->u.ref.addr = find_free();
    return op;
}

Q_exp Q_Exp(Q_operand result){
    Q_exp exp = checked_malloc(sizeof(*exp));
    exp->result = result;
    return exp;
}

Q_stmt Q_Stmt(){
    Q_stmt stmt = checked_malloc(sizeof(*stmt));
    stmt->nextList = NULL;
    return stmt;
}

Q_condition Q_Condition(){
    Q_condition con = checked_malloc(sizeof(*con));
    con->falseList = NULL;
    con->trueList = NULL;
    return con;
}

void backpatch(quadrupleList p, int instr){
    while(p){
        assert(p->tail->dest==NULL);
        p->tail->dest = Q_ImmOperand(instr);
        p = p->head;
    }
}
quadrupleList merge(quadrupleList p1, quadrupleList p2){
    if(p1==NULL) return p2;
    quadrupleList r = p1;
    while(p1->head){
        p1 = p1->head;
    }
    p1->head = p2;
    return r;
}
quadrupleList makelist(quadruple q){
    quadrupleList r = checked_malloc(sizeof(*r));
    r->tail = q;
    r->head = NULL;
    return r;
}

Q_addr find_free(){
    Q_addr addr;
    // test
    addr.reg = 0;
    return addr;
}

void quadruple_init(){
    end = checked_malloc(sizeof(*end));
    end->head = NULL;
    end->tail = checked_malloc(sizeof(*(end->tail)));
    end->tail->addr = 0;
    begin = end;
}

quadruple gen(Q_operator operator, Q_operand op1, Q_operand op2, Q_operand dest){
    quadrupleList code = checked_malloc(sizeof(*code));
    code->head = 0;
    code->tail = checked_malloc(sizeof(*(code->tail)));
    code->tail->addr = nextquad++;
    code->tail->operator = operator;
    code->tail->op1 = op1;
    code->tail->op2 = op2;
    code->tail->dest = dest;
    end->head = code;
    end = code;
    return code->tail;
}

static void operand2string(Q_operand op, char* s)
{
    if(op == NULL) {sprintf(s, "_"); return;}
    switch(op->kind){
        case Q_varOp: 
            sprintf(s, "%s", op->u.var.name);
            break;
        case Q_tempOp: 
            sprintf(s, "T%d", op->u.temp.id);
            break;
        case Q_immOp: 
            sprintf(s, "%d", op->u.imm.value);
            break;
        case Q_refOp:
        // warning
            if(op->u.ref.mem_addr->kind==Q_varOp)
                sprintf(s, "*%s", op->u.ref.mem_addr->u.var.name);
            else{
                operand2string(op->u.ref.mem_addr, s+1);
                s[0]='*';
            }
            break;
    }
}

void printQuads()
{	
    quadrupleList p = begin->head;
    char *operators[] = {"+", "-", "*", "/", "==", "!=", "<", "<=", ">", ">=", ":=", 
    "b", "beq", "bne", "blt", "ble", "bgt", "bge", "*"};
    while(p){
        char op1_s[10] ;operand2string(p->tail->op1, op1_s);
        char op2_s[10] ;operand2string(p->tail->op2, op2_s);
        char dest_s[10] ;operand2string(p->tail->dest, dest_s);
        printf("(%2d)(%3s, %3s, %3s, %3s)\n",p->tail->addr, operators[p->tail->operator], op1_s, op2_s, dest_s);
        p = p->head;
    }
}
