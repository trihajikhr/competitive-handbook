---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 03TH-STMS0001
nama_algoritma: Merge Sort Algorithm
kategori_algoritma: sorting
kesulitan: 🥇 hard
time_complexity: 🟤 O(n log n) > 🟤 O(n log n) > 🟤 O(n log n)
memory_complexity: 🟠 O(n) ✅ → Stable
sumber: programiz.com & geeksforgeeks.com
date_learned: 2025-04-09T11:58:00
tags:
  - array
  - sorting
  - merge-sort
---
#array #sorting #merge-sort

---
# Merge Sort Algorithm
**Merge Sort** adalah salah satu algoritma sorting yang paling populer dan didasarkan pada prinsip **Divide and Conquer Algorithm**.

Di sini, sebuah masalah dibagi menjadi beberapa **sub-problem**. Setiap **sub-problem** diselesaikan secara individual. Akhirnya, **sub-problem** tersebut digabungkan untuk membentuk solusi akhir.

![[Merge Sort Algorithm-1.png|500]]
## Prinsip Divide and Conquer

### Divide and Conquer Strategy

Dengan menggunakan teknik **Divide and Conquer**, kita membagi sebuah masalah menjadi beberapa **subproblem**. Ketika solusi untuk masing-masing **subproblem** sudah tersedia, kita **menggabungkan** hasil dari **subproblem** tersebut untuk menyelesaikan masalah utama.

Misalkan kita harus melakukan **sorting** pada sebuah array `A`. Sebuah **subproblem** dalam hal ini adalah melakukan **sorting** pada bagian dari array tersebut yang dimulai dari indeks `p` dan berakhir di indeks `r`, yang dinotasikan sebagai `A[p..r]`.

#### Divide

Jika `q` adalah titik tengah antara `p` dan `r`, maka kita bisa membagi **subarray** `A[p..r]` menjadi dua bagian, yaitu `A[p..q]` dan `A[q+1..r]`.
#### Conquer

Pada langkah **conquer**, kita mencoba melakukan **sorting** pada kedua **subarray** `A[p..q]` dan `A[q+1..r]`. Jika kita belum mencapai **base case**, maka kita akan kembali membagi kedua **subarray** tersebut dan mencoba melakukan **sorting** terhadapnya.
#### Combine

Ketika langkah **conquer** mencapai **base case** dan kita mendapatkan dua **subarray** yang sudah terurut yaitu `A[p..q]` dan `A[q+1..r]` untuk array `A[p..r]`, kita akan **menggabungkan** hasil tersebut dengan membuat sebuah array `A[p..r]` yang terurut dari dua **subarray** `A[p..q]` dan `A[q+1..r]`.
## Algoritma Merge Sort

**Fungsi MergeSort** secara berulang membagi array menjadi dua bagian hingga kita mencapai tahap di mana kita mencoba melakukan **MergeSort** pada sebuah **subarray** berukuran 1, yaitu ketika `p == r`.

Setelah itu, fungsi **merge** mulai dijalankan dan menggabungkan array yang telah terurut menjadi array yang lebih besar hingga seluruh array berhasil digabungkan.

```cpp
MergeSort(A, p, r):
    if p > r 
        return
    q = (p + r) / 2
    mergeSort(A, p, q)
    mergeSort(A, q + 1, r)
    merge(A, p, q, r)
```

Untuk melakukan **sorting** pada seluruh array, kita perlu memanggil `MergeSort(A, 0, length(A) - 1)`.

Seperti yang ditunjukkan pada gambar di bawah, algoritma **merge sort** secara rekursif membagi array menjadi dua bagian hingga kita mencapai **base case**, yaitu array dengan 1 elemen. Setelah itu, fungsi **merge** mengambil **sub-array** yang telah terurut dan menggabungkannya secara bertahap untuk mengurutkan seluruh array.

![[Merge Sort Algorithm-2.png|500]]

## Langkah Merge dalam Merge Sort

Setiap algoritma rekursif bergantung pada **base case** dan kemampuan untuk menggabungkan hasil dari **base case** tersebut. **Merge sort** tidak berbeda. Bagian paling penting dari algoritma **merge sort** adalah, seperti yang bisa ditebak, langkah **merge**.

