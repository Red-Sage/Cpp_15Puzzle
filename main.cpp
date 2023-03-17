#include <iostream>
#include <string>
#include <ncurses.h>
#include "Puzzle.h"
#include "Board.h"
#include "Board.cpp"

void gameLoop()
{

}
int main()
{

    // Initalize
    clrscr();
    int user_in;
    Board game_board();

    while(true)
    {
        // User Input
        user_in = _getch();
        
        _putch(user_in);

        // Update State

    }

    


    return 1;
    
}