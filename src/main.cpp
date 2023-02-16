#include <iostream>
#include <fstream>
#include "Maze.h"
#include "Stack.h"


using namespace std;

int main() {
    //create maze object
    Maze maze;
    //load maze to vector
    maze.loadToMaze();
    //solve maze
    maze.exploreMaze();
    //clear marked spots
    maze.clearMaze();
    //mark maze
    maze.markMaze();
    //display maze to the console
    maze.displayMaze();
    //write maze to the file
    maze.writeToFile();

    return 0;
}