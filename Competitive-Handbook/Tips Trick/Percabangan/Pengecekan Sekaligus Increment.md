---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Pengecekan Sekaligus Increment
sumber:
  - myself
  - codeforces.com
tags:
  - tips-trick
  - syntax
---
---
# Pengecekan Sekaligus Increment

Katakanlah kita diberikan sebuah array atau vector dengan tipe data integer $a,b$, dan $c$  berpasangan sebanyak $n$ sebagai berikut:

```bash
[1,7,8]
[6,5,9]
[5,9,11]
...
...
n
```

Lalu kita diminta untuk menghitung, berapa banyak angka yang jika ketiganya dijumlahkan, melebihi $x$, atau $a+b+c > x$. Beberapa orang mungkin akan menggukana kode seperti berikut:

```cpp
#include<iostream>
#include<set>
using namespace std;

auto main() -> int {
    int n, x, cnt = 0;
    cin >> n >> x;

    for (int i=0, a,b,c; i < n; i++) {
        cin >> a >> b >> c;

        if (a + b + c > x) {
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}
```

Sebenarnya, ada cara yang lebih ringkas lagi, sangat ringkas untuk menyelesaikan permasalaha ini. Caranya adalah menggabungkan pengecekan apakah $a+b+c > x$ dengan operasi increment. Kodenya adalah sebagai berikut:

```cpp
for (int i=0, a,b,c; i < n; i++) {  
    cin >> a >> b >> c;  
    cnt += a + b + c > x;  
}
```

Perhatikan kode ini:

```bash
 cnt += a + b + c > x;    
```

Didalam operasi `a + b + c > x` , terdapat operasi logika, dimana dilakukan pengecekan dengan tanda `>`. Ketika operasi logika ini bernilai `true`, maka akan mengembalikan nilai $1$, dan jika bernilai `false`, akan mengembalikan nilai $0$. 

Ini membuat operasi pengecekan dan increment atau penambahan, bisa dilakukan hanya dengan cukup satu baris, dan sangat ringkas!