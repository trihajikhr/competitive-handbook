---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1352C
judul_DEATH: K-th Not Divisible by n
teori_DEATH:
sumber:
  - codeforces.com
rating: 1200
ada_tips: false
date_learned: 2025-10-29T13:23:00
tags:
  - binary-search
  - math
---
Sumber: [Problem - 1352C - K-th Not Divisible by n](https://codeforces.com/problemset/problem/1352/C)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1352C-K-th Not Divisible by n

Diberikan sebuah angka berupa $n$ dan $k$. Tugasmu adalah membuat deret angka $1$ menaik, yang mana tidak ada angka yang bisa dibagi oleh $n$, dan tuliskan angka yang berada tepat pada urutan ke $k$ dari deret tersebut.

Contoh, jika $n=3$, dan $k=7$, maka jawabanya adalah $10$, karena bisa dilihat sendiri dari deret berikut:

$$1,2,4,5,7,8,10,11, \dots$$
<br/>

---
# 2 | Sesi Death Ground ⚔️

Aku benar-benar pusing ketika mengerjakan ini. Jadi mari kita lihat penjelasan di bawah!

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Andaikan jawabannya hanyalah bilangan bulat positif ke-$k$ yang harus kita "geser ke kanan" dengan sejumlah angka. Setiap kelipatan dari $n$ menggeser jawaban kita sebesar $1$. Jumlah kelipatan tersebut adalah $\text{need} = \left\lfloor\frac{k-1}{n-1}\right\rfloor$, di mana $\left\lfloor\frac{x}{y}\right\rfloor$ adalah $x$ dibagi dengan $y$ yang dibulatkan ke bawah. Jadi, jawaban akhirnya adalah $k + \text{need}$ (bilangan bulat positif ke-$k$ dengan jumlah yang dibutuhkan dari bilangan bulat yang dilewati, yaitu kelipatan dari $n$).

Anda juga bisa menggunakan *binary search* untuk menyelesaikan masalah ini :)

