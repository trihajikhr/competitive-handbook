---
obsidianUIMode: preview
note_type: STRIKE
kode_soal: F
judul_FAST: Kartu Truf
teori_FAST: GEMASTIK
sumber:
  - tlx-toki
date_learned: 2025-08-06T23:48:00
tags:
  - STRIKE
---
Sumber:

> [!NOTE] ⚔️ Teori STRIKE:
>1. Precompute kombinasi $\binom{n}{k}$ sekali di awal program untuk menghindari penghitungan faktorial berulang saat runtime — ini mempercepat algoritma secara drastis di soal kombinatorik.
>2. Gunakan Pascal’s Triangle sebagai pendekatan efisien untuk membangun tabel kombinasi hingga batas maksimum $n$ yang dibutuhkan, tanpa perlu library atau operasi berat.
>3. Precompute - Teknik kerja berat diawal, tapi kerja super cepat setelahnya. Dengan menghilangkan kemungkinan pemanggilan fungsi berat berkali-kali.
>4. Kadang array sengaja dibuat lebih besar dari yang dibutuhkan, bukan karena ceroboh, tapi sebagai **tameng terhadap error**. Teknik ini disebut _buffer-overprovisioning_, berguna untuk mencegah **akses memori di luar batas saat input atau loop nyasar.**

> 

<br/>

---
# Kartu Truf

Truf adalah permainan kartu yang populer di Indonesia. Pada soal ini, Anda akan berhadapan dengan versi truf yang disederhanakan. Anda tidak perlu paham permainan truf yang sesungguhnya untuk menyelesaikan soal ini.

Pada permainan ini, terdapat 4 pemain, termasuk Anda. Setiap pemain pada awalnya memegang 13 kartu. Anda memiliki giliran pertama, dan akan memulai ronde pertama. Ronde pertama dilakukan sebagai berikut. Anda mengeluarkan salah satu kartu dari 13 kartu yang Anda pegang.  Kemudian, masing-masing dari ketiga pemain sisanya mengeluarkan sebuah kartu menurut peraturan berikut:

- Harus memiliki jenis yang sama dengan kartu yang Anda keluarkan.
- Jika tidak terdapat kartu dengan jenis yang sama, kartu apapun boleh dikeluarkan.

Pemenang dari ronde pertama adalah pemain yang mengeluarkan kartu dengan nilai tertinggi yang memiliki jenis yang sama dengan kartu yang Anda keluarkan.

Sebagai pemegang giliran pertama, Anda ingin mengetahui peluang Anda memenangkan ronde pertama, untuk setiap pilihan 13 kartu yang mungkin Anda keluarkan pertama kali. Berhubung Anda baru pertama kali bermain kartu truf, maka: setiap pemain selain Anda ingin Anda menang, dan **akan mengeluarkan kartu sedemikian rupa untuk membantu Anda memenangkan ronde pertama**.

Catatan:

- Terdapat 4 jenis kartu: D (diamond), C (club), H (heart), S (spade).
- Setiap jenis memiliki 13 nilai, dari nilai terkecil ke terbesar: 2, 3, 4, 5, 6, 7, 8, 9, T, J, Q, K, A. (Perhatikan bahwa nilai 10 diganti dengan T.)
- 52 kartu tersebut dikocok lalu dibagikan kepada 4 pemain dengan distribusi seragam (_uniform_).

### Format Masukan

Baris pertama berisi sebuah bilangan bulat B yang menyatakan banyaknya kasus uji.

Setiap kasus uji terdiri atas sebuah baris berisi 13 kartu yang Anda pegang. Setiap kartu terdiri atas tepat 2 karakter: jenis dan nilai. Perhatikan contoh masukan untuk detil formatnya.

### Format Keluaran

Untuk setiap kasus uji:

Keluarkan 13 baris berisi kartu diikuti dengan peluang memenangkan ronde pertama apabila Anda mengeluarkan kartu tersebut, dengan tepat 5 angka di belakang penanda desimal. Kartu-kartu dicetak sesuai urutan pada masukan. Perhatikan contoh keluaran untuk detil formatnya.

Keluaran akan dianggap benar apabila setiap peluang berbeda maksimal 0,00001 dari keluaran juri.

