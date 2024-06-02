%{
#include<math.h>
#include"util.h"
#include"absyn.h"
#include"quadruple.h"
#include"parser.tab.h"

//#define LEX_DEBUG

extern A_pos pos;

extern int line;

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

"&&"      {pos+=yyleng;return AND;}

"||"      {pos+=yyleng;return OR;}

"=="        {
          #ifdef LEX_DEBUG
          printf("EQ\n");
          #endif
          pos+=yyleng;
          return EQ;}
"!="        {pos+=yyleng; return NE;}

"<"         {pos+=yyleng;
          printf("LT\n");
          return LT;}

"<="        {pos+=yyleng; return LE;}

">"         {pos+=yyleng; return GT;}

">="        {pos+=yyleng; return GE;}


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

[+\-*/=!]  {
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

[ ]+      {pos+=yyleng; continue;}

[\n\t]+  {pos+=yyleng; line++; continue;}

.         {pos+=yyleng;printf("Unrecognized: %s\n", yytext);}


