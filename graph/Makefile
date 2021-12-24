CFLAGS = -g -I

PROGRAM =  exercise2

CFLAGS += -I
OBJS = main.o
OBJS +=list.o
OBJS +=hash.o
OBJS +=graph.o


$(PROGRAM): clean $(OBJS)
	gcc  $(OBJS) -o  $(PROGRAM)
clean :
	rm -f $(PROGRAM) $(OBJS)
run:
	./exercise2
