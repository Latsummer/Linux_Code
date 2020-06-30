#我的第一个makefile文件
.PHONY:clean
CC = gcc
SRCS = $(wildcard *.c)

OBJS = $(SRCS: .c = .o)

main : $(OBJS)
		$(CC) -o $@ $^

%.o : %.c
		$(CC) -c $< -o $@

clean : 
		rm -rf $(OBJS)

