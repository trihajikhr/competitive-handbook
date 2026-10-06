---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: lc-28
judul_DEATH: Find the Index of the First Occurrence in a String
teori_DEATH:
sumber:
  - leetcode.com
rating: 1
ada_tips: false
date_learned: 2025-11-20T16:20:00
tags:
  - two-pointers
  - string
  - string-matching
---
Sumber: [Find the Index of the First Occurrence in a String - LeetCode](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | Find the Index of the First Occurrence in a String

Diberikan 2 buah variable string, yaitu `haystack` dan `needle`. Tugasmu adalah menentukan index pertama kemunculan string `needle` pada `haystack`, atau outputkan -1 jika `needle` tidak terdapat pada `haystack`.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Solusinya super duper mudah, karena sudah ada fungsi bawaan dari C++ untuk kasus ini, sehingga jawabanya cukup seperti ini:

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        auto it = haystack.find(needle);
        return it;
    }
};
```

Fungsi `find()` akan mencari indeks pertama kemunculan `needle` pada `hasytack`. Secara otomatis, jika tidak ada kemunculan `needle` pada `haystack`, fungsi `find()` ini akan mengembalikan -1, sehingga semua permintaan problem ini bisa diatasi dengan hanya satu fungsi.

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Hanya member premium yang bisa melihat editorial.

## 3.2 | Analisis Pribadi

Tidak perlu analisis, soal ini cukup mudah.
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};
```
### 2 | Jawaban Kedua

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        
        if(needle.size() == 0){return 0;}
       // if(n<m){return -1;}
        for(int i = 0 ; i <= n-m ; i++){
            bool found = true;
            for(int j = 0; j < m; j++){
               if(haystack[i+j]!= needle[j]){
                    found=false;
                    break;
               }
            }
            if(found){return i;}
        }

        return -1;

    }
};
```
### 3 | Jawaban Ketiga

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
       for(int i = 0; i<haystack.size(); i++)
       {
        if(haystack.substr(i, needle.length()) == needle){
            return i;
        }
       } 
       return -1;
    }
};
```