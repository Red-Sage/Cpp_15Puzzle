#include "Screen.h"

Screen::Screen()
{
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    box(stdscr, 0, 0);
    curs_set(0);
    move(1,1);
    printw("Cpp 15 Puzzle:");
    move(2,1);
    printw("Use the arrow keys to move or q to quit.");
    refresh();
}

Screen::~Screen()
{
    endwin();
}

void Screen::render(const Board &board)
{
    
    int value;
    for(size_t i=0; i < board.get_size(); i++)
    {
        move(i+3, 3);
        for(size_t j = 0; j< board.get_size(); j++)
        {
            value = board.get_value(i, j);
            if(value == board.get_blank())
            {
                wprintw(stdscr, "   ");
            }
            else
            {
                wprintw(stdscr, "%3d", board.get_value(i, j));
            }
        }
        
    }
    refresh();
    
}