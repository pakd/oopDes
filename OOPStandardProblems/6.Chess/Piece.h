#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

#include <iostream>
#include "Box.h"

class Box;
class Board;

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

    virtual bool canMove(Board *board, Box *start, Box *end) = 0;

private:
    bool mIsWhite;
    bool mIsKilled;

};

class King : public Piece
{
public:
    King(bool isWhite) : Piece(isWhite) {}

    bool canMove(Board *board, Box *start, Box *end) { return true; }
};
class Queen : public Piece
{
public:
    Queen(bool isWhite) : Piece(isWhite) {}

    bool canMove(Board *board, Box *start, Box *end) { return true; }
};

class Rook : public Piece
{
public:
    Rook(bool isWhite) : Piece(isWhite) {}

    bool canMove(Board *board, Box *start, Box *end) { return true; }
};
class Bishop : public Piece
{
public:
    Bishop(bool isWhite) : Piece(isWhite) {}

    bool canMove(Board *board, Box *start, Box *end) { return true; }
};
class Knight : public Piece
{
public:
    Knight(bool isWhite) : Piece(isWhite) {}

    bool canMove(Board *board, Box *start, Box *end)
    {
        // knight can not move in same color
        if(end->getPiece()->isWhite() == this->isWhite())
        {
            return false;
        }

        // check if knight took 2.5 steps
        int x = abs(start->getX() - end->getX());
        int y = abs(start->getY() - end->getY());
        return x * y == 2;
    }


};

class Pawn : public Piece
{
public:
    Pawn(bool isWhite) : Piece(isWhite) {}

    bool canMove(Board *board, Box *start, Box *end) { return true; }
};
#endif // PIECE_H_INCLUDED
