---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1985E
judul_DEATH: Secret Box
teori_DEATH: mencari sisi-sisi untuk balok dengan volume k
sumber:
  - codeforces.com
rating: 1200
ada_tips: true
date_learned: 2025-10-25T12:05:00
tags:
  - brute-force
  - combinatorics
  - math
---
Sumber: [Problem - 1985E - Codeforces](https://codeforces.com/problemset/problem/1985/E)

```ad-tip
title:⚔️ Teori Death Ground
Untuk mendapatkan sisi-sisi yang mungkin dari suatu balok $S$ dengan volume $k$, rumus berikut bisa diikuti:

Untuk mencari nilai $a$ dan $b$, cukup mencari nilai yang bisa membagi habis $k$. Ini karena $k$ didapat dari $a \times b \times c = k$, sehingga sudah pasti bahwa $a,b,c \mid k$, maka:

$$\frac{k}{a} =b \; \text{ dan } \; k \text{ mod } a \equiv 0$$

Lalu, ketika sudah mendapatkan nilai $a$ dan $b$, maka nilai $c$ bisa didapat dengan cara berikut;

$$\frac{k}{a \times b}$$
```

<br/>

---
# 1 | 1985E-Secret Box

Diberikan sebuah balok $3$ dimensi, yang mana memiliki panjang sisi berupa $x,y,z$. Diberikan juga sebuah balok $S$, dan volumenya yaitu $k$.

Tugasmu adalah menentukan, banyak cara maksimal untuk menempatkan balok $S$ dengan volume $k$ kedalam balok berukuran $x,y,z$. Balok $S$ hanya diberikan volume, artinya kamu harus menentukan sendiri panjang sisi-sisi dari balok $S$, asalkan tidak ada sisi dari balok $S$ yang keluar atau melebihi ukuran dari sisi balok $x,y,z$.


<br/>

---
# 2 | Sesi Death Ground ⚔️

Akju mencoba soal ini dan memakan waktu yang lumayan lama. Berikut adalah contoh implementasiku, walaupun tidak berhasil:

```cpp
#include<iostream>
#include<numeric>
#include<array>
#include<algorithm>
using namespace std;

#define pass(x) cerr << "\nPass here: " << x << '\n'
using LL = long long;

auto isPrime(LL n) -> bool {
    if (n==1) return false;
    if (n==2 || n==3) return true;
    for (LL i=2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void solve() {
    array<LL, 3> in{};
    LL k;
    cin >> in[0] >> in[1] >> in[2] >> k;
    LL ls = accumulate(in.begin(), in.end(), 1LL, multiplies<LL>());
    if (ls < k || isPrime(k)) {
        cout << 0 << '\n';
    } else if (ls == k) {
        cout << 1 << "\n";
    } else {
        array<LL, 3> s{};
        s[0] = in[0], s[1] = in[1], s[2] = in[2];
        LL ans = 0;
        while (s[0]*s[1]*s[2] != k && min({s[0], s[1], s[2]}) != 0) {
            auto idx = max_element(s.begin(), s.end());
            *idx -= 1;
        }

        if (s[0]*s[1]*s[2] == 0) {
            cout << ans << '\n';
        } else {
            sort(in.begin(), in.end());
            sort(s.begin(), s.end());
            ans += (in[0]-s[0]+1) * (in[1]-s[1]+1) * (in[2]-s[2]+1);
            cout << ans << '\n';
        }
    }
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

Dan ini adalah implementasi kedua, yang juga salah:

```cpp
#include<iostream>
#include<numeric>
#include<array>
#include<algorithm>
using namespace std;

#define pass(x) cerr << "\nPass here: " << x << '\n'
using LL = long long;

using AL = array<LL, 3>;
void print(const AL& data) {
    for (const auto& x : data) {
        cerr << x << " ";
    }
    cerr << '\n';
}

void solve() {
    array<LL, 3> in{};
    LL k;
    cin >> in[0] >> in[1] >> in[2] >> k;
    LL ls = accumulate(in.begin(), in.end(), 1LL, multiplies<LL>());
    if (ls < k) {
        cout << 0 << '\n';
    } else if (ls == k) {
        cout << 1 << "\n";
    } else {
        array<LL, 3> s{};
        s[0] = in[0], s[1] = in[1], s[2] = in[2];
        LL ans = 0;
        bool found = false;
        for (LL a=in[0]; a > 0; a--) {
            for (LL b=in[1]; b >0 ; b--) {
                for (LL c=in[2]; c > 0; c--) {
                    if (a*b*c == k) {
                        found = true;
                        s[0] = a, s[1] = b, s[2] = c;
                        break;
                    }
                }
                if (found) break;
            }
            if (found) break;
        }

        if (!found) {
            cout << ans << '\n';
        } else {
            sort(in.begin(), in.end());
            sort(s.begin(), s.end());
            ans += (in[0]-s[0]+1) * (in[1]-s[1]+1) * (in[2]-s[2]+1);
            cout << ans << '\n';
        }
    }
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

Daftar kesalahan:

1. Pada implementasi pertama, aku berpikir bahwa ketika $k$ adalah angka prima, maka mustahil untuk memiliki sisi-sisi yang pas, karena angka prima hanya bisa dibagi habis oleh satu dan angka itu sendiri. Tapi ternyata kondisi ini masih bisa memiliki jawaban yang valid, dengan memberikan sisi-sisi berupa $1,1,k$.

2. Perhatikan kode ini:
   
	```cpp
	LL ls = accumulate(in.begin(), in.end(), 1LL, multiplies<LL>());
	```
	
	Sebelumnya aku menggunakan parameter $1$, namun ketika ingin menggunakan `long long`, seharusnya diberi keterangan tambahan, menjadi `1LL`. Akan aku tambahkan ke tips-trick.
	
2. Masalah terbesarku di problem ini, adalah aku kesulitan untuk mencari panjang sisi yang pas untuk balok $S$, yang mana ketiga sisinya tidak melebihi batasan dari $x,y,z$. Tanpa batasan ini, mudah saja menemukan panjang sisi yang bisa membangun $S$. Ingat juga bahwa karena $k$ didapat dari perkalian $a \times b \times c = k$, otomatis $a,b,c \mid k$, atau $a,b$, dan $c$ adalah pembagi dari $k$.
   
   Untuk mendapatkan panjang sisi $a$ dan $b$, kita bisa mencoba melakukan pembagian apapun, misal didapat:
   
   $$\frac{k}{a} = b \; \text{ dan } \; k \text{ mod } a \equiv 0 $$
   Maka kita bisa mendapatkan nilai $c$ dengan cara berikut:
   
   $$c = \frac{k}{a\times b}$$
   
   Sekarang kita sudah mendapatkan nilai dari $a,b$, dan $c$. 
   
   Namun, masalahnya adalah untuk setiap nilai dari $a,b$, dan $c$, tidak boleh ada satupun nilai yang melebihi nilai dari batasan $x,y,z$. Atau kondisi berikut ini harus terpenuhi:
   $$a \leq x, \; b \leq y, \; c \leq z$$
   
	Selain itu, kita diminta untuk mencari panjang sisi-sisi yang **pas**. Yaitu yang bisa memaksimalkan perbedaan penempatan di dalam balok dengan ukurang $x,y,z$. Disinilah aku buntu.

3. Implementasi pertama aku mencoba brute force, dengan cara selalu mengurai sisi terpanjang hingga perkalian antara ketiganya sama dengan $k$, yang mana menyebabkan *wrong answer*, karena menghasilkan panjang sisi yang tidak **pas**, sehingga tidak berhasil mendapatkan penempatan maksimal. Yaitu seperti ini:
   
   ```cpp
   while (s[0]*s[1]*s[2] != k && min({s[0], s[1], s[2]}) != 0) {
	auto idx = max_element(s.begin(), s.end());
	*idx -= 1;
}
   ```
   
   Aku juga sepertinya perlu belajar lagi tentang penggunaan iterator. Karena aku sempat melakukan kesalahan saat menggunakna operasi dasar ini.


4. Sedangkan pada implementasi kedua, aku mencoba membangun kombinasi dari panjang sisi $x,y,z$, hingga aku menemukan kondisi dimana $a\times b \times c = k$. Tapi sayangnya implementasi ini tidak efisien, dan untuk inputan besar, tidak mungki lolos dari *time limit exceed*.
   
   ```cpp
   for (LL a=in[0]; a > 0; a--) {
	for (LL b=in[1]; b >0 ; b--) {
		for (LL c=in[2]; c > 0; c--) {
			if (a*b*c == k) {
				found = true;
				s[0] = a, s[1] = b, s[2] = c;
				break;
			}
		}
		if (found) break;
	}
	if (found) break;
}
   ```

Hal yang sudah benar:
1. Batasan untuk input adalah $1 \leq x,y,z \leq 2000$, dan $1 \leq k \leq x \cdot y \cdot z$.  Ini artinya, nilai $k$ memiliki batasan nilai maksimal hingga $8,000,000,000$ atau $10^{10}$. Karena melebihi kemampuan tipe data `int`, maka harus digunakan tipe data `long`. Tapi aku mencoba lebih aman dengan `long long`.

2. Pencarian banyaknya penempatan sudah benar, yaitu dengan menggunakan rumus ini:
   $$(x-a+1) \times (y-b+1) \times (z-c+1)$$
<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Karena panjang sisi balok $S$ harus dikalikan menjadi $k$, maka ketiga panjang sisi $S$ harus merupakan pembagi (*divisor*) dari $k$. Mari kita notasikan panjang sisi $S$ di sepanjang sumbu $x$, $y$, dan $z$ sebagai $a$, $b$, dan $c$ secara berturut-turut.

Agar $S$ dapat termuat (*fit*) di dalam balok $B$, kondisi berikut harus dipenuhi: $a \le x$, $b \le y$, dan $c \le z$.

Karena kendala (*constraints*) yang rendah, kita dapat melakukan perulangan (*loop*) melalui semua nilai $a$ dan $b$ yang mungkin, dan menyimpulkan bahwa $c = \frac{k}{a \cdot b}$ (pastikan $c \le z$ dan $c$ adalah bilangan integer).

Untuk mendapatkan jumlah cara kita dapat menempatkan $S$, kita hanya perlu mengalikan jumlah ruang pergeseran (*shifting space*) di sepanjang setiap sumbu, yang dapat dirumuskan menjadi:

$$(x - a + 1) \cdot (y - b + 1) \cdot (z - c + 1)$$

Jawabannya adalah nilai maksimum dari semua nilai $a$, $b$, dan $c$ yang mungkin.

Kompleksitas waktu (*Time complexity*) dari solusi ini adalah $O(n^2)$, di mana $n$ paling banyak adalah $2000$.

Kode editorial:

```cpp
#include <iostream>
using namespace std;
using ll = long long;

int main(){
	int t; cin >> t;
	while(t--){
		ll x, y, z, k; cin >> x >> y >> z >> k;
		ll ans = 0;
		for(int a = 1; a <= x; a++){
			for(int b = 1; b <= y; b++){
				if(k % (a * b)) continue;
				ll c = k / (a * b);
				if(c > z) continue;
				ll ways = (ll)(x - a + 1) * (y - b + 1) * (z - c + 1);
				ans = max(ans, ways);
			}
		}
		cout << ans << "\n";
	}
}
```

## 3.2 | Analisis Pribadi

Oke, melihat dari petunjuk editorial, ternyata solusinya lebih efisien jika untuk menangani batasan dari $x,y,z$, cukup mencari nilai $c$ yang didapat dari $\frac{k}{a \cdot b}$, yang memenuhi $c \leq z$. Ketika didapat nilai $k \text{ mod } (a \cdot b) \neq 0$, maka skip. Jika memenuhi, maka lakukan pemerisakaan untuk $\frac{k}{a \cdot b} \leq z$. Jika memenuhi juga, maka kita berhasil mendapatkan sisi-sisi yang bisa membangun $S$. 

Tapi, untuk memaksimalkan penempatan, dibutuhka panjang sisi-sisi yang **pas**. Artinya kita bisa mencari dan mengambil nilai maksimal dari jumlah penempatan yang mungkin, dari tiap sisi-sisi yang mungkin.

Maka berikut adalah implementasiku:

```cpp
#include<iostream>
using namespace std;

using LL = long long;
void solve() {
    LL x,y,z,k,a,b,c;
    cin >> x >> y >> z >> k;
    LL ans = 0;
    for (a=1; a <= x; a++) {
        for (b=1; b<= y; b++) {
            if (k % (a * b)) continue;
            c = k / (a*b);
            if (c > z) continue;
            ans = max(ans, (x-a+1)*(y-b+1)*(z-c+1));
        }
    }
    cout << ans << '\n';
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
## 3.3 | Analisis Jawaban User Lain

Solusi dari editorial sudah merupakan solusi yang efisien, jadi tidak aneh jika kebanyakan jawaban orang lain juga tidak jauh berbeda:

### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x, y, z, k, p, m = 0;
        cin >> x >> y >> z >> k;
        for (long long i = 1; i <= x; i++) {
            for (long long j = 1; j <= y; j++) {
                p = k / (i * j);
                if (p * i * j == k && p <= z) {
                    m = max(m, (x - i + 1) * (y - j + 1) * (z - p + 1));
                }
            }
        }
        cout << m << "\n";
    }
}
```
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll x, y, z, a, maxx = 0;
        ll k;
        cin >> x >> y >> z >> k;
        for (ll i = 1; i <= x; i++) {
            for (ll j = 1; j <= y; j++) {
                if (k % (i * j) == 0 && k / (i * j) <= z) {
                    a = k / (i * j);
                    maxx = max(maxx, (x - i + 1)*(y - j + 1)*(z - a + 1));
                }
            }
        }
        cout << maxx << endl;
    }
}
```
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

long long solve() {
    ll x, y, z, k;
    cin >> x >> y >> z >> k;
    ll ans = 0;
    for (ll i = 1; i <= x; i++) {
        if (k % i) continue;
        for (ll j = 1; j <= y; j++) {
            if ((k / i) % j) continue;
            ll l = (k / i) / j;
            if (l <= z) {
                ans = max(ans, (x - i + 1) * (y - j + 1) * (z - l + 1));
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
```