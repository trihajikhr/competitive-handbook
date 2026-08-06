---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 03TH-STBS-BUC1
nama_algoritma: Bucket Sort
kategori_algoritma: sorting
kesulitan: 🥉 easy
time_complexity: 🟠 O(n) > ⚪O(n+k) > O(n²)
memory_complexity: ⚪O(n+k) ✅ → Stable
sumber: geeksforgeeks.org
date_learned: 2025-04-18T01:34:00
tags:
  - array
  - sorting
  - bucket-sort
---
#array #sorting #bucket-sort 

---
# Bucket Sort Algorithm
Bucket Sort adalah algoritma sorting yang membagi elemen ke dalam beberapa _bucket_. Setiap _bucket_ akan diurutkan secara terpisah, biasanya dengan menggunakan algoritma sorting lain (seperti **Insertion Sort**), dan hasilnya digabungkan untuk menghasilkan array yang terurut.

### Langkah-langkah Bucket Sort:

1. **Pembagian ke dalam Buckets**: Tentukan jumlah bucket yang diperlukan. Kemudian, elemen-elemen dalam array dibagi ke dalam bucket-bucket sesuai dengan interval tertentu.
    
2. **Sorting dalam Setiap Bucket**: Setiap bucket diurutkan menggunakan algoritma sorting lainnya (biasanya Insertion Sort jika ukuran bucket kecil).
    
3. **Penggabungan**: Gabungkan elemen dari semua bucket yang telah diurutkan untuk menghasilkan array yang terurut.

> Programmiz version:

**Bucket Sort** adalah algoritma pengurutan yang membagi elemen-elemen array yang belum terurut ke dalam beberapa kelompok yang disebut _bucket_. Setiap bucket kemudian diurutkan menggunakan algoritma pengurutan yang sesuai atau dengan menerapkan algoritma bucket yang sama secara rekursif.

Akhirnya, bucket-bucket yang telah diurutkan digabungkan untuk membentuk array yang terurut.

### Pendekatan Scatter-Gather

Proses bucket sort dapat dipahami sebagai pendekatan _scatter-gather_. Di sini, elemen-elemen pertama-tama disebarkan ke dalam bucket-bucket, kemudian elemen-elemen dalam setiap bucket diurutkan. Terakhir, elemen-elemen tersebut dikumpulkan dalam urutan yang benar.

![[Bucket Sort Algorithm-1.png]]
## Algoritma Bucket Sort
1. Misalkan, array inputnya adalah:
   
   ![[Bucket Sort Algorithm-2.png]]
   Buatlah sebuah array dengan ukuran 10. Setiap slot dari array ini digunakan sebagai bucket untuk menyimpan elemen-elemen.
   
   ![[Bucket Sort Algorithm-3.png]]
2. Masukkan elemen-elemen ke dalam bucket-bucket dari array. Elemen-elemen dimasukkan sesuai dengan rentang masing-masing bucket. 
   
   Pada contoh kode kami, bucket-bucket memiliki rentang mulai dari 0 hingga 1, 1 hingga 2, 2 hingga 3, ...... (n-1) hingga n. 
   
   Misalkan, sebuah elemen input adalah `0.23`. Elemen tersebut dikalikan dengan ukuran `array = 10` (yaitu, `0.23 * 10 = 2.3`). Kemudian, hasilnya diubah menjadi bilangan bulat (yaitu, `2.3 ≈ 2`). Akhirnya, `0.23` dimasukkan ke dalam **bucket-2**.
   
   ![[Bucket Sort Algorithm-4.png]]
   Begitu juga, 0.25 dimasukkan ke dalam bucket yang sama. Setiap kali, nilai floor dari angka titik desimal diambil. 
   
   Jika kita mengambil angka bulat sebagai input, kita harus membagi angka tersebut dengan interval (di sini 10) untuk mendapatkan nilai floor. 
   
   Begitu juga, elemen-elemen lainnya dimasukkan ke dalam bucket yang sesuai.
   
   ![[Bucket Sort Algorithm-5.png]]
3. Elemen-elemen dari setiap bucket diurutkan menggunakan salah satu algoritma pengurutan stabil. Di sini, kami menggunakan quicksort (fungsi bawaan).
   
   ![[Bucket Sort Algorithm-6.png]]
4. Elemen-elemen dari setiap bucket dikumpulkan. 
   
   Proses ini dilakukan dengan melakukan iterasi melalui setiap bucket dan memasukkan setiap elemen individu ke dalam array asli pada setiap siklus. Elemen dari bucket akan dihapus setelah disalin ke dalam array asli.
   
   ![[Bucket Sort Algorithm-7.png]]

## Pseudocode Bucket Sort

```bash
bucketSort()
  create N buckets each of which can hold a range of values
  for all the buckets
    initialize each bucket with 0 values
  for all the buckets
    put elements into buckets matching the range
  for all the buckets 
    sort elements in each bucket
  gather elements from each bucket
end bucketSort
```
# Contoh Algoritma Bucket Sort

