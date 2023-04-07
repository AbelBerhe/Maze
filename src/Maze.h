//
// Created by abelg on 2023-02-14.
//

#ifndef ASSIGNMENT_2_MAZE_H
#define ASSIGNMENT_2_MAZE_H

#include <vector>
#include "Stack.h"
#include <string>

class Maze {
private:
    Stack stack;
    std::vector<std::vector<char>> maze;
public:
    Maze();

    ~Maze();

    void displayMaze();

    void loadToMaze(std::string file);

    void exploreMaze();

    void clearMaze();

    void markMaze();

    void writeToFile(std::string file);
    //bool isNotVisited(int x, int y);
};

#endif //ASSIGNMENT_2_MAZE_H
