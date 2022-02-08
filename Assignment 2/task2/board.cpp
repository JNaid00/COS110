#include "piece.h"
#include "board.h"
#include <fstream>

using namespace std;
//class peice;
//class board;
bool isHorizontalCheck(piece**, int, piece**, int, int /* xPosition king*/, int/* yPosition king*/, int /* xPosition attack*/, int /* YPosition attack*/);
                    // white        //Black
bool isDiagonalCHeck(piece**, int, piece**, int, int /* xPosition king*/, int/* yPosition king*/, int /* xPosition attack*/, int /* YPosition attack*/);
                     // white        //Black
bool isNoPieceThere(piece**, int, piece**, int, int , int);

bool checkIfPieceHasCheckonOPP(string ,int ,int  ,int , int,piece**, int, piece**, int);

bool RangeCheck(int, int);



board::board(string pieceList)
{
    //cout << "NewYork" << endl;
    ifstream inputfile;
    inputfile.open(pieceList.c_str());
    string line;
   //cout << "NewYork: " << numWhitePieces + numBlackPieces << endl;
    numBlackPieces = 0;
    numWhitePieces = 0;
    chessboard = new string*[8];
    for (int ROWx = 0; ROWx < 8; ROWx++)
    {
        chessboard[ROWx] = new string[8];
        for (int COLy = 0; COLy < 8; COLy++)
        {
            chessboard[ROWx][COLy] = "-";
        }
    }
    getline(inputfile,line);
    while (getline(inputfile,line))
    {
        if (line[0] == 'b')
        numBlackPieces++;
        else
        if (line[0] == 'w')
        numWhitePieces++;
    }
    inputfile.close();
    inputfile.open(pieceList.c_str());
    getline(inputfile,line);
    this->sideToMove = line[0];
    //cout << "NewYork: " << sideToMove << endl;
    getline(inputfile,line);
    this->move = line;
   // cout << "NewYork: " << line << endl;
    this->whitePieces = new piece*[numWhitePieces];
    for (int i = 0; i< this->numWhitePieces;i++)
    {
        this->whitePieces[i] = NULL;
    }

    this->blackPieces = new piece*[numBlackPieces];
    for (int i = 0; i< this->numBlackPieces;i++)
    {
        this->blackPieces[i] = NULL;
    }
    int xPos, yPos;
    string type;
    string side;
    string Type2;
    //cout << "NewYork: " << numWhitePieces + numBlackPieces << endl;
    int countW = 0, countB = 0;
    while(getline(inputfile,line))
    {
        side = line[0];
        line.erase(0,2);
        type = line.substr(0,line.find(","));
        line.erase(0,line.find(",") + 1);
        stringstream a(line.substr(0,1));
        a >> xPos;
        line.erase(0,2);
        stringstream b(line);
        b >> yPos;
        if (type == "king")
        Type2 = "K";
        else
        Type2 = type[0];
        this->chessboard[xPos][yPos] = side + Type2;
        if (side == "w")
        {
            this->whitePieces[countW] = new piece(type, side[0], xPos, yPos);
            countW++;
        }
        else
        if (side == "b")
        {
            this->blackPieces[countB] = new piece(type, side[0], xPos, yPos);
            countB++;
        }
       
    }
    // string out = "";
    // for (int i = 0; i < 8; i++)
    // {
    //     for (int k = 0; k < 8; k++)
    //     {
    //         out = out + chessboard[i][k];
    //     }
    //     cout << out << endl;
    //     out = "";
    // }
    // cout << endl;
    ++(*this);
}

board::~board() //Ask about cout
{
    for (int i = 0; i < numBlackPieces;i++)
    {
        delete this->blackPieces[i];
    }
    delete [] blackPieces;
    for (int i = 0; i < numWhitePieces;i++)
    {
        delete this->whitePieces[i];
    }
    delete [] whitePieces;
    for (int i = 0; i<8; i++)
    {
        delete [] this->chessboard[i];
    }
    delete [] this->chessboard;
    cout << "Num Pieces Removed: " << numWhitePieces + numBlackPieces << endl;
}

