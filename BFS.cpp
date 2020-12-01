#include "BFS.h"

BFS::BFS(const vector<vector<bool>> &map_input)
{
    vector<close_node> tmp_row(map_input[0].size());
    vector<vector<close_node>> tmp_grid(map_input.size(), tmp_row);
    closed_list = std::move(tmp_grid);
    map = &map_input;
}

void BFS::search(const pose &start, const pose &goal)
{
    ori = &start;
    target = &goal;

    /* initialize parameters */
    int grid_height = (*map).size();
    int grid_width = (*map)[0].size();


    /* add original into fronteir queue*/
    frontier.emplace_back(start);
    closed_list[start.x][start.y].visited = true;

    /* start Breadth First Search */
    while (!frontier.empty())
    {
        pose expand = frontier.front();
        frontier.pop_front();

        if (expand.x == goal.x && expand.y == goal.y)
        {
            find_path = true;
            cout << "BSS Path constructed! " << endl;
            break;
        }
        else
        {
            for (auto &move : delta_list)
            {
                pose next;
                next.x = expand.x + move.x;
                next.y = expand.y + move.y;
                if (next.x >= 0 && next.x < grid_height && next.y >= 0 && next.y < grid_width && (*map)[next.x][next.y] != true && closed_list[next.x][next.y].visited != true)
                {
                    frontier.emplace_back(next);
                    closed_list[next.x][next.y].visited = true;
                    closed_list[next.x][next.y].parent.x = expand.x;
                    closed_list[next.x][next.y].parent.y = expand.y;
                    closed_list[next.x][next.y].move = move.move;
                }
            }
        }
    }
    if (find_path != true)
        cout << "Path can not be found!" << endl;
}



void BFS::draw_path()
{
    vector<vector<char>> path(closed_list.size(), vector<char>(closed_list[0].size(), ' '));

    if (find_path != true)
    {
        cout << "No path was build" << endl;
    }
    else
    {
        close_node *current = &closed_list[target->x][target->y];
        path[target->x][target->y] = '@';
        while (current->parent.x != ori->x || current->parent.y != ori->y)
        {
            path[current->parent.x][current->parent.y] = current->move;
            current = &closed_list[current->parent.x][current->parent.y];
        }
        path[current->parent.x][current->parent.y] = current->move;
    }
    /* print path */
    for (auto row : path)
    {
        for (auto i : row)
            cout << i << " ";
        cout << endl;
    }
}

