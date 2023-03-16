#include <assert.h>

#include "../Board.h"
#include "../Board.cpp"

int main()
{
    // This code contains a few test to make sure the board logic is good
    
    // Test initialization
    Board board(4, 4);
    assert(board.get_board_size() == 16);
    std::cout << "Test initalization: Pass" << std::endl;

    assert(false);

    // Test 






    return 1;
}


