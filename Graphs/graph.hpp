#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
#include <vector>

using namespace std;

class Graph{
    private:
        int num_v;
        vector<vector<int>> adj_matrix;   
    public:
        Graph(int v);
        ~Graph();
};

#endif