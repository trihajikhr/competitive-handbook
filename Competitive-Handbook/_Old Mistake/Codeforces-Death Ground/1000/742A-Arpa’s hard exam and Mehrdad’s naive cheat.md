---
obsidianUIMode: preview
note_type: death ground
kode_soal: 742A
judul_DEATH: Arpa’s hard exam and Mehrdad’s naive cheat
teori_DEATH: Digit terakhir dari perpangkatan
sumber:
  - codeforces.com
rating: 1000
ada_tips: true
date_learned: 2025-12-05T10:57:00
tags:
---
Sumber: [Problem - 742A - Codeforces](https://codeforces.com/problemset/problem/742/A)

```ad-tip
title:⚔️ Teori Death Ground
Lakukan eksplorasi terlebih dahulu untuk menemukan pola yang terbentuk dari angka yang dipangkatkan dengan $n$ yang sangat besar. Cari tahu juga, bagaimana caranya mencari angka besar tanpa bantuan kalkulator, jika yang diminta adalah menebak digit terakhirnya.
```

<br/>

---
# 1 | 742A-Arpa’s hard exam and Mehrdad’s naive cheat

Diberikan sebuah angka yaitu $1378$ dan sebuah angka $n$. Tentukan digit terakhir dari hasil $1378^n$, yang mana $n$ berada adalah inputan yang berada di rentang $0 \leq n \leq 10^9$.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Jika melihat batasan yang ada, dimana $n$ memiliki batasan hingga $10^9$, maka mustahil untuk mencari apa digit terakhir dari $n$ yang bernilai lumayan besar, bahkan mungkin tidak akan sampai untuk $n > 10$. 

Jika menggunakan intuisi disini, pasti terdapat sebuah pola yang bisa digunakan, untuk melihat jawaban yang mungkin bisa dibentuk dengan penyelesaian yang sederhana. Misalnya kita menggunakan bantuan kalkulator, tapi kalkulator [Big Number](https://www.calculator.net/big-number-calculator.html), maka kita bisa menelusuri jawabanya ketika $n$ berada di rentang $1$ hingga $10$:

1. $1378^0 = 1,\text{ last digit } \rightarrow 1$
2. $1378^1=1378, \text{ last digit } \rightarrow 8$
3. $1378^2=1,898,884, \text{ last digit } \rightarrow 4$
4. $1378^3=2,616,662,152, \text{ last digit } \rightarrow 2$
5. $1378^4=3,605,760,445,456, \text{ last digit } \rightarrow 6$
6. $1378^5=4,968,737,893,838,368, \text{ last digit } \rightarrow 8$
7. $1378^6=6,846,920,817,709,271,104, \text{ last digit } \rightarrow 4$
8. $1378^7=9,435,056,886,803,375,581,312, \text{ last digit } \rightarrow 2$
9. $1378^8=13,001,508,390,015,051,551,047,936, \text{ last digit } \rightarrow 6$
10. $1378^9=17,916,078,561,440,741,037,344,055,808, \text{ last digit } \rightarrow 8$
11. $1378^{10}=24,688,356,257,665,341,149,460,108,903,424, \text{ last digit } \rightarrow 4$

Sekarang terlihat sebuah pola yang jelas, yaitu pola $8,4,2,6$, lalu ulang lagi $8,4,2,6$, dan akan begitu seterusnya.

Ini artinya, kita bisa membuat kesimpulan bahwa, ketika $n=0$, maka hasilnya pasti $1$, karena angka berapapun ketika dipangkatkan dengan $0$ hasilnya pastti $1$.

Tapi ketika $n \neq 1$, maka kita bisa menggunakan operasi modulo, untuk mendapatkan jawabanya, dimana ketika:

$$n \text{ mod 4}=
\begin{cases}
0, & 6 \\\\
1, & 8 \\\\
2, & 4 \\\\
3, & 2 
\end{cases}$$

Sehingga implementasinya cukup mudah, berikut implementasiku:

```cpp
#include<iostream>  
using namespace std;  
  
auto main() -> int {  
    int n;  
    cin >> n;  
    int b = n % 4;  
    if (n==0) {  
        cout << 1;  
        return 0;  
    }  
    if (b==1) cout << 8;  
    else if (b==2) cout << 4;  
    else if (b==3) cout << 2;  
    else if (b==0) cout << 6;  
    return 0;  
}
```
<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Analisis editorial memiliki solusi yang sama dengan jawabanku! Hanya saja dituliskan dengan menggunakan format gambar, sehingga tidak bisa disalin disini.

## 3.2 | Analisis Pribadi

Kompleksitas solusi diatas sudah $O(1)$, kompleksitas paling efisien untuk kasus ini, sehingga tidak perlu diperbaiki lagi.
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, ar[4] = {6,8,4,2};
    
    cin >> n;
    if (n == 0) {
        cout << 1;
    } else {
        cout << ar[n % 4];
    }
    return 0;

}
```

Cara yang cerdas! Kode ini tidak menggunakan percabangan yang panjang, namun memanfaatkan hasil dari $n \mod 4$ sebagai indeks untuk mengakses jawaban yang tersimpan di array $ar$.
### 2 | Jawaban Kedua

```cpp
#include <iostream>
#define ll long long
using namespace std;

int main() {
    ll num; 
    cin >> num;
    cout << "68421"[(num!=0) ? num%4 : 4];
    return 0;
}
```

Cara ini juga *clever!* Dia menggunakan String yang menyimpan `68421`, dan menggunakan percabangan ternary untuk mengakses indeks pada string, dan mendapatkan jawaban dengan cara yang sangat rapi dan simple!
### 3 | Jawaban Ketiga

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=1;
    cin >> n;
    if (n == 0){
        cout << 1;
        return 0;
    }
    if (n%4 == 0) cout << 6;
    else if (n%4==1) cout << 8;
    else if (n%4==2) cout << 4;
    else cout << 2;
}
```

Cara yang sama dengan caraku, menggunakan percabangan dan cara yang lebih native.