board& board::operator++()
{
    int numberPieces;
    piece **changePieces;
    int oldX, oldY, newX, newY;
    if (sideToMove == 'w')
    {
        
        numberPieces = this->numWhitePieces;
       // cout << "NewYork: " << numberPieces << endl;
        changePieces = this->whitePieces;
    }
    else
    {
        numberPieces = this->numBlackPieces;
        changePieces = this->blackPieces;
    }


    stringstream x;
    x.str(move.substr(0,1));
    x >> oldX;
    x.clear();
    x.str(move.substr(2,1));
    //cout << "NewYOrk: " <<move.substr(2,1) << endl;
    x >> oldY;
    x.clear();
    x.str(move.substr(4,1));
    x >> newX;
    x.clear();
    x.str(move.substr(6,1));
    x >> newY;
    string type;
    for (int i = 0; i < numberPieces; i++)
    {
       // cout << "NewYork: " << changePieces[i]->getX() << " " << changePieces[i]->getY() << endl;
      // cout << "NewYork: " << newX << " " << newY << endl;
        if ((changePieces[i]->getX() == oldX) && (changePieces[i]->getY() == oldY))
        {
            this->chessboard[oldX][oldY] = "-";
            changePieces[i]->setX(newX);
            changePieces[i]->setY(newY);
            if (changePieces[i]->getPieceType() == "king")
            type = "K";
            else
            type = (changePieces[i]->getPieceType())[0];
            //cout << "NewYork " << sideToMove + type;
             this->chessboard[newX][newY] = sideToMove + type ;
            i = numberPieces;
            //cout << "NewYork" <<this->chessboard[newY][newX] <<endl;
        }
    }
    // string out = "";
    // for (int i = 0; i < 8; i++)
    // {
    //     for (int k = 0; k < 8; k++)
    //     {
    //         out = out + chessboard[i][k];
    //     }
    //     cout << out << endl;
    //     out = "";
    // }
return *this;
}

