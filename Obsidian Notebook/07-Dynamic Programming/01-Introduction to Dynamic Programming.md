---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 07TH-DPCP-0001
nama_algoritma: fibonacci dynamic programming
kategori_algoritma: dynamic programming
kesulitan: 🥈 medium
time_complexity:
memory_complexity:
sumber:
  - cp-algorithms.com
date_learned: 2025-09-02T00:55:00
tags:
  - dynamic-programming
---
Link Sumber: [Introduction to Dynamic Programming - Algorithms for Competitive Programming](https://cp-algorithms.com/dynamic_programming/intro-to-dp.html)

---
# Introduction to Dynamic Programming

Inti dari *dynamic programming* adalah menghindari perhitungan yang berulang. Sering kali, permasalahan dynamic programming secara alami dapat diselesaikan dengan rekursi. Dalam kasus seperti itu, cara termudah adalah menuliskan solusi rekursif terlebih dahulu, kemudian menyimpan keadaan yang berulang dalam sebuah *lookup table*. Proses ini dikenal sebagai *top-down dynamic programming dengan memoization*. Perlu diperhatikan bahwa kata *memoization* dibaca seperti *memo pad* (menulis catatan), bukan *memorization* (mengingat).

Salah satu contoh paling dasar dan klasik dari proses ini adalah deret Fibonacci. Formulasi rekursifnya adalah:

$$
f(n) = f(n-1) + f(n-2)
$$

dengan syarat:

$$
n \ge 2, \quad f(0) = 0, \quad f(1) = 1
$$

Dalam C++, hal ini dapat diekspresikan sebagai:

```cpp
int f(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return f(n - 1) + f(n - 2);
}
```


Waktu eksekusi dari fungsi rekursif ini bersifat eksponensial — kira-kira $O(2^n)$ karena satu pemanggilan fungsi $(f(n))$ menghasilkan 2 pemanggilan fungsi lain dengan ukuran yang hampir sama $(f(n-1)$ dan $f(n-2))$.

<br/>

---
## 1 | Speeding up Fibonacci with Dynamic Programming (Memoization)

Fungsi rekursif kita saat ini menyelesaikan Fibonacci dalam waktu eksponensial. Ini berarti kita hanya bisa menangani nilai input yang kecil sebelum masalah menjadi terlalu sulit. Sebagai contoh, $f(29)$ menghasilkan lebih dari *1 juta* pemanggilan fungsi!

Untuk meningkatkan kecepatan, kita menyadari bahwa jumlah submasalah hanya sebesar $O(n)$. Artinya, untuk menghitung $f(n)$ kita hanya perlu mengetahui $f(n-1), f(n-2), \dots, f(0)$

Oleh karena itu, alih-alih menghitung ulang submasalah ini, kita cukup menyelesaikannya sekali dan kemudian menyimpan hasilnya dalam sebuah lookup table. Pemanggilan berikutnya akan menggunakan lookup table ini dan langsung mengembalikan hasil, sehingga menghilangkan pekerjaan eksponensial!

Setiap pemanggilan rekursif akan memeriksa ke dalam lookup table untuk melihat apakah nilai tersebut sudah dihitung. Proses ini dilakukan dalam waktu $O(1)$. Jika sudah pernah dihitung, kita cukup mengembalikan hasilnya. Jika belum, maka fungsi dihitung secara normal. Kompleksitas waktu keseluruhannya adalah $O(n)$

Ini merupakan peningkatan yang sangat besar dibandingkan algoritma eksponensial sebelumnya!

```cpp
const int MAXN = 100;
bool found[MAXN];
int memo[MAXN];

int f(int n) {
    if (found[n]) return memo[n];
    if (n == 0) return 0;
    if (n == 1) return 1;

    found[n] = true;
    return memo[n] = f(n - 1) + f(n - 2);
}
```

Dengan fungsi rekursif yang sudah dimemoisasi, $f(29)$ yang sebelumnya menghasilkan lebih dari 1 juta pemanggilan fungsi, kini hanya menghasilkan 57 pemanggilan, atau hampir *20.000 kali* lebih sedikit! Ironisnya, sekarang kita justru dibatasi oleh tipe data. $f(46)$ adalah bilangan Fibonacci terakhir yang masih dapat dimuat dalam signed 32-bit integer.

Biasanya, kita mencoba menyimpan state dalam array jika memungkinkan, karena waktu aksesnya adalah $O(1)$ dengan overhead yang minimal. Namun, secara lebih umum, kita bisa menyimpan state dengan cara apa pun yang kita suka. Contoh lainnya termasuk *binary search tree* (`map` di C++) atau *hash table* (`unordered_map` di C++).

Contohnya adalah sebagai berikut:

```cpp
unordered_map<int, int> memo;
int f(int n) {
    if (memo.count(n)) return memo[n];
    if (n == 0) return 0;
    if (n == 1) return 1;

    return memo[n] = f(n - 1) + f(n - 2);
}
```

Atau secara analoginya:

```cpp
map<int, int> memo;
int f(int n) {
    if (memo.count(n)) return memo[n];
    if (n == 0) return 0;
    if (n == 1) return 1;

    return memo[n] = f(n - 1) + f(n - 2);
}
```

Kedua cara tersebut hampir selalu lebih lambat dibandingkan versi berbasis array untuk fungsi rekursif yang dimemoisasi secara umum. Cara alternatif dalam menyimpan state ini terutama berguna ketika kita ingin menyimpan **vector** atau **string** sebagai bagian dari ruang state.

Cara sederhana untuk menganalisis kompleksitas waktu dari sebuah fungsi rekursif yang dimemoisasi adalah:

$$
\text{pekerjaan per submasalah} \times \text{jumlah submasalah}
$$

Menggunakan binary search tree (`map` di C++) untuk menyimpan state secara teknis akan menghasilkan kompleksitas $O(n \log n)$ karena setiap *lookup* dan *insertion* memerlukan waktu $O(\log n)$ dan dengan $O(n)$ submasalah unik, kita mendapatkan total waktu $O(n \log n)$.

Pendekatan ini disebut **top-down**, karena kita bisa memanggil fungsi dengan suatu nilai query, lalu perhitungannya dimulai dari atas (nilai query tersebut) turun ke bawah (kasus dasar dari rekursi), dan membuat jalan pintas melalui **memoization** di sepanjang prosesnya.

<br/>

---
## 2 | Bottom-up Dynamic Programming

Sejauh ini, kamu hanya melihat dynamic programming top-down dengan memoization. Namun, kita juga bisa menyelesaikan masalah dengan *bottom-up dynamic programming*.

Bottom-up adalah kebalikan dari top-down: kita mulai dari bawah (kasus dasar dari rekursi), lalu memperluasnya ke nilai-nilai yang lebih besar.

Untuk membuat pendekatan bottom-up pada bilangan Fibonacci, kita menginisialisasi kasus dasar dalam sebuah array. Kemudian, kita cukup menggunakan definisi rekursif pada array tersebut:

```cpp
const int MAXN = 100;
int fib[MAXN];

int f(int n) {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) fib[i] = fib[i - 1] + fib[i - 2];

    return fib[n];
}
```

Tentu saja, kode ini agak tidak efisien karena dua alasan:

1. Kita melakukan pekerjaan berulang jika fungsi dipanggil lebih dari sekali.
2. Kita hanya butuh dua nilai sebelumnya untuk menghitung elemen saat ini.

Karena itu, kita bisa mengurangi penggunaan memori dari $O(n)$ menjadi $O(1)$.

Contoh solusi bottom-up dynamic programming untuk Fibonacci yang hanya menggunakan memori $O(1)$ adalah:

```cpp
const int MAX_SAVE = 3;
int fib[MAX_SAVE];

int f(int n) {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++)
        fib[i % MAX_SAVE] = fib[(i - 1) % MAX_SAVE] + 
						    fib[(i - 2) % MAX_SAVE];

    return fib[n % MAX_SAVE];
}
```

Perhatikan bahwa kita mengubah konstanta dari `MAXN` menjadi `MAX_SAVE`. Hal ini karena jumlah elemen yang perlu kita simpan hanya 3. Nilai ini tidak lagi bergantung pada ukuran input, sehingga secara definisi adalah $O(1)$ memory. Selain itu, kita menggunakan trik umum yaitu operator modulo untuk hanya menyimpan nilai-nilai yang benar-benar diperlukan.

<br/><br/>

Itulah dasar dari dynamic programming: **Jangan mengulang pekerjaan yang sudah pernah dilakukan sebelumnya.**

Salah satu trik untuk menjadi lebih baik dalam dynamic programming adalah dengan mempelajari beberapa contoh klasik.

<br/>

---
## 3 | Classic Dynamic Programming Problems

### 0-1 Knapsack
Diberikan $W$, $N$, dan $N$ buah item dengan bobot $w_i$ dan nilai $v_i$. Pertanyaannya: berapakah nilai maksimum $\sum_{i=1}^k v_i$ untuk setiap subset item berukuran $k$ ($1 \leq k \leq N$) dengan syarat $\sum_{i=1}^k w_i \leq W$?

### Subset Sum
Diberikan $N$ bilangan bulat dan sebuah target $T$. Tentukan apakah ada subset dari himpunan tersebut yang jumlah elemennya sama dengan $T$.

### Longest Increasing Subsequence (LIS)
Diberikan sebuah array yang berisi $N$ bilangan. Tugasnya adalah menentukan subsekuens terpanjang yang setiap elemennya lebih besar daripada elemen sebelumnya.

### Counting Paths in a 2D Array
Diberikan $N$ dan $M$. Hitung semua jalur berbeda dari $(1,1)$ ke $(N,M)$, di mana setiap langkah hanya boleh dari $(i,j)$ ke $(i+1,j)$ atau $(i,j+1)$.

### Longest Common Subsequence (LCS)
Diberikan string $s$ dan $t$. Tentukan panjang subsekuens terpanjang yang merupakan subsekuens dari keduanya.

### Longest Path in a Directed Acyclic Graph (DAG)
Mencari jalur terpanjang dalam sebuah Directed Acyclic Graph (DAG).

### Longest Palindromic Subsequence
Menentukan subsekuens palindrom terpanjang dari sebuah string.

### Rod Cutting
Diberikan sebuah batang dengan panjang $n$ satuan, dan sebuah array bilangan bulat `cuts[i]` yang menunjukkan posisi pemotongan. Biaya dari satu pemotongan adalah panjang batang yang dipotong. Tentukan total biaya minimum dari semua pemotongan.

### Edit Distance
Jarak edit antara dua string adalah jumlah minimum operasi yang diperlukan untuk mengubah satu string menjadi string lainnya. Operasi yang diperbolehkan adalah **Tambah (Add)**, **Hapus (Remove)**, dan **Ganti (Replace)**.

<br/>

---
## 4 | Related Topics

- [Bitmask Dynamic Programming](https://cp-algorithms.com/dynamic_programming/profile-dynamics.html)
- Digit Dynamic Programming
- Dynamic Programming on Trees

Tentu saja, trik terbaik adalah praktek dan berlatih!
<br/>

---
## 5 | Practice Problems

- [LeetCode - 1137. N-th Tribonacci Number](https://leetcode.com/problems/n-th-tribonacci-number/description/)
- [LeetCode - 118. Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/description/)
- [LeetCode - 1025. Divisor Game](https://leetcode.com/problems/divisor-game/description/)
- [Codeforces - Vacations](https://codeforces.com/problemset/problem/699/C)
- [Codeforces - Hard problem](https://codeforces.com/problemset/problem/706/C)
- [Codeforces - Zuma](https://codeforces.com/problemset/problem/607/b)
- [LeetCode - 221. Maximal Square](https://leetcode.com/problems/maximal-square/description/)
- [LeetCode - 1039. Minimum Score Triangulation of Polygon](https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/)
<br/>

---
## 6 | DP Contests

- [Atcoder - Educational DP Contest](https://atcoder.jp/contests/dp/tasks)
- [CSES - Dynamic Programming](https://cses.fi/problemset/list/)
