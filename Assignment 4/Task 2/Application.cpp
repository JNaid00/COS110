#include "Application.h"
#include <string>
#include <sstream>
#include <iostream>
#include "Message.h"
#include "Presentation.h"
#include "Layer.h"
using namespace std;

Application::Application() : Layer()
{
    this->down = new Presentation();
    // Layer::down->Layer::up = this;
   //this->down->up = this;
   this->down->setUp(this);
}

void Application::execute(Message* message, bool sending)
{
 
    if (sending == true)
    {
        this->down->execute(message, sending);
        
    }
    else
    {
        cout << "Computer " << this->computerName << " Received message: " << message->getData() << endl;
        //cout << "Hello" << endl;
    }


}

void Application::execute(std::string data, int contentLength)
{
    //cout << "Application execute" << endl;
    //     return;
   // Message newMessage(data);
   // newMessage.setContentLength(contentLength);
   Message *newMessage;
   newMessage = new Message(data);
    newMessage->setContentLength(contentLength);
    this->down->execute(newMessage, true);
}
