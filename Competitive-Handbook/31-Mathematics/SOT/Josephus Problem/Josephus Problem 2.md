---
obsidianUIMode: preview
note_type: book theory
judul_materi:
sumber:
date_learned:
tags:
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Josephus Problem

## Statement

Diberikan bilangan asli $n$ dan $k$. Semua bilangan asli dari $1$ hingga $n$ dituliskan dalam bentuk lingkaran. Pertama, hitung elemen ke-$k$ dimulai dari elemen pertama lalu hapus elemen tersebut. Kemudian $k$ elemen dihitung mulai dari elemen berikutnya dan elemen ke-$k$ dihapus kembali, dan seterusnya. Proses ini berhenti ketika tersisa satu elemen. Diperlukan cara untuk menemukan elemen terakhir tersebut.

Tugas ini diajukan oleh Flavius Josephus pada abad ke-1 (meskipun dalam formulasi yang sedikit lebih sempit: untuk $k = 2$).

Masalah ini dapat diselesaikan dengan melakukan _modeling_ terhadap prosedurnya. _Brute force modeling_ akan bekerja dalam $O(n^2)$. Menggunakan _Segment Tree_, kita dapat mengoptimalkannya menjadi $O(n \log n)$. Namun, kita menginginkan pendekatan yang lebih baik.

## Modeling Solusi $O(n)$

Kita akan mencoba mencari _pattern_ yang menyatakan jawaban untuk masalah $J_{n, k}$ melalui solusi dari masalah sebelumnya.

Menggunakan _brute force modeling_, kita dapat menyusun tabel nilai, misalnya sebagai berikut:

$$\begin{array}{ccccccccccc} n\setminus k & 1 & 2 & 3 & 4 & 5 & 6 & 7 & 8 & 9 & 10 \\ 1 & 1 & 1 & 1 & 1 & 1 & 1 & 1 & 1 & 1 & 1 \\ 2 & 2 & 1 & 2 & 1 & 2 & 1 & 2 & 1 & 2 & 1 \\ 3 & 3 & 3 & 2 & 2 & 1 & 1 & 3 & 3 & 2 & 2 \\ 4 & 4 & 1 & 1 & 2 & 2 & 3 & 2 & 3 & 3 & 4 \\ 5 & 5 & 3 & 4 & 1 & 2 & 4 & 4 & 1 & 2 & 4 \\ 6 & 6 & 5 & 1 & 5 & 1 & 4 & 5 & 3 & 5 & 2 \\ 7 & 7 & 7 & 4 & 2 & 6 & 3 & 5 & 4 & 7 & 5 \\ 8 & 8 & 1 & 7 & 6 & 3 & 1 & 4 & 4 & 8 & 7 \\ 9 & 9 & 3 & 1 & 1 & 8 & 7 & 2 & 3 & 8 & 8 \\ 10 & 10 & 5 & 4 & 5 & 3 & 3 & 9 & 1 & 7 & 8 \\ \end{array}$$

Dari tabel ini, kita dapat melihat _pattern_ berikut secara jelas:

$$J_{n,k} = \left( (J_{n-1,k} + k - 1) \bmod n \right) + 1$$

$$J_{1,k} = 1$$

Di sini, _1-indexing_ membuat formulanya agak rumit; jika Anda menggunakan _0-indexing_ untuk penomoran posisi, Anda akan mendapatkan formula yang sangat elegan:

$$J_{n,k} = (J_{n-1,k} + k) \bmod n$$

Dengan demikian, kita telah menemukan solusi untuk _Josephus Problem_ yang bekerja dalam $O(n)$ operasi.

## Implementation

_Simple recursive implementation_ (dalam _1-indexing_):

```cpp
int josephus(int n, int k) {
    return n > 1 ? (josephus(n-1, k) + k - 1) % n + 1 : 1;
}
```

Bentuk _non-recursive_:

```cpp
int josephus(int n, int k) {
    int res = 0;
    for (int i = 1; i <= n; ++i)
        res = (res + k) % i;
    return res + 1;
}
```

Formula ini juga dapat ditemukan secara analitis. Sekali lagi di sini kita berasumsi menggunakan _0-indexing_. Setelah kita menghapus elemen pertama, tersisa $n-1$ elemen. Ketika kita mengulangi prosedurnya, kita akan memulai dari elemen yang awalnya memiliki _index_ $k \bmod n$. $J_{n-1, k}$ akan menjadi jawaban untuk lingkaran yang tersisa jika kita mulai menghitung dari $0$, tetapi karena pada kenyataannya kita mulai dari $k$, kita mendapatkan $J_{n, k} = (J_{n-1,k} + k) \bmod n$.

## Modeling Solusi $O(k \log n)$

