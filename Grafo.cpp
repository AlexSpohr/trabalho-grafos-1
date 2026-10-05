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

// Busca em largura a partir de v, limitada a ttl saltos. Devolve a distancia
// de v ate cada vertice; -1 para os vertices nao alcancados dentro do limite.
vector<int> Grafo::busca_larg(int v, int ttl) {
    vector<int> dist(num_vertices_, -1);
    queue<int> fila;

    dist[v] = 0;
    fila.push(v);

    while (!fila.empty()) {
        int w = fila.front();
        fila.pop();

        // A mensagem so eh encaminhada enquanto o ttl atualizado for maior
        // que 0, ou seja, enquanto a distancia percorrida for menor que ttl.
        if (dist[w] >= ttl) {
            continue;
        }

        for (int i = 0; i < num_vertices_; i++) {
            if (matriz_adj_[w][i] != 0) {
                if (dist[i] == -1) {
                    dist[i] = dist[w] + 1;
                    fila.push(i);
                }
            }
        }
    }

    return dist;
}

void Grafo::nao_recebem_mensagem(int x, int ttl) {
    vector<int> dist = busca_larg(x, ttl);

    cout << x << " " << ttl << ":";
    for (int i = 0; i < num_vertices_; i++) {
        if (dist[i] == -1) {
            cout << " " << i;
        }
    }
    cout << endl;
}