Langkah **merge** adalah solusi untuk masalah sederhana yaitu menggabungkan dua **list (array)** yang sudah terurut menjadi satu **list (array)** besar yang juga terurut.

Algoritma ini menggunakan tiga **pointer**, masing-masing untuk dua array input, dan satu lagi untuk melacak indeks saat ini pada array hasil yang terurut.

```
Apakah kita telah mencapai akhir dari salah satu array?
- Tidak:
    - Bandingkan elemen saat ini dari kedua array
    - Salin elemen yang lebih kecil ke dalam array hasil yang terurut
    - Geser **pointer** dari elemen yang lebih kecil
- Ya:
    - Salin semua elemen yang tersisa dari array yang belum kosong
```

![[Merge Sort Algorithm-3.png|500]]

# Contoh Algoritma Merge Sort

Perbedaan yang cukup mencolok antara langkah **merge** yang kita jelaskan sebelumnya dan yang kita gunakan dalam **merge sort** adalah bahwa kita hanya menjalankan fungsi **merge** pada dua **sub-array** yang berurutan.

Itulah mengapa kita hanya membutuhkan array, posisi awal, indeks terakhir dari **sub-array** pertama (kita bisa menghitung indeks pertama dari **sub-array** kedua), dan indeks terakhir dari **sub-array** kedua.

Tugas kita adalah menggabungkan dua **sub-array** `A[p..q]` dan `A[q+1..r]` untuk membuat array terurut `A[p..r]`. Jadi, **input** untuk fungsi ini adalah `A`, `p`, `q`, dan `r`.

Fungsi **merge** bekerja sebagai berikut:

- Buat salinan dari **sub-array** `L ← A[p..q]` dan `M ← A[q+1..r]`
- Buat tiga **pointer** `i`, `j`, dan `k`
    
    - `i` melacak indeks saat ini dari `L`, dimulai dari 0
    - `j` melacak indeks saat ini dari `M`, dimulai dari 0
    - `k` melacak indeks saat ini dari `A[p..r]`, dimulai dari `p`
- Selama kita belum mencapai akhir dari `L` atau `M`, pilih elemen yang lebih kecil dari antara `L[i]` dan `M[j]`, dan tempatkan di posisi yang benar pada `A[p..r]`
- Ketika kita kehabisan elemen pada `L` atau `M`, salin semua elemen yang tersisa dari array yang belum habis ke dalam `A[p..r]`

Dalam kode, ini akan terlihat seperti:

```cpp
// Menggabungkan dua subarray L dan M ke dalam arr
void merge(int arr[], int p, int q, int r) {

    // Buat L ← A[p..q] dan M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Menjaga indeks saat ini dari sub-array dan array utama
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Selama kita belum mencapai akhir dari L atau M,
    // pilih elemen yang lebih kecil dari L dan M,
    // dan tempatkan pada posisi yang benar di A[p..r]
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // Ketika kita kehabisan elemen di L atau M,
    // ambil elemen yang tersisa dan masukkan ke dalam A[p..r]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}
```

## Fungsi `merge( )` Dijelaskan Langkah demi Langkah

Banyak hal yang terjadi di dalam fungsi ini, jadi mari kita ambil sebuah contoh untuk melihat bagaimana cara kerjanya.

Seperti biasa, sebuah gambar bernilai seribu kata.

![[Merge Sort Algorithm-4.png]]


Array `A[0..5]` berisi dua **sub-array** yang sudah terurut: `A[0..3]` dan `A[4..5]`. Mari kita lihat bagaimana fungsi `merge` akan menggabungkan kedua array tersebut.

```cpp
void merge(int arr[], int p, int q, int r) {
// Di sini, p = 0, q = 3, r = 5 (ukuran array = 6)
```

### Langkah 1: Buat salinan duplikat dari sub-array yang akan digabungkan

```cpp
    // Buat L ← A[p..q] dan M ← A[q+1..r]
    int n1 = q - p + 1 = 3 - 0 + 1 = 4;
    int n2 = r - q = 5 - 3 = 2;

    int L[4], M[2];

    for (int i = 0; i < 4; i++)
        L[i] = arr[p + i];
        // L[0,1,2,3] = A[0,1,2,3] = [1,5,10,12]

    for (int j = 0; j < 2; j++)
        M[j] = arr[q + 1 + j];
        // M[0,1] = A[4,5] = [6,9]
```

