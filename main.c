#include<stdio.h>
#include<stdlib.h>
#include"util.h"
#include"absyn.h"
#include"prabsyn.h"
#include"translate.h"
#include"parser.tab.h"

extern int yyparse(void);

extern FILE *yyin;

extern A_stmts root_stmts;

void parse(const char* fname)
{
	yyin = fopen(fname,"r");
	if (!yyin) {fprintf(stderr,"cannot open!\n"); exit(1);}
	if (yyparse() == 0) /* parsing worked */
   		fprintf(stderr,"Parsing successful!\n");
 	else fprintf(stderr,"Parsing failed\n");
}

int main(int argc, char** argv)
{
	if (argc!=2) {fprintf(stderr,"usage: a.out filename\n"); exit(1);}
 	parse(argv[1]);
	pr_stmts(stdout, root_stmts, 0);
	translate(stdout, root_stmts);
 	return 0;
}