bool board::checkIfPieceHasCheck(string pieceType ,int xPos,int yPos ,int kingX, int kingY)
{
    if (pieceType == "king")
    {
    return false;
    }
    if ((RangeCheck(xPos,yPos) == false) || (RangeCheck(kingX,kingY) == false)) 
    {
        return false;
    }
    

    bool hasCheck = false;
    char type;
    if (pieceType == "king")
    type = 'K';
    else
    type = pieceType[0];
    int changeX = 0, changeY = 0;
    //Account for different sides
    int yAccount = 0;
    if (this->sideToMove == 'w')
    yAccount = -1;
    else
    if (this->sideToMove == 'b')
    yAccount = 1;
    switch (type)
    {
        case 'p':
            {
                if (sideToMove == 'w')
                {
                    if ((xPos-1 == kingX) && ((yPos-1 == kingY) || (yPos+1 == kingY)))
                        {
                            hasCheck = true;
                        }
                }
                if (sideToMove == 'b')
                {
                    if ((xPos+1 == kingX) && ((yPos-1 == kingY) || (yPos+1 == kingY)))
                        {
                            hasCheck = true;
                        }
                }
                
                
                break;
            }
        case 'r':
            {
                if ((xPos == kingX) || (yPos == kingY))
                {
                    //cout << "NewYork" << endl;
                    //hasCheck = true;
                    if (isHorizontalCheck(this->whitePieces, this->numWhitePieces, this->blackPieces, this->numBlackPieces, kingX,kingY, xPos,yPos ))
                    hasCheck = true;
                }
                break;
            }
        case 'b':
            {
                changeX = kingX - xPos;
                if (changeX < 0)
                changeX *= -1;
                changeY = kingY-yPos;
                if (changeY < 0)
                changeY *= -1;
                if (changeY == changeX)
                {
                   // cout << "NewYork: " << changeY << endl;
                    if (isDiagonalCHeck(this->whitePieces, this->numWhitePieces, this->blackPieces, this->numBlackPieces, kingX,kingY, xPos,yPos ))
                    hasCheck =true;
                }
                
                break;
            }
        case 'q':
            {
                changeX = kingX - xPos;
                if (changeX < 0)
                changeX *= -1;
                changeY = kingY-yPos;
                if (changeY < 0)
                changeY *= -1;
                if (changeY == changeX)
                {
                    if (isDiagonalCHeck(this->whitePieces, this->numWhitePieces, this->blackPieces, this->numBlackPieces, kingX,kingY, xPos,yPos ) == true)
                    hasCheck =true;
                }
                else
                if (((xPos == kingX) || (yPos == kingY)) && (isHorizontalCheck(this->whitePieces, this->numWhitePieces, this->blackPieces, this->numBlackPieces, kingX,kingY, xPos,yPos ) == true))
                hasCheck = true;
                break;
            }
        case 'k':
            {
               // cout << "NewYork: " << hasCheck << endl;
                int loopValue = -1;
                for (int i = 1; i <= 2; i++)
                {
                    for (int k = 1;k <= i;k++)
                    loopValue = loopValue * -1;
                    //cout << "NewYork: " << loopValue << endl;
                    if (((yPos+(2*loopValue)) == kingY) && ((xPos-1 == kingX) || (xPos+1 == kingX)))
                    {
                        hasCheck = true;
                        // cout << "NewYork: K " << kingX << " " << kingY << endl;
                        // cout << "NewYork: Piece " << xPos << " " << yPos << endl;
                    }
                    
                    if (((xPos+(2*loopValue)) == kingX) && ((yPos-1 == kingY) || (yPos+1 == kingY)))
                    hasCheck = true;

                    
                    // cout << "NewYork: " << xPos-1 << " " << yPos+(2*loopValue) << endl;
                    // cout << "NewYork: " << xPos+1 << " " << yPos+(2*loopValue) << endl;
                    // cout << "NewYork: " << xPos+(2*loopValue) << " " << yPos-1 << endl;
                    // cout << "NewYork: " << xPos+(2*loopValue) << " " << yPos+1 << endl << endl;
                    loopValue = -1;
                }
                break;
            }
        case 'K': break;
    }
  return hasCheck;  
}