Keluarkan baris kosong di antara kasus-kasus uji.

### Contoh Masukan

```
2
6D 8C 9C TC 9H JH KH AH 3S 4S 7S 9S JS
6D JD QD 6C 7C JC 3H KH 2S 8S TS JS AS
```

### Contoh Keluaran

```
6D: 48.74964%
8C: 81.45732%
9C: 81.45732%
TC: 81.45732%
9H: 91.60454%
JH: 96.80539%
KH: 100.00000%
AH: 100.00000%
3S: 0.00628%
4S: 0.00628%
7S: 29.98808%
9S: 54.97518%
JS: 73.72181%

6D: 50.34658%
JD: 94.89091%
QD: 94.89091%
6C: 50.34658%
7C: 50.34658%
JC: 89.69690%
3H: 0.00001%
KH: 98.87638%
2S: 0.00000%
8S: 73.72181%
TS: 86.49864%
JS: 86.49864%
AS: 100.00000%
```

### Batasan

- 1 ≤ B ≤ 52
- Setiap masukan dijamin merepresentasikan 52 kartu yang _valid_.

<br/>

---
# Sesi STRIKE ⚔️


<br/>

---


# Jawaban dan Editorial

Misalkan kartu yang kita keluarkan berjenis $S$. Misalkan di tangan kita terdapat $K$ buah kartu berjenis $S$. Artinya, terdapat $12 - K$ kartu berjenis $S$ yang ada di tangan pemain-pemain selain kita. Kita bisa lakukan _brute force_ untuk mencoba semua distribusi $12 - K$ kartu pada 3 pemain lainnya; yakni terdapat $3(12 - K)$ kemungkinan. Jawaban akhirnya adalah total peluang distribusi yang menyebabkan Anda menang.

Untuk menentukan apakah sebuah distribusi menyebabkan kita menang, cukup mudah. Kita akan menang hanya jika setiap pemain lainnya tidak memiliki kartu berjenis $S$ yang bernilai lebih tinggi daripada kartu yang hendak Anda keluarkan.

Yang lebih menantang adalah menghitung peluang sebuah distribusi terjadi. Misalkan $C(i, j) =$ banyaknya cara memilih $j$ benda dari $i$ benda. Pertama-pertama, hitung ada berapa cara pembagian 52 kartu kepada 4 orang, dengan 13 kartu kita sudah ditentukan dari awal. Banyaknya cara adalah:

$$C(39, 13) * C(26, 13) \dots (i)$$

Kemudian, misalkan dalam distribusi tersebut orang 1 mendapat $A$ buah kartu berjenis $S$, orang 2 mendapat $B$ buah kartu berjenis $S$, dan orang 3 mendapat $C$ buah kartu berjenis $S$. Banyaknya cara distribusi ini terjadi adalah

$$C(39, 13 - A) * C(12 - K, A) * C(39 - (13 - A), 13 - B) * C(12 - K - A, B) \dots (ii)$$

Peluang sebuah distribusi terjadi adalah hasil pembagian ekspresi (i) dengan (ii).

Catatan: alih-alih _brute-force_, dapat juga dilakukan DP untuk menghitung semua distribusi. Observasinya adalah: untuk setiap pemain lainnya, kita hanya peduli berapa banyaknya kartu yang nilainya lebih rendah dan banyaknya kartu yang lebih tinggi daripada kartu yang kita pegang. Sisanya diserahkan kepada pembaca.

---
Jawaban dari salah satu pengguna yang benar:

