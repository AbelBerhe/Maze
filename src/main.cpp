#include <iostream>
#include <fstream>
#include <regex>
#include "Maze.h"
#include "Stack.h"


using namespace std;

int main(int argc, char *argv[]) {

    //create maze object
    if (argc != 3) {
        cout<< "3 arguments should be passed!, Valid arguments are program file(Assignment_2), test files(test.txt, text1.txt, test3.txt), output file(e.g text.txt)";
        return 1;
    }

    Maze maze;
    //load maze to vector
    maze.loadToMaze(argv[1]);
    //solve maze
    maze.exploreMaze();
    //clear marked spots
    maze.clearMaze();
    //mark maze
    maze.markMaze();
    //display maze to the console
    maze.displayMaze();
    //write maze to the file
    maze.writeToFile(argv[2]);

    return 0;
}