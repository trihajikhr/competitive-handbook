---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Mengefisiensikan Perhitungan Faktorial
sumber:
  - myself
  - chatgpt.com
date_learned: 2026-01-13T18:49:00
tags:
  - number-theory
  - tips-trick
---
---
# Mengefisiensikan Perhitungan Faktorial

Misal kita diberikan sebuah tantangan, dimana kita diminta untuk mendapatkan jumlah dari hasil perkalian dari $1$ hingga $n$. Awalnya mudah bagi kita untuk menyelesaikan tantangan ini dengan kompleksitas $O(n)$, semisal melakukan perulangan sebanyak $n$, dan menjumlahkan semua total perkalian seperti berikut:

```cpp
#include<iostream>
#include<set>
using namespace std;

auto main() -> int {
    long long sum = 1, n;
    cin >> n;

    for (long long i = 1; i <= n; i++) {
        sum *= i;
    }

    cout << sum;
    return 0;
}
```

Ini adalah algoritma umum untuk mencari nilai dari faktorial $n!$, jumlah perkalian dari $1$ hingga $n$. Namun apa jadinya jika semisal kita diminta untuk menghitung jumlah faktorial berulang kali pada program yang kita buat?

Melakukan perhitunga satu-persatu sebenarnya kurang efisien, karena kita selalu mengulang perhitungan yang dimulai dari $1$ berulang kali. Langkah yang paling tepat adalah dengan mengefisiensikan waktu perhitungan, dengan cara melakukan *trade-off* pada penggunaan memory, yaitu dengan menggunakan array bantu, atau melakukan *precompute*.

## 1. Precompute Array

Semisal kita diberikan sebanyak $1.000.000$ test case untuk menjawab berapa hasil dari faktorial $1$ hingga $20$ (karena untuk nilai $n$ yang lebih besar dari $20$-an, harus menggunakan bantuan modulo karena batasan tipe data long long), maka kita bisa menyiapkan array yang menyimpan hasil dari setiap faktorial dari $1$ hingga $20$ terlebih dahulu, misal sebagai berikut:

```cpp
#include<iostream>
#include <vector>
using namespace std;

auto main() -> int {
    vector<long long> fact(20 + 1);
    data[0] = 1;
    for (long long i = 1; i <= 20; i++) {
        fact[i] = fact[i-1] * i;
    }

    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        cout << fact[a] << "\n";
    }
    return 0;
}
```

Karena kita harus menjawab hingga $1.000.000$ query dan nilai $n$ hanya berada pada rentang kecil $(0–20)$, kita dapat melakukan precomputation faktorial terlebih dahulu. Dengan menyimpan nilai $n!$ ke dalam array, setiap query dapat dijawab dalam waktu konstan $O(1)$.

## 2. Precompute Array Dengan Modulo

Namun, jauh lebih sering batasan $n$ untuk nilai faktorial sangatlah tinggi, misal rentang $n$ berada di rentang $1 \leq n \leq 10^6$, maka data yang disimpan pada array precompute adalah angka hasil modulo, karena nilai faktorial tumbuh sangat cepat dan akan melampaui kapasitas tipe data bawaan, sehingga yang disimpan adalah nilai faktorial dalam modulo tertentu. 

Biasanya, nilai modulo yang digunakan adalah $1.000.000.07$ atau $10^9 + 7$. Pendekatan ini hanya valid jika semua operasi dilakukan dalam modulo yang sama.

Maka, operasi precompute yang digunakan bisa dirubah menjadi seperti ini:

```cpp
#include<iostream>
#include <vector>
using namespace std;

constexpr long long MOD = 1e9 + 7;
constexpr long long MAXN = 1e6;

auto main() -> int {
    vector<long long> fact(MAXN + 1);
    fact[0] = 1;
    for (long long i = 1; i <= MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << fact[n] << "\n";
    }
    return 0;
}
```

Precompute ini akan membuat pencarian nilai dari faktorial $n$ bisa dicari cukup dengan kompleksitas konstan $O(1)$, karena cukup gunakan $n$ sebagai indeks untuk mengakses data yang sudah disimpan didalam vector $fact$.

