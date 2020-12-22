
/*
 * the input of Dijkstra's algorithm is a Graph : G = (V, E)
 * |V| = m x n
 * |E| = (2 x m x n) - m - n
**/

// for min priority queue (node set V)
struct HeapNode{
    int id; // node id should be unique
    int pi; // id of predecessor
    double d; // distance to start point
    HeapNode(int id = -1, int parent = -1, float weight = 0) : id(id), pi(parent), d(weight) {} 
};

// for adjacency list (edge set E)
struct AdjNode{
    int id; // node id should be unique
    int weight;
    int capacity;
    AdjNode(int id = -1, int w = 0, int c = 0) : id(id), weight(w), capacity(c){}
};

// point for router pos
struct Point{
    int x;
    int y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};
