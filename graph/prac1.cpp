#include<bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int, list<int>>& adjlist, int node, unordered_map<int, bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adjlist[node]) {
        if (!visited[neighbor]) {
            dfs(adjlist, neighbor, visited);
        }
    }
}

void bfs(unordered_map<int, list<int>>& adjlist, int start) {
    queue<int> q;
    unordered_map<int, bool> visited;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        cout << node << " ";
        q.pop();

        for (int neighbor : adjlist[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main()
{
    int m,n;
    cout << "Enter number of vertices: " ;
    cin >> m;
    cout << "Enter number of edges: " ;
    cin >> n;
    int adjmat[m][m];
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            adjmat[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++)
    {
        int x ,y;
        cin >> x >> y;
        for(int j = 0; j < m; j++)
        {
            adjmat[x][y] = 1;
            adjmat[y][x] = 1;
        }
    }

    cout << "Adjacency matrix: " << endl;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << adjmat[i][j] << " ";
        }
        cout << endl;
    }

    unordered_map<int, list<int>> adjlist;
    int dir;
    cout << "Enter 1 if directed graph and 0 otherwise: ";
    cin >> dir;
    cout << "Taking input for adjacency list: " << endl;
    for(int i = 0; i < n;i++)
    {
        int a,b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        if(dir == 0)
        {
            adjlist[b].push_back(a);
        }
    }
    cout << "Adjacency list: "<< endl;
    for(auto i:adjlist)
    {
        cout << i.first << " -> " ;
        for(auto j : i.second)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    int start_node;
    cout << "Enter the starting node for BFS: ";
    cin >> start_node;
    cout << "BFS traversal starting from node " << start_node << ": ";
    bfs(adjlist, start_node);
    cout << endl;
    cout << "Enter the starting node for DFS: ";
    cin >> start_node;
    cout << "DFS traversal starting from node " << start_node << ": ";
    unordered_map<int, bool> visited;
    dfs(adjlist, start_node, visited);
    return 0;
}