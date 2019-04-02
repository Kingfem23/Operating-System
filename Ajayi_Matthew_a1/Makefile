all: msh
msh: my_shell.o lex.yy.o myshellFunctions.o
	gcc -o msh my_shell.o lex.yy.o myshellFunctions.o -ll
my_shell.o: my_shell.c
	gcc -Wall -g -c my_shell.c
lex.yy.o: lex.yy.c
	gcc -Wall -g -c lex.yy.c
lex.yy.c: lex.c
	flex lex.c
myshellFunctions.o: myshellFunctions.c
	gcc -Wall -g -c myshellFunctions.c
clean:
	rm -f *.o
	rm -f lex.yy.c
	rm -f msh
	