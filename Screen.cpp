#include "Screen.h"

int header_rows = 3;

void Screen::init_screen()
{
    // Initalizes the screen for use with ncurses
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    erase();
    box(stdscr, 0, 0);
    curs_set(0);
    move(1,1);
    printw("Cpp 15 Puzzle:");
    move(2,1);
    printw("Use the arrow keys to move or q to quit.");
    move(3,1);
    printw("Score:");
    refresh();
}

void Screen::render(const Board &board)
{
    // Renders the game state
    int value;
    for(size_t i=0; i < board.get_size(); i++)
    {
        move(i+header_rows+1, 3);
        for(size_t j = 0; j< board.get_size(); j++)
        {
            value = board.get_value(i, j);
            if(value == board.get_blank() && !board.is_complete())
            {
                wprintw(stdscr, "   ");
            }
            else
            {
                wprintw(stdscr, "%3d", board.get_value(i, j));
            }
        }
        
    }

    move(3, 8);
    printw("%4d", board.get_score());
    refresh();
    
}

void Screen::render_game_complete(const Board &board)
{
    // Tells the user they completed the puzzle and asks if they want to play again.
    int start_row = header_rows + board.get_size() + 1;
    move(start_row, 1);
    printw("You Solved the Puzzle!");
    move(start_row+1, 1);
    printw("Would you like to play again? Press y for yes and anthing else to qut.");
    refresh();
}