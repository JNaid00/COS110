#ifndef NETWORK_H
#define NETWORK_H
#include <string>
#include <sstream>
#include <iostream>
#include "Layer.h"
#include "Message.h"

class Network : public Layer
{
    private:
        std::string ip;
        std::string DestIP;
    public:
        Network();
        void execute(Message* message, bool sending=true);
        void configure(config settings );
};
#endif