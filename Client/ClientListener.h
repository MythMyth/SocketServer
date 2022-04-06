#ifndef __CLIENTLISTENER__
#define __CLIENTLISTENER__

#include<map>
#include<string>
#include "Client.h"
#include "../PThread/MyPThread.h"

using namespace std;

class ClientListener : public MyPThread{
    map<string, Client*> connected;
public:
    ClientListener();
    void run();
private: 
    map<string, Client*> connected;
};

#endif