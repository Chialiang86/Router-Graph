#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <limits>
#include <map>
#include "MinHeap.h"
using namespace std;


/*
struct HeapNode{
    int id;
    int pi; // id of predecessor
    float d; // distance to start point
    HeapNode(int id, int parent, float distance) : id(id), pi(parent), d(distance) {} 
    HeapNode(int id) : id(id) {pi = -1; d = 0;}
    HeapNode() { id = -1; d = 0; pi = -1;}
};

class MinHeap{
public:
    MinHeap(int size = 12){
        heap.push_back(HeapNode()); //dummy node
    }
    
    MinHeap(int m, int n){
        heap.push_back(HeapNode()); //dummy node
        int nodes = m * n;
        for(int i = 1; i <= nodes; ++i){
            indexTable[i] = i;
            heap.push_back(HeapNode(i));
        }
    }

    void addNode(int pi = -1, float d = 99999999.0f){
        HeapNode node(heap.size(), pi, d); // id = n + 1
        float temp = node.d;
        heap.push_back(node);
        indexTable[node.id] = heap.size() - 1;
        for(int index = heap.size() - 1; index > 0 && temp < heap[index/2].d; index /= 2)
            swap(index, index / 2);
    }

    HeapNode getNodeById(int id){
        if(indexTable.find(id) == indexTable.end()) return heap[0];
        return heap[ indexTable[id] ];
    }

    void decreaseKey(HeapNode n, float key){
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

    void heapify(HeapNode n){
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
        HeapNode temp = heap[l];
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
    vector<HeapNode> heap;
    map<int, int> indexTable;
};


*/


int main(int argc, char * argv[]){
    MinHeap heap;
    heap.addNode(-1, 3);
    heap.printHeap();
    heap.addNode(-1, 5);
    heap.printHeap();
    heap.addNode(-1, 2);
    heap.printHeap();
    heap.addNode(-1, 4);
    heap.printHeap();
    heap.addNode(-1, 1);
    heap.printHeap();
    heap.addNode(-1, 7);
    heap.printHeap();
    heap.addNode(-1, 10);
    heap.printHeap();
    heap.addNode(-1, 8);
    heap.printHeap();
    heap.addNode(-1, 9);
    heap.printHeap();
    heap.addNode(-1, 6);
    heap.printHeap();
    heap.decreaseKey(7, 0);
    heap.printHeap();
    return 0;
}