---
obsidianUIMode: preview
note_type: book theory
judul_materi: Generating Permutations
sumber:
  - geeksforgeeks.org
  - gemini.google.com
date_learned: 2026-02-13T03:06:00
tags:
  - complete-search
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Generating Permutations

Membangkitkan permutasi (_generating permutation_) merupakan salah satu persoalan mendasar dalam bidang kombinatorial dan ilmu komputer. Permutasi sendiri didefinisikan sebagai pengaturan ulang seluruh atau sebagian elemen dari suatu himpunan ke dalam urutan yang berbeda-beda. Dalam konteks pemrograman, kemampuan kita untuk menghasilkan seluruh kemungkinan susunan ini menjadi fondasi penting dalam memecahkan berbagai masalah optimasi, pencarian solusi dalam ruang sampel yang luas, hingga pengujian fungsionalitas algoritma tertentu.

Secara matematis, jika kita memiliki $n$ elemen yang unik, maka total permutasi yang dapat kita hasilkan adalah sebanyak $n!$ (n faktorial). Mengingat pertumbuhan nilai faktorial yang sangat eksplosif, efisiensi algoritma yang kita pilih akan sangat menentukan keberhasilan eksekusi program.

Dalam modul ini, kita akan mengeksplorasi berbagai metodologi untuk menghasilkan permutasi secara sistematis. Kita akan memulai dari pendekatan klasik seperti _Backtracking_ dan _Depth-First Search_ (DFS), hingga mempelajari algoritma yang lebih spesifik seperti Algoritma Heap untuk efisiensi maksimal, serta teknik _Bitmask_ untuk kebutuhan optimasi yang lebih kompleks. Dengan memahami karakteristik unik dari setiap algoritma, kita akan mampu menentukan strategi yang paling tepat sesuai dengan batasan waktu dan memori dari persoalan yang sedang kita hadapi.

<br/>

---
## 1. Backtracking / DFS

Algoritma ini menggunakan pendekatan *Depth-First Search* (DFS) untuk mengeksplorasi semua kemungkinan susunan elemen. Ide utamanya adalah membangun permutasi langkah demi langkah: memilih satu elemen, menandainya sebagai "terpakai", lalu lanjut mencari elemen berikutnya secara rekursif hingga semua posisi terisi.

Contoh kasus:

**Input:**

```
3
1 2 3
```

**Output:**

```
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 1 2 
3 2 1 
```

### 1.1. Cara Kerja Algoritma

Algoritma ini bekerja dengan menelusuri pohon keputusan (*decision tree*). Pada setiap level rekursi, kita mencoba menempatkan setiap elemen yang belum digunakan ke posisi saat ini.

Langkah-langkah backtracking:

1. **Pilih**: Ambil satu elemen yang belum digunakan dalam jalur saat ini.
2. **Eksplorasi**: Masuk ke rekursi berikutnya untuk menentukan elemen di posisi selanjutnya.
3. **Backtrack**: Setelah selesai mengeksplorasi satu cabang, tandai elemen tadi sebagai "belum digunakan" lagi, sehingga bisa digunakan untuk kombinasi di cabang lain.

Teknik yang paling umum digunakan dalam implementasi adalah menggunakan array **boolean `used[]`** untuk melacak elemen yang sedang berada dalam susunan.

### 1.2. Implementasi dalam C++

Berikut adalah implementasi menggunakan array `used` untuk menandai elemen yang sudah diambil:

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Fungsi untuk mencetak hasil permutasi
void printPermutation(const vector<int>& res) {
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;
}

/**
 * Fungsi rekursif Backtracking/DFS
 * nums: array sumber elemen
 * used: array penanda elemen mana yang sudah dipakai
 * current: menyimpan susunan angka saat ini
 */
