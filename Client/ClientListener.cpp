#include "ClientListener.h"

ClientListener::ClientListener(int server, struct sockaddr_in *address) {
    m_server_fd = server;
    m_address = address;
}

void ClientListener::run() {
    int addrlen = sizeof(struct sockaddr_in);    
    while(1) {
        Debug::GetInstance()->Log(LOG_LEVEL_HIGH, "Start listening to new client");
        int new_socket = accept(m_server_fd, (struct sockaddr*)m_address, (socklen_t*)&addrlen);
        if(new_socket > 0) {
            Debug::GetInstance()->Log(LOG_LEVEL_HIGH, "New client connected. ID: %d", new_socket);  
            connected.insert({new_socket, new Client(new_socket, this)});
            connected[new_socket]->start();
        }
    }
}

void ClientListener::ClientEnd(int client_id) {
    if(connected.find(client_id) == connected.end()) return;
    Debug::GetInstance()->Log(LOG_LEVEL_HIGH, "Client %d disconnected", client_id);
    delete connected[client_id];
    connected.erase(client_id);
}