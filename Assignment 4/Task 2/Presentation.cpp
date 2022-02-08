#include "Presentation.h"
#include <string>
#include <sstream>
#include <iostream>
#include "Message.h"
#include "Layer.h"
#include "Transport.h"

using namespace std;

Presentation::Presentation() : Layer()
{
    this->down = new Transport();
    this->down->setUp(this);
}

void Presentation::execute(Message* message, bool sending)
{
      // cout << "Presentation execute" << endl;
        //return;
    if(sending == true)
    {
        //this->encoding = message->getEncoding();
        message->setEncoding(this->encoding);
        // cout << "Presentation encoding: " << this->encoding << endl;
        // return;
        this->down->execute(message,sending);
    }
    else
    {
        
        if (this->encoding == message->getEncoding())
        {
            cout << "Message at Presentation layer on computer: " << this->computerName << endl;
            this->up->execute(message, false);
        }
        else
        {
           // cout << "encoding: " << this->encoding << endl << "getEncoding: " << message->getEncoding() << endl;
            cout << "Encoding type mismatch on computer: " << this->computerName << " Expected: " << this->encoding << endl;
            message->PrintMessage();    
        }
    }
}

void Presentation::configure(config settings)
{
    // cout << "Presentation configure" << endl;
    // return;
    this->encoding = settings.encoding;
    Layer::configure(settings);
}