void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current) {
    // Jika ukuran susunan saat ini sudah sama dengan sumber, cetak hasil
    if (current.size() == nums.size()) {
        printPermutation(current);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        // Jika elemen ke-i sudah digunakan, lewati
        if (used[i]) continue;

        // 1. Pilih elemen
        used[i] = true;
        current.push_back(nums[i]);

        // 2. Eksplorasi (DFS)
        backtrack(nums, used, current);

        // 3. Backtrack (Tarik kembali status)
        current.pop_back();
        used[i] = false;
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<bool> used(nums.size(), false);
    vector<int> current;

    backtrack(nums, used, current);
    return 0;
}
```

### 1.3. Analisis Kompleksitas

- **Kompleksitas Waktu:** $O(n \cdot n!)$. 
	- Karena terdapat $n!$ kemungkinan permutasi. Pada setiap pemanggilan fungsi hingga mencapai _base case_, kita melakukan _looping_ sebanyak $n$ kali untuk mencari elemen yang tersedia.

- **Kompleksitas Memori:** $O(n)$. 
	- Karena dibutuhkan memori tambahan untuk menyimpan _recursion stack_ sedalam $n$ level, serta array `used` dan `current` yang masing-masing berukuran $n$.

> [!INFO]
> Berbeda dengan Algoritma Heap yang urutannya agak acak, metode Backtracking/DFS ini menghasilkan permutasi dalam urutan **leksikografis** (urut kamus) jika array inputnya sudah terurut di awal.

<br/>

---
## 2. Next Permutation Manual

Algoritma ini digunakan untuk menghasilkan variasi urutan berikutnya yang secara nilai lebih besar dari urutan saat ini. Jika urutan saat ini adalah yang terbesar (misal: `3 2 1`), maka algoritma akan memutar kembali ke urutan terkecil (`1 2 3`).

Contoh kasus:

**Input:**

```
3
1 2 3
```

**Output:**

```
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
```
### 2.1. Cara Kerja Algoritma

Untuk mencari permutasi selanjutnya secara manual, kita menggunakan langkah-langkah berikut:

1. **Cari Pivot**: Telusuri dari kanan ke kiri untuk menemukan elemen pertama yang lebih kecil dari elemen di sebelah kanannya. Sebut indeks ini sebagai `i`. (Jika tidak ketemu, berarti ini permutasi terakhir, tinggal balik/reverse seluruh array).
    
2. **Cari Pengganti**: Telusuri lagi dari kanan ke kiri untuk menemukan elemen pertama yang lebih besar dari elemen di indeks `i`. Sebut indeks ini sebagai `j`.
    
3. **Tukar (Swap)**: Tukar posisi elemen di indeks `i` dengan elemen di indeks `j`.
    
4. **Balik (Reverse)**: Balikkan urutan elemen-elemen yang berada di sebelah kanan indeks `i` untuk mendapatkan urutan terkecil yang mungkin di bagian tersebut.

### 2.2. Implementasi dalam C++

Berikut adalah implementasi manual algoritma `next_permutation` agar kita paham logikanya, sebelum menggunakan fungsi bawaan C++.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Fungsi mencetak vector
void printVector(const vector<int>& a) {
    for (int x : a) cout << x << " ";
    cout << endl;
}

// Fungsi manual Next Permutation
bool myNextPermutation(vector<int>& a) {
    int n = a.size();
    if (n <= 1) return false;

    int i = n - 2;
    // 1. Cari pivot
    while (i >= 0 && a[i] >= a[i + 1]) i--;

    if (i >= 0) {
        // 2. Cari elemen pengganti yang lebih besar dari pivot
        int j = n - 1;
        while (a[j] <= a[i]) j--;
        // 3. Tukar
        swap(a[i], a[j]);
    } else {
        // Jika i < 0, berarti array 
        // sudah terurut menurun (permutasi terakhir)
        reverse(a.begin(), a.end());
        return false;
    }

    // 4. Balikkan bagian setelah pivot
    reverse(a.begin() + i + 1, a.end());
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // Urutkan dulu agar mulai dari permutasi terkecil (leksikografis)
    sort(a.begin(), a.end());

    do {
        printVector(a);
    } while (myNextPermutation(a)); // Menggunakan fungsi buatan sendiri

    return 0;
}
```

### 2.3. Analisis Kompleksitas

- **Kompleksitas Waktu:** $O(n \cdot n!)$.
	- Karena untuk menghasilkan _satu_ permutasi selanjutnya, dibutuhkan waktu $O(n)$ (karena kita melakukan scan dan reverse). Karena total ada $n!$ permutasi, maka total waktu untuk mencetak semua adalah $O(n \cdot n!)$.

- **Kompleksitas Memori:** $O(1)$. 
	- Berbeda dengan metode rekursif/DFS, algoritma ini bersifat **iteratif**. Kita tidak butuh _recursion stack_, hanya butuh beberapa variabel bantuan untuk indeks. Inilah keunggulan utama `next_permutation`.

> [!INFO]
> Di dunia nyata atau kompetisi, kita cukup menggunakan `std::next_permutation(a.begin(), a.end())` dari header `<algorithm>`. Fungsinya identik dengan logika di atas, namun sudah dioptimasi oleh compiler.

<br/>

---
## 3. Next Permutation STL

C++ menyediakan fungsi bawaan dalam library `<algorithm>` untuk menghasilkan permutasi selanjutnya secara leksikografis. Fungsi ini mengembalikan nilai `true` jika permutasi selanjutnya berhasil dibuat, dan `false` jika urutan sudah mencapai permutasi terbesar (kembali ke urutan terkecil). 

Untuk bisa menggunakan fungsi ini, pastikan array atau data yang diberikan sudah dalam kondisi terurut (*sorted*).

Contoh kasus:

**Input:**

```
3
1 2 3
```

**Output:**

```
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
```

### 3.1. Cara Kerja Algoritma

Fungsi `std::next_permutation(start_iterator, end_iterator)` akan mengubah urutan elemen di dalam container secara langsung (_in-place_).

### 3.2. Implementasi dalam C++

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // Library wajib untuk next_permutation
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // WAJIB: Sort agar permutasi dimulai dari urutan terkecil!
    sort(a.begin(), a.end());

    // Do-while digunakan agar permutasi 
    // pertama (hasil sort) tetap tercetak
    do {
        for (int x : a) {
            cout << x << " ";
        }
        cout << "\n";
    } while (next_permutation(a.begin(), a.end()));

    return 0;
}
```

### 3.3. Analisis Kompleksitas

- **Kompleksitas Waktu:** $O(n \cdot n!)$.
    
    - Setiap pemanggilan `next_permutation` rata-rata adalah $O(1)$ secara amortisasi, namun dalam kasus terburuk adalah $O(n)$.
    - Karena kita memanggilnya sebanyak $n!$ kali, totalnya menjadi $O(n \cdot n!)$.
        
- **Kompleksitas Memori:** $O(1)$.
    
    - Karena ini algoritma iteratif, tidak ada tumpukan rekursi (_recursion stack_). Memori yang digunakan konstan, hanya untuk beberapa variabel penunjuk internal.


> [!INFO]
> - **Kenapa menggunakan `do-while`?** Karena jika menggunakan `while` biasa, urutan pertama hasil `sort` akan langsung diproses oleh fungsi dan mungkin terlewat atau tidak tercetak dengan benar sebelum dicek.
> - **Urutan custom:** Jika ingin permutasi dibentuk dari besar ke kecil, kita bisa menggunakan `std::prev_permutation` dengan kondisi awal data di-`sort` secara descending menggunakan `greater<int>()`.

<br/>

---
## 4. Heap’s Algorithm

**Algoritma Heap** digunakan untuk menghasilkan semua kemungkinan permutasi dari $n$ buah objek. Ide utamanya adalah menghasilkan setiap permutasi dari permutasi sebelumnya dengan cara memilih sepasang elemen untuk ditukar, tanpa mengganggu $n-2$ elemen lainnya.

Contoh kasus:

- **Input:**

```
3
1 2 3
```
- **Output:**

```
1 2 3
2 1 3
3 1 2
1 3 2
2 3 1
3 2 1
```

### 4.1. Cara Kerja Algoritma

1. Algoritma ini menghasilkan $(n-1)!$ permutasi dari $n-1$ elemen pertama, lalu menyandingkan elemen terakhir ke setiap permutasi tersebut. Ini akan menghasilkan semua permutasi yang diakhiri oleh elemen terakhir tersebut.
    
2. Aturan penukaran (*swap*):
    - Jika $n$ ganjil, tukar elemen pertama dan elemen terakhir.
    - Jika $n$ genap, tukar elemen ke-$i$ (di mana $i$ adalah indeks iterasi dari $0$) dan elemen terakhir.

3. Ulangi langkah di atas sampai semua elemen diproses. Dalam setiap iterasi, algoritma akan menghasilkan semua permutasi yang berakhir dengan elemen terakhir yang sedang aktif saat itu.

### 4.2. Implementasi dalam C++

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Fungsi untuk mencetak isi vector
void printVector(const vector<int>& a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

/*
 * Menghasilkan permutasi menggunakan Algoritma Heap
 * a    : Vector yang akan di-permutasi (dikirim secara reference)
 * size : Ukuran sub-vector yang sedang diproses
 */
void heapPermutation(vector<int>& a, int size) {
    // Base Case: Jika size menjadi 1, cetak permutasi yang didapat
    if (size == 1) {
        printVector(a);
        return;
    }

    for (int i = 0; i < size; i++) {
        heapPermutation(a, size - 1);

        // Aturan penukaran (swap)
        if (size % 2 == 1) {
            // Jika size ganjil, tukar elemen pertama 
            // dengan elemen terakhir
            swap(a[0], a[size - 1]);
        } else {
            // Jika size genap, tukar elemen ke-i 
            // dengan elemen terakhir
            swap(a[i], a[size - 1]);
        }
    }
}

int main() {
    int n;
    cin >> n;

    // Inisialisasi vector dengan ukuran n
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    heapPermutation(a, n);
    return 0;
}
```
### 4.3. Analisis Kompleksitas

