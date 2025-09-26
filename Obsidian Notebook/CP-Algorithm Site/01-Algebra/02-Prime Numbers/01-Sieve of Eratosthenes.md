---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Sieve of Eratosthenes
sumber:
  - cp-algorithms.com
date_learned: 2025-09-24T03:22:00
tags:
  - number-theory
  - algebra
  - prime-numbers
---
Link Sumber: [Sieve of Eratosthenes - Algorithms for Competitive Programming](https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html)

---
# Sieve of Eratosthenes

**Sieve of Eratosthenes** adalah algoritma untuk menemukan semua bilangan prima dalam rentang $[1; n]$ menggunakan $O(n \log \log n)$ operasi.

Algoritma ini sangat sederhana: pada awalnya, kita tuliskan semua bilangan antara 2 dan $n$. Kita tandai semua kelipatan sejati dari 2 (karena 2 adalah bilangan prima terkecil) sebagai bilangan **komposit**. Kelipatan sejati dari suatu bilangan $x$ adalah bilangan yang lebih besar dari $x$ dan habis dibagi $x$. Kemudian, kita temukan bilangan berikutnya yang belum ditandai sebagai komposit, dalam hal ini adalah 3. Ini berarti 3 adalah bilangan prima, dan kita tandai semua kelipatan sejati dari 3 sebagai komposit. Bilangan yang belum ditandai berikutnya adalah 5, yang merupakan bilangan prima selanjutnya, dan kita tandai semua kelipatan sejatinya. Kita teruskan prosedur ini sampai kita telah memproses semua bilangan dalam baris tersebut.

Pada gambar berikut, Anda dapat melihat visualisasi algoritma untuk menghitung semua bilangan prima dalam rentang $[1; 16]$.  Terlihat, bahwa sering kali kita menandai bilangan sebagai komposit berkali-kali.

![[01-Sieve of Eratosthenes-1.png]]


Idenya adalah ini: Sebuah bilangan adalah **prima**, jika tidak ada bilangan prima yang lebih kecil yang habis membaginya. Karena kita mengiterasi bilangan prima secara berurutan, kita sudah menandai semua bilangan yang habis dibagi oleh setidaknya satu dari bilangan prima tersebut. Oleh karena itu, jika kita mencapai sebuah sel dan sel tersebut belum ditandai, maka sel itu tidak habis dibagi oleh bilangan prima yang lebih kecil mana pun dan karenanya pasti merupakan bilangan prima.

## 1 | Implementation

```cpp
int n;
vector<bool> is_prime(n + 1, true);
is_prime[0] = is_prime[1] = false;

for (int i = 2; i <= n; i++) {
    if (is_prime[i] && (long long)i * i <= n) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}
```

Kode ini pertama-tama menandai semua bilangan kecuali nol dan satu sebagai bilangan prima potensial, kemudian memulai proses penyaringan (*sifting*) bilangan komposit. Untuk itu, kode ini mengiterasi semua bilangan dari $2$ hingga $n$. Jika bilangan saat ini $i$ adalah bilangan prima, ia menandai semua bilangan yang merupakan kelipatan dari $i$ sebagai bilangan komposit, dimulai dari $i^2$.

Ini sudah merupakan **optimasi** dibandingkan implementasi naif, dan dimungkinkan karena semua bilangan yang lebih kecil yang merupakan kelipatan dari $i$ pasti juga memiliki faktor prima yang kurang dari $i$, jadi semuanya sudah disaring lebih awal. Karena $i^2$ dapat dengan mudah menyebabkan **overflow** tipe `int`, verifikasi tambahan dilakukan menggunakan tipe `long long` sebelum *nested loop* kedua.

Dengan implementasi seperti ini, algoritma ini membutuhkan memori $O(n)$ (jelas) dan melakukan operasi dalam waktu $O(n \log \log n)$.

## 2 | Analisis Asimtotik

Sangat mudah untuk membuktikan waktu berjalan (*running time*) sebesar $O(n \log n)$ tanpa mengetahui apa pun tentang distribusi bilangan prima — dengan mengabaikan pemeriksaan `is_prime`, *inner loop* akan berjalan (paling banyak) $n/i$ kali untuk $i = 2, 3, 4, \dots$. Ini mengarah pada jumlah total operasi dalam *inner loop* yang merupakan penjumlahan harmonik seperti $n(1/2 + 1/3 + 1/4 + \cdots)$, yang dibatasi oleh $O(n \log n)$.

