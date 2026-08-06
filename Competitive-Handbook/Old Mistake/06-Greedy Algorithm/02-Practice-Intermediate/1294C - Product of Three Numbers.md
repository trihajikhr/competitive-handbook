---
obsidianUIMode: preview
note_type: STRIKE
kode_soal: 1294C
judul_FAST: Product of Three Numbers
teori_FAST: 
sumber:
  - codeforces
date_learned: 2025-08-11T17:26:00
tags:
  - STRIKE
  - greedy
---
Sumber: [Problem - 1294C - Codeforces](https://codeforces.com/problemset/problem/1294/C)

> [!NOTE] ⚔️ Teori STRIKE:
> Dari penerapan metode **STRIKE** pada problem ini, aku mendapatkan dua poin penting:
> 
>1. **Trik faktor** – Saat mencari faktor dari $n$, cukup memeriksa hingga $i \times i \leq n$, karena faktor yang lebih besar dari $\sqrt{n}$ pasti punya pasangan di bawahnya.
>   <br/>
>
>2. **Pencarian 3 bilangan berbeda** – Jika diminta mencari tiga bilangan berbeda $a, b, c \ge 2$ dengan $a \cdot b \cdot c = n$, kita dapat menggunakan dua perulangan bersarang dengan batas luar $i \times i \times i \leq n$ untuk mengoptimalkan pencarian.


<br/>



---
# Product of Three Numbers

Diberikan sebuah bilangan bulat $n$. Temukan tiga bilangan bulat **berbeda** $a, b, c$ sehingga: $2 \leq a, b, c$ dan $a \cdot b \cdot c = n$, atau nyatakan bahwa hal tersebut **tidak mungkin** dilakukan.

Jika terdapat beberapa jawaban, Anda boleh mencetak jawaban mana saja.

Anda harus menjawab untuk $t$ **kasus uji** yang saling independen.

**Input**
Baris pertama berisi sebuah bilangan bulat $t$  $(1 \leq t \leq 100)$ — jumlah kasus uji.
$t$ baris berikutnya masing-masing berisi sebuah bilangan bulat $n$ $(2 \leq n \leq 10^{9})$.

**Output**
Untuk setiap kasus uji, cetak jawabannya:

* Cetak `"NO"` jika tidak mungkin merepresentasikan $n$ sebagai $a \cdot b \cdot c$ untuk tiga bilangan berbeda $a, b, c$ dengan $2 \leq a, b, c$.
* Jika mungkin, cetak `"YES"` dan **salah satu** representasi yang memenuhi.

<br/>

---
# Sesi STRIKE ⚔️

Ada beberapa petunjuk penting:
- Jika angkanya boleh boleh sama, mungkin kita bisa menggunakan strategi $n/2$ sebanyak 2 kali untuk kasus $n$ genap. Dan jika berhasil, maka kita sudah mendapatkan angka untuk $a,b,c$. Tapi ketiga angka harus berbeda disini. Dan ternyata kasus angka $n$ ganjil tidak tercover strategi ini.

<br/>

- Mungkin menggunakan strategi menggunakan perulangan dengan $i$ sebagai pembagi, dimulai dari nilai $a$ yaitu 2, dan jika tidak membagi habis $n$, maka tingkatkan nilai $a$ menjadi 3. Jika berhasil membagi habis, maka kita ambil nilai $i$ tersebut dan simpan di $a$, lalu teruskan untuk mencari nilai $b$. Jika ditemukan nilai $b$ yang membagi habis nilai $n$, maka kita menemukan 2 angka, yaitu untuk $b$ dan $c$. 


<br/>

---


# Jawaban dan Editorial

Misalkan $a < b < c$. Kita akan mencoba meminimalkan $a$ dan memaksimalkan $c$. Biarkan $a$ menjadi pembagi terkecil dari $n$ yang lebih besar dari $1$. Kemudian biarkan $b$ menjadi pembagi terkecil dari $\frac{n}{a}$ yang tidak sama dengan $a$ maupun $1$. Jika $\frac{n}{a \cdot b}$ tidak sama dengan $a$, $b$, maupun $1$, maka jawabannya adalah `"YES"`, jika tidak maka jawabannya adalah `"NO"`. Kompleksitas waktu: $O(\sqrt{n})$ per kueri.

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int n;
		cin >> n;
		set<int> used;
		for (int i = 2; i * i <= n; ++i) {
			if (n % i == 0 && !used.count(i)) {
				used.insert(i);
				n /= i;
				break;
			}
		}
		for (int i = 2; i * i <= n; ++i) {
			if (n % i == 0 && !used.count(i)) {
				used.insert(i);
				n /= i;
				break;
			}
		}
		if (int(used.size()) < 2 || used.count(n) || n == 1) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			used.insert(n);
			for (auto it : used) cout << it << " ";
			cout << endl;
		}
	}
	
	return 0;
}
```
## Analisis Pribadi

Sebelumnya, aku menggunakan kode ini, dan terkena time limit:

```cpp
/*
Author  : Riveris
Date    : 2025-08-11 17:38
Problem : Codeforces - 1294C | Product of Three Numbers
*/

