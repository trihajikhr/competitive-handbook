---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 270A
judul_DEATH: Fancy Fence
teori_DEATH: menghitung semua derajat poligon yang mungkin
sumber:
  - codeforces.com
rating: 1100
ada_tips?: true
date_learned: 2025-10-19T13:50:00
tags:
  - geometry
  - implementation
  - math
---
Sumber: [Problem - 270A - Codeforces](https://codeforces.com/problemset/problem/270/A)

```ad-tip
title:⚔️ Teori Death Ground

Untuk mengetahui apakah suatu besaran sudut yang diberikan mampu membentuk poligon regular (*regular polygon*), kita bisa melakukan pengecekan berikut:

$$n \cdot (180^{\circ} - \alpha) \equiv 360$$

Dimana nilai $n$ adalah banyaknya sudut, dan $\alpha$ adalah besaran sudut yang diberikan.

Jika yang diketahui hanyalah besaran sudut $\alpha$, maka operasi modulo untuk bisa digunakan untuk pengecekan yang sama:

$$360 \; mod \; (180^{\circ} - \alpha) \equiv 0$$
```

<br/>

---
# 1 | 270A-Fancy Fence

Diberikan besaran sudut $\alpha$. Tentukan apakah mungkin untuk membentuk poligon regular (*regular polygon*) yang memiliki sudut dengan besaran $\alpha$ atau tidak.

> Poligon reguler adalah bangun datar tertutup yang memiliki semua sisi sama panjang dan semua sudut sama besar. Sifat kesamaan sisi dan sudut ini membuat poligon reguler sangat simetris, sehingga memudahkan perhitungan seperti luas dan sudut. Contohnya termasuk segitiga sama sisi, persegi, dan pentagon (segi lima) beraturan.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Aku tidak berhasil menemukan solusi yang valid. Pertama aku membentuk solusi dari intuisi bahwa sudut sebesar $60^{\circ}$ dan $90^{\circ}$ memiliki selisih $30$. Lalu sudut ketiga yang mungkin adalah $108^{\circ}$, dan sudut keempat adalah $120^{\circ}$.

Masing-masing memiliki selisih sebagai berikut:

$$30, 18, 12$$
Terdapat pola yang terbentuk menurutku, nilai selanjutnya didapat dari selisih $2$ angka terakhir, yang dibagi dengan $2$, lalu ditambahkan dengan $3$. Misal nilai $108^{\circ}$, didapat dari operasi berikut:

$$90 + \left( \frac{90-60}{2} + 3 \right) = 108$$
Dan nilai $120^{\circ}$ didapat dari operasi berikut:

$$108 + \left( \frac{108-90}{2}+3 \right) = 120$$
Namun, poligon tujuh sisi, memiliki derajat $128,57^{\circ}$, dan ada beberapa poligon yang memiliki derajat yang pecahan.

Dan karena itu, solusiku gagal, karena tidak bisa melewati couter example ini.
<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Pertimbangkan semua sudut suplemen dari segi-$n$ beraturan dengan sudut $\alpha$, yang sama dengan $180^{\circ} - \alpha$. Jumlah mereka sama dengan $360^{\circ}$, karena poligon tersebut cembung (*convex*). Maka, kesamaan berikut berlaku: $n \cdot (180^{\circ} - \alpha) = 360^{\circ}$, yang berarti ada jawaban jika dan hanya jika $360 \bmod (180 - \alpha) \equiv 0$.

**Penjelasan Matematis Singkat**

Dalam geometri, sudut suplemen dari sudut interior segi-$n$ beraturan ($\alpha$) adalah sudut eksterior ($180^{\circ} - \alpha$).

  * Jumlah semua sudut eksterior dari poligon cembung mana pun (beraturan atau tidak) selalu **$360^{\circ}$**.
  * Karena segi-$n$ memiliki $n$ sudut, dan semua sudut eksteriornya sama, maka $n$ dikalikan dengan satu sudut eksterior ($180^{\circ} - \alpha$) harus sama dengan $360^{\circ}$.
  * $n \cdot (180^{\circ} - \alpha) = 360^{\circ}$
  * Karena $n$ harus berupa bilangan bulat (jumlah sisi), maka $(180^{\circ} - \alpha)$ harus membagi habis $360^{\circ}$. Inilah yang diwakili oleh $360 \bmod (180 - \alpha) \equiv 0$.

Implementasi editorial:

```cpp
#include<iostream>
#include<cstdio>

using namespace std;

int main() {    
	int t; cin >> t;
	for(int i = 0; i < t; i++) {
		int a; cin >> a;
		cout << (360 % (180-a) == 0 ? "YES" : "NO") << endl;
	}
}
```
## 3.2 | Analisis Pribadi

Baiklah, melihat dari petunjuk editorial, aku akhirnya mengerti, berikut adalah solusiku:

```cpp
#include<iostream>
using namespace std;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
     cin >> t;
    while (t--) {
        int q;
        cin >> q;
        if (360 % (180-q) == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
```
## 3.3 | Analisis Jawaban User Lain

Solusi dari editorial sudah merupakan solusi yang efisien. Jawaban dari kebanyakan user tidak jauh berbeda:

### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, a;
    cin >> t;
    while (t--) {
        cin >> a;
        cout << (360 % (180 - a) ? "NO\n" : "YES\n");
    }
}
```
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if ((360 % (180 - n)) == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
```
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        int diff = 180 - a;

        if (diff > 0 && 360 % diff == 0) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}
```