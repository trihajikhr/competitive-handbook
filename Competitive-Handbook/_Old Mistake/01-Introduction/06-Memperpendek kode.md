---
obsidianUIMode: preview
note_type: tips trick
tips_trick: memperpendek kode
sumber: "buku: CP handbook by Antti Laaksonen"
tags:
  - efisien
---
#efisien 

---
# Memperpendek Kode

Kode yang ringkas sangat ideal dalam _competitive programming_, karena program harus ditulis secepat mungkin. Oleh karena itu, banyak programmer kompetitif menggunakan nama yang lebih pendek untuk tipe data dan bagian kode lainnya.

## Menyingkat Nama Tipe Data

Menggunakan perintah `typedef`, kita dapat memberi nama yang lebih pendek untuk sebuah tipe data. Sebagai contoh, tipe `long long` cukup panjang, sehingga kita dapat mendefinisikan nama lebih pendek seperti `ll`:

```cpp
typedef long long ll;
```

Setelah ini, kode berikut:

```cpp
long long a = 123456789;
long long b = 987654321;
cout << a * b << "\n";
```

dapat diperpendek menjadi:

```cpp
ll a = 123456789;
ll b = 987654321;
cout << a * b << "\n";
```

Selain itu, `typedef` juga bisa digunakan untuk tipe data yang lebih kompleks. Contohnya:

```cpp
typedef vector<int> vi;
typedef pair<int, int> pi;
```

Sekarang, kita bisa menulis `vi` untuk `vector<int>` dan `pi` untuk `pair<int, int>`.

## Menggunakan Macro

Cara lain untuk memperpendek kode adalah dengan mendefinisikan _macro_. _Macro_ adalah bagian kode yang akan diganti sebelum kompilasi, menggunakan perintah `#define`.

Sebagai contoh, kita dapat mendefinisikan beberapa _macro_ berikut:

```cpp
#define F first
#define S second
#define PB push_back
#define MP make_pair
```

Setelah ini, kode berikut:

```cpp
v.push_back(make_pair(y1, x1));
v.push_back(make_pair(y2, x2));
int d = v[i].first + v[i].second;
```

dapat diperpendek menjadi:

```cpp
v.PB(MP(y1, x1));
v.PB(MP(y2, x2));
int d = v[i].F + v[i].S;
```

### Macro dengan Parameter

_Macro_ juga bisa memiliki parameter, sehingga dapat digunakan untuk memperpendek loop atau struktur lainnya. Sebagai contoh, kita bisa mendefinisikan _macro_ untuk _loop_ sebagai berikut:

```cpp
#define REP(i, a, b) for (int i = a; i <= b; i++)
```

Setelah ini, kode:

```cpp
for (int i = 1; i <= n; i++) {
    search(i);
}
```

dapat diperpendek menjadi:

```cpp
REP(i, 1, n) {
    search(i);
}
```

### Potensi Bug pada Macro

Kadang-kadang, _macro_ dapat menyebabkan _bug_ yang sulit dideteksi. Misalnya, perhatikan _macro_ berikut yang menghitung kuadrat dari sebuah angka:

```cpp
#define SQ(a) a * a
```

Jika kita menulis:

```cpp
cout << SQ(3 + 3) << "\n";
```

Maka kode ini akan diterjemahkan menjadi:

```cpp
cout << 3 + 3 * 3 + 3 << "\n"; // 15 (SALAH!)
```

Karena perkalian memiliki prioritas lebih tinggi daripada penjumlahan, hasilnya menjadi salah. Solusi yang lebih baik adalah dengan menambahkan kurung pada ekspresi:

```cpp
#define SQ(a) (a) * (a)
```

Sekarang, jika kita menjalankan:

```cpp
cout << SQ(3 + 3) << "\n";
```

maka kode akan diterjemahkan dengan benar menjadi:

```cpp
cout << (3 + 3) * (3 + 3) << "\n"; // 36 (BENAR)
```


---

# Perbedaan `typedef` dan `define`
Memang sekilas penggunaan `typedef` dan `#define` tampak mirip karena keduanya bisa digunakan untuk menyingkat kode. Namun, ada **perbedaan penting** antara keduanya:

## 1. `typedef` dan `using` (Menyingkat Nama Tipe Data)

- Digunakan **khusus untuk tipe data**.
- Dikenali oleh **compiler** dan memiliki **tipe yang jelas**.
- Alternatif modern dari `typedef` adalah `using` (lebih fleksibel dalam beberapa kasus).

Contoh dengan `typedef`:

```cpp
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
```

Setelah ini, kita bisa menulis:

```cpp
ll a = 1000000000;  // Sama dengan long long
vi v = {1, 2, 3};   // Sama dengan vector<int>
pi p = {3, 4};      // Sama dengan pair<int, int>
```

✅ **Keuntungan:**

- Memberikan tipe yang lebih jelas kepada compiler.
- Bisa digunakan dalam konteks template dan _type safety_ tetap terjaga.

### Penggunaan `typedef` vs `using`
Ya! `using` adalah alternatif modern dari `typedef` di C++. `using` diperkenalkan di C++11 dan lebih fleksibel dibandingkan `typedef`.

#### 1. `typedef` (Cara Lama)

Digunakan untuk membuat alias tipe data, tapi kurang fleksibel terutama saat digunakan dengan template.

