#ifndef PHYSICAL_H
#define PHYSICAL_H
#include <string>
#include <sstream>
#include <iostream>
#include "Layer.h"
#include "Message.h"

class Physical : public Layer
{
    private:
      Physical *next;
    public:
        Physical();
        void execute(Message* message, bool sending=true);
        ~Physical();
        void link(Layer* LinkStack);
        Physical* getNext();
        void setNext(Physical* newNext);
        void configure(config settings );

};
#endif
