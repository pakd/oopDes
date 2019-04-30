#ifndef BOX_H_INCLUDED
#define BOX_H_INCLUDED

#include <iostream>
#include "Piece.h"
using namespace std;

class Piece;

class Box // or Cell
{
public:
    Box(int x, int y, Piece* piece)
    {
        cout << endl << __func__ << endl;
        setX(x);
        setY(y);
        setPiece(piece);
    }

    // all getters
    int getX() { return mX; }
    int getY() { return mY; }
    Piece* getPiece() { return mPiece; }

    // all setters
    void setX(int x) { mX = x; }
    void setY(int y) { mY = y; }
    void setPiece(Piece* piece) { mPiece = piece; }

private:
    int mX;
    int mY;
    Piece *mPiece;


};

#endif // BOX_H_INCLUDED
