CC=gcc
CFLAGS=-Wall
DEPS = algo.h

rand: rand.c
	gcc -o rand rand.c

double_num: double_num.c utils.c 
	gcc -o double_num double_num.c utils.c

my_sort: my_sort.c utils.c
	gcc -o my_sort my_sort.c utils.c