#include "Client.h"

Client::Client(int id, ClientListener* listener) {
    client_id = id;
    client_listener = listener;
    client_name = "";
}

void Client::run() {
    char buffer[1024+1] = {'\0'};
    Debug::GetInstance()->Log(LOG_LEVEL_HIGH, "Client thread started: %d", client_id);
    while(1) {
        int valread = read( client_id , buffer, 1024);
        Debug::GetInstance()->Log(LOG_LEVEL_MED, "Read %d byte(s)", valread);
        if(valread <= 0) break;
        if(valread <= 1024) buffer[valread] = '\0';
        string received_string(buffer);
        trim(received_string);
        if(client_name == ""){
            if(received_string.substr(0, 6) == "/name " && received_string.size() > 6) {
                client_name = received_string.substr(6);
                trim(client_name);
                Debug::GetInstance()->Log(LOG_LEVEL_LOW, "Client name: %s", client_name.c_str());
                continue;
            }
            Debug::GetInstance()->Log(LOG_LEVEL_LOW, "Name not set");
            send(client_id, "Name not set", 12, 0);
        } else {
            if(received_string.substr(0, 6) == "/name " && received_string.size() > 6) {
                Debug::GetInstance()->Log(LOG_LEVEL_LOW, "Name reset");
                send(client_id, "Name already set", 16, 0);
                continue;
            }
            cout << client_name << ": " << received_string << "\n";
        }
        
    }
    client_listener->ClientEnd(this->client_id);
}

void Client::trim(string &s) {
    int len = s.size();
    int start = 0;
    while(start < len && s[start] == ' ') {
        start++;
    }
    s = s.substr(start);
    while(*s.rbegin() == ' ') {
        s.pop_back();
    }
}