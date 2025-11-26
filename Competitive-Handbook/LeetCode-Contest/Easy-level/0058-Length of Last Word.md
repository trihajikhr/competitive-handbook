---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: lc-58
judul_DEATH: Length of Last Word
teori_DEATH:
sumber:
  - leetcode.com
rating: 1
ada_tips:
date_learned: 2025-11-20T19:20:00
tags:
  - string
---
Sumber: [Length of Last Word - LeetCode](https://leetcode.com/problems/length-of-last-word/description/)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | Length of Last Word

Diberikan sebuah string $s$ yang terdiri dari beberapa kata. Tentukan panjang dari kata terarkhir dari string yang diberikan.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Ada beberapa solusi untuk masalah ini, pertama kita bisa memanfaatkan library `sstream`, dan menggunakan fungsi `stringstream`. Cukup terima inputan $s$, dan filter hingga mencapai kata terakhir, setelah itu return panjang kata terakhir tersebut, misal seperti ini:

```cpp
class Solution {
public:
  int lengthOfLastWord(string s) {
      stringstream ss(s);
      string prev;
      while (ss >> prev);
      return prev.length();
  }
};
```

Namun, harusnya ada solusi yang lebih cepat dan efisien, karena solusi diatas ternyata masih kurang cepat.

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Tidak ada editorial disini.

## 3.2 | Analisis Pribadi

Aku taruh sekalian dibawah!
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1;
        int j=0;
        
        while(i >=0 && s[i]== ' '){
            i--; // remove extra space if any
        }
        
        while(i>=0 && s[i] != ' '){
            j++;
            i--;
        }

        return j;
    }
};
```

Jenius! Kode diatas secara langsung melakukan traversal dari belakang string, ailh-alih dari depan. Perulangan while pertama digunakan untuk menghapus karakter spasi yang ada dibelakang string jika ada. Setelah karakter spasi dibersihakn, maka ketika karakter terakhjir dari string terindex, perulangan while berhenti.

Masuk ke perulangan while kedua. Disini program melakukan traversal pada kata terakhir. Perulangan berhenti ketika spasi yang memisahkah kata terakhir dan kata sebelum terakhir terindex. Setelah itu, return-kan variabel counter $j$, untuk mengoutputkan panjang kata terakhir.
### 2 | Jawaban Kedua

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while (~i && s[i] == ' ') {
            --i;
        }
        int j = i;
        while (~j && s[j] != ' ') {
            --j;
        }
        return i - j;
    }
};
```

Syntax `~i` digunakan sebagai pengganti `i != -1`. Jelas? Jangan terlalu diambil pusing, aku akan membuat materi tentang ini dibagian terpisah!
### 3 | Jawaban Ketiga

```cpp
class Solution {
public:
    int lengthOfLastWord(const string& s) {
          int i = s.length() - 1, length = 0;

    // Skip trailing spaces
    while (i >= 0 && s[i] == ' ') i--;

    // Count length of last word
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;

    }
};
```