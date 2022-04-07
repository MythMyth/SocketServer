CC=g++

SRC =  SocketServer.cpp Client/Client.cpp Client/ClientListener.cpp PThread/MyPThread.cpp
OBJ = $(foreach d, $(SRC), $(addsuffix .o, $(basename $d)))
LIB = -pthread
TARGET = build/SocketServer

SocketServer: $(OBJ)
	$(CC) $(LIB) $(foreach d, $(SRC), $(addprefix build/, $(addsuffix .o, $(basename $(notdir $d))))) -o $(TARGET)

$(OBJ):
	$(CC) -c $(addsuffix .cpp, $(basename $@)) -o build/$(notdir $@)

clean: 
	rm -rf build
	mkdir build