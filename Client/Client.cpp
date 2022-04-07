#include "Client.h"

Client::Client(int id, ClientListener* listener) {
    client_id = id;
    client_listener = listener;
}

void Client::run() {
    char buffer[1024+1] = {'\0'};
    cout << "Client thread started: " << client_id << "\n";
    while(1) {
        int valread = read( client_id , buffer, 1024);
        if(valread <= 0) break;
        if(valread <= 1024) buffer[valread] = '\0';
        printf("Client %d: %s\n", client_id, buffer );
    }
    client_listener->ClientEnd(this->client_id);
}