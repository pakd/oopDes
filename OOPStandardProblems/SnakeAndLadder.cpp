#include <iostream>
using namespace std;


class SnakeNLadder
{
public:

    SnakeNLadder(int boardSize, int noOfPlayers, bool haveDefaultSnakeNLadders)
    {
        cout << __func__ << endl;

        mBoardSize = boardSize;
        mNoOfPlayers = noOfPlayers;


        moveArr = new int[mBoardSize + 1];
        for(int i=1; i<=mBoardSize; i++)
        {
            moveArr[i] = -1;
        }

        playersPosition = new int[noOfPlayers + 1];
        for(int i=1; i<=noOfPlayers; i++)
        {
            playersPosition[i] = 1;
        }

        if(haveDefaultSnakeNLadders)
        {
            defaultCreateSnakes();
            defaultCreateLadders();
        }
        // otherwise application will set snakes and ladders

    }


    void defaultCreateSnakes()
    {
        addSnake(99, 54);
        addSnake(70, 55);
        addSnake(52, 42);
        addSnake(25, 2);
        addSnake(95, 72);
    }

    void defaultCreateLadders()
    {
        addLadder(6, 25);
        addLadder(11, 40);
        addLadder(60, 85);
        addLadder(46, 90);
        addLadder(17, 69);
    }

    // have sanity checks later & make function bool ret type
    void addSnake(int from, int to)
    {
        moveArr[from] = to;
    }

    // have sanity checks later & make function bool ret type
    void addLadder(int from, int to)
    {
        moveArr[from] = to;
    }

    int rollDice()
    {
        return (1 + rand()%6);
    }

    bool isWin(int player)
    {
        if(playersPosition[player] >= mBoardSize)
        {
            return true;
        }
        return false;
    }

    void movePosition(int player, int diceValue)
    {
        int prevPos = playersPosition[player];
        int newPos = prevPos + diceValue;
        if(newPos < 100 && moveArr[newPos] != -1)
        {
            newPos = moveArr[newPos];
        }
        playersPosition[player] = newPos;
    }

    // only one winner
    void startGame()
    {
        int playerTurn = 1;
        while(1)
        {
            int diceVal = rollDice();
            cout << "player" << playerTurn << " got : " << diceVal << endl;
            movePosition(playerTurn, diceVal);
            cout << "newPosition of player " << playerTurn << " is "<< playersPosition[playerTurn] << endl;
            if(isWin(playerTurn))
            {
                cout << "player " << playerTurn << " won." << endl;
                return;
            }

            playerTurn = (playerTurn == mNoOfPlayers)? 1: playerTurn+1;
        }
    }

private:
    int mBoardSize; // board from 1 to mBoardSize
    int *moveArr;
    int *playersPosition;
    int mNoOfPlayers;
};


int main()
{
    SnakeNLadder SnakeNLadderObj(100, 2, true);

    SnakeNLadderObj.startGame();

    return 0;
}
