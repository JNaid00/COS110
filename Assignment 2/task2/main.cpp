#include "piece.h"
#include "board.h"
using namespace std;
int main()
{   
    board test("game1.txt");
    --test;
   // cout << test.checkIfPieceHasCheck("pawn",4,2,3,2) << endl; 
    // cout << test.checkIfPieceHasCheck("bishop",0,0,4,4) <<  endl; 
   // cout << test.checkIfPieceHasCheck("knight",4,4,5,6) << endl;
    return 0;
}