```cpp

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int testCases;
double combination[100][100];
string playerHand[15];
bool cardUsed[15];
int cardValues[256];

void calculateCombinations() {
   for (int i = 0; i <= 52; i++) {
      combination[i][0] = 1;
      for (int j = 1; j <= i; j++) {
         combination[i][j] = combination[i - 1][j] + combination[i - 1][j - 1];
      }
   }
}

void mapCardValues() {
   for (char rank = '2'; rank <= '9'; rank++) {
      cardValues[rank] = rank - '2';
   }
   cardValues['T'] = 8;
   cardValues['J'] = 9;
   cardValues['Q'] = 10;
   cardValues['K'] = 11;
   cardValues['A'] = 12;
}

double calculateProbability(int low, int high, int player, int remainingCards) {
   if (player == 3)
      return 1;

   double result = 0;

   for (int lowCount = 0; lowCount <= low; lowCount++) {
      for (int highCount = 0; highCount <= high; highCount++) {
         if (lowCount + highCount <= remainingCards) {
            result += combination[low][lowCount] * combination[high][highCount] *
                      combination[remainingCards][13 - lowCount - highCount] *
                      calculateProbability(low - lowCount, high - highCount, player + 1,
                                           remainingCards - (13 - lowCount - highCount));
         }
      }
   }

   return result;
}

void determineCardProbability(int lowCount, int highCount) {
   double probability = calculateProbability(lowCount, highCount, 0, 39 - lowCount - highCount);
   double totalCombinations = combination[13][13] + combination[26][13] + combination[13][13];
   double result = (probability * 100) / totalCombinations;
   cout << fixed << setprecision(6) << result << " %\n";
}

void processTestCase() {
   int lowCount, highCount;

   memset(cardUsed, false, sizeof(cardUsed));

   for (int i = 0; i < 13; i++) {
      cin >> playerHand[i];
      int cardValue = cardValues[playerHand[i][0]];
      int cardSuit = playerHand[i][1];
      cardUsed[cardValue] = true;
   }

   lowCount = 0;
   highCount = 0;

   for (int v = 0; v < 13; v++) {
      if (!cardUsed[v])
         lowCount++;
   }
   for (int v = cardValues['J']; v <= 12; v++) {
      if (!cardUsed[v])
         highCount++;
   }

   cout << playerHand[0] << " : ";
   determineCardProbability(lowCount, highCount);
}

int main() {
   calculateCombinations();
   mapCardValues();

   cin >> testCases;
   for (int i = 0; i < testCases; i++) {
      if (i > 0)
         cout << '\n';
      processTestCase();
   }

   return 0;
}
```

<br/>

---
# Analisis Pribadi

Ini benar-benar soal yang sulit, aku harus membedah kode milik orang lain untuk memahaminya:

```cpp
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
```

Deklarasi beberapa library yang digunakan, namun sepertinya beberapa library tidak digunakan sepenuhnya saat penulisan kode, seperti header `algorithm` dan juga header `vector`. Tidak lupa juga langsung mendeklarasikan `using namespace std`.

Kita bahas mulai dari `main` supaya lebih urut:

---

## 1 | main()

```cpp
int main() {
   calculateCombinations();
   mapCardValues();

   cin >> testCases;
   for (int i = 0; i < testCases; i++) {
      if (i > 0)
         cout << '\n';
      processTestCase();
   }
   return 0;
}
```

Pada bagian main, dipanggil 2 fungsi, sebelum test case pertama dipanggil. Yaitu fungsi:
- `calculateCombination()`
- `mapCardValues()`

Pembahasan kedua fungsi ini akan dibahas dibawah. Tampaknya kita perlu mendeklarasikan beberapa hal sebelum program memulai pengetesan pertama.

Untuk proses inputan test case, kita mengatasinya dengan perulangan, dimana setiap testcase akan diproses oleh fungsi `procesTestCase()`. Lalu, karena hasil dari setiap testcase wajib dipisahkan oleh pemisah satu baris kosong, tepat ketika testcase kedua dan seterusnya, pemberian baris kosong mulai berlaku, dengan mekanisme:

```cpp
if(i > 0) cout << '\n';
```

Pada bagian main, memang tidak terlalu banyak kode yang ditunjukan, kita beralih ke fungsi yang harus kita bedah pertama.

<br/> <br/>

---
## 2 | calculateCombinations()

Fungsi `calculateCombinations()` itu **mengisi tabel kombinasi** (alias nilai $\binom{n}{k}$ atau “n choose k”) yang sering dipakai dalam probabilitas atau komputasi kombinatorik.

### 💡 Tujuan utamanya:

Untuk **menghindari penghitungan kombinasi berulang-ulang** selama program jalan, karena:

$$
\binom{n}{k} = \frac{n!}{k!(n-k)!}
$$

...itu mahal kalau dihitung terus-menerus. Jadi kita **precompute semua kombinasi yang mungkin**, simpan di array `combination[n][k]`.

