%{
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"util.h"
#include"absyn.h"
#include"symbol.h"
#include"prabsyn.h"
#include"quadruple.h"

#define DEBUG

void yyerror(const char*);
int yylex (void);

A_pos pos = 0;

int line = 1;

A_stmts root_stmts = NULL;

S_table var_table = NULL;

extern int nextquad;

%}

%union{
  int ival;
  string sval;
  Q_stmt stmt;
  //Q_stmts stmts;
  Q_declarator dctor;
  Q_exp exp;
  Q_condition con;
  Mtype m;
  A_dec dec;
  A_ty ty;
}

%token <ival> NUM
%token <sval> ID
%token IF
%token ELSE
%token WHILE
%token INT
%token AND OR
%token EQ NE LT LE GT GE

%type <exp> exp
%type <stmt> stmt
%type <stmt> stmts
%type <dec> var_dec
%type <dctor> declarator
%type <con> condition
%type <m> M
%type <stmt> N

%start program

%left OR
%left AND
%left '!'
%right '='
%left EQ NE LT LE GT GE
%left '-' '+'
%left '*' '/'
%left NEG
%left STAR

%%

program: fun_def_list


fun_def_list: fun_def
            | fun_def_list fun_def


fun_def: ID ID'('var_dec_seq')''{'stmts'}'
       {
         //root_stmts = A_reverseStmts($7);
         free($7);
       }

/* valua declaration lists used for function definition */
var_dec_seq: /*empty*/
            | var_dec_seq1

var_dec_seq1: var_dec
             | var_dec_seq1',' var_dec

/* simple valua declaration */
var_dec: 
         INT declarator
       {
         //$$ = A_VarDec(pos, S_Symbol($2), S_Symbol($1), 0);
         S_symbol sym = S_Symbol($2->name);
         Q_addr addr = find_free();
         Q_operand op = Q_VarOperand($2->name, addr);
         op->type = $2->type;
         S_enter(var_table, sym, op);
       }
       | INT ID '=' exp
       {
         //$$ = A_VarDec(pos, S_Symbol($2), S_Symbol($1), $4);
         S_symbol sym = S_Symbol($2);
         Q_addr addr = find_free();
         Q_operand op = Q_VarOperand($2, addr);
         S_enter(var_table, sym, op);
         gen(Q_assignOp, $4->result, NULL, op);
       }

declarator:
      ID
      {
         $$ = Q_Declarator($1, Q_Int());
      }
      | '*'declarator
      {
         Q_type inner = $2->type;
         $$ = Q_Declarator($2->name, Q_Pointer(inner));
      }

/*ID ID
       {
         //$$ = A_VarDec(pos, S_Symbol($2), S_Symbol($1), 0);
         if(strcmp($1, "int")==0){
            S_symbol sym = S_Symbol($2);
            Q_addr addr = find_free();
            Q_operand op = Q_VarOperand($2, addr);
            S_enter(var_table, sym, op);
         }else{
            yyerror("only support int now.");
         }

       }
       | ID ID '=' exp
       {
         //$$ = A_VarDec(pos, S_Symbol($2), S_Symbol($1), $4);
         if(strcmp($1, "int")==0){
            S_symbol sym = S_Symbol($2);
            Q_addr addr = find_free();
            Q_operand op = Q_VarOperand($2, addr);
            S_enter(var_table, sym, op);
            gen(Q_assignOp, $4->result, NULL, op);
         }else{
            yyerror("only support int now.");
         }
       }*/
/*
exp_list: exp';'             {printf("Reduce exp_list by rule 1.\n");}
        | exp_list exp';'    {printf("Reduce exp_list by rule 2.\n");}
*/

/* statements including expression and declaration */
stmts: stmt
     {
      $$ = $1;
     }
     | stmts M stmt
     {
      $$ = Q_Stmt();
      backpatch($1->nextList, $2->instr);
      $$->nextList = $3->nextList;
      free($1); free($2); free($3);
     }

