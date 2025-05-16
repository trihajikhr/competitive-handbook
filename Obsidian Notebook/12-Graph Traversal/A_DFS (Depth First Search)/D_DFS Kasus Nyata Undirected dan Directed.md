---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 12TH-GTDF-S004
nama_algoritma: 
kategori_algoritma: Graph Algorithm - Traversal
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: "buku: CP handbook by Antti Laaksonen & programmiz.com & geeksforgeeks.com & chatgpt.com"
date_learned: 2025-05-03T19:51:00
tags:
  - graph
  - depth-first-search
  - graph-traversal
---
#graph #depth-first-search #graph-traversal 

---
# Undirected - Connected
Implementasi dinamis dalam C++:
## Versi 1:
Di versi ini, implementasi masih mengikuti referensi awal, belum banyak perubahan: 

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

inline void fastio(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
}

void dfsRec(vector<vector<int>>&adj, vector<bool>&visited, int s, vector<int>&rest){
    visited[s]=true;
    rest.push_back(s);

    for(auto&x:adj[s]){
        if(visited[x]==false){
            dfsRec(adj, visited, x, rest);
        }
    }
}

vector<int> DFS(vector<vector<int>>&adj){
    vector<bool> visited(adj.size(), false);
    vector<int> rest;
    dfsRec(adj, visited, 0, rest);
    return rest;
}

void addEdge(vector<vector<int>>&adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    fastio();
    int n,m;
    cin >> n >> m;

    vector<vector<int>>adj(n);

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;

        addEdge(adj,u,v);
    }

    for(auto&x:adj){
        sort(x.begin(), x.end());
    }

    vector<int> rest = DFS(adj);

    cout << "\nHasil : ";
    for(auto&x:rest){
        cout << x << " ";
    }
    return 0;
}
```

# Undirected - Disconnected
Implementasi dinamis dalam C++:
## Versi 1:
Di versi ini, implementasi masih mengikuti referensi awal, belum banyak perubahan: 

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

inline void fastio(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
}

void dfsRec(vector<vector<int>>&adj, vector<bool>&visited, int s, vector<int>&rest){
    visited[s]=true;
    rest.push_back(s);

    for(auto&x:adj[s]){
        if(visited[x]==false){
            dfsRec(adj, visited, x, rest);
        }
    }
}

vector<int> DFS (vector<vector<int>>&adj){
    vector<bool> visited (adj.size(), false);
    vector<int> rest;


    for(int i=0;i<adj.size();i++){
        if(visited[i]==false){
            dfsRec(adj, visited, i, rest);
        }
    }
    return rest;
}

void addEdge(vector<vector<int>>&adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    fastio();
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;

        addEdge(adj,u,v);
    }

    for(auto&x:adj){
        sort(x.begin(), x.end());
    }

    vector<int> rest = DFS(adj);

    cout << "Hasil: ";
    for(auto&x:rest){
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
```

# Directed - Connected
Implementasi dinamis dalam C++:
## Versi 1:
Di versi ini, implementasi masih mengikuti referensi awal, belum banyak perubahan: 

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

inline void fastio(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
}

void dfsRec(vector<vector<int>>&adj, vector<bool>&visited, int s, vector<int>&rest){
    visited[s]=true;
    rest.push_back(s);

    for(auto&x:adj[s]){
        if(visited[x]==false){
            dfsRec(adj, visited, x, rest);
        }
    }
}

vector<int> DFS(vector<vector<int>>&adj){
    vector<bool> visited(adj.size(), false);
    vector<int> rest;
    dfsRec(adj, visited, 0, rest);
    return rest;
}

void addEdge(vector<vector<int>>&adj, int u, int v){
    adj[u].push_back(v);
}

int main() {
    fastio();
    int n,m;
    cin >> n >> m;

    vector<vector<int>>adj(n);

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;

        addEdge(adj,u,v);
    }

    for(auto&x:adj){
        sort(x.begin(), x.end());
    }

    vector<int> rest = DFS(adj);

    cout << "\nHasil : ";
    for(auto&x:rest){
        cout << x << " ";
    }
    return 0;
}
```

# Directed - Disconnected
Implementasi dinamis dalam C++:
## Versi 1:
Di versi ini, implementasi masih mengikuti referensi awal, belum banyak perubahan: 

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

inline void fastio(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
}

void dfsRec(vector<vector<int>>&adj, vector<bool>&visited, int s, vector<int>&rest){
    visited[s]=true;
    rest.push_back(s);

    for(auto&x:adj[s]){
        if(visited[x]==false){
            dfsRec(adj, visited, x, rest);
        }
    }
}

vector<int> DFS (vector<vector<int>>&adj){
    vector<bool> visited (adj.size(), false);
    vector<int> rest;


    for(int i=0;i<adj.size();i++){
        if(visited[i]==false){
            dfsRec(adj, visited, i, rest);
        }
    }
    return rest;
}

void addEdge(vector<vector<int>>&adj, int u, int v){
    adj[u].push_back(v);
}

int main() {
    fastio();
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;

        addEdge(adj,u,v);
    }

    for(auto&x:adj){
        sort(x.begin(), x.end());
    }

    vector<int> rest = DFS(adj);

    cout << "Hasil: ";
    for(auto&x:rest){
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
```