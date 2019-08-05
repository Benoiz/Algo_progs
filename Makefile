CC=gcc
CFLAGS=-Wall
DEPS = algo.h

rand: rand.c
	gcc -Wall -o rand rand.c

double_num: double_num.c 
	gcc -Wall -o double_num double_num.c

my_sort: my_sort.c utils.c
	gcc -Wall -o my_sort my_sort.c utils.c