### 🔍 Penjelasan fungsi:

```cpp
void calculateCombinations() {
    for (int i = 0; i <= 52; i++) {
        combination[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            combination[i][j] = combination[i-1][j] + combination[i-1][j-1];
        }
    }
}
```

Ini sebenarnya bikin **Pascal’s Triangle** — struktur klasik buat nyusun semua kombinasi:

$$
\binom{n}{k} = \binom{n-1}{k} + \binom{n-1}{k-1}
$$

Misalnya:

* $\binom{5}{2} = \binom{4}{2} + \binom{4}{1} = 6 + 4 = 10$

### 📦 Kenapa ini penting di program?

Program kamu ngitung kemungkinan kombinasi **kartu-kartu**:

* Misalnya memilih 13 kartu dari 39 kartu sisa,
* Atau memilih X kartu rendah dan Y kartu tinggi,
* Maka kombinasi kayak $\binom{13}{5}$ itu muncul **ribuan kali** selama rekursi.

Kalau dihitung dari nol terus-terusan? **Lambat.**
Kalau disimpan di awal? **Cepat. Efisien.**

### 🧠 Singkatnya:

Fungsi `calculateCombinations()` itu bikin cache semua nilai kombinasi $\binom{n}{k}$ sampai $n = 52$, supaya:

* Kalkulasi probabilitas kartu lebih cepat,
* Tidak ngulang-ngulang faktorial,
* Lebih hemat waktu (dari O(n!) ke O(1) lookup).

### Analisis Pribadi
Serius, ini soal bikin puyeng, mahamin satu fungsi ini aja butuh waktu lama. Tapi akhirnya tidak sia-sia.

Jika semisal kita ingin mengambil 4 kartu dari 52 kartu yang ada, berapa banyak cara yang mungkin? Berapa kombinasi yang mungkin?

Mungkin pakai rumus:

$$C(n,k) = \frac{n!}{k!(n-k)!}$$

Nah, cara jalanin rumus diatas bagaimana? Adalah dengan membuat fungsi faktorial, caranya tidak perlu dijelaskan, cukup perulangan sambil dikalikan, simple. Dan lakukan pembagian dan perkalian dari hasil faktorial supaya sesuai dengan rumus diatas.

Terus, jika aku bertanya lagi, berapa kombinasi dari mengambil 39 kartu dari 52? Oke, mungkin kamu gunakan rumus diatas, lagi, kan? Dan jalankan fungsi faktorial lagi.

Sekarang bayangkan, kamu punya 52 kartu, dan kamu harus tahu kombinasi yang mungkin dari setiap pengambilan kartu tersebut, mulai dari cuma diambil 1, hingga diambil semua kartu yang ada?

Apakah bisa? Bisa. BISA MELEDAK PC MU MAKSUDNYA!

Jika kita mencari setiap kombinasi yang mungkin dari nilai $n$ dan $k$ yang berbeda-beda, dengan menunggu inputan dari user, Coba pikir! Entah berapa kali kita harus menjalankan rumus diatas, dan panggil fungsi faktorial terus-terusan, ini tidak efisien, dan jelas akan memakan waktu lama. FIX bakal kena runtime limit!

Untuk mengatasi hal itu, kita lakukan Precompute. Yaitu alih-alih kita memproses kombinasi setelah user memasukan kombinasi yang ingin mereka cari, kita siapkan langsung saja semua kombinasi yang mungkin dari semua kemungkinan pilihan yang tersedia, dimana $1 \leq n \leq 52$ dan $1 \leq k \leq n$. Ini membuat kita bisa tahu nilai dari suatu kombinasi $n$ dan $k$, bukan dengan menghitung lagi, tapi dengan menggunakan $n$ dan $k$ sebagai cara untuk mengakses array 2 dimensi yang menyimpan nilai-nilai tersebut, dan mendapatkan nilai kombinasi hanya dengan $O(1)$ kompleksitas.

See? Kerja berat diawal, tapi setelahnya lega, inilah tujuan dari kita membuat fungsi ini. Membuat pencarian kombinasi memiliki kompleksitas cukup $O(1)$ setelah precompute dilakukan diawal.

