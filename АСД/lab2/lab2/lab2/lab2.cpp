#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Объявление функций DFS и BFS
void dfs1(vector<vector<int>>& adge, int v, vector<int>& visited);
void dfs2(vector<vector<int>>& listedgency, int v, vector<int>& visited);
void dfs3(vector<vector<int>>& matradjency, int v, vector<int>& visited);
void bfs1(vector<vector<int>>& adge, int start, vector<int>& visited);
void bfs2(vector<vector<int>>& listedgency, int start, vector<int>& visited);
void bfs3(vector<vector<int>>& matradjency, int start, vector<int>& visited);

int main() {
    setlocale(LC_ALL, "ru");
    int v = 10;
    vector<int> visited(v + 1, 0); // Исправлено: инициализация массива visited

    vector<vector<int>> adge =
    {
        {1, 2},{2, 1},
        {1, 5},{5, 1},
        {2, 7},{7, 2},
        {2, 8},{8, 2},
        {3, 8},{8, 3},
        {4, 6},{6, 4},
        {4, 9},{9, 4},
        {5, 6},{6, 5},
        {6, 9},{9, 6},
        {7, 8},{8, 7},
        {9, 10},{10, 9}
    };

    vector<vector<int>> matradjency =
    {
        {0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
        {1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}
    };

    vector<vector<int>> listedgency =
    {
        {2, 5},
        {1, 7, 8},
        {8},
        {6, 9},
        {1, 6},
        {4, 5, 9},
        {2, 8},
        {2, 3, 7},
        {4, 6, 9},
        {9},
    };

    // Вызов функций DFS и BFS для графа на основе матрицы смежности
    cout << "DFS для матрицы смежности:" << endl;
    dfs3(matradjency, 1, visited); // Замените '1' на желаемую начальную вершину
    visited.assign(v + 1, 0);

    cout << "BFS для матрицы смежности:" << endl;
    bfs3(matradjency, 1, visited); // Замените '1' на желаемую начальную вершину
    visited.assign(v + 1, 0);

    // Вызов функций DFS и BFS для графа на основе списка смежности
    cout << "DFS для списка смежности:" << endl;
    dfs2(listedgency, 1, visited); // Замените '1' на желаемую начальную вершину
    visited.assign(v + 1, 0);

    cout << "BFS для списка смежности:" << endl;
    bfs2(listedgency, 1, visited); // Замените '1' на желаемую начальную вершину
    visited.assign(v + 1, 0);

    // Вызов функций DFS и BFS для графа на основе списка рёбер
    cout << "DFS для списка рёбер:" << endl;
    dfs1(adge, 1, visited); // Замените '1' на желаемую начальную вершину
    visited.assign(v + 1, 0);

    cout << "BFS для списка рёбер:" << endl;
    bfs1(adge, 1, visited); // Замените '1' на желаемую начальную вершину

    return 0;
}

// Определение функции DFS для списка рёбер
void dfs1(vector<vector<int>>& adge, int v, vector<int>& visited) {
    visited[v] = 1;
    cout << "DFS1 посещение вершины " << v << endl; // Замените на желаемое действие
    for (int i = 0; i < adge.size(); i++) {
        if (adge[i][0] == v && !visited[adge[i][1]]) {
            dfs1(adge, adge[i][1], visited);
        }
    }
}

// Определение функции DFS для списка смежности
void dfs2(vector<vector<int>>& listedgency, int v, vector<int>& visited) {
    visited[v] = 1;
    cout << "DFS2 посещение вершины " << v << endl; // Замените на желаемое действие
    for (int to : listedgency[v]) {
        if (!visited[to])
            dfs2(listedgency, to, visited);
    }
}

// Определение функции DFS для матрицы смежности
void dfs3(vector<vector<int>>& matradjency, int v, vector<int>& visited) {
    visited[v] = 1;
    cout << "DFS3 посещение вершины " << v << endl; // Замените на желаемое действие
    for (int i = 0; i < matradjency.size(); i++) {
        if (matradjency[v][i] == 1 && !visited[i]) {
            dfs3(matradjency, i, visited);
        }
    }
}

// Определение функции BFS для списка рёбер
void bfs1(vector<vector<int>>& adge, int start, vector<int>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << "BFS1 посещение вершины " << v << endl; // Замените на желаемое действие

        for (int i = 0; i < adge.size(); i++) {
            if (adge[i][0] == v && !visited[adge[i][1]]) {
                visited[adge[i][1]] = 1;
                q.push(adge[i][1]);
            }
        }
    }
}

// Определение функции BFS для списка смежности
void bfs2(vector<vector<int>>& listedgency, int start, vector<int>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << "BFS2 посещение вершины " << v << endl; // Замените на желаемое действие

        for (int to : listedgency[v]) {
            if (!visited[to]) {
                visited[to] = 1;
                q.push(to);
            }
        }
    }
}

// Определение функции BFS для матрицы смежности
void bfs3(vector<vector<int>>& matradjency, int start, vector<int>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << "BFS3 посещение вершины " << v << endl; // Замените на желаемое действие

        for (int i = 0; i < matradjency.size(); i++) {
            if (matradjency[v][i] == 1 && !visited[i]) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}
