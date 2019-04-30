#include <iostream>

using namespace std;

class Board;
class Box;
class Piece;

class Board
{
    public:
    Box box[8][8];
};

class Piece
{

public:
    Piece(bool isWhite)
    {
        mIsWhite = isWhite;
    }

    // all getters
    bool isWhite()
    {
        return (true == mIsWhite);
    }

    bool isKilled()
    {
        return (true == mIsKilled);
    }

    virtual void canMove(Board *board, Box *start, Box *end) = 0;

private:
    bool mIsWhite;
    bool mIsKilled;

};

class King : public Piece
{
    King(bool isWhite) : Piece(isWhite)
    {

    }

    void canMove(Board *board, Box *start, Box *end)
    {

    }
};




class Box
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





int main()
{


    return 0;
}
