---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 13TH-SPBF-0004
nama_algoritma: Bellman Ford Algorithm
kategori_algoritma: Graph - Shortest Path
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: "buku: CP handbook by Antti Laaksonen & chatgpt.com"
date_learned: 2025-05-04T13:14:00
tags:
  - graph-algorithm
  - shortest-paths
  - bellman-ford
---
#graph-algorithm #shortest-paths #bellman-ford 

---
# Implementasi Algoritma Bellman Ford
Implementasi dinamis dalam C++:
## Versi 1:

Di versi ini, implementasi masih mengikuti referensi awal, belum banyak perubahan:

```cpp
#include<iostream>
#include<vector>
using namespace std;

const int INF = 1e9;

inline void fastio(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
}

vector<int> bellmanFord(int n, vector<vector<int>>&edges, int src){
    vector<int> dist(n, INF);
    dist[src]=0;

    for(int i=0;i<n;i++){
        for(vector<int>edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if(dist[u] != INF && dist[u]+wt < dist[v]){
                if(i == n-1){
                    return {-1};
                } 

                dist[v] = dist[u] + wt;
            }
        }
    }
    return dist;
}

int main() {
    fastio();
    int n,m;
    cin >> n >> m;

    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;

        edges.push_back({u,v,w});
    }

    int src=0;
    vector<int> rest = bellmanFord(n, edges, src);

    cout << "\nHasil: ";
    for(auto&x:rest){
        if(x==INF) cout << "INF ";
        else cout << x << " ";
    }
    cout << "\n";
    return 0;
}
```