Intinya, fungsi ini menyiapkan table hasil kombinasi, supaya operasi selanjutnya menjadi lebih efisien!

Baiklah, sekarang fungsi `calculateCombination()` dan array 2 dimensi:

```cpp
combination[100][100];
```

...berhasil kita isi.

<br/><br/>

---

## mapCardValues()

```cpp
void mapCardValues() {
   for (char rank = '2'; rank <= '9'; rank++) {
      cardValues[rank] = rank - '2';
   }
   cardValues['T'] = 8;
   cardValues['J'] = 9;
   cardValues['Q'] = 10;
   cardValues['K'] = 11;
   cardValues['A'] = 12;
}
```



Diketahui bahwa setiap jenis kartu — baik itu Hearts, Spades, Clubs, maupun Diamonds — memiliki nilai **rank** dari yang paling rendah yaitu **2**, hingga yang paling tinggi yaitu **A** (Ace).
Untuk mempermudah proses **pengecekan nilai kartu**, kita bisa menerapkan strategi **precompute**. 

Caranya adalah dengan memetakan setiap karakter rank kartu (`'2'` sampai `'A'`) ke dalam **array** bernama `cardValues[]`, yang menyimpan nilai numerik dari kartu tersebut (dalam range 0–12).

Dengan strategi ini, kita **tidak perlu menghitung atau mencocokkan karakter setiap kali input kartu diterima**. Cukup dengan mengakses array menggunakan karakter rank sebagai indeks (`cardValues[card[0]]`), kita langsung dapatkan nilai numeriknya.

Pendekatan ini **mirip dengan strategi precompute** pada kombinasi sebelumnya: kita melakukan kerja berat di awal, agar proses berikutnya berjalan cepat dan efisien, hanya dengan akses array **$O(1)$**.

<br/><br/

---
## processTestCase();

Karena kita mencoba urut dalam membedah program ini, maka fungsi selanjutnya yang perlu dibedah adalah `processTestCase();`.

```cpp
void processTestCase() {

   int lowCount, highCount;
   memset(cardUsed, false, sizeof(cardUsed));
   
   for (int i = 0; i < 13; i++) {
      cin >> playerHand[i];
      int cardValue = cardValues[playerHand[i][0]];
      int cardSuit = playerHand[i][1];
      cardUsed[cardValue] = true;
   }
   
   lowCount = 0;
   highCount = 0;
   for (int v = 0; v < 13; v++) {
      if (!cardUsed[v])
         lowCount++;
   }
   
   for (int v = cardValues['J']; v <= 12; v++) {
      if (!cardUsed[v])
         highCount++;
   }
   
   cout << playerHand[0] << " : ";
   determineCardProbability(lowCount, highCount);
}
```

Pertama, kita buat variabel `lowCount` dan juga `highCount`, penjelasan untuk kegunaan dari variabel ini akan dijelaskan dibagian bawah.

Sekarang, kiga fokus pada baris ini:

```cpp
memset(cardUsed, false, sizeof(cardUsed));
```

Ini adalah fungsi untuk bahasa C, dimana fungsi `memset()` berguna untuk mengisi semua nilai dalam array menjadi nilai tertentu. Fungsi diatas dipanggil, untuk mengisi seluruh array `cardUsed()` dengan nilai false semuanya. 

Ini sebenarnya sama saja dengan syntax berikut jika semisal array yang kita gunakan bukan C-Style array, melainkan mengacu pada C++ modern seperti  `std::array`:

```cpp
fill(begin(cardUsed), end(cardUsed), false);
```

... atau jika semisal kita menggunakan vector, deklarasikan dan langsung inisialisasi ukuran dan nilainya menjadi false langsung semujanya:

```cpp
vector<bool> cardUsed(15, false); // langsung reset tiap test case
```

Lebih aman dan cocok untuk C++.

Sekarang pertanyaan, kenapa dibuat array `cardUsed[]` memiliki ukuran hingga 15? **array ini mungkin dibuat oversized secara sengaja**, mungkin untuk mencegah **access out of bounds** karena input tidak valid atau untuk **defensive safety**. Karena jika dipikir, kartu yang kita punya hanya 13, dan ini malah buat 15. Tapi tidak usah terlalu dipikirkan lah, yang penting tahu alasanya dan kenapa begini.

