#include "DFS.h"

void DFS::search(const pose &start, const pose &goal)
{
    ori = &start;
    target = &goal;
    vector<pose> tmp_frontier;
    /* initialize parameters */
    int grid_height = (*map).size();
    int grid_width = (*map)[0].size();

    /* add original into fronteir queue*/
    frontier.emplace_back(start);
    closed_list[start.x][start.y].visited = true;

    /* start Breadth First Search */
    while (!frontier.empty())
    {
        pose expand = frontier.back();
        frontier.pop_back();

        if (expand.x == goal.x && expand.y == goal.y)
        {
            find_path = true;
            cout << "DFS Path constructed! " << endl;
            break;
        }
        else
        {
            for (auto &move : delta_list)
            {
                pose next;
                next.x = expand.x + move.x;
                next.y = expand.y + move.y;
                if (next.x >= 0 && next.x < grid_height && next.y >= 0 && next.y < grid_width 
                && (*map)[next.x][next.y] != true && closed_list[next.x][next.y].visited != true)
                {
                    tmp_frontier.emplace_back(next);
                    closed_list[next.x][next.y].visited = true;
                    closed_list[next.x][next.y].parent.x = expand.x;
                    closed_list[next.x][next.y].parent.y = expand.y;
                    closed_list[next.x][next.y].move = move.move;
                }
            }
        }
        while(!tmp_frontier.empty())
        {   
            frontier.emplace_back(tmp_frontier.back());
            tmp_frontier.pop_back();         
        }
    }
    if (find_path != true)
        cout << "Path can not be found!" << endl;

}

