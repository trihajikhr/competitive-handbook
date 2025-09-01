---
obsidianUIMode: preview
note_type: latihan
latihan: Liga Programmer
sumber:
  - chatgpt.com
tags:
  - data-structure
  - tuple
date_learned: 2025-08-29T18:50:00
---
---
# 1 | Liga Programmer

Ada sebuah **liga programmer**. Setiap peserta punya data:

* `id` → nomor unik
* `nick` → string
* `stat` → tuple `(solved, penalty, submissions)`
* `country` → string
* `rating` → integer

### Tugasmu

1. Urutkan peserta dengan aturan:

   2. **Rating tertinggi dulu** (descending)
   3. Jika sama, urutkan berdasarkan **soal terselesaikan terbanyak** (descending)
   4. Jika sama, urutkan berdasarkan **penalty terkecil** (ascending)
   5. Jika sama, urutkan berdasarkan **submissions paling sedikit** (ascending)
   6. Jika masih sama, urutkan berdasarkan **nick secara alfabetis** (ascending)

7. Setelah diurutkan, tampilkan:

   * Top 10 peserta
   * Negara dengan total solved terbanyak
   * Peserta dengan submissions paling efisien (rasio `solved/submissions` tertinggi, min submissions ≥ 10)

### Sample Input

```
8
1 Alice 50 300 200 USA 2800
2 Bob 48 250 190 JPN 2800
3 Charlie 50 310 180 USA 2800
4 Dave 45 200 150 IDN 2700
5 Eve 50 250 200 GER 2800
6 Frank 48 260 200 USA 2800
7 Grace 40 150 120 JPN 2600
8 Heidi 45 220 180 IDN 2700
```

### Sample Output

```
Sorted Leaderboard:
1 Alice 50 300 200 USA 2800
5 Eve 50 250 200 GER 2800
3 Charlie 50 310 180 USA 2800
2 Bob 48 250 190 JPN 2800
6 Frank 48 260 200 USA 2800
4 Dave 45 200 150 IDN 2700
8 Heidi 45 220 180 IDN 2700
7 Grace 40 150 120 JPN 2600

Top 10:
1 Alice
5 Eve
3 Charlie
2 Bob
6 Frank
4 Dave
8 Heidi
7 Grace

Best Country: USA (total solved = 148)

Most Efficient: 3 Charlie (ratio = 0.277...)
```

⚡ Hint Comparator pakai tuple:

```cpp
tie(-rating, -get<0>(stat), get<1>(stat), get<2>(stat), nick)
```

<br/>

---
# 2 | Jawaban

Berikut adalah jawabanku yang sudah god tier:

```cpp
#include <algorithm>
#include <climits>
#include <iomanip>
#include <iostream>
#include <limits>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

struct Player {
    int id{};
    string nick;
    tuple<int, int, int> stats;
    string country;
    int rating{};
    float efficSubs = 0.0;
};

namespace {
auto getMostSolved(const unordered_map<string, int>& data) -> pair<string, int> {
    pair<string, int> rest{"", INT_MIN};
    for (const auto& [key, val] : data) {
        if (rest.second < val) {
            rest.second = val;
            rest.first = key;
        }
    }

    return rest;
}
}  // namespace

auto main() -> int {
    cout << "Hello kawan!\n";
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;

    cerr << "Nilai n saat ini: " << n;

    unordered_map<string, int> mostSolved;
    mostSolved.reserve(n);
    tuple<string, int, float> mEffic{"", 0, numeric_limits<float>::min()};

    vector<Player> player(n);

    for (auto& [id, nc, stats, country, rats, effic] : player) {
        cin >> id >> nc >> get<0>(stats) >> get<1>(stats) >> get<2>(stats) >> country >> rats;

        mostSolved[country] += get<0>(stats);
        effic = static_cast<float>(get<0>(stats)) / static_cast<float>(get<2>(stats));

        if (effic > get<2>(mEffic)) {
            get<2>(mEffic) = effic;
            get<1>(mEffic) = id;
            get<0>(mEffic) = nc;
        }
    }

    ranges::sort(player, [](const auto& a, const auto& b) {
        int ratA = -a.rating;
        int ratB = -b.rating;
        int solA = -get<0>(a.stats);
        int solB = -get<0>(b.stats);
        int penA = get<1>(a.stats);
        int penB = get<1>(b.stats);
        int subA = get<2>(a.stats);
        int subB = get<2>(b.stats);
        string nickA = a.nick;
        string nickB = b.nick;

        auto aKey = tie(ratA, solA, penA, subA, nickA);
        auto bKey = tie(ratB, solB, penB, subB, nickB);

        return aKey < bKey;
    });

    cout << "\nSorted Leaderboard: \n";
    for (const auto& [id, nick, stats, cnt, rats, effic] : player) {
        cout << id << " " << nick << " " << get<0>(stats) << " " << get<1>(stats) << " "
             << get<2>(stats) << " " << cnt << " " << rats << '\n';
    }

    cout << "\nTop 10:\n";
    for (int i = 0; i < min(10, n); i++) {
        cout << player[i].id << " " << player[i].nick << '\n';
    }

    auto mSolve = getMostSolved(mostSolved);
    cout << "\nBest Country: " << mSolve.first << " (total solve:  " << mSolve.second << '\n';

    cout << "Most Efficient: " << get<1>(mEffic) << " " << get<0>(mEffic)
         << " (ratio = " << setprecision(3) << fixed << get<2>(mEffic) << " ...)\n";

    return 0;
}
```

