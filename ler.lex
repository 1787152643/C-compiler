%{
#include<math.h>
#include"util.h"
#include"absyn.h"
#include"parser.tab.h"

#define LEX_DEBUG

extern A_pos pos;

%}

%option noyywrap

DIGIT [0-9]
ID    [a-zA-Z][a-zA-Z0-9]*


%%

if        {
          #ifdef LEX_DEBUG
          printf("IF\n");
          #endif
          pos+=yyleng;
          return IF;}

else      {
          pos+=yyleng;return ELSE;}

while     {pos+=yyleng;return WHILE;}

{DIGIT}+  {
          #ifdef LEX_DEBUG
          printf("An integer:%s (%d)\n", yytext, atoi(yytext));
          #endif
          yylval.ival = atoi(yytext);
          pos+=yyleng;
          return NUM;
          }

{ID}      {
          #ifdef LEX_DEBUG
          printf("An identifier:%s\n", yytext);
          #endif
          yylval.sval = String(yytext);
          pos+=yyleng;
          return ID;
          }

==        {
          #ifdef LEX_DEBUG
          printf("EQ\n");
          #endif
          pos+=yyleng;
          return EQ;}

[+\-*/=]  {
          #ifdef LEX_DEBUG
          printf("detect operator:%s\n", yytext); 
          #endif
          pos+=yyleng;
          return *yytext;
          }

[(){},.;] {
          #ifdef LEX_DEBUG
          printf("detect punctuation:%s\n", yytext); 
          #endif
          pos+=yyleng;
          return *yytext;
          }

[ \n\t]+  {pos+=yyleng;continue;}

.         {pos+=yyleng;printf("Unrecognized: %s\n", yytext);}


