---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1618A
judul_DEATH: Polycarp and Sums of Subsequences
teori_DEATH:
sumber:
  - codeforces.com
rating: 800
ada_tips: false
date_learned: 2025-10-23T22:47:00
tags:
  - math
  - sorting
---
Sumber: [Problem - 1618A - Codeforces](https://codeforces.com/problemset/problem/1618/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1618A-Polycarp and Sums of Subsequences

Polycarp awalnya memiliki array berukuran $3$, namun kemudian dia merubah array tersebut menjad array berukuran $7$ dengan cara melakukan operasi berikut:

Semisal dia memiliki array $\{1,4,3\}$, maka dia akan menulisnya dengan $1,4,3,1+4,1+3,4+3,1+4+3$, lalu disorting menjadi $1,3,4,4,5,7,8$.

Sayangnya Polycarp lupa dengan array asli ketika dia merubah array tersebut. Tugasmu adalah merubah array yang sudah di operasikan, menjadi array semula, yang masih berukuran $3$. 

<br/>

---
# 2 | Sesi Death Ground ⚔️

Solusinya mudah, karena array yang diberikan adalah array yang dalam kondisi terurut (*ascending, merupakan petunjuk soal*), maka kita hanya perlu menggunakan intuisi saja. Dimana $2$ elemen terkecil, pasti adalah nilai dari elemen pertama dan kedua array asli.

Sedangkan nilai asli dari elemen ketiga, bisa didapatkan dengan mengambil nilai maksimal dari array input, lalu kurangi dengan jumlah elemen pertama dan elemen kedua array input. Hal ini karena elemen terbesar dari array input pastilah jumlah dari $3$ elemen array asli. Jika kita sudah mendapatkan $2$ array asli, maka untuk mendapatkan array ketiga cukup dengan melakukan operasi ini. 

Berikut adalah implementasiku:

```cpp
#include<iostream>
#include<array>
using namespace std;

void solve() {
    array<int, 7> d{};
    for (auto& x : d) {
        cin >> x;
    }

    cout << d[0] << " " << d[1] << " "
         << d[6]-d[1]-d[0] << '\n';
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Urutan elemen dalam $a$ tidak menjadi masalah. Jika setidaknya ada satu larik (*array*) $a$ yang benar, maka kita dapat mengurutkannya dan mendapatkan jawaban di mana $a_1 \leq a_2 \leq a_3$. Oleh karena itu, kita selalu dapat menemukan larik yang terurut (*sorted array*).

Misalkan $a_1 \leq a_2 \leq a_3$. Maka $b_1 = a_1$, $b_2 = a_2$, dan $b_7 = a_1 + a_2 + a_3$. Kita dapat menemukan $a_3$ sebagai $b_7 - a_1 - a_2$.

Implementasi editorial:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        vector <int> b(7);
        for(int i = 0; i < 7; i++)
            cin >> b[i];
        cout << b[0] << ' ' << b[1] << ' ' << b[6] - b[0] - b[1] << endl;
    }
}
```
## 3.2 | Analisis Pribadi

Ide dan konsepku sudah sama dengan editorial, jadi sudah jelas benar dan sama-sama efisien.
## 3.3 | Analisis Jawaban User Lain

Penjelasan ide dan konsep dari editorial sudah merupakan yang paling efisien. Jawaban dari pengguna lain tidak jauh berbeda dengan ide dan konssep ini:

### 1 | Jawaban Pertama

```cpp
#include<iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p, b, c, d;
        cin >> p >> b >> c >> d >> d >> d >> d;
        cout << p << ' ' << b << ' ' << d - p - b << endl;
    }
}
```
### 2 | Jawaban Kedua

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int a[7];
		for(int &x : a) cin >> x;
		sort(a, a + 7);
		cout << a[0] << " " << a[1] << " " << a[6] - a[0] - a[1] << endl;
	}
	return 0;
}
```
### 3 | Jawaban Ketiga

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>

#define ll long long

using namespace std;
ll n, m;
ll a[10];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        for (int i = 1; i <= 7; i++) {
            cin >> a[i];
        }
        for (int i = 3; i <= 7; i++)
            if (a[1] + a[2] + a[i] == a[7]) {
                cout << a[1] << " " << a[2] << " " << a[i] << "\n";
                break;
            }

    }
}
```