#include<bits/stdc++.h>
using namespace std;

// #define v 4

// void init(int arr[][v]) {
//     int i, j;
//     for (i = 0; i < v; i++) {
//         for (j = 0; j < v; j++) {
//             arr[i][j] = 0;
//         }
//     }
// }

// void addedge(int arr[][v], int i, int j) {
//     arr[i][j] = arr[j][i] = 1;
// }

// void printmat(int arr[][v]) {
//     int i, j;
//     for (i = 0; i < v; i++) {
//         cout << i << " ";
//         for (j = 0; j < v; j++) {
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

// void bfs(int arr[][v], int startVertex) {
//     bool visited[v] = {false};
//     int queue[v];
//     int front = 0, rear = 0;

//     visited[startVertex] = true;
//     queue[rear++] = startVertex;

//     while (front < rear) {
//         int vertex = queue[front++];
//         cout << vertex << " ";

//         for (int i = 0; i < v; i++) {
//             if (arr[vertex][i] == 1 && !visited[i]) {
//                 visited[i] = true;
//                 queue[rear++] = i;
//             }
//         }
//     }
// }

class Graph {
public:
    list<int>* adjList;

    Graph(int vertices) {
        adjList = new list<int>[vertices];
    }

    void addEdge(int u, int x) {
        adjList[u].push_back(x);
        adjList[x].push_back(u);
    }

    void printAdjacencyList() {
        for (int i = 0; i < v; i++) {
            cout << "Adjacency list of vertex " << i << ": ";
            for (auto& neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // int adjmat[v][v];
    // init(adjmat);
    // printmat(adjmat);
    // cout << endl;
    // addedge(adjmat, 0, 1);
    // addedge(adjmat, 0, 2);
    // addedge(adjmat, 3, 1);
    // addedge(adjmat, 1, 2);
    // addedge(adjmat, 0, 3);
    // addedge(adjmat, 2, 1);

    // cout << "Breadth-First Traversal (starting from vertex 0): ";
    // bfs(adjmat, 0);

    Graph graph(v);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 6);
    graph.addEdge(3, 5);
    graph.addEdge(4, 1);
    graph.addEdge(4, 5);
    graph.addEdge(5, 2);
    graph.addEdge(5, 3);
    graph.addEdge(5, 6);
    cout << "\nAdjacency List:\n";
    graph.printAdjacencyList();

    return 0;
}