- **Kompleksitas Waktu:** $O(N \times N!)$. 
	- $N$ adalah ukuran array. Ini karena ada $N!$ permutasi dan setiap permutasi membutuhkan waktu $O(N)$ untuk dicetak.

- **Kompleksitas Memori:** $O(N)$.
	- Digunakan untuk tumpukan rekursi (_recursive stack space_) sebesar $N$.

> [!INFO]
> Algoritma ini sangat populer di kompetisi karena dianggap sebagai salah satu yang paling efisien dalam hal jumlah penukaran (_swaps_) antar elemen.

<br/>

---
## 5. Bitmask

Selain menggunakan array `used[]` pada DFS standar, kita dapat mengoptimalkan representasi status elemen menggunakan teknik **Bitmask**. Teknik ini sangat efisien karena kita memanfaatkan operasi tingkat bit untuk mengelola status kunjungan elemen dalam satu variabel integer tunggal.

Contoh kasus:

**Input:**

```
3
10 20 30
```

**Output:**

```
10 20 30 
10 30 20 
20 10 30 
20 30 10 
30 10 20 
30 20 10 
```

### 5.1. Cara Kerja Algoritma

Dalam algoritma ini, kita merepresentasikan kumpulan elemen yang sudah terpilih menggunakan angka biner. Setiap posisi bit (0 atau 1) dalam sebuah integer menandakan apakah elemen pada indeks tertentu sudah digunakan atau belum.