stmt: /* empty stmt */';'
    {
      $$ = Q_Stmt();
    }
    | exp';'
    {
      //$$ = A_ExpStmt(pos, $1);
      $$ = Q_Stmt();
    }
    | var_dec';'
    {
      //$$ = A_DecStmt(pos, $1);
      $$ = Q_Stmt();
    }
    | IF'('condition')'M bs'{'stmts'}'es
    {
      //$$ = A_IfStmt(pos, $3, $6, NULL);
      $$ = Q_Stmt();
      backpatch($3->trueList, $5->instr);
      $$->nextList = merge($3->falseList, $8->nextList);
      free($3); free($8);
    }
    | IF'('condition')'M bs'{'stmts'}'es N ELSE M bs'{'stmts'}'es
    {
      //$$ = A_IfStmt(pos, $3, A_reverseStmts($6), A_reverseStmts($10));
      $$ = Q_Stmt();
      backpatch($3->trueList, $5->instr);
      backpatch($3->falseList, $13->instr);
      quadrupleList temp = merge($8->nextList, $11->nextList);
      $$->nextList = merge(temp, $16->nextList);
      free($3); free($5); free($8); free($11); free($13); free($16);
    }
    | WHILE M'('condition')'M bs'{'stmts'}'es
    {
      $$ = Q_Stmt();
      backpatch($9->nextList, $2->instr);
      backpatch($4->trueList, $6->instr);
      $$->nextList = $4->falseList;
      gen(Q_bOp, NULL, NULL, Q_ImmOperand($2->instr));
      free($2); free($4); free($6); free($9);
    }
    /*| error
   {
      fprintf(stderr, "Syntax error when parsing stmt in line %d.\n", line);
      yyerrok;
   }*/
//    | '{'stmts'}'

/* conditional expression! */
condition:
     condition OR M condition
   {
      $$ = Q_Condition();
      backpatch($1->falseList, $3->instr);
      $$->trueList = merge($1->trueList, $4->trueList);
      $$->falseList = $4->falseList;
      free($3); free($1); free($4);
   }
   | condition AND M condition
   {
      $$ = Q_Condition();
      printf("AND\n");
      backpatch($1->trueList, $3->instr);
      $$->trueList = $4->trueList;
      $$->falseList = merge($1->falseList, $4->falseList);
      free($3); free($1); free($4);
   }
   | '!'condition
   {
      $$ = Q_Condition();
      $$->trueList = $2->falseList;
      $$->falseList = $2->trueList;
      free($2);
   }
   | '('condition')'
   {
      $$ = $2;
   }
   | exp EQ exp
   {
      $$ = Q_Condition();
      $$->trueList = makelist(gen(Q_beqOp, $1->result, $3->result, NULL));
      $$->falseList = makelist(gen(Q_bOp, NULL, NULL, NULL));
   }
   | exp NE exp
   {
      $$ = Q_Condition();
      $$->trueList = makelist(gen(Q_bneOp, $1->result, $3->result, NULL));
      $$->falseList = makelist(gen(Q_bOp, NULL, NULL, NULL));
   }
   | exp LT exp
   {
      $$ = Q_Condition();
      $$->trueList = makelist(gen(Q_bltOp, $1->result, $3->result, NULL));
      $$->falseList = makelist(gen(Q_bOp, NULL, NULL, NULL));
   }
   | exp LE exp
   {
      $$ = Q_Condition();
      $$->trueList = makelist(gen(Q_bleOp, $1->result, $3->result, NULL));
      $$->falseList = makelist(gen(Q_bOp, NULL, NULL, NULL));
   }
   | exp GT exp
   {
      $$ = Q_Condition();
      $$->trueList = makelist(gen(Q_bgtOp, $1->result, $3->result, NULL));
      $$->falseList = makelist(gen(Q_bOp, NULL, NULL, NULL));
   }
   | exp GE exp
   {
      $$ = Q_Condition();
      $$->trueList = makelist(gen(Q_bgeOp, $1->result, $3->result, NULL));
      $$->falseList = makelist(gen(Q_bOp, NULL, NULL, NULL));
   }
   | error
   {
      $$ = Q_Condition();
      fprintf(stderr, "Syntax error when parsing condition in line %d\n", line);
      yyerrok;
   }

