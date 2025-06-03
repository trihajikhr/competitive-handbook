---
obsidianUIMode: preview
note_type: problem set
id_problem: 03PS-STBS-E003
judul_problem: Jumlah perbandingan
sumber: chatgpt.com
kategori_problem: 🎯 exercise
kesulitan: 🥉 easy
time_complexity: 🟣 O(n²)
memory_complexity: 🟢 O(1) ✅ → Stable
status: 🏆 solved
date_solved: 2025-03-04T22:00:00
pendekatan: bubble sort algorithm
tags:
  - array
  - bubble-sort
  - sorting
---
Link problem: 

#array #bubble-sort #sorting 

---
# Hitung Jumlah Perbandingan dalam Bubble Sort
Time limit: -
Memory limit: -

Urutkan sebuah array yang dimasukan dengan menggunakan algoritma bubble sort, lalu hitung jumlah perbandingan atau comparison yang dilakukan.

### Input
- Baris pertama berisi satu bilangan bulat $n(1 \leq n \leq 1000)$, jumlah elemen array.
- Baris kedua berisi $n$ bilangan bulat yang merupakan elemen array _(angka bisa negatif atau positif_, $-10^6 ≤ a_{i} ≤ 10^6)$.
#### Input constraints
\-
### Output
- Cetak array yang sudah terurut dalam satu baris.
- Cetak jumlah **perbandingan (comparison)** yang dilakukan selama proses Bubble Sort.
### Examples
Input 1:
```
5  
5 3 8 1 2  
```

Output 1:
```bash
1 2 3 5 8  
10  
```

Input 2:
```
10
1 4 3 2 7 6 5 8 9 11
```

Output:
```bash
1 2 3 4 5 6 7 8 9 11  
24  
```

### Note
Perbandingan terjadi setiap kali `if(arr[j] > arr[j+1])` dievaluasi.
# Jawaban

```cpp
#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0); cin.tie(0);
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(a) for(auto&x:a)
using vi=vector<int>;

int bs(vi & arr){
    int n=arr.size();
    int count=0;

    rep(i,0,n-1){
        bool swapped=false;

        rep(j,0,n-i-1){
            count++;
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped=true;
            }
        }
        if(!swapped) break;
    }
    return count;
}

int main(){
    fastio();
    int n;cin >>n;
    vi arr(n);
    fore(arr)cin >> x;
    int rest=bs(arr);
    fore(arr)cout << x << " ";
    cout << "\n" << rest << "\n";

    return 0;
}
```

Time complexity: $O(n^2)$
Memory complexity: $O(1)$
## Jawaban efektif
// penjelasan singkat

```cpp

```

Time complexity: $O()$
Memory complexity: $O()$
# Editorial 
Kita hanya perlu menambahkan variabel  `count`, dan melakukan iterator didalam perulangan kedua, namun bukan didalam percabangan. Ini adalah jumlah total pemeriksaan kondisional antara `arr[j]` dengan `arr[j+1]`.

Perhatikan iterator `count++` pada baris ke 17.
# Informasi tambahan