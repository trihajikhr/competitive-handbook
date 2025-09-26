---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Pengecekan Kuadrat Sempurna
sumber:
  - myself
  - chatgpt.com
tags:
  - tips-trick
  - number-theory
---
---
# Pengecekan Kuadrat Sempurna

## 1 | Definisi

Suatu bilangan bulat non-negatif $n \in \mathbb{Z}_{\ge 0}$ disebut **kuadrat sempurna** (perfect square) apabila terdapat suatu bilangan bulat $m \in \mathbb{Z}$ sehingga

$$
n = m^2.
$$

Dengan kata lain, $n$ adalah hasil perkalian suatu bilangan bulat $m$ dengan dirinya sendiri. Contoh

* $n = 0$. Karena $0 = 0^2$, maka $0$ adalah kuadrat sempurna.
* $n = 9$. Karena $9 = 3^2$, maka $9$ adalah kuadrat sempurna.
* $n = 12$. Tidak ada bilangan bulat $m$ dengan $m^2 = 12$, maka $12$ **bukan** kuadrat sempurna.

Ciri-ciri angka yang memiliki kuadrat sempurna adalah sebagai berikut:

1. Jika $n$ adalah kuadrat sempurna, maka akar kuadratnya $\sqrt{n}$ merupakan bilangan bulat.
2. Sebaliknya, jika $\sqrt{n}$ bukan bilangan bulat, maka $n$ bukan kuadrat sempurna.

## 2 | Pengecekan Kuadrat Sempurna

Ada beberapa cara untuk mengecek apakah suatu angka merupakan angka dengan kuadrat sempuarna atau tidak, berikut adalah beberapa caranya:

### 2.1 | Cara Biasa

```cpp
#include <cmath>
#include <iostream>
using namespace std;

auto main() -> int {
    int n;
    cin >> n;

    if ((int)sqrt(n) == sqrt(n)) {
        cout << "Perfect Square";
    } else {
        cout << "NO";
    }
    return 0;
}
```

Fungsi `sqrt()` merupakan fungsi yang akan mengembalikan nilai dari akar suatu angka. Tetapi, walaupun kode diatas bekerja, tapi masih ada rawan atau potensi kesalahan yang terjadi dari kode diatas.

Fungsi `sqrt()` mengembalikan nilai dengan tipe data double, bukan int. Itulah alasan kenapa kita melakukan *truncate* dengan `(int)sqrt(n)`.  Jadi kita membandingkan `double` dengan versi `int`-nya.

Contoh:
- $n = 16$: `sqrt(16) = 4.0`, `(int)4.0 = 4`, maka sama → benar.
- $n=18$: `sqrt(18) ≈ 4.24`, `(int)4.24 = 4`, dibandingkan dengan `4.24` → tidak sama → benar juga.
### 2.2 | Dengan Bantuan Toleransi Floating Point

Artinya secara logika kode ini bekerja, tapi ini agak rawan karena melibatkan floating point. Kalau angkanya besar, ada kemungkinan terjadi error presisi.

Solusi kedua, adalah dengan tetap menggunakan double, tapi menggunakan bantuan toleransi *floating-point*, seperti berikut:

```cpp
#include <cmath>
#include <iostream>
using namespace std;

using LL = long long;

auto main() -> int {
    LL x;
    cin >> x;

    LL a = (LL)sqrt(x);
    double b = sqrt(x);

    if (fabs(b - a) < 1e-9) {
        cout << "Perfect square\n";
    } else {
        cout << "NO";
    }

    return 0;
}
```

Program tersebut ditulis dalam bahasa C++ dengan tujuan memeriksa apakah suatu bilangan bulat $x$ merupakan kuadrat sempurna. Struktur kode dimulai dengan memasukkan sebuah bilangan bulat bertipe `long long` dari masukan standar. Kemudian, nilai akar kuadrat dari $x$ dihitung dua kali: pertama disimpan sebagai bilangan bulat (`LL a`), hasil dari pembulatan ke bawah pada `sqrt(x)`; kedua disimpan sebagai bilangan pecahan bertipe `double` (`double b`).