Nah, setiap test case, kita menerima hingga 13 inputan kan. Nah program inputan ada di blok perulangan ini:

```cpp
for (int i = 0; i < 13; i++) {
  cin >> playerHand[i];
  int cardValue = cardValues[playerHand[i][0]];
  int cardSuit = playerHand[i][1];
  cardUsed[cardValue] = true;
}
```

Nah, fungsi ini bekerja dengan cara sudah menyiapkan array `string playerHand[15]`, dimana setiap inputan dari user seperti jenis kartu dan nilai kartu, ditampung sebagai string, dan disimpan ke dalam array. Lagi lagi ukuran yang dibuat disini adalah 15, mungkin untuk defensive safety  seperti sebelumnya. 

Disetiap perulangan, kita membuat variabel `cardValue` yang digunakan untuk mengisi nilai dari `cardValues[playerHand[i][0]]`. Nah ini maksudnya gimana nih? Diapain nih?

Ingat lagi bahwa array `playerHand[]` itu digunakan untuk menyimpan tipe data string. Jadi sistemnya itu seperti ini:

Kita ambil imputan dengan cara menggunakan elemen dari array sebagai tempat menerim inputanya langsung, ngga diterima sama variabel. Langsung aja pakai arraynya langsung.

Nah sekarang, array `playerHand[i]` berisi kartu yang baru saja diinputkan. Kita cek berapa nilai dari kartu tersebut, yaitu cek karakter pertamanya. Caranya?

Kita harus cek nilainya dari array `cardValues[]` yang sudah berisi Precompute nilai-nilai tiap kartu. Kita ambil karakter pertama dari inputan yang tersimpan di `playerHand[i]`, lalu akses karakter pertama dengan `playerHand[i][0]`, kita akses array, baru akses string, makanya terlihat kaya kita akses array dua dimensi, padahal tidak.

Setelah karakter pertama berhasil didapat, kita gunakan karakter pertama itu untuk mengakses nilai di `cardValues[]`, ingat lagi bahwa tiap karakter itu memiliki representasi ASCII, sehingga kita gunakan representasi tersebut.

Mungkin jika kamu menggunakan unordered map, akan jauh lebih mudah membuatnya, daripada pakai array manual.

Nah, lalu, nilai variabel dari `cardSuit`, itu berisi jenis kartunya, baca karakter kedua dari inputan yang diberikan.

Lalu, kita tandai setiap `cardUsed[]` menjadi true, jika kartu nilai tertentu sudah ada ditangan kita.

```cpp
	lowCount = 0;
   highCount = 0;

   for (int v = 0; v < 13; v++) {
      if (!cardUsed[v])
         lowCount++;
   }
   
   for (int v = cardValues['J']; v <= 12; v++) {
      if (!cardUsed[v])
         highCount++;
   }

   cout << playerHand[0] << " : ";
   determineCardProbability(lowCount, highCount);
}
```

Dibawahnya, kita isi `lowCount=0` dan juga `highCount=0`.

Nilai dari `lowCount` akan menyimpan banyaknya nilai kartu berapapun yang belum kita miliki, atau hitung banyaknya nilai `false` pada array `cardUsed[]`.

`highCount` digunakan untuk menghitung berapa banyak kartu tinggi yang belum muncul di tangan pemain, atau dengan kata lain, yang masih mungkin muncul dari sisa tumpukan.. Nilai dari `v = vardValues['J']` itu maksudnya kita mengakses indeks ke kode ASCII karakter J, yang mana berisi nilai 9.

Aku tidak tahu kenapa penulis program seribet ini, kenapa tidak tulis aja langsung `int v = 9` 😂. 

> Tapi sebenarnya ini **lebih readable** kalau kamu ngerti mapping-nya. Kalau nanti `'J'` berubah mapping-nya (misal di set yang beda), `cardValues['J']` tetap aman. Jadi ini soal **maintainability**, bukan karena males nulis angka 😄

Tapi intinya `highCount` digunakan untuk menghitung banyaknya kartu angka yang kita punya. Oh ya, kartu T hanyalah pengganti dari nilai 10, karena pada dasarnya kartu T tidak ada didalam kartu kan.

