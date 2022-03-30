#ifndef __CLIENTLISTENER__
#define __CLIENTLISTENER__

#include<map>
#include<string>
#include "Client.h"

using namespace std;

class ClientListener {
    map<string, Client*> connected;
};

#endif