Dalam C++:

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Fungsi Insertion Sort untuk mengurutkan bucket individual
void insertionSort(vector<float>& bucket) {
    for (int i = 1; i < bucket.size(); ++i) {
        float key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Fungsi untuk mengurutkan arr[] dengan ukuran n menggunakan bucket sort
void bucketSort(float arr[], int n) {
    // 1) Membuat n bucket kosong
    vector<float> b[n];

    // 2) Menempatkan elemen array ke dalam bucket yang berbeda
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }

    // 3) Mengurutkan setiap bucket menggunakan insertion sort
    for (int i = 0; i < n; i++) {
        insertionSort(b[i]);
    }

    // 4) Menggabungkan semua bucket menjadi arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b[i].size(); j++) {
            arr[index++] = b[i][j];
        }
    }
}

// Program utama untuk menguji fungsi di atas
int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);

    cout << "Array yang sudah terurut adalah \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
```
# Bucket Sort Complexity
## Time Complexity
### Best Case (Kasus Terbaik) - $O(n+k)$
Pada **best case**, jika distribusi elemen ke dalam bucket sangat merata dan masing-masing bucket berukuran kecil, maka waktu untuk mengurutkan elemen di setiap bucket menggunakan **Insertion Sort** akan lebih cepat. Dalam hal ini, **time complexity** adalah **O(n + k)**, dengan **n** adalah jumlah elemen dalam array dan **k** adalah jumlah bucket.
### Average Case (Kasus Rata-rata) -$O(n)$
Pada **kasus rata-rata**, distribusi elemen ke dalam bucket lebih merata, dan setiap bucket memiliki ukuran yang sebanding. Oleh karena itu, kompleksitas waktu secara keseluruhan adalah **O(n + k + n log n)**, di mana **n** adalah jumlah elemen, dan **k** adalah jumlah bucket. Biasanya, kompleksitas ini dominan oleh waktu sorting dalam bucket.

### Worst Case (Kasus Terburuk) - $O(n^2)$
Pada **kasus terburuk**, semua elemen mungkin berada di bucket yang sama, dan membutuhkan waktu **O(n log n)** untuk mengurutkan elemen-elemen tersebut (jika menggunakan algoritma seperti Merge Sort). Dengan demikian, kompleksitas waktu pada kasus terburuk adalah **O(n^2)**.
### Ringkasan
| Kasus        | Kompleksitas Waktu |
| ------------ | ------------------ |
| Best Case    | $O(n+k)$           |
| Average Case | $O(n)$             |
| Worst Case   | $O(n^2)$           |
## Space Complexity dan Stability
### Space Complexity
**Space complexity** Bucket Sort adalah **O(n + k)**, di mana **n** adalah jumlah elemen dalam array dan **k** adalah jumlah bucket yang digunakan. Ini mencakup ruang untuk menyimpan elemen dalam bucket dan untuk penyimpanan array output.
### Stability
Bucket Sort adalah algoritma **stabil**, karena elemen dengan nilai yang sama akan tetap mempertahankan urutan relatifnya setelah proses sorting, yang sangat berguna dalam beberapa aplikasi seperti pengurutan data dengan beberapa kunci.

## Kesimpulan
| Faktor Complexity | Nilai    |
| ----------------- | -------- |
| Best Case         | $O(n+k)$ |
| Average Case      | $O(n)$   |
| Worst Case        | $O(n^2)$ |
| Space Complexity  | $O(n+k)$ |
| Stability         | Stable   |
# Aplikasi Bucket Sort
Bucket Sort sangat efektif digunakan ketika:

- Data yang akan diurutkan memiliki distribusi yang merata atau terbatas dalam rentang tertentu.
    
- Data terdiri dari angka-angka desimal atau nilai numerik lainnya yang terdistribusi secara merata.
## Keunggulan dan kelemahan
### Keunggulan Bucket Sort
- **Efisiensi tinggi untuk distribusi merata**: Bucket Sort dapat sangat efisien untuk data yang memiliki distribusi yang merata, karena proses pembagian ke dalam bucket sangat cepat.
    
- **Stabil**: Seperti disebutkan, Bucket Sort adalah algoritma stabil, yang mempertahankan urutan relatif elemen yang memiliki nilai yang sama.
    
- **Fleksibel**: Dapat digunakan untuk data yang terdistribusi secara merata, seperti data angka desimal.
### Kelemahan Bucket Sort
- **Memerlukan ruang tambahan**: Memerlukan lebih banyak ruang penyimpanan untuk bucket, yang mungkin tidak efisien untuk data yang sangat besar.
    
- **Tidak cocok untuk distribusi data yang tidak merata**: Jika data tidak merata atau terlalu bervariasi, performa Bucket Sort dapat menurun secara signifikan.
    
- **Ketergantungan pada distribusi data**: Efisiensinya sangat tergantung pada bagaimana data didistribusikan.
## Kesimpulan
Bucket Sort adalah algoritma yang efisien untuk sorting data dengan distribusi yang merata. Namun, penggunaannya lebih terbatas pada situasi di mana data terdistribusi dengan baik. Dalam kasus tertentu, algoritma ini dapat memberikan performa yang sangat cepat, tetapi dalam situasi lain, dapat mengalami penurunan performa.