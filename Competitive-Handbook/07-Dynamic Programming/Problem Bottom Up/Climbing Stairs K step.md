---
obsidianUIMode: preview
note_type: latihan
judul_problem: Climbing Stairs K step
latihan: dynamic programming bottom-up
sumber:
  - myself
tags:
  - dynamic-programming
date_learned: 2026-07-20T03:22:00
---
Link Sumber: 

---
> [!IMPORTANT]
# Climbing Stairs K step

Ada sebuah tangga, dimana kamu ingin menaiki tangga tersebut hingga anak tangga ke $n$. Untuk setiap gerakan, kamu bisa bergerak sebanyak $k$ anak tangga sekaligus. Tentukan berapa banyak kombinasi gerakan yang bisa diambil untuk sampai ke anak tangga ke $n$.

**Constrainst:**
- $n \ge 2$
- $k \ge 1$

## Editorial

Masalah ini bertujuan untuk mencari total cara unik yang dapat ditempuh untuk mencapai anak tangga ke-$n$. Pada setiap langkah, seseorang diperbolehkan untuk menaiki minimal $1$ anak tangga hingga maksimal $k$ anak tangga sekaligus. Problem ini merupakan variasi dari permasalahan *climbing stairs*, dan bisa diselesaikan dengan *dynamic programming*.

Penyelesaian ini  menggunakan *dynamic programming* dengan teknik _bottom-up_ untuk menghindari perhitungan ulang yang berulang kali seperti pada rekursi biasa. State $dp[i]$ merepresentasikan jumlah cara unik untuk mencapai anak tangga ke-$i$.

Relasi rekurensi untuk masalah ini didefinisikan sebagai berikut:

$$dp[i] = \sum_{j=1}^{k} dp[i - j]$$

Dengan batasan bahwa $i - j \ge 0$. Basis kasus dari relasi ini adalah:

$$dp[0] = 1$$

Artinya, hanya terdapat $1$ cara untuk berada di lantai dasar (tidak melangkah sama sekali).

**Analisis Kompleksitas**

Kompleksitas waktu dari algoritma ini adalah $O(n \cdot k)$ karena terdapat perulangan luar sebanyak $n$ kali dan perulangan dalam sebanyak $k$ kali untuk setiap iterasi. Kompleksitas memori adalah $O(n)$ karena penggunaan _vector_ berukuran $n + 1$ untuk menyimpan state sebelumnya.
## Jawaban

```cpp
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
    int n, k;
    cin >> n >> k;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                sum += dp[i - j];
            } else {
                break;
            }
        }
        dp[i] = sum;
    }
    
    cout << dp[n];
    return 0;
}
```
