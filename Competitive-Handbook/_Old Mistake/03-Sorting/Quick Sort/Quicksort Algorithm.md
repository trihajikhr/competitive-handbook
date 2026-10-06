---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 03TH-STQS0001
nama_algoritma: Quicksort Algorithm
kategori_algoritma: sorting
kesulitan: 🥉 easy
time_complexity: 🟤 O(n log n) > 🟤 O(n log n) > 🟣 O(n²)
memory_complexity: 🔵 O(log n) ✅ → Stable
sumber: chatgpt.com, Programiz.com, Google AI
date_learned: 2025-04-09T12:50:00
tags:
  - array
  - quick-sort
---
#array #sorting #quick-sort

---
# Quicksort Algorithm Algorithm

**Quicksort** adalah algoritma pengurutan yang menggunakan pendekatan _divide and conquer_ di mana:

1. Sebuah array dibagi menjadi subarray dengan memilih sebuah **pivot element** (elemen yang dipilih dari array). Saat membagi array, elemen pivot ditempatkan sedemikian rupa sehingga elemen-elemen yang **lebih kecil dari pivot berada di sisi kiri**, dan elemen yang **lebih besar dari pivot berada di sisi kanan**.
</br>
2. Subarray kiri dan kanan kemudian dibagi lagi menggunakan pendekatan yang sama. Proses ini berlanjut hingga setiap subarray hanya berisi satu elemen.
</br>
3. Pada titik ini, elemen-elemen sudah dalam keadaan terurut. Terakhir, elemen-elemen digabungkan untuk membentuk array yang sudah terurut.

## Cara Kerja Quicksort Algorithm

### 1. Memilih Pivot Element

Terdapat beberapa variasi dalam quicksort tergantung pada bagaimana pivot dipilih.  
Pada penjelasan ini, **pivot akan dipilih sebagai elemen paling kanan dari array**.

![[Quicksort Algorithm-1.png]]

### 2. Menata Ulang Array

Sekarang, elemen-elemen dalam array ditata ulang sedemikian rupa sehingga **elemen-elemen yang lebih kecil dari pivot ditempatkan di sebelah kiri**, dan **elemen-elemen yang lebih besar dari pivot ditempatkan di sebelah kanan**.

![[Quicksort Algorithm-2.png]]

Berikut adalah cara kita menata ulang array:

1. Sebuah _pointer_ ditempatkan pada elemen pivot. Elemen pivot kemudian dibandingkan dengan elemen-elemen yang dimulai dari indeks pertama.
   ![[Quicksort Algorithm-3.png]]
2. Jika elemen tersebut lebih besar dari elemen pivot, maka sebuah _pointer_ kedua akan ditempatkan pada elemen tersebut.
   
   ![[Quicksort Algorithm-4.png]]
3. Sekarang, elemen pivot dibandingkan dengan elemen-elemen lainnya. Jika ditemukan elemen yang lebih kecil dari elemen pivot, maka elemen yang lebih kecil tersebut ditukar dengan elemen yang lebih besar yang telah ditemukan sebelumnya.
   
   ![[Quicksort Algorithm-5.png]]
4. Proses ini diulang kembali untuk menetapkan elemen lebih besar berikutnya sebagai pointer kedua, lalu menukarnya dengan elemen yang lebih kecil lainnya.
   
   ![[Quicksort Algorithm-6.png]]
5. Proses ini berlanjut hingga elemen kedua terakhir tercapai.
   
   ![[Quicksort Algorithm-7.png]]
6. Akhirnya, elemen pivot ditukar dengan elemen pada posisi pointer kedua.
   
   ![[Quicksort Algorithm-8.png]]
### 3. Bagi Subarray
Elemen pivot kembali dipilih secara terpisah untuk bagian kiri dan kanan dari array. Lalu, langkah 2 diulang kembali.

![[Quicksort Algorithm-9.png]]

Subarray dibagi terus hingga setiap subarray hanya terdiri dari satu elemen. Pada titik ini, array sudah dalam keadaan terurut.
## Algoritma Quicksort Algorithm

```cpp
quickSort(array, leftmostIndex, rightmostIndex)
  if (leftmostIndex < rightmostIndex)
    pivotIndex <- partition(array,leftmostIndex, rightmostIndex)
    quickSort(array, leftmostIndex, pivotIndex - 1)
    quickSort(array, pivotIndex, rightmostIndex)

partition(array, leftmostIndex, rightmostIndex)
  set rightmostIndex as pivotIndex
  storeIndex <- leftmostIndex - 1
  for i <- leftmostIndex + 1 to rightmostIndex
  if element[i] < pivotElement
    swap element[i] and element[storeIndex]
    storeIndex++
  swap pivotElement and element[storeIndex+1]
return storeIndex + 1
```

