---
obsidianUIMode: preview
note_type: latihan
latihan: Turnamen Game Online
sumber:
  - chatgpt.com
tags:
  - data-structure
  - tuple
date_learned: 2025-08-29T18:13:00
---
---
# 1 | Turnamen Game Online

Sebuah turnamen online punya data pemain dalam bentuk:

* ID pemain (`int`)
* Nickname (`string`)
* Statistik (disimpan dalam `tuple<int,int,int>`, berisi `(kills, deaths, assists)`)
* Total poin rank (`int`)

### Aturan Sorting

1. Urutkan pemain berdasarkan **rank tertinggi** (`rank` descending).
2. Jika rank sama, urutkan berdasarkan **kill terbanyak** (descending).
3. Jika kill sama, urutkan berdasarkan **rasio KDA** (`(kills+assists)/max(1,deaths)`) terbesar.
4. Jika tetap sama, urutkan berdasarkan **nickname** ascending (A-Z).

### Input Format

* Baris pertama: `N` (jumlah pemain, `1 ≤ N ≤ 1000`).
* Baris berikutnya: `id nickname kills deaths assists rank`.

### Output Format

1. Daftar pemain setelah diurutkan, dalam format:

   ```
   ID Nickname K/D/A Rank
   ```

   (contoh: `101 ShadowX 20/5/10 3000`)
2. Ringkasan 3 pemain teratas.


### Sample Text Case

```
6
101 ShadowX 20 5 10 3000
102 Luna 15 3 7 2800
103 Zephyr 20 5 10 3000
104 Blaze 10 2 20 3000
105 Orion 20 5 10 3200
106 Aria 20 5 10 3000
```

Output:

```
105 Orion 20/5/10 3200
106 Aria 20/5/10 3000
101 ShadowX 20/5/10 3000
103 Zephyr 20/5/10 3000
104 Blaze 10/2/20 3000
102 Luna 15/3/7 2800

Top 3 Players:
105 Orion
106 Aria
101 ShadowX
```

1. Urutkan berdasarkan **rank** descending → `Orion (3200)` pasti paling depan.
2. Sisanya rank `3000`: `ShadowX, Zephyr, Blaze, Aria`.
3. Bandingkan **kills** → Blaze (10 kills) kalah dari yang 20 kills → Blaze di belakang.
4. Sisa `ShadowX, Zephyr, Aria` → kills sama (`20`), deaths sama (`5`), assists sama (`10`), jadi KDA ratio sama → fallback ke nickname ascending → `Aria, ShadowX, Zephyr`.

### Tantangan

* Gunakan `tuple` sebagai representasi tiap pemain.
* Lakukan sorting menggunakan **`std::tie` atau `std::tuple`** untuk membandingkan banyak kriteria sekaligus.
* Jangan lupa hitung rasio KDA di comparator.


⚔️ Ini lumayan tricky karena ada perhitungan turunan (KDA ratio) di dalam sorting.

<br/>

---
# 2 | Jawaban

## 2.1 | Jawaban Pertama

Ini adalah jawaban pertamaku, aku mencoba menggunakan custom sort tanpa `tie()`:

```cpp
#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

struct Player {
    int id{};
    string nick;
    tuple<int, int, int> stats;
    int rank{};
    int kda = 0;
};

namespace {
void outputPlayer(const Player& p) {
    cout << p.id << " " << p.nick << " " << get<0>(p.stats) 
    << "/" << get<1>(p.stats)
    << get<2>(p.stats) << " " << p.rank << "\n";
}
}  // namespace

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;

    vector<Player> player(n);

    for (auto& [id, nick, stats, rank, kda] : player) {
        int k = 0;
        int d = 0;
        int a = 0;
        cin >> id >> nick >> k >> d >> a >> rank;

        tuple<int, int, int> getData = {k, d, a};
        stats = getData;

        kda = (k + a) / max(1, d);
    }

    ranges::sort(player, [](const auto& a, const auto& b) {
        if (a.rank == b.rank) {
            if (get<0>(a.stats) == get<0>(b.stats)) {
                if (a.kda == b.kda) {
                    if (a.nick < b.nick) {
                        return true;
                    }
                } else if (a.kda > b.kda) {
                    return true;
                }
            } else if (get<0>(a.stats) > get<0>(b.stats)) {
                return true;
            }
        } else if (a.rank > b.rank) {
            return true;
        }

        return false;
    });

    cout << '\n';
    for (const auto& x : player) {
        outputPlayer(x);
    }

    cout << "\nTop 3 Players:\n";
    for (int i = 0; i < min(3, n); i++) {
        cout << player[i].id << " " << player[i].nick << '\n';
    }

    return 0;
}
```

## 2.2 | Jawaban Kedua

Well, seperrti biasa, kita bisa menggunakan custom sort dengan menggunakan bantuan fungsi `tie()`, sebagai berikut:

```cpp
ranges::sort(player, [](const auto& a, const auto& b) {
    int rankA = -a.rank;
    int rankB = -b.rank;
    int killsA = -get<0>(a.stats);
    int killsB = -get<0>(b.stats);
    int kdaA = -a.kda;
    int kdaB = -b.kda;

    auto keyA = tie(rankA, killsA, kdaA, a.nick);
    auto keyB = tie(rankB, killsB, kdaB, b.nick);
    return keyA < keyB;
});
```

<br/>

---
# 3 | Editorial

Soal ini sebenarnya hampir sama seperti soal sebelumnya, hanya saja dibuat lebih sulit saja, karena aku ingin mencoba kombinasi tuple didalam struct, yang ada didalam vector.