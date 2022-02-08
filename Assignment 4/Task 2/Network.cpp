#include "Network.h"
#include <string>
#include <sstream>
#include <iostream>
#include "Layer.h"
#include "Message.h"
#include "Datalink.h"
using namespace std;

Network::Network() : Layer()
{
    this->down = new Datalink();
    this->down->setUp(this);
}

void Network::execute(Message* message, bool sending) //Must revisit
{
    if (sending == true)
    {
        if (message->setOriginIP(this->ip) == false)
        {
            cout << "ERROR OCCURRED WITH ORIGIN IP" << endl;
            return;
        }
        if (message->setDestinationIP(this->DestIP) == false)
        {
            cout << "ERROR OCCURRED WITH DESTINATION IP" << endl;
            return;
        }
        this->down->execute(message, true);
    }
    else
    {
        if (message->getDestinationIP() == this->ip)
        {
            cout << "Message at Network layer" <<  endl;
            this->up->execute(message,false);
           // return;
        }
        else
        if (message->getOriginIP() == this->ip)
        {
            cout << "Message has been returned to sender without finding the destination" << endl;
            message->PrintMessage();
            //return;
        }
        else
        {
            cout << "Message at Network layer" <<  endl;
            this->down->execute(message,true);
            //return;
        }
    }
}

void Network::configure(config settings)
{
    //cout << "NewYork: Network configue" << endl;
    this->ip = settings.ip;
    this->DestIP = settings.DestIP;
    Layer::configure(settings);    
}
