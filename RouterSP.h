// router shortest path problem

#ifdef ROUTER_SP_H
#define ROUTER_SP_H


#include <vector>
#include <queue>

struct HeapNode{
    float d; // distance to start point
    int pi; // id of predecessor
    HeapNode(float distance, int parent) : d(distance), pi(parent) {} 
    HeapNode() { d = 0; pi = -1;}
};

struct CompareKey{
    bool operator()(const HeapNode& l, const HeapNode& r){
        return l.d > r.d;
    }
};


#endif /* ROUTER_SP_HPP */