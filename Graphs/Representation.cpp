#include <iostream>
using namespace std;


// to store in adjacency matrix 
// SC : O(N x N)
int main() {
    int n, m;
    cin >> n >> m;
    // graph here
    int adj[n+1][n+1];

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    return 0;
}

// to store in list
// SC : O(2 x Edges)
int main() {
    int n, m;
    cin >> n >> m;
    // graph here
    vector<int> adj[n+1];

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}
// for dirceted graph
// SC; O(Edges)
int main() {
    int n, m;
    cin >> n >> m;
    // graph here
    vector<int> adj[n+1];

    for(int i = 0; i < m; i++) {
        int u, v;
        // u ------> v
        cin >> u >> v;
        adj[u].push_back(v);
    }

    return 0;
}