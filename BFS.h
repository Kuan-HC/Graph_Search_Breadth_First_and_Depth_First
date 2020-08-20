#ifndef _BFS_H_
#define _BFS_H_

#include <deque>
#include <vector>
#include <iostream>

using std::cout;
using std::deque;
using std::endl;
using std::vector;

typedef struct
{
    int x;
    int y;
} pose;

typedef struct
{
    bool visited{false};
    pose parent{-1, -1};
    char move{' '};
} close_node;

typedef struct
{
    int x;
    int y;
    char move;
} Delta;

class BreadthFirst
{
private:
    bool find_path{false};
    vector<vector<close_node>> closed_list;
    deque<pose> frontier;
    const std::vector<Delta> delta_list = {{-1, 0,'^'}, {0, 1,'>'}, {0, -1,'<'}, {1, 0,'v'}}; /*move: up, right, left, down */

    const pose* ori;
    const pose* target;
    const vector<vector<bool>> *map;

public:
    BreadthFirst(const vector<vector<bool>> &map_input);
    void search(const pose &start, const pose &goal);
    void draw_path();
};

#endif /* _BFS_H_ */