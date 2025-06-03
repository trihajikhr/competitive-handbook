---
obsidianUIMode: preview
note_type: problem set
id_problem: 03PS-STSS-E003
judul_problem: Temukan elemen ke-k setelah sorting
sumber: chatgpt.com
kategori_problem: 🎯 exercise
kesulitan: 🥉 easy
time_complexity: 🟣 O(n²)
memory_complexity: 🟢 O(1) ❌ → Unstable
status: 🏆 solved
date_solved: 2025-03-06T15:43:00
pendekatan: selection sort algorithm
tags:
  - array
  - sorting
  - selection-sort
---
Link problem: 

#selection-sort #array #sorting 

---
# Temukan Elemen ke-k setelah Sorting
Time limit: -
Memory limit: -

Diberikan sebuah array **n** bilangan bulat, setelah diurutkan dalam **ascending order** menggunakan Selection Sort, tentukan **elemen ke-k** dalam array yang sudah terurut.

### Input
- **n** (jumlah elemen dalam array).
- **n** bilangan bulat dalam satu baris.
- **k** (indeks 1-based dari elemen yang ingin dicari setelah sorting).
#### Input constraints
\-
### Output
Bilangan ke-**k** setelah array diurutkan.
### Examples
Input:
```
5  
3 1 4 1 5  
3  
```

Output:
```bash
3  
```

Ketika array sudah diurutkan, maka urutan ketiga dari array ketika sudah diurutkan adalah 3. Yaitu {1, 1 ,**3** ,4 ,5}.
### Note
\-
# Jawaban
Berikut jawaban yang belum terlalu dimodifikasi:

```cpp
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

void selectionSort(vector<int>&arr){
    int n=arr.size();

    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]) min=j;
        }
        swap(arr[min],arr[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,x; 
    cin >> n;
    vector<int> arr(n);

    for(auto&x:arr) cin >> x;

    cin >> x;
    selectionSort(arr);

    cout << arr[x-1] << "\n";

    return 0;
}

```

Time complexity: $O(n^2)$
Memory complexity: $O(1)$
## Jawaban efektif
Kesederhanaan:

```cpp
#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> & arr){
    int n=arr.size();

    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]) min = j;
        }
        swap(arr[min], arr[i]);
    }
}

int main(){
    int n,x;
    cin >> n;

    vector<int> arr(n);

    for(int &x:arr) cin >> x;

    cin >> x;
    selectionSort(arr);

    cout << arr[x-1] << "\n";

    return 0;
}
```

Time complexity: $O(n^2)$
Memory complexity: $O(1)$
# Editorial 
Terdapat masalah ketika aku menjalankan kode di `main`, misal seperti ini:

```cpp
int main(){
    int n,x;
    cin >> n;

    vector<int> arr(n);

    for(int &x:arr) cin >> x;

    selectionSort(arr);
    cin >> x;    // cin >> x; dibawah pemanggilan fungsi!

    cout << arr[x-1] << "\n";

    return 0;
}
```

Dimana ketika `cin >> x;` ditulis sesudah pemanggilan fungsi, input untuk variabel `x` tidak mau muncul. Masalah terjadi karena **urutan `cin >> x` setelah `selectionSort(arr)`** membuat input yang seharusnya diambil sebagai elemen **x** malah diabaikan.

Mari kita **analisis kode ini** secara lebih mendalam:

---

### Kode yang Bermasalah

```cpp
cin >> n;
vector<int> arr(n);

for(auto& x : arr) cin >> x;

cin >> x;  // ← PROBLEM! Seharusnya ini sebelum selectionSort

selectionSort(arr);

cout << arr[x-1] << "\n";
```

---

### Kenapa Bermasalah?

1. **`cin >> n`** → Membaca ukuran array **n**.
2. **Loop `for(auto& x : arr) cin >> x;`** → Mengisi array dengan **n** angka.
3. **`cin >> x;`**
    - **Masalahnya**: Jika kita menjalankan **`selectionSort(arr);`** sebelum **`cin >> x;`**, maka kode tetap menunggu input tambahan **x** dari pengguna.
    - Namun, karena pengguna mungkin sudah memasukkan semua angka dalam satu baris saat input array, **`cin >> x;` tidak membaca input yang diharapkan**.

---

### Solusi: Tukar Urutan Input

Pastikan **x diambil sebelum memanggil selectionSort**:

```cpp
cin >> n;
vector<int> arr(n);

for(auto& x : arr) cin >> x;

cin >> x;  // Pastikan kita ambil x sebelum sorting!

selectionSort(arr);

cout << arr[x-1] << "\n";
```

Sekarang kode **akan berjalan dengan benar!** ✅ 🚀
# Informasi tambahan