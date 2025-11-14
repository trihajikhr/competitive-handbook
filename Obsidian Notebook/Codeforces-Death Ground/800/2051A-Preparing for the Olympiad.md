---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 2051A
judul_DEATH: Preparing for the Olympiad
teori_DEATH:
sumber:
  - codeforces.com
rating: 800
ada_tips: false
date_learned: 2025-10-23T22:19:00
tags:
  - greedy
---
Sumber: [Problem - 2051A - Codeforces](https://codeforces.com/problemset/problem/2051/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 2051A-Preparing for the Olympiad

Diberikan $2$ buah array yang sama-sama berukuran $n$. Array pertama berisi daftar banyak latihan soal Monocarp sebanyak $a_i$ tiap harinya, dan array kedua berisi daftar banyak latihan soal Stereocarp sebanyak $b_i$ setiap harinya. 

Monocarp bisa berlatih kapan saja, namun setiap ia berlatih di hari ke $i$ dan menyelesaikan $a_i$ soal, maka Stereocarp akan berlatih di hari $i+1$ dan menyelesaikan $b_{i+1}$ soal. Tugasmu adalah membuat selisih sebesar mungkin untuk Monocarp, dimana ia berlatih lebih banyak soal daripada Stereo.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Ada dua kondisi yang tepat untuk Monocarp memilih hari latihanya, yaitu ketika $a_i > b_{i+1}$, dan juga ketika $i=n$. Hal itu akan memperbesar selisih jumlah latihan soalnya. Sangat sederhana:

$$ans \; +=
\begin{cases} 
a[i] > b[i+1] &\text{maka } a[i]-b[i+1] \\ 
i \equiv n &\text{maka } a[i]
\end{cases}$$

Berikut adalah implementasiku:

```cpp
#include<iostream>
#include<vector>
using namespace std;

void solve() {
    int n, ans = 0;
    cin >> n;
    vector<int> A(n), B(n);
    for (auto& x : A) cin >> x;
    for (auto& x : B) cin >> x;
    for (int i=0; i<n; i++) {
        if (i==n-1) {
            ans += A[i];
        }  else if (A[i] > B[i+1]) {
            ans += A[i] - B[i+1];
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

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Mari kita pertimbangkan kontribusi apa yang diberikan oleh setiap hari Monokarp berlatih terhadap perbedaan (*difference*). Untuk setiap hari, kecuali hari terakhir, jika Monokarp berlatih pada hari itu, maka jumlah soal yang ia pecahkan akan meningkat sebesar $a_i$, dan jumlah soal yang dipecahkan oleh Stereokarp akan meningkat sebesar $b_{i+1}$. Oleh karena itu, jika $a_i - b_{i+1} > 0$, akan **menguntungkan** (*beneficial*) bagi Monokarp untuk berlatih pada hari ke-$i$; jika tidak, hal itu tidak menguntungkan.

Pada hari terakhir, berlatih akan **selalu menguntungkan**, karena Stereokarp tidak akan memecahkan soal apa pun pada hari berikutnya.

Kode editorial:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    int ans = a[n - 1];
    for (int i = 0; i < n - 1; ++i)
      ans += max(0, a[i] - b[i + 1]);
    cout << ans << '\n';
  }
}
```
## 3.2 | Analisis Pribadi

Pendekatanku sudah benar dan sesuai dengan ide dan konsep dari editorial, jadi menurutku sudah benar dan efisien.
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>
using namespace std;

int a[105];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 0, b; i < n; i++) cin >> b, a[n] += max(0, a[i] - b);
        cout << a[n] << '\n';
    }
}
```

Dia tidak menyimpan array kedua sama sekali, tapi langsung melakukan penghitungan ketika menerima inputan array $b$. Lumayan efisien karena tidask harus mengalokasikan penyimpanan untuk array kedua.
### 2 | Jawaban Kedua

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test = 1;
    cin >> test;

    while(test--){
        int N; cin >> N;
        vector<int> A(N),B(N);
        for(auto &a : A) cin >> a;
        for(auto &b : B) cin >> b;
        B.push_back(0);

        int answer = 0;
        for(int i=0; i<N; i++) answer += max(0,A.at(i)-B.at(i+1));
        cout << answer << "\n";
    }
}
```

Trik yang *clever*. Daripada dipusingkan dengan edge case dimana array $b$ mencapai batas lebih awal selama traversal daripada array $a$, maka buat saja array $b$ memiliki ukuran satu elemen lebih banyak dengan melakukan `push_back()` pada array $b$ dengan value $0$.
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	vector<int> a(n), b(n);
	generate(all(a), nxt);
	generate(all(b), nxt);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += max(0, a[i] - (i == n - 1 ? 0 : b[i + 1]));
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}
```

Ini adalah kode jawaban Red Coder. Walalupun implementasinya sama secara ise dan konsep, namun ada beberapa trik C++ yang lumayan keren disini. Bisa dijadikan bahan belajar kedepanya.