<br/>

---
# 3 | Editorial

Untuk melakukan penyortiran, dilakukan hal seperti biasa, yaitu sort custom dengan menggunakan lambda function. Tapi sebelum itu, terima inputan dan tampung pada vector struct sebagai berikut:

```cpp
struct Player {
    int id{};
    string nick;
    tuple<int, int, int> stats;
    string country;
    int rating{};
    float efficSubs = 0.0;
};
```

Lakukan penyortiran dengan cara seperti ini:

```cpp
ranges::sort(player, [](const auto& a, const auto& b) {
	int ratA = -a.rating;
	int ratB = -b.rating;
	int solA = -get<0>(a.stats);
	int solB = -get<0>(b.stats);
	int penA = get<1>(a.stats);
	int penB = get<1>(b.stats);
	int subA = get<2>(a.stats);
	int subB = get<2>(b.stats);
	string nickA = a.nick;
	string nickB = b.nick;

	auto aKey = tie(ratA, solA, penA, subA, nickA);
	auto bKey = tie(ratB, solB, penB, subB, nickB);

	return aKey < bKey;
});
```

Baiklah, mungkin akan aku jelaskan kenapa kita bisa membuat sorting custom yang terlihat lebih ringkas disini. Jika sebelumnya kita menggunakan perbandingan satu-persatu, disini kita menggunakan variabel bantu untuk mempermudah perbandingan, dengan menyatukanya nanti menggunakan fungsi `tie()`.

Nah, kenapa beberapa data yang diambil malah dijadikan negatif?

Jadi begini, amati beberapa analogi berikut:

Mana lebih besar: $10$ atau $5$, tentu jawabanya $10 > 5$, ya kan?

Nah sekarang, jika keduanya dibuat menjadi negatif, mana yang lebih besar: $-10$ atau $-5$? Kali ini jawabanya justru terbalik. Yaitu adalah $-10 < -5$.

Nah, dengan menggunakan pembalikan nilai ini, kita bisa mengatur, bagian mana yang ingin diurutkan dengan cara ascending, dan bagian mana yang ingin diurutkan dengan cara descending. Namun perhatikan juga perbandingan final berikut:

```cpp
return aKey < bKey;
```

Kita harus menggunakan tanda $<$ untuk menjadikan pembalikan nilai diatas bekerja sepenuhnya, karena satu blok kode ini merupakan satu kesatuan yang saling berhubungan.

Oke, selanjutnya, mencari negara dengan problem terpecahkan terbanyak, bisa kita lakukan dengan unordered map. Caranya mudah, kita cukup lakukan proses ini ketika proses inputan, lalu lakukan traversal terhadap semua data pada unordered map, mana yang nilainya paling besar.

Lalu, untuk pencarian effisiensi submission tertinggi, caranya adalah dengan melakukan pembagian $Solved/Submission$. Lalu cari, mana yang nilainya paling besar. Hal ini bisa dilakukan ketika proses inputan, sehingga menyingkat pekerjaan. 

