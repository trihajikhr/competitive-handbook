---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1624B
judul_DEATH: Make AP
teori_DEATH:
sumber:
  - codeforces.com
ada_tips?:
date_learned: 2025-10-04T13:48:00
tags:
  - math
---
Sumber: [Problem - 1624B - Codeforces](https://codeforces.com/problemset/problem/1624/B)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1624B-Make AP

Diberikan 3 angka yaitu $a,b,c$. Aku diminta untuk membuat 3 angka tersebut, menjadi arithmetic progression.

```ad-info
Barisan Aritmatika / Arithmetic Progression (AP)

**Definisi:** Urutan bilangan di mana selisih antara setiap suku berurutan adalah **konstan** (tetap). Selisih konstan ini disebut **beda umum ($d$)**.


1.  **Suku ke-$n$ ($U_n$):**
    $$U_n = a + (n-1)d$$

2.  **Jumlah $n$ Suku Pertama ($S_n$):**
    $$S_n = \frac{n}{2}(a + U_n) \quad \text{atau} \quad S_n = \frac{n}{2}(2a + (n-1)d)$$

* $a$: Suku pertama.
* $d$: Beda umum.
* $n$: Posisi/jumlah suku.

**Contoh Barisan:** $3, 7, 11, 15, \dots$ ($a=3$, $d=4$)
```

Tantanganya adalah, aku harus memilih salah satu dari angka yang diberikan, dan mengalikanya dengan angka tertentu untuk menjadikanya barisan aritmatika. Disini urutan angka tidak boleh diacak. 

Selama trial of ten, aku berpikir bahwa hanya angka terbesar dan terkecil dalam inputan yang diberikan yang perlu kita perhatikan. Tapi aku masih tidak menemukan solusi yang tepat untuk menentukan jawaban yang pasti.
<br/>

---
# 2 | Sesi Death Ground ⚔️

Ternyata dugaanku masih salah, ternyata harus dilakukan pemeriksaan terhadap ketiga angka yang diberikan.

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Mari kita ulangi (*iterate*) pada bilangan yang ingin kita kalikan dengan $m$.

Bagaimana kita bisa memeriksa bahwa kita dapat mengalikan bilangan saat ini sehingga terbentuk Barisan Aritmetika (AP)?

Perhatikan bahwa dua bilangan yang tidak kita sentuh harus membentuk Barisan Aritmetika sendiri. Misalnya, pada operasi saat ini, kita ingin mengalikan bilangan $c$. Maka, **$a = x_1$** dan **$b = x_2 = x_1 + d$**.

Perhatikan bahwa **$b - a = (x_1 + d) - x_1 = d$**. Dengan demikian, kita tahu berapa nilai $d$. Kita juga tahu bahwa **$c = x_1 + 2 \cdot d = a + 2 \cdot d$**. Mari kita periksa apakah $a + 2 \cdot d$ habis dibagi oleh $c$. Jika ya, maka kita telah menemukan jawabannya; jika tidak, maka lanjutkan ke bilangan berikutnya.

$$\text{Periksa apakah } \frac{a + 2d}{c} \text{ adalah bilangan bulat.}$$

Kita melakukan hal yang sama untuk $a$ dan $b$.

Berhati-hatilah dengan bilangan non-positif, pembagian bilangan bulat (*integer divisions*), dan kasus-kasus batas (*edge cases*) lainnya.

Berikut adalah implementasinya:

```cpp
#include<bits/stdc++.h>
using namespace std;

void solveTest() {
    int a, b, c;
    cin >> a >> b >> c;

    int new_a = b - (c - b);
    if(new_a >= a && new_a % a == 0 && new_a != 0) {
        cout << "YES\n";
        return;
    }

    int new_b = a + (c - a)/2;
    if(new_b >= b && (c-a)%2 == 0 && new_b % b == 0 && new_b != 0) {
        cout << "YES\n";
        return;
    }

    int new_c = a + 2*(b - a);
    if(new_c >= c && new_c % c == 0 && new_c != 0) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tt;
    cin >> tt;
    while(tt--)
        solveTest();
    return 0;
}
```
## 3.2 | Analisis Pribadi

Jika semisal angka yang salah adalah $a$, maka kita harus cari nilai yang seharusnya dimiliki oleh $a$, dan menentukan apakah angka yang seharusnya bisa dibagi dengan angka $a$.

Disini, kita bisa menggunakan rumus: $(2 \times b-c) \%a==0$

Jika semisal angka yang salah adalah angka $b$, maka tentukan apakah angka yang seharusnya bisa dibagi habis oleh angka $b$.

Berikut rumusnya: $(a+c) \% (b \times 2)==0$

Jika semisal angka yang salah adalah $c$, maka tenttukan apakah angka yang seharusnya bisa dibagi habis oleh angka $c$.

Berikut rumusnya: $(2\times b-a)\%c==0$

Dan tentukan juga, bahwa angka yang seharusnya, bukan angka 0. Jadi disetiap kondisional, pastikan nilainya lebih dari 0!

Berikut adalah implementasiku:

```cpp
#include<iostream>
using namespace std;

void solve() {
    int a,b,c;
    cin >> a >> b >> c;

    if (
        // jika a salah
        // 1 6 9
        // 10 30 40 -> (2*b - c)
        (2*b-c)%a==0 && (2*b-c)>0 ||

        // jika b salah
        // 1 1 5
        // 20 10 40 -> (a+c)
        // 50 10 150
        ((a+c) % (b*2)==0 && (a+c)) >0 ||

        // jika c salah
        // 1 3 1
        // 10 20 10 -> (2*b -a)
        // 50 100 10
        ((2*b-a)%c==0 && (2*b-a)>0)
    ) cout << "YES\n";
    else cout << "NO\n";
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
```
## 3.3 | Analisis Jawaban User Lain

Berikut adalah jawaban dari beberapa user yang dirasa jauh lebih singkat atau efisien.

### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--) {
		int a,b,c;
		cin>>a>>b>>c;
		if((a+c)%(2*b)==0&&a+c>0 ||
			((2*b-c)%a==0&&2*b-c>0) ||
			((2*b-a)%c==0&&2*b-a>0))
			puts("YES");
		else
			puts("NO");
	}
}
```

Jauh lebih singkat, kondisional pertama digunakan untuk nilai $a$, kondisional kedua digunakan untuk memeriksa nilai $b$, dan kondisional ketiga digunakan untuk memeriksa nilai $c$. Jika ada salah satu dari kondisional tersebut yang terpenuhi atau bernilai true, maka hasilnya pasti `YES`. Tapi jika tidak, maka hasilnya pasti `NO`.

### 2 | Jawaban Kedua

```cpp
#include <bits/stdc++.h>

