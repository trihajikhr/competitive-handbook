---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal:
judul_DEATH:
teori_DEATH:
sumber:
rating:
ada_tips:
date_learned:
tags:
---
Sumber:

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | Judul

<br/>

---
# 2 | Sesi Death Ground ⚔️

Berikut adalah implementasiku:

```cpp
#include<iostream>
#include<string>
using namespace std;

void solve() {
    int n;
    char c;
    string s;
    cin >> n >> c >> s;
    bool poss = false;
    for (int i=0; i<n; i++) {
        if (s[i] < c) {
            s.insert(i,1,c);
            poss = true;
            break;
        }
    }
    if (!poss) s += c;
    cout << s << '\n';
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

## 3.2 | Analisis Pribadi
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
```
### 2 | Jawaban Kedua

```cpp
```
### 3 | Jawaban Ketiga

```cpp
```