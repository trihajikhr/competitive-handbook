---
obsidianUIMode: preview
note_type: problem set
id_problem: 03PS-STBS-E002
judul_problem: Hitung swap
sumber: chatgpt.com
kategori_problem: 🎯 exercise
kesulitan: 🥉 easy
time_complexity: 🟣 O(n²)
memory_complexity: 🟢 O(1) ✅ → Stable
status: 🏆 solved
date_solved: 2025-03-04T21:21:00
pendekatan: bubble sort algorithm
tags:
  - array
  - bubble-sort
  - sorting
---
Link problem: -

#array  #bubble-sort #sorting 

---
# Hitung swap
Time limit: -
Memory limit: -

Modifikasi algoritma **Bubble Sort** sehingga selain mengurutkan array, program juga mencetak **jumlah pertukaran (swap) yang terjadi** selama proses sorting.
### Input
- Satu bilangan bulat $N \, (1 ≤ N ≤ 1000)$, banyaknya elemen dalam array.
- $N$ bilangan bulat terpisah dengan spasi.
#### Input constraints
\-
### Output
- Cetak array yang telah diurutkan dalam satu baris.
- Cetak jumlah total pertukaran yang terjadi selama proses sorting.
### Examples
Input 1:
```
5
5 3 8 1 2
```

Output 1:
```bash
1 2 3 5 8
7
```


Input 2:
```
4
10 7 3 5
```

Output 2:
```bash
3 5 7 10
5
```

### Note
\-
# Jawaban
Sebenarnya soal ini mudah, hanya perlu menambahkan sedikit variabel tambahan:

```cpp
#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0); cin.tie(0);
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(a) for(auto&x:a)
using vi = vector<int>;

int bs(vi & arr){
    int n =arr.size();
    int count=0;

    rep(i,0,n-1){
        bool sw=false;
        rep(j,0,n-i-1){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                sw=true;
                count++;
            }
        }
        if(!sw) break;
    }
    return count;
}

int main(){
    fastio();
    int n; cin >> n;

    vi arr(n);
    fore(arr) cin >> x;
    int rest=bs(arr);
    fore(arr) cout << x << " ";
    cout << "\n" <<rest;

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
Cukup tambahkan variabel `count` pada perulangan kedua, tepatnya di kondisi ketika `arr[j] > arr[j+1]`. Ketika kondisi ini terpenuhi, maka akan terjadi `swap`, dan variabel `count` akan menampung banyaknya swap yang terjadi. 

Setelah itu kita kembalikan nilai `count`, dan tampilkan jumlah swap dengan `cout` di fungsi main.

Problem ini sangat mudah.
# Informasi tambahan