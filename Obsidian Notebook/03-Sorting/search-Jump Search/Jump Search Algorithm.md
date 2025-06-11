---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 03TH-STJS-0001
nama_algoritma: Jump Search Algorithm
kategori_algoritma: search
kesulitan: 🥉 easy
time_complexity: 🟡 O(√n)
memory_complexity: 🟢 O(1)
sumber: Google.com, AI
date_learned: 2025-06-03T21:36:00
tags:
  - search
  - array
  - jump-search
---
---

# Jump Search ALgorithm
**Jump Search** (pencarian lompat) adalah algoritma pencarian pada array terurut yang berusaha mengurangi jumlah perbandingan yang diperlukan dengan “melompat” beberapa elemen sekaligus sebelum melakukan pemeriksaan linier di dalam suatu blok. Alih-alih memeriksa setiap elemen satu per satu (seperti pada linear search), Jump Search membagi keseluruhan array menjadi blok-blok berukuran sama dan melompat dari satu blok ke blok berikutnya hingga menemukan blok di mana target mungkin berada. Setelah itu, algoritma akan melakukan pencarian linier di dalam blok tersebut.

## Pengertian dan Dasar Pemikiran

1. **Kebutuhan Data Terurut**  
    Jump Search hanya bekerja pada array/list yang sudah diurutkan menaik (ascending). Tanpa urutan ini, lompatan indeks tidak dapat menjamin target masih bisa ditemukan di blok yang dipilih.
    
2. **Ukuran Lompat (Step Size)**
    
    - Misalkan panjang array = $n$.
        
    - Tentukan ukuran lompat $m = \lfloor \sqrt{n} \rfloor$.
        
    - Angka $\sqrt{n}$ dipilih karena jika kita melompat sebanyak $\sqrt{n}$ langkah dan kemudian melakukan pencarian linier di satu blok $\sqrt{n}$ besar, total langkah yang diambil menjadi kira-kira $2\sqrt{n}$, atau $O(\sqrt{n})$. Ini lebih baik daripada $O(n)$ jika $n$ sangat besar.
        
3. **Tiga Tahap Dasar Jump Search**
    
    - **Tahap 1. Lompat Perblok**  
        Mulai dari indeks $0$, periksa elemen di indeks $0,\, m,\, 2m,\, 3m,\dots$ sampai menemukan indeks ke-$k\cdot m$ di mana nilai array pada indeks itu ≥ target (atau sampai melewati batas array). Dengan kata lain, kita mencari blok pertama yang “mungkin” memuat target.
	<br/>

    - **Tahap 2. Menemukan Batas Atas Blok**  
        Setelah menemukan nilai pada indeks $(k \cdot m)$ yang ≥ target, maka blok tempat target bisa berada adalah rentang $[(k-1)\cdot m\; …\; k\cdot m]$. Jika saat melompat kita melewati indeks terakhir (misalnya $k \cdot m ≥ n$), maka blok terakhir adalah $[(k-1)\cdot m\; …\; n-1]$.
    <br/>
    
    - **Tahap 3. Pencarian Linear di Dalam Blok**  
        Lakukan pencarian linear (satu per satu) mulai dari indeks $(k-1)\cdot m$ hingga indeks $k\cdot m$ (atau sampai akhir array). Ketika ditemukan nilai yang sama dengan target, berhenti dan kembalikan indeks. Jika sudah memeriksa seluruh blok tanpa menemukan target, maka target tidak ada di array.
        

---
## Algoritma Search ALgorithm
### Penjelasan Langkah demi Langkah

Misalkan kita memiliki array terurut `arr[0..n-1]` dan ingin mencari nilai `x`. Langkah-langkah Jump Search secara detail adalah sebagai berikut:

1. **Hitung Ukuran Lompat**
    
     $$m = \lfloor \sqrt{n} \rfloor$$
    
    Gunakan fungsi floor agar $m$ menjadi bilangan bulat.
    
2. **Lompat-Melompat hingga Menemukan Batas**
    
    - Inisialisasi `prev = 0` (awal blok).
        
    - Inisialisasi `step = m`.
        
    - Sementara `arr[min(step, n) - 1] < x`:
        
        - Atur `prev = step`.
            
        - Tambah `step` dengan $m$: `step += m`.
            
        - Jika `prev ≥ n`, artinya kita telah melewati seluruh array dan elemen tidak ditemukan → kembalikan “tidak ditemukan.”
            
    
    Penjelasan:
    
    - Pada setiap lompatan, kita memeriksa elemen di indeks `step - 1` (atau `n - 1` jika `step > n`).
        
    - Jika nilai tersebut masih lebih kecil daripada `x`, berarti target belum masuk ke blok saat ini, sehingga kita lompat ke blok berikutnya.
        
    - Ketika kita mencapai blok di mana `arr[step - 1] ≥ x`, kita tahu bahwa target (jika ada) pasti berada di rentang indeks `[prev..step-1]`.
        
