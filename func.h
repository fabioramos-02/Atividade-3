#include <vector>
#include <queue>
#include <random>
using namespace std;

void gerarGrafos(vector<vector<int>>& adj, int n, float p);
void grauMinimoMaximoMedio(const vector<vector<int>>& adj, int n, int& gmin, int& gmax, float& gmed);
int calcularDiametro(const vector<vector<int>>& adj, int n);
void imprimir(int n, int numArestas, int gmin, int gmax, float gmed, int diam);
