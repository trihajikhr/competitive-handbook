---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 02TH-TC00-0001
nama_algoritma: Time Complexity dalam Algoritma
kategori_algoritma: 
kesulitan: 🥉 easy
time_complexity: 
memory_complexity: 
sumber: "buku: CP handbook by Antti Laaksonen"
date_learned: 2025-06-01T10:23:00
tags:
  - time-complexity
---
---
# Time Complexity dalam Algoritma

Time Complexity (Kompleksitas Waktu) mengukur seberapa cepat suatu algoritma dijalankan berdasarkan besar input. Kompleksitas ini dinyatakan dalam notasi Big-O, seperti `O(1)`, `O(n)`, `O(n^2)`, dll.

## 1 | $O(1)$ – Waktu Konstan

- **$O(1)$** artinya waktu eksekusi program **tetap**, tidak tergantung pada ukuran input.
    
- Mau input 1 atau 1 juta, jumlah langkah program tetap segitu-segitu saja.
    
- Biasanya terjadi saat:
    
    - Kita langsung **mengakses indeks array** tertentu.
        
    - Melakukan **penghitungan sederhana** (penjumlahan, pengurangan, dsb).
        
    - Menyimpan atau mengambil data dari struktur seperti **hash table** (dalam kondisi ideal).
        
### 🧪 Contoh Program: Penjumlahan Dua Bilangan

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20;
    cout << (a + b) << endl; // Output: 30
    return 0;
}
```

### ⏱ Analisis Kompleksitas

- Tidak peduli apakah nilai `a` dan `b` kecil atau besar, operasi `a + b` selalu butuh **satu langkah saja**.
    
- Inilah kenapa kita bilang ini $O(1)$.
### 🧠 Contoh Operasi / Algoritma yang Biasa O(1)

- Mengakses elemen array/vector dengan indeks (`arr[i]`)
    
- Melakukan operasi matematika sederhana (`+`, `-`, `*`, `/`)
    
- Menambahkan elemen ke akhir vector (dalam banyak kasus)
    
- Menyimpan/mengakses data di struktur seperti **unordered_map** (hash table)
    
- Memeriksa panjang array atau string (kalau disimpan, bukan dihitung)
    
- Return dari fungsi (selama tidak ada loop atau rekursi)

---
## 2 | $O(log \; n)$ – Logaritmik

- **$O(log \;n)$** berarti jumlah langkah yang diperlukan **berkembang lambat** saat ukuran input bertambah.
    
- Cocok untuk algoritma yang **membagi masalah jadi dua** setiap langkahnya.
    
- Istilah "log" di sini biasanya mengacu ke **logaritma basis 2 (log₂)**, karena komputer bekerja dengan bilangan biner.

### 🔁 Contoh Sederhana

Bayangkan kamu menebak angka antara 1 sampai 100:

- Kamu menebak angka tengah → 50
    
- Jika terlalu kecil, nebak lagi antara 51–100 → 75
    
- Lanjut terus sampai ketemu
    

Setiap langkah **membagi ruang pencarian menjadi dua**, jadi jumlah langkah tumbuh **logaritmik** terhadap ukuran total.

### 🧪 Contoh Program: Binary Search

```cpp
#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return -1; // jika tidak ditemukan
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << binarySearch(arr, n, 7) << endl; // Output: 3 (index ke-3)
    return 0;
}
```

### ⏱ Analisis Kompleksitas

- Setiap iterasi membagi jumlah elemen yang diperiksa menjadi dua.
    
- Untuk `n` elemen, hanya butuh sekitar `log₂(n)` langkah.
    
- Contoh:
    
    - 1.000 elemen → butuh sekitar 10 langkah
        
    - 1.000.000 elemen → butuh sekitar 20 langkah
        

### 🧠 Contoh Algoritma yang Memiliki $O(log \; n)$

- Binary Search (paling klasik)
    
- Insert/Delete/Search pada BST (Binary Search Tree) — jika tree seimbang
    
- Beberapa algoritma divide and conquer lainnya seperti:
    
    - Exponentiation by Squaring
        
    - Binary GCD (Greatest Common Divisor)
        

---

## 3  $O(\sqrt{n})$ – Akar Kuadrat

- Kompleksitas $O(\sqrt{n})$ muncul ketika jumlah langkah yang dibutuhkan sebanding dengan akar kuadrat dari ukuran input.
    
- Biasanya muncul di algoritma yang **mengurangi ruang pencarian secara bertahap sampai akar kuadrat dari n**.
    
- Contoh klasik adalah pengecekan **bilangan prima** dan **faktorisasi**.
    
### 🧪 Contoh Program: Mengecek Bilangan Prima

```cpp
#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n = 29;
    cout << (isPrime(n) ? "Prima" : "Bukan Prima") << endl;
    return 0;
}
```

### ⏱ Analisis Kompleksitas

- Untuk mengecek apakah `n` bilangan prima, tidak perlu periksa sampai `n-1`.
    
- Cukup periksa sampai akar kuadrat `n` karena:
    
    - Jika `n` memiliki faktor lebih dari $\sqrt{n}$, maka pasti ada pasangan faktornya yang lebih kecil dari $\sqrt{n}$.
        
- Jadi, jumlah iterasi maksimal sekitar $\sqrt{n}$, sehingga kompleksitasnya $O(\sqrt{n})$.
    

### 🧠 Contoh Algoritma yang Memiliki $O(\sqrt{n})$

- Pengecekan bilangan prima sederhana
- Faktorisasi bilangan bulat (mencari faktor-faktor bilangan)
- Algoritma tertentu yang menggunakan **blok atau segmentasi** dalam pemrosesan data

---

## 4. $O(n)$ – Linear

- O(n) berarti waktu eksekusi program **bertambah secara linear** seiring pertambahan jumlah input.
    
- Misalnya: Jika kamu punya 10 data, waktu proses butuh 10 langkah. Jika datanya jadi 100, langkahnya jadi sekitar 100 juga.
    
- Ini sering terjadi saat kamu:
    
    - Mengecek semua elemen satu per satu.
        
    - Melakukan satu loop `for` yang melewati seluruh data.
        

### 🧪 Contoh Program: Mencari Elemen dalam Array

```cpp
#include <iostream>
using namespace std;

