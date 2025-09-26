---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Algoritma Generate Angka
sumber:
  - myself
  - chatgpt.com
date_learned: 2025-09-25T13:24:00
tags:
  - number-theory
---
Link Sumber: 

---
# 1 | Algoritma Generate Angka

Pada materi kali ini, kita akan belajar algoritma untuk menghasilkan semua kombinasi dari angka-angka tertentu. 

Terkadang, terdapat problem yang mengharuskan kita untuk menggenerate angka, dari beberapa digit, dengan panjang semisal $n$ digit. Katakanlah kita diminta untuk menggenerate semau angka-angka dengan panjang maksimal 3, yang mungkin disusun oleh digit-digit seperti $4$ dan $7$, maka berikut adalah hasilnya:

```
7
77
777
774
74
747
744
4
47
477
474
44
447
444
```

Terdapat 14 kombinasi angka yang mungkin, ini benar karena mengacu pada rumus kombinasi, yaitu sebagai berikut:

$$(2\cdot 2\cdot2)+(2\cdot2)+(2)=14$$
Yaitu banyaknya kombinasi dari angka dengan 3 digit, 2 digit, dan 1 digit yang saling ditambahkan.

Materi kali ini kita akan belajar algoritma untuk melakukan generate angka sepeerti ini, dengan beberapa cara, dan juga dengan beberapa kasus. Selain itu, ada cara rekursif, dan juga cara iteratif, intinya kita akan membahas kedua cara ini, tapi kita akan susun kedua cara tadi, dengan 2 subtopik, yaitu:

1. Generate semua kombinasi angka dengan panjang maksimal $n$, dari beberapa digit.
2. Generate angka dengan panjang tepat $n$, dari beberapa digit.

Baiklah, mari kita mulai!

<br/>

---

# 2 | Cara Rekursif
## 2.1 | Generate Angka dengan Panjang Maksimal $n$

Buatkan semua kombinasi angka dengan panjang tepat $n$, dari digit-digit:
- $1,3$
- $4,7,9$
- $3,4,5,6$

Dalam penyusunan kombinasi angka, kita bisa membangun kombinasi dengan bantuan string, atau angka langsung. Untuk angka langsung, maka algoritmanya adalah seperti ini:

```cpp
#include <iostream>
#include <vector>
using namespace std;

void generateNumber(int n, int num, vector<int>& davec, int curr = 0) {
    if (curr == n + 1)
        return;
    if (num > 0) {
        davec.push_back(num);
    }

    generateNumber(n, num * 10 + 1, davec, curr + 1);
    generateNumber(n, num * 10 + 3, davec, curr + 1);
}

auto main() -> int {
    int n;
    cin >> n;
    vector<int> vec;
    generateNumber(n, 0, vec);

    for (const auto& x : vec) {
        cout << x << '\n';
    }

    return 0;
}
```

Kita menerima inputan $n$ sebagai panjang digit angka yang akan dibuat. Lalu deklarasikan vector `vec` yang akan digunakan untuk menampung semua hasil kombinasi dari generate angka dari digit-digit yang ditentukan. Setelah itu panggil fungsi `generateNumber()`.

Fungsi `generateNumber()` memiliki beberapa parameter penting disini, yaitu `num` dan juga `curr`. Parameter `num` adalah variabel bertipe integer, yang akan menampung hasil semua kombinasi semua angka, dari pemanggilan fungsi secara rekursif, yaitu pemanggilan berikut:

```cpp
generateNumber(n, num * 10 + 1, davec, curr + 1);
generateNumber(n, num * 10 + 3, davec, curr + 1);
```

Ketika pemanggilan pertama, `num` akan bernilai angka satuan, karena perkalian dengan 10 akan menghasilkan 0, karena `num` masih bernilai 0. Selanjutnya, num sudah berisi angka satuan, dan pemanggilan berikutnya akan membangun kombinasi angka satu-persatu. Setiap pemanggilan fungsi, akan menambahkan nilai `curr` sebanyak 1, sehingga ketika panjang digit pada `num` sudah tepat $n$, maka pemanggilan fungsi secara recursif akan mencapai base case, dan berhenti:

```cpp
if (curr == n + 1)
	return;
```

Setiap pemanggilan fungsi, setiap `num` yang bukan 0, akan disimpan kedalam vector `rest`, menyimpan kombinasi dari angka-angka yang telah disusun dari pemanggilan fungsi secara rekursif.

Jika kita ingin menyusun angka dengan digit lain, kita bisa menambahkan banyaknya pemanggilan fungsi seperti berikut:

```cpp
generateNumber(n, num * 10 + 4, davec, curr + 1);
generateNumber(n, num * 10 + 7, davec, curr + 1);
generateNumber(n, num * 10 + 9, davec, curr + 1);
```

Syntax diatas akan membuat kita membangun beberapa kombinasi angka dengan digit $4,7,9$. Tapi, jika kombinasi digit yang ingin kita buat cukup banyak, akan jauh lebih baik jika kita menyimpanya di dalam array, lalu lakukan pemanggilan berdasarkan traversal, sebagai berikut:

