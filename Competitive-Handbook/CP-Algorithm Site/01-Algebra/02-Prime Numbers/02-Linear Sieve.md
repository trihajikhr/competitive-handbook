---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Linear Sieve
sumber:
  - cp-algorithms.com
date_learned: 2025-10-26T10:05:00
tags:
  - cp-algorithms
---
Link Sumber: [Linear Sieve - Algorithms for Competitive Programming](https://cp-algorithms.com/algebra/prime-sieve-linear.html)

---
# Linear Sieve

Diberikan sebuah bilangan $n$, temukan semua bilangan prima dalam segmen $[2;n]$.

Cara standar untuk menyelesaikan tugas ini adalah dengan menggunakan [Sieve of Eratosthenes](https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html). Algoritma ini sangat sederhana, namun memiliki waktu runtime $O(n \log \log n)$.

Meskipun banyak algoritma yang dikenal dengan waktu runtime sublinear (yaitu $o(n)$), algoritma yang dijelaskan di bawah ini menarik karena kesederhanaannya: ia tidak lebih kompleks daripada sieve of Eratosthenes klasik.

Selain itu, algoritma yang diberikan di sini menghitung **faktorisasi semua bilangan** dalam segmen $[2; n]$ sebagai efek samping (*side effect*), dan itu dapat membantu dalam banyak aplikasi praktis.

Kelemahan algoritma ini terletak pada penggunaan memori yang lebih besar daripada sieve of Eratosthenes klasik: ia membutuhkan **array** $n$ bilangan, sementara untuk sieve of Eratosthenes klasik sudah cukup menggunakan $n$ bit memori (yang 32 kali lebih sedikit).

Oleh karena itu, masuk akal untuk menggunakan algoritma yang dijelaskan ini hanya untuk bilangan dengan orde $10^7$ dan tidak lebih besar.

Algoritma ini adalah karya Paul Pritchard. Ini adalah varian dari Algoritma 3.3 dalam (Pritchard, 1987: lihat referensi di akhir artikel).


## 1 | Algorithm

Tujuan kita adalah untuk menghitung **faktor prima minimum** $lp [i]$ untuk setiap bilangan $i$ dalam segmen $[2; n]$.

Selain itu, kita perlu menyimpan daftar semua bilangan prima yang ditemukan—mari kita sebut $pr []$.

Kita akan menginisialisasi nilai $lp [i]$ dengan nol, yang berarti kita berasumsi bahwa semua bilangan adalah prima. Selama eksekusi algoritma, **array** ini akan diisi secara bertahap.

Sekarang kita akan melalui bilangan dari $2$ hingga $n$. Kita memiliki dua kasus untuk bilangan $i$ saat ini:

* $lp[i] = 0$ — itu berarti $i$ adalah **bilangan prima**, yaitu kita belum menemukan faktor yang lebih kecil darinya. Oleh karena itu, kita menetapkan $lp [i] = i$ dan menambahkan $i$ ke akhir daftar $pr[]$.

<br/>

* $lp[i] \neq 0$ — itu berarti $i$ adalah **bilangan komposit**, dan faktor prima minimumnya adalah $lp [i]$.

Dalam kedua kasus, kita memperbarui nilai $lp []$ untuk bilangan-bilangan yang habis dibagi oleh $i$. Namun, tujuan kita adalah mempelajari cara melakukannya sedemikian rupa sehingga kita menetapkan nilai $lp []$ paling banyak **satu kali** untuk setiap bilangan. Kita dapat melakukannya sebagai berikut:

Mari kita pertimbangkan bilangan $x_j = i \cdot p_j$, di mana $p_j$ adalah semua bilangan prima yang kurang dari atau sama dengan $lp [i]$ (inilah sebabnya kita perlu menyimpan daftar semua bilangan prima). 

Kita akan menetapkan nilai baru $lp [x_j] = p_j$ untuk semua bilangan dengan bentuk ini.

Bukti kebenaran (*proof of correctness*) algoritma ini dan waktu *runtime* dapat ditemukan setelah implementasi.

## 2 | Implementation

```cpp
const int N = 10000000;
vector<int> lp(N+1);
vector<int> pr;

for (int i=2; i <= N; ++i) {
    if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back(i);
    }
    for (int j = 0; i * pr[j] <= N; ++j) {
        lp[i * pr[j]] = pr[j];
        if (pr[j] == lp[i]) {
            break;
        }
    }
}
```

## 3 | Correctness Proof

Kita perlu membuktikan bahwa algoritma menetapkan semua nilai $lp []$ dengan benar, dan bahwa setiap nilai akan ditetapkan **tepat satu kali**. Dengan demikian, algoritma akan memiliki waktu runtime linear, karena semua aksi algoritma yang tersisa, jelas, bekerja dalam $O (n)$.

Perhatikan bahwa setiap bilangan $i$ memiliki representasi yang tepat satu dalam bentuk:
$$i = lp [i] \cdot x,$$
di mana $lp [i]$ adalah faktor prima minimal dari $i$, dan bilangan $x$ tidak memiliki faktor prima yang lebih kecil dari $lp [i]$, yaitu:
$$lp [i] \le lp [x].$$

Sekarang, mari kita bandingkan hal ini dengan tindakan algoritma kita: pada dasarnya, untuk setiap $x$, algoritma melalui semua bilangan prima yang dapat dikalikan dengannya, yaitu semua bilangan prima hingga $lp [x]$ secara inklusif, untuk mendapatkan bilangan dalam bentuk yang diberikan di atas.

Oleh karena itu, algoritma akan melalui setiap bilangan komposit **tepat satu kali**, menetapkan nilai $lp []$ yang benar di sana. **Q.E.D.** (*Quod Erat Demonstrandum* - Yang Telah Dibuktikan).

## 4 | Runtime and Memory

Meskipun waktu runtime $O(n)$ lebih baik daripada $O(n \log \log n)$ dari sieve of Eratosthenes klasik, perbedaan di antara keduanya tidak terlalu besar. Dalam praktiknya, *linear sieve* berjalan kira-kira sama cepatnya dengan implementasi tipikal sieve of Eratosthenes.

Dibandingkan dengan versi sieve of Eratosthenes yang sudah dioptimasi, misalnya *segmented sieve*, algoritma ini jauh lebih lambat.

Mempertimbangkan kebutuhan memori algoritma ini—sebuah **array** $lp []$ dengan panjang $n$, dan sebuah **array** $pr []$ dengan panjang $\frac n {\ln n}$—algoritma ini tampaknya lebih buruk daripada sieve of Eratosthenes klasik dalam segala aspek.

Namun, nilai unggulnya (*redeeming quality*) adalah bahwa algoritma ini menghitung **array** $lp []$, yang memungkinkan kita untuk menemukan **faktorisasi** (*factorization*) dari bilangan apa pun dalam segmen $[2; n]$ dalam waktu seorde ukuran faktorisasi ini. Selain itu, hanya dengan menggunakan satu **array** tambahan, kita dapat menghindari operasi pembagian ketika mencari faktorisasi.

Mengetahui faktorisasi semua bilangan sangat berguna untuk beberapa tugas, dan algoritma ini adalah salah satu dari sedikit algoritma yang memungkinkan untuk menemukannya dalam waktu linear (*linear time*).

## 5 | References

- Paul Pritchard, **Linear Prime-Number Sieves: a Family Tree**, Science of Computer Programming, vol. 9 (1987), pp.17-35.