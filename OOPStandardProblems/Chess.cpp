#include <iostream>
using namespace std;

class Board;
class Box;

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

    virtual void canMove(Board board, Box start, Box end) = 0;

private:
    bool mIsWhite;
    bool mIsKilled;

};

class King : public Piece
{
    King(bool isWhite) : Piece(isWhite)
    {

    }

    void canMove(Board board, Box start, Box end)
    {

    }
};

int main()
{


    return 0;
}