![[Merge Sort Algorithm-5.png]]

### Langkah 2: Menjaga indeks saat ini dari sub-array dan array utama

```cpp
    int i, j, k;
    i = 0; 
    j = 0; 
    k = p;
```

- `i` digunakan untuk melacak indeks saat ini pada sub-array `L`
- `j` digunakan untuk melacak indeks saat ini pada sub-array `M`
- `k` digunakan untuk melacak indeks saat ini pada array utama `A`, dimulai dari posisi `p`

![[Merge Sort Algorithm-6.png]]

### Langkah 3: Sampai kita mencapai akhir dari L atau M, pilih elemen yang lebih kecil di antara L dan M, lalu tempatkan di posisi yang benar dalam `A[p..r]`

```cpp
    while (i < n1 && j < n2) { 
        if (L[i] <= M[j]) { 
            arr[k] = L[i]; 
            i++; 
        } else { 
            arr[k] = M[j]; 
            j++; 
        } 
        k++; 
    }
```

Penjelasan:

- Selama elemen di `L` dan `M` masih ada, kita bandingkan elemen saat ini.
- Jika `L[i]` lebih kecil atau sama dengan `M[j]`, salin `L[i]` ke `arr[k]` dan geser `i`.
- Jika `M[j]` lebih kecil, salin `M[j]` ke `arr[k]` dan geser `j`.
- `k` selalu digeser agar terus mengisi posisi berikutnya di array utama.

![[Merge Sort Algorithm-7.png]]

### Langkah 4: Ketika elemen di L atau M sudah habis, ambil elemen-elemen yang tersisa dan masukkan ke dalam `A[p..r]`

```cpp
    // Kita keluar dari loop sebelumnya karena kondisi j < n2 tidak terpenuhi
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
```

Penjelasan:

- Jika `M` sudah habis (semua elemennya sudah diproses), tapi masih ada elemen di `L`, maka kita masukkan sisa elemen dari `L` ke dalam `arr` secara langsung.

![[Merge Sort Algorithm-8.png]]


```cpp
    // Kita keluar dari loop sebelumnya karena kondisi i < n1 tidak terpenuhi  
    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}
```

Penjelasan:

- Jika `L` sudah habis (semua elemennya sudah diproses), tapi masih ada elemen di `M`, maka kita salin sisa elemen dari `M` ke dalam `arr` secara langsung.
- Dengan langkah ini, kita memastikan bahwa seluruh elemen dari kedua sub-array (`L` dan `M`) digabungkan ke dalam array utama secara **terurut**.

![[Merge Sort Algorithm-9.png]]

Langkah ini akan dibutuhkan **jika ukuran M lebih besar dari L**.

Pada akhir fungsi `merge`, **subarray `A[p..r]` akan terurut**.
## Contoh Merge Sort

```cpp
// Merge sort dalam C++
#include <iostream>
#include <vector>
using namespace std;

// Gabungkan dua subarray L dan M ke dalam arr
void merge(int arr[], int p, int q, int r) {
  
  // Buat L ← A[p..q] dan M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;
  
  // Gunakan std::vector untuk mengalokasikan array secara dinamis
  vector<int> L(n1);
  vector<int> M(n2);
  
  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
    
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];
    
  // Menjaga indeks saat ini dari subarray dan array utama
  int i = 0, j = 0, k = p;
  
  // Selama kita belum mencapai akhir dari L atau M,
  // pilih elemen terkecil dari L dan M lalu tempatkan di posisi yang tepat di A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }
  
  // Ketika kita kehabisan elemen dari L atau M,
  // ambil sisa elemen yang masih ada dan masukkan ke A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  
  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Bagi array menjadi dua subarray, urutkan, lalu gabungkan
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // m adalah titik di mana array dibagi menjadi dua subarray
    int m = l + (r - l) / 2;
    
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    // Gabungkan kedua subarray yang sudah terurut
    merge(arr, l, m, r);
  }
}

// Cetak isi array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

// Program utama
int main() {
  int arr[] = {6, 5, 12, 10, 9, 1};
  int size = sizeof(arr) / sizeof(arr[0]);
  mergeSort(arr, 0, size - 1);
  cout << "Array yang sudah diurutkan: \n";
  printArray(arr, size);
  return 0;
}
```

