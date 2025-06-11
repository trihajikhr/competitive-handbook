---
obsidianUIMode: preview
note_type: Advice
judul_materi: All You Need is Randomly Guessing — How to Improve at Codeforces
sumber: codeforces
date_learned: 2025-05-18T21:47:00
tags:
  - advice
  - problem-solving
---
Link sumber: [All You Need is Randomly Guessing — How to Improve at Codeforces - Codeforces](https://codeforces.com/blog/entry/126875)

---
# All You Need is Randomly Guessing — How to Improve at Codeforces

Saya harap blog saya sebelumnya telah meyakinkan Anda bahwa cara terbaik untuk menjadi lebih baik di Codeforces adalah dengan menjadi "lebih Rusia", yaitu dengan meningkatkan kemampuan matematika Anda. Sayangnya, manusia biasa seperti Anda dan saya tidak diberkahi dengan bakat seperti grandmaster Rusia ternama seperti 74TrAkToR:

*Tentunya, memiliki referensi kode untuk berbagai algoritma dan struktur data itu menguntungkan, namun saya juga berpikir bahwa sekadar mengetahui algoritma tersebut secara dangkal dan mungkin pernah mengimplementasikannya sekali atau dua kali sudah cukup untuk bisa menggunakannya tanpa referensi, bukan?*

— Seorang grandmaster Codeforces lainnya

Oleh karena itu, dalam blog ini saya akan mengeksplorasi sisi gelap dari "kekerasian khas Rusia" — yaitu _menebak secara acak_ — sesuatu yang ditinggalkan oleh setiap grandmaster Rusia dari "sisi terang" yang saya kenal. Namun, pendekatan ini sangat membantu bagi saya, dan saya berharap bisa bermanfaat juga bagi Anda.

---

## Contoh 1

Saya akan mulai dengan sebuah contoh untuk menunjukkan proses berpikir saya. Masalah **1923C** ini berasal dari salah satu _Educational Round_ terbaru.

### 🔍 *Intuisi*

Untuk menyelesaikan soal ini, pertama-tama saya membaca pernyataan soalnya. Kesan pertama saya adalah bahwa soal ini seolah-olah menanyakan apakah Anda bisa _mengutak-atik_ sebuah subarray sedikit. Jadi, secara intuitif, saya langsung membayangkan semacam subarray (dalam bentuk grafik) di dalam kepala saya.

![[All You Need is Randomly Guessing — How to Improve at Codeforces-1.png]]

Saya kemudian memeriksa kembali syarat-syarat dari soal — saya harus mengubah setiap elemen sedikit saja sambil menjaga agar jumlah total tetap sama. Secara intuitif, cukup mudah untuk mengubah setiap elemen naik 1 atau turun 1 tanpa terlalu memengaruhi jumlah totalnya.

![[All You Need is Randomly Guessing — How to Improve at Codeforces-2.png]]

Lalu tampaknya sulit untuk melakukan penalaran lebih jauh dari sini, jadi saya membuat sebuah tebakan: **Setiap subarray bisa diutak-atik**.

Sekarang saya mencoba mencari counterexample (contoh penyangkal) dari tebakan saya. Ada cukup banyak contohnya, tapi secara intuitif, hal-hal buruk terjadi ketika kita memiliki banyak angka **1**, karena kita tidak bisa menurunkan mereka lagi.

![[All You Need is Randomly Guessing — How to Improve at Codeforces-3.png]]

Dari situ tampaknya kita perlu mempertimbangkan kemungkinan elemen lain bisa diturunkan, serta kebutuhan untuk menaikkan angka-angka **1**.

![[All You Need is Randomly Guessing — How to Improve at Codeforces-4.png]]

Sekarang saya membuat tebakan baru: **Selama ada cukup banyak potensi untuk menurunkan elemen lain dibandingkan jumlah angka 1, maka jawabannya adalah YES**.

Saya kemudian mencoba mencari counterexample lagi. Saya tidak bisa menemukannya, jadi saya percaya bahwa tebakan ini benar (walaupun nanti Anda akan lihat bahwa sebenarnya tidak).

Sekarang saya perlu mencari tahu bagaimana cara menghitung jumlah angka **1** dan potensi penurunan dalam setiap subarray. Saya cukup “[berjiwa Cina]”, jadi saya anggap dua hal itu bisa dilakukan dengan teknik-teknik biasa.

Pada titik ini, masalahnya tampak sudah selesai, jadi saya melanjutkan ke tahap _formalisasi_.

### 🖥️ *Formalisasi*

Pada tahap ini, saya harus benar-benar menuliskan matematikanya. Jelas bahwa kebutuhan untuk menaikkan nilai ditentukan oleh jumlah angka **1**, dan ini bisa dengan mudah dilacak menggunakan prefix sum `cnt[]` untuk menghitung jumlah angka **1**.

Potensi penurunan tampaknya dapat dihitung sebagai **jumlah elemen dikurangi panjang subarray**, dan ini juga dapat dilacak dengan prefix sum `sum[]`.

Sekarang masalah ini tampaknya bisa langsung di-_coding_, jadi saya lanjut ke tahap implementasi.
### 🦉 *Implementasi*

Tahap ini sebagian besar hanya melibatkan proses _coding_ dan _debugging_. Pertama saya menulis kode berikut:

#### Kode:

```cpp
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N, Q;
    static int C[310000];
    static long long cnt[310000], sum[310000];
    scanf("%d%d", &N, &Q);
    for (int i = 0; i < N; ++i)
      scanf("%d", &C[i]);
    for (int i = 0; i < N; ++i)
      cnt[i + 1] = cnt[i] + (C[i] == 1);
    for (int i = 0; i < N; ++i)
      sum[i + 1] = sum[i] + C[i];
    for (int i = 0; i < Q; ++i) {
      int l, r;
      scanf("%d%d", &l, &r), --l, --r;
      long long c = cnt[r + 1] - cnt[l];
      long long s = sum[r + 1] - sum[l];
      if (s - (r - l + 1) >= c)
        puts("YES");
      else
        puts("NO");
    }
  }
}
```

Namun ternyata hasilnya **WA (Wrong Answer)** pada contoh uji coba... Untungnya, setelah melihat contoh tersebut, saya menyadari bahwa saya melewatkan kasus trivial di mana panjang subarray adalah **1**. Ini bisa diperbaiki dengan cepat:

```cpp
if (s - (r - l + 1) >= c && (r - l + 1) > 1)
```

Setelah perbaikan ini, program pun **Accepted (AC)**. Seluruh proses ini memakan waktu tak lebih dari 15 menit.

### Review

Jadi, apa yang sebenarnya terjadi pada contoh tadi?

Dalam blog ini, saya terutama ingin membahas proses **intuisi**. Seperti yang bisa Anda lihat dari contoh sebelumnya, saya memulai intuisi dengan membayangkan permasalahannya di kepala saya dengan menggunakan sesuatu yang sudah akrab — seperti _plot_ atau grafik. Karena semua ini terjadi hanya dalam kepala saya, Anda akan melihat bahwa hampir tidak ada rumus di dalam proses berpikir saya. Atau, seperti yang saya suka katakan:

> **Formalisasi adalah kematian intuisi; jangan gunakan rumus dalam tahap intuisi jika tidak terpaksa.**

Kemudian, secara umum ada tiga pendekatan yang bisa saya gunakan untuk menyelesaikan masalah:

1. **Dismiss (Abaikan).**  
    Saya bisa berkata bahwa saya tahu cara menyelesaikannya dengan teknik tertentu (disebut _kekhasan orang Cina_), lalu saya abaikan dan lanjut.
<br/>
2. **Reason (Penalaran).**  
    Saya bisa mengambil satu langkah logis ke depan, dengan cukup yakin bahwa langkah tersebut benar.
<br/>
3. **Guess (Tebak).**  
    Saya bisa menebak secara acak — apapun yang tampaknya paling membantu menyelesaikan masalah. Setelah itu saya mencoba mencari _counterexample_ dalam batas waktu tertentu. Jika tidak ditemukan, saya anggap tebakan tersebut benar.
    


Sekarang saya akan mendemonstrasikan proses ini lagi pada soal lain: **1923D**, kali ini **tanpa gambar**.


## Contoh 2 – Soal Slime (1923D)

### 🦉 *Intuisi*

Soal ini berkaitan dengan slime, jadi masuk akal untuk membayangkan _kolom bola-bola slime_ di kepala saya.

Pertama, saya **menalar** bahwa jika suatu slime dimakan, maka slime itu pasti dimakan oleh **bola raksasa dari kiri** atau **bola raksasa dari kanan**. Karena masalah ini bersifat simetris, saya fokus dulu pada kasus dari **kiri**.

Saya lanjut **menalar** bahwa bola raksasa dari kiri pasti terdiri dari suatu **interval slime** yang jumlah totalnya **lebih besar** dari slime yang akan dimakan.

Lalu saya **buntu**, jadi saya **menebak**: setiap interval dengan jumlah lebih besar dari slime tersebut bisa digunakan untuk memakannya.

Saya mencoba mencari _counterexample_, dan saya menemukannya: ketika semua slime **berukuran sama**, maka tidak ada satu pun yang bisa memakan yang lain.

Maka saya **tebak ulang**: setiap interval yang jumlahnya lebih besar **dan tidak semuanya sama** adalah valid.

Saya mencoba mencari _counterexample_, dan **tidak menemukan satu pun**, jadi saya percaya hipotesis ini benar.

Maka, untuk setiap slime, saya perlu mencari:

- **interval terpendek dari kiri** yang jumlahnya lebih besar dan tidak semuanya sama.
    
- **interval terpendek dari kanan** yang memenuhi syarat yang sama.
    

Saya **abaikan** (dismiss) bahwa kedua hal ini bisa dilakukan dengan **binary search** menggunakan prefix sum — cukup mudah. Jadi masalah ini kini terlihat siap untuk diformalkan dan diimplementasikan.

---

### ✏️ _Formalisasi_

Sekarang saya perlu tahu bagaimana cara mengecek apakah suatu interval terdiri dari nilai yang sama.

Ada banyak cara, tapi secara intuitif kita bisa menggunakan **prefix sum** pada kondisi `A[i] != A[i - 1]`.

Kalau total selisih dalam sebuah interval adalah 0, berarti semuanya sama.

---

### ⚙️ _Implementasi_

Saatnya langsung ngoding...

```cpp
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N;
    static int A[310000];
    static long long sum[310000], eq[310000];
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
      scanf("%d", &A[i]);

    for (int i = 0; i < N; ++i)
      sum[i + 1] = sum[i] + A[i];

    for (int i = 0; i < N; ++i)
      eq[i + 1] = eq[i] + (A[i] != A[i + 1]);

    for (int i = 0; i < N; ++i) {
      int ans1 = N + 1, ans2 = N + 1;

      // Cek dari kiri
      {
        int l = 0, r = i - 1;
        while (l <= r) {
          int m = l + r >> 1;
          if (sum[i] - sum[m] > A[i] &&
              (i - 1 == m || eq[i - 1] - eq[m] != 0)) {
            ans1 = i - m;
            l = m + 1;
          } else {
            r = m - 1;
          }
        }
      }

      // Cek dari kanan
      {
        int l = i + 1, r = N - 1;
        while (l <= r) {
          int m = l + r >> 1;
          if (sum[m + 1] - sum[i + 1] > A[i] &&
              (m == i + 1 || eq[m] - eq[i + 1] != 0)) {
            ans2 = m - i;
            r = m - 1;
          } else {
            l = m + 1;
          }
        }
      }

      // Ambil minimum dari dua sisi
      int ans = std::min(ans1, ans2);
      if (ans == N + 1) {
        printf("-1%c", " \n"[i + 1 == N]);
      } else {
        printf("%d%c", ans, " \n"[i + 1 == N]);
      }
    }
  }
}
```

---

### 🐛 _Bug dan Solusi_

Ternyata, program ini **WA (Wrong Answer)** di **test 2**.

_Debugging_ ini merupakan tugas khas ala orang Amerika — menarik tapi di luar topik intuisi — jadi saya skip detailnya, dan langsung menyebutkan bahwa masalahnya adalah:

> Dalam **binary search**, saya tidak mempertimbangkan **kasus tetangga langsung yang lebih besar**.

Contohnya, jika slime di kiri/kanan **langsung lebih besar**, maka jawabannya harus **1**, dan tidak perlu binary search.

Cukup tambahkan pengecekan ini:

```cpp
if ((i - 1 >= 0 && A[i - 1] > A[i]) || (i + 1 < N && A[i + 1] > A[i])) {
  ans1 = ans2 = 1;
}
```

Setelah penambahan ini, program berhasil **AC (Accepted)**.

## 🐘 Gajah di Dalam Ruangan — Kenapa Kamu Harus Berani Menebak Tanpa Membuktikan

Sekarang, setelah semua grandmaster Rusia yang terhormat mungkin sudah sangat marah, menganggap ini _“terlalu muda, terlalu sederhana,”_ lalu men-downvote blog ini dan pergi, saya akan membahas isu yang paling penting:

> **Mengapa kamu harus belajar untuk _menebak_ tanpa membuktikan apapun.**

---

## ❌ _Sebuah Counterexample_: Kenapa Membuktikan Itu Bisa Menyesatkan

Mari kita pakai kembali contoh slime sebelumnya. Anggap kita benar-benar ingin **membuktikan** tebakan kita. Bagaimana kita harus mulai?

Kita bisa mencoba menyusun urutan slime mana yang memakan slime lainnya di dalam interval. Untuk itu, kita perlu menebak bahwa slime terbesar dengan ukuran $m$ di dalam interval bisa memakan semua yang lain.

Tapi... jika dua slime yang **bersebelahan** sama-sama memiliki ukuran maksimum $m$, maka mereka **tidak bisa saling memakan**.

Maka kita perlu menebak:

> Jika ada interval slime dengan nilai maksimum $m$, dan interval itu punya setidaknya dua elemen yang berbeda, maka **pasti ada sepasang slime tetangga** $(a_i, a_{i+1})$ dimana salah satunya adalah $m$ dan satunya bukan $m$.

Tapi... kalimat ini tidak mudah dibuktikan.

Jadi kita coba **kontrapositifnya** (logika yang ekivalen tapi mungkin lebih mudah dibuktikan):

> Jika di interval slime dengan maksimum $m$ **tidak ada** pasangan tetangga $(a_i, a_{i+1})$ dengan satu $m$ dan satu bukan $m$, maka seluruh interval hanya terdiri dari **satu elemen saja**.

Nah, ini bisa kita buktikan dengan **induksi**:

### 🔁 _Induksi_

- **Basis**: Untuk interval panjang 1, jelas hanya ada satu elemen → benar.
    
- **Induksi**: Misalkan untuk interval panjang $n$, semua benar — seluruh elemennya $m$.
    
- **Lanjut ke $n + 1$**: Kita ambil prefix sepanjang $n$. Karena tidak ada pasangan tetangga yang "berbeda", maka elemen ke-$n+1$ **juga harus sama dengan $m$**.
    

➡️ Maka terbukti seluruh interval berisi $m$.

Kalau kamu mengikuti pembuktian di atas, kamu akan sadar bahwa:

1. Kita menghabiskan **banyak waktu dan energi** untuk menebak dan membuktikan sesuatu yang **tidak berhubungan langsung dengan implementasi**.
    
2. Kita menggunakan teknik bukti seperti **induksi**, padahal semua itu **tidak perlu** kalau tujuan kita cuma ingin menyelesaikan soal.
    
3. Bahkan mungkin **lebih sulit dan lama** menyusun bukti ini dibanding langsung ngoding dan mengecek dengan beberapa percobaan saja.
    

Justru karena hal-hal di atas, saya terdorong untuk menyusun _teori tentang menebak_ (**theory of guessing**) — yaitu bahwa dalam kompetisi atau problem solving cepat, **menebak yang masuk akal, lalu mencoba counterexample**, bisa jauh lebih efisien dan produktif daripada membuktikan kebenaran secara formal di awal.

## Teori Mengenai Menebak (_Theory on Guessing_)

Saya memulai dengan menyatakan bahwa proses pembuktian (proving) sangat tidak efisien:

> (**Tesis Pembuktian dengan AC** / _Thesis of Proof-by-AC_): Misalkan untuk suatu permasalahan, Anda memiliki sebuah solusi yang membutuhkan waktu $a$ untuk diimplementasikan dan memiliki peluang $p$ untuk benar. Jika Anda dapat menemukan bukti atas solusi tersebut dalam waktu $b$, maka Anda seharusnya hanya membuktikannya apabila  
> $b< \frac{1-p}{p} a$.

Sayangnya, saya tidak bisa mengklaim bahwa saya _menebak_ tesis ini begitu saja, dan saya memang harus membuktikannya. Berikut adalah buktinya.

Mari kita definisikan efisiensi harapan dari penyelesaian masalah sebagai:

> **Efisiensi = (Jumlah ekspektasi masalah yang berhasil diselesaikan) / (Waktu yang dibutuhkan)**

Tujuan kita adalah memaksimalkan efisiensi ini.

- Jika kita langsung menulis kode untuk menyelesaikan masalah ini, maka efisiensi yang diharapkan adalah $\frac{p}{a}$.
    
- Jika kita mencoba untuk membuktikan kebenaran solusi terlebih dahulu, maka **kasus terbaiknya** adalah setelah waktu $b$, kita memiliki solusi yang benar secara mutlak (karena jika ternyata solusi kita salah, efisiensinya akan lebih rendah). Dalam kasus ini, efisiensi yang diharapkan adalah $\frac{1}{a+b}$.
    

Perhitungan sederhana (yang saya serahkan kepada para grandmaster Rusia yang belum meninggalkan blog ini sebagai latihan) akan menghasilkan tesis tersebut.

---

Kita bisa mencoba memasukkan beberapa nilai numerik untuk memperjelas **ketidakefisienan pembuktian**:

Misalnya, Anda memiliki solusi yang _berfungsi_ dengan peluang 50%. Maka menurut tesis di atas, Anda hanya seharusnya mencoba membuktikannya apabila waktu yang dibutuhkan untuk membuktikannya **lebih kecil daripada waktu pengkodeannya**.

Namun, karena solusi tersebut merupakan hasil _tebakan_ (bukan hasil penalaran yang sistematis), kemungkinan besar Anda **tidak akan menemukan buktinya dalam waktu yang singkat**. Maka, **sebaiknya Anda langsung mencoba menulis kode** saja.

---

### Inti dari Tesis _Proof-by-AC_

Pesan utama dari tesis ini adalah:

> Kita **tidak perlu** solusi yang benar secara mutlak. Kita hanya butuh solusi yang **berpeluang benar secara probabilistik** untuk meningkatkan efisiensi (dan secara langsung, **meningkatkan rating kita** dalam kompetisi).

Pada bagian selanjutnya, kita akan melihat bahwa pernyataan ini bahkan masih bisa diperlonggar lagi.

Berikut adalah terjemahan resmi dalam **bahasa Indonesia yang baku, baik, dan benar**, tanpa perubahan isi, dari bagian **“Some Theory on Reasoning” dan “Some Learning Theory”**:


## Beberapa Teori tentang Penalaran (_Some Theory on Reasoning_)

Ternyata dalam bidang filsafat, beberapa orang telah membahas tentang penalaran (_reasoning_) vs. menebak (_guessing_). Dalam teori mereka, logika dikategorikan ke dalam tiga jenis:

### 1. Deduksi (_Deduction_)

Ini adalah bentuk logika yang paling ketat dan formal — jenis logika yang paling sering Anda temui dalam solusi model (model solution).

### 2. Induksi (_Induction_)

Induksi berarti menyimpulkan sesuatu berdasarkan serangkaian observasi. Dalam konteks Competitive Programming (CP), ini berarti melakukan _brute-force_ pada kasus-kasus kecil dan kemudian melakukan pengenalan pola (_pattern recognition_). Beruntungnya, grandmaster Rusia yang terhormat (mungkin dengan pengecualian **74TrAkToR**) tidak terlalu menyukai bentuk penalaran ini. Jadi, Anda tidak akan sering menemui soal yang menuntut pencarian pola dari hasil brute-force.  

Sebagai informasi tambahan, **ChatGPT juga cukup mahir dalam membuat brute-force**.

### 3. Abduksi (_Abduction_) — alias **menebak secara acak**

Inilah jenis tebakan yang kita bicarakan. Abduksi berarti mencari kesimpulan yang **paling sederhana dan paling mungkin benar** dari serangkaian observasi.

---

Yang akan saya tunjukkan selanjutnya adalah bahwa **abduksi tidaklah seburuk itu**, terutama dalam konteks Codeforces.

---

## Beberapa Teori Pembelajaran (_Some Learning Theory_)

Untungnya, dalam bidang **machine learning**, para peneliti sudah sejak lama memikirkan cara **memperkirakan kebenaran suatu model dalam dunia nyata**, **meskipun model tersebut benar pada seluruh data pelatihan**. Ini **sangat mirip** dengan apa yang kita coba lakukan di CP: kita ingin memperkirakan **kebenaran dari sebuah tebakan** dalam sistem pengujian, **berdasarkan kebenarannya terhadap contoh-contoh kasus uji yang kita pikirkan sendiri**.

Teori dari PAC Learning bisa didapatkan dari materi ini: [[PAC Learning.pdf]]

Izinkan saya memperkenalkan konsep dari **PAC Learning**:

> (**Klaim dari PAC Learning, dari UPenn**)  
> Peluang bahwa terdapat sebuah hipotesis $h ∈ H$ yang konsisten dengan $m$ contoh, tetapi memiliki tingkat kesalahan $Error(h) > ϵ$, adalah kurang dari $|H|(1 − ϵ)^m$.

Atau dalam istilah sederhana:

> (**Tesis PAC Abduksi**)  
> **Semakin sederhana hipotesisnya**, dan **semakin banyak contoh yang cocok**, maka **semakin besar kemungkinan hipotesis tersebut benar pada sebagian besar pengujian.**

---

Sekarang kita bisa mengasumsikan bahwa kita mengambil contoh dari distribusi yang **kurang lebih mirip** dengan cara test case dibuat.

Kita juga bisa mengasumsikan bahwa setiap masalah di Codeforces memiliki **tidak lebih dari 1000 test case**. Ini mengarah pada suatu kesimpulan:  

Selama kita bisa memastikan bahwa $Error(h) < \frac{1}{1000}$, maka kita memiliki peluang yang cukup besar untuk **lolos semua pengujian**, bahkan lebih dari $\frac{1}{e}$.

Dengan kata lain,

> **Kita hanya perlu memastikan bahwa tebakan kita adalah _probabilistically approximately correct_ (PAC).**

---

## Contoh 3

Saya ingin menambahkan satu contoh terakhir tentang soal **1930C**, sebuah soal lucu yang saya kerjakan baru-baru ini, untuk **menunjukkan kekuatan penuh dari PAC Abduction**, alias **menebak secara acak**.

Secara naif, jika kita **tidak pernah mengambil angka yang sama**, maka seharusnya kita cukup mengambil angka-angka **secara greedy dari kanan ke kiri**. Tapi apa yang terjadi **kalau kita harus mengambil angka-angka yang sama**?

Saya, setelah melihat contoh-contoh yang diberikan di soal, **langsung menebak**:  
_“Pasti kita cukup ambil angka itu dikurangi 1.”_

### Kode Saya:

```cpp
#include <bits/stdc++.h>

const int INF = 2E9;
int A[310000];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
      scanf("%d", &A[i]), A[i] += i + 1;
    std::sort(A, A + N);
    int upp = INF;
    std::vector<int> ans;
    for (int i = N - 1; i >= 0; --i) {
      if (A[i] < upp) {
        ans.push_back(A[i]);
        upp = A[i];
      } else {
        ans.push_back(upp - 1);
        upp = upp - 1;
      }
    }
    for (int i = 0; i < (int)ans.size(); ++i) {
      printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
    }
  }
}
```

### Bagian lucu terjadi **setelah kontes**:

**Seorang Master Rusia lainnya**: Aku tidak mengerti kenapa C-mu bisa Accepted.  
**Saya**: Aku juga tidak tahu.  
**Seorang Master Rusia lainnya**: Apa maksudmu?  
**Saya**: Maksudmu apa?

## Kesalahan Umum

Ada beberapa kesalahan umum ketika menggunakan cara berpikir seperti ini. Saya akan mencantumkan beberapa yang saya temui.

**Terlalu cepat mengabaikan sesuatu.**  
Ketika Anda mengabaikan sesuatu, Anda sebenarnya harus mengetahui cara melakukannya saat mulai memformalisasikannya. Terkadang saya mengabaikan sesuatu terlalu cepat dan baru sadar bahwa saya sebenarnya tidak tahu bagaimana menyelesaikannya. Untungnya, ini biasanya hanya menyebabkan lebih banyak berpikir, tetapi penting untuk menyadari tingkat *Chinese Skill* Anda.

**Tidak tahu apa yang harus ditebak.**  
Hal ini biasanya terjadi karena Anda tidak familiar dengan hal-hal umum yang bisa ditebak. Salah satu cara untuk mengatasinya adalah dengan **selalu menebak hal yang paling nyaman/nyaman dipakai** (seperti pada tiga contoh di atas). Cara lain adalah ketika membaca tutorial, tanyakan pada diri Anda: _"Tebakan apa yang bisa saya buat untuk menyelesaikan masalah ini?"_ Atau lebih tepatnya, seperti yang biasa saya katakan:  

Saat mengulas kembali soal (upsolve), tanyakan pada diri Anda bagaimana Anda bisa menyelesaikan soal tersebut saat kontes berlangsung.  

Jika Anda tidak bisa melihat cara yang masuk akal untuk menyelesaikan masalah tersebut saat kontes, maka Anda memang tidak akan bisa menyelesaikannya di kontes.

**Menebak hal yang salah dan tidak menemukan counterexample-nya.**  
Ini adalah harga yang harus dibayar dari proses menebak. Namun, Anda harus bertanya pada diri sendiri apakah counterexample-nya mudah ditemukan. Jika itu adalah sesuatu yang sederhana (misalnya: semua elemen bernilai sama), maka Anda sebaiknya berpikir lebih banyak contoh di kontes-kontes berikutnya.

---

## FAQ

**Saya menebak solusi dan semua orang di sekitar saya menyebut saya curang!**  
_Sisi gelap dari kenegarawan Rusia adalah jalan menuju banyak kemampuan yang dianggap tidak alami oleh sebagian orang._

**Tapi menebak secara acak itu tidak menyenangkan!**  
Saya juga tidak menganggap itu menyenangkan. Namun sayangnya, karena **Codeforces hanya terdiri dari soal-soal dengan kadar “ke-Rusia-an” yang tinggi**, maka menebak adalah cara tercepat untuk berkembang menurut saya. Mungkin Anda bisa meminta Mike untuk mengadakan soal-soal yang memiliki unsur lebih banyak “ke-Cina-an” atau “ke-Amerika-an”, agar kita tidak dipaksa untuk menebak selama kontes.


 Saya akan mengakhiri blog ini dengan _kode untuk menebak secara acak_:


*Pembuktian adalah kebohongan; hanya ada AC.*  
*Melalui tebakan, aku mendapatkan kode.*  
*Melalui kode, aku mendapatkan AC.*  
*Melalui AC, rating-ku meningkat.*  
*Ke-Rusia-an akan membebaskanku.*

— Darth Luo, mungkin

---

## Eksperimen

**Pertanyaan:** Apakah komunisme itu ilmu atau seni?  
**Jawaban:** Tentu saja itu seni. Kalau itu ilmu, mereka pasti bereksperimen pada tikus dulu!

— Seorang grandmaster Soviet, mungkin

---

Saya sebenarnya penasaran seberapa besar menebak secara acak bisa membantu peserta Divisi 3 dan Divisi 2. Jika Anda merasa yakin dengan tulisan saya, mungkin Anda bisa mencobanya pada beberapa soal yang berada di sekitar rating Anda, dan beri tahu saya pengalaman Anda di kolom komentar! Ini akan membantu saya memahami seberapa efektif metode ini. Terima kasih!