Untuk nilai $k$ yang relatif kecil, kita dapat membuat solusi yang lebih baik daripada solusi _recursive_ $O(n)$ di atas. Jika $k$ jauh lebih kecil daripada $n$, kita dapat menghapus banyak elemen ($\lfloor \frac{n}{k} \rfloor$) dalam satu kali jalan tanpa perlu melakukan _looping_ berulang. Setelahnya, tersisa $n - \lfloor \frac{n}{k} \rfloor$ elemen, dan kita mulai dari elemen ke-$(\lfloor \frac{n}{k} \rfloor \cdot k)$. Jadi kita perlu melakukan _shift_ sebanyak nilai tersebut. Kita dapat mengamati bahwa $\lfloor \frac{n}{k} \rfloor \cdot k$ bernilai sama dengan $-n \bmod k$. Dan karena kita menghapus setiap elemen ke-$k$, kita harus menambahkan jumlah elemen yang telah kita hapus sebelum _result index_. Nilai ini dapat kita hitung dengan membagi _result index_ dengan $k - 1$.

Selain itu, kita perlu menangani _edge case_ ketika $n$ menjadi lebih kecil dari $k$. Dalam kasus ini, optimasi di atas akan menyebabkan _infinite loop_.

_Implementation_ (untuk kemudahan dalam _0-indexing_):

```cpp
int josephus(int n, int k) {
    if (n == 1)
        return 0;
    if (k == 1)
        return n-1;
    if (k > n)
        return (josephus(n-1, k) + k) % n;
    int cnt = n / k;
    int res = josephus(n - cnt, k);
    res -= n % k;
    if (res < 0)
        res += n;
    else
        res += res / (k - 1);
    return res;
}
```

Mari kita perkirakan _complexity_ dari _algorithm_ ini. Perlu dicatat bahwa kasus $n < k$ dianalisis oleh solusi lama, yang dalam kasus ini bekerja dalam $O(k)$. Sekarang tinjau _algorithm_ itu sendiri. Faktanya, setelah setiap _iteration_, alih-alih $n$ elemen, kita menyisakan $n \left( 1 - \frac{1}{k} \right)$ elemen, sehingga total _iteration_ $x$ dari _algorithm_ dapat ditemukan secara kasar dari persamaan berikut:

$$n \left(1 - \frac{1}{k} \right) ^ x = 1$$

Dengan mengambil logaritma di kedua sisi, kita memperoleh:

$$\ln n + x \ln \left(1 - \frac{1}{k} \right) = 0$$

$$x = - \frac{\ln n}{\ln \left(1 - \frac{1}{k} \right)}$$

Menggunakan dekomposisi logaritma ke dalam _Taylor series_, kita mendapatkan estimasi pendekatan:

$$x \approx k \ln n$$

Dengan demikian, _complexity_ dari _algorithm_ ini sebenarnya adalah $O(k \log n)$.

## Solusi Analitis untuk $k = 2$

Dalam kasus khusus ini (di mana masalah ini diajukan oleh Josephus Flavius), masalah diselesaikan dengan jauh lebih mudah.

Dalam kasus $n$ bernilai genap, kita mendapatkan bahwa semua bilangan genap akan dicoret, dan kemudian tersisa masalah untuk $\frac{n}{2}$. Jawaban untuk $n$ akan diperoleh dari jawaban untuk $\frac{n}{2}$ dengan mengalikan dua dan menguranginya dengan satu (karena ada _shifting_ posisi):

$$J_{2n, 2} = 2 J_{n, 2} - 1$$

Sama halnya, dalam kasus $n$ bernilai ganjil, semua bilangan genap akan dicoret, kemudian elemen pertama dicoret, dan tersisa masalah untuk $\frac{n-1}{2}$. Dengan memperhitungkan _shift_ posisi, kita memperoleh formula kedua:

$$J_{2n+1,2} = 2 J_{n, 2} + 1$$

Kita dapat menggunakan dependensi _recurrent_ ini secara langsung dalam _implementation_ kita. _Pattern_ ini dapat diterjemahkan ke bentuk lain: $J_{n, 2}$ merepresentasikan urutan semua bilangan ganjil, yang "dimulai ulang" dari satu kapan pun $n$ merupakan _power of two_. Ini dapat dituliskan sebagai formula tunggal:

$$J_{n, 2} = 1 + 2 \left(n-2^{\lfloor \log_2 n \rfloor} \right)$$

## Solusi Analitis untuk $k > 2$

Meskipun bentuk masalahnya sederhana dan terdapat banyak artikel mengenai masalah ini beserta variansinya, representasi analitis yang sederhana untuk solusi _Josephus Problem_ belum ditemukan. Untuk nilai $k$ yang kecil, beberapa formula berhasil diturunkan, tetapi tampaknya sulit untuk diterapkan dalam praktik (sebagai contoh, lihat Halbeisen, Hungerbuhler "The Josephus Problem" dan Odlyzko, Wilf "Functional iteration and the Josephus problem").