3. **Pencarian Linear di Dalam Blok Tersebut**
    
    - Setelah keluar dari loop lompat, lakukan pencarian linier mulai dari `i = prev` hingga `i < min(step, n)`:
        
        - Jika `arr[i] == x`, return `i`.
            
    - Jika loop linier selesai tanpa menemukannya, return “tidak ditemukan.”
        

---

### Contoh Ilustratif

Misalkan array terurut berikut dan kita ingin mencari `x = 30`:

```
arr = [2, 5, 8, 12, 16, 23, 27, 30, 34, 37, 41, 44, 48]
n = 13
m = floor(sqrt(13)) = 3
```

1. **Inisialisasi**:
    
    - `prev = 0`, `step = 3`.
        
2. **Lompat Pertama** (`step=3`):
    
    - Periksa `arr[3-1] = arr[2] = 8`. Karena `8 < 30`, berarti target belum di blok pertama.
        
    - `prev = 3`, `step = 6` (tambah `m`).
        
3. **Lompat Kedua** (`step=6`):
    
    - Periksa `arr[6-1] = arr[5] = 23`. Karena `23 < 30`, masih belum di blok kedua.
        
    - `prev = 6`, `step = 9`.
        
4. **Lompat Ketiga** (`step=9`):
    
    - Periksa `arr[9-1] = arr[8] = 34`. Karena `34 ≥ 30`, blok yang mungkin memuat `30` adalah rentang indeks `[6 .. 8]`.
        
    - Keluar dari loop lompat.
        
5. **Pencarian Linier di Blok [6..8]**:
    
    - `i = 6`: `arr[6] = 27` → tidak cocok (`27 < 30`).
        
    - `i = 7`: `arr[7] = 30` → cocok! Kembalikan indeks `7`.
        
6. **Hasil**:
    
    - Jump Search berhasil menemukan `30` di indeks 7, dengan total langkah:
        
        - 3 cek lompat: (8, 23, 34)
            
        - 1 cek linier: (27)
            
        - 1 cek linier: (30)
            
    - Total = 5 perbandingan, yang lebih sedikit daripada memeriksa semua 13 elemen satu per satu.
        

# Contoh Algoritma Jump Search
## Pseudocode Jump Search (Ringkas)

```pseudo
function jumpSearch(arr, n, x):
    m = floor(sqrt(n))
    prev = 0
    step = m

    // Lompat blok demi blok
    while arr[min(step, n) - 1] < x:
        prev = step
        step = step + m
        if prev >= n:
            return -1   // target tidak ada

    // Pencarian linier di dalam blok [prev..step-1]
    for i from prev to min(step, n)-1:
        if arr[i] == x:
            return i

    return -1   // jika sudah memeriksa seluruh blok tapi tidak ketemu
```

- Fungsi `min(step, n) - 1` memastikan kita tidak melewati batas akhir array.
    
- `prev` melacak awal blok yang sedang diperiksa secara linier setelah lompatan.
    
- Jika `prev ≥ n` sebelum loop linier, berarti kita sudah melewati akhir array tanpa menemukan blok yang memuat target.
    

---
Implementasi Algoritma Jump Search dengan C++:

```cpp
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int jumpSearch(const vector<int>& arr, int x) {
    int n = arr.size();
    int step = floor(sqrt(n));
    int prev = 0;

    // Lompat blok demi blok sampai menemukan blok yang mungkin mengandung x
    while (prev < n && arr[min(step, n) - 1] < x) {
        prev = step;
        step += floor(sqrt(n));
        if (prev >= n) {
            return -1; // x tidak ditemukan
        }
    }

    // Pencarian linier di dalam blok yang ditemukan
    for (int i = prev; i < min(step, n); i++) {
        if (arr[i] == x) {
            return i; // indeks ditemukan
        }
    }

    return -1; // x tidak ditemukan
}

int main() {
    vector<int> arr = {2, 5, 8, 12, 16, 23, 27, 30, 34, 37, 41, 44, 48};
    int x = 30;

    int index = jumpSearch(arr, x);
    if (index != -1) {
        cout << "Elemen " << x << " ditemukan pada indeks " << index << endl;
    } else {
        cout << "Elemen " << x << " tidak ditemukan dalam array" << endl;
    }

    return 0;
}
```

