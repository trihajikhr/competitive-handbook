---
obsidianUIMode: preview
note_type: book theory
judul_materi: Introduction to Dynamic Programming
sumber:
  - cp-algorithms.com
date_learned: 2026-02-14T21:36:00
tags:
  - dynamic-programming
  - cp-algorithms
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
## Speeding up Fibonacci with Dynamic Programming (Memoization)

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

Kedua cara tersebut hampir selalu lebih lambat dibandingkan versi berbasis array untuk fungsi rekursif yang dimemoisasi secara umum. Cara alternatif dalam menyimpan state ini terutama berguna ketika kita ingin menyimpan vector atau string sebagai bagian dari ruang state.

Cara sederhana untuk menganalisis kompleksitas waktu dari sebuah fungsi rekursif yang dimemoisasi adalah:

$$
\text{pekerjaan per submasalah} \times \text{jumlah submasalah}
$$

Menggunakan binary search tree (`map` di C++) untuk menyimpan state secara teknis akan menghasilkan kompleksitas $O(n \log n)$ karena setiap *lookup* dan *insertion* memerlukan waktu $O(\log n)$ dan dengan $O(n)$ submasalah unik, kita mendapatkan total waktu $O(n \log n)$.

Pendekatan ini disebut **top-down**, karena kita bisa memanggil fungsi dengan suatu nilai query, lalu perhitungannya dimulai dari atas (nilai query tersebut) turun ke bawah (kasus dasar dari rekursi), dan membuat jalan pintas melalui **memoization** di sepanjang prosesnya.
## Bottom-up Dynamic Programming

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

Itulah dasar dari dynamic programming: Jangan mengulang pekerjaan yang sudah pernah dilakukan sebelumnya.

Salah satu trik untuk menjadi lebih baik dalam dynamic programming adalah dengan mempelajari beberapa contoh klasik.
## Classic Dynamic Programming Problems

| Nama Masalah                              | Deskripsi / Contoh                                                                                                                                                                                                                                     |
| ----------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| 0-1 Knapsack                          | Diberikan $N$ barang dengan bobot $w_i$ dan nilai $v_i$, serta kapasitas maksimal $W$. Berapa total nilai $\sum v_i$ maksimum yang bisa didapat untuk setiap subset barang berukuran $k$ ($1 \le k \le N$) dengan syarat total bobot $\sum w_i \le W$? |
| Subset Sum                            | Diberikan $N$ bilangan bulat dan sebuah target $T$. Tentukan apakah terdapat subset dari kumpulan bilangan tersebut yang jumlah elemennya tepat bernilai $T$.                                                                                          |
| LIS (Subsekuens Terpanjang Menaik)    | Diberikan sebuah array berisi $N$ bilangan bulat. Tugasmu adalah mencari LIS dalam array tersebut, yaitu subsekuens di mana setiap elemen lebih besar dari elemen sebelumnya.                                                                          |
| Menghitung Jalur dalam Array 2D       | Diberikan dimensi $N$ dan $M$. Hitung semua kemungkinan jalur berbeda dari titik $(1,1)$ ke $(N, M)$, di mana setiap langkah hanya boleh berpindah dari $(i,j)$ ke $(i+1,j)$ atau $(i,j+1)$.                                                           |
| LCS (Subsekuens Terpanjang yang Sama) | Diberikan dua buah string $s$ dan $t$. Temukan panjang string terpanjang yang merupakan subsekuens dari $s$ sekaligus subsekuens dari $t$.                                                                                                             |
| Jalur Terpanjang pada DAG             | Mencari jalur terpanjang dalam _Directed Acyclic Graph_ (Graf Berarah Tanpa Siklus).                                                                                                                                                                   |
| LPS (Subsekuens Palindrom Terpanjang) | Mencari panjang subsekuens palindrom terpanjang (LPS) dari suatu string yang diberikan.                                                                                                                                                                |
| Pemotongan Batang (Rod Cutting)       | Diberikan batang dengan panjang $n$ unit dan array berisi posisi pemotongan yang harus dilakukan. Biaya satu kali potong adalah panjang batang yang sedang dipotong. Berapa total biaya minimum untuk melakukan semua pemotongan tersebut?             |
| Edit Distance                         | Jarak edit antara dua string adalah jumlah operasi minimum yang diperlukan untuk mengubah satu string menjadi string lainnya. Operasi yang diizinkan adalah ["Tambah", "Hapus", "Ganti"].                                                              |

## Related Topics

- [Bitmask Dynamic Programming](https://cp-algorithms.com/dynamic_programming/profile-dynamics.html)
- Digit Dynamic Programming
- Dynamic Programming on Trees

Tentu saja, trik terbaik adalah praktek dan berlatih!
## Practice Problems

- [LeetCode - 1137. N-th Tribonacci Number](https://leetcode.com/problems/n-th-tribonacci-number/description/)
- [LeetCode - 118. Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/description/)
- [LeetCode - 1025. Divisor Game](https://leetcode.com/problems/divisor-game/description/)
- [Codeforces - Vacations](https://codeforces.com/problemset/problem/699/C)
- [Codeforces - Hard problem](https://codeforces.com/problemset/problem/706/C)
- [Codeforces - Zuma](https://codeforces.com/problemset/problem/607/b)
- [LeetCode - 221. Maximal Square](https://leetcode.com/problems/maximal-square/description/)
- [LeetCode - 1039. Minimum Score Triangulation of Polygon](https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/)

## DP Contests

- [Atcoder - Educational DP Contest](https://atcoder.jp/contests/dp/tasks)
- [CSES - Dynamic Programming](https://cses.fi/problemset/list/)
