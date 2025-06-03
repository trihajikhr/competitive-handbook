---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 03TH-STBS-V001
nama_algoritma: bubble sort algorithm
kategori_algoritma: sorting
kesulitan: 🥉 easy
time_complexity: 🟠 O(n) >  🟣 O(n²) > 🟣 O(n²)
memory_complexity: 🟢 O(1) ✅ → Stable
sumber: "buku: CP handbook by Antti Laaksonen & chatgpt.com"
date_learned: 2025-06-01T08:38:00
tags:
  - sorting
  - bubble-sort
  - array
---
---
# Variasi Bubble Sort

## 1 | Basic Bubble Sort (Naïve)
Versi paling dasar: bandingkan pasangan elemen berurutan dan tukar jika perlu. Diulang sebanyak `n-1` kali tanpa cek apakah array sudah urut. Pendekatan ini lebih cocok untuk pengenalan algoritma sorting untuk para pemula, karena mudah untuk dipahami. Namun tidak cocok dibandingkan variasi lain, karena ada variasi atau pendekatan yang lebih efisien, terutama *Optimized Bubble Sort*.

```cpp
void bubbleSort(vector<int> & arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
```

Atau secara lengkap:

```cpp
#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int> & arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for(auto&x:arr) cin >> x;
    bubbleSort(arr);

    for(const auto&x:arr) cout << x << " ";
    return 0;
}
```
## 2 | Optimized Bubble Sort (Early Exit) / Standard Variation
Bubble sort yang dioptimalkan menggunakan bantuan variabel boolean `swapped`, untuk menandai apakah array sudah terurut atau belum. Jika sudah terurut, maka bubble sort hanya akan melakukan $O(n)$ operasi, dimana operasi yang dilakukan hanya mengecek apakah suatu array sudah terurut atau belum, membuat program sorting berhenti lebih cepat. Tanpa menggunakan bantuan flag ini, baik array belum terurut atau sudah, akan tetap dilakukan $O(n^2)$ operasi, yang mana kurang efisien.

### 2.1 | Variasi penulisan array lama 
Jika kamu masih menggunakan pendeklarasian array dengan `int arr[]`, maka pendekatan ini bisa digunakan:

```cpp
#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){

    for(int i=0;i<n-1;i++){
        bool swapped=false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped=true;
            }
        }
        if(!swapped) break;
    }
}

int main() {
    int n; cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    bubbleSort(arr,n);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
```

Penggunaan `int arr[]` sebenarnya kurang tepat jika digunakan dalam C++ modern. Selain itu, penggunaan `int arr[n];` adalah **Variable Length Array (VLA)**, yang hanya valid di C99 (C, bukan C++). Di C++, standar resmi **tidak mendukung VLA**. Beberapa compiler seperti GCC mengizinkan ini sebagai ekstensi, tapi tidak portable.

Ada satu hal yang perlu diketahui lagi, ketika kita menggunakan array jenis ini, kita tidak bisa mengirimkan array sebagai agumen, lalu menghitung ukuran array di fungsi yang dipanggil. 

Misal didalam fungsi `bubbleSort`, aku menggunakan sintaks ini untuk menghitung ukuran array, ini tidak akan berhasil:

```cpp
int n = sizeof(arr)/sizeof(arr[0]);
```

Fungsi `bubbleSort` menerima parameter `int arr[]`, yang **sebenarnya setara dengan `int* arr`**. Maka dari itu, saat kamu menulis kode diatas, itu sebenarnya menjadi:

```cpp
int n = sizeof(int*) / sizeof(int);
```

Misalnya pada sistem 64-bit:

- `sizeof(int*)` = 8 bytes
- `sizeof(int)` = 4 bytes
- Maka hasilnya adalah `8 / 4 = 2`, yang **jelas salah**, karena jumlah elemen asli tidak 2.

Oleh karena itu, solusinya adalah dengan mengirimkan ukuran array sebagai argumen dan parameter juga, sehingga kita tidak perlu menghitung ukuran array di fungsi. ALternatif lain yang lebih cocok, adalah dengan menggunakan vector.

> Penggunaan `int arr[]` ini dimaksudkan untuk jaga-jaga, jika kita diminta menggunakan C++ versi lama, seperti Dev C++.

