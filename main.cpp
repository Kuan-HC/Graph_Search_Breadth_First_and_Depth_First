#include <iostream>
#include <vector>
#include <deque>
#include <stdio.h>
#include <memory>
#include <string.h>

#define length 6U
#define HEIGHT 6U
#define WIDTH 6U

using std::cout;
using std::endl;
using std::vector;
using std::deque;

typedef struct
{
    int x;
    int y;
} Point;

enum Direction
{
    kUp,
    kRight,
    kLeft,
    kDown,   
    unknown
};

class Search_Pt
{
public:
    Search_Pt() : x(-1), y(-1){};
    Search_Pt(int current_x, int current_y) : x(current_x), y(current_y){};
    /*member*/
    int x;
    int y;
    
    bool visited{false};
    Direction action{unknown};
    Point parent{-1, -1};
    /* member function */
};


typedef struct
{
    int x;
    int y;
    Direction action;
} Delta;

std::vector<Delta> delta_list = {{-1, 0, kUp}, {0, 1, kRight}, {0, -1, kLeft}, {1, 0, kDown}}; /*move: up, right, left, down */

void path_search(const std::vector<std::vector<bool>> &grid_name, std::vector<std::vector<Direction>> &Direction,
                 Point food, Point head, const int &width, const int &height);

/****************************************
*   Set Grid Map                        *
* **************************************/
bool grid[HEIGHT][WIDTH] = {{0, 1, 0, 0, 0, 0},
                            {0, 0, 0, 1, 0, 0},
                            {0, 0, 0, 1, 0, 0},
                            {0, 1, 0, 1, 0, 0},
                            {0, 1, 0, 0, 0, 0},
                            {0, 1, 0, 0, 0, 0}};


int main()
{    
    
    std::vector<std::vector<Direction>> direction_arr(length, std::vector<Direction>(length, unknown));

    /****************************************
    *   Set Start and Goal                  *
    * **************************************/
    Point start{0, 0};
    Point goal{1, 5};


    /***************************************
    *   Path Planning  function            *
    * *************************************/

    path_search(grid, direction_arr, start, goal);  

    for (auto row : direction_arr)  
    {
        for(auto i : row)
            cout << i << " ";
        cout<< endl;
    }
    
    return 0;
}

void path_search(const bool* grid_name, std::vector<std::vector<Direction>> &direction_arr, Point start, Point goal)
{
    /* initialize parameters */
    bool find_path = false;
    //vector<vector <Search_Pt> > close_mtx ( HEIGHT, vector <Search_Pt>(WIDTH));
    deque<Point> frontier;

    
    /*Set a Grid to record visted spot */
    bool visited_grid[HEIGHT][WIDTH];
    memset(visited_grid, false, sizeof(grid));    

    /* set first point and add it into fronteir queue*/
    Search_Pt start(start.x, start.y);
    frontier.emplace_back(start);
    /* set first point as visited */
    visited_grid[start.x][start.y] = true;
    
    /* Breadth-First Search Algorithm*/
    while (!frontier.empty())
    {
        Search_Pt P2expand = open_list.back();
        open_list.pop_back();

        if (P2expand.x == food.x && P2expand.y == food.y)
        {
            find_path = true;
            std::cout << "reach goal counter " << std::endl;
            break;
        }
        else
        {
            for (auto &move : delta_list)
            {
                int next_x = P2expand.x + move.x;
                int next_y = P2expand.y + move.y;
                if (next_x >= 0 && next_x < width && next_y >= 0 && next_y < height && grid_name[next_x][next_y] != true && close_mtx[next_x][next_y].visited != true)
                {
                    close_mtx[next_x][next_y].cost = P2expand.cost + 1U;
                    close_mtx[next_x][next_y].parent.x = P2expand.x;
                    close_mtx[next_x][next_y].parent.y = P2expand.y;
                    close_mtx[next_x][next_y].action = move.action;
                    close_mtx[next_x][next_y].x = next_x;
                    close_mtx[next_x][next_y].y = next_y;

                    open_list.emplace_back(close_mtx[next_x][next_y]);
                    close_mtx[next_x][next_y].visited = true;
                }
            }
        }
    }
    if (find_path == true)
    {
        Search_Pt* current = &close_mtx[food.x][food.y];        

        while (current->x != start.x || current->y != start.y)
        {
            direction_arr[current->parent.x][current->parent.y] = current->action;
            current = &close_mtx[current->parent.x][current->parent.y];
        } 
    }
}