#include <iostream>
#include "graph.hpp"

using namespace std;

int main(){
    Graph g1(4);

    g1.adicionar_aresta(0,1);
    g1.adicionar_aresta(0,2);
    g1.adicionar_aresta(1,2);
    g1.adicionar_aresta(1,3);
    g1.adicionar_aresta(2,3);

    g1.busca_profundidade_iterativa(0);

    return 0;
}