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
    // arg number debug
    if (argc != 3) {
        cout << "2 extra arguments needed(input.txt output.txt)." << endl;
        exit(0);
    }

    // file initilizing
    ifstream fin;
    ofstream fout;
    fin.open(argv[1], ios::in);
    fout.open(argv[2], ios::out | ios::trunc);
    if(!fin || !fout){
        cout << "some problems with input.txt or output.txt" << endl;
        exit(0);
    }

    int m, n, capacity, numNet;
    vector<Point> from, to;
    vector<int> ids;
    string info;

    // input region
    fin >> info; //grid
    if(info != "grid") cout << "should be grid!" << endl;
    fin >> m >> n;
    cout << "m, n = " << m << ", " << n << endl;
    
    fin >> info; //capacity
    if(info != "capacity") cout << "should be capacity!" << endl;
    fin >> capacity;
    cout << "capacity = " << capacity << endl;
    
    fin >> info; //num
    if(info != "num") cout << "should be num!" << endl;
    fin >> info; //net
    if(info != "net") cout << "should be net!" << endl;
    fin >> numNet;
    cout << "num net = " << numNet << endl;
    
    int id = 0;
    Point f, t;
    while(fin >> info){
        if(id == atoi(info.c_str())){
            fin >> f.x >> f.y >> t.x >> t.y;
            ids.push_back(id);
            from.push_back(f);
            to.push_back(t);
            cout << ids[id] << " " << from[id].x << " " << from[id].y << " " << to[id].x << " " << to[id].y << endl;
            id++;
        } else {
            cout << "router id error" << endl;
        }
    }
    fin.close();


    // router processing
    RouterSP * router = new RouterSP(4, 4, 2, 3);
    router->initMinQ();
    router->initAdjList();
    for(int i = 0; i < ids.size(); ++i)
        router->routeAndOutput(fout, ids[i], from[i], to[i]);
    cout << "total overflow : " << router->countOverflow() << endl;
    fout.close();

    return 0;
}