### 2.2 | Variasi Vector
Vector adalah data structure, atau struktur data array, yang memiliki sifat dinamis, artinya kita bisa menghapus elemen yang ada didalam array, dan menambahkan elemen ke dalam array. Penggunaan vector lebih cocok untuk C++ modern, karena didukung oleh banyak fungsi bawaan, yang membuatnya lebih mudah dan efisien untuk kebanyakan kasus.

```cpp
void bubbleSort(vector<int> & arr){

    int n=arr.size();

    for(int i=0;i<n-1;i++){
        bool swapped=false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped=true;
            }
        }
        if(!swapped) break;
    }
}
```

Penggunaan vector juga lebih disarankan untuk kasus-kasus sorting seperti ini. Berikut contohnya:

```cpp
#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int> & arr){

    int n=arr.size();

    for(int i=0;i<n-1;i++){
        bool swapped=false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped=true;
            }
        }
        if(!swapped) break;
    }
}

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for(auto&x:arr) cin >> x;
    bubbleSort(arr);

    for(const auto&x:arr) cout << x << " ";
    return 0;
}
```

Saat menggunakan vector, kita bisa menghitung ukuan array tersebut didalam fungsi yang dipanggil, seperti pada syntax berikut:

```cpp
int n=arr.size();
```

Selain itu, ada beberapa hal yang harus diperhatikan ketika kita memutuskan menggunakan vector dalam kode buatan kita. Saat memanggil vector dalam parameter, penting untuk menggunakan syntax `&`, atau *reference*, dimana artinya kita mengakses array secara *langsung*, yang akan membuat array asli ikut berubah. Tanpa menggunakan *reference*, fungsi akan menggunakan salinan dari array, dan array hanya akan terurut jika kita mengoutputkanya atau mengoperasikanya didalam fungsi. Diluar fungsi, array seakan tidak tersentuh, tidak tersorting.

Gunakan ini jika ingin array asli berubah:

```cpp
void bubbleSort(vector<int> & arr) {  }
```

Bukan ini:

```cpp
void bubbleSort(vector<int> arr) {  }
```

Karena kita menggunakan vector, kita juga bisa menggunakan perulangan ringkas yaitu `for-each loop`, perulangan ini lebih pendek, dan cepat digunakan, asal ukuran array sudah ditentukan diawal. Untuk penjelasan tentang perulangan ini, pelajari di [[For-each loop]].

## 3 | Reverse Bubble Sort (Descending Order)
Mengubah tanda pembanding untuk mengurutkan dari besar ke kecil (descending order). Kita cukup melakukan perubahan pada beberapa syntax.

```cpp
void bubbleSort(vector<int> & arr){

    int n=arr.size();

    for(int i=0;i<n-1;i++){
        bool swapped=false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped=true;
            }
        }
        if(!swapped) break;
    }
}
```

Rubah syntax menjadi seperti ini:
```cpp
if(arr[j]<arr[j+1]){  // mengurutkan secara descending
	swap(arr[j], arr[j+1]);
	swapped=true;
}
```

Maka, algoritma sorting akan mengurutkan dari terbesar ke terkecil.

## 4 | Cocktail Shaker Sort (Bidirectional Bubble Sort)

**Cocktail Shaker Sort**, atau sering disebut **Bidirectional Bubble Sort**, adalah variasi dari algoritma Bubble Sort yang bekerja dengan cara bolak-balik. Jika Bubble Sort hanya menyapu array dari kiri ke kanan untuk menempatkan elemen terbesar di ujung, Cocktail Shaker Sort menambahkan langkah sebaliknya—dari kanan ke kiri—untuk sekaligus menempatkan elemen terkecil ke depan. Karena gerakannya dua arah, algoritma ini mirip seperti gerakan mengocok minuman dalam shaker, itulah asal namanya.

