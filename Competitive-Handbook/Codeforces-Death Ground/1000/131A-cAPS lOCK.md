---
obsidianUIMode: preview
note_type: death ground kilat
kode_soal: 131A
judul_DEATH: cAPS lOCK
sumber:
  - codeforces.com
rating: 1000
date_learned: 2025-11-29T18:48:00
tags:
  - implementation
  - strings
---
Sumber: [Problem - 131A - Codeforces](https://codeforces.com/problemset/problem/131/A)

```ad-tip
title: 🛡️ Review Death Ground
Fungsi `transform()` bisa digunakan untuk menkonversi karakter seluruh string. Fungsi-fungsi seperti `islower()`, `isupper()`, `tolower()`, dan `toupper()` bisa digunakan secara langsung sehingga tidak perlu mengakses kode ASCII pada karakter.
```

<br/>

---
# 1 | 131A-cAPS lOCK

Jika semisal karakter pertama kecil dan semua karakter setelahnya besar, maka transform supaya karakter pertama menjadi besar, dan sisa karakter setelahnya menjadi kecil.

Jika semua karakter besar, maka rubah semuanya menjadi kecil.

Jika tidak, maka outputkan apa adanya:

```cpp
#include<iostream>
#include<cctype>
#include<algorithm>
using namespace std;

auto main() -> int {
    string s;
    cin >> s;

    if (islower(s[0])) {
        for (int i=1; i<s.length(); i++) {
            if (islower(s[i])) {
                cout << s;
                return 0;
            }
        }

        s[0] = toupper(s[0]);
        cout << s[0];
        for (int i = 1; i<s.length(); i++) {
            s[i] = tolower(s[i]);
            cout << s[i];
        }
    } else {
        for (int i=0; i<s.length(); i++) {
            if (islower(s[i])) {
                cout << s;
                return 0;
            }
        }

        transform(s.begin(), s.end(), s.begin(), ::tolower);
        cout << s;
    }
    return 0;
}
```

Versi yang sudah aku perbaiki:

```cpp
#include<iostream>
#include<cctype>
#include<algorithm>
using namespace std;

auto main() -> int {
    string s;
    cin >> s;
    int cnt = 0;
    for (char & c : s) {
        if(isupper(c)) cnt++;
    }

    if (cnt == s.length()) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        cout << s;
    } else if (s.length() - cnt == 1 && islower(s[0])) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        s[0] = toupper(s[0]);
        cout << s;
    } else {
        cout << s;
    }
    return 0;
}
```

<br/>

---
# 2 | Analisis Singkat

Banyak yang mengandalkan kode ASCII untuk memeriksa apakah karakter yang sedang dicek adalah karakter huruf besar atau huruf kecil. Tapi sebenarnya dengan menggunakan library `cctype`, pe\ngecekan tersebut bisa dilakukan dengan menggunakan fungsi `islower()` dan `isupper()`. Bahkan konversi dari kecil ke besar dan sebaliknya juga sudah disedikan fungsinya sendiri, yaitu dengan menggunakan `tolower()` dan `toupper()`.

```cpp
#include<iostream>
#include<regex>
using namespace std;

int i;
main() {
    string s;
    cin >> s;
    if (regex_match(s, regex("[a-z]?[A-Z]*")))
        for(;i < s.size();)
            cout << char(s[i++]^32);
    else
        cout << s;
}
```

```cpp
#include<iostream>
using namespace std;

int main() {
	string s, l = "";
	cin >> s;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] <= 'Z')
			l += char(s[i] + 32);
		else if(i == 0)
			l += char(s[i] - 32);
		else {
			cout << s;
			return 0;
		}
	}
	cout << l;
}
```

```cpp
#include<bits/stdc++.h>

using namespace std;
int main() {
    string a;
    cin >> a;
    int n = a.size(), c = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 97) c++;
    }
    if (c == n || (c == n - 1 && a[0] > 96)) {
        for (int i = 0; i < n; i++) {
            if (a[i] > 96)
                a[i] = a[i] - 32;
            else a[i] = a[i] + 32;
        }
    }
    cout << a;
}
```

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    bool all_upper = true;
    for (int i = 1; i < (int) s.size(); i++)
        if (islower(s[i])) all_upper = 0;
    if (all_upper) {
        for (auto & c: s) c = (islower(c) ? toupper(c) : tolower(c));
        cout << s;
    } else cout << s;
}
```

