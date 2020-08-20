#include <vector>
#include <iostream>

#include "BFS.h"

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
    *   Path Planning  function            *
    * *************************************/
    BreadthFirst map_1(grid);
    map_1.search(start, goal);
    map_1.draw_path();

    return 0;
}