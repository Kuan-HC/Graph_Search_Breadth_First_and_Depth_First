#include "BFS.h"

BreadthFirst::BreadthFirst(pose &start, pose &goal, vector<vector<bool>> &map_input)
{
    ori = start;
    target = goal;
    map = map_input;

    vector<bool> tmp_row(map_input[0].size(), 0);
    vector<vector<bool>> tmp_grid(map_input.size(), tmp_row);
    closed = tmp_grid;
}