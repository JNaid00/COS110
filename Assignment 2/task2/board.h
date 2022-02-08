#ifndef BOARD_H
#define BOARD_H
#include "piece.h"
#include <fstream>


using namespace std;

class board
{
    private:
        int numWhitePieces;
        int numBlackPieces;
        piece **whitePieces;
        piece **blackPieces;
        string **chessboard;
        string move;
        char sideToMove;
        board& operator++();
    public:
        board(string pieceList);
        ~board();
        
        board& operator--();
        bool checkIfPieceHasCheck(string pieceType ,int xPos,int yPos ,int kingX, int kingY);

};
#endif