#include <iostream>
#include <string>
#include <ncurses.h>
#include <memory>
#include "Puzzle.h"
#include "Board.h"
#include "Screen.h"
//#include "Screen.cpp"


enum class Direction{UP=259, RIGHT=261, DOWN=258, LEFT=260, QUIT=113};

int main()
{

    // Initalize
    Board game_board(4);
    Screen screen;
    screen.render(game_board);
    int user_in;
    Direction test_dir{259};
    int i = 0;
    bool quit = false;
    while(!quit)
    {
        // User Input
        user_in = getch();
        Direction direction{user_in};
        
        // Update State
        switch(direction)
        {
            case Direction::UP:
                game_board.move_up();
                break;
            case Direction::RIGHT:
                game_board.move_right();
                break;
            case Direction::DOWN:
                game_board.move_down();
                break;
            case Direction::LEFT:
                game_board.move_left();
                break;
            case Direction::QUIT:
                quit = true;
                break;


        }
        
        //Render
        screen.render(game_board);
        i++;
        

    }

    return 0;    
}