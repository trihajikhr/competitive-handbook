---
obsidianUIMode: preview
note_type: latihan
latihan: Kombinasi Dengan Pengulangan
sumber:
  - chatgpt.com
tags:
  - combinatorics
date_learned: 2025-08-12T01:15:00
---
---
# Kue Ulang Tahun Berlapis 🎂

Sebuah toko kue punya $n$ rasa kue berbeda.

Seorang pembeli ingin memesan $k$ lapis kue untuk ulang tahun temannya.
Aturan pemesanan:

* Setiap lapisan boleh memakai rasa yang sama atau berbeda.
* Urutan lapisan **tidak penting** (lapisan vanilla di atas coklat dianggap sama dengan coklat di atas vanilla).

Berapa banyak cara berbeda pembeli dapat memilih rasa untuk $k$ lapis kuenya?

**Input format:**

```
n k
```

**Output format:**

```
jumlah_cara
```

**Batasan:**

* $1 \le n \le 50$
* $1 \le k \le 50$

**Contoh:**

```
Input:
3 2

Output:
6
```

💡 **Hint:** Ini bukan kombinasi biasa, tapi **kombinasi dengan pengulangan** (*combinations with repetition*). Rumusnya mirip kombinasi, tapi dengan:

$$
\binom{n + k - 1}{k}
$$

Kalau mau, kamu bisa langsung coba implementasi, nanti aku cek.


<br/>

---
# Jawaban

Berikut adalah jawaban yang sudah benar:

```cpp
#include <iostream>
using namespace std;

long long nCr(int n, int r) {
    r = min(r, n - r); // simetri kombinasi
    long long res = 1;
    for (int i = 1; i <= r; i++) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << nCr(n + k - 1, k) << '\n';
    return 0;
}
```

<br/>

---
# Editorial
## Rumusan Solusi

### 1 | Identifikasi Masalah
Kita punya:

* $n$ = jumlah rasa berbeda
* $k$ = jumlah lapisan kue yang akan dipilih
  Aturan:
* Rasa boleh diulang (boleh semua lapisan rasa yang sama).
* Urutan **tidak penting** (Coklat–Vanilla sama dengan Vanilla–Coklat).


### 2 | Mengapa bukan kombinasi biasa?

* Kombinasi biasa $\binom{n}{k}$ mengasumsikan **tidak ada pengulangan**.
* Di soal ini pengulangan **boleh**, sehingga harus pakai **kombinasi dengan pengulangan** (*combinations with repetition*).

### 3 | Modelisasi masalah — “Stars and Bars”
Bayangkan $k$ lapisan kue sebagai **bintang** `*`.

Kita ingin menaruh bintang-bintang ini ke dalam $n$ kotak (tiap kotak = rasa kue), boleh lebih dari 1 bintang per kotak.

Untuk memisahkan kotak, kita butuh $n-1$ **batang** `|` sebagai pembatas.
Contoh:

```
**|*|    → 2 lapis rasa 1, 1 lapis rasa 2, 0 lapis rasa 3
```

Total slot yang akan diisi = jumlah bintang + jumlah batang:

$$
k + (n - 1) = n + k - 1
$$

Kita cukup memilih posisi batang (atau bintang), sehingga jumlah cara =:

$$
\binom{n + k - 1}{n - 1}
$$

Karena sifat simetri kombinasi:

$$
\binom{n + k - 1}{n - 1} = \binom{n + k - 1}{k}
$$


### 4 | Rumus akhir:

$$
\text{Jawaban} = \binom{n + k - 1}{k}
$$

dengan $\binom{\cdot}{\cdot}$ adalah kombinasi biasa.


### 5 | Kompleksitas

* Menggunakan **multiplicative formula** untuk kombinasi: $O(k)$ waktu, memori O(1).
* Aman untuk $n, k \le 50$ dengan `long long`.


### 6 | Contoh perhitungan manual
Input:

```
n = 3, k = 2
```

Hitung:

$$
\binom{3 + 2 - 1}{2} = \binom{4}{2} = 6
$$

Enam kemungkinan:

```
(1,1), (1,2), (1,3), (2,2), (2,3), (3,3)
```

(Setiap angka = kode rasa kue)

---
> intinya gini kan: Jika kita diminta membuat kombinasi dari $n$ dan $k$, dimana nilai dari kombinasi boleh terdiri dari susunan angka yang sama, maka gunakan rumus:
> $$\binom{n+k-1}{k}$$ 

Betul 👍, itu inti konsepnya.

Kalau dibahas formalnya:

* **Kombinasi biasa (tanpa pengulangan)** → pilih $k$ item berbeda dari $n$ item, **tidak boleh** ada yang terulang ⇒ rumus:

  $$
  \binom{n}{k}
  $$
* **Kombinasi dengan pengulangan** → pilih $k$ item dari $n$ item, **boleh** ada yang terulang ⇒ rumus:

  $$
  \binom{n+k-1}{k}
  $$

  Ini berasal dari konsep **Stars and Bars** (bintang mewakili item, batang mewakili pemisah antar jenis).

Syaratnya:

1. $n \ge 1$
2. $k \ge 0$
3. Urutan **tidak diperhitungkan** (kalau urutan dihitung → itu jadi permutasi).

<br/>

---
## Visualisasi Solusi

### 1 | Intuisi Awal

Misal kita punya:

* $n$ jenis item (contoh: rasa es krim: Vanila, Coklat, Stroberi).
* Mau pilih total $k$ item (lapisan es krim).
* **Boleh ada rasa yang sama lebih dari satu kali.**
* Urutan tidak penting (Vanila + Coklat = Coklat + Vanila).

### 2 | Representasi Stars and Bars

* Kita gambarkan **bintang (\*)** = 1 item yang kita pilih.
* Kita gambarkan **batang (|)** = pemisah antara jenis item.

Contoh:
$n = 3$ (Vanila, Coklat, Stroberi)
$k = 4$ (4 scoop es krim total)

Satu kombinasi bisa ditulis seperti:

```
**|*|*    → 2 Vanila, 1 Coklat, 1 Stroberi
```

### 3 | Menghitung Banyak Susunan

Untuk $n$ jenis item:

* Kita butuh **n − 1 batang** untuk memisahkan.
* Kita punya $k$ bintang (total item).

Total simbol = $k$ bintang + $(n - 1)$ batang

$$
\text{total simbol} = k + (n - 1) = n + k - 1
$$

### 4 | Memilih Posisi Batang atau Bintang

Kita bisa:

* Pilih posisi **bintang** dari total simbol, atau
* Pilih posisi **batang** dari total simbol.

Jumlah kombinasi = banyak cara memilih $k$ posisi untuk bintang dari total $n + k - 1$ posisi:

$$
\binom{n+k-1}{k}
$$

atau setara dengan:

$$
\binom{n+k-1}{n-1}
$$

(keduanya sama karena sifat simetri $\binom{a}{b} = \binom{a}{a-b}$).

### 5 | Contoh Kecil

$n = 3, k = 2$
Total simbol = $3 + 2 - 1 = 4$
Pilih 2 posisi untuk bintang ⇒ $\binom{4}{2} = 6$ kombinasi:

```
**||  → 2,0,0
*|*|  → 1,1,0
*||*  → 1,0,1
|**|  → 0,2,0
|*|*  → 0,1,1
||**  → 0,0,2
```
