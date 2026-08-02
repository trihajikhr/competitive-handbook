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

Kamu ingin menaiki tangga hingga anak tangga ke-$N$. Kamu bisa melakukan gerakan yang terdiri dari $1$ langkah atau $2$ langkah. 

Namun, tidak seperti anak tangga pada umumnya, sebanyak $B$ anak tangga yang ada ternyata rusak dan tidak bisa ditempati. Artinya, kamu tidak bisa menempati setiap anak tangga $B_i$, dan harus melompatinya jika memungkinkan. Dijami bahwa tidak ada $2$ anak tangga yang rusak secara berturut-turut, sehingga selalu mungkin untuk sampai ke anak tangga ke-$N$.

Tentukan berapa banyak kombinasi langkah yang bisa diambil untuk sampai ke anak tangga ke-$N$.

---

## Editorial

---
## Jawaban

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
    int n, bk;
    cin >> n >> bk;
    vector<int> dp(n + 1, 0);
    vector<int> broken(bk);

    for (int i = 0; i < bk; i++) {
        cin >> broken[i];
    }

    sort(broken.rbegin(), broken.rend());
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    if (!broken.empty() && broken.back() == 1) {
        dp[1] = 0;
        broken.pop_back();
    } else if (!broken.empty() && broken.back() == 2) {
        dp[2] = 0;
        broken.pop_back();
    }

    for (int i = 3; i <= n; i++) {
        if (!broken.empty() && broken.back() == i) {
            dp[i] = 0;
            broken.pop_back();
            continue;
        }

        int a = 0, b = 0;
        if (dp[i - 1] != 0) {
            a = dp[i - 1];
        }

        if (dp[i - 2] != 0) {
            b = dp[i - 2];
        }

        dp[i] = a + b;
    }

    cout << dp[n];

    return 0;
}

```