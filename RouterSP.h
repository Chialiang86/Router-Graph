// router shortest path problem

#include <vector>
#include <list>
#include <algorithm>
#include "MinHeap.h"

struct AdjNode{
    int id;
    int weight;
    AdjNode(int id = -1,int w = 0) : id(id), weight(w) {}
};


class RouterSP{
public:
    RouterSP(int mNum = 2, int nNum = 2, int c = 1, int num = 1) : 
        m(mNum), n(nNum), capacity(c), numNet(num){
        
    }

    void initMinQ(){
        minQ = new MinHeap(m, n);
    }

    void initAdjList(){
        int size = m * n;
        adjList.resize(size);
        for(int i = 0; i < size; ++i){
            if(i + n < size)
                adjList[i].push_back(AdjNode(i + n));
            if(i + 1 < size)
                adjList[i].push_back(AdjNode(i + 1));
            if(i - 1 >= 0)
                adjList[i].push_back(AdjNode(i - 1));
            if(i - n >= 0)
                adjList[i].push_back(AdjNode(i - n));
        }

        for(int i = 0; i < size; ++i){
            for(list<AdjNode>::iterator item = adjList[i].begin(); item != adjList[i].end(); item++){
                cout << i << " " << item->id << " " << item->weight << endl;
            }
            cout << endl;
        }
    }

    void relex(){

    }


private:
    int m;
    int n;
    int capacity;
    int numNet;
    MinHeap * minQ;
    vector< list<AdjNode> > adjList;
    
    int * pi;

};