Mari kita buktikan bahwa waktu berjalan algoritma adalah $O(n \log \log n)$. Algoritma akan melakukan $\frac{n}{p}$ operasi untuk setiap bilangan prima $p \le n$ di *inner loop*. Oleh karena itu, kita perlu mengevaluasi ekspresi berikutnya:

$$\sum_{\substack{p \le n, \\\ p \text{ prime}}} \frac n p = n \cdot \sum_{\substack{p \le n, \\\ p \text{ prime}}} \frac 1 p.$$

Mari kita ingat dua fakta yang diketahui:

1.  Jumlah bilangan prima yang kurang dari atau sama dengan $n$ kira-kira $\frac n {\ln n}$.
2.  Bilangan prima ke-$k$ kira-kira sama dengan $k \ln k$ (ini mengikuti dari fakta sebelumnya).

Dengan demikian, kita dapat menulis penjumlahan tersebut dengan cara berikut:

$$\sum_{\substack{p \le n, \\\ p \text{ prime}}} \frac 1 p \approx \frac 1 2 + \sum_{k = 2}^{\frac n {\ln n}} \frac 1 {k \ln k}.$$

Di sini kita mengekstrak bilangan prima pertama, 2, dari penjumlahan, karena $k = 1$ dalam aproksimasi $k \ln k$ adalah $0$ dan menyebabkan pembagian dengan nol.

Sekarang, mari kita evaluasi penjumlahan ini menggunakan integral dari fungsi yang sama di atas $k$ dari $2$ hingga $\frac n {\ln n}$ (kita dapat membuat aproksimasi seperti itu karena, pada kenyataannya, penjumlahan tersebut terkait dengan integral sebagai aproksimasinya menggunakan metode persegi panjang):

$$\sum_{k = 2}^{\frac n {\ln n}} \frac 1 {k \ln k} \approx \int_2^{\frac n {\ln n}} \frac 1 {k \ln k} dk.$$

Anti-turunan untuk integran adalah $\ln \ln k$. Menggunakan substitusi dan menghapus suku-suku dari orde yang lebih rendah, kita akan mendapatkan hasilnya:

$$\int_2^{\frac n {\ln n}} \frac 1 {k \ln k} dk = \ln \ln \frac n {\ln n} - \ln \ln 2 = \ln(\ln n - \ln \ln n) - \ln \ln 2 \approx \ln \ln n.$$

Sekarang, kembali ke penjumlahan asli, kita akan mendapatkan evaluasi aproksimasinya:

$$\sum_{\substack{p \le n, \\\ p\ is\ prime}} \frac n p \approx n \ln \ln n + o(n).$$

Anda dapat menemukan bukti yang lebih ketat (yang memberikan evaluasi yang lebih tepat yang akurat dalam konstanta pengganda) dalam buku karya Hardy & Wright "An Introduction to the Theory of Numbers" (hal. 349).

## 3 | Berbagai Optimasi dari Sieve of Eratosthenes

Kelemahan terbesar dari algoritma ini adalah ia "berjalan" di sepanjang memori berkali-kali, hanya memanipulasi elemen tunggal. Ini tidak terlalu ramah terhadap **cache**. Dan karena itu, konstanta yang tersembunyi dalam $O(n \log \log n)$ relatif besar.

Selain itu, memori yang digunakan menjadi kendala (*bottleneck*) untuk $n$ yang besar.

Metode yang disajikan di bawah ini memungkinkan kita untuk mengurangi jumlah operasi yang dilakukan, serta mempersingkat penggunaan memori secara signifikan.

### 3.1 | Penyaringan Sampai Akar Kuadrat (*Sieving till root*)

Jelas, untuk menemukan semua bilangan prima hingga $n$, cukup dengan melakukan penyaringan hanya dengan bilangan prima yang tidak melebihi akar kuadrat dari $n$.

```cpp
int n;
vector<bool> is_prime(n + 1, true);
is_prime[0] = is_prime[1] = false;

for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}
```

Optimasi seperti ini tidak memengaruhi **kompleksitas** (memang, dengan mengulang bukti yang disajikan di atas, kita akan mendapatkan evaluasi $n \ln \ln \sqrt n + o(n)$, yang secara asimtotik sama sesuai dengan sifat-sifat logaritma), meskipun jumlah operasi akan berkurang secara signifikan.

### 3.2 | Penyaringan Hanya dengan Bilangan Ganjil (*Sieving by the odd numbers only*)

Karena semua bilangan genap (kecuali 2) adalah komposit, kita dapat berhenti memeriksa bilangan genap sama sekali. Sebaliknya, kita hanya perlu beroperasi dengan bilangan ganjil.

