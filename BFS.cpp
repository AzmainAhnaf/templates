#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> parent;
vector<bool> vis;

void bfs(int start){
    queue<int> order;
    // Order of traversal
    order.push(start);
    vis[start] = true;
    while (!order.empty()){
        // storing current node and popping out
        int cur = order.front();
        order.pop();
        for (int next: adj[cur]){
            // checking if neighbor visited
            if (!vis[next]){
                order.push(next);
                vis[next] = true;
                parent[next] = cur;
            }
        }
    }
}


int main(){
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1), parent.resize(n + 1);
    vis.assign(n + 1, false);
    parent[1] = -1;
    // taking edge inputs
    while(m--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // doing bfs on node 1
    bfs(1);
    // vector to construct the path
    vector<int> path;
    if (vis[n]){
        for (int i = n; i != -1; i = parent[i]){
            path.push_back(i);
        }
        reverse(path.begin(), path.end());
        cout << path.size() << "\n";
        for (int node: path){
            cout << node << " ";
        }
    }
    else {
        cout << "IMPOSSIBLE\n";
    }
}
