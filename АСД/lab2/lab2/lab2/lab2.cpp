#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ���������� ������� DFS � BFS
void dfs1(vector<vector<int>>& adge, int v, vector<int>& visited);
void dfs2(vector<vector<int>>& listedgency, int v, vector<int>& visited);
void dfs3(vector<vector<int>>& matradjency, int v, vector<int>& visited);
void bfs1(vector<vector<int>>& adge, int start, vector<int>& visited);
void bfs2(vector<vector<int>>& listedgency, int start, vector<int>& visited);
void bfs3(vector<vector<int>>& matradjency, int start, vector<int>& visited);

int main() {
    setlocale(LC_ALL, "ru");
    int v = 10;
    vector<int> visited(v + 1, 0); // ����������: ������������� ������� visited

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

    // ����� ������� DFS � BFS ��� ����� �� ������ ������� ���������
    cout << "DFS ��� ������� ���������:" << endl;
    dfs3(matradjency, 1, visited); // �������� '1' �� �������� ��������� �������
    visited.assign(v + 1, 0);

    cout << "BFS ��� ������� ���������:" << endl;
    bfs3(matradjency, 1, visited); // �������� '1' �� �������� ��������� �������
    visited.assign(v + 1, 0);

    // ����� ������� DFS � BFS ��� ����� �� ������ ������ ���������
    cout << "DFS ��� ������ ���������:" << endl;
    dfs2(listedgency, 1, visited); // �������� '1' �� �������� ��������� �������
    visited.assign(v + 1, 0);

    cout << "BFS ��� ������ ���������:" << endl;
    bfs2(listedgency, 1, visited); // �������� '1' �� �������� ��������� �������
    visited.assign(v + 1, 0);

    // ����� ������� DFS � BFS ��� ����� �� ������ ������ ����
    cout << "DFS ��� ������ ����:" << endl;
    dfs1(adge, 1, visited); // �������� '1' �� �������� ��������� �������
    visited.assign(v + 1, 0);

    cout << "BFS ��� ������ ����:" << endl;
    bfs1(adge, 1, visited); // �������� '1' �� �������� ��������� �������

    return 0;
}

// ����������� ������� DFS ��� ������ ����
void dfs1(vector<vector<int>>& adge, int v, vector<int>& visited) {
    visited[v] = 1;
    cout << "DFS1 ��������� ������� " << v << endl; // �������� �� �������� ��������
    for (int i = 0; i < adge.size(); i++) {
        if (adge[i][0] == v && !visited[adge[i][1]]) {
            dfs1(adge, adge[i][1], visited);
        }
    }
}

// ����������� ������� DFS ��� ������ ���������
void dfs2(vector<vector<int>>& listedgency, int v, vector<int>& visited) {
    visited[v] = 1;
    cout << "DFS2 ��������� ������� " << v << endl; // �������� �� �������� ��������
    for (int to : listedgency[v]) {
        if (!visited[to])
            dfs2(listedgency, to, visited);
    }
}

// ����������� ������� DFS ��� ������� ���������
void dfs3(vector<vector<int>>& matradjency, int v, vector<int>& visited) {
    visited[v] = 1;
    cout << "DFS3 ��������� ������� " << v << endl; // �������� �� �������� ��������
    for (int i = 0; i < matradjency.size(); i++) {
        if (matradjency[v][i] == 1 && !visited[i]) {
            dfs3(matradjency, i, visited);
        }
    }
}

// ����������� ������� BFS ��� ������ ����
void bfs1(vector<vector<int>>& adge, int start, vector<int>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << "BFS1 ��������� ������� " << v << endl; // �������� �� �������� ��������

        for (int i = 0; i < adge.size(); i++) {
            if (adge[i][0] == v && !visited[adge[i][1]]) {
                visited[adge[i][1]] = 1;
                q.push(adge[i][1]);
            }
        }
    }
}

// ����������� ������� BFS ��� ������ ���������
void bfs2(vector<vector<int>>& listedgency, int start, vector<int>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << "BFS2 ��������� ������� " << v << endl; // �������� �� �������� ��������

        for (int to : listedgency[v]) {
            if (!visited[to]) {
                visited[to] = 1;
                q.push(to);
            }
        }
    }
}

// ����������� ������� BFS ��� ������� ���������
void bfs3(vector<vector<int>>& matradjency, int start, vector<int>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << "BFS3 ��������� ������� " << v << endl; // �������� �� �������� ��������

        for (int i = 0; i < matradjency.size(); i++) {
            if (matradjency[v][i] == 1 && !visited[i]) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}
