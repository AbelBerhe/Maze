//
// Created by abelg on 2023-02-14.
//
#include <vector>
#include <fstream>
#include <iostream>
#include "Maze.h"
#include "Coordinate.h"


Maze::Maze() = default;

Maze::~Maze() = default;


//load maze to double dimensional vector
void Maze::loadToMaze() {
    //declare file reader and passing the file.
    //std::ifstream  fin(R"(C:\Users\abelg\CLionProjects\assignment-2-Abel-Berhe\docs\maze.txt)");
    //std::ifstream  fin(R"(C:\Users\abelg\CLionProjects\assignment-2-Abel-Berhe\tests\test.txt)");
    //std::ifstream  fin(R"(C:\Users\abelg\CLionProjects\assignment-2-Abel-Berhe\tests\test2.txt)");
    std::ifstream fin(R"(C:\Users\abelg\CLionProjects\assignment-2-Abel-Berhe\tests\test3.txt)");
    std::string line;
    //check if file exist
    if (fin.is_open()) {
        while (getline(fin, line)) {
            //vector to store row
            std::vector<char> row;
            for (char c: line) {
                if (c != '\0') {
                    row.push_back(c);
                }
            }
            //store row in the 2D vector
            maze.push_back(row);
        }

    } else {
        std::cout << "File not found" << std::endl;
    }
    fin.close();
}

//SolveMaze
void Maze::exploreMaze() {
    //declare coordinate object;
    Coordinate coordinate;
    //flag to check for exit
    bool isExit = true;
    //Starting point at maze
    coordinate.x = 1;
    coordinate.y = 0;
    //start maze that starting point
    maze[coordinate.x][coordinate.y] = '#';
    //pass the starting coordinates to stack
    stack.push({coordinate.x, coordinate.y});
    while (isExit) {
        //coordinates should be greater than the starting point
        if (coordinate.x < 1 && coordinate.y < 0) {
            std::cout << "Error!- Outside of the Maze grid" << std::endl;
            break;
        } else {
            //check if left for movement
            if (maze[coordinate.x][coordinate.y - 1] == ' ' && coordinate.y > 1) {
                //mark the path
                maze[coordinate.x][coordinate.y - 1] = '#';
                //add coordinates to the stack
                stack.push({coordinate.x, coordinate.y - 1});
                coordinate.y--;
                //check bottom for movement
            } else if (maze[coordinate.x + 1][coordinate.y] == ' ') {
                //mark the path
                maze[coordinate.x + 1][coordinate.y] = '#';
                //add coordinates to the stack
                stack.push({coordinate.x + 1, coordinate.y});
                coordinate.x++;
                //check right for movement
            } else if (maze[coordinate.x][coordinate.y + 1] == ' ') {
                //mark the path
                maze[coordinate.x][coordinate.y + 1] = '#';
                //add coordinates to the stack
                stack.push({coordinate.x, coordinate.y + 1});
                coordinate.y++;
                //check top for movement
            } else if (maze[coordinate.x - 1][coordinate.y] == ' ') {
                //mark the path
                maze[coordinate.x - 1][coordinate.y] = '#';
                //add coordinates to the stack
                stack.push({coordinate.x - 1, coordinate.y});
                coordinate.x--;

            } else {
                //Dead end, maze loops back the same path
                //check left to move back
                if (maze[coordinate.x][coordinate.y - 1] == '#') {
                    //mark the path with D to indicate it is a dead end path
                    maze[coordinate.x][coordinate.y] = 'D';
                    //remove coordinates from stack
                    stack.pop();
                    coordinate.y--;
                    //check bottom to move back
                } else if (maze[coordinate.x + 1][coordinate.y] == '#') {
                    //mark the path with D to indicate it is a dead end path
                    maze[coordinate.x][coordinate.y] = 'D';
                    //remove coordinates from the stack
                    stack.pop();
                    coordinate.x++;
                    //check right to move back
                } else if (maze[coordinate.x][coordinate.y + 1] == '#') {
                    //mark the path with D to indicate it is a dead end path
                    maze[coordinate.x][coordinate.y] = 'D';
                    //remove coordinates from the stack
                    stack.pop();
                    coordinate.y++;
                    //check top to move back
                } else if (maze[coordinate.x - 1][coordinate.y] == '#') {
                    //mark the path with D to indicate it is a dead end path
                    maze[coordinate.x][coordinate.y] = 'D';
                    //remove coordinates from the stuck
                    stack.pop();
                    coordinate.x--;
                }
            }
        }

        //check if the coordinates are the at end
        if (coordinate.x == 49 && coordinate.y == 50) {
            isExit = false;
        }
    }

}

//clear maze
void Maze::clearMaze() {
    //loop through maze and clear any marked characters
    for (int i = 0; i < maze.size(); i++) {
        for (int j = 0; j < maze[i].size(); j++) {
            if (maze[i][j] == 'D' || maze[i][j] == '#') {
                maze[i][j] = ' ';
            }
        }
    }
}

//mark maze
void Maze::markMaze() {
    //vector stores x coordinates
    std::vector<int> xNums = stack.xCoordinates();
    //vector stores y coordinates
    std::vector<int> yNums = stack.yCoordinates();
    //loop through maze and mark spot with # character at the right coordinates using stack
    for (int i = 0; i < yNums.size(); i++) {
        maze[xNums[i]][yNums[i]] = '#';
    }
}

//display maze in the console
void Maze::displayMaze() {
    //loop through the maze and display the result to the console
    for (auto &i: maze) {
        for (char j: i) {
            std::cout << j << "";
        }
        std::cout << std::endl;
    }

}

//write to file
void Maze::writeToFile() {
    //declare file writer
    //std::ofstream outPut(R"(C:\Users\abelg\CLionProjects\assignment-2-Abel-Berhe\solved\maze.txt)");
    //std::ofstream outPut(R"(C:\Users\abelg\CLionProjects\assignment-2-Abel-Berhe\solved\test.txt)");
    //std::ofstream outPut(R"(C:\Users\abelg\CLionProjects\assignment-2-Abel-Berhe\solved\test1.txt)");
    std::ofstream outPut(R"(C:\Users\abelg\CLionProjects\assignment-2-Abel-Berhe\solved\test2.txt)");
    //check if file exist
    if (outPut.is_open()) {
        for (auto &i: maze) {
            for (char j: i) {
                //write characters to  file
                outPut << j << "";
            }
            //create space after each line
            outPut << std::endl;
        }
    } else {
        std::cout << "File not found" << std::endl;
    }
    outPut.close();
}