Operasi bitwise yang kita gunakan:

1. **Pemeriksaan Status (Check)**: Kita menggunakan operasi `mask & (1 << i)`. Jika hasilnya adalah $0$, berarti elemen pada indeks ke-$i$ belum masuk ke dalam susunan kita.
    
2. **Penandaan Status (Set)**: Kita menggunakan operasi `mask | (1 << i)` untuk menghasilkan _mask_ baru yang menandakan bahwa elemen ke-$i$ kini sudah digunakan.

Dengan metode ini, kita tidak lagi memerlukan array boolean tambahan. Selain lebih hemat memori, operasi bitwise diproses jauh lebih cepat oleh prosesor dibandingkan manipulasi array.
### 5.2. Implementasi dalam C++

Berikut adalah implementasi lengkap menggunakan `std::vector` dan teknik penandaan bitmask:

```cpp
#include <iostream>
#include <vector>
using namespace std;

/**
 * Fungsi pembantu untuk mencetak isi vector
 */
void cetakPermutasi(const vector<int>& susunan) {
    for (int i = 0; i < susunan.size(); i++) {
        cout << susunan[i] << " ";
    }
    cout << "\n";
}

/**
 * Fungsi rekursif Backtracking dengan Bitmask
 * @param n       : Jumlah total elemen
 * @param mask    : Variabel integer sebagai penanda status elemen
 * @param susunan : Wadah untuk menyimpan permutasi saat ini
 * @param data    : Vector sumber yang berisi elemen asli
 */
void hasilkanPermutasi(int n, int mask, vector<int>& susunan, const vector<int>& data) {
    // Jika ukuran susunan sudah mencapai n, 
    // kita telah menemukan satu permutasi lengkap
    if (susunan.size() == n) {
        cetakPermutasi(susunan);
        return;
    }

    for (int i = 0; i < n; i++) {
        // Kita periksa apakah bit ke-i pada mask masih bernilai 0
        if (!(mask & (1 << i))) {
            
            // Langkah 1: Kita masukkan elemen ke dalam susunan
            susunan.push_back(data[i]);

            // Langkah 2: Kita lanjut ke rekursi berikutnya 
            // dengan memperbarui mask
            hasilkanPermutasi(n, mask | (1 << i), susunan, data);

            // Langkah 3: Backtrack - Kita keluarkan elemen 
            // untuk mencoba kemungkinan lain
            susunan.pop_back();
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    vector<int> susunan;
    // Kita mulai proses dari mask 0 (semua elemen belum terpilih)
    hasilkanPermutasi(n, 0, susunan, data);

    return 0;
}
```

