#ifndef _BFS_H_
#define _BFS_H_

#include <deque>
#include <vector>
#include <iostream>
#include "main.h"

using std::deque;
using std::vector;
using std::cout;
using std::endl;

typedef struct
{
    int x;
    int y;
} pose;

typedef struct
{
    pose current;
    pose parent;
} node;

class BreadthFirst
{
private:
    pose ori;
    pose target;
    vector<vector<bool>> map;
    vector<vector<bool>> closed;
    int grid_length;
    int grid_width;
    deque<pose> frontier;
    

public:
    BreadthFirst(pose &start, pose &goal, vector<vector<bool>> &map_input);
    void search()
    {
        /* initialize parameters */
        bool find_path = false;
        /* add original into fronteir queue*/
        frontier.emplace_back(ori);
        /* start Breadth First Search */
        while (!frontier.empty())
        {
            pose expand = frontier.front();
            frontier.pop_front();

            if(expand.x == target.x && expand.y == target.y)
            {
                find_path = true;
                std::cout << "Goal achieved! "<< std::endl;
                break;
            }
            else
            {
                
            }
            
        }
    }


};

#endif /* _BFS_H_ */