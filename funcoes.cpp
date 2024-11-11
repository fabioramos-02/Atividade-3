#include "func.h"

// Função para gerar arestas aleatórias com probabilidade p
void gerarGrafos(vector<vector<int>>& adj, int n, float p) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {  // Apenas j > i para evitar duplicação
            if (static_cast<float>(rand()) / RAND_MAX < p) {
                adj[i].push_back(j);
                adj[j].push_back(i);  // Aresta bidirecional
            }
        }
    }
}

// Função para calcular o grau mínimo, máximo e médio dos vértices
void grauMinimoMaximoMedio(const vector<vector<int>>& adj, int n, int& gmin, int& gmax, float& gmed) {
    gmin = n; // Define gmin como o valor máximo possível
    gmax = 0;
    int somaGraus = 0;

    for (const auto& vizinhos : adj) {
        int grau = vizinhos.size();
        gmin = min(gmin, grau);
        gmax = max(gmax, grau);
        somaGraus += grau;
    }

    gmed = static_cast<float>(somaGraus) / n;
}

// Função BFS para calcular o diâmetro (maior distância mínima do vértice origem)
int calcularDiametro(const vector<vector<int>>& adj, int n) {
    int diametro = 0;

    for (int i = 0; i < n; i++) {
        vector<int> dist(n, -1);
        queue<int> fila;

        dist[i] = 0;
        fila.push(i);

        int maxDist = 0;

        while (!fila.empty()) {
            int u = fila.front();
            fila.pop();

            for (int v : adj[u]) {
                if (dist[v] == -1) {  // Se v ainda não foi visitado
                    dist[v] = dist[u] + 1;
                    maxDist = max(maxDist, dist[v]);
                    fila.push(v);
                }
            }
        }

        diametro = max(diametro, maxDist);
    }

    return diametro;
}

// Função para imprimir o número de vértices (V) do grafo, o número de arestas (E) do grafo, seu grau
void imprimir(int n, int numArestas, int gmin, int gmax, float gmed, int diam) {
    printf("%d \t%d \t%d \t%d \t%.2f \t%d\n", n, numArestas, gmin, gmax, gmed, diam);
}
