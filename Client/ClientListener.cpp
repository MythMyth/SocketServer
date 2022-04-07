#include "ClientListener.h"

ClientListener::ClientListener(int server, struct sockaddr_in *address) {
    m_server_fd = server;
    m_address = address;
}

void ClientListener::run() {
    int addrlen = sizeof(struct sockaddr_in);    
    while(1) {
        cout << "Start listening to new client\n";
        int new_socket = accept(m_server_fd, (struct sockaddr*)m_address, (socklen_t*)&addrlen);
        if(new_socket > 0) {
            cout << "New client connected. ID: " << new_socket << "\n";  
            connected.insert({new_socket, new Client(new_socket, this)});
            connected[new_socket]->start();
        }
    }
}

void ClientListener::ClientEnd(int client_id) {
    if(connected.find(client_id) == connected.end()) return;
    cout << "Client " << client_id << " disconnected\n";
    delete connected[client_id];
    connected.erase(client_id);
}