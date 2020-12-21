// router shortest path problem

#include <list>
#include <algorithm>
#include "MinHeap.h"

class RouterSP{
public:
    RouterSP(int mNum = 2, int nNum = 2, int c = 1, int num = 1) : 
        m(mNum), n(nNum), capacity(c), numNet(num){
        
    }

    void initMinQ(){
        minQ = new MinHeap(m, n);
        resSP.resize(m * n);
        for(int i = 0; i < resSP.size(); ++i)
            resSP[i] = Node(i, -1, INF);
    }

    void initAdjList(){
        int size = m * n;
        adjList.resize(size);
        for(int i = 0; i < size; ++i){
            if(i + n < size)
                adjList[i].push_back(Node(i + n));
            if(i + 1 < size && (i + 1) % n != 0)
                adjList[i].push_back(Node(i + 1));
            if(i - 1 >= 0 && i % n != 0)
                adjList[i].push_back(Node(i - 1));
            if(i - n >= 0)
                adjList[i].push_back(Node(i - n));
        }
        /*
        for(int i = 0; i < size; ++i){
            for(list<Node>::iterator item = adjList[i].begin(); item != adjList[i].end(); item++){
                cout << i << " " << item->id << " " << item->d << endl;
            }
            cout << endl;
        }*/
    }

    void Dijkstra(int startx, int starty){
        int startID = startx * n + starty;

        minQ->decreaseKey(startID, 0.0f); // 

        Node u;
        while(!minQ->isEmpty()){
            u = minQ->extractMin();
            resSP[u.id] = u;
            for(list<Node>::iterator v = adjList[u.id].begin(); v != adjList[u.id].end(); ++v)
                relax(u, minQ->getNodeById(v->id));
        }
    }


    void relax(Node u, Node v){
        int w = adjFindWeight(u.id, v.id);
        if(w < 0) return;
        if(v.d > u.d + w){
            minQ->decreaseKey(v.id, u.d + w);
            minQ->setPi(u.id, v.id);
        }
    }
    
    int adjFindWeight(int uid, int vid){
        for(list<Node>::iterator item = adjList[uid].begin(); item != adjList[uid].end(); item++)
            if(item->id == vid)
                return item->d;
        return -1;
    }

    
    void printRes(int tox, int toy){
        int pos = tox * n + toy;
        int startPos = 2 * n + 3;
        vector<int> path;
        while(pos != startPos){
            path.push_back(pos);
            pos = resSP[pos].pi;
        }
        path.push_back(11);

        for(int i = path.size() - 1; i > 0; --i)
            cout << "(" << path[i]/n << "," << path[i]%n << ")" << "->" << "(" << path[i - 1]/n << "," << path[i - 1]%n << ")"  << endl;
    }

private:
    int m;
    int n;
    int capacity;
    int numNet;
    MinHeap * minQ;
    vector<Node> resSP;
    vector< list<Node> > adjList;
    vector< vector<int> > pathLog;
    
    int * pi;

};
