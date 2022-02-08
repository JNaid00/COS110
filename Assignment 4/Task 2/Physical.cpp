#include "Physical.h"
#include <string>
#include <sstream>
#include <iostream>
#include "Layer.h"
#include "Message.h"

using namespace std;

Physical::Physical() : Layer()
{
    this->next ==NULL;
    //cout << "PHysical constructor" << endl;
}

void Physical::execute(Message* message, bool sending)
{
    if (sending == true)
    {
        if (this->next == NULL)
        {
            cout << "NOT CONNECTED TO A NETWORK" << endl;
            message->PrintMessage();
        }
        else
        if (this->next !=NULL)
        {
            this->next->execute(message,false);
        }
    }
    else
    if (sending == false)
    {
        cout << "Message at Physical layer of computer: " << this->computerName << endl;
        this->up->execute(message,false);
    }
}

Physical::~Physical() 
{
    
    if (this->next != NULL)
    {
        Physical *nodePtr;
        nodePtr = this->next;
        while (nodePtr->next != this)
        {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = this->next;

        if (nodePtr == this->next)
        {
            nodePtr->next = NULL;
            //this->next = NULL;
        }
        
        this->next = NULL;
        //delete nodePtr;
        //delete this;
    }
}

void Physical::link(Layer* LinkStack) 
{
   // cout << "Nework: link" << endl;
    Layer *nodeStack = LinkStack;
    while (nodeStack->getDown() != NULL)
    {
        //cout << "NewYork" << endl;
        nodeStack = nodeStack->getDown();
        
    }

    if (this->next == NULL)
    {
        this->next = dynamic_cast<Physical*>(nodeStack);
        this->next->setNext(this);
    }
    else
    {
        Physical *temp = this->next;
        this->next = dynamic_cast<Physical*>(nodeStack);
        this->next->setNext(temp);
    }

}

Physical* Physical::getNext()
{
    return this->next;
}

void Physical::setNext(Physical* newNext) 
{
    this->next = newNext;    
}

void Physical::configure(config settings)
{
    this->computerName = settings.computerName;    
}
