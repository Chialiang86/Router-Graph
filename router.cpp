#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include "RouterSP.h"
using namespace std;



int main(int argc, char *argv[])
{
    if (argc != 3) {
        cout << "2 extra arguments needed(input.txt output.txt)." << endl;
        exit(0);
    }

    ifstream fin;
    ofstream fout;
    fin.open(argv[1], ios::in);
    fout.open(argv[2], ios::out | ios::trunc);
    if(!fin || ! fout){
        cout << "some problems with input.txt or output.txt" << endl;
        exit(0);
    }

    int m, n, capacity, numNet, id;
    vector<Point> from, to;
    string info;

    //get input
    fin >> info; //grid
    if(info != "grid")
        cout << "should be grid!" << endl;
    fin >> m >> n;
    cout << "m, n = " << m << ", " << n << endl;
    
    fin >> info; //capacity
    if(info != "capacity")
        cout << "should be capacity!" << endl;
    fin >> capacity;
    cout << "capacity = " << capacity << endl;
    
    fin >> info; //num
    if(info != "num")
        cout << "should be num!" << endl;
    fin >> info; //net
    if(info != "net")
        cout << "should be net!" << endl;
    fin >> numNet;
    cout << "num net = " << numNet << endl;
    
    id = 0;
    Point f, t;
    while(fin >> info){
        if(id == atoi(info.c_str())){
            fin >> f.x >> f.y >> t.x >> t.y;
            from.push_back(f);
            to.push_back(t);
            cout << id << " " << from[id].x << " " << from[id].y << " " << to[id].x << " " << to[id].y << endl;
            id++;
        } else {
            cout << "Oops!!!" << endl;
        }
    }


    RouterSP * dijk = new RouterSP(4, 4, 2, 3);
    dijk->initMinQ();
    dijk->initAdjList();
    dijk->Dijkstra(from[0].x, from[0].y);
    dijk->printRes(to[0].x, to[0].y);
    

    return 0;
}


    /*
    MinHeap heap;
    heap.addNode(-1, 5);
    heap.addNode(-1, 3);
    heap.addNode(-1, 4);
    heap.printHeap();
    cout << "p of 2 = " << heap.findParentIdById(2) << endl;  
    cout << "p of 1 = " << heap.findParentIdById(1) << endl;  
    cout << "p of 0 = " << heap.findParentIdById(0) << endl;  
    list<int> l;
    l.push_back(0);
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    l.push_back(7);
    l.push_back(8);
    for(list<int>::iterator i = l.begin(); i != l.end(); ++i){
        cout << *i << endl;
    }
    */