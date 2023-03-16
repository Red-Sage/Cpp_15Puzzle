#include <gtest/gtest.h>

#include "../Board.h"
#include "../Board.cpp"

TEST(BoardTest, Size)
{
    // Test board constructor    
    Board board(4);
    EXPECT_EQ(board.get_num_tiles(), 16) << "Board size incorrect";
}

TEST(BoardTest, IsRandom)
{
    Board board_1(4);
    Board board_2(4);

    int count = 0;
    for(int i=0; i < board_1.get_size(); i++)
    {
        for(int j=0; j<board_1.get_size(); j++)
        {
            if(board_1.get_value(i, j) == board_2.get_value(i, j)) count++;
        }
    }

    std::cout << count;
    EXPECT_TRUE((count < board_1.get_num_tiles())) << "Boards are the same";

}

TEST(BoardTest, NotValidDuplicate)
{
    // This test checks that duplicats in the permutation fail
    std::vector<int> test_vect{1,1,2,3,4,5,6,7,8};
    EXPECT_FALSE(Board::is_valid(test_vect));
}

TEST(BoardTest, IsValidUnique)
{
    // This test checks that a simple valid board passes
    std::vector<int> test_vect{1, 3, 4, 2, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    EXPECT_TRUE(Board::is_valid(test_vect));
}

TEST(BoardTest, NotSquareBoard)
{
    // Test a permutation that does not represent a square board
    std::vector<int> test_vect{1, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    EXPECT_FALSE(Board::is_valid(test_vect));
}

TEST(BoardTest, UnsolvableBoard)
{
    // Test a permutation that can't be solved (classic case)
    std::vector<int> test_vect{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 14, 16};
    EXPECT_FALSE(Board::is_valid(test_vect)) << "Unsolvable board passed!";
}

TEST(BoardTest, RandomSolvableBoard)
{
    // Test a random solvable board
    std::vector<int> test_vect{14, 1, 11, 15, 8, 5, 12, 16, 3, 6, 2, 9, 4, 7, 10, 13};
    EXPECT_TRUE(Board::is_valid(test_vect));
}

TEST(BoardTest, UnsolvableBoard2)
{
    // Annother instance of an unsolvable board
    std::vector<int> test_vect{15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 16};
    EXPECT_FALSE(Board::is_valid(test_vect));
}

TEST(BoardTest, TooSmallBoard)
{
    // Empty board
    std::vector<int> test_vect{1};
    EXPECT_FALSE(Board::is_valid(test_vect));
}

TEST(BoardTest, MoveUpOne)
{
    std::vector<int> board_init{1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 11, 12, 13, 14, 15, 16};
    Board test_board(board_init);

    size_t blank_loc = test_board.get_tile_idx(16);
    test_board.move_up();

    EXPECT_EQ(blank_loc-4, test_board.get_tile_idx(16));

}

TEST(BoardTest, MoveUpMany)
{
    std::vector<int> board_init{1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 11, 12, 13, 14, 15, 16};
    Board test_board(board_init);

    // move up too many times
    for(int i=0; i<5; i++)
    {
        test_board.move_up();
    }
    
    EXPECT_EQ(3, test_board.get_tile_idx(16)); 
}

TEST(BoardTest, MoveRightOne)
{
    std::vector<int> board_init{1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 11, 12, 13, 14, 16, 15};
    Board test_board(board_init);

    size_t blank_loc = test_board.get_tile_idx(16);
    test_board.move_right();

    EXPECT_EQ(blank_loc+1, test_board.get_tile_idx(16));

}

TEST(BoardTest, MoveRightMany)
{
    std::vector<int> board_init{1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 11, 12, 13, 14, 16, 15};
    Board test_board(board_init);

    // move right too many times
    for(int i=0; i<2; i++)
    {
        test_board.move_right();
    }
    
    EXPECT_EQ(15, test_board.get_tile_idx(16)); 
}

TEST(BoardTest, MoveDownOne)
{
    std::vector<int> board_init{1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 11, 16, 13, 14, 15, 12};
    Board test_board(board_init);

    size_t blank_loc = test_board.get_tile_idx(16);
    test_board.move_down();

    EXPECT_EQ(15, test_board.get_tile_idx(16));

}

TEST(BoardTest, MoveDownMany)
{
    std::vector<int> board_init{1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 11, 16, 13, 14, 15, 12};
    Board test_board(board_init);

    // move down too many times
    for(int i=0; i<2; i++)
    {
        test_board.move_down();
    }
    
    EXPECT_EQ(15, test_board.get_tile_idx(16)); 
}

TEST(BoardTest, MoveLeftOne)
{
    std::vector<int> board_init{1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 11, 12, 13, 14, 15, 16};
    Board test_board(board_init);

    size_t blank_loc = test_board.get_tile_idx(16);
    test_board.move_left();

    EXPECT_EQ(14, test_board.get_tile_idx(16));

}

TEST(BoardTest, MoveLeftMany)
{
    std::vector<int> board_init{1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 11, 12, 13, 14, 15, 16};
    Board test_board(board_init);

    // move left too many times
    for(int i=0; i<5; i++)
    {
        test_board.move_left();
    }
    
    EXPECT_EQ(12, test_board.get_tile_idx(16)); 
}

TEST(BoardTest, SetupInvalidBoard)
{
    std::vector<int> board_init{1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 11, 12, 13, 14, 16};
    try
    {
        Board test_board(board_init);
        FAIL() << "Expected invalid_argument";
    }
    catch(std::invalid_argument const & e)
    {
        EXPECT_EQ(e.what(), std::string("Attempt to construct invalid game board."));
    }
    catch(...)
    {
        FAIL() << "Expected std::invalid_argument";
    }
    
}

