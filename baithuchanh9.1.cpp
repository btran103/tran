#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
#define MAX_VERTICES 100

using namespace std;

// Cau truc do thi bang ma tran ke
struct AdjMatrixGraph {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

// a) Doc du lieu do thi tu file
void readGraphFromFile(string& fileName, AdjMatrixGraph& g) {
    ifstream file("Graph1.txt");
    if (!file) {
        cerr << "Khong the mo tep " << fileName << endl;
        return;
    }

    file >> g.numVertices;
    for (int i = 0; i < g.numVertices; i++) {
        for (int j = 0; j < g.numVertices; j++) {
            file >> g.adjMatrix[i][j];
        }
    }
    file.close();
}

// b) In ma tran ke cua do thi
void printGraph(AdjMatrixGraph& g) {
    cout << "So dinh: " << g.numVertices << endl;
    for (int i = 0; i < g.numVertices; i++) {
        for (int j = 0; j < g.numVertices; j++) {
            cout << g.adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// c) Duyet do thi theo chieu sau (DFS)
void DFS(AdjMatrixGraph& g, int vertex, bool visited[]) {
    visited[vertex] = true;
    cout << vertex << " ";
    for (int i = 0; i < g.numVertices; i++) {
        if (g.adjMatrix[vertex][i] != 0 && !visited[i]) {
            DFS(g, i, visited);
        }
    }
}

// d) Duyet do thi co trong so theo chieu sau
void weightedDFS(AdjMatrixGraph& g, int u, bool visited[]) {
    visited[u] = true;
    cout << u << " ";
    for (int v = 0; v < g.numVertices; v++) {
        if (g.adjMatrix[u][v] > 0 && !visited[v]) {
            weightedDFS(g, v, visited);
        }
    }
}

// e) Duyet toan bo do thi (ke ca do thi khong lien thong)
void traverseGraph(AdjMatrixGraph& g) {
    bool visited[MAX_VERTICES] = {false};
    for (int i = 0; i < g.numVertices; i++) {
        if (!visited[i]) {
            DFS(g, i, visited);
        }
    }
    cout << endl;
}

// f) Duyet do thi theo chieu rong (BFS)
void BFS(AdjMatrixGraph& g, int vertex) {
    queue<int> q;
    bool visited[MAX_VERTICES] = {false};

    visited[vertex] = true;
    q.push(vertex);

    while (!q.empty()) {
        int currVertex = q.front();
        cout << currVertex << " ";
        q.pop();

        for (int i = 0; i < g.numVertices; i++) {
            if (g.adjMatrix[currVertex][i] != 0 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

// g) Dem tong so canh cua do thi vo huong
int countEdges(AdjMatrixGraph& g) {
    int count = 0;
    for (int i = 0; i < g.numVertices; i++) {
        for (int j = i + 1; j < g.numVertices; j++) {
            if (g.adjMatrix[i][j] != 0) {
                count++;
            }
        }
    }
    return count;
}

// h) Dem so canh vao cua dinh x
int countIncomingEdges(AdjMatrixGraph& g, int x) {
    int count = 0;
    for (int i = 0; i < g.numVertices; i++) {
        if (g.adjMatrix[i][x] != 0) {
            count++;
        }
    }
    return count;
}

// i) Liet ke cac dinh khong ke voi dinh x
void notAdjacent(AdjMatrixGraph& g, int x) {
    for (int i = 0; i < g.numVertices; i++) {
        if (i != x && g.adjMatrix[x][i] == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}

// j) Liet ke cac dinh khong the tham tu dinh x
void unreachableVertices(AdjMatrixGraph& g, int x) {
    bool visited[MAX_VERTICES] = {false};
    DFS(g, x, visited);
    for (int i = 0; i < g.numVertices; ++i) {
        if (!visited[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

// k) Kiem tra mot day dinh co phai la duong di hop le
bool isPath(AdjMatrixGraph& g, int arr[], int k) {
    for (int i = 0; i < k - 1; ++i) {
        if (g.adjMatrix[arr[i]][arr[i + 1]] == 0)
            return false;
    }
    return true;
}

// Ham phu tro: kiem tra dinh u co the di den dinh dest
bool canReach(AdjMatrixGraph& g, int u, int dest, bool visited[]) {
    if (u == dest) return true;
    visited[u] = true;
    for (int v = 0; v < g.numVertices; v++) {
        if (g.adjMatrix[u][v] != 0 && !visited[v]) {
            if (canReach(g, v, dest, visited)) return true;
        }
    }
    return false;
}

// l) Liet ke cac dinh co the di den dinh x
void pathToVertex(AdjMatrixGraph& g, int x) {
    for (int i = 0; i < g.numVertices; ++i) {
        if (i == x) continue;
        bool visited[MAX_VERTICES] = {false};
        if (canReach(g, i, x, visited)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

// Ham chinh
int main() {
    AdjMatrixGraph g;
    string filename = "Graph1.txt";
    readGraphFromFile(filename, g);
    printGraph(g);

    cout << "DFS tu dinh 0: ";
    bool visitedDFS[MAX_VERTICES] = {false};
    DFS(g, 0, visitedDFS);
    cout << endl;

    cout << "Weighted DFS tu dinh 0: ";
    bool visitedW[MAX_VERTICES] = {false};
    weightedDFS(g, 0, visitedW);
    cout << endl;

    cout << "BFS tu dinh 0: ";
    BFS(g, 0);

    cout << "Tong so canh (do thi vo huong): " << countEdges(g) << endl;
    cout << "So canh vao dinh 0: " << countIncomingEdges(g, 0) << endl;

    cout << "Cac dinh khong ke voi dinh 0: ";
    notAdjacent(g, 0);

    cout << "Cac dinh khong the tham duoc tu dinh 0: ";
    unreachableVertices(g, 0);

    cout << "Cac dinh co the di den dinh 0: ";
    pathToVertex(g, 0);

    int path[] = {0, 1, 2};
    cout << "Day {0, 1, 2} ";
    if (isPath(g, path, 3)) cout << "la duong di hop le\n";
    else cout << "khong phai duong di\n";

    return 0;
}