```cpp
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
```

Penggunaan:

```cpp
ll a = 1000000000;  // Sama dengan long long
vi v = {1, 2, 3};   // Sama dengan vector<int>
pi p = {3, 4};      // Sama dengan pair<int, int>
```

✅ **Kelebihan:** Bisa digunakan untuk menyingkat tipe data.  
🚫 **Kekurangan:** Tidak fleksibel saat digunakan dengan template.

#### 2. `using` (Cara Modern, C++11+)

Menggantikan `typedef` dan lebih fleksibel, terutama untuk template.

```cpp
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
```

Penggunaan:

```cpp
ll a = 1000000000;
vi v = {1, 2, 3};
pi p = {3, 4};
```

✅ **Kelebihan `using`:**

- Lebih mudah dibaca.
- Lebih fleksibel untuk **template alias**.

Contoh penggunaan dengan template:

```cpp
template <typename T>
using my_pair = pair<T, T>;

my_pair<int> p = {3, 4};  // Sama dengan pair<int, int>
my_pair<double> q = {3.14, 2.71};  // Sama dengan pair<double, double>
```

🚫 **Kekurangan `typedef`:** Tidak bisa melakukan hal ini.

### Kesimpulan: Pilih `using` atau `typedef`?

✅ **Gunakan `using`** karena lebih modern, lebih fleksibel, dan lebih mudah dibaca.  
🚫 `typedef` masih bisa digunakan, tapi **`using` direkomendasikan**, terutama saat bekerja dengan template.

## 2. `#define` Macro (Mengganti Bagian Kode Sebelum Kompilasi)

- **Bukan bagian dari C++ secara langsung**, melainkan diproses oleh **preprocessor** sebelum kompilasi.
- **Bisa digunakan untuk apa saja**, tidak hanya tipe data.
- Tidak dicek oleh compiler, sehingga bisa menyebabkan bug jika tidak hati-hati.

Contoh dengan `#define`:

```cpp
#define ll long long
#define vi vector<int>
#define pi pair<int, int>
```

Setelah ini, kita bisa menulis:

```cpp
ll a = 1000000000;  // Sama dengan long long
vi v = {1, 2, 3};   // Sama dengan vector<int>
pi p = {3, 4};      // Sama dengan pair<int, int>
```

📌 **Mirip dengan `typedef`, tapi dengan perbedaan utama:**

- `#define` **hanya mengganti teks**, bukan bagian dari sistem tipe data C++.
- Bisa menyebabkan bug yang sulit dideteksi jika digunakan dengan cara yang salah.
- Tidak bisa digunakan untuk mendefinisikan _template types_.

---

## Mana yang Lebih Baik?

✅ **Gunakan `typedef` atau `using` untuk tipe data** karena lebih aman dan dikenali compiler.  
✅ **Gunakan `#define` hanya untuk konstanta, ekspresi, atau kode yang tidak bisa dilakukan dengan `typedef` atau `using`**, seperti:

```cpp
#define PB push_back
#define F first
#define S second
#define REP(i, a, b) for (int i = a; i <= b; i++)
```

🚫 **Hindari mendefinisikan tipe data dengan `#define`**, karena bisa menyebabkan error sulit dideteksi.

Jadi, meskipun `typedef` dan `#define` tampak mirip dalam menyingkat kode, perbedaannya cukup besar terutama dalam hal _type safety_ dan bagaimana compiler menanganinya.

---
# Cara lama vs cara baru? Mana lebih baik?

Tunggu? Tapi kenapa kebanyakan programmer CP menggunakan `#define`, bukan `typedef` atau `using`  🤔?

HAHAHAHA 🤣 Tenang, bro! Itu bukan tanpa alasan!

Di _competitive programming (CP)_, makro `#define` sering dipakai karena:  
- ✅ **Lebih cepat diketik** → Dalam CP, kecepatan mengetik itu penting!  
- ✅ **Tidak menambah overhead runtime** → Makro langsung diganti sebelum kompilasi.  
- ✅ **Banyak digunakan di komunitas CP** → Jadi biar familiar kalau lihat kode orang lain.

Tapi, emang bener sih, kalau coding _beyond CP_ (misal di proyek serius), **pakai `using` lebih baik** karena lebih aman dan lebih readable. Makro bisa bikin bug aneh kalau nggak hati-hati.

Kalau buat CP aja sih, **`define` masih oke**, tapi kalau buat kode yang lebih maintainable, **pakai `using` lebih direkomendasikan**.

Jadi, kesimpulan dari `typedef` vs `using`, ini dia perbedaannya:

|Fitur|`typedef`|`using`|
|---|---|---|
|**Sintaks**|`typedef long long ll;`|`using ll = long long;`|
|**Support Template**|❌ Tidak bisa|✅ Bisa|
|**Kebersihan Kode**|Agak ribet kalau kompleks|Lebih bersih & fleksibel|
|**Rekomendasi**|Lama, tapi masih dipakai|Modern, lebih direkomendasikan|

📌 **Kesimpulan:**

- Kalau pakai **C++11 ke atas**, **pakai `using` lebih baik**.
- Kalau pakai **C++98 atau C++03**, ya pakai `typedef`.

Jadi buat CP, dua-duanya bisa dipakai, tapi `using` lebih enak buat kode jangka panjang. 🚀