Nah, sekarang kita memiliki nilai:
- `lowCount` yang berisi banyaknya kartu dengan nilai-nilai tertentu yang kita punya, tidak peduli jenis kartunya dulu. 
- `highCount` yang berisi kartu-kartu tinggi yang kita punya.

Nah setelah itu, program akan mengelurarkan kartu, dan " : ", yang artinya selanjutnya diproses di fungsi selanjutnya, yaitu fungsi `determineCardProbability()`.

<br/><br/>

---
## determineCardProbability()

```cpp
void determineCardProbability(int lowCount, int highCount) {
   double probability = calculateProbability(lowCount, highCount, 0, 39 - lowCount - highCount);
   double totalCombinations = combination[13][13] + combination[26][13] + combination[13][13];
   double result = (probability * 100) / totalCombinations;
   cout << fixed << setprecision(6) << result << " %\n";
}
```

Oke, karena nama variabelnya panjang-panjang, kita buat lebih singkat dulu saja oke:

```cpp
void determineCardProbability(int low, int high) {
   double prob = calculateProbability(low, high, 0, 39 - low - high);
   
   double combTotal = combination[13][13] + combination[26][13] + combination[13][13];
   
   double result = (probability * 100) / combTotal;
   cout << fixed << setprecision(6) << result << " %\n";
}
```

Oke, fungsi ini menggunakan 2 parameter, dan langsung mendeklarasikan variabel `prob` bertipe double, yang akan menampung hasil dari fungsi `calculateProbability()`.

<br/><br/>

---

## calculateProbability()

```cpp
double calculateProbability(int low, int high, int player, int remainingCards) {
   if (player == 3)
      return 1;
   double result = 0;
   for (int lowCount = 0; lowCount <= low; lowCount++) {
      for (int highCount = 0; highCount <= high; highCount++) {
         if (lowCount + highCount <= remainingCards) {
            result += combination[low][lowCount] * 
            combination[high][highCount] *
            combination[remainingCards][13 - lowCount - highCount] *
            calculateProbability(low - lowCount, high - highCount, player + 1,remainingCards - (13 - lowCount - highCount));
         }
      }
   }
   return result;
}
```


Fungsi ini bertujuan menghitung total jumlah cara distribusi kartu yang tersisa ke pemain lain, berdasarkan berapa banyak kartu rendah dan tinggi yang tersisa, serta pemain keberapa yang sedang diproses.

```cpp
double calculateProbability(int low, int high, int player, int remainingCards)
```

**Parameter:**

- `low`: jumlah kartu rendah (angka < J) yang belum dibagikan.
    
- `high`: jumlah kartu tinggi (J, Q, K, A) yang belum dibagikan.
    
- `player`: indeks pemain saat ini (0-based). Misalnya player = 0 berarti pemain kedua (selain kita).
    
- `remainingCards`: jumlah total kartu yang tersisa di dek (belum dibagikan).
    

Fungsi ini bekerja secara rekursif. Pada setiap tahap, ia mencoba semua kemungkinan jumlah kartu rendah dan kartu tinggi yang bisa diberikan ke pemain saat ini. Karena setiap pemain harus menerima 13 kartu, maka sisanya (13 - lowCount - highCount) diisi oleh kartu yang bukan low maupun high.

Setiap kombinasi valid akan dihitung berapa banyak caranya:

- `C(low, lowCount)` untuk memilih `lowCount` kartu rendah.
    
- `C(high, highCount)` untuk memilih `highCount` kartu tinggi.
    
- `C(remainingCards, 13 - lowCount - highCount)` untuk memilih sisanya dari kartu lain.
    

Kemudian, fungsi akan melanjutkan ke pemain berikutnya dengan parameter yang telah diperbarui:

- `low - lowCount`
    
- `high - highCount`
    
- `player + 1`
    
- `remainingCards - (13 - lowCount - highCount)`
    

Jika `player == 3`, berarti semua pemain selain kita telah mendapatkan kartunya, dan fungsi mengembalikan `1` sebagai tanda satu distribusi valid ditemukan.

Seluruh nilai akan dijumlahkan menjadi total `result` yang menunjukkan jumlah cara distribusi kartu sisa ke pemain lain sesuai dengan aturan kombinasi yang diberikan.

