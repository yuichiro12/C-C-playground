#include <stdio.h>
#include <graphviz/gvc.h>

int* dfs(int *);

typedef struct graph {
  int row;
  int col;
  int D[][];
  int weight[];
  
};

int main(void)
{
  graph G;
  G.row = 6;
  G.col = 8;
  G.D[G.row][G.col] = {
    {1, 0, 1, -1, 1, 0, 0, 0},
    {-1, -1, 0, 0, 0, 0, 0, 0},
    {0, 1, -1, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, -1, -1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, -1},
    {0, 0, 0, 0, 0, 0, -1, 0},
  };
  G.weight = {1, 2, 4, 8, 3, 5, 7, 4};

  return 0;
}

int* dfs(int *graph)
{
  return graph;
}
