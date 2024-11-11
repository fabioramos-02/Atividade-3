#include "func.h"
using namespace std;

int main(int argc, char const *argv[]) {
    // Definindo valores iniciais para os experimentos
    int ini = 10, fim = 200, stp = 10;
    float p = 0.1;

    // Imprime o cabeçalho da tabela
    printf("V \tE \tgmin \tgmax \tgmed \tdiam\n");
    printf("------------------------------------------------\n");

    for (int n = ini; n <= fim; n += stp) {
        vector<vector<int>> v(n);  // Definindo v como lista de adjacência

        gerarGrafos(v, n, p);  // Gera o grafo com probabilidade p

        // Calcula o número de arestas no grafo
        int numArestas = 0;
        for (const auto& vizinhos : v) {
            numArestas += vizinhos.size();
        }
        numArestas /= 2;  // Divide por 2 para ajustar a contagem bidirecional

        int gmin = n, gmax = 0;
        float gmed = 0;

        // Calcula grau mínimo, máximo e médio
        grauMinimoMaximoMedio(v, n, gmin, gmax, gmed);

        // Calcula o diâmetro do grafo
        int diam = calcularDiametro(v, n);

        // Imprime os resultados
        imprimir(n, numArestas, gmin, gmax, gmed, diam);
    }

    return 0;
}
