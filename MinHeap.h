#include <iostream>
#include <vector>
#include <map>
#include "DataType.h"

#define INF 99999999.0f
using namespace std;

class MinHeap{
public:
    MinHeap(int size = 12){
        heap.push_back(Node()); //dummy node
    }
    
    MinHeap(int m, int n){
        heap.push_back(Node()); //dummy node
        int nodes = m * n;
        for(int i = 0; i < nodes; ++i){
            indexTable[i] = i + 1;
            heap.push_back(Node(i, -1, INF));
        }
    }

    bool isEmpty(){
        return heap.size() <= 1;
    }

    void addNode(int pi = -1, float d = INF){
        Node node(heap.size() - 1, pi, d); // id = n
        float temp = node.d;
        indexTable[node.id] = heap.size() - 1;
        heap.push_back(node);
        for(int index = heap.size() - 1; index > 0 && temp < heap[index/2].d; index /= 2)
            swap(index, index / 2);
    }

    Node getNodeById(int id){
        if(indexTable.find(id) == indexTable.end()) return heap[0];
        return heap[ indexTable[id] ];
    }
    
    int findParentIdById(int id){
        if(indexTable.find(id) == indexTable.end()) return -1;
        return heap[indexTable[id]].pi;
    }

    int findParentIdByNode(Node n){
        if(indexTable.find(n.id) == indexTable.end()) return -1;
        return n.pi;
    }

    void decreaseKey(Node n, float key){
        int i = indexTable[n.id];
        if(heap[i].d < key) return;
        heap[i].d = key;
        for(int index = i; index > 0 && key < heap[index/2].d; index /= 2)
            swap(index, index / 2);
    }

    void decreaseKey(int id, float key){
        if(indexTable.find(id) == indexTable.end()) return;
        int i = indexTable[id];
        if(heap[i].d < key) return;
        heap[i].d = key;
        for(int index = i; index > 0 && key < heap[index/2].d; index /= 2)
            swap(index, index / 2);
    }

    Node extractMin(){
        if(heap.size() == 1) return heap[0];
        Node returnNode = heap[1];
        swap(1, heap.size() - 1);
        heap.pop_back();
        heapify(heap[1]);
        return returnNode;
    }

    void setPi(int uid, int vid){
        if(indexTable.find(uid) == indexTable.end() || indexTable.find(vid) == indexTable.end())
            return;
        int vindex = indexTable[vid];
        heap[vindex].pi = uid;
    }

    void heapify(Node n){
        int root = indexTable[n.id];
        int min = -1;
        if(2 * root < heap.size())
            min = heap[2 * root].d < heap[root].d ? 2 * root : root;
        if(2 * root + 1 < heap.size())
            min = heap[2 * root + 1].d < heap[min].d ? 2 * root + 1 : min;
        if(min > 0 && min != root){
            swap(min, root);
            heapify(heap[min]);
        }
    }

    void swap(int l, int r){
        Node temp = heap[l];
        heap[l] = heap[r];
        indexTable[heap[l].id] = l;
        heap[r] = temp;
        indexTable[heap[r].id] = r;
    }

    void printHeap(){
        cout << "print " << heap.size() - 1 << " elements" << endl;
        for(int i = 1; i < heap.size(); ++i)
            cout << "id = " << heap[i].id << " at "<< indexTable[heap[i].id] << ", d = " << heap[i].d << endl;
        cout << endl;
    }

private:
    vector<Node> heap;
    map<int, int> indexTable;
};