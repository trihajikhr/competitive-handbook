---
obsidianUIMode: preview
note_type: problem statement
id_problem: 03PS-STSWE0002
judul_problem: Sliding Window Maximum (Maximum of all subarrays of size K)
sumber: geeksforgeeks.org
kategori_problem: 🎯 exercise
kesulitan: 🥉 easy 🥈 medium
time_complexity: " 🟠 O(n)"
memory_complexity: " ⚪O(k)"
status: ⏳ progress 🏆 solved
date_solved: 2025-03-02T23:14:00
pendekatan: algoritma sliding window
tags:
  - array
  - sliding-window
  - two-pointer
---
Link problem: [Sliding Window Maximum (Maximum of all subarrays of size K) - GeeksforGeeks](https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/#expected-approach-using-deque-on-time-and-ok-space)

#array #sliding-window #two-pointer 

---
# Maximum Sliding Window (Maksimum dari semua subarray berukuran K)  
Time limit: -
Memory limit: -

Diberikan sebuah array `arr[]` yang berisi bilangan bulat dan sebuah bilangan bulat `k`, tugasmu adalah menemukan nilai maksimum untuk setiap subarray kontinu yang berukuran `k`. Outputnya harus berupa array dari nilai maksimum yang sesuai dengan masing-masing subarray kontinu.

### Input
Array `arr[]` dan `k`. Dalam implementasi asli mungkin harus memasukan deklarasi banyaknya array, dengan `n`.
### Output
Subarray berupa nilai maksimum yang sesuai dari masing-masing subarray kontinu.
### Examples
#### Contoh 1

Input:
```bash
arr[] = [1, 2, 3, 1, 4, 5, 2, 3, 6], k = 3
```

Output:
```bash
[3, 3, 4, 5, 5, 5, 6]
```

- Subarray kontinu pertama = [1, 2, 3] → maksimum = 3
- Subarray kontinu kedua = [2, 3, 1] → maksimum = 3
- Subarray kontinu ketiga = [3, 1, 4] → maksimum = 4
- Subarray kontinu keempat = [1, 4, 5] → maksimum = 5
- Subarray kontinu kelima = [4, 5, 2] → maksimum = 5
- Subarray kontinu keenam = [5, 2, 3] → maksimum = 5
- Subarray kontinu ketujuh = [2, 3, 6] → maksimum = 6

#### Contoh 2

Input:
```bash
arr[] = [5, 1, 3, 4, 2, 6], k = 1
```

Output:
```bash
[5, 1, 3, 4, 2, 6]
```

Ketika `k=1`, setiap elemen dalam array akan menjadi subarraynya sendiri, sehingga outputnya adalah array itu sendiri.

#### Contoh 3

Input:
```bash
arr[] = [1, 3, 2, 1, 7, 3], k = 3
```

Output
```bashSliding Window Maximum (Maximum of all subarrays of size K)
[3, 3, 7, 7]
```


### Note
Gunakan pendekatan yang paling optimal.
# Jawaban
Menggunakan pendekatan Nested Loops
```cpp
#include <iostream>
#include <vector>
using namespace std;

// Metode untuk menemukan nilai maksimum untuk
// setiap subarray kontinu berukuran k.
vector<int> maxOfSubarrays(vector<int>& arr, int k) {
    int n = arr.size();

    // untuk menyimpan hasil
    vector<int> res;
  
    for (int i = 0; i <= n - k; i++) {
      
        // Menemukan nilai maksimum dari subarray
        // yang dimulai dari arr[i]
        int max = arr[i];
        for (int j = 1; j < k; j++) {
            if (arr[i + j] > max)
                max = arr[i + j];
        }
        res.push_back(max);
    }
  
    return res;
}

int main() {
    vector<int> arr = { 1, 2, 3, 1, 4, 5, 2, 3, 6 };
    int k = 3;
    vector<int> res = maxOfSubarrays(arr, k);
    for (int maxVal : res) {
        cout << maxVal << " ";
    }
    return 0;
}
```
Time complexity: $O(n*k)$
Memory Complexity: $O(1)$
## Jawaban efektif
Menggunakan pendekatan yang palin optimal yang mungkin:
```cpp
#include <bits/stdc++.h>
using namespace std;

// Metode untuk menemukan nilai maksimum untuk
// setiap subarray kontinu berukuran k.
vector<int> maxOfSubarrays(vector<int>& arr, int k) {

    // untuk menyimpan hasil
    vector<int> res;
  
    // membuat deque untuk menyimpan indeks elemen maksimum
    deque<int> dq(k);

    // Proses elemen pertama sebanyak k (atau jendela pertama) dari array
    for (int i = 0; i < k; ++i) {
      
        // Untuk setiap elemen, elemen-elemen sebelumnya yang lebih kecil 
        // tidak berguna, jadi hapus dari dq
        while (!dq.empty() && arr[i] >= arr[dq.back()]) {
          
            // Hapus dari belakang
            dq.pop_back();
        }

        // Tambahkan elemen baru di belakang deque
        dq.push_back(i);
    }

    // Proses sisa elemen, yaitu dari arr[k] hingga arr[n-1]
    for (int i = k; i < arr.size(); ++i) {
      
        // Elemen di depan deque adalah elemen terbesar
        // dari jendela sebelumnya, jadi simpan nilainya
        res.push_back(arr[dq.front()]);

        // Hapus elemen-elemen yang berada di luar jendela ini
        while (!dq.empty() && dq.front() <= i - k) {
          
            // Hapus dari depan deque
            dq.pop_front();
        }

        // Hapus semua elemen yang lebih kecil dari elemen yang akan ditambahkan saat ini
        // (hapus elemen yang tidak berguna)
        while (!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        }

        // Tambahkan elemen saat ini di belakang deque
        dq.push_back(i);
    }

    // Simpan elemen maksimum dari jendela terakhir
    res.push_back(arr[dq.front()]);

    return res;
}

int main() {
    vector<int> arr = {1, 3, 2, 1, 7, 3};
    int k = 3;
    vector<int> res = maxOfSubarrays(arr, k);
    for (int maxVal : res) {
        cout << maxVal << " ";
    }
    return 0;
}
```

Time complexity: $O(n)$
Memory Complexity: $O(k)$
# Editorial 
Buat sebuah Deque, _dq_ dengan kapasitas _k_, yang hanya menyimpan elemen-elemen berguna dari window saat ini yang berisi _k_ elemen. Sebuah elemen dikatakan berguna jika elemen tersebut ada di window saat ini dan lebih besar dari semua elemen lain di sebelah kanannya dalam window tersebut. Proses semua elemen array satu per satu dan pertahankan _dq_ untuk mengandung elemen-elemen berguna dari window saat ini, di mana elemen-elemen berguna ini disimpan dalam urutan yang terurut. Elemen di bagian depan _dq_ merupakan yang terbesar, sedangkan elemen di bagian belakang merupakan yang terkecil dari window saat ini.

---

## Algoritma Langkah demi Langkah:

1. **Buat sebuah deque** untuk menyimpan hanya elemen-elemen berguna dari window saat ini.
   <br/>
2. **Jalankan sebuah loop** dan masukkan _k_ elemen pertama ke dalam deque.  
    Sebelum memasukkan suatu elemen, periksa apakah elemen di bagian belakang deque lebih kecil daripada elemen saat ini. Jika ya, hapus elemen tersebut dari bagian belakang deque hingga semua elemen yang tersisa di dalam deque lebih besar daripada elemen saat ini. Kemudian, masukkan elemen saat ini ke bagian belakang deque.
    <br/>
3. **Jalankan loop dari indeks _k_ hingga akhir array.**
    - Cetak elemen di bagian depan deque.
    - Hapus elemen dari bagian depan deque jika elemen tersebut sudah berada di luar window saat ini.
    - Masukkan elemen berikutnya ke dalam deque.  
        Sebelum memasukkan elemen tersebut, periksa apakah elemen di bagian belakang deque lebih kecil daripada elemen saat ini. Jika ya, hapus elemen dari bagian belakang deque hingga semua elemen yang tersisa lebih besar daripada elemen saat ini. Kemudian, masukkan elemen saat ini ke bagian belakang deque.
    <br/>
4. **Cetak elemen maksimum** dari window terakhir (elemen di bagian depan deque).

---

**Implementasi dari pendekatan di atas:**

- **Kompleksitas Waktu:** O(n)  
    Setiap elemen dalam array ditambahkan dan dihapus paling banyak sekali, sehingga total operasi adalah sekitar 2n.
    <br/>
- **Ruang Tambahan:** O(k)  
    Elemen yang disimpan di dalam deque membutuhkan ruang sebesar O(k).

# Informasi tambahan
Untuk bisa memahami teknik ini, pemahaman mengenai struktur data Deque sangat dibutuhkan, mungkin bisa dipelajari di materi struktur data.