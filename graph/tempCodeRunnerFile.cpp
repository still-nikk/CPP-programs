#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
public:
    int V;            // Number of vertices
    list<int>* adjList; // Array of lists

    Graph(int vertices) {
        V = vertices;
        adjList = new list<int>[V];
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For an undirected graph
    }

    void printAdjacencyList() {
        for (int i = 0; i < V; i++) {
            cout << "Adjacency list of vertex " << i << ": ";
            for (auto neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    void DFS(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (auto i = adjList[v].begin(); i != adjList[v].end(); ++i) {
            if (!visited[*i]) {
                DFS(*i, visited);
            }
        }
    }

    void DFSTraversal() {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                cout << "DFS starting from vertex " << i << ": ";
                DFS(i, visited);
                cout << endl;
            }
        }
    }
};

int main() {
    int vertices = 6; // Change the number of vertices as needed
    Graph graph(vertices);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);

    cout << "Adjacency List:" << endl;
    graph.printAdjacencyList();

    cout << "DFS Traversal:" << endl;
    graph.DFSTraversal();

    return 0;
}
