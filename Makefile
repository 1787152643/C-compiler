a.out: util.o parser.tab.o lex.yy.o main.o
	cc -g util.o parser.tab.o lex.yy.o main.o

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
	rm -f a.out main.o util.o parser.tab.o parser.tab.c parser.tab.h lex.yy.o lex.yy.c
