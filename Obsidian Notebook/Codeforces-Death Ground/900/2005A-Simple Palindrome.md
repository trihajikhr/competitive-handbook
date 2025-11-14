---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 2005A
judul_DEATH: Simple Palindrome
teori_DEATH:
sumber:
  - codeforces.com
rating: 900
ada_tips?:
date_learned: 2025-10-15T16:24:00
tags:
---
Sumber: [Problem - 2005A - Codeforces](https://codeforces.com/problemset/problem/2005/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 2005A-Simple Palindrome

(*Soalnya lumayan sulit untuk dimengerti, jadi jika ringkasan ku ini kurang jelas, lihat saja langsung ke problem statementnya*)

Diberikan panjang $N$ untuk string, tugasmu adalah menyusun sebuah string sepanjang $N$ yang hanya terdiri dari huruf vokal ($a, e, i, o, u$).

Tujuan dari konstruksi string ini adalah untuk meminimalkan jumlah total subsequence yang bersifat palindrome di dalamnya.

(Catatan: Sebuah palindrome adalah string yang dibaca sama dari depan dan belakang; sebuah subsequence adalah string yang dibentuk dari string asli dengan menghapus nol atau lebih karakter tanpa mengubah urutan sisanya.)

<br/>

---
# 2 | Sesi Death Ground ⚔️

Untuk membuat substring palindrome sesedikit mungkin, aku memiliki intuisi bahwa karakter-karakter yang sama harus berada berdampingan didalam string, seandainya panjang string adalah lebih dari $5$. Jika panjang string atau $n$ adalah $n \leq 5$, maka kita cukup tampilkan karakter huruf vokal satu-persatu secara bergantian.

Misal, nilai $n$ atau panjang string adalah $10$, maka kita bisa menyusun string seperti ini:
$$aaiiuueeoo$$

Mudah menentukan banyaknya karakter yang harus dimunculkan jika $n$ bisa dibagi $5$. Tapi jika tidak, maka kita bisa menggunakan perulangan tambahan, yang berjalan sebanyak $n \; \% \;5$. Mekanismenya sulit dijelaskan disini, sehingga lebih baik lihat implementasiku berikut:

```cpp
#include<iostream>
#include<array>
#include<unordered_map>
using namespace std;

array<char, 5> vow = {'a', 'e', 'i', 'o', 'u'};
void solve() {
    int n;
    cin >> n;
    unordered_map<char, int> dasmap;
    dasmap.reserve(5);
    for (int i=0; i<5; i++) {
        dasmap[vow[i]] += n/5;
    }

    for (int i=0; i<n%5; i++) {
        dasmap[vow[i]]++;
    }

    for (const auto& [key, val] : dasmap) {
        for (int i=0; i<val; i++) {
            cout << key;
        }
    }
    cout << '\n';
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

**Hint 1**: Jika jumlah setiap huruf vokal telah ditetapkan, bagaimana cara mengaturnya agar mendapatkan jawaban terbaik?

**Hint 2**: Bagaimana cara memilih jumlah masing-masing huruf vokal? Haruskah jumlahnya sedekat mungkin?

**Solusi**:

Mari kita definisikan jumlah kemunculan huruf vokal sebagai $a_0, \dots, a_4$ dan asumsikan kita telah menetapkannya. Tentu saja, $a_0 + \cdots + a_4 = n$.

Pertama, mari kita tidak mempertimbangkan *string* kosong karena ia tidak mengubah apa pun (terkait minimasi). Maka, jumlah *subsequence* *palindrome* setidaknya adalah $A = 2^{a_0} + \cdots + 2^{a_4} - 5$ (setiap *subsequence* yang terdiri dari huruf yang sama, dikurangi lima *subsequence* *string* kosong). Perhatikan bahwa jika kita meletakkan karakter yang sama secara berurutan (*consecutively*), maka jawabannya akan persis $A$, dan itu akan menjadi jawaban terbaik yang mungkin untuk jumlah yang sudah ditetapkan tersebut (tidak mungkin ada *subsequence* *palindrome* lain karena jika karakter pertama dan terakhir sama, maka seluruh bagian tengah juga akan sama).

Sekarang, kita perlu menemukan *array* $a$ yang terbaik. Untuk melakukan ini, mari kita asumsikan ada dua angka $x$ dan $y$ dalam *array* tersebut sedemikian sehingga $x + 2 \le y$. Maka, $2^x + 2^y > 2 \cdot 2^{y-1} \ge 2^{x+1} + 2^{y-1}$. Ini berarti bahwa mengganti $x$ dan $y$ dengan $x+1$ dan $y-1$ tidak akan mengubah jumlah *array* $a$, tetapi akan membuat jumlah *subsequence* *palindrome* menjadi lebih kecil. Kita dapat melakukan proses penggantian ini sampai tidak ada dua angka dalam $a$ yang memiliki selisih lebih besar dari $1$. Sebenarnya, hanya ada satu *array* seperti itu (tanpa mempertimbangkan permutasinya), dan *array* tersebut hanya berisi $\lfloor n/5 \rfloor$ dan $\lfloor n/5 \rfloor + 1$.

Implementasi editorial:

```cpp
#include <bits/stdc++.h>
using namespace std;

const string VOWELS = "aeiou";

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(0);

	int t; 
	cin >> t;
	while (t--) {
		int n; 
		cin >> n; 

		vector<int> v(5, n / 5);   
		// n - (n % 5) numbers should be (n / 5)
		for (int i = 0; i < n % 5; i++) v[i]++; 
		// and the others should be (n / 5) + 1

		for (int i = 0; i < 5; i++) 
			for (int j = 0; j < v[i]; j++) cout << VOWELS[i]; 
				// output VOWELS[i] v[i] times
		cout << "\n";
	}
}
```
## 3.2 | Analisis Pribadi

Membaca penjelasan dari editorial membuatku pusing. Tapi melihat ke kode editorial, pendekanya hampir sama dengan pendekatanku, malah lebih efisien secara memory dan sintaksis.

Dia tidak menggunakan array terpisah untuk menyimmpan huruf vokal, tapi langsung saja simpan di string. Dia langsung menyimpan hasil dari $n/5$ sebagai nilai inisialisasi default pada vector, dan hanya menggunakan satu saja perulangan untuk mengatasi ketika $n \; \% \; 5 \neq 0$.

Jika aku memperbaiki kode programku agar sama simplenya, mungkin jadi seperti ini:

```cpp
#include<iostream>
#include<array>
using namespace std;

