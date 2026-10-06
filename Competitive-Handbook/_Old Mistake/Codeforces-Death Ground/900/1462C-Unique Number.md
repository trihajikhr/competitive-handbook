---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1462C
judul_DEATH: Unique Number
teori_DEATH:
sumber:
  - codeforces.com
rating: 900
ada_tips?:
date_learned: 2025-10-08T16:44:00
tags:
---
Sumber: [Problem - 1462C - Codeforces](https://codeforces.com/problemset/problem/1462/C)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1462C-Unique Number

Kita diberikan sebuah angka $n$. Tugas kita adalah mencari angka $x$ terkecil, dimana jika kita menjumlahkan masing-masing digitnya, maka jumlahnya adalah sama dengan $n$. Digit-digit yang ada didalam angka $x$ harus unik, alias hanya muncul sekali.

Jika tidak ada angka $x$ yang memenuhi, outputkan $-1$.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Kita hanya boleh menggunakan satu digit unik, sehingga nilai $n$ maksimal yang bisa dicari hanyalah nilai $n$ yang:

$$n \leq 1+2+3+4+5+6+7+8+9$$
$$n\leq45$$
Jika nilai $n$ lebih dari 45, maka kita outputkan $-1$, karena tidak mungkin disusun oleh beberapa digit unik. Jika nilai $n \leq 45$ maka kita bisa mengurangi dengan 9, dan jika nilai $n$ masih diatas 9, kira kurangi dengan 8, dan jika nilai $n$ masih diatas 8, maka kita kurangi dengan 7, dan seterusnya.

Jika setelah beberapa operasi nilai $n=0$, maka hentikan perulangan, atau ketika nilai $n<i$, dimana $i$ adalah pengurang di perulangan ke $i$, maka simpan langsung nilai $n$.

Kita bisa membangun jawabanya dalam string, lalu reverse untuk menjadikanya nilai $x$ terkecil, dan simpan ke integer. Lalu outputkan hasilnya.

Implementasinya adalah sebagai berikut:

```cpp
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n>45) {
        cout << -1 << '\n';
    } else {
        string ans = "";
        for (int i=9; i>0; i--) {
            if (n>=i) {
                n-=i;
                ans+= to_string(i);
            } else {
                if (n==0) break;
                ans+=to_string(n);
                break;
            }
        }

        ranges::reverse(ans);
        n = stoi(ans);
        cout << n << '\n';
    }
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


Pertama-tama, mari kita pahami bahwa jawaban untuk masalah ini tidak boleh mengandung nol (nol di awal tidak berguna, sementara yang lain memperbesar angka, tetapi tidak mengubah jumlah). Jelas juga bahwa angka yang kita temukan harus memiliki **panjang minimum** yang mungkin (karena semakin panjang angka tanpa nol di awal, semakin besar angkanya). Angka-angka dengan panjang yang sama dibandingkan secara leksikografis, yaitu, pertama berdasarkan digit pertama, kemudian berdasarkan digit kedua, dan seterusnya. Ini berarti bahwa digit-digit dalam angka harus **berurutan** (urutan digit tidak memengaruhi jumlah, tetapi memengaruhi nilai).

Mari kita minimalkan panjang angka terlebih dahulu. Kita perlu mendapatkan jumlah yang ditentukan dengan digit sesedikit mungkin. Jadi, kita harus menggunakan digit sebesar mungkin. Kemudian, mari kita mulai dengan angka $9$ dan tambahkan digit dari $8$ hingga $1$ secara bergantian ke awal angka, sampai jumlah digit melebihi jumlah yang ditentukan. Jelas, Anda tidak bisa mendapatkan jawaban dengan digit yang lebih sedikit.

Sekarang, kita **minimalkan angkanya** itu sendiri. Pertama, kita harus meminimalkan digit pertama. Digit pertama ditentukan secara unik sebagai selisih antara jumlah digit yang tersisa dan jumlah yang disyaratkan. Jadi, Anda perlu memaksimalkan jumlah semua digit kecuali yang pertama (yang telah dilakukan pada paragraf sebelumnya). Tinggal mengoreksi digit pertama dan mencetak jawabannya.

Berikut implementasinya:

```cpp
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int x;
  cin >> x;
  vector<int> ans;
  int sum = 0, last = 9;
  while (sum < x && last > 0) {
    ans.push_back(min(x - sum, last));
    sum += last;
    last--;
  }
  if (sum < x) {
    cout << -1 << "\n";
  } else {
    reverse(ans.begin(), ans.end());
    for (int i : ans) {
      cout << i;
    }
    cout << "\n";
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
```

## 3.2 | Analisis Pribadi

Jawabanku sebenarnya masih bisa dibuat lebih pendek lagi, seperti beberapa jawaban orang lain. Namun jika melihat ke editorial, jawabanku sudah sangat mirip, yaitu membangun jawaban, dan membaliknya dengan `reverse()`. 

Jadi, aku rasa itu sudah cukup efisien.
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>

int main() {
    int T;
    scanf("%d", & T);
    while (T--) {
        int n, ans = 0, p = 1;
        scanf("%d", & n);
        for (int i = 9; i; i--)
            if (n >= i) n -= i, ans += p * i, p *= 10;
        if (n) printf("-1\n");
        else printf("%d\n", ans);
    }
    return 0;
}
```

Program ini membangun jawaban tanpa menggunakan bantuan string atau vector, melainkan langsung membangun jawaban dengan memanfaatkan operasi aritmatika sederhana.

Program ini juga menggunakan logika, dimana pengurangan terhadap nilai $n$ hanya dilakukan ketika nilai $n \geq i$, tidak ada operasi break disini.

Jadi, ketika sudah dilakukan 9 perulangan untk mengurangi nilai $n$ dengan setiap nilai $i$, dia nilai $n$ masih belum habis, maka jelas bahwa nilai $n$ diatas 45, sehingga outputkan $-1$. Karena jika nilai $n \leq 45$, maka perulangan tersebut jelas akan mengurangi habis nilai $n$ hingga 0.
### 2 | Jawaban Kedua

```cpp
#include <bits/stdc++.h>
using namespace std;

int t,n;
int dfs(int x,int limit){
    return x<=limit?x:dfs(x-limit,limit-1)*10+limit;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("%d\n",n>45?-1:dfs(n,9));
    }
    return 0;
}
```

Well, logika utamanya hampir mirip jawaban pertama, namun jelas terlihat bahwa program ini menggunakan pendekatan rekursif jika $n \leq 45$, dan langsung mengoutputkan $-1$ jika lebih dari 45. Program ini pendek dan sederhana, karena percabanganya menggunakan ternary, dan penyelesaianya menggunakan rekursif.
### 3 | Jawaban Ketiga

```cpp
#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<char> s;
    int max = 9;
    while(n>0){
        if (n > max) {
            s.push_back((char)(max + '0'));
            n = n - max;
            max--;
        }else{
            s.push_back((char)(n + '0'));
            n = 0;
            break;
        }
    }

    if(!n){
        for (int i = s.size() - 1; i >= 0; i--){
            cout << s[i];
        }
        cout << '\n';
    }else{
        cout << "-1\n";
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    long long int tt;
    cin >> tt;
    // tt = 1;
    while(tt--) solve();
}
```

Walaupun begitu, jawaban tercepat justru dimiliki oleh jawaban ini. Jawaban ini menggunakan cara yang mirip editorial, hanya saja tidak direverse, karena mekanisme reversenya diganti dengan proses output dari belakang ke depan.