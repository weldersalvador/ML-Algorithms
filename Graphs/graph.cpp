#include <graph.hpp>
#include <iostream>
using namespace std;

Graph::Graph(int v){
    num_v = v;
    adj_matrix.reserve(v*v);
}