### 5.3. Analisis Kompleksitas

- **Kompleksitas Waktu:** $O(n \cdot n!)$.
	- Sama seperti algoritma permutasi lainnya, kita membangkitkan $n!$ kemungkinan. Di setiap level, kita melakukan iterasi sebanyak $n$ kali. Meskipun secara notasi Big O tetap sama, penggunaan bitmask memberikan konstanta waktu yang lebih kecil karena efisiensi di level CPU.
    
- **Kompleksitas Memory:** $O(n)$.
    - Kita memerlukan ruang untuk tumpukan rekursi (_recursion stack_) sedalam $n$ dan sebuah vector untuk menyimpan susunan sementara. Penggunaan satu variabel integer untuk _mask_ sangat menghemat penggunaan memori jika dibandingkan dengan pembuatan array boolean baru di setiap cabang rekursi.
    

> [!INFO]
> - Perlu kita perhatikan bahwa penggunaan bitmask pada tipe data `int` 32-bit membatasi kita hingga maksimal $n = 31$ elemen. Namun, dalam praktiknya, karena kompleksitas waktu bersifat faktorial ($n!$), algoritma ini biasanya hanya digunakan untuk nilai $n$ di bawah 15 hingga 20.
> - Teknik bitmask ini adalah **syarat mutlak** untuk menguasai algoritma **DP Traveling Salesman Problem (TSP)**. Di TSP, kita tidak hanya mencari permutasinya, tapi menyimpan hasil perhitungan di dalam `dp[mask][last_element]` agar tidak dihitung berulang kali.

<br/>

---
## 6. Steinhaus–Johnson–Trotter Algorithm

**Algoritma Steinhaus–Johnson–Trotter** adalah metode untuk membangkitkan semua permutasi dari $n$ elemen di mana setiap permutasi berbeda dari permutasi sebelumnya hanya pada posisi dua elemen yang bertetangga. Karakteristik ini membuat SJT sangat efisien untuk aplikasi yang membutuhkan perubahan minimal antar status.

Contoh kasus:

**Input:**

```
3
1 2 3
```

**Output:**

```
1 2 3 
1 3 2 
3 1 2 
3 2 1 
2 3 1 
2 1 3 
```

### 6.1. Cara Kerja Algoritma

Dalam algoritma ini, setiap elemen diberikan atribut tambahan berupa **arah** (ke kiri atau ke kanan). Sebuah elemen dikatakan "mobile" jika arahnya menunjuk ke elemen tetangga yang nilainya lebih kecil darinya.

Langkah-langkah utama:

1. Inisialisasi permutasi pertama (biasanya urutan naik) dan beri arah ke kiri untuk semua elemen.
    
