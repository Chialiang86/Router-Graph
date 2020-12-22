

struct HeapNode{
    int id;
    int pi; // id of predecessor
    double d; // distance to start point
    HeapNode(int id = -1, int parent = -1, float weight = 0) : id(id), pi(parent), d(weight) {} 
};

struct AdjNode{
    int id;
    int weight;
    int capacity;
    AdjNode(int id = -1, int w = 0, int c = 0) : id(id), weight(w), capacity(c){}
};

struct Point{
    int x;
    int y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};
