#ifndef ROTATEEXCEPTION_H
#define ROTATEEXCEPTION_H
#include "BabushkaException.h"

class RotateException : public BabushkaException
{
    public:
        virtual void printMessage();
};
#endif