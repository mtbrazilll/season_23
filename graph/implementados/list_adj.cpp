#include <bits/stdc++.h>

using namespace std;

#define MAXV 1000

bool processed[MAXV+1];
bool discovered[MAXV+1];
int parent[MAXV+1];

typedef struct edgenode{
    int y;
    int weight;
    struct edgenode *next;
}edgenode;

typedef struct {
    edgenode *edges[MAXV+1];
    int degree[MAXV+1];
    int nvertices;
    int nedges;
    int directed;
}graph;

void initializa_graph(graph *g, bool directed)
{

    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;

    for (int i = 1; i <= MAXV; i++){
        g->degree[i] = 0;
        g->edges[i] = NULL;
    }
    
}

void insert_edge(graph *g, int x, int y, bool directed){

    edgenode *p;

    p = (edgenode *)malloc(sizeof(edgenode));
    p->weight = 0;
    p->y = y;
    p->next = g->edges[x];

    g->edges[x] = p;
    g->degree[x] ++;

    if (directed == false)
        insert_edge(g,y,x,true);
    else
        g->nedges ++;


}

void print_graph(graph *g)
{
    edgenode *p;
    
    for (int i = 1; i < g->nvertices; i++)
    {
        printf("%d:", i);
        p = g->edges[i];
        while (p != NULL){
            printf(" %d", p->y);
            p = p->next;
        }
        printf("\n");
    }
    
}

void initializa_search(graph *g){

    for (int i = 0; i <= g->nvertices; i++){
        processed[i] = false;
        discovered[i] = false;
        parent[i] = -1;
    }
}

void process_vertex_early(int v){
    printf("%d ", v);
}

void process_vertex_late(int v){}

void process_edge(int v, int y){}

void bfs(graph *g, int start)
{
    queue<int> q;

    int v;
    int y;
    edgenode *p;

    q.push(start);
    discovered[start] = true;
    
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        process_vertex_early(v);
        processed[v] = true;
        p = g->edges[v];

        while (p != NULL)
        {
            y = p->y;
            if ( (!processed[y]) || g->directed){
                process_edge(v,y);
            }
            if ( !discovered[y] ){
                q.push(y);
                discovered[y] = true;
                parent[y] = v;
            }

            p = p->next;
        }
        process_vertex_late(v);
        
    }
    


}

void find_path(int start, int end, int *parent)
{
    if ( start == end || end == -1 )
        printf("\n%d", end);
    
    else {
        find_path(start,parent[end],parent);
        printf("\n%d", end);
    }

}

void connected_components(graph *g){

    int c = 0;

    initializa_search(g);

    for (int i = 1; i < g->nvertices; i++)
    {
        if (!discovered[i])
        {
            c = c + 1;
            printf("Component %d:", c);
            bfs(g,i);
            printf("\n");
        }
        
    }
    
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    graph *g = (graph *) malloc(sizeof(graph));
    initializa_graph(g,false);


    insert_edge(g,1,8,false);
    insert_edge(g,1,7,false);
    insert_edge(g,1,2,false);

    insert_edge(g,2,7,false);
    insert_edge(g,2,3,false);
    insert_edge(g,2,5,false);

    insert_edge(g,5,3,false);
    insert_edge(g,5,4,false);
    insert_edge(g,5,6,false);

    insert_edge(g,3,4,false);
    g->nvertices = 8;
    
    bfs(g,1);

    find_path(1,4,parent);

    
    



    return 0;
}