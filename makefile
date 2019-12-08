main:	main.o avl.o
	gcc	main.o	avl.o	main	-Wall	-Wextra	-Werror	Wpedantic	-lm
main.o:	main.c
	gcc	-c	main.c	-o	main.o	-Wall	-Wextra	-Werror	Wpedantic
avl.o: avl.c
	gcc	-c	avl.c -o avl.o	-Wall	-Wextra	-Werror	Wpedantic
clear:
	rm -rf *.o
mrproper:	clean
