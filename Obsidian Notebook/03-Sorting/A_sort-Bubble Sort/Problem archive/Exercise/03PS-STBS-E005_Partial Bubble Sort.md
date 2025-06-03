---
obsidianUIMode: preview
note_type: problem set
id_problem: 03PS-STBS-E005
judul_problem: Partial Bubble Sort
sumber: chatgpt.com
kategori_problem: 🎯 exercise
kesulitan: 🥉 easy
time_complexity: 🟣 O(n²)
memory_complexity: 🟢 O(1) ✅ → Stable
status: 🏆 solved
date_solved: 2025-03-04T23:02:00
pendekatan: bubble sort algorithm
tags:
  - array
  - bubble-sort
  - sorting
---
Link problem: 

#array  #sorting  #bubble-sort 

---
# Partial Bubble Sort
Time limit: -
Memory limit: -

Diberikan array $arr$ dengan panjang $n$, dan dua bilangan $l$ dan $r$ $(1 ≤ l ≤ r ≤ n)$, urutkan hanya bagian $arr[l-1]$ sampai $arr[r-1]$ dalam **ascending order** menggunakan Bubble Sort. Elemen di luar rentang tersebut tetap tidak berubah.

### Input
- Baris pertama berisi bilangan bulat $n$ $(1 ≤ n ≤ 100)$.
- Baris kedua berisi $n$ bilangan bulat, elemen array.
- Baris ketiga berisi dua bilangan $l$ dan $r$.
#### Input constraints
\-
### Output
Cetak array setelah pengurutan sebagian dilakukan.
### Examples
Input:
```
10
5 4 3 9 8 7 2 1 10 11
3 9
```

Output:
```bash
5 4 1 2 3 7 8 9 10 11
```

Penjelasan: Hanya angka ketiga sampai ke sembilan yang diurutkan. Diluar rentang tersebut, urutan angka tetap.
### Note
\-
# Jawaban
Ini adalah jawaban pertamaku, tetapi ada jawaban yang jauh lebih bagus dari ini.

```cpp
#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int l, int r, vector<int> & arr){

    int n = arr.size();

    for(int i=l-1;i<=r-1;i++){
        bool swapped=false;
        for(int j=l-1;j<n-i-1;j++){    
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped=true;
            }
        }
        if(!swapped) break;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l, r;
    cin >> n;
    vector<int> arr(n);
    for(auto& x : arr) cin >> x;

    cin >> l >> r;

    bubbleSort(l,r,arr);
    for(auto&x:arr) cout << x << " "; cout << "\n";

    return 0;
}
```

Time complexity: $O((r-l+1)^2)$
Memory complexity: $O(1)$
## Jawaban efektif
Ini adalah jawaban yang lebih dioptimalkan, karena batasan perulangan tidak melebihi yang seharusnya. Jawaban pertama memang bisa menghasilkan jawaban yang diinginkan, namun masih terdapat hal yang bisa diperbaiki, dan lagipula jika problem set berukuran besar, maka jawaban dibawah ini jauh lebih optimal:

```cpp
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void bs(vector<int>& arr, int l, int r) {
    // Konversi ke indeks 0-based
    // supaya tidak harus int i=l-1/atau i<r-1. Kurangi langsung saja!
    l--; r--;

    for (int i = l; i < r; i++) {
        bool swapped = false;
        for (int j = l; j < r - (i - l); j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; 
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l, r;
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr) cin >> x;
    cin >> l >> r;

    bs(arr, l, r);

    for (int& x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
```

Time complexity: $O((r-l+1)^2)$
Memory complexity: $O(1)$

## Edisi `sort()`
Kita juga bisa menggunakan fungsi `sort()`. Tetapi, pahami beberapa aturan berikut:
- Gunakan `sort(arr.begin() + l - 1, arr.begin() + r);` untuk mengurutkan subarray dari indeks `l` hingga `r` (1-based).
    
- Jangan menggunakan `arr.end() + r`, karena itu tidak valid dan akan menyebabkan kesalahan runtime.
    
- Pastikan Anda memahami cara kerja iterator dan range **\[first, last)** dalam `std::sort`.

Syntaxnya seperti ini:
```cpp
sort(arr.begin() + l - 1, arr.begin() + r);
```

Berikut adalah implementasi yang benar:
```cpp
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void partial_sort(vector<int>& arr, int l, int r) {
    // Mengurutkan subarray dari l hingga r (1-based)
    sort(arr.begin() + l - 1, arr.begin() + r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l, r;
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr) cin >> x;
    cin >> l >> r;

    partial_sort(arr, l, r);

    for (int& x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
```
# Editorial 
Catatan Perbaikan Kode Sorting dengan Batasan Kiri dan Kanan

### Kesalahan dalam Kode Awal

1. **Indeks yang Salah dalam Loop `i`**
    
    - Kode awal: `for(int i=l-1; i<=r-1;i++)`
    - **Kesalahan:** Loop berjalan hingga `r-1`, padahal harusnya `r-1` hanya sebagai batas akhir.
    - **Perbaikan:** `i < r - 1` agar iterasi berjalan dengan benar.
2. **Kesalahan dalam Loop `j` (Inner Loop)**
    
    - Kode awal: `for(int j=l-1;j<=r-1-(i-(l-1)); j++)`
    - **Kesalahan:** Batas kanan dari `j` salah dihitung, menyebabkan sorting tidak berjalan dengan baik.
    - **Perbaikan:** `j < r - 1 - (i - l)`, agar Bubble Sort tetap berjalan dengan benar.
3. **Konversi Indeks ke 0-based**
    
    - Karena input `l` dan `r` berbasis 1 (1-based index), maka perlu dikonversi ke **0-based index** dengan mengurangi 1.
    - **Perbaikan:** Tambahkan `l--` dan `r--` di awal fungsi.
4. **Mengoptimalkan Bubble Sort**
    
    - Bubble Sort bisa berhenti lebih awal jika tidak ada pertukaran.
    - **Perbaikan:** Menambahkan `swapped` untuk mengecek apakah ada pertukaran dalam iterasi tertentu.
    - Jika tidak ada pertukaran, keluar dari loop lebih awal untuk meningkatkan efisiensi.
5. **Kasus Ketika `l == r`**
    
    - Jika `l == r`, maka hanya satu elemen yang diproses, yang artinya tidak perlu dilakukan sorting.
    - **Perbaikan:** Fungsi tetap berjalan aman meskipun `l == r`, namun tidak ada operasi sorting yang terjadi.

### Perbaikan Akhir

- Kode telah diperbaiki dengan indeks yang benar dan lebih optimal.
- Bubble Sort kini berhenti lebih awal jika tidak ada pertukaran.
- Indeks dikonversi ke **0-based** untuk kompatibilitas dengan `vector` di C++.
- Perbaikan ini membuat kode lebih **efisien dan mudah dibaca**.
# Informasi tambahan