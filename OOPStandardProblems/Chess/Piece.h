#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

#include <iostream>
#include "Board.h"
using namespace std;

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
    King(bool isWhite) : Piece(isWhite) {}

    void canMove(Board *board, Box *start, Box *end) {}
};
class Queen : public Piece
{
    Queen(bool isWhite) : Piece(isWhite) {}

    void canMove(Board *board, Box *start, Box *end) {}
};

class Rook : public Piece
{
    Rook(bool isWhite) : Piece(isWhite) {}

    void canMove(Board *board, Box *start, Box *end) {}
};
class Bishop : public Piece
{
    Bishop(bool isWhite) : Piece(isWhite) {}

    void canMove(Board *board, Box *start, Box *end) {}
};
class Knight : public Piece
{
    Knight(bool isWhite) : Piece(isWhite) {}

    void canMove(Board *board, Box *start, Box *end) {}
};

class Pawn : public Piece
{
    Pawn(bool isWhite) : Piece(isWhite) {}

    void canMove(Board *board, Box *start, Box *end) {}
};
#endif // PIECE_H_INCLUDED
