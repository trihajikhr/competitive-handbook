---
obsidianUIMode: preview
note_type: problem set
id_problem: 03PS-STMSPS0002
judul_problem: Merge Sort algorithm
sumber: hackerrank.com
kategori_problem: 📊 problem_statement
kesulitan: 🥇 hard
time_complexity: 🟤 O(n log n)
memory_complexity: 🟠 O(n) ✅ → Stable
status: 🏆 solved
date_solved: 2025-04-10T07:52:00
pendekatan: merge sort algorithm
tags:
  - array
  - sorting
  - merge-sort
---
Link problem: [Merge Sort \| HW1 Question \| Contests \| HackerRank](https://www.hackerrank.com/contests/hw1/challenges/merge-sort/problem)

#array #sorting #merge-sort 

---
# Merge Sort algorithm
Time limit: -
Memory limit: -

Urutkan array yang diinputkan oleh user dengan menggunakan algoritma merge sort.

### Input
- Baris pertama menerima ukuran array
- Baris kedua menerima nilai atau value dari array.
#### Input constraints
\-
### Output
\-
### Examples
Input:
```
5
5 4 3 2 1
```

Output:
```bash
1 2 3 4 5 
```

### Note
\-
# Jawaban
Dengan menggunakan algoritma merge sort yang diimprovisasi:

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)

void merge(vector<int>&arr, int p, int q, int r){
    int n1=q-p+1;
    int n2=r-q;
    
    vector<int>L(arr.begin()+p, arr.begin()+q+1);
    vector<int>M(arr.begin()+q+1,arr.begin()+r+1);
    
    int i{}, j{}, k{p};
    
    while(i < n1 && j < n2){
        if(L[i]<M[j]){
            arr[k++]=L[i++];
        } else {
            arr[k++]=M[j++];
        }
    }
    
    while(i < n1){
        arr[k++]=L[i++];
    }
    
    while(j < n2){
        arr[k++]=M[j++];
    }
    
}

void mergeSort(vector<int>&arr, int l, int r){
    if(l < r){
        int m= l+(r-l)/2;
        
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main(){
    fastio();
    
    int n; cin >> n;
    vector<int>arr(n);
    for(auto&x:arr)cin >> x;
    mergeSort(arr, 0, n-1);
    
    cout << "[";
    for(int i=0; i<n-1; i++){
        cout << arr[i] << ",";
    }
    cout << arr[n-1] << "]";
    
    return 0;
}
```

Time complexity: $O(n\;log\;n)$
Memory complexity: $O(n)$
## Jawaban efektif
Dengan pemahaman yang lebih baik pada algoritma merge sort ini, maka ditambahkan beberapa efisiensi sebagai berikut:

```cpp
#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)
#define vi vector<int>

void merge(vi &arr, int p, int q, int r){
    int n1=q-p+1;
    int n2=r-q;
    
    vi L (arr.begin()+p, arr.begin()+q+1);
    vi M (arr.begin()+q+1, arr.begin()+r+1);
    
    int i{}, j{}, k{p};
    
    while(i < n1 && j < n2){
        if(L[i]<=M[j]){
            arr[k++]=L[i++];
        } else {
            arr[k++]=M[j++];
        }
    }
    
    while(i < n1){
        arr[k++]=L[i++];
    }
    
    while(j < n2){
        arr[k++]=M[j++];
    }
}

void mergeSort(vi &arr, int l, int r){
    if(l < r){
        int m=l+(r-l)/2;
        
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main(){
    fastio();
    
    int n; cin >> n;
    vi arr(n);
    for(auto&x:arr) cin >> x;
    mergeSort(arr, 0, n-1);
    cout << "[";
    for(int i=0; i<n-1; i++){
        cout << arr[i] << ",";
    }
    cout << arr[n-1] << "]";
    
    return 0;
}
```

Time complexity: $O(n\;log\;n)$
Memory complexity: $O(n)$
# Editorial 
Perubahan pada improvisasi merge sort diatas, mengikuti penulisan kode yang efisien dari editorial problem statement [[03PS-STMSPS0001]].
# Informasi tambahan