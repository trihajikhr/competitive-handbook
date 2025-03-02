---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 03TH-STSW0001
nama_algoritma: sliding window algorithm
kategori_algoritma: sorting
kesulitan: 🥉 easy 🥈 medium
time_compx: " 🟠 O(n)"
memory_compx: 🟢 O(1)
sumber: geeksforgeeks.org
date_learned: 2025-03-02T21:02:00
tags:
  - two-pointer
  - sliding-window
  - array
---

#two-pointer #sliding-window #array #string

---
# Teknik Sliding Window

Masalah **Sliding Window** melibatkan pergerakan jendela dengan ukuran tetap atau variabel melalui suatu struktur data, biasanya sebuah array atau string, untuk menyelesaikan masalah secara efisien berdasarkan subset elemen yang berkesinambungan. Teknik ini digunakan ketika kita perlu menemukan subarray atau substring sesuai dengan suatu himpunan kondisi yang diberikan.

![[Sliding Windows Algorithm-1.png]]

## Apa itu Teknik Sliding Window?

Teknik **Sliding Window** adalah metode yang digunakan untuk menyelesaikan masalah secara efisien dengan mendefinisikan sebuah jendela (window) atau rentang dalam data masukan (array atau string), kemudian menggeser jendela tersebut melintasi data untuk melakukan suatu operasi di dalamnya. Teknik ini sering digunakan dalam algoritma seperti mencari **subarray dengan jumlah tertentu**, menemukan **substring terpanjang dengan karakter unik**, atau menyelesaikan masalah yang memerlukan **jendela berukuran tetap** untuk memproses elemen secara efisien.

---

Mari kita ambil sebuah contoh untuk memahami konsep ini dengan lebih baik. Misalkan kita memiliki **array berukuran N** dan sebuah **bilangan bulat K**. Sekarang, kita perlu menghitung **jumlah maksimum dari sebuah subarray yang memiliki ukuran tepat K**. Bagaimana kita harus mendekati masalah ini?

Salah satu cara untuk melakukannya adalah dengan mengambil setiap **subarray berukuran K** dari array dan mencari jumlah maksimum dari subarray tersebut. Pendekatan ini dapat dilakukan dengan **loop bersarang (nested loops)** yang akan menghasilkan **kompleksitas waktu $O(n^2)$**.

Namun, apakah kita bisa mengoptimalkan pendekatan ini?

Jawabannya adalah **ya**. Alih-alih mengambil setiap **subarray berukuran K** dan menghitung jumlahnya satu per satu, kita cukup mengambil satu **subarray berukuran K** dari indeks **0 hingga K-1**, menghitung jumlahnya, lalu menggeser rentang tersebut satu per satu seiring dengan iterasi, serta memperbarui hasilnya. Pada iterasi berikutnya, kita **menaikkan pointer kiri dan kanan**, lalu memperbarui jumlah sebelumnya seperti yang ditunjukkan pada gambar di bawah ini:

![[Sliding Windows Algorithm-2.png]]

Sekarang, ikuti metode ini untuk setiap iterasi hingga kita mencapai akhir dari array.

![[Sliding Windows Algorithm-3.png]]

Jadi, kita dapat melihat bahwa alih-alih menghitung ulang jumlah untuk setiap **subarray berukuran K**, kita menggunakan jendela sebelumnya yang berukuran **K** dan memperbarui jumlahnya berdasarkan hasil sebelumnya, lalu menggeser jendela ke kanan dengan menggerakkan **pointer kiri dan kanan**. Operasi ini optimal karena hanya membutuhkan **O(1) waktu** untuk menggeser rentang, dibandingkan dengan menghitung ulang.

Pendekatan **menggeser pointer** dan menghitung hasilnya sesuai dengan pergerakan ini dikenal sebagai **Teknik Sliding Window**.

---
## Bagaimana Cara Menggunakan Teknik Sliding Window?

Secara umum, terdapat dua jenis **Sliding Window**:

### 1. Fixed Size Sliding Window (Jendela dengan Ukuran Tetap)

Langkah-langkah umum untuk menyelesaikan masalah dengan teknik ini:

1. Tentukan ukuran jendela yang dibutuhkan, misalnya K.
2. Hitung hasil untuk jendela pertama, yaitu dengan memasukkan K elemen pertama dari struktur data.
3. Gunakan perulangan untuk menggeser jendela satu per satu dan terus menghitung hasilnya untuk setiap jendela baru.

### 2. Variable Size Sliding Window (Jendela dengan Ukuran Variabel)

Langkah-langkah umum untuk menyelesaikan masalah dengan teknik ini:

1. Tingkatkan pointer kanan (right pointer) satu per satu sampai kondisi terpenuhi.
2. Jika pada suatu langkah kondisi tidak terpenuhi, perkecil ukuran jendela dengan menaikkan pointer kiri (left pointer).
3. Jika kondisi kembali terpenuhi, lanjutkan meningkatkan pointer kanan dan ulangi langkah 1.
4. Ulangi langkah-langkah ini sampai mencapai akhir array.