2. Cari elemen **mobile terbesar** dalam permutasi saat ini.
    
3. Tukar elemen mobile terbesar tersebut dengan tetangga sesuai arah panahnya.
    
4. Ubah arah semua elemen yang nilainya **lebih besar** dari elemen mobile tersebut (balikkan arahnya).
    
5. Ulangi langkah di atas hingga tidak ada lagi elemen yang mobile.

### 6.2. Implementasi dalam C++

Kita akan mengimplementasikan algoritma ini secara iteratif menggunakan dua vector tambahan untuk menyimpan arah elemen.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Konstanta arah
const bool KIRI = false;
const bool KANAN = true;

void cetakPermutasi(const vector<int>& a) {
    for (int x : a) cout << x << " ";
    cout << endl;
}

// Fungsi untuk mencari indeks elemen mobile terbesar
int cariMobileTerbesar(int n, const vector<int>& a, const vector<bool>& arah) {
    int mobile_terbesar = -1;
    int indeks = -1;

    for (int i = 0; i < n; i++) {
        // Cek arah kiri
        if (arah[i] == KIRI && i > 0) {
            if (a[i] > a[i - 1] && a[i] > mobile_terbesar) {
                mobile_terbesar = a[i];
                indeks = i;
            }
        }
        // Cek arah kanan
        if (arah[i] == KANAN && i < n - 1) {
            if (a[i] > a[i + 1] && a[i] > mobile_terbesar) {
                mobile_terbesar = a[i];
                indeks = i;
            }
        }
    }
    return indeks;
}

void sjtPermutation(int n) {
    vector<int> a(n);
    vector<bool> arah(n, KIRI); // Semua arah awal ke kiri

    for (int i = 0; i < n; i++) a[i] = i + 1;

    cetakPermutasi(a);

    int posisi_mobile = cariMobileTerbesar(n, a, arah);
    while (posisi_mobile != -1) {
        int nilai_mobile = a[posisi_mobile];
        
        // Tukar dengan tetangganya sesuai arah
        if (arah[posisi_mobile] == KIRI) {
            swap(a[posisi_mobile], a[posisi_mobile - 1]);
            swap(arah[posisi_mobile], arah[posisi_mobile - 1]);
        } else {
            swap(a[posisi_mobile], a[posisi_mobile + 1]);
            swap(arah[posisi_mobile], arah[posisi_mobile + 1]);
        }

        cetakPermutasi(a);

        // Ubah arah semua elemen 
        // yang nilainya > nilai_mobile yang tadi digeser
        for (int i = 0; i < n; i++) {
            if (a[i] > nilai_mobile) {
                arah[i] = !arah[i];
            }
        }

        posisi_mobile = cariMobileTerbesar(n, a, arah);
    }
}

