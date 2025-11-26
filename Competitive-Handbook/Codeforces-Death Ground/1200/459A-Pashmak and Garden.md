---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 459A
judul_DEATH: Pashmak and Garden
teori_DEATH: mencari titik koordinat sudut persegi
sumber:
  - codeforces.com
rating: 1200
ada_tips?: true
date_learned: 2025-10-18T19:58:00
tags:
---
Sumber: [Problem - 459A - Codeforces](https://codeforces.com/problemset/problem/459/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 459A-Pashmak and Garden

Ada sebuah taman berbentuk persegi. Sudut sudutnya terletak di titik koordinat tertentu. Setiap sudut ditandai dengan satu pohon.

Kita diberikan koordinat dari $2$ pohon saja, tugas kita adalah mencari koordinat dari $2$ pohon sisanya.

Inputan yang diberikan adalah $x1,y1,x2,y2$, dimana pohon $1$ terletak pada koordinat $x1,y1$, dan pohon $2$ terletak pada koordinat $x2,y2$.

Outputkan koordinat pohon sisanya, dan outputkan $-1$ jika tidak mungkin untuk membuat koordinat yang pas untuk taman berbentuk persegi.

Catatan: masing-masing koordinat memiliki batasan $-1000 \leq x3,y3,x4,y4 \leq 1000$.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Jika diberikan 2 koordinat titik sudut persegi, maka akan ada 3 kemungkinan.

Kemungkinan pertama adalah ketika sudut yang diberikan adalah sudut-sudut diagonal. Jika sudut yang diberikan adalah diagonal, maka kita tidak perlu mengkhawatirkan batasan koordinat. Nilai dari koordinat pohon ke-$3$ dan ke-$4$ sudah dimiliki oleh $x1,y1,x2,y2$, dimana koordinat pohon-$3$  bisa kita set dengan $(x2,y1)$, dan koordinat pohon ke-$4$ bisa kita set ke $(x1,y2)$ (*terbolak balik pun tidak masalah*).


![[459A-Pashmak and Garden-1.png]]


Kemungkinan kedua, adalah jika diketahui kedua koordinat memiliki nilai $x$ yang sama, atau $x1 = x2$. Ini artinya, masing-masing koordinat pohon ke-$3$ dan ke-$4$ akan memiliki nilai $y$ yang sama dengan $y1$ dan $y2$. Kita cukup menambahkan mencari nilai $diff = abs(y1-y2)$, untuk menemukan koordinat yang cocok untuk kandidat $x3$ dan $x4$. 

Namun, kita harus memerhatikan batasan koordinat sekarang. Tetapkan aturan berikut:

$$x3 = \begin{cases}
x1+diff &\text{if } x1+diff \leq 1000 \\
x1-diff\ &\text{if } x1+diff >1000\\
\end{cases}$$
$$x4 = \begin{cases}
x1+diff &\text{if } x1+diff \leq 1000 \\
x1-diff\ &\text{if } x1+diff >1000\\
\end{cases}$$

![[459A-Pashmak and Garden-2.png]]

Kemungkinan ketiga, adalah ketika nilai $y$ sama, atau $y1=y2$. Jika ini yang terjadi, maka lakukan saja operasi yang mirip dengan kemungkinan kedua, karena lokasi koordinat $x$ untuk pohon ke-$3$ dan ke-$4$ pasti akan sama dengan $x1$ dan $x2$. Isi nilai $diff = abs(x1-x2)$, dan gunakan untuk mencari kandidat $y3$ dan $y4$ yang sesuai. 

$$y3 = \begin{cases}
y1+diff &\text{if } y1+diff \leq 1000 \\
y1-diff\ &\text{if } y1+diff >1000\\
\end{cases}$$
$$y4 = \begin{cases}
y2+diff &\text{if } y2+diff \leq 1000 \\
y2-diff\ &\text{if } y2+diff >1000\\
\end{cases}$$

![[459A-Pashmak and Garden-3.png]]

Jadi, berikut adalah implementasiku:

```cpp
#include<iostream>
using namespace std;

auto main() -> int {
    int x1, y1, x2, y2, diff;
    cin >> x1 >> y1 >> x2 >> y2;

    if (abs(x1-x2) == abs(y1-y2)) {
        cout << x1 << " " << y2 << " "
             <<  x2 << " " << y1;
    } else if (x1 == x2) {
        diff = abs(y1-y2);
        diff = x1 + diff <= 1000 ? x1 + diff : x1 - diff;
        cout << diff << " " << y1 << " "
             << diff << " " << y2;
    } else if (y1 == y2) {
        diff = abs(x1 - x2);
        diff = y1 + diff <= 1000 ? y1 + diff : y1 - diff;
        cout << x1 << " " << diff << " "
             << x2 << " " << diff;
    } else {
        cout << -1;
    }
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Empat titik sudut (*vertices*) dari sebuah persegi dengan panjang sisi $a$ (dan sisi-sisi sejajar dengan sumbu koordinat) memiliki bentuk ini: $(x_0, y_0)$, $(x_0 + a, y_0)$, $(x_0, y_0 + a)$, $(x_0 + a, y_0 + a)$.

Dua titik sudut diberikan, hitunglah dua titik sudut lainnya (dan periksa rentang/batasnya).

Kompleksitas total: $\mathcal{O}(1)$.

Implementasi editorial:

```cpp
#include <iostream>
using namespace std;
int abs(int x) {
    return (x > 0 ? x : -x);
}

int main() {
    ios::sync_with_stdio(false);
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 != x2 && y1 != y2 && abs(x1 - x2) != abs(y1 - y2))
        cout << -1 << endl;
    else if (x1 == x2)
        cout << x1 + abs(y1 - y2) << " " << y1 << " " 
             << x2 + abs(y1 - y2) << " " << y2 << endl;
    else if (y1 == y2)
        cout << x1 << " " << y1 + abs(x1 - x2) << " " 
             << x2 << " " << y2 + abs(x1 - x2) << endl;
    else
        cout << x1 << " " << y2 << " " << x2 << " " << y1 << endl;
    return 0;
}
```

## 3.2 | Analisis Pribadi

Solusiku sama persis dengan editorial, kompleksitasnya konstan, dan aku rasa tidak perlu ada perbaikan lagi, karena sudah optimal.
## 3.3 | Analisis Jawaban User Lain

Solusi optimal adalah apa yang mirip dengan editorial. Banyak user lain yang menyadarinya, menyebabkan kebanyakan jawaban tidak jauh berbeda:

### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>

using namespace std;
int main() {
    int x, y, x1, y1, a = 0, b = 0;
    cin >> x >> y >> x1 >> y1;
    if (abs(x - x1) == abs(y - y1)) cout << x << ' ' << y1 << ' ' << x1 << ' ' << y;
    else if (x == x1 && y != y1) cout << (y1 - y) + x << ' ' << y << ' ' << (y1 - y) + x << ' ' << y1;
    else if (y == y1 && x != x1) cout << x << ' ' << y + abs(x1 - x) << ' ' << x1 << ' ' << y1 + abs(x1 - x);
    else cout << -1;

}
```
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h> 
using namespace std;
main() {
	int x1,x2,y1,y2;
	cin>>x1>>y1>>x2>>y2;
	if(abs(x1-x2)==abs(y1-y2)){
		printf("%d %d %d %d",x1,y2,x2,y1);
	} else if(x1==x2){
		printf("%d %d %d %d",x1+abs(y1-y2),y1,x2+abs(y1-y2),y2);
	} else if(y1==y2){
		printf("%d %d %d %d",x1,y1+abs(x1-x2),x2,y2+abs(x1-x2));
	} else {
		cout<<-1;
	}
} 
```
### 3 | Jawaban Ketiga

```cpp
//#include <stdio.h>
//#include <unordered_map>
//#include <stack>
//#include <unordered_set>
//#include <time.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm> 
#include <cmath>

const char el = '\n';
const char sp = ' ';
using namespace std;
using ll = long long;
using ull = unsigned long long;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int x3, y3, x4, y4;
	if (x1 == x2) {
		x3 = x4 = x1 + abs(y1 - y2);
		y3 = y1; y4 = y2;
		cout << x3 << sp << y3 << sp << x4 << sp << y4 << el;
	}
	else if (y1 == y2) {
		y3 = y4 = y1 + abs(x1 - x2);
		x3 = x1; x4 = x2;
		cout << x3 << sp << y3 << sp << x4 << sp << y4 << el;
	}
	else if (abs(x1 - x2) == abs(y1 - y2)) {
		x3 = x1; y3 = y2;
		x4 = x2; y4 = y1;
		cout << x3 << sp << y3 << sp << x4 << sp << y4 << el;
	}
	else cout << -1 << el;
}
```