CC = g++
OBJ = $(wildcard *.o)
EXE = $(patsubst %.x, ../%.cgi, $(wildcard *.x))

all : $(EXE)

../%.cgi : %.x $(OBJ)
	$(CC) -o $@ $< $(OBJ) -lzezeon -lmysqlcppconn -ljsoncpp