board& board::operator--()
{
    char oppSide;
    bool checkMate = true, moveCheck = false;
    int okingX = 0, okingY = 0;
    piece **oppSidePiece;
    piece **attackSide;
    int numAttackSIde;
    int numOppSide;
    int oppKingIndex;
    if (sideToMove == 'w')
    {
       // cout << "NewYork: " <<  sideToMove << endl;
        attackSide = this->whitePieces;
        numAttackSIde = this->numWhitePieces;
        oppSide = 'b';
        oppSidePiece = this->blackPieces;
        numOppSide = this->numBlackPieces;
    }
    else
    {
        attackSide = this->blackPieces;
        numAttackSIde = this->numBlackPieces;
        oppSide = 'w';
        oppSidePiece = this->whitePieces;
        numOppSide = this->numWhitePieces;
    }

    for (int i = 0; i < numOppSide; i++)
    {
       
        if (oppSidePiece[i] != NULL)
        {
             //cout << "NewYork: " << endl;
           //  cout << "NewYork: " << oppSidePiece[i]->getPieceType() <<  endl;
            if (oppSidePiece[i]->getPieceType() == "king")
            {
                oppKingIndex = i;
                okingX = oppSidePiece[i]->getX();
                okingY = oppSidePiece[i]->getY();
               //cout << "NewYork: " <<  okingX << " " << okingY <<  endl;
                i = numOppSide;
            }
        }
    }
    //Check if move has a check on opp king
        for (int i = 0; i < numAttackSIde; i++)
        {

            if (attackSide[i] != NULL)
            {
                if (checkIfPieceHasCheckonOPP(attackSide[i]->getPieceType(), attackSide[i]->getX(), attackSide[i]->getY(), okingX ,okingY,this->whitePieces, this->numWhitePieces, this->blackPieces, this->numBlackPieces) == true)
               {
                  // cout << "NewYork: " << *(attackSide[i]) << endl;
                   moveCheck = true;
                   // checkMate = false;
                   i = numAttackSIde;
               } 
            }
        }
        if (moveCheck == false)
        checkMate = false;
    //
    int falseCheck = 0;
    if (moveCheck == true)
    {
        for (int xRow = -1; xRow < 2; xRow++)
        {
            for (int yCol = -1; yCol < 2; yCol++)
            {
               for (int i = 0; i < numAttackSIde;i++)
               {
                //    xRow = 1;
                //    yCol = 1;
                //cout << "NewYork: " << (RangeCheck(okingX + xRow, okingY + yCol) == true) << endl;
                //cout << "NewYork: " << okingX + xRow << " " << okingY + yCol << endl;
                   if ((attackSide[i] != NULL) && (RangeCheck(okingX + xRow, okingY + yCol) == true) && (isNoPieceThere(this->whitePieces, this->numWhitePieces, this->blackPieces, this->numBlackPieces,okingX + xRow, okingY + yCol) == true))
                   {
                       oppSidePiece[oppKingIndex]->setX(okingX + xRow);
                       oppSidePiece[oppKingIndex]->setY(okingY + yCol);
                       if ((checkIfPieceHasCheckonOPP(attackSide[i]->getPieceType(), attackSide[i]->getX(), attackSide[i]->getY(), okingX + xRow ,okingY + yCol,this->whitePieces, this->numWhitePieces, this->blackPieces, this->numBlackPieces) == false))
                        {       
                            falseCheck++;
                        }
                        // else{
                        //     //cout << "NewYork: " << *(attackSide[i]) << endl;
                        //     //cout << "NewYork: " << *(oppSidePiece[oppKingIndex]) << endl;
                        // }
                        oppSidePiece[oppKingIndex]->setX(okingX);
                       oppSidePiece[oppKingIndex]->setY(okingY);
                        
                   }
               } 
             // cout << "NewYork: " << (attackSide[0]->getPieceType() == "King") << endl;
               //cout << "NewYork: " <<falseCheck << endl;
               if (falseCheck == numAttackSIde)
               {
                   checkMate = false;
                   xRow = 3;
                   yCol = 3;
               }
               falseCheck = 0;
            //    xRow = 3;
            //     yCol = 3;
            }
        }

    }



 // cout << "NewYork: " << checkMate << endl;
 if (checkMate == true)
 {
    cout << "Success: Checkmate of " << oppSide << " King at [" << okingX << "," << okingY << "]"<< endl;
 }
 else
 {
    cout << "Failed: No Checkmate of " << oppSide << " King" << endl;
 }


    return *this;
}

bool RangeCheck(int xPos, int yPos)
{
 bool ans =false;
 if ((xPos >= 0) && (xPos <= 7) && (yPos >= 0) && (yPos <= 7))
 {
    ans =true;
 }

 return ans;
}