```cpp
#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;

void generateNumber(int n, int num, VI& davec, VI& gen, int curr = 0) {
    if (curr > n)
        return;
    if (num > 0) {
        davec.push_back(num);
    }

    for (const auto& x : gen) {
        generateNumber(n, num * 10 + x, davec, gen, curr + 1);
    }
}

auto main() -> int {
    int n, k;
    cin >> n >> k;
    vector<int> vec;
    vector<int> gen(k);
    for (auto& x : gen) {
        cin >> x;
    }
    generateNumber(n, 0, vec, gen);

    for (const auto& x : vec) {
        cout << x << '\n';
    }

    return 0;
}
```

Pendekatan diatas jauh lebih dinamis, karena kita bisa mengatur berapa banyak maksimal digit pada angka yang ingin kita buat, dan juga kombinasi digit apa saja yang ingin kita buat. 

Jika semisal kombinasi yang ingin dibuat cukup besar, katakanlahkan melebihi batas int, atau long long, kita bisa menyusun atau membangun kombinasi angka dengan `string`. Kita bisa menyimpan digit-digit yang akan digunakan sebagai `char`, lalu menyusun variabel `num` bukan sebagai integer, melainkan sebagai string. Vector `vec` juga kita ganti sebagai string, supaya bisa menyimpan tipe data string.

Sehingga, kodenya mungkin seperti ini:

```cpp
#include <iostream>
#include <vector>
using namespace std;

using VS = vector<string>;
using VC = vector<char>;

void generateNumber(int n, string num, VS& davec, const VC& gen, int curr = 0) {
    if (curr > n)
        return;
    if (!num.empty()) {
        davec.push_back(num);
    }

    for (const auto& x : gen) {
        generateNumber(n, num + x, davec, gen, curr + 1);
    }
}

auto main() -> int {
    int n, k;
    cin >> n >> k;
    vector<string> vec;
    vector<char> gen(k);
    for (auto& x : gen) {
        cin >> x;
    }
    generateNumber(n, "", vec, gen);

    for (const auto& x : vec) {
        cout << x << '\n';
    }

    return 0;
}
```

Kelebihan dari kode ini bukan saja bisa menyusun angka yang sangat besar, tapi juga bisa menyusun kombinasi dari beberapa karakter, baik itu huruf, tanda baca, atau karakter-karakter lain. Sehingga multifungsi.

## 2.2 | Generate Angka dengan Panjang Tepat $n$

Jika semisal yang dicari adalah generate angka dengan panjang tepat $n$, maka kita cukup melakukan sedikit modifikasi pada fungsi `generateNumber()`, dimana kita hanya menyimpan kombinasi angka hanya jika angka tersebut memiliki panjang tepat $n$, atau pemanggilan fungsi rekursif tepat $n$ kali. Kodenya adalah sebagai berikut:

```cpp
#include <iostream>
#include <vector>
using namespace std;

using VS = vector<string>;
using VC = vector<char>;

void generateNumber(int n, string num, VS& davec, const VC& gen, int curr = 0) {
    if (curr == n) {
        davec.push_back(num);
        return;
    }

    for (const auto& x : gen) {
        generateNumber(n, num + x, davec, gen, curr + 1);
    }
}

auto main() -> int {
    int n, k;
    cin >> n >> k;
    vector<string> vec;
    vector<char> gen(k);
    for (auto& x : gen) {
        cin >> x;
    }
    generateNumber(n, "", vec, gen);

    for (const auto& x : vec) {
        cout << x << '\n';
    }

    return 0;
}
```

<br/>

---

# 3 | Cara Iteratif

Walaupun cara rekursif tampak jauh lebih mudah dipahami, tapi jika ukuran kombinasi besar, bisa saja terjadi stack overflow, karena rekursif mengandalkan memory. Sehingga, kita perlu mengatasi dengan cara iteratif.

## 3.1 | Generate Angka dengan Panjang Maksimal $n$

Sebelumnya kita sudah belajar pendekatan statis, tapi karena program yang bagus seharusnya bisa menerima inputan dinamis, maka kita akan membuat contoh-contoh selanjutnya juga dinamis.

Program berikut akan mengenerate angka dengan panjang maksimal $n$, dengan digit atau karakter kombinasi dinamis:

```cpp
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
    int n, k;
    cin >> n >> k;
    vector<char> gen(k);
    for (auto& x : gen) {
        cin >> x;
    }

    for (int len = 1; len <= n; len++) {
        vector<int> idx(len, 0);

        while (true) {
            for (int i = 0; i < len; i++) cout << gen[idx[i]];
            cout << "\n";

            int pos = len - 1;
            while (pos >= 0) {
                idx[pos]++;
                if (idx[pos] < k)
                    break;
                idx[pos] = 0;
                pos--;
            }
            if (pos < 0)
                break;
        }
    }
}
```

## 3.2 | Generate Angka dengan Panjang Tepat $n$

```cpp
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
    int n, k;
    cin >> n >> k;
    vector<char> gen(k);
    for (auto& x : gen) {
        cin >> x;
    }

    vector<int> idx(n, 0);

    while (true) {
        for (int i = 0; i < n; i++) cout << gen[idx[i]];
        cout << "\n";

        int pos = n - 1;
        while (pos >= 0) {
            idx[pos]++;
            if (idx[pos] < k)
                break;
            idx[pos] = 0;
            pos--;
        }
        if (pos < 0)
            break;
    }
}
```