int main() {
    int n;
    cin >> n;
    
    sjtPermutation(n);
    
    return 0;
}
```

### 6.3. Analisis Kompleksitas

- **Kompleksitas Waktu:** $O(n \cdot n!)$.
    - Sama seperti algoritma permutasi lainnya, kita menghasilkan $n!$ permutasi. Untuk setiap permutasi, kita melakukan pencarian elemen mobile dan pembaruan arah yang memakan waktu $O(n)$.
    
- **Kompleksitas Memori:** $O(n)$.
    - Kita menggunakan dua vector tambahan (untuk nilai dan arah) yang masing-masing berukuran $n$. Karena bersifat iteratif, kita tidak menggunakan tumpukan rekursi (_stack_) yang besar.
    

> [!INFO]
> Algoritma SJT sangat berguna dalam skenario di mana biaya untuk mengubah urutan sangat mahal, karena kita menjamin hanya satu pasang elemen bertetangga yang berpindah di setiap langkah. Hal ini juga sering digunakan dalam pembentukan kode Gray (_Gray Codes_) untuk permutasi.

<br/>

---
## 7. Random Shuffle (Fisher-Yates / Knuth Shuffle)

Algoritma Fisher-Yates bekerja dengan cara mengambil elemen dari array satu per satu secara acak dan menempatkannya di posisi baru. Dalam implementasi modern, kita melakukannya secara _in-place_ (langsung di dalam array tersebut) untuk menghemat memori.

Berbeda dengan algoritma sebelumnya yang bertujuan menghasilkan _seluruh_ kemungkinan permutasi secara sistematis, algoritma ini bertujuan untuk menghasilkan _satu_ susunan acak di mana setiap kemungkinan permutasi memiliki peluang yang sama untuk terpilih (**uniform distribution**).

Contoh kasus:

**Input:**

```
3
1 2 3
```

**Output (salah satu kemungkinan):**

```
2 3 1
```

### 7.1. Cara Kerja Algoritma

Ide dasarnya adalah memisahkan array menjadi dua bagian: bagian yang belum dikocok (di sisi kiri) dan bagian yang sudah dikocok (di sisi kanan).

Langkah-langkah utama:

1. Kita mulai dari elemen terakhir (indeks $n-1$) dan berjalan mundur hingga indeks $1$.
2. Untuk setiap posisi $i$, kita pilih sebuah indeks acak $j$ sedemikian rupa sehingga $0 \leq j \leq i$.
3. Kita tukar elemen pada posisi $i$ dengan elemen pada posisi $j$.
4. Karena elemen yang sudah ditukar ke posisi $i$ tidak akan disentuh lagi dalam iterasi berikutnya, kita menjamin setiap elemen memiliki kesempatan yang adil untuk menempati posisi mana pun.

### 7.2. Implementasi dalam C++

Dalam C++, kita bisa menggunakan generator angka acak dari library `<random>` untuk hasil yang lebih berkualitas dibandingkan fungsi `rand()` tradisional.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;

/**
 * Fungsi pembantu untuk mencetak isi vector
 */
void cetakVector(const vector<int>& a) {
    for (int x : a) cout << x << " ";
    cout << endl;
}

/**
 * Implementasi manual Fisher-Yates Shuffle
 */
void kocokAcak(vector<int>& a) {
    int n = a.size();
    
    // Inisialisasi generator angka acak dengan seed waktu saat ini
    static mt19937 rng(time(0));

    for (int i = n - 1; i > 0; i--) {
        // Pilih indeks acak j antara 0 sampai i secara inklusif
        uniform_int_distribution<int> dist(0, i);
        int j = dist(rng);

        // Tukar elemen di posisi i dengan posisi acak j
        swap(a[i], a[j]);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << "\nHasil sebelum dikocok: ";
    cetakVector(a);
    kocokAcak(a);
    cout << "Hasil setelah dikocok: ";
    cetakVector(a);

    return 0;
}
```

### 7.3. Analisis Kompleksitas

- **Kompleksitas Waktu:** $O(n)$.
    - Kita hanya perlu melakukan satu kali iterasi melalui array (dari belakang ke depan). Di setiap langkah, operasi penukaran dan pembangkitan angka acak memakan waktu konstan $O(1)$.
    
- **Ruang Tambahan:** $O(1)$.
    - Algoritma ini bersifat _in-place_, artinya kita tidak membutuhkan struktur data tambahan yang ukurannya bergantung pada $n$. Kita hanya memerlukan beberapa variabel integer sederhana.


> [!INFO]
> Dalam pengembangan perangkat lunak menggunakan C++ STL, kita sebenarnya tidak perlu menulis fungsi ini secara manual. Kita bisa menggunakan fungsi bawaan `std::shuffle(a.begin(), a.end(), rng)`. Algoritma ini sangat krusial dalam berbagai bidang, mulai dari pengacakan kartu dalam game hingga teknik _stochastic_ dalam algoritma pembelajaran mesin.

<br/>

---
## 8. Panduan Pemilihan Algoritma Permutasi

Setelah kita mempelajari berbagai metode untuk menghasilkan permutasi, tantangan selanjutnya adalah menentukan algoritma mana yang paling optimal untuk kasus yang sedang kita hadapi. Berikut adalah daftar kondisi spesifik dan rekomendasi algoritma yang harus kita gunakan:

### 8.1. Berdasarkan Kebutuhan Urutan (Leksikografis)

