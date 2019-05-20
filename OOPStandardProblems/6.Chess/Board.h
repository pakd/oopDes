/*
1. Include headers in particular order - maybe topologically
2. Use Header guards to avoid recursive includes.
3. Try to not import header more than once.
*/
#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <iostream>
#include <vector>
#include "Piece.h"
#include "Box.h"

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
        // initialize white pieces
        boxes[0][0] = new Box(0, 0, new Rook(true));
        boxes[0][1] = new Box(0, 1, new Knight(true));
        boxes[0][2] = new Box(0, 2, new Bishop(true));
        //...
        boxes[1][0] = new Box(1, 0, new Pawn(true));
        boxes[1][1] = new Box(1, 1, new Pawn(true));
        //...

        // initialize black pieces
        boxes[7][0] = new Box(7, 0, new Rook(false));
        boxes[7][1] = new Box(7, 1, new Knight(false));
        boxes[7][2] = new Box(7, 2, new Bishop(false));
        //...
        boxes[6][0] = new Box(6, 0, new Pawn(false));
        boxes[6][1] = new Box(6, 1, new Pawn(false));

        for (int i = 2; i < 6; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                boxes[i][j] = new Box(i, j, NULL);
            }

        }
    }

    Box* boxes[8][8];

    };

#endif
