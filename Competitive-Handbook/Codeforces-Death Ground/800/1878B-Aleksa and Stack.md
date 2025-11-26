---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1878B
judul_DEATH: Aleksa and Stack
teori_DEATH:
sumber:
  - codeforces.com
rating: 800
ada_tips: false
date_learned: 2025-10-23T19:40:00
tags:
  - constructive-algorithms
  - math
---
Sumber: [Problem - 1878B - Codeforces](https://codeforces.com/problemset/problem/1878/B)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1878B-Aleksa and Stack

Kita diminta untuk membangun sebuah array berukuran $n$, yang mana untuk setiap elemen yang terbentuk, harus memenuhi syarat berikut:

- $3 \cdot a_{i+2} \mod a_i + a_{i+1} \neq 0$. Atau elemen ketiga dari posisi indeks sekarang, tidak habis dibagi oleh penjumalah 2 buah elemen sebelumnya.
- Array harus menaik, dimana untuk setiap $a_i < a_{i+1}$.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Solusinya mudah, kita hanya perlu menggunakan sedikit intuisi bahwa ketika digunakan deret ganjil yang dimulai dari $1,3,5,7 \dots, a_n$, dan seterusnya, maka susunan tersebut akan memenuhi kedua syarat tersebut.

Berikut adalah implementasinya:

```cpp
#include<iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int curr = 1;
    for (int i=0; i<n; i++) {
        cout << curr << " ";
        curr+=2;
    }
    cout << "\n";
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

Ada banyak solusi untuk masalah ini, tetapi solusi yang dimaksud adalah sebagai berikut:

Dengan memilih $n$ bilangan bulat positif ganjil pertama, yaitu $1, 3, 5, \dots, 2n-1$, kita menemukan bahwa $3 \cdot a_{i+2}$ juga merupakan bilangan ganjil, sedangkan bilangan $a_i + a_{i+1}$ adalah bilangan genap, dan bilangan ganjil tidak pernah bisa dibagi habis oleh bilangan genap, jadi konstruksi ini benar.

Kompleksitas waktu: $O(n)$

Berikut adalah implementasi editorial:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; 
	cin >> t;
	while(t--){
		int n; 
		cin >> n;
		for(int i=0; i< n; i++)cout << i*2+1 << " "; 
		cout << '\n';
	}
}
```
## 3.2 | Analisis Pribadi

Ketika dua buah bilangan ganjil ditambahkan, maka akan menghasilkan angka genap. Dan angka ganjil mustahil bisa dibagi habis oleh angka genap.

Well, penjelasan yang masuk akal untuk ide dan konsep dari editorial.
## 3.3 | Analisis Jawaban User Lain

Ide dan konsep dari editorial sudah benar dan paling efisien, jawaban lain tidak jauh berbeda:

### 1 | Jawaban Pertama

```cpp
#include<iostream>
using namespace std;

int n, t;
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << i * 2 + 1 << " ";
        }
        cout << "\n";
    }
}
```
### 2 | Jawaban Kedua

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cout << i * 2 + 1 << ' ';
        cout << '\n';
    }
}
```
### 3 | Jawaban Ketiga

```cpp
#include<bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
	   std::cout << 2 * i + 1 << " ";
	}

	std::cout << std::endl;
	
	return;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while(t--) {
		solve();
	}

	return 0;
}
```