### Bonus versi Python

```py
# MergeSort in Python

def mergeSort(array):
    if len(array) > 1:

        #  r is the point where the array is divided into two subarrays
        r = len(array)//2
        L = array[:r]
        M = array[r:]

        # Sort the two halves
        mergeSort(L)
        mergeSort(M)

        i = j = k = 0

        # Until we reach either end of either L or M, pick larger among
        # elements L and M and place them in the correct position at A[p..r]
        while i < len(L) and j < len(M):
            if L[i] < M[j]:
                array[k] = L[i]
                i += 1
            else:
                array[k] = M[j]
                j += 1
            k += 1

        # When we run out of elements in either L or M,
        # pick up the remaining elements and put in A[p..r]
        while i < len(L):
            array[k] = L[i]
            i += 1
            k += 1

        while j < len(M):
            array[k] = M[j]
            j += 1
            k += 1


# Print the array
def printList(array):
    for i in range(len(array)):
        print(array[i], end=" ")
    print()


# Driver program
if __name__ == '__main__':
    array = [6, 5, 12, 10, 9, 1]

    mergeSort(array)

    print("Sorted array is: ")
    printList(array)
```
# Merge Sort Complexity
## Time Complexity
Merge Sort adalah algoritma divide-and-conquer yang membagi array menjadi dua bagian, mengurutkan keduanya secara rekursif, lalu menggabungkannya. Algoritma ini dikenal memiliki performa yang stabil dan efisien, bahkan untuk input berukuran besar. Berikut analisis kompleksitas waktunya dalam tiga skenario:
### Best Case (Kasus Terbaik) - $O(n\;log\;n)$
- Kasus terbaik terjadi saat array sudah terurut, namun Merge Sort tetap akan membagi array dan melakukan proses penggabungan (merge) seperti biasa.  
- Meskipun tidak ada pertukaran yang diperlukan, proses pemanggilan rekursif dan penggabungan tetap dilakukan di setiap tingkat pembagian.  
- Kompleksitas waktu pada kasus ini tetap $O(n\;log\;n)$ karena pembagian dan penggabungan tetap terjadi walaupun data sudah terurut.
### Average Case (Kasus Rata-rata) - $O(n\;log\;n)$
- Dalam kasus umum, ketika data berada dalam urutan acak, Merge Sort tetap akan membagi array menjadi dua bagian hingga elemen-elemen menjadi satuan.  
- Setiap tingkat rekursi membutuhkan waktu linear $O(n)$ untuk proses penggabungan, dan terdapat $log\;n$ tingkat pembagian.  
- Sehingga kompleksitas waktu dalam kasus rata-rata tetap $O(n\;log\;n)$ karena struktur algoritma tidak bergantung pada urutan awal elemen.
### Worst Case (Kasus Terburuk) - $O(n\;log\;n)$
- Kasus terburuk terjadi saat array dalam urutan yang benar-benar berlawanan dengan urutan akhir yang diinginkan (misalnya menurun).  
- Namun, seperti halnya pada kasus terbaik dan rata-rata, Merge Sort tetap melakukan pembagian dan penggabungan yang sama.  
- Tidak ada optimasi kondisi awal yang dapat mempercepat proses sorting.  
- Kompleksitas waktu dalam kasus terburuk juga adalah $O(n\;log\;n)$ karena seluruh elemen harus tetap diproses di setiap tingkat rekursi.
### Ringkasan
| Kasus        | Kompleksitas Waktu |
| ------------ | ------------------ |
| Best Case    | $O(n\;log\;n)$     |
| Average Case | $O(n\;log\;n)$     |
| Worst Case   | $O(n\;log\;n)$     |
## Space Complexity dan Stability
### Space Complexity
Merge Sort **tidak dilakukan secara in-place**, karena membutuhkan ruang tambahan untuk menyimpan salinan subarray yang akan digabungkan. Pada setiap langkah rekursif, algoritma membuat array baru untuk masing-masing bagian kiri dan kanan yang sedang diproses.

Dengan demikian, Merge Sort memerlukan **ruang tambahan sebesar $O(n)$** untuk menampung elemen-elemen sementara selama proses penggabungan.  