Pertama, ini akan memungkinkan kita untuk **menghemat setengah memori** yang dibutuhkan. Kedua, ini akan mengurangi jumlah operasi yang dilakukan oleh algoritma kira-kira menjadi setengahnya.
### 3.3 | Penggunaan Memori dan Kecepatan Operasi

Kita harus perhatikan bahwa dua implementasi Sieve of Eratosthenes ini menggunakan $n$ bit memori dengan menggunakan struktur data `vector<bool>`. `vector<bool>` bukanlah *container* biasa yang menyimpan serangkaian `bool` (seperti halnya di sebagian besar arsitektur komputer di mana sebuah `bool` membutuhkan satu *byte* memori). Ini adalah spesialisasi `vector<T>` yang dioptimasi memori, yang hanya menggunakan $\frac{N}{8}$ *byte* memori.

Arsitektur prosesor modern bekerja jauh lebih efisien dengan *byte* daripada dengan *bit* karena biasanya tidak dapat mengakses *bit* secara langsung. Jadi, di bawahnya, `vector<bool>` menyimpan *bit-bit* dalam memori kontinu yang besar, mengakses memori dalam blok beberapa *byte*, dan mengekstrak/menyetel *bit-bit* dengan operasi *bit* seperti **penutupan bit** (*bit masking*) dan **pergeseran bit** (*bit shifting*).

Karena hal tersebut, ada **overhead** tertentu saat Anda membaca atau menulis *bit-bit* dengan `vector<bool>`, dan sering kali menggunakan `vector<char>` (yang menggunakan 1 *byte* untuk setiap entri, jadi 8 kali lipat jumlah memori) lebih cepat.

Namun, untuk implementasi sederhana dari Sieve of Eratosthenes, menggunakan `vector<bool>` **lebih cepat**. Anda dibatasi oleh seberapa cepat Anda dapat memuat data ke dalam *cache*, dan oleh karena itu, menggunakan lebih sedikit memori memberikan keuntungan besar. Sebuah tolok ukur (*benchmark*) menunjukkan bahwa menggunakan `vector<bool>` antara 1.4x dan 1.7x lebih cepat daripada menggunakan `vector<char>`.

Pertimbangan yang sama juga berlaku untuk `bitset`. Ini juga merupakan cara efisien untuk menyimpan *bit-bit*, mirip dengan `vector<bool>`, sehingga hanya membutuhkan $\frac{N}{8}$ *byte* memori, tetapi sedikit lebih lambat dalam mengakses elemen. Dalam tolok ukur di atas, `bitset` memiliki kinerja yang sedikit lebih buruk daripada `vector<bool>`. Kekurangan lain dari `bitset` adalah Anda perlu mengetahui ukurannya saat waktu kompilasi (*compile time*).

### 3.4 | Segmented Sieve

Dari optimasi "penyaringan sampai akar kuadrat", terlihat bahwa tidak ada gunanya menyimpan seluruh *array* `is_prime[1...n]` setiap saat. Untuk menyaring, cukup menyimpan bilangan prima hingga akar kuadrat dari $n$, yaitu `prime[1...sqrt(n)]`, membagi rentang penuh menjadi blok-blok, dan menyaring setiap blok secara terpisah.

Misalkan $s$ adalah konstanta yang menentukan ukuran blok, maka kita memiliki $\lceil {\frac n s} \rceil$ blok secara keseluruhan, dan blok $k$ ($k = 0 ... \lfloor {\frac n s} \rfloor$) berisi bilangan dalam segmen $[ks; ks + s - 1]$. Kita dapat mengerjakan blok secara bergantian, yaitu untuk setiap blok $k$ kita akan melalui semua bilangan prima (dari $1$ hingga $\sqrt n$) dan melakukan penyaringan menggunakannya. Perlu dicatat, bahwa kita harus memodifikasi strategi sedikit saat menangani bilangan-bilangan pertama: pertama, semua bilangan prima dari $[1; \sqrt n]$ tidak boleh menghapus dirinya sendiri; dan kedua, bilangan 0 dan 1 harus ditandai sebagai bilangan non-prima. Saat mengerjakan blok terakhir, tidak boleh dilupakan bahwa bilangan terakhir yang dibutuhkan $n$ tidak harus berada di akhir blok.

