---
obsidianUIMode: preview
note_type: problem set
id_problem: 03PS-STRX-E001
judul_problem: Radix sort implementasi standar
sumber: chatgpt.com
kategori_problem: 🎯 exercise
kesulitan: 🥉 easy
time_complexity: ⚪O(n * d)
memory_complexity: ⚪O(n + k) ✅ → Stable
status: 🏆 solved
date_solved: 2025-04-26T13:47:00
pendekatan: radix sort
tags:
  - array
  - sorting
  - radix-sort
---
Link problem: 

#array #sorting #radix-sort 

---
# Radix sort implementasi standar
Time limit: -
Memory limit: -

Diberikan sebuah array tak terurut, non negatif. Urutkan array tersebut dengan menggunakan algoritma Radix Sort dengan urutan ascending.

### Input
- `n` berupa ukuran array.
- `arr` berupa isi atau elemen dari array.
#### Input constraints
nilai elemen array bukan negatif.
### Output
Array yang sudah diurutkan.

### Examples
Input:
```
5
5 6 3 2 1
```

Output:
```bash
1 2 3 5 6
```

### Note
\-
# Jawaban
Berikut jawaban yang sudah lumayan efektif:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSortByDigit(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0);

    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(vector<int>& arr) {
    if (arr.empty()) return;

    int maxVal = *max_element(arr.begin(), arr.end());

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortByDigit(arr, exp);
    }
}

int main() {
    int n; cin >> n;
    vector<int> data (n);
    for(int&x:data) cin >> x;

    cout << "\nSebelum sort: ";
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;

    radixSort(data);

    cout << "Setelah sort: ";
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
```

Time complexity: $O()$
Memory complexity: $O()$
## Jawaban efektif
// penjelasan singkat

```cpp

```

Time complexity: $O()$
Memory complexity: $O()$
# Editorial 

Jika harus menggunakan beberapa komentar, maka berikut komentar yang tepat untuk kode yang digunakan:

```cpp
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Counting Sort khusus untuk digit tertentu
void countingSortByDigit(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0); // Karena digit hanya 0-9

    // Hitung frekuensi berdasarkan digit (bukan nilai penuh)
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Ubah count menjadi posisi
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Susun output array berdasarkan posisi yang dihitung
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Salin hasil ke arr
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Fungsi utama Radix Sort
void radixSort(vector<int>& arr) {
    if (arr.empty()) return;

    // Cari nilai maksimum untuk tahu berapa digit
    int maxVal = *max_element(arr.begin(), arr.end());

    // Lakukan counting sort untuk setiap digit (satuan, puluhan, ratusan, dst)
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortByDigit(arr, exp);
    }
}

