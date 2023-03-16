#include <iostream>
#include "Puzzle.h"
#include "Board.h"
#include "Board.cpp"

int main()
{
    std::cout << "Hello World" << std::endl;
    Board board{4};
    board.print();
    for(int i=0; i<=5; i++)
    {
        
    }
    board.print();
    board.move_left();
    board.print();
    board.move_left();
    board.print();
    board.move_left();
    board.print();
    board.move_left();
    board.print();
    


    return 1;
    
}