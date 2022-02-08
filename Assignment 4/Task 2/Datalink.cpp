#include "Datalink.h"
#include <string>
#include <sstream>
#include <iostream>
#include "Layer.h"
#include "Message.h"
#include "Physical.h"

using namespace std;

Datalink::Datalink() : Layer()
{
    this->down = new Physical();
    this->down->setUp(this);
}

void Datalink::execute(Message* message, bool sending)
{
    if (sending == true)
    {
        this->down->execute(message,true);
    }    
    else
    {
        cout << "Message at Datalink layer" << endl;
        this->up->execute(message,false);
    }
}
