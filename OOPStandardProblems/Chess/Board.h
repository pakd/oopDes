#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <iostream>
#include <vector>
#include "Box.h"
#include "Piece.h"
using namespace std;

class King;

class Board
{
public:
    Board()
    {
        resetBoard();
    }

private:

    void resetBoard()
    {
        King kingobj(true);
        box[0][0] = new Box(0, 0, kingobj);
    }
    std::vector<std::vector<Box*>> box;
};

#endif
