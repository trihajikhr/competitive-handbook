---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 03TH-STBS0001
nama_algoritma: bubble sort algorithm
kategori_algoritma: sorting
kesulitan: 🥉 easy
time_complexity: 🟠 O(n) >  🟣 O(n²) > 🟣 O(n²)
memory_complexity: 🟢 O(1) ✅ → Stable
sumber: programiz.com
date_learned: 2025-03-03T01:11:00
tags:
  - sorting
  - array
  - bubble-sort
---
#sorting  #array  #bubble-sort 

---
# Bubble Sort Algorithm
Bubble sort adalah algoritma sorting yang membandingkan dua elemen yang berdekatan dan menukarnya hingga berada dalam urutan yang diinginkan.

Seperti pergerakan gelembung udara di dalam air yang naik ke permukaan, setiap elemen dalam array akan bergerak ke posisi akhirnya pada setiap iterasi. Oleh karena itu, algoritma ini disebut **bubble sort**.
## Cara kerja Bubble Sort
Misalkan kita ingin mengurutkan elemen dalam **urutan naik**.

### Iterasi Pertama (Membandingkan dan Menukar)
- Mulai dari indeks pertama, bandingkan elemen pertama dan kedua.
- Jika elemen pertama lebih besar dari elemen kedua, maka keduanya ditukar.
- Selanjutnya, bandingkan elemen kedua dan ketiga. Jika tidak berurutan, tukar keduanya.
- Proses ini terus berlanjut hingga mencapai elemen terakhir.
  
  ![[Bubble Sort Algorithm-1.png]]
### Iterasi Berikutnya
- Proses yang sama diulangi untuk iterasi berikutnya.
- Setelah setiap iterasi, elemen terbesar di antara elemen yang belum terurut akan ditempatkan di posisi akhirnya.

![[Bubble Sort Algorithm-2.png]]

Dalam setiap iterasi, perbandingan dilakukan hingga elemen terakhir yang belum terurut.

Bandingkan elemen yang berdekatan:

![[Bubble Sort Algorithm-3.png]]

Array dianggap sudah terurut ketika semua elemen yang belum terurut telah ditempatkan pada posisi yang benar.

Susunan diurutkan jika semua elemen disimpan dalam urutan yang benar:

![[Bubble Sort Algorithm-4.png]]

# Contoh Algoritma Bubble Sort
## 1. Implementasi standar
Implementasi standar bubble sort mungkin memiliki kerangka sebagai berikut:

```cpp
bubbleSort(array)
  for i <- 1 to sizeOfArray - 1
    for j <- 1 to sizeOfArray - 1 - i
      if leftElement > rightElement
        swap leftElement and rightElement
end bubbleSort
```

Dan berikut implementasinya dalam kode:

```cpp
// Bubble sort dalam C++

#include <iostream>
using namespace std;

// melakukan bubble sort
void bubbleSort(int array[], int size) {

  // loop untuk mengakses setiap elemen array
  for (int step = 0; step < size -1; ++step) {
      
    // loop untuk membandingkan elemen array
    for (int i = 0; i < size - step - 1; ++i) {

      // membandingkan dua elemen yang berdekatan
      // ubah > menjadi < untuk mengurutkan dalam urutan menurun
      if (array[i] > array[i + 1]) {

        // menukar elemen jika elemen tidak dalam urutan yang diinginkan
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}

// mencetak array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    cout << "  " << array[i];
  }
  cout << "\n";
}

int main() {
  int data[] = {-2, 45, 0, 11, -9};
  
  // mencari panjang array
  int size = sizeof(data) / sizeof(data[0]);
  
  bubbleSort(data, size);
  
  cout << "Array yang sudah diurutkan dalam urutan menaik:\n";  
  printArray(data, size);
}
```

## 2. Algoritma Bubble Sort yang Dioptimalkan  
Dalam algoritma di atas, semua perbandingan dilakukan bahkan jika array sudah terurut.  

Hal ini meningkatkan waktu eksekusi.  

Untuk mengatasinya, kita dapat memperkenalkan variabel tambahan `swapped`. Nilai `swapped` diatur menjadi **true** jika terjadi pertukaran elemen. Jika tidak, nilainya diatur menjadi **false**.  

Setelah satu iterasi, jika tidak ada pertukaran, nilai `swapped` akan **false**. Ini berarti elemen-elemen sudah terurut, dan tidak perlu melakukan iterasi lebih lanjut.  

Hal ini akan mengurangi waktu eksekusi dan membantu mengoptimalkan *bubble sort*.  

**Algoritma untuk optimized bubble sort adalah:**

```cpp
bubbleSort(array)
  for i <- 1 to sizeOfArray - 1
    swapped <- false
    for j <- 1 to sizeOfArray - 1 - i
      if leftElement > rightElement
        swap leftElement and rightElement
        swapped <- true
    if swapped == false
      break
end bubbleSort
```

Berikut implementasinya:

```cpp
// Bubble sort yang dioptimalkan dalam C++

#include <iostream>
using namespace std;

// melakukan bubble sort
void bubbleSort(int array[], int size) {
    
  // loop untuk mengakses setiap elemen array
  for (int step = 0; step < (size-1); ++step) {
      
    // mengecek apakah terjadi pertukaran elemen
    int swapped = 0;
    
    // loop untuk membandingkan dua elemen
    for (int i = 0; i < (size-step-1); ++i) {
        
      // membandingkan dua elemen array
      // ubah tanda > menjadi < untuk mengurutkan secara descending
      if (array[i] > array[i + 1]) {

        // pertukaran terjadi jika elemen
        // tidak dalam urutan yang diinginkan
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        
        swapped = 1;
      }
    }

    // jika tidak ada pertukaran, berarti array sudah terurut
    // sehingga tidak perlu melakukan perbandingan lebih lanjut
    if (swapped == 0)
      break;
  }
}

// mencetak array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    cout << "  " << array[i];
  }
  cout << "\n";
}

int main() {
  int data[] = {-2, 45, 0, 11, -9};
  
  // mencari panjang array
  int size = sizeof(data) / sizeof(data[0]);
  
  bubbleSort(data, size);
  
  cout << "Array yang telah diurutkan dalam urutan ascending:\n";
  printArray(data, size);
}

```

## Bonus versi python
```py
# Optimized Bubble sort in Python

def bubbleSort(array):
    
  # loop through each element of array
  for i in range(len(array)):
        
    # keep track of swapping
    swapped = False
    
    # loop to compare array elements
    for j in range(0, len(array) - i - 1):

      # compare two adjacent elements
      # change > to < to sort in descending order
      if array[j] > array[j + 1]:

        # swapping occurs if elements
        # are not in the intended order
        temp = array[j]
        array[j] = array[j+1]
        array[j+1] = temp

        swapped = True
          
    # no swapping means the array is already sorted
    # so no need for further comparison
    if not swapped:
      break

data = [-2, 45, 0, 11, -9]

bubbleSort(data)

print('Sorted Array in Ascending Order:')
print(data)
```

# Bubble Sort Complexity
## Time Complexity

Bubble Sort merupakan salah satu algoritma sorting yang sederhana tetapi memiliki efisiensi yang kurang optimal dibandingkan algoritma lain. Berikut adalah analisis kompleksitasnya dalam tiga kasus:

### Best Case (Kasus Terbaik) - $O(n)$

- Kasus terbaik terjadi ketika array sudah dalam keadaan terurut.
- Pada iterasi pertama, tidak ada pertukaran elemen yang dilakukan, sehingga algoritma dapat langsung berhenti setelah satu iterasi.
- Dengan adanya optimasi menggunakan variabel `swapped`, kompleksitas waktu dalam kasus ini adalah $O(n)$ karena hanya membutuhkan satu kali iterasi untuk mengecek bahwa array sudah terurut.

### Average Case (Kasus Rata-rata) - $O(n^2)$

- Dalam skenario umum, elemen-elemen berada dalam urutan acak.
- Algoritma tetap harus membandingkan setiap elemen dengan elemen berikutnya dalam setiap iterasi dan menukarnya jika diperlukan.
- Karena setiap iterasi menempatkan satu elemen terbesar ke posisi akhirnya, jumlah iterasi yang diperlukan tetap sekitar **n-1**, dan dalam setiap iterasi dilakukan **n-i-1** perbandingan.
- Kompleksitas waktu dalam kasus rata-rata tetap $O(n^2)$ karena jumlah perbandingan dan pertukaran tetap dominan.

### Worst Case (Kasus Terburuk) - $O(n^2)$ 

- Kasus terburuk terjadi ketika array dalam keadaan benar-benar terbalik, yaitu dalam urutan menurun.
- Setiap elemen harus ditukar dalam setiap iterasi agar mendapatkan urutan yang benar.
- Seperti pada kasus rata-rata, jumlah iterasi yang dilakukan adalah **n-1**, dan dalam setiap iterasi tetap ada perbandingan sebanyak **n-i-1**.
- Oleh karena itu, kompleksitas waktu dalam kasus terburuk tetap $O(n^2)$ karena jumlah operasi tetap maksimal.

### Ringkasan
| Kasus        | Kompleksitas Waktu |
| ------------ | ------------------ |
| Best Case    | $O(n)$             |
| Average Case | $O(n^2)$           |
| Worst Case   | $O(n^2)$           |
## Space Complexity dan Stability
### Space Complexity
Bubble Sort menggunakan $O(1)$ ruang tambahan karena sorting dilakukan secara in-place tanpa memerlukan struktur data tambahan.

### Stability

Bubble Sort adalah **stable sorting algorithm**, karena elemen dengan nilai yang sama tidak akan bertukar posisi relatif selama proses sorting.

## Kesimpulan
| Faktor Complexity | Nilai           |
| ----------------- | --------------- |
| Best Case         | $O(n)$          |
| Average Case      | $O(n^2)$        |
| Worst Case        | $O(n^2)$        |
| Space Complexity  | $O(1)$ in-place |
| Stability         | Stable          |
# Aplikasi Bubble Sort
Bubble Sort digunakan jika:

- Kompleksitas tidak menjadi masalah.
- Kode yang pendek dan sederhana lebih diutamakan.
## Keunggulan dan kelemahan
### Keunggulan Bubble Sort

- Mudah dipahami dan diimplementasikan.
- Tidak memerlukan ruang memori tambahan karena sorting dilakukan secara in-place.
- Merupakan algoritma sorting yang **stabil**, sehingga elemen dengan nilai kunci yang sama tetap mempertahankan urutan relatifnya dalam output yang sudah diurutkan.

### Kelemahan Bubble Sort

- Memiliki kompleksitas waktu $O(n²)$, yang membuatnya sangat lambat untuk dataset besar.
- Hampir tidak memiliki atau memiliki aplikasi dunia nyata yang sangat terbatas. Bubble Sort lebih sering digunakan dalam akademik untuk mengajarkan berbagai metode sorting.


