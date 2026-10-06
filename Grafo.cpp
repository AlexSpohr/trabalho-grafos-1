#include "Grafo.h"
#include <iostream>
#include <stdexcept>
#include <queue>


using namespace std;

Grafo::Grafo(int num_vertices) {
    if (num_vertices <= 0) {
        throw(invalid_argument("Erro no construtor Grafo(int): o numero de "
            "vertices " + to_string(num_vertices) + " eh invalido!"));
    }

    num_vertices_ = num_vertices;
    num_arestas_ = 0;

    matriz_adj_.resize(num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        matriz_adj_[i].resize(num_vertices, 0);
    }
}

int Grafo::num_vertices() {
    return num_vertices_;
}

int Grafo::num_arestas() {
    return num_arestas_;
}

bool Grafo::tem_aresta(Aresta e) {
    if (matriz_adj_[e.v1][e.v2] != 0) {
        return true;
    }
    return false;
}

void Grafo::insere_aresta(Aresta e) {
    if (!tem_aresta(e) && (e.v1 != e.v2)) {
        matriz_adj_[e.v1][e.v2] = 1;
        matriz_adj_[e.v2][e.v1] = 1;

        num_arestas_++;
    }
}

void Grafo::busca_larg(int v, int ttl) {
    queue<int> fila;
    marcado_.resize(num_vertices_);
    for (int i = 0; i < num_vertices_; i++) {
        marcado_[i] = 0;
    }
    marcado_[v] = 1;
    fila.push(v);

    while(!fila.empty() && ttl > 0) {
        int vertices_nivel = fila.size();
        for (int j = 0; j < vertices_nivel; j++) {
            int w = fila.front();
            fila.pop();
            for (int i = 0; i < num_vertices_; i++) {
                if (matriz_adj_[w][i] != 0) {
                    if (marcado_[i] == 0) {
                        marcado_[i] = 1;
                        fila.push(i);
                    }
                }
            }
        }
        ttl--;
    }
}

void Grafo::nao_recebem_mensagem(int x, int ttl) {
    busca_larg(x, ttl);

    cout << x << " " << ttl << ":";
    for (int i = 0; i < num_vertices_; i++) {
        if (marcado_[i] == 0) {
            cout << " " << i;
        }
    }
    cout << endl;
}