Setelah itu dilakukan perbandingan antara `a` dan `b` menggunakan fungsi `fabs` dengan toleransi $10^{-9}$. Uji ini bertujuan untuk menentukan apakah hasil akar kuadrat `b` cukup dekat dengan bilangan bulat `a`. Jika perbedaan keduanya lebih kecil dari $10^{-9}$, maka dianggap bahwa $\sqrt{x}$ adalah bilangan bulat, sehingga $x$ adalah kuadrat sempurna, dan program mencetak `"Perfect square"`. Jika tidak terpenuhi, program mencetak `"NO"`.

Secara matematis, uji ini mencoba memastikan bahwa terdapat bilangan bulat $a$ dengan $|\sqrt{x} - a| < 10^{-9}$. Dengan demikian, pendekatan ini mengandalkan presisi floating point dari tipe `double`. Untuk nilai $x$ yang tidak terlalu besar, metode ini cukup akurat. Namun, karena `double` hanya mampu merepresentasikan sekitar 15–16 digit signifikan, metode ini dapat gagal untuk bilangan yang sangat besar akibat keterbatasan presisi. Alternatif yang lebih aman adalah menggunakan perbandingan murni dalam ranah bilangan bulat, yakni dengan menghitung $a = \lfloor \sqrt{x} \rfloor$ dan memeriksa apakah $a \times a = x$.

Dengan demikian, kode tersebut secara fungsional benar untuk kisaran input moderat, namun secara formal memiliki batasan akurasi karena bergantung pada aritmetika floating point.

```ad-info
Fungsi `fabs` adalah singkatan dari *floating absolute value*, yaitu fungsi dalam pustaka `<cmath>` C++ yang digunakan untuk menghitung nilai absolut dari sebuah bilangan bertipe pecahan (`float`, `double`, atau `long double`). Secara formal, untuk setiap bilangan real $x$, fungsi ini mengembalikan

$$
\text{fabs}(x) = |x| =
\begin{cases} 
x, & \text{jika } x \geq 0, \\ 
-x, & \text{jika } x < 0.
\end{cases}
$$

Dalam konteks program yang kamu tulis, `fabs(b - a)` digunakan untuk mengukur seberapa jauh nilai akar kuadrat `b` (hasil floating point) dari bilangan bulat `a`. Karena selisih tersebut bisa bernilai negatif maupun positif, fungsi `fabs` memastikan perbandingan dilakukan terhadap jarak (nilai absolut) tanpa memperhatikan tanda.

Sebagai ilustrasi:

* Jika `b = 4.000000001` dan `a = 4`, maka `b - a = 0.000000001` → `fabs(b - a) = 0.000000001`.
* Jika `b = 3.999999999` dan `a = 4`, maka `b - a = -0.000000001` → `fabs(b - a) = 0.000000001`.

Kedua kasus sama-sama menunjukkan bahwa `b` sangat dekat dengan `a`, dan berkat `fabs`, perbandingan dengan toleransi `1e-9` dapat dilakukan dengan benar tanpa dipengaruhi tanda selisihnya.
```

### 2.3 | Solusi Yang Paling Aman dan Benar

Ada versi pengecekan kuadrat sempurna yang lebih aman, tanpa membandingkan int vs double. Yaitu, lebih baik simpan akar ke variabel integer, lalu kuadratkan lagi:

```cpp
#include <cmath>
#include <iostream>
using namespace std;

auto main() -> int {
    long long n;
    cin >> n;

    long long r = sqrt(n); // dibulatkan ke bawah
    if (r * r == n) {
        cout << "Perfect Square dari: " << r;
    } else {
        cout << "NO";
    }
    return 0;
}
```

Dengan cara ini:
- TIdak ada perbandingan `int` vs `double`
- Hanya melakukan pengecekan dengan integer murni (`r * r == n`)
- Aman dari error presisi floating point.