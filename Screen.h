#ifndef REDSAGES_15PUZZLE_SCREEN_H_
#define REDSAGES_15PUZZLE_SCREEN_H_

#include <ncurses.h>
#include <vector>
#include "Board.h"

class Screen
{
public:
    Screen();
    ~Screen();
    void render(const Board &Board);

};

#endif //REDSAGES_15PUZZLE_SCREEN_H_