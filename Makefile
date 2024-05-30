a.out: util.o table.o symbol.o absyn.o prabsyn.o types.o translate.o parser.tab.o main.o lex.yy.o
	cc -g util.o table.o symbol.o absyn.o prabsyn.o types.o translate.o parser.tab.o main.o lex.yy.o
	
translate.o:util.h absyn.h symbol.h prabsyn.h types.h translate.h translate.c
	cc -g -c translate.c

types.o:util.h symbol.h types.h types.c
	cc -g -c types.c

prabsyn.o:util.h symbol.h absyn.h prabsyn.h prabsyn.c
	cc -g -c prabsyn.c

absyn.o: util.h symbol.h symbol.h absyn.c
	cc -g -c absyn.c

symbol.o: util.h symbol.c symbol.h table.h
	cc -g -c symbol.c

table.o: table.c table.h
	cc -g -c table.c

main.o: main.c util.c
	cc -g -c main.c

util.o: util.c util.h
	cc -g -c util.c

parser.tab.o: parser.tab.c util.h
	cc -g -c parser.tab.c
	
parser.tab.c: parser.y
	bison -dv parser.y

parser.tab.h: parser.tab.c
	echo "parser.tab.h was created at the same time as parser.tab.c"

lex.yy.o: lex.yy.c util.h
	cc -g -c lex.yy.c

lex.yy.c: ler.lex
	lex ler.lex

clean:
	rm -f a.out main.o util.o parser.tab.o parser.tab.c parser.tab.h parser.output lex.yy.o lex.yy.c absyn.o symbol.o table.o prabsyn.o types.o translate.o
