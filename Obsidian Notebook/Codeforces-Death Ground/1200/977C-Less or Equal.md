---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 977C
judul_DEATH: Less or Equal
teori_DEATH:
sumber:
  - codeforces.com
rating: 1200
ada_tips:
date_learned: 2025-11-06T22:51:00
tags:
  - sortings
---
Sumber: [Problem - 977C - Less or Equal](https://codeforces.com/problemset/problem/977/C)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 977C-Less or Equal

Diberikan sebuah array $a$ dengan ukuran $n$, dan sebuah angka $k$. Tugasmu adalah mencetak angka bilangan bulat $x$, yang berada di rentang $[1;10^9]$ yang mana tepat $k$ elemen dari array adalah kurang atau sama dengan angka $x$.

Info tambahan, sekuens yang diberikan mungkin memiliki beberapa elemen yang kembar.

Jika angka $x$ tidak mungkin didapatkan, maka outputkan $-1$.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Sekilas tampak bahwa kita perlu mengurutkan array, dan itu benar. 

Tugas kita adalah mencari angka $x$, yang mana angka tersebut lebih besar atau sama dengan $k$ buah elemen dari array yang diberikan. Jika diberikan array sebagai berikut, dan nilai $k$ adalah $5$, maka mudah untuk menemukan jawabanya:

$$1,2,3,4,5,6,7,8,9,10$$

Maka kita bisa menggunakan angka $x=5$, karena $x \geq 1,2,3,4,5$, tepat terdapat $5$ angka. Namun, tantangan sebenarnya dari problem ini adalah jika array yang diberikan memiliki kondisi sebagai berikut:

$$1,2,3,4,5,5,6,7,8,9,10$$
Maka jawabanya adalah $-1$, karena kita tidak bisa memilih angka $x$ yang tepat memiliki $k$ elemen yang kurang atau sama dengan $x$, karena terdapat lebih dari satu kemunculan angka $5$ pada elemen. Tetapi jika $k=6$, maka kita bisa menggunakan $x=5$, karena $x \geq 1,2,3,4,5,5$.

Jadi, intuisiku sederhana:

Aku perlu menerima array dan mengetahui  apakah ada elemen duplikat, dan mengurutkanya juga. Selain itu, aku juga perlu mengetahui berapa banyak frekuensi elemen duplikat tersebut yang muncul pada array. Maka digunakanlah struktur data `set` dan `unordered_map`.

`set` akan menampung nilai unik sekaligus mengurutkan, sedangkan `unordered_map` akan menampung frekuensi kemunculan masing-masing elemen.

Itu ditangani oleh kode seperti ini:

```cpp
set<int> daset;
unordered_map<int, int> dasmap;

for (int i=0, x; i<n; i++) {
	cin >> x;
	daset.insert(x);
	dasmap[x]++;
}
```

Terdapat edgecase dimana nilai $k=0$. Satu-satunya jawaban  untuk membuat tepat $0$ angka berada dibawah $k$, adalah jika angka terkecil pada array bukan angka $1$. Ini karena kita akan menggunakan $x=1$ sebagai jawaban paling mungkin dan aman. Tetapi jika $k=0$, dan angka terkecill pada array adalah $1$, maka tidak mungkin memenuhi persyaratan ini. Kita bisa mengakses elemen terkecil pada array langsung dari struktur data set, dengan menggunakan bantuan itarator `begin`, dan akses nilainya sebagai pointer:

```cpp
if (k==0) {
	if (*daset.begin() == 1) cout << -1;
	else cout << 1;
	return 0;
}
```

Satu-satunya cara agar nilai $x$ mungkin didapat, adalah dengan memastikan bahwa tempat dimana angka $x$ seharusnya diselipkan (*semisal diselipkan*) tidak memiliki elemen duplikat, atau seadainya terdapat beberapa elemen duplikat, maka jumlah angka dbawah $k$ harus pas (*seperti contoh diawal*).

Oleh karena itu, lakukan perulangan pada `set`, dan gunakan elemen pada `set` untuk mengetahui frekuensi kemunculan dengan `unordered_map`. Jumlahkan frekuensi kemunculan setiap elemen, dan jika jumlahnya tepat sama dengan $k$, maka $x$ ditemukan, yaitu tepat elemen ke-$i$ dari perulangan terhadap set. Jika melebihi $k$, berarti beberapa elemen duplikat membuat angka $x$ tidak mungkin ditemukan.

Berikut implementasiku:

```cpp
#include<iostream>
#include<unordered_map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    set<int> daset;
    unordered_map<int, int> dasmap;

    for (int i=0, x; i<n; i++) {
        cin >> x;
        daset.insert(x);
        dasmap[x]++;
    }

    if (k==0) {
        if (*daset.begin() == 1) cout << -1;
        else cout << 1;
        return 0;
    }

    int ans = 0;
    for (auto itr = daset.begin(); itr != daset.end(); itr++) {
        ans += dasmap[*itr];
        if (ans > k) {
            cout << -1;
            break;
        }

        if (ans == k) {
            cout << *itr;
            break;
        }
    }
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official


Dalam masalah ini, Anda dapat melakukan hal berikut: pertama, mari kita sort (urutkan) array kita.

Misalkan $ans$ adalah hasilnya. Kemudian Anda memiliki dua kasus: jika $k=0$ maka $ans:=a_0 - 1$ sebaliknya $ans:=a_{k-1}$ (untuk array yang berindeks 0).

Kemudian Anda perlu menghitung jumlah elemen dari array $a$ yang kurang dari atau sama dengan $ans$. Misalkan jumlah tersebut adalah **$cnt$**. Kemudian jika **$ans < 1$** atau **$cnt \ne k$** maka cetak "-1" sebaliknya cetak **$ans$**.

Implementasi editorial:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, k;
	scanf("%d %d", &n, &k);
	
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	
	sort(a.begin(), a.end());
	
	int ans;
	
	if (k == 0) {
		ans = a[0] - 1;
	} else {
		ans = a[k - 1];
	}
	
	int cnt = 0;
	
	for (int i = 0; i < n; ++i)
		if (a[i] <= ans) ++cnt;
	
	if (cnt != k || !(1 <= ans && ans <= 1000 * 1000 * 1000)) {
		puts("-1");
		return 0;
	}
	
	printf("%d\n", ans);
	
	return 0;
}
```


## 3.2 | Analisis Pribadi

Well, setelah beberapa lama, aku menemukan solusi yang cukup efisien dengan menggunakan `map`. Struktur data ini mengurutkan elemen, sehingga jauh lebih efisien dibandingkan dengan menggunakan struktur data terpisah untuk memanfaatkan pengurutan datanya seperti `set` yang dibantu oleh `unordered_map`. Jumlah frekeunsi kemunculan data juga bisa ditampung oleh value kedua dari `map`, tidak perlu menggunakan `unordered_map`.

Implementasi baru ini menggunakan satu struktur data, menjadikanya lebih efisien daripada implementasi pertamaku:

```cpp
#include<iostream>
#include<map>
using namespace std;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    map<int, int> dasmap;

    for (int i=0, x; i<n; i++) {
        cin >>x;
        dasmap[x]++;
    }

    if (k==0) {
        cout << (dasmap.begin()->first == 1 ? -1 : 1);
    } else {
        int cnt = 0;
        for (auto itr = dasmap.begin(); itr != dasmap.end(); ++itr) {
            cnt += itr->second;
            if (cnt == k) {
                cout << itr->first;
                break;
            }

            if (cnt > k) {
                cout << -1;
                break;
            }
        }
    }
    return 0;
}
```
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include <bits/stdc++.h>
using namespace std;

int n, k;
int main() {
	cin >> n >> k;
	int ar[n];
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	sort(ar,ar + n);
	if ((k != 0 && ar[k - 1] == ar[k]) || (k == 0 && ar[0] == 1))
	    cout << -1;
	else if (k == 0 && ar[0] > 1)
	    cout << 1;
	else
	    cout << ar[k - 1];
}
```

Program ini menerima inputan dalam vector, dan lalu mengurutkanya secara ascending. Kondisional pertama mengatasi ketika $k \neq  0$, dan elemen tepat ke $ar[k] \equiv ar[k+1]$. Ini menandakan nilai $x$ tidak bisa diambil, karena posisi yang seharusnya berada di dalam elemen yang memiliki lebih dari satu duplika, dan duplikat tersebut ada di kananya, sehingga tepat ada $k$ angka dibawah $x$ mustahil tercapai. 

Kondisional yang sama juga mengatasi ketika $k=0$, dan elemen pertama adalah $1$, artinya nilai $x$ juga tidak bisa diambil. 

Selain itu, jika $k=0$, dan elemen pertama bukan $1$, maka kita bisa memenuhi kondisi ini dengan mengoutputkan $1$.

Selain itu, maka nilai $x$ bisa ditemukan, dengan menggunakan angka dari array, yaitu $x=ar[k]$.
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector < int64_t > a(n + 1);
    a[0] = 1;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    cout << (k == n || a[k + 1] - a[k] ? a[k] : -1);
}
```

Well, ini merupakan cara yang *clever*. Kondisional terakhir ternyata cukup untuk mengatasi logika penyelesaian masalah yang diberikan.

Jika $k \equiv n$ atau elemen ke $a[k+1]\equiv a[k]$, maka langsung outputkan saja $-1$. Edgecase jika $k=0$ diatasi dengan menginisialisasi $a[0]=1$, karena array ini menggunakan 0-based index, sehingga jika $k=0$, maka jika array pertama adalah $1$, maka akan tercipta operasi $a[1]-a[0]=1-1=0$, atau false. 
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cout.tie(nullptr), cin.tie(nullptr);
using namespace std;

const int sz = 2e5 + 5;

int main() {
	FIO;
    int n, k;
    cin >> n >> k;

    vector <int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());

    if (k == 0) {
        if (vec[0] == 1)
            cout << -1;
        else
            cout << 1;
    } else if (k != n) {
        if (vec[k] != vec[k - 1]) {
            cout << vec[k - 1];
        } else {
            cout << -1;
        }
    } else
        cout << vec[k - 1];
}
```

Metode penyelesaian ini mirip dengan jawaban pertama, menggunakan beberap kondisional untuk mengecek apakah elemen ke-$k$ memiliki duplikat di sebelah kananya atau tidak, dan mengatasi beberapa edgecase seperti ketika $k=0$.