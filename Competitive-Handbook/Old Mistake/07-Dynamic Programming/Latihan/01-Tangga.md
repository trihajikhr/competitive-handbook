---
obsidianUIMode: preview
note_type: latihan
latihan: Tangga
sumber:
  - chatgpt.com
tags:
  - dynamic-programming
date_learned: 2025-09-02T01:06:00
---
---
# 1 | Tangga

Seorang anak sedang menaiki sebuah tangga yang memiliki $N$ anak tangga. Setiap kali melangkah, ia dapat menaiki 1 anak tangga atau 2 anak tangga.

**Tugas:**
Tentukan berapa banyak cara berbeda untuk mencapai anak tangga ke-$N$.

**Contoh:**

* Jika $N = 2$, terdapat 2 cara:
	- 1 + 1
	- 2

* Jika $N = 3$, terdapat 3 cara:
	- 1 + 1 + 1
	- 1 + 2
	- 2 + 1

* Jika $N = 4$, terdapat 5 cara:
	- 1 + 1 + 1 + 1
	- 1 + 1 + 2
	- 1 + 2 + 1
	- 2 + 1 + 1
	- 2 + 2

**Input:**
Baris pertama berupa $t$, banyaknya kasus uji.

$t$ baris berikutnya adalah bilangan bulat $N$ $(1 ≤ N ≤ 45$).

**Output:**
Satu bilangan bulat yang menyatakan jumlah cara mencapai anak tangga ke-$N$.

<br/>

---
# 2 | Jawaban
## 2.1 | Versi Tanpa Testcase

Ini adalah versi jawaban yang hanya menerima satu inputan, dengan kata lain tanpa test case:

```cpp
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
    int n = 0;
    cin >> n;

    vector<int> stair(n + 1);

    stair[0] = 1; // base case: 1 cara untuk tidak melangkah
    stair[1] = 1;
    stair[2] = 2;

    for (int i = 3; i <= n; i++) {
        stair[i] = stair[i - 1] + stair[i - 2];
    }

    cout << stair[n];
    return 0;
}
```

## 2.2 | Versi dengan Testcase

Ini adalah jawaban untuk versi dengan test case. Aku menambahkan batas input hingga 100, sehingga jelas harus menggunakan tipe data `long long`:

```cpp
#include <array>
#include <iostream>
using namespace std;

constexpr int SIZE = 100;
array<long long, SIZE + 1> stair{};

void fillStair() {
    stair[0] = 1;
    stair[1] = 1;
    for (int i = 2; i <= SIZE; i++) {
        stair[i] = stair[i - 1] + stair[i - 2];
    }
}

void solve() {
    int n = 0;
    cin >> n;
    cout << stair[n] << "\n";
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 0;
    cin >> t;
    fillStair();
    while ((t--) != 0) {
        solve();
    }
    return 0;
}
```

## 2.3 | Versi Jawaban dengan  Class
Karena aku sedang berlatih menggunakan class juga, jadi aku akan buat versi jawaban dengan class:

```cpp
#include <array>
#include <iostream>
using namespace std;

class Solution {
   private:
    static constexpr int SIZE = 100;
    array<long long, SIZE + 1> stair{};

   public:
    Solution() {
        stair[0] = 1;
        stair[1] = 1;
        for (int i = 2; i <= SIZE; i++) {
            stair[i] = stair[i - 1] + stair[i - 2];
        }
    }

    void solve() const {
        int n = 0;
        cin >> n;
        cout << stair[n] << "\n";
    }
};

auto main() -> int {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 0;
    cin >> t;
    Solution sol;
    while ((t--) != 0) {
        sol.solve();
    }
    return 0;
}
```

<br/>

---
# 3 | Editorial

Jadi, ide untuk menemukan jawaban dari problem anak tangga ini sebenarnya sangatlah sederhana, kita cukup mengamati pola yang terbentuk ketika $N$ bernilai kecil.

