CC=g++

SocketServer: build/SocketServer.o
	$(CC) build/SocketServer.o -o build/SocketServer

build/SocketServer.o: SocketServer.cpp
	$(CC) -c SocketServer.cpp -o build/SocketServer.o