## Ilustrasi Visual dari Algoritma Quicksort  
Kamu bisa memahami cara kerja algoritma quicksort dengan bantuan ilustrasi berikut.

![[Quicksort Algorithm-10.png]]

![[Quicksort Algorithm-11.png]]
# Contoh Algoritma Quicksort Algorithm

```cpp
// Quick sort dalam C++

#include <iostream>
using namespace std;

// fungsi untuk menukar elemen
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// fungsi untuk mencetak array
void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

// fungsi untuk mengatur ulang array (mencari titik partisi)
int partition(int array[], int low, int high) {
    
  // pilih elemen paling kanan sebagai pivot
  int pivot = array[high];
  
  // penunjuk untuk elemen yang lebih besar
  int i = (low - 1);

  // telusuri setiap elemen dalam array
  // bandingkan dengan pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      // jika ditemukan elemen yang lebih kecil dari pivot
      // tukar dengan elemen lebih besar yang ditunjuk oleh i
      i++;
      
      // tukar elemen di i dengan elemen di j
      swap(&array[i], &array[j]);
    }
  }
  
  // tukar pivot dengan elemen lebih besar di i
  swap(&array[i + 1], &array[high]);
  
  // kembalikan titik partisi
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
      
    // temukan elemen pivot sehingga
    // elemen yang lebih kecil dari pivot berada di kiri pivot
    // elemen yang lebih besar dari pivot berada di kanan pivot
    int pi = partition(array, low, high);

    // pemanggilan rekursif untuk bagian kiri pivot
    quickSort(array, low, pi - 1);

    // pemanggilan rekursif untuk bagian kanan pivot
    quickSort(array, pi + 1, high);
  }
}

// kode utama (driver code)
int main() {
  int data[] = {8, 7, 6, 1, 0, 9, 2};
  int n = sizeof(data) / sizeof(data[0]);
  
  cout << "Array sebelum diurutkan: \n";
  printArray(data, n);
  
  // jalankan quicksort pada data
  quickSort(data, 0, n - 1);
  
  cout << "Array setelah diurutkan secara menaik: \n";
  printArray(data, n);
}
```

### Bonus versi Python
```py
# Quick sort in Python

# function to find the partition position
def partition(array, low, high):

  # choose the rightmost element as pivot
  pivot = array[high]

  # pointer for greater element
  i = low - 1

  # traverse through all elements
  # compare each element with pivot
  for j in range(low, high):
    if array[j] <= pivot:
      # if element smaller than pivot is found
      # swap it with the greater element pointed by i
      i = i + 1

      # swapping element at i with element at j
      (array[i], array[j]) = (array[j], array[i])

  # swap the pivot element with the greater element specified by i
  (array[i + 1], array[high]) = (array[high], array[i + 1])

  # return the position from where partition is done
  return i + 1

# function to perform quicksort
def quickSort(array, low, high):
  if low < high:

    # find pivot element such that
    # element smaller than pivot are on the left
    # element greater than pivot are on the right
    pi = partition(array, low, high)

    # recursive call on the left of pivot
    quickSort(array, low, pi - 1)

    # recursive call on the right of pivot
    quickSort(array, pi + 1, high)


data = [8, 7, 2, 1, 0, 9, 6]
print("Unsorted Array")
print(data)

size = len(data)

quickSort(data, 0, size - 1)

print('Sorted Array in Ascending Order:')
print(data)
```

# Quicksort Algorithm Complexity
## Time Complexity
Quicksort adalah algoritma sorting berbasis _divide and conquer_ yang sangat efisien dalam praktiknya, meskipun memiliki kompleksitas terburuk yang sama dengan algoritma sederhana lainnya. Berikut analisis kompleksitas waktunya:
### Best Case (Kasus Terbaik) - $O(n \;log\; n)$
- Kasus terbaik terjadi ketika pembagian array oleh pivot menghasilkan dua bagian yang relatif seimbang.  
- Setiap pembagian memerlukan operasi, dan ada $log \;n$ pembagian secara rekursif.  
- Kompleksitas waktu dalam kasus terbaik adalah $O(n \;log\; n)$.
### Average Case (Kasus Rata-rata) - $O(n \;log\; n)$
- Pada kasus umum, pembagian mungkin tidak sepenuhnya seimbang tetapi tidak ekstrem.  
- Operasi pembagian tetap berjumlah n, dan kedalaman rekursi rata-rata mendekati $log \;n$.  
- Kompleksitas waktu dalam kasus rata-rata adalah $O(n \;log\; n)$.
### Worst Case (Kasus Terburuk) - $O(n²)$
- Terjadi ketika pivot selalu memilih elemen terbesar atau terkecil (misalnya, jika array sudah terurut).  
- Pembagian menjadi sangat tidak seimbang, sehingga kedalaman rekursi menjadi n.  
- Kompleksitas waktu dalam kasus terburuk adalah $O(n²)$.
### Ringkasan
| Kasus        | Kompleksitas Waktu |
| ------------ | ------------------ |
| Best Case    | $O(n \;log\; n)$   |
| Average Case | $O(n \;log\; n)$   |
| Worst Case   | $O(n²)$            |
## Space Complexity dan Stability
### Space Complexity
Quicksort merupakan algoritma **in-place sorting**, karena tidak memerlukan struktur data tambahan yang besar untuk menyimpan array baru (selain stack rekursif).  
Namun, karena menggunakan rekursi, akan ada penggunaan stack untuk setiap pemanggilan fungsi.

