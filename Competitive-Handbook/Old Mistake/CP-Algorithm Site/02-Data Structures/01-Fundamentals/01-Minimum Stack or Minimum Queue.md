---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Minimum Stack or Minimum Queue
sumber:
  - cp-algorithms.com
date_learned: 2025-09-24T07:22:00
tags:
  - data-structure
---
Link Sumber: [Minimum Stack / Minimum Queue - Algorithms for Competitive Programming](https://cp-algorithms.com/data_structures/stack_queue_modification.html)

---
# Minimum Stack or Minimum Queue

Dalam artikel ini, kita akan mempertimbangkan tiga masalah: pertama, kita akan memodifikasi **stack** sedemikian rupa sehingga memungkinkan kita untuk menemukan elemen terkecil dari stack dalam waktu **$O(1)$**, kemudian kita akan melakukan hal yang sama dengan **queue**, dan akhirnya kita akan menggunakan struktur data ini untuk menemukan minimum di semua **subarray** dengan panjang tetap dalam sebuah **array** dalam waktu **$O(n)$**.
## 1 | Modifikasi Stack

Kita ingin memodifikasi struktur data stack sedemikian rupa sehingga dimungkinkan untuk menemukan elemen terkecil dalam stack dalam waktu **$O(1)$**, sambil mempertahankan perilaku asimtotik yang sama untuk menambahkan dan menghapus elemen dari stack. Sebagai pengingat singkat, pada stack kita hanya menambah dan menghapus elemen di satu ujung.

Untuk melakukan ini, kita tidak hanya akan menyimpan elemen di stack, tetapi kita akan menyimpannya dalam **pasangan (pair)**: elemen itu sendiri dan nilai minimum dalam stack yang dimulai dari elemen ini dan ke bawah.

```cpp
stack<pair<int, int>> st;
```

Jelas bahwa menemukan minimum di seluruh stack hanya terdiri dari melihat nilai `stack.top().second`.

Juga jelas bahwa menambahkan atau menghapus elemen baru ke stack dapat dilakukan dalam waktu konstan.

**Implementasi:**

  * **Menambahkan elemen:**
```cpp
int new_min = st.empty() ? new_elem : min(new_elem, st.top().second);
st.push({new_elem, new_min});
```
  * **Menghapus elemen:**
```cpp
int removed_element = st.top().first;
st.pop();
```
  * **Menemukan minimum:**
```cpp
int minimum = st.top().second;
```

## 2 | Modifikasi Antrean (Queue) (Metode 1)

Sekarang kita ingin melakukan operasi yang sama pada **queue**—yaitu, menambahkan elemen di belakang dan menghapusnya dari depan—namun dengan metode yang berbeda. Metode ini memiliki kelemahan besar: antrean yang dimodifikasi ini tidak akan menyimpan semua elemen.

Ide utamanya adalah hanya menyimpan elemen-elemen yang diperlukan untuk menentukan nilai minimum. Kita akan menjaga antrean dalam urutan **non-menurun**, yang berarti nilai terkecil akan selalu berada di bagian **depan (head)** antrean. Tentu saja, minimum sebenarnya harus selalu terkandung dalam antrean. Dengan cara ini, elemen terkecil akan selalu ada di `q.front()`.

Sebelum menambahkan elemen baru ke antrean, kita akan melakukan "pemotongan": kita akan **menghapus semua elemen di belakang (tail) antrean yang lebih besar** dari elemen baru tersebut. Setelah itu, kita menambahkan elemen baru. Dengan begini, kita tidak merusak urutan antrean dan tidak akan kehilangan elemen saat ini jika suatu saat nanti ia menjadi minimum. Semua elemen yang kita hapus sebelumnya tidak akan pernah bisa menjadi minimum itu sendiri, jadi operasi ini valid.

Saat kita ingin mengeluarkan elemen dari depan, elemen tersebut mungkin sudah tidak ada (karena kita telah menghapusnya saat menambahkan elemen yang lebih kecil). Oleh karena itu, ketika menghapus elemen dari antrean, kita perlu mengetahui nilainya. Jika elemen di depan antrean memiliki nilai yang sama, kita bisa menghapusnya dengan aman; jika tidak, kita tidak melakukan apa-apa.

Berikut adalah implementasi dari operasi-operasi di atas, menggunakan `deque` (double-ended queue):

```cpp
deque<int> q;
```

**Menemukan minimum:**

```cpp
int minimum = q.front();
```

**Menambahkan elemen:**

```cpp
while (!q.empty() && q.back() > new_element)
    q.pop_back();
q.push_back(new_element);
```

**Menghapus elemen:**

```cpp
if (!q.empty() && q.front() == remove_element)
    q.pop_front();
```

Jelas bahwa rata-rata, semua operasi ini hanya membutuhkan waktu **$O(1)$** karena setiap elemen hanya dapat didorong (**pushed**) dan dikeluarkan (**popped**) sekali.

## 3 | Modifikasi Antrean (Queue) (Metode 2)

Ini adalah modifikasi dari **Metode 1**, yang memungkinkan kita untuk menghapus elemen dari antrean tanpa perlu mengetahui nilai elemen yang akan dihapus. Kita bisa mencapai ini dengan menyimpan **indeks** untuk setiap elemen di dalam antrean, dan kita juga melacak berapa banyak elemen yang telah ditambahkan (`cnt_added`) dan dihapus (`cnt_removed`).

Dengan menggunakan pasangan (`pair`), kita akan menyimpan elemen itu sendiri (`.first`) dan indeksnya (`.second`) di dalam sebuah `deque`.

```cpp
deque<pair<int, int>> q;
int cnt_added = 0;
int cnt_removed = 0;
```

**Implementasi**

  * **Menemukan minimum:**
    Nilai minimum selalu berada di bagian depan antrean, jadi kita cukup mengakses nilai elemen pertama (`.first`) dari pasangan di `q.front()`.

    ```cpp
    int minimum = q.front().first;
    ```

  * **Menambahkan elemen:**
    Sama seperti Metode 1, kita menghapus semua elemen di bagian belakang (`.back()`) yang lebih besar dari elemen baru. Setelah itu, kita menambahkan pasangan yang terdiri dari elemen baru dan indeks `cnt_added` ke dalam antrean. Terakhir, kita tingkatkan `cnt_added` untuk elemen berikutnya.

    ```cpp
    while (!q.empty() && q.back().first > new_element)
        q.pop_back();
    q.push_back({new_element, cnt_added});
    cnt_added++;
    ```

  * **Menghapus elemen:**
    Kita tidak lagi perlu mengetahui nilai elemen yang akan dihapus. Kita hanya perlu memeriksa apakah elemen di bagian depan (`q.front()`) memiliki indeks yang sama dengan jumlah elemen yang sudah dihapus (`cnt_removed`). Jika cocok, kita tahu bahwa elemen tersebut adalah yang seharusnya dihapus, dan kita bisa melakukannya. Setelah itu, kita tingkatkan `cnt_removed` untuk melacak penghapusan berikutnya.

    ```cpp
    if (!q.empty() && q.front().second == cnt_removed)
        q.pop_front();
    cnt_removed++;
    ```

    Pendekatan ini menjamin bahwa kita hanya menghapus elemen yang benar-benar ada di depan antrean, terlepas dari nilai-nilainya.
## 4 | Modifikasi Antrean (Queue) (Metode 3)

Metode ini, meskipun lebih kompleks, memungkinkan kita untuk menemukan minimum dalam antrean dengan waktu **$O(1)$** sambil menyimpan **semua** elemen dan menghapus elemen dari depan tanpa mengetahui nilainya. Ide dasarnya adalah **mereplikasi perilaku antrean menggunakan dua tumpukan (stacks)** yang telah dimodifikasi sebelumnya.

Kita menggunakan dua tumpukan, `s1` dan `s2`. Kedua tumpukan ini adalah tumpukan yang telah dimodifikasi, sehingga kita bisa menemukan minimum di masing-masing tumpukan dalam waktu **$O(1)$**.

1.  **Penambahan Elemen (Add Element):** Elemen baru selalu ditambahkan ke tumpukan `s1`.
2.  **Penghapusan Elemen (Removing an Element):** Elemen dihapus dari tumpukan `s2`.
3.  **Transfer Elemen:** Jika `s2` kosong dan kita perlu menghapus elemen, kita akan memindahkan semua elemen dari `s1` ke `s2`. Proses pemindahan ini secara efektif membalik urutan elemen, sehingga elemen yang paling lama di `s1` (yang berada di dasar tumpukan) menjadi yang teratas di `s2`. Ini meniru perilaku FIFO (First-In, First-Out) dari antrean.
4.  **Menemukan Minimum:** Nilai minimum dari seluruh antrean adalah nilai minimum dari `s1` dan `s2`.

Dengan metode ini, setiap elemen akan ditambahkan ke `s1` satu kali, dipindahkan ke `s2` satu kali, dan dikeluarkan dari `s2` satu kali. Oleh karena itu, semua operasi memiliki kompleksitas waktu **$O(1)$** secara rata-rata.

**Implementasi**

```cpp
stack<pair<int, int>> s1, s2;
```

  * **Menemukan minimum:**
    Kita harus memeriksa kedua tumpukan. Jika salah satu kosong, minimumnya adalah `s1.top().second` atau `s2.top().second`. Jika keduanya berisi elemen, minimumnya adalah nilai terkecil dari keduanya.

    ```cpp
    if (s1.empty() || s2.empty())
        minimum = s1.empty() ? s2.top().second : s1.top().second;
    else
        minimum = min(s1.top().second, s2.top().second);
    ```

  * **Menambahkan elemen:**
    Elemen baru ditambahkan ke `s1`. Minimum baru dihitung berdasarkan nilai elemen baru dan minimum saat ini di `s1`.

    ```cpp
    int minimum = s1.empty() ? new_element : min(new_element, s1.top().second);
    s1.push({new_element, minimum});
    ```

  * **Menghapus elemen:**
    Pertama, kita periksa apakah `s2` kosong. Jika ya, kita pindahkan semua elemen dari `s1` ke `s2` dengan urutan terbalik, sambil memperbarui minimum di setiap langkah. Setelah itu, kita bisa dengan aman mengeluarkan elemen dari `s2`.

    ```cpp
    if (s2.empty()) {
        while (!s1.empty()) {
            int element = s1.top().first;
            s1.pop();
            int minimum = s2.empty() ? element : min(element, s2.top().second);
            s2.push({element, minimum});
        }
    }
    int remove_element = s2.top().first;
    s2.pop();
    ```

## 5 | Mencari Minimum untuk Semua Sub-array dengan Panjang Tetap

Diberikan sebuah **array** $A$ dengan panjang $N$ dan panjang sub-array tetap $M \le N$. Kita perlu menemukan nilai minimum dari setiap sub-array dengan panjang $M$. Dengan kata lain, kita harus menemukan:

$$\min_{0 \le i \le M-1} A[i], \min_{1 \le i \le M} A[i], \min_{2 \le i \le M+1} A[i], \dots, \min_{N-M \le i \le N-1} A[i]$$

Untuk menyelesaikan masalah ini secara efisien, yaitu dalam waktu linear **$O(n)$**, kita dapat memanfaatkan salah satu dari tiga modifikasi **queue** yang telah dibahas sebelumnya.
### 5.1 | Strategi Penyelesaian

Solusinya sangat jelas dan intuitif: kita akan menggunakan **sliding window** (jendela geser) yang berukuran $M$. Kita akan memproses array dari awal hingga akhir, menjaga jendela geser ini selalu memiliki $M$ elemen.

1.  **Inisialisasi**: Pertama, kita tambahkan $M$ elemen pertama dari array $A$ ke dalam **queue** yang telah dimodifikasi (misalnya, menggunakan **Metode 3** yang mampu menyimpan semua elemen).
2.  **Iterasi Pertama**: Setelah $M$ elemen pertama ditambahkan, kita cari dan cetak nilai minimumnya. Operasi ini membutuhkan waktu **$O(1)$** karena modifikasi queue.
3.  **Jendela Geser**: Setelah itu, kita ulangi proses berikut untuk sisa elemen array:
    * **Tambahkan Elemen Baru**: Tambahkan elemen berikutnya dari array (di luar jendela saat ini) ke dalam queue.
    * **Hapus Elemen Lama**: Hapus elemen pertama dari array (yang sekarang berada di luar jendela) dari queue.
    * **Cari Minimum**: Cari dan cetak nilai minimum baru dari queue.

Karena setiap operasi (menambahkan dan menghapus elemen, serta mencari minimum) pada queue yang dimodifikasi ini memiliki kompleksitas waktu **$O(1)$** secara rata-rata, maka kompleksitas waktu keseluruhan dari algoritma ini adalah **$O(n)$**.

Pendekatan ini sangat efisien karena kita tidak perlu memindai setiap sub-array secara terpisah, yang akan menghasilkan kompleksitas **$O(n \cdot M)$**. Sebaliknya, kita hanya melakukan satu lintasan (pass) melalui array, menjaga struktur data kita selalu *up-to-date* dengan jendela yang bergeser.