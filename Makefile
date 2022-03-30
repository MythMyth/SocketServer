CC=g++

SRC =  SocketServer.cpp Client.cpp ClientListener.cpp
OBJ = $(foreach d, $(SRC), $(addsuffix .o, $(basename $d)))

SocketServer: $(OBJ)
	$(CC) $(foreach d, $(SRC), $(addprefix build/, $(addsuffix .o, $(basename $d)))) -o build/SocketServer

$(OBJ):
	$(CC) -c $(addsuffix .cpp, $(basename $@)) -o build/$@

clean: 
	rm -rf build
	mkdir build