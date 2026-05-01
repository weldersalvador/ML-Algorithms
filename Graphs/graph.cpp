#include "graph.hpp"
#include <iostream>
using namespace std;

No::No(int id){
    this->id = id;
}

Graph::Graph(int v){
    num_vertices = v;
    for(int i = 0; i < num_vertices; i++){
        nos.push_back(new No(i));
    }
}

Graph::~Graph(){
    for(No* no : nos){
        delete no;
    }
}

void Graph::limpar_visitados(){
    for(No * no : nos){
        no->visitado = false;
    }
}

void Graph::adicionar_aresta(int u, int v, bool direcionado){
    if(direcionado){
        nos[u]->vizinhos.push_back(nos[v]);
        nos[u]->grau_saida++;
        nos[v]->grau_entrada++;
    }
    else{
        nos[u]->vizinhos.push_back(nos[v]);
        nos[v]->vizinhos.push_back(nos[u]);
        nos[u]->grau_entrada++;
        nos[v]->grau_entrada++;
    }
}

void Graph::imprimir(){
    for(No* no: nos){
        cout << no->id << ": ";
        for(No* vizinhos: no->vizinhos){
            cout << vizinhos->id << " ";
        }
        cout << endl;
    }
}