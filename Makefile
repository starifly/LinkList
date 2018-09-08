CC=gcc
FLAGS=-I include -g

exe=userapp
obj:=main.o stubylinklist.o
all:$(obj)
	$(CC) -o $(exe) $(obj) $(FLAGS)
%.o : %.c
	$(CC) -c $^ -o $@ $(FLAGS)
clean:
	rm -rf $(obj) $(exe)
