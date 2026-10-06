---
obsidianUIMode: preview
note_type: book theory
judul_materi: Minimum stack / Minimum queue
sumber:
  - cp-algorithms.com
date_learned: 2026-03-07T04:40:00
tags:
  - data-structures
---
Link Sumber: [Minimum Stack / Minimum Queue - Algorithms for Competitive Programming](https://cp-algorithms.com/data_structures/stack_queue_modification.html)

---

> [!IMPORTANT]
>  

# Minimum stack / Minimum queue

Dalam artikel ini kita akan membahas tiga masalah: pertama kita akan memodifikasi `stack`[^1] sedemikian rupa sehingga memungkinkan kita untuk menemukan elemen terkecil dalam `stack` dalam $O(1)$, kemudian kita akan melakukan hal yang sama dengan `queue`[^2], dan terakhir kita akan menggunakan struktur data tersebut untuk menemukan minimum di semua subarrays dari panjang tetap dalam sebuah array dalam $O(n)$.

## Stack modification

Kita ingin memodifikasi struktur data `stack` sedemikian rupa sehingga memungkinkan untuk menemukan elemen terkecil dalam `stack` dalam waktu $O(1)$, sambil tetap mempertahankan perilaku asimtotik yang sama untuk menambah dan menghapus elemen dari `stack`. Pengingat singkat, pada `stack` kita hanya dapat menambah dan menghapus elemen di satu ujung.

Untuk melakukan ini, kita tidak hanya akan menyimpan elemen dalam `stack`, tetapi kita akan menyimpannya dalam pasangan: elemen itu sendiri dan minimum dalam `stack` mulai dari elemen ini ke bawah.

```cpp
stack<pair<int, int>> st;
```

Sangat jelas bahwa menemukan minimum di seluruh `stack` hanya terdiri dari melihat nilai `st.top().second`.

Juga jelas bahwa menambah atau menghapus elemen baru ke `stack` dapat dilakukan dalam waktu konstan.

Implementasi:

- Menambah elemen:

```cpp
int new_min = st.empty() ? new_elem : min(new_elem, st.top().second);
st.push({new_elem, new_min});
```


- Menghapus elemen:

```cpp
int removed_element = st.top().first;
st.pop();
```

- Menemukan minimum:

```cpp
int minimum = st.top().second;
```

## Queue modification (method 1)

Sekarang kita ingin mencapai operasi yang sama dengan `queue`, yaitu kita ingin menambah elemen di akhir dan menghapusnya dari depan.

Di sini kita mempertimbangkan metode sederhana untuk memodifikasi `queue`. Namun, metode ini memiliki kelemahan besar, karena `queue` yang dimodifikasi sebenarnya tidak akan menyimpan semua elemen.

Ide utamanya adalah hanya menyimpan item dalam `queue` yang diperlukan untuk menentukan nilai minimum. Yakni, kita akan menjaga `queue` dalam urutan tidak menurun atau **non-decreasing** (yaitu nilai terkecil akan disimpan di `head` atau bagian depan), dan tentu saja tidak dengan cara sembarang; minimum yang sebenarnya harus selalu terkandung dalam `queue`. Dengan cara ini, elemen terkecil akan selalu berada di depan `queue`.

Sebelum menambahkan elemen baru ke `queue`, cukup lakukan sebuah "pemotongan": kita akan menghapus semua elemen di akhir `queue` yang lebih besar dari elemen baru, dan setelah itu menambahkan elemen baru ke dalam `queue`. Dengan cara ini kita tidak merusak urutan `queue`, dan kita juga tidak akan kehilangan elemen saat ini jika elemen tersebut menjadi minimum pada langkah selanjutnya. Semua elemen yang kita hapus tidak akan pernah bisa menjadi minimum itu sendiri, jadi operasi ini diperbolehkan.

Saat kita ingin mengekstrak sebuah elemen dari depan, elemen tersebut mungkin sebenarnya tidak ada di sana (karena kita telah menghapusnya sebelumnya saat menambahkan elemen yang lebih kecil). Oleh karena itu, saat menghapus elemen dari `queue`, kita perlu mengetahui nilai dari elemen tersebut. Jika bagian depan atau `head` dari `queue` memiliki nilai yang sama, kita dapat menghapusnya dengan aman, jika tidak, kita tidak melakukan apa pun.

Perhatikan implementasi dari operasi-operasi di atas menggunakan `deque`:

```cpp
deque<int> q;
```

- Menemukan minimum:

```cpp
int minimum = q.front();
```

- Menambah elemen:

```cpp
while (!q.empty() && q.back() > new_element)
	q.pop_back();
q.push_back(new_element);
```

- Menghapus elemen:

```cpp
if (!q.empty() && q.front() == remove_element)
	q.pop_front();
```

Sangat jelas bahwa secara rata-rata semua operasi ini hanya membutuhkan waktu $O(1)$ (karena setiap elemen hanya dapat dimasukkan dan dikeluarkan satu kali).

## Queue modification (method 2)

Ini adalah modifikasi dari metode 1. Kita ingin dapat menghapus elemen tanpa harus mengetahui nilai elemen mana yang harus kita hapus. Kita dapat mencapainya dengan menyimpan indeks untuk setiap elemen dalam `queue`. Selain itu, kita juga mencatat berapa banyak elemen yang telah kita tambahkan dan hapus.

```cpp
deque<pair<int, int>> q;
int cnt_added = 0;
int cnt_removed = 0;
```

- Menemukan minimum:

```cpp
int minimum = q.front().first;
```

- Menambah elemen:

```cpp
while (!q.empty() && q.back().first > new_element)
    q.pop_back();
q.push_back({new_element, cnt_added});
cnt_added++;
```

- Menghapus elemen:

```cpp
if (!q.empty() && q.front().second == cnt_removed) 
    q.pop_front();
cnt_removed++;
```

## Queue modification (method 3)

Di sini kita mempertimbangkan cara lain untuk memodifikasi `queue` guna menemukan nilai minimum dalam $O(1)$. Cara ini agak lebih rumit untuk diimplementasikan, tetapi kali ini kita benar-benar menyimpan semua elemen. Kita juga dapat menghapus elemen dari depan tanpa perlu mengetahui nilainya.

Idenya adalah mereduksi masalah ini menjadi masalah `stack`, yang sudah kita selesaikan sebelumnya. Jadi kita hanya perlu mempelajari cara menyimulasikan sebuah `queue` menggunakan dua `stack`.

Kita membuat dua `stack`, `s1` dan `s2`. Tentu saja `stack` ini akan menggunakan bentuk yang telah dimodifikasi sehingga kita dapat menemukan minimum dalam $O(1)$. Kita akan menambahkan elemen baru ke `stack` `s1`, dan menghapus elemen dari `stack` `s2`. Jika sewaktu-waktu `stack` `s2` kosong, kita memindahkan semua elemen dari `s1` ke `s2` (yang pada dasarnya membalikkan urutan elemen-elemen tersebut). Terakhir, menemukan minimum dalam sebuah `queue` hanya melibatkan pencarian nilai minimum dari kedua `stack` tersebut.

Dengan demikian, kita melakukan semua operasi dalam $O(1)$ secara rata-rata atau **amortized** (setiap elemen akan ditambahkan satu kali ke `stack` `s1`, dipindahkan satu kali ke `s2`, dan dikeluarkan satu kali dari `s2`).

Implementasi:

```cpp
stack<pair<int, int>> s1, s2;
```

- Menemukan minimum:

```cpp
if (s1.empty() || s2.empty()) 
    minimum = s1.empty() ? s2.top().second : s1.top().second;
else
    minimum = min(s1.top().second, s2.top().second);
```

- Menambah elemen:

```cpp
int minimum = s1.empty() ? new_element : min(new_element, s1.top().second);
s1.push({new_element, minimum});
```

- Menghapus elemen:

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

## Finding the minimum for all subarrays of fixed length

Misalkan kita diberikan sebuah array $A$ dengan panjang $N$ dan sebuah nilai $M \le N$. Kita harus menemukan nilai minimum dari setiap **subarray** (_subarray_) dengan panjang $M$ dalam array ini, yaitu kita harus menemukan:

$$\min_{0 \le i \le M-1} A[i], \min_{1 \le i \le M} A[i], \min_{2 \le i \le M+1} A[i],~\dots~, \min_{N-M \le i \le N-1} A[i]$$

Kita harus menyelesaikan masalah ini dalam waktu linier, yaitu $O(n)$.

Kita dapat menggunakan salah satu dari tiga modifikasi `queue` yang telah dibahas sebelumnya untuk menyelesaikan masalah ini. Solusinya cukup jelas: kita menambahkan $M$ elemen pertama dari array ke dalam `queue`, temukan dan tampilkan nilai minimumnya, kemudian tambahkan elemen berikutnya ke `queue` dan hapus elemen pertama dari array yang sudah tidak masuk dalam jendela, temukan dan tampilkan minimumnya, dan seterusnya. Karena semua operasi pada `queue` dilakukan dalam waktu konstan secara rata-rata, kompleksitas dari seluruh algoritma akan menjadi $O(n)$.

## Practice Problems

- [Queries with Fixed Length](https://www.hackerrank.com/challenges/queries-with-fixed-length/problem)
- [Sliding Window Minimum](https://cses.fi/problemset/task/3221)
- [Binary Land](https://www.codechef.com/MAY20A/problems/BINLAND)

[^1]: Stack (tumpukan) adalah struktur data linier yang mengikuti prinsip LIFO (Last In, First Out), di mana data yang terakhir masuk akan menjadi yang pertama keluar.

[^2]: Queue (antrean) dalam struktur data adalah kumpulan data linier yang menggunakan prinsip FIFO (First In, First Out), di mana elemen yang pertama kali dimasukkan akan menjadi yang pertama kali keluar.