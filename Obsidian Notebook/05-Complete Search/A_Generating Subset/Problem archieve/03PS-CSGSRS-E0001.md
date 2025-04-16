---
obsidianUIMode: preview
note_type: problem set
id_problem: 05PS-CSGSRS-E0001
judul_problem: Membuat subset dari user
sumber: chatgpt.com
kategori_problem: 🎯 exercise
kesulitan: 🥉 easy
time_complexity: 🔴 O(2ⁿ)
memory_complexity: 🟠 O(n)
status: 🏆 solved
date_solved: 2025-04-12T12:03:00
pendekatan: recursive search subset
tags:
  - complete-search
  - recursive-search
  - generating-subset
---
Link problem: 

#complete-search #recursive-search #generating-subset 

---
# Membuat subset dari user
Time limit: -
Memory limit: -

Buatkan program yang menerima inputan array dari user, dan cetak subset dari array yang diberikan. Hasil subset harus dari angka besar, menuju angka kecil.

### Input
- Baris pertama berupa `n` ukuran array
- Baris kedua berupa isi array
#### Input constraints
\-
### Output
Hasil subset dari array yang diberikan, dan dimulai dari angka yang paling besar.
### Examples
Input:
```
5
5 2 3 4 1
```

Output:
```bash
[ ]
[ 5 ]
[ 4 ]
[ 4 5 ]
[ 3 ]
[ 3 5 ]
[ 3 4 ]
[ 3 4 5 ]
[ 2 ]
[ 2 5 ]
[ 2 4 ]
[ 2 4 5 ]
[ 2 3 ]
[ 2 3 5 ]
[ 2 3 4 ]
[ 2 3 4 5 ]
[ 1 ]
[ 1 5 ]
[ 1 4 ]
[ 1 4 5 ]
[ 1 3 ]
[ 1 3 5 ]
[ 1 3 4 ]
[ 1 3 4 5 ]
[ 1 2 ]
[ 1 2 5 ]
[ 1 2 4 ]
[ 1 2 4 5 ]
[ 1 2 3 ]
[ 1 2 3 5 ]
[ 1 2 3 4 ]
[ 1 2 3 4 5 ]
```

### Note
Sorting yang dilakukan boleh menggunakan STL sort, dan modifikasi fungsi sorting agar bisa menghasilkan urutan yang descending atau ascending.
# Jawaban
Berikut jawabanya:

```cpp
// buatkkan subset dari [1,2,3,4,5], dan berasal dari inputan user
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void search(vector<int>&subset, vector<int>&arr,int k,int n){
    if(k == n){
        cout << "[ ";
        for(int x : subset){
            cout << x << " ";
        }
        cout << "]\n";
    } else {
        search(subset,arr,k+1,n);
        subset.push_back(arr[k]);
        search(subset,arr,k+1,n);
        subset.pop_back();   
    }
}

int main(){
    int n; cin >> n;
    vector<int> arr (n), subset;
    for(int&x:arr) cin >> x;
    sort(arr.begin(),arr.end());

    search(subset,arr,0,n);
    return 0;
}
```

Time complexity: $O(2^n)$
Memory complexity: $O(n)$
## Jawaban efektif
// penjelasan singkat

```cpp

```

Time complexity: $O()$
Memory complexity: $O()$
# Editorial 
Untuk membuat subset dimulai dari angka kecil, maka array harus memiliki urusan ascending atau dari kecil, ke angka besar. Hal itu bisa dilakukan dengan cara ini:

```cpp
sort(arr.begin(), arr.end());
```

Jika ingin subset dimulai dari angka besar, ke angka kecil, bisa dilakukan dengan cara membuat array memiliki urutan descending, atau sebaliknya, modifikasi fungsi `sort` menjadi ini:

```cpp
sort(arr.rbegin(), arr.rend());
```

Sebenarnya, array yang dimasukan tidak harus diurutkan. Dan subses akan tetap bekerja, walaupun urutan angkanya tidak urut. Tanpa sort, kode akan tetap aman dan valid, walaupun urutan output yang bisa acak
# Informasi tambahan