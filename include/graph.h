#ifndef GRAPH_H
#define GRAPH_H
#define N 4
#define M 5

typedef struct st
{
    struct st* child[M];
    char codes[N][M];
}node;

class graph{
protected:
    int levels;

public:
    graph();
    node* createnode();
    node* completetree();
    void printtree(node* root);
    node* connecttree(node* x, int level);
    void printnode(node* y);

};





















#endif // GRAPH_H


