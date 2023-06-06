#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

const int INF = 1e9;

int main() {
    setlocale(0, "rus");
        int n, m;
    cout << "Введите количество вершин: ";
    cin >> n;
    cout << "Введите количество ребер: ";
    cin >> m;

    vector<vector<int>> graph(n, vector<int>(n, INF));

    cout << "Введите ребра в формате \"u v w\", где u - начальная вершина, v - конечная вершина, а w - вес: " << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u - 1][v - 1] = w;
    }

    for (int i = 0; i < n; i++) {
        graph[i][i] = 0;
    }

    vector<int> dist(n, INF);
    dist[0] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (dist[j] != INF && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }
        if (dist[u] == INF) {
            break;
        }
        for (int v = 0; v < n; v++) {
            if (graph[u][v] < INF && dist[v] > dist[u] + graph[u][v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Минимальная стоимость пути от вершины 1 до всех остальных вершин: " << endl;
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) {
            cout << "Нет пути от вершины 1 до " << i + 1 << endl;
        }
        else {
            cout << "Стоимость пути до вершины " << i + 1 << ": " << dist[i] << endl;
        }
    }

    return 0;
}