Cara kerja dasarnya dimulai dengan membandingkan elemen-elemen secara berurutan dari kiri ke kanan, seperti pada Bubble Sort. Jika ditemukan pasangan elemen yang salah urut, maka dilakukan pertukaran. Setelah sampai di ujung kanan, proses dilanjutkan dari arah sebaliknya, yaitu dari kanan ke kiri. Langkah ini akan menempatkan elemen terkecil ke posisi awal. Kedua arah ini terus dilakukan bergantian hingga tidak ada lagi pertukaran yang terjadi, yang berarti array sudah terurut.

Algoritma ini bekerja lebih baik dibanding Bubble Sort biasa ketika data hampir terurut tetapi ada elemen kecil yang berada di ujung kanan atau elemen besar yang ada di ujung kiri. Karena pergerakannya dua arah, elemen-elemen ekstrem bisa lebih cepat mencapai posisi yang seharusnya.

### ⚙️ Bagaimana Cara Kerjanya?

Bayangkan kamu punya array:  
`[5, 1, 4, 2, 8]`

#### Langkah 1: Kiri ke kanan

- Bandingkan dan swap jika perlu:
    - 5 > 1 → swap → `[1, 5, 4, 2, 8]`
    - 5 > 4 → swap → `[1, 4, 5, 2, 8]`
    - 5 > 2 → swap → `[1, 4, 2, 5, 8]`
    - 5 < 8 → tidak swap

Elemen **terbesar** sudah berada di posisi terakhir.

#### Langkah 2: Kanan ke kiri

- Bandingkan mundur:
    - 5 > 2 → swap → `[1, 4, 2, 5, 8]`
    - 4 > 2 → swap → `[1, 2, 4, 5, 8]`
    - 1 < 2 → tidak swap

Elemen **terkecil** sekarang berada di awal.
➡️ Lanjutkan proses sampai tidak ada pertukaran.

---

Contoh implementasi sederhananya dalam C++ bisa seperti ini:

```cpp
void cocktailShakerSort(vector<int> & arr, int n) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while(swapped) {
        swapped = false;

        // kiri ke kanan
        for(int i = start; i < end; ++i) {
            if(arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
                swapped = true;
            }
        }

        if(!swapped) break;
        swapped = false;
        --end;

        // kanan ke kiri
        for(int i = end - 1; i >= start; --i) {
            if(arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
                swapped = true;
            }
        }

        ++start;
    }
}
```

Secara kompleksitas, dalam kasus terbaik saat array sudah terurut, algoritma ini bisa selesai dalam waktu linier $O(n)$ karena akan langsung mendeteksi bahwa tidak ada pertukaran yang perlu dilakukan. Namun, dalam kasus terburuk dan rata-rata, performanya tetap $O(n²)$ seperti Bubble Sort.

Meskipun tidak seefisien algoritma seperti Merge Sort atau Quick Sort, *Cocktail Shaker Sort* cukup menarik untuk dipelajari karena memperkenalkan ide penyapuan dua arah yang sederhana namun efektif untuk data yang hampir terurut.

## 5 | Recursive Bubble Sort
**Recursive Bubble Sort** adalah bentuk rekursif dari algoritma Bubble Sort biasa. Secara prinsip, Bubble Sort bekerja dengan membandingkan pasangan-pasangan elemen yang bersebelahan dan menempatkan elemen terbesar ke posisi akhir array di setiap putaran. Versi iteratif melakukan ini dengan menggunakan dua buah loop `for`, sedangkan versi rekursif menggantikan perulangan luar dengan pemanggilan fungsi itu sendiri secara berulang.

Cara kerjanya cukup sederhana
1. Dalam satu panggilan fungsi, kita menjalankan satu putaran perbandingan dan pertukaran dari elemen-elemen dalam array, sama seperti yang dilakukan oleh perulangan luar pada versi iteratif. 
2. Setelah elemen terbesar sudah dipastikan berada di akhir, kita panggil fungsi tersebut lagi secara rekursif, kali ini dengan panjang array dikurangi satu, karena elemen terakhir sudah pasti berada di tempat yang benar. 
3. Proses ini terus berlanjut hingga ukuran array yang perlu diurutkan tinggal satu, artinya semua elemen sudah terurut.

Berikut adalah contoh implementasinya dalam bahasa C++:

```cpp
void recursiveBubbleSort(vector<int> & arr, int n) {
    if (n == 1) return;

    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }

    recursiveBubbleSort(arr, n - 1);
}
```

