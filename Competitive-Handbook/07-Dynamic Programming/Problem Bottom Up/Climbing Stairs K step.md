---
obsidianUIMode: preview
note_type: latihan
judul_problem:
latihan:
sumber:
tags:
date_learned:
---
Link Sumber: 

---
> [!IMPORTANT]
# Judul

Ada sebuah tangga, dimana kamu ingin menaiki tangga tersebut hingga anak tangga ke $n$. Untuk setiap gerakan, kamu bisa bergerak sebanyak $k$ anak tangga sekaligus. Tentukan berapa banyak kombinasi gerakan yang bisa diambil untuk sampai ke anak tangga ke $n$.

**Constrainst:**
- $n \ge 2$
- $k \ge 1$

<br/>

---
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

<br/>

---
## Editorial