### Bonus versi Python
```py
import math

def jump_search(arr, x):
    n = len(arr)
    step = int(math.sqrt(n))
    prev = 0

    # Lompat blok demi blok sampai menemukan blok yang mungkin mengandung x
    while prev < n and arr[min(step, n) - 1] < x:
        prev = step
        step += int(math.sqrt(n))
        if prev >= n:
            return -1  # x tidak ditemukan

    # Pencarian linier di dalam blok yang ditemukan
    for i in range(prev, min(step, n)):
        if arr[i] == x:
            return i  # indeks ditemukan

    return -1  # x tidak ditemukan

# Contoh penggunaan
arr = [2, 5, 8, 12, 16, 23, 27, 30, 34, 37, 41, 44, 48]
x = 30

index = jump_search(arr, x)
if index != -1:
    print(f"Elemen {x} ditemukan pada indeks {index}")
else:
    print(f"Elemen {x} tidak ditemukan dalam array")
```
# Jump Search Complexity

## Time Complexity (Kompleksitas Waktu)

- **Kasus Terbaik (Best Case):**  
    Jika elemen yang dicari berada tepat di indeks pertama yang diperiksa (misalnya pada awal array), maka pencarian langsung ditemukan dengan satu kali pemeriksaan. Kompleksitas waktu di kasus terbaik adalah:
    $$O(1)$$
- **Kasus Rata-Rata dan Terburuk (Average & Worst Case):**  
    Pada umumnya, Jump Search melakukan dua tahap:
    
    1. Melakukan lompat-lompat sebanyak kira-kira $\frac{n}{m} = \frac{n}{\sqrt{n}} = \sqrt{n}$ kali (melihat setiap blok awal), dan
        
    2. Melakukan pencarian linier di dalam blok berukuran $m = \sqrt{n}$.
        
    
    Total operasi perbandingan adalah sekitar:
    
    $$O(\sqrt{n}) + O(\sqrt{n}) = O(\sqrt{n})$$

Jadi, kompleksitas waktu Jump Search secara keseluruhan adalah:

$$\boxed{O(\sqrt{n})}$$

Ini lebih efisien daripada linear search $O(n)$, tapi masih kurang efisien dibandingkan binary search $O(\log n)$.

---

## Space Complexity (Kompleksitas Memori)

- Jump Search menggunakan variabel indeks dan sedikit variabel tambahan seperti `prev` dan `step`.
    
- Tidak membutuhkan struktur data tambahan seperti array baru, tumpukan (stack), atau rekursi.
    
- Algoritma bekerja **in-place** pada array yang sudah diurutkan.
    

Sehingga, kompleksitas ruangnya adalah:

$$\boxed{O(1)}$$

---

### Ringkasan:

| Aspek                 | Kompleksitas  |
| --------------------- | ------------- |
| Waktu (Best case)     | $O(1)$        |
| Waktu (Average/Worst) | $O(\sqrt{n})$ |
| Memori (Space)        | $O(1)$        |
# Aplikasi Penggunaan Jump Search

1. **Pencarian pada Array Terurut Ukuran Sedang**  
    Jump Search cocok digunakan ketika data sudah terurut dan ukurannya cukup besar, tapi tidak sebesar yang membuat Binary Search lebih optimal. Contohnya: daftar produk, daftar nilai, atau dataset yang sudah diurutkan secara statis.
<br/>
2. **Sistem dengan Akses Memori Mahal atau Terbatas**  
    Misalnya, data tersimpan di memori eksternal (hard drive, SSD, atau media penyimpanan lain) di mana setiap akses memori memakan waktu. Dengan melompat blok yang relatif besar (ukuran $\sqrt{n}$), jumlah akses memori bisa dikurangi dibandingkan linear search.
<br/>
3. **Alternatif yang Simpel dan Mudah Diimplementasikan daripada Binary Search**  
    Bila implementasi binary search terlalu rumit atau untuk kasus yang tidak membutuhkan efisiensi maksimal, jump search bisa menjadi pilihan.
<br/>
4. **Situasi di Mana Binary Search Tidak Efisien Karena Akses Acak Mahal**  
    Pada perangkat keras tertentu atau struktur data yang lebih cocok untuk akses berurutan, jump search bisa lebih efisien dibanding binary search yang memerlukan akses acak sering.
    

---

## Kelebihan Jump Search

- **Lebih Cepat daripada Linear Search**  
    Kompleksitas waktu $O(\sqrt{n})$ membuatnya jauh lebih efisien dibanding linear search yang $O(n)$.
<br/>
- **Implementasi Relatif Sederhana**  
    Algoritma mudah dipahami dan diimplementasikan tanpa rekursi atau struktur data kompleks.