bool checkIfPieceHasCheckonOPP(string pieceType ,int xPos,int yPos ,int kingX, int kingY, piece** whitePieces, int numWhitePieces, piece** blackPieces, int numBlackPieces)
{ 
    if (pieceType == "king")
    return false;
   // cout << "NewYork: " << endl;
   if ((RangeCheck(xPos,yPos) == false) || (RangeCheck(kingX,kingY) == false)) 
    {
        return false;
    }
    bool hasCheck = false;
    char type;
    if (pieceType == "king")
    type = 'K';
    else
    type = pieceType[0];

    int changeX = 0, changeY = 0;
    //Account for different sides
    // int yAccount = 0;
    // if (this->sideToMove == 'w')
    // yAccount = -1;
    // else
    // if (this->sideToMove == 'b')
    // yAccount = 1;
    char side = 'b';
    for (int i = 0; i < numWhitePieces; i++)
    {
       
        if (whitePieces[i] != NULL)
        {
             //cout << "NewYork: " << endl;
           //  cout << "NewYork: " << oppSidePiece[i]->getPieceType() <<  endl;
            if ((whitePieces[i]->getX() == xPos) && (whitePieces[i]->getY() == yPos))
            {
                side = 'w';
               //cout << "NewYork: " <<  okingX << " " << okingY <<  endl;
                i = numWhitePieces;
            }
        }
    }

    switch (type)
    {
        case 'p':
            {
                if (side == 'w')
                {
                    if ((xPos-1 == kingX) && ((yPos-1 == kingY) || (yPos+1 == kingY)))
                        {
                            hasCheck = true;
                        }
                }
                if (side == 'b')
                {
                    if ((xPos+1 == kingX) && ((yPos-1 == kingY) || (yPos+1 == kingY)))
                        {
                            hasCheck = true;
                        }
                }
                break;
            }
        case 'r':
            {
                if ((xPos == kingX) || (yPos == kingY))
                {
                    //cout << "NewYork" << endl;
                    //hasCheck = true;
                    //cout << "NewYork" <<  endl;
                    if (isHorizontalCheck(whitePieces, numWhitePieces, blackPieces, numBlackPieces, kingX,kingY, xPos,yPos ))
                    {
                      //  cout << "NewYork" << endl;
                        hasCheck = true;
                    }
                    
                }
                break;
            }
        case 'b':
            {
                changeX = kingX - xPos;
                if (changeX < 0)
                changeX *= -1;
                changeY = kingY-yPos;
                if (changeY < 0)
                changeY *= -1;
                if (changeY == changeX)
                {
                   // cout << "NewYork: " << changeY << endl;
                    if (isDiagonalCHeck(whitePieces, numWhitePieces, blackPieces, numBlackPieces, kingX,kingY, xPos,yPos ))
                    hasCheck =true;
                }
                
                break;
            }
        case 'q':
            {
                changeX = kingX - xPos;
                if (changeX < 0)
                changeX *= -1;
                changeY = kingY-yPos;
                if (changeY < 0)
                changeY *= -1;
                if (changeY == changeX)
                {
                    if (isDiagonalCHeck(whitePieces, numWhitePieces, blackPieces, numBlackPieces, kingX,kingY, xPos,yPos ))
                    hasCheck =true;
                }
                else
                if (((xPos == kingX) || (yPos == kingY)) && isHorizontalCheck(whitePieces, numWhitePieces, blackPieces, numBlackPieces, kingX,kingY, xPos,yPos ))
                hasCheck = true;
                break;
            }
        case 'k':
            {
                int loopValue = -1;
                for (int i = 1; i <= 2; i++)
                {
                    for (int k = 1;k <= i;k++)
                    loopValue = loopValue * -1;
                    //cout << "NewYork: " << loopValue << endl;
                    if (((yPos+(2*loopValue)) == kingY) && ((xPos-1 == kingX) || (xPos+1 == kingX)))
                    hasCheck = true;
                    if (((xPos+(2*loopValue)) == kingX) && ((yPos-1 == kingY) || (yPos+1 == kingY)))
                    hasCheck = true;
                    loopValue = -1;
                }
                break;
            }
        case 'K': break;
    }
  return hasCheck;   
}
///////////////////////////////////////////////////////////////
bool isNoPieceThere(piece** white, int numWhitePieces, piece** black, int numBlackPieces, int xCor, int yCor)
{
    bool ans = true;
    for (int i = 0; i < numWhitePieces; i++)
    {
        if (white[i] != NULL)
        {
            if ((white[i]->getX() == xCor) && (white[i]->getY() == yCor))
            {
                ans = false;
                // cout << "NewYork: " << xCor << " " <<  yCor << endl;
                 i = numWhitePieces;
            }
            
        }
    }

    for (int i = 0; i < numBlackPieces; i++)
    {
        if (black[i] != NULL)
        {
            if ((black[i]->getX() == xCor) && (black[i]->getY() == yCor))
            {
                ans = false;
                i = numBlackPieces;
            }
            
        }
    }
return ans;
}


