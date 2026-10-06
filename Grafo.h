#ifndef GRAFO_H
#define GRAFO_H

#include "Aresta.h"
#include <vector>

class Grafo {
public:
    Grafo(int num_vertices);

    int num_vertices();
    int num_arestas();

    bool tem_aresta(Aresta e);

    void insere_aresta(Aresta e);

    void busca_larg(int v, int ttl);

    void nao_recebem_mensagem(int x, int ttl);

private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::vector<int>> matriz_adj_;
    std::vector<bool> marcado_;
};

#endif 