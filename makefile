a.out: avl.o
    gcc -Wall -Wextra -Werror -Wpedantic  main.c avl.o

avl.o: avl.c
    gcc -Wall -Wextra -Werror -Wpedantic -c avl.c -o avl.o
clear:
    rm -rf *.o
mrproper:    clean