- **Kondisi**: Kita membutuhkan hasil permutasi yang terurut rapi seperti urutan kamus (misalnya: `123, 132, 213, ...`).
    
- **Rekomendasi**: **`std::next_permutation` (STL)** atau **DFS Standar**.
    
- **Alasan**: Algoritma ini dirancang untuk mencari elemen terkecil berikutnya yang lebih besar dari status saat ini. Jika kita memulai dari array yang sudah terurut (`sort`), kita akan mendapatkan seluruh kemungkinan secara sistematis.
    

### 8.2. Berdasarkan Kecepatan Eksekusi Murni

- **Kondisi**: Kita hanya perlu memproses seluruh permutasi secepat mungkin dan tidak peduli dengan urutan hasilnya.
    
- **Rekomendasi**: **Algoritma Heap**.
    
- **Alasan**: Algoritma ini meminimalkan jumlah operasi penukaran (_swap_). Dalam setiap langkahnya, Heap hanya melakukan satu kali _swap_, menjadikannya algoritma tercepat secara konstanta waktu dibandingkan metode lainnya.
    

### 8.3. Berdasarkan Kebutuhan Pemangkasan (Pruning)

- **Kondisi**: Kita ingin menyelesaikan masalah pencarian solusi yang memiliki batasan (_constraint_), seperti masalah _N-Queens_ atau _Sudoku_.
    
- **Rekomendasi**: **Backtracking (DFS)**.
    
- **Alasan**: Dengan DFS, kita bisa berhenti di tengah jalan jika sebuah susunan parsial sudah dipastikan tidak akan menghasilkan solusi. Kita bisa langsung kembali (_backtrack_) tanpa harus menyelesaikan seluruh permutasi, yang mana hal ini mustahil dilakukan oleh algoritma iteratif seperti `next_permutation`.
    

### 8.4. Berdasarkan Penggunaan Memori (Space Efficiency)

- **Kondisi**: Kita bekerja di lingkungan dengan memori terbatas atau ingin menghindari risiko _Stack Overflow_ pada nilai $n$ yang cukup besar.
    
- **Rekomendasi**: **`std::next_permutation`** atau **SJT Algorithm**.
    
- **Alasan**: Keduanya bersifat iteratif. Mereka bekerja langsung pada array asli (_in-place_) dengan kompleksitas ruang $O(1)$, berbeda dengan DFS yang membutuhkan tumpukan rekursi (_recursive stack_) sebesar $O(n)$.
    

### 8.5. Berdasarkan Integrasi dengan Dynamic Programming (DP)

- **Kondisi**: Kita menghadapi masalah optimasi seperti _Traveling Salesman Problem_ (TSP), di mana kita perlu menyimpan hasil perhitungan untuk "status" tertentu agar tidak dihitung ulang.
    
- **Rekomendasi**: **Permutasi dengan Bitmask**.
    
- **Alasan**: Bitmask memungkinkan kita merangkum status kunjungan elemen ke dalam satu bilangan integer. Angka ini sangat ideal untuk dijadikan indeks dalam tabel DP (misal: `dp[mask][posisi]`), yang memudahkan kita melakukan _memoization_.
    

### 8.6. Berdasarkan Perubahan Minimal (Minimum Change)

- **Kondisi**: Kita ingin setiap permutasi baru hanya berbeda satu posisi (tetangga) dari permutasi sebelumnya, misalnya untuk pengujian perangkat keras atau kode Gray.
    
- **Rekomendasi**: **Steinhaus–Johnson–Trotter (SJT)**.
    
- **Alasan**: Algoritma ini menjamin properti _adjacent swap_, sehingga perubahan antar status sangat minim dan stabil.
    

### 8.7. Berdasarkan Pengambilan Sampel Acak

- **Kondisi**: Kita tidak butuh semua permutasi, melainkan hanya satu susunan acak untuk keperluan simulasi, _shuffling_ lagu, atau inisialisasi algoritma genetika.
    
- **Rekomendasi**: **Fisher-Yates Shuffle**.
    
- **Alasan**: Ini adalah satu-satunya cara yang menjamin distribusi seragam (_uniform_) dengan kompleksitas waktu sangat singkat, yaitu $O(n)$.
