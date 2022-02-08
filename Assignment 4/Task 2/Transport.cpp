#include "Transport.h"
#include <string>
#include <sstream>
#include <iostream>
#include "Layer.h"
#include "Message.h"
#include "Network.h"

using namespace std;

Transport::Transport() : Layer()
{
    this->down = new Network();
    this->down->setUp(this);
}

void Transport::execute(Message* message, bool sending)
{
    if (sending == true)
    {

        if (message->setOriginPort(this->port) == false)
        {
            cout << "ERROR OCCURRED WITH ORIGIN PORT" << endl;
            return;
        }
        if (message->setDestinationPort(this->DestPort) == false)
        {
            cout << "ERROR OCCURRED WITH DESTINATION PORT" << endl;
            return;
        }

        this->down->execute(message);

    }
    else
    {
        if (message->getDestinationPort() != this->port)
        {
            cout << "Message sent to wrong port" << endl;
            message->PrintMessage();
        }
        else
        if (message->getData().length() != message->getContentLength())
        {
            cout << "Content Length error" << endl;
            message->PrintMessage();
        }
        else
        if ((message->getDestinationPort() == this->port) && (message->getData().length() == message->getContentLength()))
        {
            cout << "Message at Transport layer" << endl;
            this->up->execute(message, false);
        }
    }
}

void Transport::configure(config settings)
{
    //cout << "NewYork: Transport configue" << endl;
    this->port = settings.port;
    this->DestPort = settings.DestPort;
    Layer::configure(settings);
}
