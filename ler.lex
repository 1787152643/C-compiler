%{
#include<math.h>
#include"util.h"
#include"parser.tab.h"

//#define LEX_DEBUG

%}

%option noyywrap

DIGIT [0-9]
ID    [a-zA-Z][a-zA-Z0-9]*


%%

IF        {return IF;}

ELSE      {return ELSE;}

WHILE     {return WHILE;}

{DIGIT}+  {
          #ifdef LEX_DEBUG
          printf("An integer:%s (%d)\n", yytext, atoi(yytext));
          #endif
          yylval.ival = atoi(yytext);
          return NUM;
          }

{ID}      {
          #ifdef LEX_DEBUG
          printf("An identifier:%s\n", yytext);
          #endif
          yylval.sval = String(yytext);
          return ID;
          }

[+\-*/=]  {
          #ifdef LEX_DEBUG
          printf("detect operator:%s\n", yytext); 
          #endif
          return *yytext;
          }

[(){},.;] {
          #ifdef LEX_DEBUG
          printf("detect punctuation:%s\n", yytext); 
          #endif
          return *yytext;
          }

[ \n\t]+  {continue;}

.         {printf("Unrecognized: %s\n", yytext);}


