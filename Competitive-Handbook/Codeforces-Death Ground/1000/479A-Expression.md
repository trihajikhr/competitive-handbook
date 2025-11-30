---
obsidianUIMode: preview
note_type: death ground kilat
kode_soal: 479A
judul_DEATH: Expression
sumber:
  - codeforces.com
rating: 1000
date_learned: 2025-11-29T14:39:00
tags:
  - brute-force
  - math
---
Sumber: [Problem - 479A - Codeforces](https://codeforces.com/problemset/problem/479/A)

```ad-tip
title: 🛡️ Review Death Ground
Gunakan saja teknik hard-coded jika tidak terlalu panjang, dan kemungkinan salahnya 0%.
```

<br/>

---
# 1 | 479A-Expression

Kita bisa mengambil nilai terbesar dari 4 kombinasi saja. Setiap kombinasi ini bisa kita taruh dalam satu variabel, dan gunakan fungsi `max()` untuk mencari mana nilai terbesar.

- $x+y+z$, ketika inputan semuanya bernilai $1$, maka penjumlahan yang akan menghasilkan jumlah terbesar.
- $x \times y \times z$, ketika semua inputan bukan bernilai $1$, maka perkalian akan menghasilkan nilai terbesar.
- $(x + y) \times z$ atau $x \times (y + z)$, jika ada satu atau dua angka $1$.

Berikut implementasinya:

```cpp
#include<iostream>
#include<algorithm>
using namespace std;

auto main() -> int {
    int x, y, z;
    cin >> x >> y >> z;

    int a = x + y + z;
    int b = x * y * z;
    int c = (x+y) * z;
    int d = x * (y+z);
    cout << max({a,b,c,d});
    return 0;
}
```

Ternyata kita bisa menggunakan satu variabel, dan melakukan operasi `max()` berkali-kali seperti seperti ini:

<br/>

---
# 2 | Analisis Singkat

Banyak pengguna yang menuliskan 4 jenis kombinasi yang mungkin secara langsung. Lagipula cara ini lebih pendek, dan cepat.

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<max({a*b*c,(a+b)*c,(b+c)*a,a+b+c});
}
```

```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a,b,c;
  cin>>a>>b>>c;
  cout<<max({a+b+c,((a+b)*c),(a*(b+c)),(a*b*c)});
}
```

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;
	cin >> a >> b >> c;
	cout << max({a + b + c,a * b * c,a * (b + c),(a + b)* c});
} 
```

```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll i,ans,a,b,c;
	while(cin>>a>>b>>c)
	{
		ans=a+b+c;
		ans=max(ans,(a*b*c));
		ans=max(ans,(a+b)*c);
		ans=max(ans,a*(b+c));
		ans=max(ans,a+(b*c));
		ans=max(ans,(a*b)+c);
		cout<<ans<<endl;
	}
	return 0;
}
```

```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
signed main() {
    int a , b , c;
    cin >> a >> b >> c;
    int ans = 0;
    ans = max(ans,a+b+c);
    ans = max(ans, a*b+c);
    ans = max(ans, a+b*c);
    ans = max(ans, (a+b)*c);
    ans = max(ans, a*(b+c));
    ans = max(ans, a*b*c);
    cout << ans << "\n";
}
```