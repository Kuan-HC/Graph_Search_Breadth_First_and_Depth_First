#ifndef _DFS_H_
#define _DFS_H_

#include "BFS.h"

class DFS: public BFS{
    public:
    DFS(const vector<vector<bool>> &map_input): BFS(map_input){};
    void search(const pose &start, const pose &goal);
};

#endif /* _DFS_H_ */