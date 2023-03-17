# Cpp_15Puzzle
C++ 15 Puzzle  Implementation

# Game Loop

```mermaid
flowchart TD
    main[Main Loop] -> user[User Input]
    user -> update[Update State]
    update -> render[Render]
    render -> user
``` 

# The Game Board
The game board is a class that represent the state of the game and the game logic.
The board itself is represented by a vector of integers. The integers are 
required to start at 1 and end at a perfect square. That is, the game board
must be square. This is enforced by in the class.
