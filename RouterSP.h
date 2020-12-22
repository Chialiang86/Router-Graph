// router shortest path problem

#include <list>
#include <algorithm>
#include <stack>
#include <fstream>
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
            resSP[i] = HeapNode(i, -1, INF);
    }

    void initAdjList(){
        int size = m * n;
        adjList.resize(size);
        for(int i = 0; i < size; ++i){
            if(i + n < size)
                adjList[i].push_back(AdjNode(i + n, 0, capacity));
            if(i + 1 < size && (i + 1) % n != 0)
                adjList[i].push_back(AdjNode(i + 1, 0, capacity));
            if(i - 1 >= 0 && i % n != 0)
                adjList[i].push_back(AdjNode(i - 1, 0, capacity));
            if(i - n >= 0)
                adjList[i].push_back(AdjNode(i - n, 0, capacity));
        }
    }

    void routeAndOutput(ofstream& fout, int routeId, const Point& from, const Point& to){
        minQ->resetHeap();
        Dijkstra(from);
        printResUpdateWeight(fout, routeId, from, to);
    }

    void Dijkstra(const Point& startPos){
        int startID = startPos.x * n + startPos.y;

        minQ->decreaseKey(startID, 0.0f); // 

        HeapNode u;
        while(!minQ->isEmpty()){
            u = minQ->extractMin();
            resSP[u.id] = u;
            for(list<AdjNode>::iterator v = adjList[u.id].begin(); v != adjList[u.id].end(); ++v)
                relax(u, minQ->getNodeById(v->id));
        }
    }
    
    
    void printResUpdateWeight(ofstream& fout, int routeId, const Point& from, const Point& to){
        int fromPos = from.x * n + from.y;
        int v = to.x * n + to.y, u;
        stack<int> path;
        while(v != fromPos){
            path.push(v);
            u = resSP[v].pi;
            if(!adjUpdateWeight(u, v)) break;
            v = u;
        }
        path.push(v);
        adjUpdateWeight(u, v);

        fout << routeId << " " << path.size() - 1 << endl;
        cout << routeId << " " << path.size() - 1 << endl;

        u = path.top();
        path.pop();
        while(!path.empty()){
            v = path.top();
            fout << u / n << " " << u % n << " " << v / n << " " << v % n << endl;
            cout << u / n << " " << u % n << " " << v / n << " " << v % n << endl;
            u = v;
            path.pop();
        }
    }

    int countOverflow(){
        int size = m * n;
        int temp;
        int numOverflow = 0;
        cout << "< overflow counting >" << endl;
        for(int i = 0; i < size; ++i){
            for(list<AdjNode>::iterator item = adjList[i].begin(); item != adjList[i].end(); item++){
                if(item->capacity < 0){
                    numOverflow += -item->capacity;
                    //cout << "at:(" << i << "," << item->id << ")  overflow:" << -item->capacity << endl;
                }
            }
        }
        return numOverflow / 2;
    }

private:
    
    void relax(const HeapNode& u, const HeapNode& v){
        int w = adjFindWeight(u.id, v.id);
        if(w < 0) return;
        if(v.d > u.d + w){
            minQ->decreaseKey(v.id, u.d + w);
            minQ->setPi(u.id, v.id);
        }
    }
    
    int adjFindWeight(int uid, int vid){
        for(list<AdjNode>::iterator item = adjList[uid].begin(); item != adjList[uid].end(); item++)
            if(item->id == vid)
                return item->weight;
        return -1;
    }

    bool adjUpdateWeight(int uid, int vid){
        bool udone = false, vdone = false;
        for(list<AdjNode>::iterator item = adjList[uid].begin(); item != adjList[uid].end(); item++){
            if(item->id == vid){
                udone = true;
                item->weight = updatePolicy(item->weight);
                item->capacity--;
                break;
            }
        }

        for(list<AdjNode>::iterator item = adjList[vid].begin(); item != adjList[vid].end(); item++){
            if(item->id == uid){
                vdone = true;
                item->weight = updatePolicy(item->weight);
                item->capacity--;
                break;
            }
        }

        return udone && vdone;
    }

    double updatePolicy(double w){
        if(w < 0){
            cout << "update policy err" << endl;
            return -1;
        } 
        return w > 0 ? w * 2 : 1;
    }

    int m;
    int n;
    int capacity;
    int numNet;
    MinHeap * minQ;
    vector<HeapNode> resSP;
    vector< list<AdjNode> > adjList;
    vector< vector<int> > pathLog;

};
