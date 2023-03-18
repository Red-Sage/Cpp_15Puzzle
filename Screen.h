#ifndef REDSAGES_15PUZZLE_SCREEN_H_
#define REDSAGES_15PUZZLE_SCREEN_H_

#include <ncurses.h>
#include "Board.h"

namespace Screen
{
    void init_screen();
    void render(const Board &board);
    void render_game_complete(const Board &Board);
}

#endif