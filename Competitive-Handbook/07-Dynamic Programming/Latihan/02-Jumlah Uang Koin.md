---
obsidianUIMode: preview
note_type: latihan
latihan: Jumlah Uang Koin
sumber:
  - chatgpt.com
tags:
  - dynamic-programming
date_learned: 2025-09-02T03:21:00
---
---
# 1 | Jumlah Uang Koin

Diberikan sejumlah koin dengan nilai berbeda, dan sebuah target nilai $N$. Tentukan banyak cara untuk menyusun koin-koin tersebut sehingga total nilainya sama dengan $N$.

Setiap jenis koin dapat digunakan tanpa batasan jumlah. Urutan koin tidak diperhitungkan (misalnya kombinasi ${1,2}$ sama dengan ${2,1}$).

**Input:**

- Baris pertama berisi dua bilangan bulat $M$ dan $N$ ($1 \leq M \leq 50$, $1 \leq N \leq 1000$), dengan $M$ menyatakan banyaknya jenis koin.
- Baris kedua berisi $M$ bilangan bulat $a_1, a_2, \dots, a_M$ yang menyatakan nilai masing-masing koin.

**Output:**

- Satu bilangan bulat yang menyatakan banyak cara untuk membentuk nilai $N$.

**Contoh:**

```
Input:
3 4
1 2 3

Output:
4
```

**Penjelasan:**  
Nilai $4$ bisa dibentuk dengan cara:

1. $1 + 1 + 1 + 1$
2. $1 + 1 + 2$
3. $2 + 2$
4. $1 + 3$

<br/>

---
# 2 | Jawaban

## 2.1 | Jawaban Versi Pertamaku

Berikut adalah jawaban yang ditujukan untuk menangani satu inputan:

```cpp
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
    int m = 0;
    int n = 0;
    cin >> m >> n;
    vector<int> coins(m);
    for (auto& x : coins) {
        cin >> x;
    }

    vector<int> dp(n + 1);
    dp[0] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            if (coins[i] <= j) {
                dp[j] += dp[j - coins[i]];
            }
        }
    }

    cout << dp[n];
    return 0;
}
```

## 2.2 | Versi Multi Testcase

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    static void solve() {
        int m = 0;
        int n = 0;
        cin >> m >> n;
        vector<int> coins(m);
        vector<long long> dp(n + 1);
        for (auto& x : coins) {
            cin >> x;
        }

        dp[0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 1; j <= n; j++) {
                if (coins[i] <= j) {
                    dp[j] += dp[j - coins[i]];
                }
            }
        }

        cout << dp[n] << "\n";
    }
};

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 0;
    cin >> t;
    while ((t--) != 0) {
        Solution::solve();
    }

    return 0;
}
```

<br/>

---
# 3 | Editorial
## 3.1 | Petunjuk Official

### Petunjuk Penyelesaian

1. **Definisikan fungsi DP**  
    Misalkan $dp[x]$ = banyak cara untuk menyusun koin sehingga total nilainya **tepat** $x$.
    
2. **Basis kasus**
    
    - $dp[0] = 1$ (ada tepat satu cara membentuk $0$, yaitu tidak memilih koin).
        
3. **Transisi**
    
    - Untuk setiap koin $a_i$, perbarui $dp[x]$ dengan menambahkan cara dari $dp[x - a_i]$ (jika $x \geq a_i$).
        
    
    Jadi secara umum:
    $$dp[x] = \sum_{i=1}^{M} dp[x - a_i] \quad \text{(untuk semua $x \geq a_i$)}$$
    
    Bedanya dengan soal tangga:
    
    - Di tangga, pilihan langkah **tetap** (hanya 1 atau 2).
    - Di sini, pilihan koin berasal dari input, jadi lebih umum.
        
4. **Urutan iterasi**
    
    - Supaya tidak menghitung urutan berbeda sebagai solusi berbeda (misalnya ${1,2}$ sama dengan ${2,1}$), iterasi koin dulu, baru nilai $x$.
        
5. **Hasil akhir**
    
    - Jawaban ada di $dp[N]$.
### Ilustrasi kecil

Input:

```
3 4
1 2 3
```

- Mulai dengan $dp[0] = 1$.
    
- Pakai koin 1 → bisa bangun semua nilai.
    
- Tambahkan koin 2 → tambahkan kombinasi baru.
    
- Tambahkan koin 3 → tambahkan kombinasi baru.
    

Akhirnya $dp[4] = 4$.

## 3.2 | Editorial Sendiri

Jadi, karena yang diminta adalah banyaknya kombinasi, maka:

$$2+2+3 = 3+2+2$$

Urutan tidak penting, yang penting adalah banyaknya kombinasi angka-angka yang ada. Sehingga didapat jawaban seperti 2 versi jawaban diatas.

Karena diketahui bahwa rumus dari permasalah ini adalah:

$$dp[x] = \sum_{i=1}^{M} dp[x - a_i] \quad \text{(untuk semua $x \geq a_i$)}$$

Maka, didapat solusinya adalah sebagai berikut:

```cpp
dp[0] = 1;
for (int i = 0; i < m; i++) {
	for (int j = 1; j <= n; j++) {
		if (coins[i] <= j) {
			dp[j] += dp[j - coins[i]];
		}
	}
}
```


Tetapi, jika yang dicari adalah permutasi (urutan penting), maka rumusnya adalah:

$$
dp[x] = \sum_{\substack{i=1 \\ a_i \leq x}}^{M} dp[x - a_i]
\quad \text{untuk semua } x \geq 1
$$

Dengan implementasi adalah sebagai berikut:

```cpp
dp[0] = 1;
for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
        if (coins[j] <= i) {
            dp[i] += dp[i - coins[j]];
        }
    }
}
```

Bedanya:

* Kombinasi: "loop koin dulu, baru jumlah" → menghindari double count urutan.
* Permutasi: "loop jumlah dulu, baru koin" → tiap urutan dihitung berbeda.
