#include "piece.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

piece::piece()
{

}

piece::piece(piece* newPiece)
{
    this->pieceType = newPiece->getPieceType();
    this->side = newPiece->getSide();
    this->xPos = newPiece->getX();
    this->yPos = newPiece->getY();
   //cout << "NewYork" << endl;
}

piece::piece(string pType, char side, int x, int y)
{
    this->pieceType = pType;
    this->side = side;
    this->xPos = x;
    this->yPos = y; 
}

piece::~piece()
{
    cout << "(" << xPos << "," << yPos << ") " << side << " " << pieceType << " deleted"  << endl;  
}

char piece::getSide()
{
    return side;
}

string piece::getPieceType()
{
    return pieceType;
}

int piece::getX()
{
    return xPos;
}

int piece::getY()
{
    return yPos;
}

void piece::setX(int x)
{
    xPos = x;
}

void piece::setY(int y)
{
    yPos = y;
}

void piece::operator[](int pos)
{
    if ((pos != 0) && (pos != 1))
    {
        cout << "Invalid Index" << endl;
    }
    else
    {
        if (pos == 0)
        cout << "x coord: " << xPos << endl;
        else
        cout << "y coord: " << yPos << endl;
    }
}

piece& piece::operator+(string move)
{
    int tempX, tempY;
    stringstream a(move.substr(0,move.find(",")));
    a >> tempX;
    move.erase(0,move.find(",") + 1);
    stringstream b(move.substr(0,move.size()));
    b >> tempY;
   // cout << "NewYork" << tempY << endl;
    piece *newPiece = this;
    if (((tempX <= 7) && (tempX >= 0)) && ((tempY <= 7) && (tempY >= 0)))
    {
        newPiece->setX(tempX);
        newPiece->setY(tempY);
       
    }
    return *newPiece;
}

ostream& operator<<(ostream& output, const piece& t)
{
    output << t.side << " " << t.pieceType << " at [" << t.xPos << "," << t.yPos << "]" << endl;
    return output;
}