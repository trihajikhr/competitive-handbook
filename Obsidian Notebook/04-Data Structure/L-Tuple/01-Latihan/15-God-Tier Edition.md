---
obsidianUIMode: preview
note_type: latihan
latihan: God-Tier Edition
sumber:
  - chatgpt.com
tags:
  - data-structure
  - tuple
date_learned: 2025-08-29T23:18:00
---
---
# 1 | God-Tier Edition

Kamu diminta membuat sistem peringkat kompetisi internasional dengan aturan multi-layer yang ribet. Setiap peserta punya data:

* `id` (int)
* `nama` (string)
* `usia` (int)
* `soal_solved` (int)
* `penalty_total` (int)
* `fastest_submit` (int, menit)
* `negara` (string)

### Aturan Ranking (berlapis):

1. Jumlah soal solved (desc).
2. Penalty total (asc).
3. Fastest submit (asc).
4. Kategori usia (Veteran > Challenger > Rookie).

   * `< 20` = Rookie
   * `20–29` = Challenger
   * `30+` = Veteran
5. **Bonus negara**: tiap negara punya multiplier tersendiri (misalnya dari input). Ranking mempertimbangkan `soal_solved * multiplier`.

   * Contoh: `USA=1.1`, `JPN=0.9`, `GER=1.3`
   * Jadi solved efektif = `soal_solved * multiplier`.
1. Negara (asc lexicographically).
2. ID (asc).

### Input Format

```
N M
<N data peserta...>  (N baris)
<M data negara multiplier...> (M baris)
```

* `N` = jumlah peserta.
* `M` = jumlah negara berbeda.
* Peserta: `id nama usia soal_solved penalty fastest_submit negara`
* Negara multiplier: `kode negara multiplier (float)`
### Output Format

Cetak leaderboard final:

```
rank id nama usia(kategori) soal_solved penalty fastest_submit negara skor_efektif
```
### Contoh Input

```
6 3
1 Alice 19 5 600 30 USA
2 Bob 21 5 600 30 CAN
3 Charlie 32 5 600 30 USA
4 Diana 28 4 500 20 JPN
5 Eve 21 5 600 20 GER
6 Frank 35 5 600 30 FRA
USA 1.1
GER 1.3
JPN 0.9
```

### Proses Perhitungan

* Alice: solved 5 × 1.1 = 5.5
* Bob: solved 5 × 1.0 = 5
* Charlie: 5 × 1.1 = 5.5
* Diana: 4 × 0.9 = 3.6
* Eve: 5 × 1.3 = 6.5
* Frank: 5 × 1.0 = 5

### Output Leaderboard

```
1 Eve 21(Challenger) 5 600 20 GER 6.5
2 Alice 19(Rookie) 5 600 30 USA 5.5
3 Charlie 32(Veteran) 5 600 30 USA 5.5
4 Frank 35(Veteran) 5 600 30 FRA 5.0
5 Bob 21(Challenger) 5 600 30 CAN 5.0
6 Diana 28(Challenger) 4 500 20 JPN 3.6
```

🔥 Jadi sortingnya udah multi-key + transformasi data (multiplier negara) + kategori usia + final fallback ID. Kamu wajib pake struct, tuple, dan custom comparator biar bisa kelar.

<br/>

---
# 2 | Jawaban

Berikut adalah jawaban dari tantangan ini:

```cpp
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

struct Coder {
    int id{};
    string name;
    int age{};
    tuple<int, int, int> stats;
    string country;
    int category{};
    float mulpVal = NAN;

    string catCall;
};

namespace {
// clang-format off
void outputData(const vector<Coder>& coder){
     int idx = 1;
    cout << left;

    cout << setw(6)  << "Rank"
     << setw(6)  << "ID"
     << setw(12) << "Name"
     << setw(15) << "Age(Category)"
     << setw(8)  << "Solved"
     << setw(10) << "Penalty"
     << setw(10) << "Fastest"
     << setw(10) << "Country"
     << setw(10) << "Score" << "\n";

cout << string(80, '-') << "\n"; // garis pemisah
for (const auto& x : coder) {
    cout << setw(6)  << idx++
         << setw(6)  << x.id
         << setw(12) << x.name
         << setw(15) << (to_string(x.age) + "(" + x.catCall + ")")
         << setw(8)  << get<0>(x.stats)
         << setw(10) << get<1>(x.stats)
         << setw(10) << get<2>(x.stats)
         << setw(10) << x.country
         << setw(10) << fixed << setprecision(2) << x.mulpVal
         << "\n";
}
}
//clang-format on
}

auto main() -> int {
    cout << "Hello Kaw\n";
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    int m = 0;
    cin >> n >> m;

    vector<Coder> coder(n);
    unordered_map<string, float> mulp;
    mulp.reserve(m);

    for (auto& [id, nm, age, stat, cnt, cat, valMulp, caCall] : coder) {
        cin >> id >> nm >> age >> get<0>(stat) >> get<1>(stat) 
        >> get<2>(stat) >> cnt;

        if (age >= 30) {
            cat = 3;
        } else if (age > 20 && age < 30) {
            cat = 2;
        } else if (age < 20) {
            cat = 1;
        }

        if (cat == 1) {
            caCall = "Rookie";
        } else if (cat == 2) {
            caCall = "Challanger";
        } else if (cat == 3) {
            caCall = "Veteran";
        }
    }

    for (int i = 0; i < m; i++) {
        string cnt;
        float a = NAN;
        cin >> cnt >> a;
        mulp[cnt] = a;
    }

    for (auto& x : coder) {
        x.mulpVal = static_cast<float>(get<0>(x.stats)) * mulp[x.country];
    }

    ranges::sort(coder, [](const auto& a, const auto& b) {
        int solvedA = -get<0>(a.stats);
        int solvedB = -get<0>(b.stats);

        int penalA = get<1>(a.stats);
        int penalB = get<1>(b.stats);

        int fastA = get<2>(a.stats);
        int fastB = get<2>(b.stats);

        int ageA = -a.age;
        int ageB = -b.age;

        float plierA = -a.mulpVal;
        float plierB = -b.mulpVal;

        string cntA = a.country;
        string cntB = b.country;

        int idA = a.id;
        int idB = b.id;

        auto aKey = tie(solvedA, penalA, fastA, ageA, plierA, cntA, idA);
        auto bKey = tie(solvedB, penalB, fastB, ageB, plierB, cntB, idB);

        return aKey < bKey;
    });

    int idx = 1;
    cout << "LeaderBoard:\n";
    outputData(coder);

    return 0;
}
```

<br/>

---
# 3 | Editorial

Ini hanya soal untuk bersenang-senang, dan juga soalnya tidak jauh berbeda dengan soal sebelumnya, sehingga aku tidak akan membuat editorial lengkap tentang problem ini. Cukup sama algoritma sortingnya dengan soal-soal sebelumnya.