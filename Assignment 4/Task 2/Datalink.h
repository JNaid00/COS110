#ifndef DATALINK_H
#define DATALINK_H
#include <string>
#include <sstream>
#include <iostream>
#include "Layer.h"
#include "Message.h"

class Datalink : public Layer
{
    public:
        Datalink();
        void execute(Message* message, bool sending=true);
};
#endif