M: /* empty */
  {
   $$ = checked_malloc(sizeof(*$$));
   $$->instr = nextquad;
  }
N: /* empty */
  {
   $$ = Q_Stmt();
   $$->nextList = makelist(gen(Q_bOp, NULL, NULL, NULL));
  }
bs: /* empty */
  {
   S_beginScope(var_table);
  }
es:
  {
   S_endScope(var_table);
  }

/* expression sequence used for function calls.*/
exp_seq: exp
        | exp_seq',' exp

/* expression */
exp: 
     ID /*identifier*/
   {
#ifdef DEBUG
      printf("Found exp ID:%s\n", $1);
#endif
      // $$ = A_VarExp(pos, A_SimpleVar(pos, S_Symbol($1)));
      S_symbol sym = S_Symbol($1);
      Q_operand op = S_look(var_table, sym);
      if(op==NULL) fprintf(stderr, "Undefined variable: %s\n", $1);
      $$ = Q_Exp(op);
   }
   | NUM /*number*/   
   {
#ifdef DEBUG
      printf("Found exp INT:%d\n", $1);
#endif
      //$$ = A_IntExp(pos, $1);
      $$ = Q_Exp(Q_ImmOperand($1));
   }
   | ID '=' exp   /* assignment */
   {
      //$$ = A_AssignExp(pos, A_SimpleVar(pos, S_Symbol($1)), $3);
      //Q_operand temp = Q_TempOperand();
      S_symbol sym = S_Symbol($1);
      Q_operand dest = S_look(var_table, sym);
      if(dest==NULL) fprintf(stderr, "Undefined variable: %s\n", $1);
      gen(Q_assignOp, $3->result, NULL, dest);
      $$ = Q_Exp(dest);
   }
   | exp '+' exp 
   {
      //$$ = A_OpExp(pos, A_plusOp, $1, $3);
      Q_operand dest = Q_TempOperand();
      gen(Q_plusOp, $1->result, $3->result, dest);
      $$ = Q_Exp(dest);
   }
   | exp '-' exp
   {
      //$$ = A_OpExp(pos, A_minusOp, $1, $3);
      Q_operand dest = Q_TempOperand();
      gen(Q_minusOp, $1->result, $3->result, dest);
      $$ = Q_Exp(dest);
   }
   | exp '*' exp
   {
      //$$ = A_OpExp(pos, A_timesOp, $1, $3);
      Q_operand dest = Q_TempOperand();
      gen(Q_timesOp, $1->result, $3->result, dest);
      $$ = Q_Exp(dest);
   }
   | exp '/' exp
   {
      //$$ = A_OpExp(pos, A_divideOp, $1, $3);
      Q_operand dest = Q_TempOperand();
      gen(Q_divideOp, $1->result, $3->result, dest);
      $$ = Q_Exp(dest);
   }
   /*| '-' exp %prec NEG
   {}*/
   /*| exp EQ exp
   {
      //$$ = A_OpExp(pos, A_eqOp, $1, $3);
      Q_operand dest = Q_TempOperand();
      gen(Q_eqOp, $1->result, $3->result, dest);
      $$ = Q_Exp(dest);
   }*/
   | '*'exp %prec STAR
   {
      Q_type type;
      if($2->result->type->kind==Q_pointer){
         type = $2->result->type->u.points;
      }else{
         yyerror("warning");
         type = Q_Int();
      }
      Q_operand dest = Q_RefOperand($2->result, type);
      gen(Q_starOp, $2->result, NULL, dest);
      $$ = Q_Exp(dest);
   }
   | ID'('exp_seq')'  /* function call */
   {
      printf("No implementation of function call.\n");
   }
   | error
   {
      fprintf(stderr, "Syntax error when parsing expression in line %d\n", line);
      yyerrok;
   }

%%

void yyerror(const char* s){
	fprintf(stderr, "%s\n", s);
}
