%{
#include<stdlib.h>
#include<stdio.h>
#include"util.h"

#define DEBUG

void yyerror(const char*);
int yylex (void);

%}

%union{
  int ival;
  string sval;
}

%token <ival> NUM
%token <sval> ID
%token IF
%token ELSE
%token WHILE

%type <ival> exp

%start program

%right '='
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

/* valua declaration lists used for function definition */
var_dec_seq: /*empty*/
            | var_dec_seq1

var_dec_seq1: var_dec
             | var_dec_seq1',' var_dec

/* simple valua declaration */
var_dec: ID ID 
       | ID ID '=' exp 

/* statements including expression and declaration */
stmts: stmt
     | stmts stmt

stmt: exp';'
    | var_dec';'
    | IF'('exp')''{'stmts'}'
    | IF'('exp')''{'stmts'}'ELSE'{'stmts'}'
    | WHILE'('exp')''{'stmts'}'
//    | '{'stmts'}'

/* expression sequence used for function calls.*/
exp_seq: exp
        | exp_seq',' exp

/* expression */
exp: /*empty expression */
   | ID              /*identifier*/
   | NUM             /*number*/
   | ID '=' exp      /* assignment */
   | exp '+' exp 
   | exp '-' exp
   | exp '*' exp
   | exp '/' exp
   | '-' exp %prec NEG
   | ID'('exp_seq')' /* function call */


%%

void yyerror(const char* s){
	printf("%s\n", s);
}