constexpr string VOW = "aiueo";
void solve() {
    int n;
    cin >> n;
    array<int, 5> arr{};
    arr.fill(n/5);
    for (int i=0; i<n%5; i++) arr[i]++;
    for (int i=0; i<5; i++) {
        for (int j=0; j<arr[i]; j++) {
            cout << VOW[i];
        }
    }
    cout << '\n';
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

### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int t,n;
	string ans="aiueo";
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<5;++i){
			cout<<string(n/5+(n%5>i),ans[i]);
		}
		cout<<"\n";
	}
}
```
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	char c[]="aeiou";
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<5;i++)
			for(int j=i;j<n;j+=5)
				putchar(c[i]);
		putchar(10);
	}
	return 0;
}
```
### 3 | Jawaban Ketiga

```cpp
#include "bits/stdc++.h"
#define intt long long
// #define int intt
#define pb push_back
#define endl '\n'
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<intt,intt>
#define ld long double
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(), x.end()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int inf = 1e9+7;
const int mod = 1000000007;
const int sz = 2e5+5;
int i,j;
void solve(){
    string s = "aeiou";
    int n;
    cin >> n;
    string res = "";
    for ( i = 0; i < n; i++ )   res += s[i%5];
    sort(all(res));
    cout << res << endl;
}
signed main() {
    fastio;
    int t = 1;
    cin >> t;
    for ( int cs = 1; cs <= t; cs++ ){
        // cout << "Case " << cs << ": ";
        solve();
    }
}
```