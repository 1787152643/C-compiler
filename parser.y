%{
#include<stdlib.h>
#include<stdio.h>
#include"util.h"
#include"absyn.h"
#include"symbol.h"
#include"prabsyn.h"

//#define DEBUG

void yyerror(const char*);
int yylex (void);

A_pos pos = 0;

A_stmts root_stmts = NULL;

%}

%union{
  int ival;
  string sval;
  A_stmt stmt;
  A_stmts stmts;
  A_exp exp;
  A_dec dec;
  A_ty ty;
}

%token <ival> NUM
%token <sval> ID
%token IF
%token ELSE
%token WHILE

%type <exp> exp
%type <stmt> stmt
%type <stmts> stmts
%type <dec> var_dec

%start program

%right '='
%left EQ
%left '-' '+'
%left '*' '/'
%left NEG

%%
/*
program: stmt {printf("Reduce program.\n");}

stmt: exp {printf("Reduce stmt.\n");}
    | stmt exp {printf("Reduce stmt by rule 2.\n");}

exp: INT {printf("Reduce INT:%d.\n", $1);}
   | ID  {printf("Reduce ID:%s.\n", $1);}
*/

/*program: exp {printf("final = %d\n", $1);}

exp: INT         {$$ = $1;}
   | exp '+' exp {$$ = $1+$3; printf("%d + %d = %d\n", $1, $3, $$);}
   | exp '-' exp {$$ = $1-$3; printf("%d - %d = %d\n", $1, $3, $$);}*/
   

program: fun_def_list


fun_def_list: fun_def
            | fun_def_list fun_def


fun_def: ID ID'('var_dec_seq')''{'stmts'}'
       {
         root_stmts = A_reverseStmts($7);
       }

/* valua declaration lists used for function definition */
var_dec_seq: /*empty*/
            | var_dec_seq1

var_dec_seq1: var_dec
             | var_dec_seq1',' var_dec

/* simple valua declaration */
var_dec: ID ID
       {
         $$ = A_VarDec(pos, S_Symbol($2), S_Symbol($1), 0);
       }
       | ID ID '=' exp
       {
         $$ = A_VarDec(pos, S_Symbol($2), S_Symbol($1), $4);
       }

/*
exp_list: exp';'             {printf("Reduce exp_list by rule 1.\n");}
        | exp_list exp';'    {printf("Reduce exp_list by rule 2.\n");}
*/

/* statements including expression and declaration */
stmts: stmt
     {
      $$ = A_Stmts($1, NULL);
     }
     | stmts stmt
     {
      // warning!! there is a reverse link list.
      $$ = A_Stmts($2, $1);
     }

stmt: exp';'
    {
      $$ = A_ExpStmt(pos, $1);
    }
    | var_dec';'
    {
      $$ = A_DecStmt(pos, $1);
    }
    | IF'('exp')''{'stmts'}'
    {
      $$ = A_IfStmt(pos, $3, $6, NULL);
    }
    | IF'('exp')''{'stmts'}'ELSE'{'stmts'}'
    {
      $$ = A_IfStmt(pos, $3, A_reverseStmts($6), A_reverseStmts($10));
    }
    | WHILE'('exp')''{'stmts'}'
//    | '{'stmts'}'

/* expression sequence used for function calls.*/
exp_seq: exp
        | exp_seq',' exp

/* expression */
exp: /*empty expression */
   | ID /*identifier*/
   {
      #ifdef DEBUG
      printf("Found exp ID:%s\n", $1);
      #endif
      $$ = A_VarExp(pos, A_SimpleVar(pos, S_Symbol($1)));
   }
   | NUM /*number*/   
   {
      #ifdef DEBUG
      printf("Found exp INT:%d\n", $1);
      #endif
      $$ = A_IntExp(pos, $1);
   }
   | ID '=' exp   /* assignment */
   {
      $$ = A_AssignExp(pos, A_SimpleVar(pos, S_Symbol($1)), $3);
   }
   | exp '+' exp 
   {
      $$ = A_OpExp(pos, A_plusOp, $1, $3);
   }
   | exp '-' exp
   {
      $$ = A_OpExp(pos, A_minusOp, $1, $3);
   }
   | exp '*' exp
   {
      $$ = A_OpExp(pos, A_timesOp, $1, $3);
   }
   | exp '/' exp
   {
      $$ = A_OpExp(pos, A_divideOp, $1, $3);
   }
   /*| '-' exp %prec NEG
   {}*/
   | exp EQ exp
   {
      $$ = A_OpExp(pos, A_eqOp, $1, $3);
   }
   | ID'('exp_seq')'  /* function call */
   {
      printf("No implementation of function call.\n");
   }

%%

void yyerror(const char* s){
	printf("%s\n", s);
}