Oleh karena itu, **space complexity** Merge Sort adalah: $O(n)$
### Stability
Merge Sort adalah **stable sorting algorithm**, karena saat menggabungkan dua subarray yang sudah terurut, elemen dengan nilai yang sama akan tetap mempertahankan **urutan relatif** mereka dari input awal.

Hal ini sangat penting dalam konteks di mana data memiliki properti tambahan selain nilai yang dibandingkan, seperti _timestamp_ atau _ID_.

Dengan kata lain, Merge Sort **tidak menukar posisi elemen yang setara**, menjadikannya pilihan ideal untuk situasi di mana stabilitas penting.

## Kesimpulan
| Faktor Complexity | Nilai          |
| ----------------- | -------------- |
| Best Case         | $O(n\;log\;n)$ |
| Average Case      | $O(n\;log\;n)$ |
| Worst Case        | $O(n\;log\;n)$ |
| Space Complexity  | $O(n)$         |
| Stability         | Stable         |
# Aplikasi Merge Sort
- **Pengurutan Data Besar:**
    Merge sort sangat cocok untuk mengurutkan kumpulan data besar karena kompleksitas waktunya yang efisien, yaitu O(n log n). 
</br>
- **Pengurutan Daftar Terhubung:**
    Merge sort dapat digunakan untuk mengurutkan daftar terhubung, meskipun membutuhkan ruang tambahan untuk menyimpan sub-daftar sementara. 
</br>
- **Pengurutan Eksternal:**
    Merge sort dapat digunakan untuk mengurutkan data yang terlalu besar untuk dimuat ke dalam memori utama, dengan memproses data secara bertahap dari disk. 
</br>
- **Manajemen Basis Data:**
    Merge sort sering digunakan dalam sistem manajemen basis data untuk mengurutkan data sebelum melakukan operasi seperti penggabungan atau seleksi. 
</br>
- **Stabilitas:**
    Merge sort merupakan algoritma pengurutan yang stabil, artinya elemen dengan nilai yang sama akan tetap berada pada urutan relatif yang sama setelah pengurutan, yang penting untuk aplikasi tertentu. 
</br>
- **Paralelisasi:**
    Pendekatan divide-and-conquer merge sort memungkinkan paralelisasi yang mudah, sehingga cocok untuk aplikasi multi-thread. 
</br>
- **Pengurutan Rekaman dalam Basis Data:**
    Merge sort ideal untuk mengurutkan rekaman dalam basis data karena stabilitasnya.
## Keunggulan dan kelemahan
### Keunggulan Merge Sort

- **Kompleksitas waktu terjamin O(nlog⁡n)O(n \log n)**  
    Tidak peduli apakah data sudah hampir terurut atau acak sepenuhnya, waktu eksekusi tetap efisien.
</br>
- **Stable sort**  
    Elemen dengan nilai sama tidak berubah posisi relatifnya.
</br>
- **Cocok untuk data besar**  
    Performanya tetap baik meski untuk array berukuran besar.
</br>
- **Tidak bergantung pada urutan awal data**  
    Tidak seperti Bubble Sort atau Insertion Sort yang cepat untuk data hampir terurut, Merge Sort konsisten.
</br>
- **Digunakan pada struktur data linked list**  
    Merge Sort dapat bekerja sangat baik pada linked list karena tidak perlu akses acak terhadap elemen.

### Kelemahan Merge Sort

- **Menggunakan ruang tambahan O(n)O(n)**  
    Karena membutuhkan array sementara untuk menyimpan hasil penggabungan, Merge Sort **tidak efisien dalam hal memori**.
</br>
- **Kurang efisien untuk array kecil**  
    Untuk data kecil, algoritma seperti Insertion Sort biasanya lebih cepat karena overhead Merge Sort lebih besar.
</br>
- **Bukan in-place sorting**  
    Tidak memodifikasi array langsung tanpa ruang tambahan, sehingga memori bisa menjadi isu.
## Kesimpulan

Merge Sort adalah algoritma sorting yang sangat kuat dan stabil dengan waktu eksekusi yang konsisten di semua kasus. Meski membutuhkan ruang tambahan, keandalannya dalam menangani data besar dan kestabilannya menjadikannya pilihan utama dalam banyak aplikasi, terutama jika kestabilan dan performa konsisten dibutuhkan. Namun, untuk data kecil atau saat efisiensi memori sangat penting, algoritma lain mungkin lebih sesuai.