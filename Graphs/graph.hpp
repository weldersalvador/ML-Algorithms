#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
#include <vector>

using namespace std;

class No{
    public:
        int id;
        bool visitado;
        int grau_entrada;
        int grau_saida;
        vector<No*> vizinhos;
        No(int id);
};

class Graph{
    private:
        int num_vertices;
        vector<No*> nos;   

        void limpar_visitados();
    public:
        Graph(int v);
        ~Graph();

        void adicionar_aresta(int u, int v, bool direcionado = false);
        void imprimir();
};

#endif