#include <iostream>
using namespace std;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

void solve() {
   int n;
   cin >> n;
   if (n < 24) {
      cout << "NO\n";
      return;
   }
   int a, b, c;

   int cnt = 2;
   while (true) {
      if (n % cnt == 0) {
         a = cnt;
         cnt++;
         break;
      } else {
         cnt++;
         if (cnt == n) {
            cout << "NO\n";
            return;
         }
      }
   }

   n /= a;
   while (true) {
      if (n % cnt == 0 && cnt != (n / cnt) && (n / cnt) != a && cnt != a) {
         b = cnt;
         c = n / cnt;
         break;
      } else {
         cnt++;
         if (cnt == n) {
            cout << "NO\n";
            return;
         }
      }
   }

   cout << "YES\n";
   cout << a << " " << b << " " << c << '\n';
}

auto main() -> int {
   fastio();
   int t;
   cin >> t;
   while (t--) {
      solve();
   }
   return 0;
}
```

Dengan menggunakan kode dari petunjuk editorial, problem berhasil diselesaikan, berikut kodenya:

```cpp
/*
Author  : Riveris
Date    : 2025-08-11 17:38
Problem : Codeforces - 1294C | Product of Three Numbers
*/

#include <iostream>
#include <set>
using namespace std;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

auto main() -> int {
   fastio();
   int t;
   cin >> t;
   while (t--) {
      int n;
      cin >> n;
      set<int> used;

      for (int i = 2; i * i <= n; i++) {
         if (n % i == 0 && !used.count(i)) {
            used.insert(i);
            n /= i;
            break;
         }
      }

      for (int i = 2; i * i <= n; i++) {
         if (n % i == 0 && !used.count(i)) {
            used.insert(i);
            n /= i;
            break;
         }
      }

      if (used.size() < 2 || used.count(n) || n == 1) {
         cout << "NO\n";
      } else {
         cout << "YES\n";
         used.insert(n);
         for (const auto& it : used) {
            cout << it << " ";
         }
         cout << '\n';
      }
   }
   return 0;
}
```

Baiklah mari kita bedah. Disini kita menggunakan bantuan struktur data Set, karena struktur data ini mencegah elemen duplikat, ini sesuai dengan ketentuan soal untuk mencari nilai $a,b,c$ yang berbeda-beda.

Langsung kita deklarasikan Set:

```cpp
set<int> used;
```

Baiklah, dilangkah awal, kita mencari nilai dari $a$ terlebih dahulu. Nilai $a$ akan menyimpan pembagian dengan angka terkecil,

```cpp
for (int i = 2; i * i <= n; i++) {
 if (n % i == 0 && !used.count(i)) {
	used.insert(i);
	n /= i;
	break;
 }
}
```

Karena nilai dari $a,b,c \geq 2$, maka kita mulai $i$ dari 2. 

Perhatikan bahwa kita menggunakan $i * i$. Tahu kenapa? 

Oke, aku jelasin logikanya kenapa di loop itu dipakai kondisi $i \times i \leq n$.

---

**1. Kenapa cukup sampai $\sqrt{n}$**

* Kalau kita mencari **faktor** (pembagi) dari $n$, kita tidak perlu memeriksa sampai $n$ itu sendiri.
* Misal $n$ punya faktor $d$ yang lebih besar dari $\sqrt{n}$, maka faktor pasangannya $n/d$ pasti lebih kecil dari $\sqrt{n}$.
* Artinya, kalau kita sudah memeriksa semua $i$ dari $2$ sampai $\sqrt{n}$ dan tidak menemukan pembagi, maka $n$ pasti **bilangan prima**.

Contoh:

$$
n = 100  
$$

* $\sqrt{100} = 10$
* Faktor di bawah atau sama dengan 10: $2, 4, 5, 10$
* Faktor di atas 10 pasti pasangannya ada di bawah 10, misalnya $20$ pasangannya $5$, $25$ pasangannya $4$, dll.

---

**2. Kenapa ditulis $i \times i \leq n$ bukannya $i \leq \sqrt{n}$**

* Menghitung $\sqrt{n}$ di setiap iterasi butuh operasi akar kuadrat (*square root*) yang lebih lambat.
* Dengan membandingkan $i \times i \leq n$, kita hanya memakai perkalian dan perbandingan, yang jauh lebih cepat.
* Jadi, kondisi ini adalah **trik optimisasi** supaya perulangan tetap efisien.

---

**Intinya:**
$i \times i \leq n$ artinya kita hanya mencari faktor sampai $\sqrt{n}$, karena faktor di atasnya sudah pasti punya pasangan di bawahnya. Ini menghemat waktu dari $O(n)$ menjadi $O(\sqrt{n})$.

---


Oke, jika kita menemukan pembagi untuk $n$, maka kita ambil nilai dari $i$, dan hentikan perulangan, tidak lupa juga simpan nilai $i$ tersebut kedalam set `used`. Cara diatas juga akan membuat set `used` tidak akan terisi jika semisal nilai dari $n$ adalah angka prima.

### Pencarian nilai $b$ dan $c$

Jika sebelumnya kita sudah menemukan pembagi yang valid untuk $a$, maka sekarang nilai $n$ sekarang sudah berubah karena kita melakukan operasi $n/=i$.

Sekarang kita lakukan perulangan kedua untuk mencari lagi pembagi $i$ yang bisa membagi habis nilai $n$ yang baru ini, tapi dengan catatan nilai $i$ belum ada di set `used`. 

Jika ditemukan, sisipkan nilai dari $i$ ke set `used`, dan sekarang kita maju ke tahap selanjutnya.

### Pemeriksaan set

Jika semisal angka $n$ adalah angka prima, maka set pasti akan kurang dari 2. Jika semisal kita menemukan pembagi $a$, namun kita menemukan satu-satunya pembagi yang tersisa adalah $b$ dan $c$ dimana $b==c$, maka hasilnya pasti `NO` karena kondisi `used.count(n)` terpenuhi.

Perhatikan pemeriksaan ini:

```cpp
if (used.size() < 2 || used.count(n) || n == 1) { // kode }
```

JIka angka $n$ prima, maka isi dari set `used` pasti kurang dari 2.

Jika semisal $n$ tidak mungkin memiliki 3 pembagi $a,b,c$ yang berbeda, maka `used.count(n)` pasti akan tertrigger. Kasus ini terjadi jika semisal $n=32$, dimana $32/2=16$, dan $16 = 4 \cdot 4$. Kita tidak bisa menggunakan angka 2, dan juga angka 4. Dan ternyata nilai dari $b==c$ sehingga kita output `NO`.

Kasus `n == 1` terjadi ketika nilai $n$ semisal adalah 2. Ini mangakibatkan $2/2 = 1$.

Jika pemeriksaan diatas terlewati, artinya kita menemukan pembagi yang sesuai untuk nilai $n$, sehingga kita bisa outputkan `YES`. Nilai $a$ dan $b$ sudah ada di dalam set `used`, kita masukan $n$ kedalam set, lalu outputkan nilainya. 

## Kode Hasil Analisis
Berikut adalah kodeku ketika aku mengamati editorial dan melakukan beberapa penyederhanaan. ternyata seperti ini sudah cukup:

```cpp
/*
Author  : Riveris
Date    : 2025-08-11 17:38
Problem : Codeforces - 1294C | Product of Three Numbers
*/

#include <iostream>
#include <set>
using namespace std;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

auto main() -> int {
   fastio();
   int t;
   cin >> t;
   while (t--) {
      int n;
      cin >> n;
      set<int> used;

      for (int i = 2; i * i <= n; i++) {
         if (n % i == 0) {
            used.insert(i);
            n /= i;
            break;
         }
      }

      for (int i = 2; i * i <= n; i++) {
         if (n % i == 0 && !used.count(i)) {
            used.insert(i);
            n /= i;
            break;
         }
      }

      if (used.size() < 2 || used.count(n)) {
         cout << "NO\n";
      } else {
         cout << "YES\n";
         for (const auto& it : used) {
            cout << it << " ";
         }
         cout << n << '\n';
      }
   }
   return 0;
}
```

Jika melihat kode orang lain, ada juga yang bisa mengimplementasikan solusi tanpa bantuan struktur data apapun, seperti ini, fungsi `solve()`:

```cpp
void solve(){
	int n;
	scanf("%d",&n);
	for(int i=2; i*i*i<=n; i++){
		if(n%i==0){
			for(int j=2;j*j<=n/i;j++){
				if((n/i)%j==0&&j!=i&&(n/i)/j!=i&&j*j!=n/i){
					cout<<"YES"<<endl;
					cout<<i<<' '<<j<<' '<<(n/i)/j<<endl;
					return;
				}
			}
		}
	}
	cout<<"NO"<<endl;
}
```

Jika kamu melihat syntax `(n/i)`, itu sebenarnya bisa dibuat lebih mudah dibaca jika semisal ditulis:

```cpp
int temp = (n/i);
```

Sehingga kita cukup menggunakan `temp` di dalam perulangan kedua. Namun mungkin penulis kode ini ingin membuat kode seefisien mungkin wkwkwk.