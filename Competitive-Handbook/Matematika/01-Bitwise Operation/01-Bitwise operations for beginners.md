---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Bitwise operations for beginners
sumber: codeforces
date_learned: 2025-06-09T14:29:00
tags:
  - bitwise
  - bits
---
Link Sumber:  [Bitwise operations for beginners - Codeforces](https://codeforces.com/blog/entry/73490)

---
Kamu bisa menonton video YouTube-ku ([Youtube](https://www.youtube.com/watch?v=xXKL9YBWgCY&list=PLl0KD3g-oDOHpWRyyGBUJ9jmul0lUOD80&t=5s&ab_channel=ErrichtoAlgorithms)) dengan konten yang sama seperti blog ini. Pokoknya, selamat belajar!

# Pendahuluan

Mari kita pelajari operasi bitwise yang berguna dalam Competitive Programming. Prasyaratnya adalah kamu sudah memahami sistem bilangan biner. Sebagai contoh, kamu harus sudah paham hal berikut ini:

$$13 = 1⋅8 + 1⋅4 + 0⋅2 + 1⋅1 = 1101₂ = 00001101₂$$

Perlu diingat bahwa kita bisa menambahkan **angka nol di depan (leading zeros)** agar panjang bilangan biner sesuai dengan ukuran tipe datanya. Contohnya:

- Tipe data `char` memiliki $8$ bit
- Tipe data `int` memiliki $32$ bit
# Bitwise AND, OR, XOR

Kamu mungkin sudah familiar dengan operasi logika dasar seperti AND dan OR. Misalnya, `if(condition1 && condition2)` akan mengecek apakah kedua kondisi benar, sedangkan `c1 || c2` akan benar jika salah satu saja benar.

Hal yang sama bisa dilakukan bit per bit terhadap bilangan bulat, dan ini disebut **operasi bitwise**. Kamu harus tahu tiga operator bitwise dasar berikut:

- Bitwise AND: `&`
    
- Bitwise OR: `|`
    
- Bitwise XOR: `^`

Masing-masing dituliskan dengan satu karakter saja.

**XOR** dari dua bit bernilai **1 jika hanya satu dari dua bit tersebut yang 1** (jadi, XOR pada bit mirip seperti operator `!=`).

Ada juga **operator NOT (~)**, tetapi tidak terlalu sering digunakan dalam kompetisi.

Penjelasan lengkap bisa kamu temukan di [Wikipedia](https://en.wikipedia.org/wiki/Bitwise_operation), tetapi berikut adalah contoh **bitwise AND**:

Ditunjukkan bahwa `53 & 28` sama dengan $20$:

```
53 = 110101
28 = 11100  

// perhatikan bahwa angka yang lebih pendek diberi padding nol di depan

   110101
&  011100 
 --------
   010100  = 20
```

## Eksperimen dengan C++

```cpp
#include <bits/stdc++.h>
using namespace std;

string to_binary(int x) {
	string s;
	while(x > 0) {
		s += (x % 2 ? '1' : '0'); 
		x /= 2; 
	}
	reverse(s.begin(), s.end()); 
	return s;
}

int main() {
	cout << "13 = " << to_binary(13) << endl; 
	
	int x = 53;
	int y = 28;
	cout << "x = " << to_binary(x) << ", y = " << to_binary(y) << endl;
	
	cout << "AND, OR, XOR:" << endl;
	cout << to_binary(x & y) << " " << to_binary(x | y) << " " << to_binary(x ^ y) << endl;
}
```

### Penjelasan:

1. **Fungsi `to_binary(int x)`**  
    Mengubah bilangan desimal menjadi string biner. Misalnya:
    
    - `to_binary(13)` menghasilkan `"1101"`
        
    - Prosesnya: ambil sisa pembagian 2 (bit terakhir), lalu geser ke kanan dengan `x /= 2`.
        
2. **Bagian `main()`**:
    
    - Mencetak representasi biner dari angka 13.
        
    - Mendeklarasikan `x = 53` dan `y = 28`, lalu mencetak bentuk biner keduanya.
        
    - Menghitung hasil `AND`, `OR`, dan `XOR` antara `x` dan `y`, lalu mencetak hasil binernya.
        
    
    Misalnya:
    
    ```
    x = 110101
    y = 011100
    
    AND : 010100
    OR  : 111101
    XOR : 101001
    ```
    

Versi dengan komentar:
```cpp
#include <bits/stdc++.h>
using namespace std;

// Fungsi untuk mengubah bilangan bulat menjadi representasi biner dalam bentuk string
string to_binary(int x) {
	string s;
	while(x > 0) {
		s += (x % 2 ? '1' : '0'); // Tambahkan '1' jika bit terakhir 1, else '0'
		x /= 2; // Geser ke kanan (bagi 2)
	}
	reverse(s.begin(), s.end()); // Balik string karena kita membangunnya dari belakang
	return s;
}

int main() {
	cout << "13 = " << to_binary(13) << endl; // Output: 1101
	
	int x = 53;
	int y = 28;
	cout << "x = " << to_binary(x) << ", y = " << to_binary(y) << endl;
	
	cout << "AND, OR, XOR:" << endl;
	cout << to_binary(x & y) << " " << to_binary(x | y) << " " << to_binary(x ^ y) << endl;
}

```


> Di bagian komentar, **RezwanArefin01** menyarankan cara yang lebih sederhana untuk mencetak angka dalam format biner.  
> 
> `cout << bitset<8>(x);` mencetak angka setelah diubah menjadi **bitset**, yang bisa langsung dicetak.  
> 
> Akan ada informasi lebih lanjut tentang **bitset** di bagian ke-2.

---

### Penjelasan Tambahan tentang `bitset`:

```cpp
#include <bitset>
cout << bitset<8>(x);
```

- `bitset<8>` berarti ubah angka `x` menjadi bentuk biner 8 bit.
    
- Contoh: `bitset<8>(13)` menghasilkan `00001101`
    
- Ini adalah **cara yang lebih ringkas dan aman** untuk mencetak bilangan biner dalam C++.
    

---
# Pergeseran (Shifts)

Terdapat juga operator pergeseran bit (*bitwise shifts*) yaitu `<<` dan `>>`, yang tidak ada hubungannya dengan operator yang digunakan untuk `cin` dan `cout`.

Sesuai dengan arah panahnya:

- **Left shift (`<<`)** menggeser bit ke kiri, yang akan **meningkatkan nilai bilangan**.
    
- Berikut ini adalah contoh dari `13 << 2`, yaitu **angka $13$ yang digeser $2$ bit ke kiri**.
    

```
    LEFT SHIFT                             RIGHT SHIFT
       13 =     1101                          13 =   1101
(13 << 2) =   110100                   (13 >> 2) =     11
```

Jika **tidak terjadi overflow**, maka ekspresi `x << b` **sama seperti** `x × 2ᵇ` ($x \cdot 2ᵇ$), seperti contoh di atas:  `13 << 2 = 13 × 4 = 52`


Sebaliknya, **right shift (`>>`)** menggeser bit ke kanan, dan beberapa bit bisa **hilang** akibat pergeseran, seperti bit `01` pada contoh di atas.

Ekspresi `x >> b` **setara dengan** `⌊x / 2ᵇ⌋` ($\frac{x}{2^{b}}$) (dibulatkan ke bawah). Contoh:

- `13 >> 2 = ⌊13 / 4⌋ = 3`

Catatan:  
Untuk **bilangan negatif**, hasilnya **lebih rumit** karena bergantung pada sistem representasi bilangan negatif (biasanya two's complement), namun hal itu **tidak akan dibahas di sini**.

## Rangkuman:

|Operasi|Efek|Sama dengan|
|---|---|---|
|`x << b`|Geser `b` bit ke kiri|`x × 2ᵇ` (jika tidak overflow)|
|`x >> b`|Geser `b` bit ke kanan|`⌊x / 2ᵇ⌋`|

# Jadi apa yang bisa kita lakukan?

Ekspresi $2^k$ dalam bentuk bitwise adalah `1 << k` . Atau jika kamu butuh **tipe long long**, maka gunakan `1LL << k`. Bilangan tersebut akan memiliki bentuk biner seperti ini: `10000` (hanya satu bit yang aktif/bernilai 1 di posisi ke-`k`), dan jika kita lakukan operasi **AND** dengan bilangan lain $x$, hasilnya **maksimal hanya memiliki satu bit yang aktif**.

Dengan cara ini, kita bisa mengecek apakah suatu bit ke-`k` aktif (bernilai $1$) dalam bilangan $x$.

## Contoh: Menemukan semua bit yang aktif dalam bilangan `x`

Asumsikan $x ∈ [0, 10⁹]$. Berikut adalah kode untuk menemukan posisi bit 1:

```cpp
for(int i = 0; i < 30; i++) 
    if((x & (1 << i)) != 0) 
        cout << i << " ";
```

Kenapa hanya sampai `i < 30`?  
Karena $2^{30} > 10^9$, jadi tidak ada bit ke-30 yang aktif jika $x <= 10^9$.

---

## Versi yang lebih efisien dan bersih:

Dan mari kita lakukan itu dengan sedikit lebih baik, yaitu menghentikan proses saat bit yang dicek sudah terlalu besar, serta memanfaatkan fakta bahwa `if(value)` dalam C++ akan bernilai benar jika `value` tidak sama dengan nol.

> Tahukah kamu? Dalam C++, kondisi `if(x & (1 << i))` tidak hanya lebih ringkas, tapi juga sangat optimal karena langsung mengevaluasi hasil AND sebagai boolean!

```cpp
for(int i = 0; (1 << i) <= x; i++) 
    if(x & (1 << i)) 
        cout << i << " ";
```

Penjelasan:

- `(1 << i) <= x` akan menghentikan loop jika nilai bit sudah melebihi `x`.
    
- `if(x & (1 << i))` akan bernilai **true** jika bit ke-`i` dari `x` aktif (tidak perlu bandingkan `!= 0` karena dalam C++ ekspresi `if(value)` cukup selama `value ≠ 0`).
    

---

## Studi Kasus: Subset Sum Problem (≤ 20 elemen)

**Masalah**: Diberikan N ≤ 20 bilangan (masing-masing ≤ 10⁹), apakah ada **subset** yang jumlahnya **sama dengan nilai tertentu `S`**?

Ini bisa diselesaikan dengan **rekursi**, tapi ada solusi **iteratif yang sangat elegan** menggunakan bitwise.

### Pendekatan Bitmask (Bitwise Subset Enumeration)

Kita akan mengiterasi setiap bilangan `x` dari 0 sampa $2^n - 1$ dan menganggap `x` sebagai **bilangan biner sepanjang `n` bit**, di mana:

- **bit 1** berarti elemen ke-`i` diambil dalam subset
    
- **bit 0** berarti elemen ke-`i` tidak diambil
    

Memahami konsep ini **sangat penting** untuk menyelesaikan masalah-masalah yang lebih kompleks dengan **bitwise operations**.

### Saran Latihan:

Pelajari kode tersebut dengan cermat, **pahami logikanya**, dan **cobalah tulis ulang sendiri dari awal** tanpa melihat kode aslinya.

```cpp
for(int mask = 0; mask < (1 << n); mask++) {
	long long sum_of_this_subset = 0;
	for(int i = 0; i < n; i++) {
		if(mask & (1 << i)) {
			sum_of_this_subset += a[i];
		}
	}
	if(sum_of_this_subset == S) {
		puts("YES");
		return 0;
	}
}
puts("NO");
```

Berikut adalah **dua soal mudah** yang cocok untuk **berlatih iterasi semua kemungkinan 2ⁿ subset** menggunakan bitmask:
- [https://codeforces.com/problemset/problem/1097/B](https://codeforces.com/problemset/problem/1097/B)  
- [https://codeforces.com/problemset/problem/550/B](https://codeforces.com/problemset/problem/550/B)

# Speed

- **Waktu eksekusi dari setiap operasi bitwise adalah O(1)** — artinya waktu tetap, secepat mungkin!
    
- Operasi-operasi ini **sangat cepat** di prosesor modern. Bahkan jika kamu melakukan hingga **10⁹ (satu miliar)** operasi bitwise, masih bisa selesai **dalam waktu sekitar 1 detik**.
    

⚠️ Catatan kecil:

- Fungsi `__popcount()` (atau `__builtin_popcount()` di C++) memang tidak O(1) dalam teori, tapi **sangat cepat dalam praktik**, karena dioptimasi secara hardware.
    

---

### 🧠 Tentang Bitset dan Kompleksitas

- Nantinya kamu akan mempelajari **`bitset`** di C++, yaitu struktur data khusus untuk menyimpan dan memproses kumpulan bit secara efisien.
    
- Dalam banyak kasus, operasi dengan `bitset` bisa memberikan kompleksitas $O(\frac {n^2} {32})$.
    
- Kompleksitas seperti ini **cukup untuk lulus batas waktu** pada soal dengan **n ≤ 10⁵** — selama konstanta dan operasinya ringan.
    

---

### 📢 Penutup dari Penulis Asli

> Saya sangat terbuka terhadap masukan (feedback).  
> Materi selanjutnya: **popcount**, **bitsets**, dan **dynamic programming dengan bitmask**.  
> Saya juga akan membuat video YouTube tentang ini (link ada di bagian atas).
