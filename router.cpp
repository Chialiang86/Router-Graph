#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <limits>
#include <map>
#include "MinHeap.h"
using namespace std;


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
    cout << "min d in id :" << heap.extractMin().id << endl;
    heap.printHeap();

    return 0;
}