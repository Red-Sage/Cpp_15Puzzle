#ifndef REDSAGES_15PUZZLE_BOARD_H_
#define REDSAGES_15PUZZLE_BOARD_H_

#include <vector>
#include <stddef.h>
#include <cstdlib>
#include <tuple>
#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <unordered_set>
#include <cmath>
#include <numeric>

using std::size_t;

// Class defining a square game board. The classic 15 puzzle is a 4x4 square 
// with 15 tiles and one blank.
class Board
{
public:
    Board( size_t size_in );
    Board( std::vector<int> board_init );
    void move_up();
    void move_right();
    void move_down();
    void move_left();
    void print();
    int get_value(size_t row, size_t col) const;
    size_t get_tile_idx(int tile);
    size_t get_num_tiles();
    size_t get_size() const;
    int get_blank() const;
    static bool is_valid(std::vector<int> permutation);

private:
    size_t size_;
    int blank_;
    std::vector<int> board_;
    size_t loc_to_idx(size_t row, size_t col) const;
    void swap_tiles(size_t blank_idx, size_t idx);
    void randomize();
    

};


#endif