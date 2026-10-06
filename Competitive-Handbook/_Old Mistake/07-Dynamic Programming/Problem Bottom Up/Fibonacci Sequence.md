---
obsidianUIMode: preview
note_type: latihan
judul_problem: Fibonacci Sequence
latihan: dynamic programming bottom-up
sumber:
  - myself
tags:
  - dynamic-programming
date_learned: 2026-07-20T02:18:00
---
Link Sumber: 

---
> [!IMPORTANT]
# Fibonacci Sequence

Diberikan nilai $n$, tentukan nilai deret Fibonacci pada urutan ke-$n$.


<br/>

---
## Jawaban

```cpp
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n - 1];

    return 0;
}

```

<br/>

---
## Editorial

Ini adalah problem klasik untuk memperkenalkan konsep *Dynamic Programming* (*DP*). Pendekatan yang digunakan adalah *bottom-up*, yaitu menyelesaikan submasalah dari yang paling kecil, kemudian membangun solusi untuk submasalah yang lebih besar.

Kita mengetahui bahwa deret Fibonacci memenuhi relasi berikut:

$$  
f(n)=f(n-1)+f(n-2)  
$$

Daripada menggunakan pendekatan rekursif yang menghitung banyak submasalah berulang kali sehingga boros waktu, kita dapat menyimpan hasil perhitungan setiap submasalah menggunakan *Dynamic Programming*.

Pertama, buat sebuah array satu dimensi $dp$ untuk menyimpan nilai Fibonacci yang telah dihitung. Selanjutnya, tetapkan nilai dasar (_base case_) sebagai berikut:

$$  
dp[0]=0,\qquad dp[1]=1  
$$

Setelah itu, setiap nilai $dp[i]$ dapat dihitung menggunakan relasi yang sama seperti definisi deret Fibonacci:

$$  
dp[i]=dp[i-1]+dp[i-2]  
$$

Karena nilai $dp[i-1]$ dan $dp[i-2]$ telah dihitung sebelumnya, kita cukup mengisi array $dp$ secara berurutan mulai dari $i=2$ hingga $n$. Dengan demikian, setiap submasalah hanya dihitung satu kali sehingga kompleksitas waktunya menjadi $O(n)$.