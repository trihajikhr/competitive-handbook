---
obsidianUIMode: preview
note_type: problem set
id_problem: 03PS-STBS-E004
judul_problem: Urutan terbesar ke terkecil
sumber: chatgpt.com
kategori_problem: 🎯 exercise
kesulitan: 🥉 easy
time_complexity: 🟣 O(n²)
memory_complexity: 🟢 O(1) ✅ → Stable
status: 🏆 solved
date_solved: 2025-03-04T22:29:00
pendekatan: bubble sort algorithm
tags:
  - array
  - bubble-sort
  - sorting
---
Link problem: 

#array #bubble-sort #sorting 

---
# Urutan Terbesar ke Terkecil (Bubble Sort Descending)
Time limit: -
Memory limit: -

Buat program yang menerima array, lalu mengurutkanya dengan urutan descending, dan juga menghitung banyak swap yang terjadi.

### Input
- Satu bilangan bulat **n** $(1 \leq n \leq 1000)$, jumlah elemen array.
- **n** bilangan bulat yang dipisahkan oleh spasi, masing-masing dalam rentang $(-10^6 \leq a_i \leq 10^6)$.
#### Input constraints
\-
### Output
- Cetak **array yang sudah terurut** dalam **descending order**.
- Cetak jumlah **pertukaran (swap)** yang terjadi selama proses sorting.
### Examples
Input 1:
```
5
3 1 4 1 5
```

Output 1:
```bash
5 4 3 1 1 
6
```

Input 2:
```
10
6 5 3 2 4 7 8 9 10 1
```

Output 2:
```bash
10 9 8 7 6 5 4 3 2 1 
28
```
### Note
\-
# Jawaban
Disini karena sedang mempelajari tentang bubble sort, masih belum menggunakan built-in function, yaitu `sort()`.

```cpp
#include<bits/stdc++.h>
using namespace std;

// yang jelas tidak menggunakan: sort(arr.rbegin(), arr.rend())
// karena terlalu gampang

#define fastio() ios_base::sync_with_stdio(0); cin.tie(0);
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(a) for(auto&x:a)
using vi = vector<int>;

int bubbleSort(vi & arr){
    int n= arr.size();
    int count=0;

    rep(i,0,n-1){
        bool swapped=false;
        rep(j,0,n-i-1){
            if(arr[j]< arr[j+1]){    // sebelumnya >, sekarang < 
                swap(arr[j], arr[j+1]);
                count++;
                swapped = true;
            }
        }
        if(!swapped) break;
    }
    return count;
}

int main(){
    fastio();
    int n; cin >> n;
    vi arr(n);

    fore(arr) cin >> x;
    int rest = bubbleSort(arr);
    fore(arr) cout << x << " ";

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
Yang perlu kita lakukan agar membuat sorting bubble sort menjadi descending, adalah cukup merubah kondisionalnya saja, yang sebelumnya seperti ini:

```cpp
if(arr[j] > arr[j+1])
```

Menjadi seperti ini:

```cpp
if(arr[j] < arr[j+1])
```

Untuk menghitung banyaknya swap yang terjadi, latihan sebelumnya sudah kita bahas. Kita cukup menggunakan variabel `count`, dan melakukan iterasi pada `count++` untuk menghitung seberapa banyak swap yang terjadi, di perulangan kedua, didalam `if`.
# Informasi tambahan