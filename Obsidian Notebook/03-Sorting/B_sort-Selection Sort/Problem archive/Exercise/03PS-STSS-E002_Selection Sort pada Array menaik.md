---
obsidianUIMode: preview
note_type: problem set
id_problem: 03PS-STSS-E002
judul_problem: Selection sort pada array menaik
sumber: chatgpt.com
kategori_problem: 🎯 exercise
kesulitan: 🥉 easy
time_complexity: 🟣 O(n²)
memory_complexity: 🟢 O(1) ❌ → Unstable
status: 🏆 solved
date_solved: 2025-03-06T14:59:00
pendekatan: selection sort algorithm
tags:
  - sorting
  - array
  - selection-sort
---
Link problem: 

#array #selection-sort #sorting  

---
# Selection Sort pada Array menaik
Time limit: -
Memory limit: -

Diberikan sebuah array berisi **n angka**. Gunakan **Selection Sort** untuk mengurutkan array dalam **urutan naik (ascending order)**.

### Input
- Baris pertama berupa $n$, yaitu banyaknya array.
- Baris kedua berupa elemen-elemen array.
#### Input constraints
\-
### Output
Array dalam urutan ascending
### Examples
Input:
```
7
7 6 5 4 3 2 1
```

Output:
```bash
1 2 3 4 5 6 7
```

### Note
\-
# Jawaban
Berikut jawabanya, sangat mudah:

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void selectionSort(vector<int> & arr){
    int n=arr.size();

    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[min]) min=j;
        }
        swap(arr[min], arr[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> arr(n);
    for(auto&x:arr) cin >> x;
    selectionSort(arr);
    for(auto&x:arr) cout << x << " ";

    cout << "\n";

    return 0;
}
```

Time complexity: $O(n^2)$
Memory complexity: $O(1)$

---
Jika merasa menggunakan fungsi `swap` terlalu mudah:

```cpp
#include<iostream>
#include<vector>
using namespace std;

void tukar(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(vector<int> &arr){
    int n = arr.size();

    for(int i = 0; i < n - 1; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        tukar(&arr[min], &arr[i]);
    }
}

int main(){
    int n; 
    cin >> n;
    vector<int> arr(n);

    for(int &x : arr) {
        cin >> x;
    }

    selectionSort(arr);

    for(int x : arr) {
        cout << x << " ";
    }

    cout << "\n";

    return 0;
}
```
## Jawaban efektif
Mode competitive:

```cpp
#include<bits/stdc++.h>
using namespace std;

#define fore(a) for(auto&x:a)
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0);

void selectionSort(vector<int> & arr){
    int n = arr.size();

    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[min]) min=j;
        }
        swap(arr[min], arr[i]);
    }
}

int main(){
    fastio();
    int n; cin >>n;
    vector<int> arr(n);
    fore(arr) cin >> x;
    selectionSort(arr);
    fore(arr) cout << x << " ";
    
    cout << "\n";

    return 0;
}
```

Time complexity: $O(n^2)$
Memory complexity: $O(1)$
# Editorial 
Perhatikan baris ke-12, kita hanya perlu menggunakan perbandingan `arr[j] < arr[min]`, untuk mengurutkan dari terkecil ke terbesar dengan mudah. Jika kamu sudah memahami algoritma selection sort, soal ini bisa dikerjakan di luar kepala.
# Informasi tambahan