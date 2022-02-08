#ifndef PRESENTATION_H
#define PRESENTATION_H
#include <string>
#include <sstream>
#include <iostream>
#include "Message.h"
#include "Layer.h"

class Presentation  : public Layer
{
    private:
        std::string encoding;
    public:
        Presentation();
        void execute(Message* message, bool sending=true);
        void configure(config settings);


};
#endif