bool findElement(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return true;
    }
    return false;
}

int main() {
    int arr[] = {4, 7, 1, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    if (findElement(arr, n, target))
        cout << "Ditemukan!" << endl;
    else
        cout << "Tidak ditemukan." << endl;

    return 0;
}
```

### ⏱ Analisis Kompleksitas

- Fungsi `findElement()` akan:
    
    - Dalam kasus terburuk, memeriksa seluruh elemen → $O(n)$ waktu.
    - Dalam kasus terbaik, bisa langsung ketemu di awal → $O(1)$.
    - Tapi notasi big-O fokus ke worst case, jadi kita bilang ini $O(n)$.

### 🧠 Contoh Algoritma / Operasi yang Biasa O(n)

- Linear Search (seperti contoh di atas)
- Menjumlahkan semua elemen dalam array
- Mencari nilai maksimum/minimum di array
- Prefix Sum (1 kali hitung awal)
- Traversal satu lapis (DFS/BFS) pada tree atau graph tanpa siklus
- Menyalin seluruh elemen dari satu array ke array lain
- Count karakter dalam string

---

## 5 | $O(n \; log \; n)$ – Linear-Logaritmik

- Kompleksitas $O(n\; log \; n)$ biasanya muncul pada algoritma yang melakukan operasi **berulang kali pada data dengan pembagian atau penggabungan secara logaritmik**.
    
- Log n berasal dari pembagian data menjadi bagian-bagian kecil secara berulang (misal: pembagian setengah).
    
- n berasal dari pengolahan atau penggabungan seluruh elemen data dalam setiap langkah pembagian.
    
- Contoh paling umum adalah **algoritma sorting efisien** seperti **Merge Sort** dan **Quick Sort**.
    

### 🧪 Contoh Program: Mengurutkan Array dengan std::sort

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n);

    for (int i : arr) cout << i << " ";
    cout << endl;
    return 0;
}
```

### ⏱ Analisis Kompleksitas

- `std::sort` di C++ umumnya menggunakan **introsort**, yang memiliki rata-rata kompleksitas $O(n\; log \; n)$.
    
- Ini berarti waktu eksekusi akan naik sedikit lebih dari linear saat data bertambah besar, tetapi jauh lebih efisien dibandingkan $O(n²)$.
    
- Log n berasal dari pembagian pengurutan (misalnya, membagi array menjadi dua bagian terus-menerus).
    
- n berasal dari penggabungan dan perbandingan elemen pada setiap level pembagian.

### 🧠 Contoh Algoritma yang Memiliki $O(n\; log \; n)$

- Merge Sort
- Quick Sort (rata-rata kasus)
- Heap Sort
- Algoritma pencarian dan manipulasi data berbasis pohon balanced (seperti AVL, Red-Black Tree)
- Beberapa algoritma pemrosesan data besar dan pengurutan eksternal

---

## 6 | $O(n²)$ – Kuadratik

- Kompleksitas $O(n²)$ berarti waktu eksekusi berbanding lurus dengan kuadrat ukuran input.
    
- Biasanya terjadi ketika ada **dua perulangan bersarang** yang masing-masing berjalan hingga n.
    
- Saat input bertambah, waktu berjalan sangat cepat naik (misal input 10 jadi 100 langkah, input 100 jadi 10.000 langkah).
    
- Contoh klasik: algoritma sorting sederhana seperti **Bubble Sort**, **Selection Sort**, dan **Insertion Sort** versi dasar.
    
### 🧪 Contoh Program: Bubble Sort

```cpp
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    for (int i : arr) cout << i << " ";
    cout << endl;
    return 0;
}
```

### ⏱ Analisis Kompleksitas

- Ada dua loop bersarang yang masing-masing berjalan hingga n.
    
- Setiap elemen dibandingkan dengan elemen-elemen lainnya dalam jumlah yang hampir sama dengan n.
    
- Ini menyebabkan total operasi sekitar n * n = n².
    
- Jadi waktu eksekusi meningkat sangat cepat saat n besar.
    

---

### 🧠 Contoh Algoritma dengan Kompleksitas $O(n²)$

- Bubble Sort
    
- Selection Sort
    
- Insertion Sort (versi sederhana)
    
- Algoritma perbandingan pasangan (pairwise comparison)
    
- Algoritma dasar untuk mencari pasangan atau kombinasi dua elemen dalam data
    

---

## 7 | $O(n³)$ – Kubik

- Kompleksitas $O(n³)$ terjadi saat ada **tiga loop bersarang**, masing-masing berjalan hingga n.
    
- Waktu eksekusi berbanding lurus dengan kubik ukuran input.
    
- Biasanya muncul di operasi yang melibatkan **tiga dimensi** atau **tiga variabel yang harus dicek bersamaan**.
    
- Contohnya adalah operasi **perkalian matriks sederhana** dan beberapa brute force dengan tiga variabel.

### 🧪 Contoh Program: Perkalian Matriks 3x3

```cpp
#include <iostream>
using namespace std;

const int N = 3;

void multiply(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {         // Loop baris matriks A
        for (int j = 0; j < N; j++) {     // Loop kolom matriks B
            C[i][j] = 0;
            for (int k = 0; k < N; k++) { // Loop elemen untuk perkalian
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void printMatrix(int M[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << M[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int A[N][N] = {{1, 2, 3},
                   {4, 5, 6},
                   {7, 8, 9}};
    int B[N][N] = {{9, 8, 7},
                   {6, 5, 4},
                   {3, 2, 1}};
    int C[N][N];

    multiply(A, B, C);

    cout << "Hasil Perkalian Matriks:\n";
    printMatrix(C);

    return 0;
}
```

### ⏱ Analisis Kompleksitas

- Tiga loop bersarang (i, j, k), masing-masing berjalan n kali.
    
- Total operasi kira-kira n * n * n = n³.
    
- Kompleksitas ini sangat lambat jika n besar (misal n=1000 → 1 milyar operasi).
    
- Untuk kasus nyata besar, algoritma yang lebih cepat (seperti Strassen) biasa digunakan.
    

### 🧠 Contoh Algoritma dengan Kompleksitas $O(n³)$

- Perkalian matriks standar
    
- Algoritma brute force untuk triple nested loops
    
- Beberapa algoritma graf dengan tripel nested loops
    

---

## 8 | $O(2ⁿ)$ – Eksponensial

- Kompleksitas ini sering muncul pada algoritma rekursif yang memecah masalah menjadi dua sub-masalah setiap langkahnya.
    
- Jumlah pemanggilan fungsi atau operasi tumbuh secara eksponensial seiring dengan bertambahnya ukuran input.
    
- Contoh klasik adalah menghitung bilangan Fibonacci secara rekursif tanpa optimasi.
    
- Sangat tidak efisien untuk input besar karena waktu eksekusinya sangat cepat membesar.
### 🧪 Contoh Program: Fibonacci Rekursif

```cpp
#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    cout << fibonacci(10) << endl; // Output: 55
    // Perhatikan, fibonacci(50) akan sangat lambat
    return 0;
}
```

### ⏱ Analisis Kompleksitas

- Fungsi fibonacci memanggil dirinya dua kali setiap kali dipanggil, sehingga jumlah panggilan tumbuh sekitar $2^n$.
    
- Untuk n besar, eksekusi jadi sangat lambat.
    
- Contohnya: fibonacci(50) akan butuh waktu sangat lama.
    

### 🧠 Algoritma Terkait

- Banyak algoritma rekursif naive
    
- Solusi brute force untuk masalah subset, kombinasi, dan permutasi tanpa pruning
    
- Algoritma backtracking tanpa optimasi
    

---

## 9 | $O(n!)$ – Faktorial

- Kompleksitas ini muncul ketika kita harus mengeksplorasi semua kemungkinan urutan dari n elemen, yaitu permutasi.
    
- Jumlah permutasi dari n elemen adalah n!, sehingga waktu yang dibutuhkan meningkat sangat drastis saat n bertambah.
    
- Contoh penerapan: menghasilkan semua permutasi dari sebuah array, problem travelling salesman secara brute force.
    

### 🧪 Contoh Program: Menghasilkan Semua Permutasi

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void permute(vector<int> &arr, int l, int r) {
    if (l == r) {
        for (int num : arr) cout << num << " ";
        cout << endl;
    } else {
        for (int i = l; i <= r; i++) {
            swap(arr[l], arr[i]);
            permute(arr, l + 1, r);
            swap(arr[l], arr[i]); // backtrack
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    permute(arr, 0, arr.size() - 1);
    return 0;
}
```

### ⏱ Analisis Kompleksitas

- Fungsi permute menghasilkan semua susunan dari elemen array.
    
- Jumlah permutasi = $n!$ (faktorial dari n).
    
- Kompleksitas ini sangat tinggi dan hanya cocok untuk n kecil.
    

### 🧠 Algoritma Terkait

- Permutasi dan kombinasi
    
- Backtracking (tanpa pruning)
    
- Problem brute force yang mengeksplorasi semua kemungkinan
    
