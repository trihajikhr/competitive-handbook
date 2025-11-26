---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1343C
judul_DEATH: Alternating Subsequence
teori_DEATH: teori negatif dan positif dasar
sumber:
  - codeforces.com
rating: 1200
ada_tips?: true
date_learned: 2025-10-18T17:16:00
tags:
  - dynamic-programming
  - greedy
  - two-pointers
---
Sumber: [Problem - 1343C - Codeforces](https://codeforces.com/problemset/problem/1343/C)

```ad-tip
title:⚔️ Teori Death Ground
- $negatif \times negatif = positif$
- $positif \times positif = positif$
- $negatif \times positif = negatif$
```

<br/>

---
# 1 | 1343C-Alternating Subsequence

Aku diminta, untuk array berukuran $n$ yang diberikan yang terdiri dari $a_i$ yang positif dan juga negatif ($-10^9 \leq a_i \leq 10^9, a_i \neq 0$), mencari jumlah maksimum yang bisa ditemukan, dengan cara mengambil elemen secara selang-seling.

- positif-negatif-positif dst, atau
- negatif-positif-negatif dst

Nilai maksimal didapat, dengan cara memaksimalkan banyaknya elemen yang dimasukan kedalam daftar (elemen selang-seling harus sebanyak mungkin, baru dihitung nilai maksimalnya).



<br/>

---
# 2 | Sesi Death Ground ⚔️

Pertama, ketahui dulu bahwa kita harus memasukan sebanyak mungkin elemen selang-seling sebagai syarat utama, karena kita juga harus mencari panjang semaksimal mungkin. 

Lalu, untuk urusan mencari nilai maksimal dari elemen-elemen yang baru saja dipilih, artinya kita harus melakukan hal berikut ketika memilih elemen.

- Untuk segment elemen negatif, cari nilai maksimalnya. Jika segment negatif mencapai ujung, atau berganti ke elemen positif, tambahkan nilai maksimal yang sudah didapat ke dalam daftar.
- Untuk segment elemen positif, lakukan hal yang sama.

Kita tidak tahu apakah elemen pertama diawali denagn positif atau negatif, sehingga aku menambahkan kondisional, supaya menangani elemen pertama yang tidak bisa dibandingkan, lihat saja maksud ku di kode implementasiku.

Berikut adalah implementasiku:

```cpp
#include<iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    long long ans = 0, x, maks = LLONG_MIN, mins = LLONG_MIN;
    bool plus = true;
    for (int i=0; i<n; i++) {
        cin >> x;
        plus = x > 0;
        if (plus) {
            if (mins != LLONG_MIN) {
                ans += mins;
                mins = LLONG_MIN;
            }
            maks = max(maks, x);
        } else {
            if (maks != LLONG_MIN) {
                ans += maks;
                maks = LLONG_MIN;
            }
            mins = max(mins, x);
        }
    }
    ans += plus ? maks : mins;
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

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Pertama, mari kita ekstrak segmen-segmen inklusi maksimum (terpanjang) dari *array* yang terdiri dari angka-angka dengan tanda yang sama.

Sebagai contoh, jika *array* tersebut adalah $[1, 1, 2, -1, -5, 2, 1, -3]$, maka segmen-segmen ini adalah $[1, 1, 2]$, $[-1, -5]$, $[2, 1]$, dan $[-3]$. Kita dapat melakukan ini dengan algoritma yang menyerupai "dua *pointer*" (*two pointers*-like algorithm).

Jumlah dari segmen-segmen ini adalah panjang maksimum yang mungkin dari subsekuens bergantian (*alternating subsequence*), karena kita hanya dapat mengambil satu elemen dari setiap blok. an karena kita ingin memaksimalkan jumlah (*maximize the sum*), kita perlu mengambil elemen maksimum dari setiap blok.

Kompleksitas waktu: $\mathcal{O}(n)$.

Implementasi Editorial:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	auto sgn = [&](int x) {
		if (x > 0) return 1;
		else return -1;
	};

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &it : a) cin >> it;
		long long sum = 0;
		for (int i = 0; i < n; ++i) {
			int cur = a[i];
			int j = i;
			while (j < n && sgn(a[i]) == sgn(a[j])) {
				cur = max(cur, a[j]);
				++j;
			}
			sum += cur;
			i = j - 1;
		}
		cout << sum << endl;
	}
	
	return 0;
}
```

## 3.2 | Analisis Pribadi

Ide dan konsep editorial sama denganku, namun implementasiku dan implementasi editorial sedikit berbeda. Tapi tetap sama-sama efisien, yaitu $O(n)$. Baiklah, valid!
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include<iostream>
using namespace std;

int main() {
    long long a, n, sum, b, c;
    cin >> a;
    while (a--) {
        cin >> n;
        sum = 0;
        cin >> b;
        n--;
        while (n--) {
            cin >> c;
            if (b * c > 0) {
                if (c > b) b = c;
            } else {
                sum += b;
                b = c;
            }
        }
        cout << sum + b << endl;
    }
}
```

Wow, trik yang lumayan clever! Ketika kedua nilai sama-sama positif atau negatif, ketika dikaliakan maka hasilnya pasti $>0$. Sedangkan jika berpindah segment, maka nilai maksimal dari segment sebelumnya disimpan. Kode ini menggunakan hanya sedikit variabel, dan benar-benar menggunakan konsep matematika dasar dengan sangat baik
### 2 | Jawaban Kedua

```cpp
#include <iostream>

using namespace std;
int main() {
    long long int t, a, m, n, x, sum;
    cin >> t;
    while (t--) {
        cin >> m >> n;
        x = n;
        sum = 0;
        m--;
        while (m--) {
            cin >> a;
            if (a * n < 0) {
                sum += x;
                x = a;
            } else {
                x = (x > a) ? x : a;
            }
            n = a;
        }
        cout << sum + x << endl;
    }
}
```

Konsepnya hampir sama, tidak jauh berbeda dengan kode sebelumnya.
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define int long long
const int N = 1e5 + 10, mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0;
    int tmp = -1e9;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0, j = 0; i < n;) {
        j = i;
        tmp = a[j];
        while (j + 1 < n && a[j] * a[j + 1] > 0)
            tmp = max(tmp, a[j + 1]), j++;
        i = j + 1;
        ans += tmp;
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
```

Menggunakan dua perulangan, namun variabel $j$ digunakan untuk maju dengan menggunakan perulangan while, mencari nilai maksimal dalam satu blok segment. Ketika nilai $j+1 >= n$ atau $a[j] \cdot a[j+1] < 0$, maka artinya index $j$ telah mencapai batas array, atau mencapai blok segment yang berbeda (*ditandai $negatif \times positif = negatif$*). Ketika hal ini terjadi, sebelum memulai pencarian di blok segment disebelahnya, simpan nilai maksimal dari segment yang baru saja ditraversal dengan menggunakan perulangan `while`.

Setelah itu, majukan perulangan bagian luar dengan $i = j+1$.

Konsep pencarian nilai maksimal antar segment mudah dilihat dan dipahami disini, karena memang ide untuk mendekati solusi dari masalah ini memang demikian.