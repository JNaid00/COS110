#ifndef TRANSPORT_H
#define TRANSPORT_H
#include <string>
#include <sstream>
#include <iostream>
#include "Layer.h"
#include "Message.h"

class Transport  : public Layer
{
    private:
        std::string port;
        std::string DestPort;
    public:
    Transport();
    void execute(Message* message, bool sending=true);
    void configure(config settings);
    
};
#endif
