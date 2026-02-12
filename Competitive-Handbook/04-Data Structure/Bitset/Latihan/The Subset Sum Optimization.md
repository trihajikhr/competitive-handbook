---
obsidianUIMode: preview
note_type: latihan
latihan: The Subset Sum Optimization
sumber:
  - gemini.google.com
tags:
  - data-structures
  - bitset
date_learned: 2026-02-13T01:56:00
---
Link Sumber: 

---
> [!IMPORTANT]
# The Subset Sum Optimization

Diberikan $N$ buah angka positif. Tugasmu adalah menentukan apakah mungkin untuk memilih beberapa angka dari kumpulan tersebut sehingga jumlah totalnya tepat sama dengan $S$. Jika mungkin, outputkan `YES`, dan jika tidak, maka outputkan `NO`.

**Batasan:**

- $N \le 10,000$
- $S \le 10,000$
- Masing-masing angka $A_i \le 10,000$
- Waktu: 0.5 detik (Sangat ketat!)

**Tugasmu:**

Selesaikan masalah ini menggunakan `std::bitset`. Jika menggunakan dynamic programming (DP) biasa dengan `bool dp[10001]`, mungkin akan terasa lambat atau standar. Gunakan bitset untuk melakukan transisi DP dalam satu operasi geser bit.

<br/>

---
## 1. Jawaban

```cpp
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

void solve() {
    int N, S;
    cin >> N >> S;

    // Deklarasi bitset dengan ukuran S maksimal (10000 + 1)
    // Bitset harus berukuran konstan (compile-time constant)
    bitset<10001> dp;

    // Base case: jumlah 0 selalu bisa dicapai
    dp[0] = 1;

    for (int i = 0; i < N; i++) {
        int angka;
        cin >> angka;
        
        // Trik Sakti: Update semua kemungkinan jumlah dalam satu baris!
        // Ini setara dengan looping manual tapi 32x-64x lebih cepat.
        if (angka <= S) {
            dp |= (dp << angka);
        }
    }

    // Cek apakah bit ke-S menyala
    if (dp[S]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
```

<br/>

---
## 2. Editorial

Dalam *dynamic programming* biasa untuk _subset sum_, kita mungkin akan menulis kode seperti ini:

```cpp
for (int i = S; i >= angka; i--) {
    if (dp[i - angka]) dp[i] = true;
}
```

Masalahnya, loop di atas berjalan satu per satu. Dengan bitset, kita bisa memproses semua kemungkinan jumlah secara paralel!

Bayangkan bitset sebagai barisan lampu ($0$ atau $1$). Indeks bitset merepresentasikan jumlah yang mungkin dicapai.

1. **Inisialisasi**: `bitset<10001> dp; dp[0] = 1;`
    
    - Artinya: Baru jumlah `0` yang mungkin. (Kondisi: `...000001`)
        
2. **Transisi**: Misal kita punya angka **$3$**. Kita ingin semua jumlah yang sudah ada ditambah $3$.
    
    - Dalam bitset, ini cukup dengan: `dp |= (dp << 3);`
    - `dp << 3` artinya menggeser semua "lampu" yang menyala sejauh $3$ langkah ke kiri.
    - `|=` (OR) artinya kita menggabungkan kemungkinan lama dengan kemungkinan baru.

### 2.1. Kenapa ini Cepat?

Jika $S = 10,000$, operasi `dp |= (dp << angka)` tidak melakukan $10,000$ operasi satu per satu di tingkat prosesor. Karena bitset disimpan dalam bentuk `unsigned long long` (64 bit) secara internal, prosesor hanya melakukan sekitar $10,000 / 64 \approx 156$ operasi saja. Itulah kenapa bitset sering disebut sebagai optimasi $\frac{N}{64}$.

### 2.2. Tips Tambahan:

- **Ukuran Bitset**: Harus berupa angka pasti (konstanta), tidak bisa pakai variabel `bitset<S>`. Jadi, gunakan angka maksimal dari soal.
    
- **Method Berguna**:
    
    - `dp.count()`: Menghitung berapa banyak angka yang bisa dibentuk.
        
    - `dp._Find_first()`: Menemukan jumlah terkecil yang bisa dibentuk (selain $0$).
        