<br/>
- **Penggunaan Memori Minimal**  
    Hanya memerlukan $O(1)$ ruang tambahan, bekerja in-place.
  <br/>
- **Dapat Memanfaatkan Data Terurut**  
    Memanfaatkan sifat data yang sudah terurut untuk mengurangi langkah pencarian.
 <br/>
- **Dapat Mengurangi Jumlah Akses Memori**  
    Efektif pada sistem di mana akses memori mahal, karena lompat-lompat indeks dapat mengurangi frekuensi akses data.
    

---

## Kekurangan Jump Search

- **Hanya Bekerja pada Data Terurut**  
    Jika data belum diurutkan, harus dilakukan sorting terlebih dahulu (yang memerlukan waktu tambahan).
<br/>
- **Kurang Efisien dibanding Binary Search**  
    Kompleksitas $O(\sqrt{n})$ masih jauh lebih besar dibanding $O(\log n)$ pada binary search.
<br/>
- **Pemilihan Ukuran Lompat Sensitif**  
    Ukuran lompat ideal adalah $\sqrt{n}$, tapi dalam praktik bisa berbeda tergantung pada tipe data dan perangkat keras. Pemilihan yang kurang tepat dapat mengurangi efisiensi.
<br/>
- **Tidak Cocok untuk Data yang Sangat Besar**  
    Untuk dataset yang sangat besar, binary search atau metode lain lebih disarankan.
<br/>
- **Pencarian Linear di Dalam Blok Masih Perlu Dilakukan**  
    Setelah lompat-lompat, masih perlu melakukan pencarian linear yang bisa memakan waktu terutama jika blok besar.
    
## Kapan dan Mengapa Menggunakan Jump Search

1. **Syarat Utama: Array Terurut**  
    Data harus sudah diurutkan secara menaik. Jika belum, perlu langkah pra-proses (sorting) terlebih dahulu, yang bisa memakan waktu $O(n \log n)$. Setelah itu, Jump Search dapat dijalankan beberapa kali dengan cepat.
    
2. **Ukuran Dataset Besar tapi Akses Memori Mahal**  
    Jump Search cocok bila:
    
    - Ukuran array cukup besar sehingga Linear Search $O(n)$ dirasa terlalu lambat.
        
    - Namun, mungkin kita tidak ingin langsung menggunakan Binary Search $O(\log n)$ karena, di beberapa arsitektur atau struktur memori eksternal (misalnya penyimpanan di disk), lompat-lompatan blok $\sqrt{n}$ bisa lebih efisien—karena meminimalkan jumlah akses ke lokasi memori yang jauh (cache-friendly).
        
3. **Kompleksitas Asymptotic**
    
    - Rata-rata dan kasus terburuk Jump Search adalah $O(\sqrt{n})$, yang di antara Linear Search $O(n)$ dan Binary Search $O(\log n)$.
        
    - Jika $\sqrt{n}$ jauh lebih kecil daripada $n$, maka Jump Search bisa menjadi kompromi jika Binary Search sulit atau overhead-nya tidak sebanding (misalnya jika hanya sekali dua kali pencarian di array besar tapi tidak banyak pemanggilan ulang).
        
4. **Tidak Perlu Struktur Tambahan**  
    Sama seperti Linear Search, Jump Search tidak memerlukan memori ekstra (selain variabel `prev`, `step`, dan indeks loop). Semua operasi dilakukan “in-place” pada array yang sudah diurutkan.
    

---
## Ringkasan

- **Tujuan Utama**: Mengurangi jumlah perbandingan dengan melompat sejumlah indeks sebelum melakukan pencarian linier.
    
- **Langkah Kunci**:
    
    1. Hitung ukuran lompat $m = \sqrt{n}$.
        
    2. Lompat-lompat pada indeks $0 → m → 2m \; \cdots$ sampai menemukan blok tempat target mungkin berada.
        
    3. Setelah menemukan blok, jalankan Linear Search di dalam blok tersebut.
        
- **Keuntungan**: Lebih efisien daripada Linear Search $(O(\sqrt{n})$ vs. $O(n))$, namun tidak setinggi efisiensi Binary Search $(O(\log n))$.
    
- **Keterbatasan**:
    
    - Hanya berlaku pada array terurut.
        
    - Nilai $m = \sqrt{n}$ diambil secara heuristik; implementasi nyata mungkin memerlukan penyesuaian tergantung pada lokasi memori atau profil akses data.
        

Dengan memahami prinsip lompat-blok di atas, Jump Search dapat menjadi salah satu alternatif saat Anda memerlukan kompromi antara kesederhanaan Linear Search dan efisiensi Binary Search.