Seperti yang telah dibahas sebelumnya, implementasi tipikal dari Sieve of Eratosthenes dibatasi oleh seberapa cepat Anda dapat memuat data ke dalam **cache CPU**. Dengan membagi rentang bilangan prima potensial $[1; n]$ menjadi blok-blok yang lebih kecil, kita tidak perlu menyimpan banyak blok dalam memori pada saat yang sama, dan semua operasi menjadi jauh lebih **ramah-cache** (*cache-friendly*). Karena kita tidak lagi dibatasi oleh kecepatan *cache*, kita dapat mengganti `vector<bool>` dengan `vector<char>`, dan mendapatkan beberapa kinerja tambahan karena prosesor dapat menangani baca dan tulis dengan *byte* secara langsung dan tidak perlu bergantung pada operasi *bit* untuk mengekstrak bit-bit individual. Tolok ukur (*benchmark*) menunjukkan bahwa menggunakan `vector<char>` sekitar 3x lebih cepat dalam situasi ini daripada menggunakan `vector<bool>`. Namun perlu diperhatikan: angka-angka ini mungkin berbeda tergantung pada arsitektur, kompiler, dan tingkat optimasi.

Berikut adalah implementasi yang menghitung jumlah bilangan prima yang lebih kecil dari atau sama dengan $n$ menggunakan **penyaringan per blok** (*block sieving*).

```cpp
int count_primes(int n) {
    const int S = 10000;

    vector<int> primes;
    int nsqrt = sqrt(n);
    vector<char> is_prime(nsqrt + 2, true);
    for (int i = 2; i <= nsqrt; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= nsqrt; j += i)
                is_prime[j] = false;
        }
    }

    int result = 0;
    vector<char> block(S);
    for (int k = 0; k * S <= n; k++) {
        fill(block.begin(), block.end(), true);
        int start = k * S;
        for (int p : primes) {
            int start_idx = (start + p - 1) / p;
            int j = max(start_idx, p) * p - start;
            for (; j < S; j += p)
                block[j] = false;
        }
        if (k == 0)
            block[0] = block[1] = false;
        for (int i = 0; i < S && start + i <= n; i++) {
            if (block[i])
                result++;
        }
    }
    return result;
}
```

Waktu berjalan (*running time*) dari *block sieving* sama dengan *sieve of Eratosthenes* biasa (kecuali jika ukuran blok sangat kecil), tetapi memori yang dibutuhkan akan berkurang menjadi $O(\sqrt{n} + S)$ dan kita mendapatkan hasil **caching** yang lebih baik.

Di sisi lain, akan ada operasi pembagian untuk setiap pasangan blok dan bilangan prima dari $[1; \sqrt{n}]$, dan ini akan jauh lebih buruk untuk ukuran blok yang lebih kecil. Oleh karena itu, penting untuk menjaga **keseimbangan** saat memilih konstanta $S$. Kami mendapatkan hasil terbaik untuk ukuran blok antara $10^4$ dan $10^5$.

## 4 | Mencari Bilangan Prima dalam Rentang

Terkadang kita perlu menemukan semua bilangan prima dalam rentang $[L, R]$ yang ukurannya kecil (misalnya $R - L + 1 \approx 10^7$), di mana $R$ bisa sangat besar (misalnya $10^{12}$).

Untuk menyelesaikan masalah seperti itu, kita bisa menggunakan ide dari **Segmented Sieve** (Saringan Bersegmen). Kita pra-generasi semua bilangan prima hingga $\sqrt R$, dan menggunakan bilangan prima tersebut untuk menandai semua bilangan komposit dalam segmen $[L, R]$.

```cpp
vector<char> segmentedSieve(long long L, long long R) {
    // menghasilkan semua bilangan prima hingga sqrt(R)
    long long lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<char> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;

    if (L == 1)
        isPrime[0] = false;

    return isPrime;
}
```

Kompleksitas waktu dari pendekatan ini adalah $O((R - L + 1) \log \log (R) + \sqrt R \log \log \sqrt R)$.

Mungkin juga kita tidak melakukan pra-generasi semua bilangan prima:

```cpp
vector<char> segmentedSieveNoPreGen(long long L, long long R) {
    vector<char> isPrime(R - L + 1, true);
    long long lim = sqrt(R);
    for (long long i = 2; i <= lim; ++i)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;

    if (L == 1)
        isPrime[0] = false;

    return isPrime;
}
```

Jelas, kompleksitasnya lebih buruk, yaitu $O((R - L + 1) \log (R) + \sqrt R)$. Namun, dalam praktiknya, kode ini masih berjalan sangat cepat.

## 5 | Modifikasi Waktu Linear

Kita dapat memodifikasi algoritma sedemikian rupa sehingga hanya memiliki kompleksitas waktu **linear**. Pendekatan ini dijelaskan dalam artikel **Linear Sieve** (Saringan Linear). Namun, algoritma ini juga memiliki kelemahannya sendiri.