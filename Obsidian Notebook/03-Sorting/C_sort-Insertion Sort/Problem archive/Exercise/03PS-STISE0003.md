---
obsidianUIMode: preview
note_type: problem set
id_problem: 03PS-STISE0003
judul_problem: Berapa Kali Penyisipan Dilakukan?
sumber: chatgpt.com
kategori_problem: 🎯 exercise
kesulitan: 🥉 easy
time_complexity: 🟣 O(n²)
memory_complexity: 🟢 O(1) ✅ → Stable
status: 🏆 solved
date_solved: 2025-04-08T19:50:00
pendekatan: insertion sort algorithm
tags:
  - insertion-sort
  - sorting
  - array
---
Link problem: 

#insertion-sort #array #sorting 

---
# Berapa Kali Penyisipan Dilakukan?
Time limit: -
Memory limit: -

Diberikan sebuah array acak, hitung **jumlah total pergeseran elemen** yang dilakukan oleh algoritma **insertion sort** untuk mengurutkan array dalam urutan menaik. Satu pergeseran terjadi setiap kali elemen dipindahkan ke kanan.

### Input
- Baris pertama: integer `n` (1 ≤ n ≤ 10⁴)
- Baris kedua: `n` bilangan bulat (nilai antar -10⁴ hingga 10⁴)
#### Input constraints
\-
### Output
Satu bilangan bulat: total jumlah pergeseran (shifts)
### Examples
Input:
```
5
2 1 3 1 2
```

Output:
```bash
4
```

### Note
- 2 > 1 → shift 1
- 3 > 1 → shift 1
- 3 > 2 → shift 1
- 2 > 2 → tidak shift (karena sama)
# Jawaban
Yang perlu dilakukan adalah dengan meembuat fungsi yang mengembalikan nilai. Dan untuk melakukan, kita hanya perlu menambahkan variabel increment didalam perulangan kedua, untuk menghitung berapa banyak shift (pergeseran) yang terjadi.

Jangan lupa untuk menginisialisasi variabel `rest` dengan 0, agar increment berfungsi:

```cpp
#include<iostream>
#include<vector>
using namespace std;

int is(vector<int> & arr){
    int n=arr.size();
    int rest=0;
    
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        
        while(j>=0 && key < arr[j]){
            arr[j+1] = arr[j];
            --j;
            rest++;
        }
        arr[j+1]=key;
    }
    return rest;
}

int main(){
    int n; cin >> n;
    vector<int> arr(n);
    
    for(int&x:arr) cin >> x;
    cout << is(arr);
    
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
- Iterasi mulai dari indeks ke-1
- Simpan nilai `arr[i]` ke `key`
- Selama elemen sebelumnya lebih besar dari `key`, geser ke kanan dan tambahkan penghitung
- Sisipkan `key` ke posisi yang sesuai
- Kembalikan total jumlah pergeseran
# Informasi tambahan