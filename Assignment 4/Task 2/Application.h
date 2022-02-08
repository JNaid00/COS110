#ifndef APPLICATION_H
#define APPLICATION_H
#include <string>
#include <sstream>
#include <iostream>
#include "Message.h"
#include "Layer.h"

class Application : public Layer
{
    public:
        Application();
        void execute(Message* message,bool sending = true);
        void execute(std::string data, int contentLength);
};
#endif