int main() {
    int n; cin >> n;
    vector<int> data (n);
    for(int&x:data) cin >> x;

    cout << "\nSebelum sort: ";
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;

    radixSort(data);

    cout << "Setelah sort: ";
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
```


## 1. Bagian Header dan Namespace

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
```

- `#include <iostream>` → Untuk input-output (seperti `cin`, `cout`).
    
- `#include <vector>` → Untuk menggunakan `std::vector`.
    
- `#include <algorithm>` → Untuk fungsi `max_element`.
    
- `using namespace std;` → Agar tidak perlu mengetik `std::cout`, `std::cin`, dst.
    

---

## 2. Fungsi `countingSortByDigit`

Fungsi **Counting Sort** **berdasarkan digit tertentu**.

```cpp
void countingSortByDigit(vector<int>& arr, int exp) {
```

- `arr` adalah **referensi ke vector** (supaya perubahan langsung ke array aslinya).
    
- `exp` adalah **faktor digit**:
    
    - `exp = 1` berarti satuan,
        
    - `exp = 10` berarti puluhan,
        
    - `exp = 100` berarti ratusan, dst.
        

---

### 2.1 Ukuran array, buat array output dan count

```cpp
int n = arr.size();
vector<int> output(n);
vector<int> count(10, 0);
```

- `n` adalah jumlah elemen array.
    
- `output(n)` adalah **array sementara** untuk hasil setelah sort berdasarkan digit ini.
    
- `count(10, 0)` adalah array frekuensi untuk **angka 0 sampai 9** (hanya 10 angka).
    

---

### 2.2 Menghitung frekuensi digit

```cpp
for (int i = 0; i < n; i++) {
    int digit = (arr[i] / exp) % 10;
    count[digit]++;
}
```

- Bagi elemen `arr[i]` dengan `exp`, lalu ambil `mod 10` untuk mendapatkan **angka pada posisi digit yang sedang disortir**.
    
- Lalu **count digit tersebut**.
    

Contoh:

- Jika `arr[i] = 345` dan `exp = 10`, maka:  
    `(345 / 10) % 10 = 34 % 10 = 4` → digit puluhan adalah 4.
    

---

### 2.3 Akumulasi count

```cpp
for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
}
```

- **Mengubah count** menjadi **posisi kumulatif**.
    
- Supaya kita tahu **di mana** setiap angka harus ditempatkan di array output.
    

---

### 2.4 Membentuk array output

```cpp
for (int i = n - 1; i >= 0; i--) {
    int digit = (arr[i] / exp) % 10;
    output[count[digit] - 1] = arr[i];
    count[digit]--;
}
```

- **Loop dari belakang** untuk **stabilitas sorting** (artinya elemen dengan digit sama akan tetap dalam urutan aslinya).
    
- Cari digit-nya lagi.
    
- Letakkan elemen di posisi yang benar di `output`.
    
- Kurangi `count` supaya posisi berikutnya turun satu.
    

---

### 2.5 Copy output ke array asli

```cpp
for (int i = 0; i < n; i++) {
    arr[i] = output[i];
}
```

- Salin hasil sort dari `output` ke `arr`.
    
- Sekarang `arr` sudah diurutkan berdasarkan digit `exp`.
    

---

## 3. Fungsi `radixSort`

Fungsi utama untuk menjalankan Radix Sort.

```cpp
void radixSort(vector<int>& arr) {
```

- Menerima `arr` sebagai **referensi**.
    

---

### 3.1 Cek array kosong

```cpp
if (arr.empty()) return;
```

- Jika `arr` kosong, langsung keluar dari fungsi.
    

---

### 3.2 Cari nilai maksimum

```cpp
int maxVal = *max_element(arr.begin(), arr.end());
```

- Mencari elemen maksimum dalam `arr` supaya tahu **berapa digit maksimum yang perlu diproses**.
    

---

### 3.3 Loop berdasarkan digit

```cpp
for (int exp = 1; maxVal / exp > 0; exp *= 10) {
    countingSortByDigit(arr, exp);
}
```

- Mulai dari `exp = 1` (satuan).
    
- Selama `maxVal / exp > 0`, artinya masih ada digit yang perlu diolah.
    
- Setiap iterasi `exp` dikali 10 (menuju puluhan, ratusan, ribuan...).
    

---

## 4. Fungsi `main`

Fungsi utama program, **ada modifikasi di sini** (yang kamu minta).

---

### 4.1 Membaca jumlah elemen dan isinya

```cpp
int n; cin >> n;
vector<int> data (n);
for(int& x : data) cin >> x;
```

- Membaca `n`, jumlah elemen array.
    
- Membuat vector `data` berukuran `n`.
    
- Membaca satu per satu elemen ke dalam `data`.
    

**Perubahan ini menggantikan** data yang hardcode (yang sebelumnya pakai `{170, 45, 75, ...}`) menjadi **input dari user**.

---

### 4.2 Menampilkan array sebelum sort

```cpp
cout << "\nSebelum sort: ";
for (int num : data) {
    cout << num << " ";
}
cout << endl;
```

- Menampilkan seluruh elemen sebelum sorting.
    

---

### 4.3 Memanggil `radixSort`

```cpp
radixSort(data);
```

- Mengurutkan `data` menggunakan Radix Sort.
    

---

### 4.4 Menampilkan array setelah sort

```cpp
cout << "Setelah sort: ";
for (int num : data) {
    cout << num << " ";
}
cout << endl;
```

- Menampilkan hasil setelah diurutkan.
    

---

### 4.5 Return

```cpp
return 0;
```

- Mengakhiri program.
    


# Informasi tambahan
Radix sort standar tidak bisa digunakan untuk menangani angka value negatif. Jika terdapat value negatif, lebih baik menggunakan algoritma seperti MergeSort atau Quick Sort. 

Walaupun begitu, kinerja algoritma semacam Counting sort dan Radix Sort untuk penanganan array non negatif jauh lebih cepat.

Kasus-kasus seperti deretan umur, dan jarak dari lokasi x, tidak mungkin negatif, sehingga penerapan kedua algoritma ini lebih tepat.