#include "Aresta.h"
#include "Grafo.h"
#include <iostream>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;

    Grafo grafo(n);

    for (int i = 0; i < c; i++) {
        int x, y;
        cin >> x >> y;
        grafo.insere_aresta(Aresta(x, y));
    }

    int o;
    cin >> o;

    for (int i = 0; i < o; i++) {
        int x, ttl;
        cin >> x >> ttl;
        grafo.nao_recebem_mensagem(x, ttl);
    }

    return 0;
}