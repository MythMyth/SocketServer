#include "ClientListener.h"

ClientListener::ClientListener() {
}

void ClientListener::run() {
    int addrlen = sizeof(struct sockaddr_in);
    while(1) {
        cout << "Start listening to new client\n";
        int new_socket = (new MSocket()) -> ListenForConnect();
        if(new_socket > 0) {
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