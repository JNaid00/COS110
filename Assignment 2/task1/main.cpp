#include "piece.h"

using namespace std;
int main()
{   
    piece test1("king",'w',5,6);
   piece *test = new piece(&test1);
    test->setX(0);
    //test = &test1;
    piece test2(test);
    test->setX(1);
    test->setY(1);
    cout << test2.getPieceType() << endl << test2.getSide() << endl << test2.getX() << endl<<test2.getY() << endl;
   cout << test2;
    test2[1];
    piece test3 = test1 + "76,77";
    cout << test3;
    return 0;
}