Implementasi Editorial:

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int need = (k - 1) / (n - 1);
		cout << k + need << endl;
	}
}
```
## 3.2 | Analisis Pribadi

### Cara langsung

Anggaplah kita sedang membuat daftar angka hitungan $(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, ...)$.

1.  Angka Nakal ($n$): Ada satu angka, sebut saja Angka Nakal ($n$). Angka Nakal ini punya "kekuatan" untuk membuat semua kelipatannya (Angka Nakal $\times$ $1$, Angka Nakal $\times$ $2$, dst.) menjadi angka yang harus kita lewati (tidak boleh dihitung).

2.  Mencari Posisi ke-$k$: Kita mau tahu, kalau kita melewati semua kelipatan Angka Nakal ($n$), angka ke-$k$ yang tersisa itu berapa?

    * Contoh: Angka Nakal ($n$) = $3$. Angka yang dilewati adalah $3, 6, 9, 12$, dst.
    * Daftar kita jadi: $1,$ $2$, (lewat $3$), $4$, $5$, (lewat $6$), $7$, $8$, (lewat $9$), $10$, $11$, ...
    * Kita mau cari, misalnya, Angka ke-$5$ ($k=5$).
        * Posisi 1: $1$
        * Posisi 2: $2$
        * Posisi 3: $4$ (seharusnya $3$, tapi $3$ dilewati, jadi kita "geser" ke $4$)
        * Posisi 4: $5$
        * Posisi 5 ($k=5$): $7$ (seharusnya $5$, tapi ada $2$ angka yang dilewati: $3$ dan $6$. Jadi, $5$ + $2$ = $7$).

Ini intinya:

* Jawaban Awal ($k$): Kita mulai dulu dari posisi yang kita mau ($k$).
* Seberapa Jauh Harus Geser? ($\text{need}$): Kita perlu tahu **berapa banyak** kelipatan Angka Nakal ($n$) yang sudah kita lewati sebelum kita sampai di posisi jawaban akhir. Setiap kelipatan yang dilewati membuat jawaban kita harus "bergeser" ke kanan sebanyak $1$.

Rumus Sederhananya:

$$\text{Jawaban Akhir} = k + \text{need}$$

Nah, sekarang bagaimana cara mencari $\text{need}$ (jumlah pergeseran)?

$$\text{need} = \left\lfloor\frac{k-1}{n-1}\right\rfloor$$

Artinya:

1.  **$k-1$**: Ini seperti melihat semua angka di belakang posisi $k$.
2.  **$n-1$**: Ini seperti melihat berapa banyak angka normal yang ada di antara setiap Angka Nakal. (Contoh $n=3$, kita hitung 1, 2, lalu 3 dilewati. Ada $3-1 = 2$ angka normal. Kita hitung 4, 5, lalu 6 dilewati. Ada $n-1=2$ angka normal).
3.  $\left\lfloor\frac{k-1}{n-1}\right\rfloor$: Kita membagi posisi yang dicari dengan "jarak normal" antar kelipatan $n$. Ini memberi tahu kita sudah berapa banyak kelipatan $n$ yang kita lewati.
4.  $\lfloor \dots \rfloor$: Tanda ini artinya dibulatkan ke bawah. Kita hanya peduli dengan jumlah kelipatan $n$ yang *sudah penuh dilewati*.

#### Penjelasan Tambahan

```ad-faq
Kenapa harus melakukan operasi $k-1$ dan $n-1$ sebelum mengoperasikan keduanya dalam pembagian?
```


Itu pertanyaan yang sangat bagus! Pengurangan $k-1$ dan $n-1$ ini adalah trik yang sangat cerdas dalam matematika diskrit (hitungan angka) agar kita mendapatkan hasil pembagian yang tepat untuk jumlah pergeseran yang dibutuhkan.

Intinya adalah, kita menghitung berapa kali kita "melewati" kelipatan $n$ di sepanjang jalan menuju angka yang kita cari.

##### Alasan $n$ Dikurangi Satu ($n-1$)

Mari kita lihat polanya, di mana $n$ adalah Angka Nakal (yang harus dilewati), misalnya $n=3$.

| Urutan Normal | Angka yang Kita Hitung (Bukan Kelipatan 3) |
| :-----------: | :----------------------------------------: |
| 1 | 1 |
| 2 | 2 |
| 3 | (Dilewati) |
| 4 | 3 |
| 5 | 4 |
| 6 | (Dilewati) |
| 7 | 5 |
| 8 | 6 |
| 9 | (Dilewati) |
| 10 | 7 |

Perhatikan:

1.  Di antara dua kelipatan $n$ yang berurutan (misalnya antara 3 dan 6, atau antara 6 dan 9), selalu ada $n-1$ angka yang kita hitung (yang bukan kelipatan $n$).
    * Untuk $n=3$: Ada $3-1 = 2$ angka yang kita hitung (1, 2) sebelum sampai ke 3. Ada 2 angka lagi (4, 5) sebelum sampai ke 6.
2.  Karena setiap $n-1$ langkah kita akan bertemu dan melewati satu kelipatan $n$, maka $n-1$ adalah jarak efektif (atau pengelompokan) antara satu pergeseran dengan pergeseran berikutnya.

> Jadi, kita membagi dengan $(n-1)$ karena ini adalah ukuran "blok" angka yang harus kita lalui sebelum kita dipaksa untuk "bergeser" sebanyak 1.

##### Alasan $k$ Dikurangi Satu ($k-1$)

$k$ adalah posisi/urutan ke-$k$ yang kita cari dalam daftar yang sudah dilewati.

Kita menggunakan $k-1$ di pembilang karena:

1.  Kita tidak menghitung pergeseran di posisi $k$ itu sendiri. Kita ingin tahu berapa banyak pergeseran yang sudah terjadi sebelum kita mencapai posisi $k$.
2.  Dalam perhitungan jumlah, kita biasanya menghitung "celah" atau "jarak" hingga elemen sebelum yang kita cari.
    * Misalnya, jika kita mencari Angka ke-1 ($k=1$), pergeseran yang dibutuhkan haruslah 0.
        * Jika kita pakai $\frac{k-1}{n-1}$: $\frac{1-1}{3-1} = 0$. $\lfloor 0 \rfloor = 0$. (Benar)
    * Misalnya, jika kita mencari Angka ke-3 ($k=3$), pergeserannya 1 (angka 3 dilewati).
        * Jika kita pakai $\frac{k-1}{n-1}$: $\frac{3-1}{3-1} = 1$. $\lfloor 1 \rfloor = 1$. (Benar)

> Menggunakan $(k-1)$ di pembilang dan $(n-1)$ di penyebut, lalu dibulatkan ke bawah ($\lfloor \dots \rfloor$), adalah cara standar untuk menghitung jumlah lengkap blok $(n-1)$ yang telah dilalui sebelum mencapai posisi ke-$k$. Ini memastikan kita menghitung semua pergeseran yang perlu ditambahkan (atau "need") ke $k$.

#### Ringkasan Analogi

Bayangkan Anda naik bus dan setiap 2 pemberhentian yang Anda lewati, ada 1 tiket yang harus dibayarkan (yaitu $n-1=2$ dan "need" = tiket yang harus dibayar).

* Anda ingin tahu berapa tiket yang harus dibayar saat Anda mencapai pemberhentian ke-$k$.
* Anda tidak peduli dengan tiket yang akan dibayar saat atau setelah pemberhentian $k$. Anda hanya peduli dengan tiket yang sudah dibayarkan sebelum $k$. Inilah mengapa kita pakai $k-1$.

### Cara Binary Search

"Anda juga bisa menggunakanbinary search untuk menyelesaikan masalah ini :)"

**Bahasa Bayi:** Daripada menghitung $\text{need}$ dengan rumus, kita bisa menebak-nebak jawaban akhirnya!

1.  Kita coba tebak satu angka $X$.
2.  Lalu kita hitung: "Kalau jawabannya $X$, ada berapa kelipatan Angka Nakal ($n$) di bawah $X$?"
3.  Kita kurangi $X$ dengan jumlah kelipatan $n$. Hasilnya adalah posisi yang sebenarnya (Angka ke- $k'$).
4.  Jika $k'$ terlalu kecil, berarti tebakan $X$ kita terlalu kecil. Jika $k'$ terlalu besar, berarti tebakan $X$ kita terlalu besar.
5.  Kita ulangi tebakan dengan lebih pintar (pencarian biner) sampai kita menemukan angka $X$ yang posisi sebenarnya adalah $k$.

### Implementasiku

Setelah mencoba memahami apa yang dibicarakan editorial, berikut adalah jawabanku yang sudah benar:

```cpp
#include <iostream>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    cout << k + (k - 1) / (n - 1) << '\n';
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
```
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include<iostream>
using namespace std;
int main(){
int t,n,k; 
	cin>>t; 
	while(t--){
		cin>>n>>k; 
		cout<<(k+((k-1)/(n-1)))<<endl;
	}
}
```

Ide dan konsep sama dengan editorial.
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		scanf("%d %d",&n,&k);
		printf("%lld\n",(1LL*k*n-1)/(n-1));
	}
	return 0;
}
```

Jawaban yang juga masih sama, namun dari Red Coder.
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        --k;
        cout << k / (n - 1) * n + k % (n - 1) + 1 << "\n";
    }
}
```

Cara perhitungan yang berbeda, namun tetap menghasilkan jawaban yang sama.