---

## Bagaimana Cara Mengidentifikasi Masalah Sliding Window?

- Masalah ini umumnya melibatkan mencari subarray atau substring yang memenuhi kondisi tertentu, seperti mencari nilai maksimum/minimum.
- Dalam beberapa kasus, ukuran subarray atau substring K akan diberikan secara eksplisit dalam soal.
- Masalah seperti ini bisa diselesaikan dalam kompleksitas waktu $O(N^2)$  menggunakan nested loops, tetapi dengan Sliding Window, kita bisa mengoptimalkannya menjadi $O(N)$.

Kompleksitas Waktu yang Diperlukan:

- O(N) atau O(N log N)
- Batasan: Biasanya N ≤ 10⁶, jika N adalah ukuran array atau string.

---
## Kasus yang menggunakan sliding windows

### 1. Mencari Jumlah Maksimum dari Semua Subarray Berukuran K

Diberikan sebuah array dengan ukuran n, tujuan kita adalah menghitung jumlah maksimum dari K elemen yang berurutan dalam array.

#### Contoh 1

```
Input:  
arr[] = {100, 200, 300, 400}, k = 2  
Output: 700
```

**Penjelasan:** Kita mendapatkan julah maksimum berupa 700, dari menjumlahkan subarrray {300,400}, menghasilkan jumlah maksimum dari subarray berupa k=2.
#### Contoh 2

```
Input:  
arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20}, k = 4  
Output: 39
```

  
**Penjelasan:** Kita mendapatkan jumlah maksimum dengan menambahkan subarray {4, 2, 10, 23} yang memiliki ukuran 4.

#### Contoh 3

```
Input:  
arr[] = {2, 3}, k = 3  
Output: Invalid
```  

Karena **tidak ada subarray** berukuran 3 dalam array yang hanya memiliki **ukuran 2**.

### Pendekatan Naïve (Brute Force)

**Analisis:**

- Kita memulai dari indeks pertama dan menjumlahkan hingga elemen ke-K.
- Lakukan ini untuk semua kelompok elemen berurutan yang berukuran K dalam array.
- Pendekatan ini menggunakan nested loop, di mana:

- Loop luar dimulai dari setiap elemen awal dari blok K elemen.
- Loop dalam akan menjumlahkan hingga elemen ke-K dari blok tersebut.

Berikut adalah implementasi dari pendekatan Brute Force ini:

```cpp
// Solusi O(n*k) untuk menemukan jumlah maksimum
// dari sebuah subarray dengan ukuran k
#include <bits/stdc++.h>
using namespace std;
 
// Mengembalikan jumlah maksimum dalam subarray berukuran k.
int maxSum(int arr[], int n, int k)
{
    // Inisialisasi hasil
    int max_sum = INT_MIN;
 
    // Pertimbangkan semua blok yang dimulai dari i.
    for (int i = 0; i < n - k + 1; i++) {
        int current_sum = 0;
        // Hitung jumlah elemen dalam blok ukuran k.
        for (int j = 0; j < k; j++)
            current_sum = current_sum + arr[i + j];
 
        // Perbarui hasil jika diperlukan.
        max_sum = max(current_sum, max_sum);
    }
 
    return max_sum;
}
 
// Kode utama (driver code)
int main()
{
    int arr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSum(arr, n, k);
    return 0;
}

```


Output: 24  
Kompleksitas waktu: $O(k\cdot n)$ karena mengandung dua loop bersarang.  
Ruang tambahan: O(1)

**Menerapkan teknik sliding window:**

- Kita menghitung jumlah dari k elemen pertama dari n elemen menggunakan loop linear dan menyimpannya dalam variabel window_sum.
- Kemudian, kita akan menelusuri array secara linear hingga mencapai akhir, sambil terus melacak jumlah maksimum.
- Untuk mendapatkan jumlah saat ini dari suatu blok berukuran k elemen, cukup kurangi elemen pertama dari blok sebelumnya dan tambahkan elemen terakhir dari blok saat ini.

Representasi di bawah ini akan memperjelas bagaimana jendela (window) bergeser di seluruh array.

Misalkan kita memiliki array arr[] = {5, 2, -1, 0, 3} dengan nilai k = 3 dan n = 5.

- **Tahap awal:**  
    Kita menghitung jumlah awal dari jendela pertama yang dimulai dari indeks 0. Pada tahap ini, jumlah jendela adalah 6. Sekarang, kita menetapkan maximum_sum sebagai current_window, yaitu 6.
    
    ![[Sliding Windows Algorithm-4.png]]

- **Menggeser jendela pertama kali:**  
    Kita menggeser jendela ke kanan sejauh satu indeks. Oleh karena itu, kita menghapus angka 5 dari jendela dan menambahkan angka 0 ke dalam jendela. Dengan demikian, kita mendapatkan jumlah jendela baru dengan mengurangkan 5 dan menambahkan 0, sehingga jumlah jendela sekarang menjadi 1. Selanjutnya, kita membandingkan jumlah jendela ini dengan maximum_sum. Karena nilainya lebih kecil, kita tidak mengubah maximum_sum.
    
    ![[Sliding Windows Algorithm-5.png]]