Fungsi `recursiveBubbleSort` pertama-tama memeriksa apakah panjang array `n` tinggal satu. Jika ya, maka pengurutan selesai. Jika belum, ia melakukan satu pass pengurutan, yaitu membandingkan dan menukar semua elemen dari indeks 0 hingga `n-2`. Kemudian fungsi ini memanggil dirinya sendiri dengan parameter `n-1` untuk mengulangi proses pada bagian array yang tersisa (karena elemen terbesar sudah berada di posisi ke-`n-1`).

Dari sisi performa, Recursive Bubble Sort tetap memiliki kompleksitas waktu $O(n²)$, sama seperti versi iteratif. Namun, karena menggunakan rekursi, algoritma ini juga menambah beban pada **stack memory**, dan bisa menyebabkan **stack overflow** jika digunakan pada array yang sangat besar. Oleh karena itu, implementasi rekursif ini lebih cocok untuk pembelajaran dan bukan untuk pemrosesan data skala besar.

Recursive Bubble Sort menarik karena menunjukkan bagaimana algoritma iteratif bisa ditulis dalam bentuk rekursif tanpa mengubah logika dasarnya. Cocok untuk latihan memahami konsep rekursi secara praktis.

## 6 | Bubble Sort dengan Last Swapped Index

**Bubble Sort dengan Last Swapped Index** adalah variasi dari algoritma Bubble Sort yang mengoptimalkan jumlah perbandingan yang dilakukan pada setiap iterasi. Pada versi Bubble Sort biasa, kita terus melakukan perbandingan hingga elemen-elemen sebelum `n - i - 1`, meskipun sebagian besar array sebenarnya sudah terurut. Nah, pendekatan _Last Swapped Index_ berusaha memperbaiki hal ini dengan cara mencatat posisi terakhir terjadinya pertukaran (swap).

Idenya sederhana namun efektif: selama proses penyapuan array dari kiri ke kanan, kita perhatikan indeks terakhir di mana dua elemen ditukar. Karena elemen-elemen setelah indeks tersebut sudah berada di posisi yang benar, maka pada iterasi berikutnya, kita cukup melakukan perbandingan sampai batas indeks itu saja. Ini menghindarkan kita dari melakukan perbandingan yang sia-sia pada bagian array yang sudah terurut sempurna.

Cara kerjanya seperti ini: 
1. Kita mulai dari indeks awal dan bandingkan elemen bersebelahan satu per satu. 
2. Jika perlu, kita tukar dan catat posisi terakhir swap ke dalam sebuah variabel, misalnya `lastSwap`. 
3. Setelah selesai satu pass, kita tahu bahwa semua elemen setelah indeks `lastSwap` sudah berada di posisi yang tepat. Maka, pada iterasi berikutnya, kita hanya perlu menyapu hingga indeks tersebut.

Berikut contoh implementasinya dalam bahasa C++:

```cpp
void bubbleSortOptimized(vector<int> & arr, int n) {
    int end = n;
    while (end > 0) {
        int lastSwap = 0;
        for (int i = 0; i < end - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                lastSwap = i + 1;
            }
        }
        end = lastSwap;
    }
}
```

Pada implementasi di atas, variabel `end` menyimpan batas atas array yang perlu disapu. Setelah setiap iterasi, `end` diperbarui menjadi `lastSwap`, yaitu posisi terakhir swap. Jika pada satu putaran tidak ada pertukaran sama sekali, maka `lastSwap` tetap nol, dan algoritma akan berhenti, karena berarti array sudah sepenuhnya terurut.

Secara kompleksitas waktu, versi ini tetap memiliki kompleksitas $O(n²)$ dalam kasus terburuk (misalnya saat array terbalik sepenuhnya), namun pada kasus terbaik (ketika array sudah hampir terurut), ia bisa lebih cepat karena mengurangi jumlah perbandingan yang tidak perlu.

Dengan penambahan kecil namun cerdas ini, algoritma Bubble Sort menjadi sedikit lebih efisien tanpa kehilangan kesederhanaannya. Sangat cocok untuk digunakan pada array berukuran kecil atau ketika data sudah hampir terurut.
