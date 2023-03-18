#include <iostream>
#include <string>
#include <memory>
#include "Puzzle.h"
#include "Board.h"
#include "Screen.h"


enum class Direction{UP=259, RIGHT=261, DOWN=258, LEFT=260, QUIT=113};


bool play()
{
    // Initalize
    // TODO: Allow the user to select the dimensions of the board up to a 
    //       resonable number.
    Board game_board(4);
    Screen::init_screen();
    Screen::render(game_board);
    int user_in;
    Direction test_dir{259};
    bool quit = false;
    while(!quit && !game_board.is_complete())
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
        Screen::render(game_board);

        if(game_board.is_complete())
        {
            Screen::render_game_complete(game_board);
            user_in = getch();
            if(user_in == 121)
            {
                endwin();
                return false;
            }
            else
            {
                endwin();
                return true;
            }
        }
    }

    endwin();
    return quit;
}

int main()
{
    // Main game loop. Plays the game as long as the user has not quit.
    bool usr_quit = false;
    while(!usr_quit)
    {
        usr_quit = play();
    }

    return 0;    
}