- **Menggeser jendela kedua kali:**  
    Sekali lagi, kita menggeser jendela sejauh satu indeks dan memperoleh jumlah jendela baru sebesar 2. Kita kembali memeriksa apakah jumlah jendela ini lebih besar dari maximum_sum sejauh ini. Karena nilainya masih lebih kecil, kita tidak mengubah maximum_sum.
    
    ![[Sliding Windows Algorithm-6.png]]

Dengan demikian, untuk array di atas, nilai maksimum dari jumlah subarray berukuran k adalah **6**.

Berikut adalah kode untuk pendekatan diatas:

```cpp
// Solusi O(n) untuk mencari jumlah maksimum dalam 
// sebuah subarray dengan ukuran k
#include <iostream>
using namespace std;
 
// Mengembalikan jumlah maksimum dalam subarray dengan ukuran k.
int maxSum(int arr[], int n, int k)
{
    // n harus lebih besar dari k
    if (n <= k) {
        cout << "Invalid"; // Jika ukuran array lebih kecil dari k, hasil tidak valid
        return -1;
    }
 
    // Menghitung jumlah elemen pada jendela pertama dengan ukuran k
    int max_sum = 0;
    for (int i = 0; i < k; i++)
        max_sum += arr[i];
 
    // Menghitung jumlah dari jendela berikutnya dengan cara:
    // - Menghapus elemen pertama dari jendela sebelumnya
    // - Menambahkan elemen terakhir dari jendela saat ini
    int window_sum = max_sum;
    for (int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i - k]; // Memperbarui jumlah jendela
        max_sum = max(max_sum, window_sum); // Memperbarui jumlah maksimum jika diperlukan
    }
 
    return max_sum;
}
 
// Driver code
int main()
{
    int arr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSum(arr, n, k);
    return 0;
}

```

Output:
```bash
24
```


Kompleksitas Waktu: O(n), di mana _n_ adalah ukuran array masukan arr[].  
Kompleksitas Ruang Tambahan: O(1)

# Sliding Windows untuk array berelemen negatif
Jika array mengandung elemen negatif, pendekatan sliding window seperti di kode sebelumnya tidak lagi valid. Ini karena asumsi dasar dari teknik sliding window adalah bahwa menambahkan elemen ke jendela selalu meningkatkan jumlah, dan mengurangkan elemen selalu menurunkannya. Dengan adanya nilai negatif, penambahan dan pengurangan elemen bisa membuat sum naik dan turun secara tidak monoton, sehingga tidak menjamin bahwa menggeser pointer akan menghasilkan solusi optimal.

### Alternatif Pendekatan untuk Array dengan Nilai Negatif

1. **Brute Force (O(n²) atau O(n³))**
    
    - Menguji semua kemungkinan subarray dan memeriksa apakah jumlahnya memenuhi syarat.
    - Metode ini tidak efisien untuk array berukuran besar.
2. **Prefix Sum dengan Binary Search (Jika array tidak mengandung bilangan negatif, metode ini juga tidak optimal untuk nilai negatif)**
    
    - Teknik ini pun memiliki keterbatasan ketika ada nilai negatif, karena prefix sum tidak lagi terurut secara monoton.
3. **Dynamic Programming / Algoritma Spesifik**
    
    - Untuk masalah seperti "subarray dengan jumlah minimal melebihi x" di mana array mengandung nilai negatif, tidak ada solusi yang linear secara umum.
    - Salah satu pendekatan adalah menggunakan algoritma O(n²) yang menghitung prefix sum untuk setiap kemungkinan subarray dan mencari panjang minimalnya.

### Contoh Brute Force dengan Prefix Sum

```cpp
#include <bits/stdc++.h>
using namespace std;

int smallestSubWithSum(int x, vector<int>& arr) {
    int n = arr.size();
    int ans = INT_MAX;
    vector<int> prefix(n + 1, 0);
    
    // Hitung prefix sum
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + arr[i];
    }
    
    // Cek semua subarray
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (prefix[j] - prefix[i] > x) {
                ans = min(ans, j - i);
                break; // Karena mencari subarray terpendek untuk indeks i tertentu
            }
        }
    }
    
    return (ans == INT_MAX) ? 0 : ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr)
        cin >> x;
    int x;
    cin >> x;
    
    cout << smallestSubWithSum(x, arr) << "\n";
    return 0;
}
```

### Catatan

- Pendekatan brute force dengan prefix sum memiliki kompleksitas O(n²) dalam kasus terburuk, sehingga tidak ideal untuk array dengan ukuran besar.
- Jika masalah mengharuskan penanganan array dengan nilai negatif dan ukuran besar, mungkin perlu mengeksplorasi algoritma yang lebih kompleks atau heuristik khusus sesuai dengan karakteristik masalahnya.

Semoga membantu! Jika ada pertanyaan lebih lanjut, silakan ditanyakan.