---
obsidianUIMode: preview
note_type: latihan
latihan: Circular Queue Game
sumber:
  - chatgpt.com
tags:
  - data-structure
  - queue
date_learned: 2025-08-28T20:56:00
---
---
# 1 | Circular Queue Game

Ada `N` orang berdiri melingkar, dinomori `1..N`. Mereka bermain sebuah permainan dengan aturan:

1. Orang nomor `1` memegang sebuah token.
2. Setiap langkah, token dipindahkan ke orang berikutnya secara melingkar (setelah orang `N`, kembali ke orang `1`).
3. Setiap kali token sudah berpindah sebanyak `K` kali, orang yang memegang token **dikeluarkan dari lingkaran**. Token kemudian langsung diberikan ke orang berikutnya (yang masih ada).
4. Proses ini berlanjut sampai hanya tersisa 1 orang.

**Tugasmu:** tentukan nomor orang yang terakhir bertahan.

Contoh input:

```
7 3
```

Output:

```
4
```

(Permainan eliminasi dengan N=7, K=3, mirip Josephus Problem, tapi diminta implementasi dengan queue).

👉 Kedua soal ini tetap berbasis **queue**, tapi lebih ke arah **simulasi** dengan twist unik:

* **Soal 1:** fokus ke **queue + prioritas** (mirip printer scheduling).
* **Soal 2:** fokus ke **circular queue** (mirip game eliminasi).

Mau aku bikinkan juga **hint solusi** dalam bentuk langkah-langkah berpikir (tanpa langsung kasih kode), biar cocok dengan metode STRIKE-mu?

<br/>

---
# 2 | Jawaban

Berikut adalah jawabanku:

```cpp
#include <iostream>
#include <queue>
using namespace std;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    int k = 0;
    cin >> n >> k;

    queue<int> player;
    for (int i = 0; i < n; i++) {
        player.push(i);
    }

    int cnt = 1;
    while (player.size() > 1) {
        if (cnt % k == 0) {
            player.pop();
        } else {
            player.push(player.front());
            player.pop();
        }
        cnt++;
    }

    cout << player.front() + 1;
    return 0;
}
```

<br/>

---
# 3 | Editorial

Ini hanya soal yang aku kerjakan sebagai sesi pendinginan, setelah banyak mengerjakan soal yang sulit.  Kode diatas seharusnya mudah untuk dipahami, jadi aku tidak akan membuat editorial untuk soal ini.