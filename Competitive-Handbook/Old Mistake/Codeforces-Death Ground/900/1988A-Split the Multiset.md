---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1988A
judul_DEATH: Split the Multiset
teori_DEATH:
sumber:
  - codeforces.com
rating: 900
ada_tips?:
date_learned: 2025-10-14T21:43:00
tags:
---
Sumber: [Problem - A - Codeforces](https://codeforces.com/contest/1988/problem/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1988A-Split the Multiset

Diberikans sebuah nilai $n$ dan $k$. Nilai $n$ menunjukan nilai awal yang berada didalam multiset $S$, sehingga $S = \{n\}$. Kita diharuskan membuat semua angka pada multiset $S$ semuanya menjadi bernilai $1$, dengan cara berikut:

Ganti angka tertentu pada multiset $S$, katakanlah angka $U$ dengan beberapa angka yang jika dijumlahkan hasilnya adalah $U$. Angka yang digunakan tidak melebihi $k$ kali.

Hitung berapa jumlah minimal operasi tersebut dilakukan, untuk membuat semua angka pada multiset $S$ semuanya menjadi bernilai $1$.

(*Baca soal untuk gambaran yang lebih jelas*)
<br/>

---
# 2 | Sesi Death Ground ⚔️

Intuisi awalku, adalah ketika $n=100$ dan $k=50$, kita bisa memilih nilai berikut:

$$\{50,50\} \rightarrow \{1,1,...,1, \,\,\, 50\} \rightarrow \{1,1,...,1, \;\;\; 1,1,...,1\}$$

Artinya, kita hanya membutuhkan 3 langkah.

Aku memiliki solusi awal, yaitu melakukan operasi $\frac{n}{k}$, dimana variabel $ans$ akan menyimpan hasil pembagianya, dan hasil dari pembagian tersebut akan disimpan kembali ke $n$, dan dibagi lagi dengan $k$, berulang kali hingga nilai dari $n=1$. Dan jika selama operasi tersebut, didapati $n \mod k \neq 0$, maka nilai $ans=ans+1$.

Tapi sepertinya masih ada yang salah, karena beberapa test case masih salah. Namun pendekatan ini mendekati, karena kebanyakan test case yang salah, hanya memiliki selisih satu dengan jawabanku.

Tapi tetap, hingga akhir, aku tidak bisa menjawabnya.


<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official


**Hint 1**: Urutan operasi yang optimal sangat sederhana.

Urutan operasi yang optimal adalah menambahkan $k-1$ buah `1` ke dalam *set* setiap saat, sekaligus mengurangi $n$ sebesar $k-1$. Ini menyiratkan bahwa jawabannya adalah $\left\lceil\frac{n-1}{k-1}\right\rceil$.

**Mengapa?**
Saya gagal menemukan bukti yang setingkat dengan Div2-A. Jika Anda memiliki bukti yang lebih sederhana, silakan bagikan di kolom komentar.

**Penjelasan yang Tersedia:**

1.  Pertimbangkan jumlah elemen dalam *set* yang $\equiv 1 \pmod{k-1}$. Jumlah elemen tersebut meningkat paling banyak sebesar $k-1$ dalam setiap operasi, dan urutan operasi yang disebutkan di atas mencapai peningkatan maksimum.

<br/>

2.  *Bukti yang lebih sederhana di komentar:* Pertimbangkan jumlah elemen dalam *set*. Jumlahnya meningkat paling banyak sebesar $k-1$ setiap saat, dan konstruksi kita mencapai peningkatan maksimum.

Implementasi editorial (python):

```py
t = (int)(input())
for _ in range(t):
    n, k = map(int, input().split())
    print((n - 1 + k - 2) // (k - 1))
```

## 3.2 | Analisis Pribadi

Menggunakan penjelasan dari editorial, jawabanya adalah dengan menerapkan rumus berikut:
$$\left\lceil\frac{n-1}{k-1}\right\rceil$$

Berikut implementasinya:

```cpp
#include<iostream>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    cout << (n-1+k-2)/(k-1) << '\n';
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
```

*Aku menggunakan trick pembulatan keatas! Kamu harusnya tahu rumus diatas jika paham maksudku!*
## 3.3 | Analisis Jawaban User Lain

Rumus dari editorial adalah jawaban yang paling efisien, kompleksitas $O(1)$, sehingga jawaban lainya, tidak terlalu jauh berbeda:

### 1 | Jawaban Pertama

```cpp
#include <stdio.h>
int main()
{
	int a,b,c;
	scanf("%d",&a);
	while(a--)
	{
		scanf("%d%d",&b,&c);
		printf("%d\n",(b-3+c)/(c-1));
	}
}
```
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,m;
    cin>>t;
    while(t--&&cin>>n>>m) cout<<((n+m-3)/(m-1))<<"\n";
}
```
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
constexpr int MAXN = 1e6 + 7;
constexpr int INF = 2e9;
constexpr ll INFF = 1e18;
constexpr ll MOD = 998244353;
#define mkp make_pair
#define F first
#define S second
#define pb emplace_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    cout << (n - 1 + (k - 1) - 1) / (k - 1) << '\n';
  }
}
```

Jawaban *Red Coder*.