Katakanlah kita memiliki fungsi $S(n)$ yang akan mengembalikan banyaknya kombinasi melangkah ke anak tangga $N$, maka:

$S(1)=1$
$S(2)=2$
$S(3)=3$
$S(4)=5$
$S(5)=8$

Sehingga, jawaban untuk banyaknya kombinasi dari setiap $S(n)$, adalah sebagai berikut:

$$S(n)=S(n-1)+S(n-2)$$
Karena untuk nilai $N$ kecil kita sudah mengetahui jawabanya, maka kita bisa menggunakan teknik dynamic programming dengan memoization, yaitu bottom up dynamic programming untuk menemukan semua hasil dari nilai-nilai $N$ besar. Sehingga metode penyelesaian untuk tantangan ini, ada 2:

Untuk program yang hanya menerima satu inputan (*Versi jawaban pertama*), kita bisa membangun array dari $1$ hingga $N$. Kompleksitas waktu dan memory adalah $O(n)$. Namun, untuk kasus hanya menjawab satu inputan saja, kita bisa membuat kompleksitas memorynya lebih kecil, yaitu hingga $O(1)$, dengan menggunakan array bantu berukuran $3$ seperti berikut:

```cpp
#include <array>
#include <iostream>
using namespace std;

constexpr int MOD = 3;

auto main() -> int {
    int n = 0;
    cin >> n;
    array<unsigned long long, 3> stair{};

    stair[0] = 1;
    stair[1] = 1;
    if (n < 2) {
        cout << stair[n];
    } else {
        for (int i = 2; i <= n; i++) {
            stair[i % MOD] = stair[(i - 1) % MOD] + stair[(i - 2) % MOD];
        }

        cout << stair[n % MOD];
    }
    return 0;
}
```

Daripada menyimpan semua $stair[i]$, kita cukup simpan 3 elemen terakhir (dengan mod 3). Hal ini menjadikan kompleksitas memory konstan $O(1)$, sangat efisien.

Sedangkan untuk program yang menerima banyak inputan, atau dengan kasus uji, kita bisa melakukan *precompute*. Ini bisa dilihat di *Versi jawaban kedua*:

```ad-info
**Precompute** adalah melakukan proses penghitungan diawal program yang biasanya dilakukan sebelum inputan pertama, dengan tujuan untuk mempermudah tahap pemrosesan dan pengolahan inputan di tahap selanjutnya.
```

```cpp
#include <array>
#include <iostream>
using namespace std;

constexpr int SIZE = 100;
array<unsigned long long, SIZE + 1> stair{};

void fillStair() {
    stair[0] = 1;
    stair[1] = 1;
    for (int i = 2; i <= SIZE; i++) {
        stair[i] = stair[i - 1] + stair[i - 2];
    }
}

void solve() {
    int n = 0;
    cin >> n;
    cout << stair[n] << "\n";
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 0;
    cin >> t;
    fillStair();
    while ((t--) != 0) {
        solve();
    }
    return 0;
}
```

Pada bagian `main`, sebelum memulai inputan beberapa test case, kita melakukan precompute dengan menjalankan fungsi `fillStair()`. Fungsi ini akan melakukan pengisian array `stair` hingga sebanyak `SIZE+1`. Nilai dari `SIZE` harus disesuaikan dengan batasan input, supaya semua nilai input bisa tercover. Jika semisal batasan input sangatlah besar, maka pertimbangkan untuk menggunakan tipe data `long long`, atau `unsigned long long` untuk menguragi resiko overflow.

Setelah langkah precompute dilakukan, maka setiap inputan akan diproses sebagai pengindeks array, sehingga kompleksitasnya konstan $O(1)$, sangat efisien. 

Kerja berat diawal dengan kompleksitas waktu dan memory $O(n)$, terbayar dengan kompleksitas konstan $O(1)$ pada setiap inputan atau testcase.

