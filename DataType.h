

struct Node{
    int id;
    int pi; // id of predecessor
    float d; // distance to start point
    Node(int id, int parent = -1, float weight = 0) : id(id), pi(parent), d(weight) {} 
    Node() { id = -1; d = 0; pi = -1;}
};

struct Point{
    int x;
    int y;
    Point(int x, int y) : x(x), y(y) {}
    Point() {x = 0; y = 0;}
};