using namespace std;

#define cctie ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(), x.end()
#define ALL(x) x.begin() + 1, x.end()

using i64 = long long;

const int INF = 0x3f3f3f3f;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    int d = b - a;
    int C = b + d;
    if (C % c == 0 && C > 0) {
        cout << "YES\n";
        return;
    }
    
    d = c - b;
    int A = b - d;
    if (A % a == 0 && A > 0) {
        cout << "YES\n";
        return;
    }

    if ((c - a) % 2 == 0) {
        d = c - a >> 1;
        int B = c - d;
        if (B % b == 0 && B > 0) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

void prework() {

}

int main() {
    cctie;

    prework();

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
} 
```

Hampir sama dengan cara editorial, tapi alih-alih menggunakan 3 variabel tambahan, dia hanya menggunakan 1 variabel yang di *reuse* (digunakan ulang). Sepertinya lebih efisien.

### 3 | Jawaban Ketiga

```cpp
#include<bits/stdc++.h>
using i64 = long long;

void solve() {
	int a, b, c;
	std::cin >> a >> b >> c;

	if(a + c > 2 * b){
		if ((a + c) % (2 * b) == 0){
			std::cout << "YES\n";
		}else{
			std::cout << "NO\n";
		}		
	}else{
		if ((2 * b - a) % c == 0 || (2 * b - c) % a == 0){
			std::cout << "YES\n";
		}else{
			std::cout << "NO\n";
		}
	}

	return;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int t;
	std::cin >> t;

	while(t--) {
		solve();
	}

	return 0;
}
```

Kondisional pertama, yaitu:

```cpp
if(a + c > 2 * b) {}
```

Akan terpenuhi jika angka yang kurang adalah angka yang berada ditengah, atau angka $b$. Jika kondisi ini tidak terpenuhi, maka berarti angka yang harus diperbaiki, adalah angka $a$ atau $c$.

Cara ini sedikit berbeda dari editorial, namun memberiku pemahaman, bahwa kita memang harus melakukan 3 kali pengecekan.






