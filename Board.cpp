#include "Board.h"


Board::Board(size_t size_in) : size_{size_in}
{
    // Game boards must be square
    
    for(int i=1; i <= size_*size_; ++i)
    {
        board_.push_back(i);
    }
    //Set the blank tile
    blank_ = board_.back();   

    bool valid = false;
    while(!valid)
    {
        randomize();
        valid = Board::is_valid(board_);
    }    
}

Board::Board( std::vector<int> board_init )
{
    // If the vector passed is a valid board it will be constructed if not,
    // an error is returned. The primairy purpose of this function is to
    // facilitate testing.

    if(is_valid(board_init))
    {
        auto it = max_element(board_init.begin(), board_init.end());
        size_t idx = it - board_init.begin();
        size_ = (size_t)sqrt(board_init.size());
        blank_ = board_init[idx];
        board_ = board_init;
    } 
    else
    {
        throw std::invalid_argument("Attempt to construct invalid game board.");
    };
}
void Board::randomize()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(board_.begin(), board_.end(), g);
}

void Board::move_up()
{
    size_t blank_idx = get_tile_idx(blank_);

    if(blank_idx > size_-1)
    {
        swap_tiles(blank_idx, blank_idx-size_);
    }
    
    score_ = calc_points() - ++moves_;
}

void Board::move_right()
{
    size_t blank_idx = get_tile_idx(blank_);

    if(blank_idx%size_ < (size_- 1 ))
    {
        swap_tiles(blank_idx, blank_idx+1);
    }

    score_ = calc_points() - ++moves_;
}

void Board::move_down()
{
    size_t blank_idx = get_tile_idx(blank_);

    if(blank_idx+size_ < board_.size())
    {
        swap_tiles(blank_idx, blank_idx+size_);
    }

    score_ = calc_points() - ++moves_;
}

void Board::move_left()
{
    size_t blank_idx = get_tile_idx(blank_);

    if(blank_idx%size_ > 0)
    {
        swap_tiles(blank_idx, blank_idx-1);
    }

    score_ = calc_points() - ++moves_;
}

void Board::swap_tiles(size_t blank_idx, size_t idx)
{
    // This function will swap any two tiles 
    board_[blank_idx] = board_[blank_idx] + board_[idx];
    board_[idx] = board_[blank_idx] - board_[idx];
    board_[blank_idx] = board_[blank_idx] - board_[idx]; 
}

size_t Board::loc_to_idx(size_t row, size_t col) const
{
    return row*size_+col;
}

size_t Board::get_num_tiles()
{
    return size_*size_;
}

size_t Board::get_tile_idx(int tile)
{
    auto it = std::find(board_.begin(), board_.end(), tile);
    size_t idx = it - board_.begin();
    return idx;

}

void Board::print()
{
    for(size_t i=0; i<size_*size_; i++)
    {
        if(i%size_==0 && i!=0) std::cout << std::endl;
        int value = board_[i];
        if(value == blank_)
        {
            std::cout << std::setw(3) << ' ';
        }
        else
        {
            std::cout << std::setw(3) << board_[i];
        }
        
        
    }
    std::cout << std::endl;
}

int Board::get_value(size_t row, size_t col) const
{
    size_t idx = loc_to_idx(row, col);
    return board_[idx];
}

size_t Board::get_size() const
{
    return size_;
}

bool contains_all(std::vector<int> p)
{
    // Helper function that ensures that all elements in p are also in test_v

    std::vector<int> v(p.size());
    std::iota(v.begin(), v.end(), 1);
    std::sort(p.begin(), p.end());
    return p == v;
}

bool isSquare(std::vector<int> p)
{
    auto size = p.size();
    if(size >= 0)
    {
        auto sr = sqrt(size);
        return(sr*sr == size);
    }
    return false;
}

int Board::get_blank() const
{
    return blank_;
}

int Board::get_score() const
{
    return score_;
}

bool Board::is_complete() const
{
    return is_complete_;
}

int Board::calc_points()
{
    int points = 0;
    for(size_t i=0; i<board_.size(); i++)
    {
        if(board_[i] == i+1)
        {
             points = points+10;
             if(i == board_.size() - 1) {is_complete_ = true;};
        }
        else break;
    }

    return points;
}

bool Board::is_valid(std::vector<int> p)
{
    // This static function validates that the permutation (p) meets the requirements
    // of the game. The board is represented by integers increasing from one to
    // size^2. 
    
    
    //check some simple conditions that must be true for the board to be valid
    if(p.size() < 4){ return false; }
    
    if(!isSquare(p)){ return false; };

    if(!contains_all(p)){ return false; }; // This will also catch cases where the board is not squre but is not explicit

    // Only some boards are solvable. This has to do with even and odd permutations.
    // Check here for more info: 
    
    // Calculate the number of moves to place the blank where it appears of board.
    // We assume that irrespective of number of tiles and shape of board, the
    // blank tile is the one with the highest value.
    size_t size = (size_t)sqrt(p.size());
    auto blank_it = std::max_element(p.begin(), p.end());
    size_t blank_idx = std::distance(p.begin(),  blank_it);
    size_t blank_row = (size_t)std::floor(blank_idx/size);
    size_t blank_col = blank_idx - (blank_row * size);
    size_t moves = (size - 1 - blank_row) + (size - 1 - blank_col);

    // Calculate the number of transpositions required to put the puzzle in the
    // solved state.
    int num_trans = 0;
    size_t num_idx;
    for(int tile_num = 1; tile_num < size*size; tile_num++)
    {
        auto num_it = std::find(p.begin(), p.end(), tile_num);
        num_idx = std::distance(p.begin(), num_it);

        if(num_idx != tile_num-1)
        {
            p[num_idx] = p[tile_num-1];
            p[tile_num-1] = tile_num;
            num_trans++;
        }
    }

    if(moves%2 != num_trans%2){ return false; };

    return true;
}