bool isHorizontalCheck(piece** white, int numWhitePieces, piece** black, int numBlackPieces, int kingX, int kingY, int xPos, int yPos)
{ //True = No peice is in the way, check is possible
    bool ans = true;
   // cout << piece::numBlackPieces << endl;
    for (int i = 0; i < numWhitePieces; i++)
    {
        
        if (white[i] != NULL)
        {
            if ((white[i]->getX() == kingX) && (white[i]->getX() == xPos))
            {
                //cout << "NewYork K: " << kingX << " " <<  kingY << endl;
                if ((white[i]->getY() > yPos) && (white[i]->getY() < kingY))
                {
                  //   cout << "NewYork P: " << white[i]->getX() << " " <<  white[i]->getY() << endl;
                    ans = false;
                }
                else
                if ((white[i]->getY() < yPos) && (white[i]->getY() > kingY))
                {
                    ans = false;
                    
                }
                
            }
            if ((white[i]->getY() == kingY) && (white[i]->getY() == yPos))
            {
                //cout << "NewYork: " << kingX << " " <<  kingY << endl;;
                
                if ((white[i]->getX() > xPos) && (white[i]->getX() < kingX))
                {
                    ans = false;
                }
                else
                if ((white[i]->getX() < xPos) && (white[i]->getX() > kingX))
                {
                    ans = false;
                }
            }
        }
    }

    for (int i = 0; i < numBlackPieces; i++)
    {
        if (black[i] != NULL)
        {
            if ((black[i]->getX() == kingX) && (black[i]->getX() == xPos))
            {
                if ((black[i]->getY() > yPos) && (black[i]->getY() < kingY))
                {
                    ans = false;
                    
                }
                else
                if ((black[i]->getY() < yPos) && (black[i]->getY() > kingY))
                {
                    ans = false;
                    
                }
                
            }
            if ((black[i]->getY() == kingY) && (black[i]->getY() == yPos))
            {
                
                if ((black[i]->getX() > xPos) && (black[i]->getX() < kingX))
                {
                   // cout << "NewYork: " << black[i]->getX() << " " << black[i]->getY() << endl;
                    ans = false;
                }
                else
                if ((black[i]->getX() < xPos) && (black[i]->getX() > kingX))
                {
                  
                    ans = false;
                }
            }
        }
    }
    

 return ans;
}

bool isDiagonalCHeck(piece** white, int numWhitePieces, piece** black, int numBlackPieces, int kingX, int kingY, int xPos, int yPos)
{
    bool ans = true;
    int changeX, changeY;
    for (int i = 0; i < numWhitePieces;i++)
    {
        if (white[i] != NULL)
        {
            changeX = white[i]->getX() - xPos;
            if (changeX < 0)
            changeX *= -1;
            changeY = white[i]->getY() - yPos;
            if (changeY < 0)
            changeY *= -1;

            if (changeY == changeX)
            {
                if ((white[i]->getY() > yPos) && (white[i]->getY() < kingY))
                {
                   
                    ans = false;
                }
                if ((white[i]->getY() < yPos) && (white[i]->getY() > kingY))
                {
                     
                    ans = false;
                }
            }
        }
    }
    changeX = 0;
    changeY = 0;
    for (int i = 0; i < numBlackPieces;i++)
    {
        if (black[i] != NULL)
        {
            changeX = black[i]->getX() - xPos;
            if (changeX < 0)
            changeX *= -1;
            changeY = black[i]->getY() - yPos;
            if (changeY < 0)
            changeY *= -1;

            if (changeY == changeX)
            {
                if ((black[i]->getY() > yPos) && (black[i]->getY() < kingY))
                {
                    //cout << "NewYork: " << endl;
                    ans = false;
                }
                if ((black[i]->getY() < yPos) && (black[i]->getY() > kingY))
                {
                    ans = false;
                }
            }
        }
    }

    return ans;
}