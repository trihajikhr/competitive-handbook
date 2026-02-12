---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 03TH-STJS-V001
nama_algoritma: Jump Search Algorithm
kategori_algoritma: search
kesulitan: 🥉 easy
time_complexity: 🟡 O(√n)
memory_complexity: 🟢 O(1)
sumber: Google.com, AI
date_learned: 2025-06-04T00:26:00
tags:
  - jump-search
  - array
  - search
---
---
# Variasi Jump Search
Seperti halnya **Linear Search** yang memiliki beberapa variasi (misalnya: sentinel linear search, recursive linear search), **Jump Search** juga bisa memiliki variasi—walaupun tidak sebanyak dan tidak sepopuler variasi pada linear atau binary search.

Berikut adalah beberapa **variasi dan pengembangan dari Jump Search** yang layak untuk dicatat:

# 1 | Variasi Standar

## 1.1 | Jump Search dengan C-style array

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int jumpSearch(int arr[], int n, int x) {
    int step = sqrt(n); // ukuran blok
    int prev = 0;

    // Lompat sampai elemen lebih besar atau akhir array
    while (arr[min(step, n) - 1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    // Linear search dalam blok
    while (arr[prev] < x) {
        prev++;
        if (prev == min(step, n))
            return -1;
    }

    // Jika elemen ditemukan
    if (arr[prev] == x)
        return prev;

    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 8, 12, 15, 18, 21, 25, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 18;

    int result = jumpSearch(arr, n, x);

    if (result != -1)
        cout << "Elemen ditemukan di indeks " << result << endl;
    else
        cout << "Elemen tidak ditemukan" << endl;

    return 0;
}
```


## 1.2 | Jump Search dengan **`std::vector`**

```cpp
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int jumpSearch(const vector<int>& arr, int x) {
    int n = arr.size();
    int step = sqrt(n);
    int prev = 0;

    while (arr[min(step, n) - 1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    while (arr[prev] < x) {
        prev++;
        if (prev == min(step, n))
            return -1;
    }

    if (arr[prev] == x)
        return prev;

    return -1;
}

int main() {
    vector<int> arr = {1, 3, 5, 8, 12, 15, 18, 21, 25, 30};
    int x = 18;

    int result = jumpSearch(arr, x);

    if (result != -1)
        cout << "Elemen ditemukan di indeks " << result << endl;
    else
        cout << "Elemen tidak ditemukan" << endl;

    return 0;
}
```

## 🔎 Catatan:

- **`sqrt(n)`** adalah ukuran lompatan optimal secara teori.
    
- Fungsi `min(step, n)` memastikan agar indeks tidak keluar dari batas array.
    
- Kedua versi ini **asumsinya array sudah terurut**.

### Untuk variasi Vector
Perhatikan baris 18 hingga 25. Kita tidak menggunakan metode linear search biasa, tapi kita menggunakan metode yang lebih efisien, dimana jika kita mengakses elemen yang lebih besar dari elemen yang kita cari, dan ternyata elemen yang kita cari tidak ada, maka perulangan akan langsung berhenti, tanpa perlu mengakses seluruh elemen didalam blok tersebut. 

Mekanisme ini membut algoritma lebih efisien. Mungkin kita bisa membuat variasi baru, berupa jumpSearch Optimized yang ditandai menggunakan pendekatan ini!

---
<br/><br/>
# 2 | Optimized Jump Search (Adaptive Block Size)

## 🧠 Konsep Dasar:

Pada Jump Search standar, ukuran blok biasanya ditetapkan sebagai:

$$\text{step size} = \sqrt{n}$$

Namun, ini tidak selalu optimal di dunia nyata.

> **Optimized Jump Search** mencoba menyesuaikan ukuran blok berdasarkan karakteristik data dan ukuran array secara dinamis agar lebih cepat dalam kasus nyata.


## 🎯 Kapan Ukuran Blok Perlu Disesuaikan?

1. **Jika data tidak terdistribusi merata.**
    
2. **Jika elemen yang dicari sering muncul di awal.**
    
3. **Jika sistem memiliki biaya tinggi untuk akses data.**
    


## 📏 Beberapa Strategi Adaptive Block Size:

| Strategi                    | Ukuran Blok           | Cocok Untuk                                         |
| --------------------------- | --------------------- | --------------------------------------------------- |
| Akar kuadrat $(\sqrt{n})$   | Default/teoritis      | Distribusi acak                                     |
| Logaritmik $(\log n)$       | Blok lebih kecil      | Data cenderung di awal (early match)                |
| Pangkat 1/3 $(\sqrt[3]{n})$ | Blok sedang           | Dataset sangat besar                                |
| Dinamis via pengujian       | Tergantung eksperimen | Jika kita tahu distribusi elemen dari data historis |

## 🧪 Implementasi C++: Adaptive Block Size

Berikut contoh kode C++ di mana ukuran blok bisa disesuaikan lewat parameter:

```cpp
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int optimizedJumpSearch(const vector<int>& arr, int x, int stepSize) {
    int n = arr.size();
    int step = stepSize;
    int prev = 0;

    while (arr[min(step, n) - 1] < x) {
        prev = step;
        step += stepSize;
        if (prev >= n)
            return -1;
    }

    for (int i = prev; i < min(step, n); ++i) {
        if (arr[i] == x)
            return i;
    }

    return -1;
}

int main() {
    vector<int> arr = {1, 3, 5, 8, 12, 15, 18, 21, 25, 30};
    int x = 18;

    int n = arr.size();
    // Ubah sesuai kebutuhan: sqrt(n), log2(n), dll
    int stepSize = sqrt(n); // atau log2(n), atau nilai eksperimen

    int result = optimizedJumpSearch(arr, x, stepSize);

    if (result != -1)
        cout << "Elemen ditemukan di indeks " << result << endl;
    else
        cout << "Elemen tidak ditemukan" << endl;

    return 0;
}
```

## 🔍 Analisis Time Complexity:

- **Worst-case:** Tetap $O(n / k + k)$ jika k = block size. Optimal saat $k = \sqrt{n}$.
    
- Bila menggunakan ukuran blok yang lebih kecil dari $\sqrt{n}$, kecepatan bisa meningkat **jika data sering ditemukan di awal.**
    

---
<br/><br/>
# 3 | Recursive Jump Search

**Recursive Jump Search** adalah versi rekursif dari algoritma **Jump Search**.

> Secara prinsip, tetap sama: lompat blok demi blok, lalu lakukan pencarian dalam blok yang mungkin berisi elemen target. Namun, kali ini menggunakan **pemanggilan fungsi secara rekursif**, bukan loop iteratif.

## 🧠 Logika Rekursif

1. Tentukan `step size`, misalnya $\sqrt{n}$.
    
2. Jika elemen di indeks `min(step, n) - 1` lebih kecil dari elemen target:
    
    - Rekursifkan pencarian dari `step` ke `step + stepSize`.
        
3. Jika sudah melewati elemen target:
    
    - Rekursifkan pencarian **linear** dalam blok sebelumnya.
        

## ⚙️ Implementasi dalam C++

```cpp
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Fungsi pencarian linear secara rekursif dalam blok
int linearSearchRecursive(const vector<int>& arr, int x, int left, int right) {
    if (left >= right) return -1;
    if (arr[left] == x) return left;
    return linearSearchRecursive(arr, x, left + 1, right);
}

// Fungsi Jump Search secara rekursif
int recursiveJumpSearch(const vector<int>& arr, int x, int stepSize, int prev = 0) {
    int n = arr.size();
    int step = min(prev + stepSize, n);

    if (arr[min(step, n) - 1] < x) {
        if (step >= n) return -1;
        return recursiveJumpSearch(arr, x, stepSize, step);
    }

    // Saat blok ditemukan, lakukan pencarian linear secara rekursif
    return linearSearchRecursive(arr, x, prev, step);
}

int main() {
    vector<int> arr = {1, 3, 5, 8, 12, 15, 18, 21, 25, 30};
    int x = 18;

    int n = arr.size();
    int stepSize = sqrt(n);

    int result = recursiveJumpSearch(arr, x, stepSize);

    if (result != -1)
        cout << "Elemen ditemukan di indeks " << result << endl;
    else
        cout << "Elemen tidak ditemukan" << endl;

    return 0;
}
```

## 📊 Kompleksitas:

- **Waktu:** Tetap $O(\sqrt{n})$
    
- **Ruang:** Tambahan $O(\sqrt{n})$ karena stack rekursif (karena maksimal ada sekitar $\sqrt{n}$ pemanggilan fungsi)
## ❗ Catatan:

- **Tidak umum dipakai di dunia nyata**, karena rekursi tidak memberi keuntungan nyata dibanding versi iteratif.
    
- Namun, ini bagus untuk dipelajari demi **memahami cara kerja recursive search** dan perbandingan performa.

---
<br/><br/>
#  4 | Hybrid Jump + Binary Search
## Konsep Dasar

**Hybrid Jump + Binary Search** adalah gabungan dua strategi:

1. **Jump Search** untuk _melokalisasi_ blok yang mungkin mengandung elemen.
    
2. **Binary Search** untuk mempercepat pencarian **di dalam blok** tersebut.
    

> Ini membuat algoritma lebih efisien daripada menggunakan linear search di dalam blok (seperti pada Jump Search standar).

## 📌 Langkah-langkah Algoritma

1. Tentukan `step size`, biasanya $\sqrt{n}$.
    
2. Lompat blok demi blok hingga menemukan blok yang mungkin berisi elemen target.
    
3. **Lakukan binary search** dalam blok tersebut.
    

## ⚙️ Implementasi C++

```cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> // untuk std::min
using namespace std;

// Binary Search dalam blok
int binarySearchInBlock(const vector<int>& arr, int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Hybrid Jump + Binary Search
int hybridJumpBinarySearch(const vector<int>& arr, int x) {
    int n = arr.size();
    int step = sqrt(n);
    int prev = 0;

    // Lompat blok
    while (arr[min(step, n) - 1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    // Binary Search dalam blok yang ditemukan
    return binarySearchInBlock(arr, prev, min(step, n) - 1, x);
}

int main() {
    vector<int> arr = {1, 3, 5, 8, 12, 15, 18, 21, 25, 30};
    int x = 18;

    int result = hybridJumpBinarySearch(arr, x);

    if (result != -1)
        cout << "Elemen ditemukan di indeks " << result << endl;
    else
        cout << "Elemen tidak ditemukan" << endl;

    return 0;
}
```

## 📈 Analisis Kompleksitas

| Aspek          | Nilai                                                                                                     |
| -------------- | --------------------------------------------------------------------------------------------------------- |
| **Waktu**      | $O(\sqrt{n} + \log(\sqrt{n}))$                                                                            |
| **Ruang**      | $O(1)$ (jika binary search iteratif)                                                                      |
| **Stabilitas** | **Tidak stabil**, karena tidak menjamin posisi elemen pertama jika duplikat (seperti binary search biasa) |

## ✅ Kelebihan

- Lebih cepat daripada jump search biasa (dalam blok besar).
    
- Kombinasi dari dua metode efisien.
    
- Tidak memerlukan modifikasi besar dari jump search standar.
    

## ⚠️ Kekurangan

- Butuh data yang sudah **terurut**.
    
- Binary search hanya bermanfaat jika blok cukup besar.
    

# 📚 Ringkasan Variasi Algoritma Jump Search

### 1. Jump Search Standar

Ini adalah bentuk dasar dari jump search. Algoritma ini melakukan lompatan blok dengan ukuran tetap (biasanya akar dari ukuran array, yaitu $\sqrt{n}$), dan setelah itu melakukan pencarian linear dalam blok tersebut. Implementasinya mudah dan efisien untuk ukuran data kecil hingga sedang. Kompleksitas waktunya adalah $O(\sqrt{n})$, dan penggunaan memori hanya $O(1)$ karena tidak ada struktur tambahan yang digunakan.

### 2. Recursive Jump Search

Versi ini bekerja dengan prinsip yang sama seperti jump search standar, tapi menggunakan pendekatan rekursif. Setelah melakukan lompatan, pencarian dalam blok juga dilakukan secara rekursif. Meski hasilnya sama, pendekatan ini lebih bersifat konseptual dan elegan. Namun, karena menggunakan fungsi rekursif, versi ini bisa memakan lebih banyak memori (stack) dan menjadi kurang efisien jika digunakan pada data yang sangat besar.

### 3. Optimized Jump Search (Adaptive Block Size)

Versi ini mencoba meningkatkan performa dengan menyesuaikan ukuran langkah lompatan (step size) secara dinamis, bukan sekadar $\sqrt{n}$. Ukuran blok dapat disesuaikan berdasarkan eksperimen, arsitektur mesin (misalnya ukuran cache), atau pola distribusi data. Pendekatan ini lebih fleksibel dan bisa lebih optimal daripada versi standar, tetapi membutuhkan tuning dan pengujian untuk mendapatkan performa terbaik.

### 4. Hybrid Jump + Binary Search

Versi hibrida ini menggabungkan dua metode: setelah menemukan blok yang mungkin berisi elemen yang dicari melalui lompatan, pencarian di dalam blok tidak dilakukan dengan linear search, melainkan dengan **binary search**. Hal ini membuat algoritma lebih cepat terutama untuk blok besar atau data dalam skala besar. Pendekatan ini tetap memiliki kompleksitas $O(n)$, tetapi performanya nyata lebih baik di banyak kasus praktis. Sangat cocok digunakan untuk array besar yang sudah **terurut**.

---

## 🎯 Kesimpulan

- Gunakan **Jump Search Standar** jika kamu butuh algoritma simpel dan cepat untuk data sedang.
    
- Gunakan **Hybrid Jump + Binary Search** jika kamu menginginkan kecepatan maksimal pada data besar.
    
- Gunakan **Recursive Jump Search** untuk eksplorasi akademis atau jika kamu nyaman dengan pendekatan rekursif.
    
- Gunakan **Optimized Jump Search** bila kamu siap mengutak-atik parameter step size agar sesuai dengan kasus spesifikmu.
    

Setiap variasi punya tempat dan kegunaannya masing-masing, dan memahami perbedaannya akan membantumu memilih solusi terbaik sesuai konteks soal atau aplikasi yang kamu hadapi.
