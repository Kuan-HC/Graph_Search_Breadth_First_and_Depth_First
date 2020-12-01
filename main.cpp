#include <vector>
#include <iostream>

#include "BFS.h"
#include "DFS.h"

#define length 6U

using std::cout;
using std::deque;
using std::endl;
using std::vector;

int main()
{
    /* Set Grid Map */
    vector<vector<bool>> grid = {{0, 1, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 1, 0, 0},
                                 {0, 1, 0, 1, 0, 0},
                                 {0, 1, 0, 0, 0, 0},
                                 {0, 1, 0, 0, 0, 0}};

    /* set start and goal position */
    pose start{0, 0};
    pose goal{5, 5};

    /***************************************
    *   Breadth First Path Planning        *
    * *************************************/
    BFS BFS(grid);
    BFS.search(start, goal);
    BFS.draw_path();

    DFS DFS(grid);
    DFS.search(start, goal);
    DFS.draw_path();


    return 0;
}