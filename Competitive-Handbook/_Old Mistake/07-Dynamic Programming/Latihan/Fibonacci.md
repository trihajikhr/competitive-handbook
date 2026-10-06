---
obsidianUIMode: preview
note_type: latihan
latihan: Fibonacci
sumber:
  - myself
tags:
  - dynamic-programming
date_learned: 2026-02-14T21:50:00
---
Link Sumber: 

---
> [!IMPORTANT]
# Fibonacci

Diberikan nilai $n$. Tentukan bilangan fibonacci ke $n$.

**Input:**
Diberikan $t$ sebagai jumlah test case dengan $1 \le t \le 100$. 

Pada $t$ baris berikutnya diberikan nilai $n$, dimana $1 \le n \le 92$.

**Output:**
Bilangan fibonacci ke $n$ pada setiap baris.

**Tugas:**
Selesaikan permasalahan ini dengan tiga pendekatan berikut.

1. Pendekatan 1  
   Hitung bilangan Fibonacci ke-$n$ menggunakan dynamic programming dengan kompleksitas memori $O(1)$.

2. Pendekatan 2  
   Hitung bilangan Fibonacci ke-$n$ menggunakan dynamic programming rekursif dengan memoization.

3. Pendekatan 3  
   Hitung bilangan Fibonacci ke-$n$ menggunakan dynamic programming iteratif dengan memoization.


<br/>

---
## Jawaban

### Pendekatan 1

```cpp
#include <array>
#include <iostream>
using namespace std;

const int MAX = 3;

auto solve(int n) -> long long {
    array<long long, MAX> dp{};
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i % MAX] = dp[(i - 1) % MAX] + dp[(i - 2) % MAX];
    }

    return dp[n % MAX];
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << solve(n) << "\n";
    }
    return 0;
}
```

### Pendekatan 2

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, long long> dp;
auto solve(int n) -> long long {
    if (dp.count(n)) {
        return dp[n];
    }

    if (n == 1 || n == 2) {
        return 1;
    }

    if (n == 0) {
        return 0;
    }

    return dp[n] = solve(n - 1) + solve(n - 2);
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    dp.reserve(92);

    while (t--) {
        int n;
        cin >> n;
        cout << solve(n) << "\n";
    }
    return 0;
}
```


### Pendekatan 3

```cpp
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 92;
vector<long long> dp(MAX + 1);

void precompute() {
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= MAX; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    precompute();
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}
```

<br/>

---
## Editorial

Semua pendekatan yang digunakan diatas sudah dijelaskan secara mendalam dan detail pada perkenalan materi dynamic programming, [Introduction to Dynamic Programming](Introduction%20to%20Dynamic%20Programming.md).