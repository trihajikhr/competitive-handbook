---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 12TH-GTBF-S004
nama_algoritma: 
kategori_algoritma: Graph Algorithm - Traversal
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber: "buku: CP handbook by Antti Laaksonen & chatgpt.com"
date_learned: 2025-05-03T21:22:00
tags:
  - graph-algorithm
  - graph-traversal
  - breadth-first-search
---
#graph-algorithm #graph-traversal #breadth-first-search 

---
# Undirected - Connected
Implementasi dinamis dalam C++:
## Versi 1:
Di versi ini, implementasi masih mengikuti referensi awal, belum banyak perubahan: 

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

inline void fastio(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
}

vector<int> bfs (vector<vector<int>>&adj){
    int v=adj.size();
    int s=0;

    vector<int>rest;

    queue<int> q;

    vector<bool> visited(v, false);

    visited[s]=true;
    q.push(s);

    while(!q.empty()){
        int curr= q.front();
        q.pop();
        rest.push_back(curr);

        for(int x: adj[curr]){
            if(visited[x]==false){
                visited[x]=true;
                q.push(x);
            }
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

    vector<int> rest = bfs(adj);

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
#include<queue>
using namespace std;

inline void fastio(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
}

void bfs(vector<vector<int>>&adj, vector<bool>&visited, int s, vector<int>&rest){
    queue<int> que;

    visited[s]=true;
    que.push(s);

    while(!que.empty()){
        int curr = que.front();
        que.pop();
        rest.push_back(curr);

        for(int x:adj[curr]){
            if(!visited[x]){
                visited[x]=true;
                que.push(x);
            }
        }
    }
}

vector<int> Discbfs(vector<vector<int>>&adj){
    vector<bool> visited(adj.size(), false);
    vector<int> rest;
    for(int i=0;i<adj.size(); i++){
        if(!visited[i]){
            bfs(adj, visited, i, rest);
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

    vector<int> rest = Discbfs(adj);

    for(auto&x:rest){
        cout << x << " ";
    }
    return 0;
}
```

## Versi 2:
Di versi 2, terdapat penyederhaan kode program, dimana tidak perlu menggunakan fungsi `addEdge()`, dan menggunakan bantuan `using vvi=vector<vector<int>>` untuk mengefisienkan waktu penulisan program:

```cpp
#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

using vvi = vector<vector<int>>;

inline void fastio(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
}

void bfs(vvi&adj, vector<bool>&visited, int s, vector<int>&rest){
    queue<int> que;

    visited[s]=true;
    que.push(s);

    while(!que.empty()){
        int curr = que.front();
        que.pop();
        rest.push_back(curr);

        for(auto&x:adj[curr]){
            if(!visited[x]){
                visited[x]=true;
                que.push(x);
            }
        }
    }
}

vector<int> discbfs (vvi&adj){
    vector<bool> visited(adj.size(), false);
    vector<int> rest;

    for(int i=0;i<adj.size(); i++){
        if(!visited[i]){
            bfs(adj, visited, i, rest);
        }
    }
    return rest;
}

int main() {
    fastio();
    int n, m;
    cin >> n >> m;

    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(auto&x:adj){
        sort(x.begin(), x.end());
    }

    vector<int> rest = discbfs(adj);

    cout << "\nHasil: ";
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
#include<queue>
using namespace std;

inline void fastio(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
}

vector<int> bfs (vector<vector<int>>&adj){
    int v=adj.size();
    int s=0;

    vector<int>rest;

    queue<int> q;

    vector<bool> visited(v, false);

    visited[s]=true;
    q.push(s);

    while(!q.empty()){
        int curr= q.front();
        q.pop();
        rest.push_back(curr);

        for(int x: adj[curr]){
            if(visited[x]==false){
                visited[x]=true;
                q.push(x);
            }
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

    vector<int> rest = bfs(adj);

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
#include<queue>
using namespace std;

inline void fastio(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
}

void bfs(vector<vector<int>>&adj, vector<bool>&visited, int s, vector<int>&rest){
    queue<int> que;

    visited[s]=true;
    que.push(s);

    while(!que.empty()){
        int curr = que.front();
        que.pop();
        rest.push_back(curr);

        for(int x:adj[curr]){
            if(!visited[x]){
                visited[x]=true;
                que.push(x);
            }
        }
    }
}

vector<int> Discbfs(vector<vector<int>>&adj){
    vector<bool> visited(adj.size(), false);
    vector<int> rest;
    for(int i=0;i<adj.size(); i++){
        if(!visited[i]){
            bfs(adj, visited, i, rest);
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

    vector<int> rest = Discbfs(adj);

    for(auto&x:rest){
        cout << x << " ";
    }
    return 0;
}
```