- **Best/Average Case**: Kedalaman rekursi maksimum adalah $log\; n$ → $O(log\;n)$

- **Worst Case**: Jika pembagian tidak seimbang, kedalaman rekursi bisa menjadi $n$ → $O(n)$
### Stability
Quicksort adalah **unstable sorting algorithm**.  

Ini karena elemen-elemen dengan nilai yang sama **dapat berubah posisi relatifnya** selama proses partisi, terutama saat terjadi pertukaran elemen.

## Kesimpulan
| Faktor Complexity | Nilai                                      |
| ----------------- | ------------------------------------------ |
| Best Case         | $O(n \;log\; n)$                           |
| Average Case      | $O(n \;log\; n)$                           |
| Worst Case        | $O(n²)$                                    |
| Space Complexity  | Best/Average → $O(log\;n)$, Worst → $O(n)$ |
| Stability         | Unstable                                   |
# Aplikasi Quicksort Algorithm
- **Basis Data:**
    Quick Sort digunakan untuk mengurutkan data dalam basis data, yang penting untuk efisiensi pencarian dan pengambilan data. 
  </br>
- **Mesin Pencari:**
    Algoritma ini membantu mengurutkan hasil pencarian, sehingga pengguna dapat dengan mudah menemukan informasi yang relevan. 
</br>
- **Pustaka Pengurutan:**
    Quick Sort sering digunakan sebagai algoritma default dalam pustaka pengurutan karena efisiensi dan kemampuannya mengurutkan data besar. 
</br>
- **Sistem Pemesanan Makanan:**
    Quick Sort dapat digunakan untuk mengurutkan daftar pesanan makanan berdasarkan prioritas atau waktu, sehingga memudahkan pegawai dalam mengelola pesanan. 
</br>
- **Aplikasi Game:**
    Algoritma ini dapat digunakan dalam game untuk mengurutkan daftar pemain, skor, atau item, sehingga memberikan pengalaman bermain yang lebih baik. 
</br>
- **Implementasi Algoritma:**
    Quick Sort dapat digunakan sebagai dasar implementasi algoritma lain yang membutuhkan pengurutan data.
## Keunggulan dan kelemahan
### Keunggulan Quicksort Algorithm
- **Cepat pada praktiknya**  
    Quicksort umumnya lebih cepat daripada algoritma lain seperti Merge Sort atau Bubble Sort pada array besar, karena pengolahan dilakukan secara in-place dan efisien terhadap cache.
</br>
- **In-place Sorting**  
    Tidak membutuhkan banyak ruang tambahan karena tidak menggunakan array tambahan besar, hanya stack rekursi.
</br>
- **Divide and Conquer**  
    Pendekatan pembagian membuat algoritma ini sangat efisien pada data besar dan mudah dioptimasi untuk berbagai kasus.
</br>
- **Bisa dioptimalkan lebih lanjut**  
    Dengan teknik seperti random pivoting atau median-of-three, performa worst-case bisa dikurangi.
### Kelemahan Quicksort Algorithm
- **Unstable**  
    Tidak mempertahankan urutan elemen yang memiliki nilai sama, sehingga kurang cocok untuk data yang perlu stabilitas sorting.
</br>
- **Worst-case Time Complexity O(n²)**  
    Jika pemilihan pivot buruk (misal selalu elemen terkecil/terbesar), performa bisa turun drastis.
</br>
- **Bergantung pada pemilihan pivot**  
    Efisiensi sangat dipengaruhi oleh strategi pemilihan pivot, sehingga butuh optimasi tambahan untuk performa konsisten.
</br>
- **Menggunakan rekursi**  
    Bisa menyebabkan stack overflow pada input yang sangat besar atau pembagian yang tidak seimbang.
## Kesimpulan
Quicksort adalah algoritma sorting yang sangat cepat dan efisien dalam banyak kasus nyata, terutama untuk array besar. Namun, algoritma ini harus digunakan dengan hati-hati pada kasus yang dapat menyebabkan pembagian tidak seimbang atau ketika stabilitas sorting diperlukan. Dengan pemilihan pivot yang baik, quicksort bisa menjadi salah satu algoritma sorting terbaik yang tersedia.