 .PHONY: clean main

 CC=gcc
 SRCS=$(wildcard *.c)  #当前目录下的所有.c文件

BASEDIR=$(shell pwd)
OBJDIR:=$(BASEDIR)/obj
$(shell mkdir -p $(OBJDIR))
OBJS=$(SRCS:.c=.o) #将SRCS对应的.c换成.o
OBJS:=$(addprefix $(OBJDIR)/, $(OBJS))

Slist : $(OBJS)
					$(CC) -o $@ $^

$(OBJDIR)/%.o : %.c
	$(CC) -c $< -o $@

clean :
					rm -rf $(OBJDIR)/$(OBJS)
rebuild : clean main
 					
