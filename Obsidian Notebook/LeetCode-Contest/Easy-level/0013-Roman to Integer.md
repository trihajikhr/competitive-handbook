---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: lc-13
judul_DEATH: Roman to Integer
teori_DEATH: formula angka romawi
sumber:
  - leetcode.com
rating: 1
ada_tips: true
date_learned: 2025-11-20T13:24:00
tags:
  - hash-table
  - math
  - string
---
Sumber: [Roman to Integer - LeetCode](https://leetcode.com/problems/roman-to-integer/description/)

```ad-tip
title:⚔️ Teori Death Ground
Aku sudah sempat mencoba problem ini beberapa kali, tapi selalu salah. Itu karena aku tidak mencoba memahami bagaimana angka romawi bekerja, dan implementasi yang tepat.

Jika kita ingin menuliskan 2, maka II.
Jika ingin menuliskan 3, maka III.
Tapi jika ingin menuliskan angka 4, kita harus menulis IV, yang artinya 5 dikurangi 1.

Artinya adalah, jika ada karakter romawi yang lebih kecil dari pada digit disebelah kananya, maka digit tersebut berfungsi sebagai pengurang nilai dari digit dikananya.
```

<br/>

---
# 1 | Roman to Integer

AKu kasih simple aja deh soalnya. Diberikan sebuah string berupa angka dalam format romawi. Tugasmu adalah menentukan berapa angka yang dimaksud oleh format tersebut.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Angka romawi bergerak dari besar ke kecil. Artiniya angka terbesar selalu ditaruh paling kiri, dan angka yang lebih kecil, selalu ditaruh paling kanan. 

Tapi terdapat kondisi dimana angka yang lebih kecil diletakan disebelah kiri dari suatu angka yang lebih besar. Jika ditemukan posisi seperti ini, maka angka yang lebih kecil tadi berguna untuk mengurangi nilai asli dari angka disebelah kananya.

Berikut adalah implementasiku:

```cpp
class Solution {
public:
  int romanToInt(string s) {
        unordered_map<char, int> roman = {
          {'I',1},
          {'V',5},
          {'X',10},
          {'L',50},
          {'C', 100},
          {'D', 500},
          {'M', 1000}
        };

    int rest = 0;
    for (int i=0; i<s.length(); i++) {
      if (i != s.length()-1) {
        if (roman[s[i+1]] > roman[s[i]]) {
          rest += roman[s[i+1]] - roman[s[i]];
          i++;
          continue;
        }
      }
      rest += roman[s[i]];
    }
    return rest;
  }
};
```

Setiap angka romawi harus dicek, apakah tetangga sebelah kananya itu lebih besar daripada dirinya. Jika iya, maka angka romawi tersebut hanya digunakan sebagai pengurang dari angka disebelah kananya tadi. implementasi algoritmanya bisa dilihat di baris 16 sampai 22.

Walaupun kode ini di accept, namun bukan merupakan yang paling efisen. Jadi aku harus membedah kode orang lain lagi.

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Tida ada, subscription dibutuhkan!

## 3.2 | Analisis Pribadi

Analisis aku pindahkan kebagian bawah!
## 3.3 | Analisis Jawaban User Lain

Setelah aku lihat jawaban dari user lain, kemungkinan jawaban mereka lebih cepat adalah karena mereka tidak menggunakan data structure untuk menyimpan key dan vlue dari angka romawi seperti yang aku dan jawaban ketiga lakukan. Oke, ini masuk akal, namun tidak efisien jika harus beradu waktu.

Jawaban ketiga mirip dengan jawabanku. Jadi aku mengambil kesimpulan jawabanku sebenarnya sudah efisien.

### 1 | Jawaban Pertama

```cpp
class Solution {
public:

    int decodeTwo(char ch1, char ch2) {
        if (ch1 == 'I') {
            if (ch2 == 'V') {
                return 4;
            } else if (ch2 == 'X') {
                return 9;
            }
        } else if (ch1 == 'X') {
            if (ch2 == 'L') {
                return 40;
            } else if (ch2 == 'C') {
                return 90;
            }
        } else if (ch1 == 'C') {
            if (ch2 == 'D') {
                return 400;
            } else if (ch2 == 'M') {
                return 900;
            }
        }

        return -1;
    }

    int decodeOne(char ch) {
        switch (ch) {
            case 'I':
                return 1;
                break;
            case 'V':
                return 5;
                break;
            case 'X':
                return 10;
                break;
            case 'L':
                return 50;
                break;
            case 'C':
                return 100;
                break;
            case 'D':
                return 500;
                break;
            case 'M':
                return 1000;
                break;
            default: 
                return -1;
                break;
        }

        return -1;
    }

    int romanToInt(string s) {
        int idx = s.size() - 1, sol = 0;
        while (idx >= 0) {
            if (idx >= 1) {
                int two = decodeTwo(s[idx - 1], s[idx]);
                if (two != -1) {
                    sol += two;
                    idx -= 2;
                    continue;
                }
            }

            int one = decodeOne(s[idx]);
            sol += one;
            idx--;
        }

        return sol;
    }
};
```
### 2 | Jawaban Kedua

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int n= s.length();
        int nums=0;
    
        for( int i=0; i<n-1;i++ ){
            if(value(s[i])<value(s[i+1])) {
                nums = nums-value(s[i]);

            }
            else {
              nums = nums+value(s[i]);

            }

        }
        nums=nums+value(s[n-1]);
        return nums; 
    }
    int value( char c){
        switch (c){
            case 'I': {
                return 1;
            }
            break;
            case 'V':{
                return 5;
            }
            break;
            case 'X':{
                return 10;
            }
            case 'L':{
                return 50;
            }
            break;
            case 'C':{
                return 100;
            }
            break;

            case 'D':{
                return 500;
            }
            case 'M':{
                return 1000;

            }        }
            return 0;}
    
};
```
### 3 | Jawaban Ketiga

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10}, 
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        for (int i = 0; i < s.size() - 1; i++) {
            if (roman[s[i]] < roman[s[i + 1]]) {
                res -= roman[s[i]];
            } else {
                res += roman[s[i]];
            }
        }

        return res + roman[s[s.size() - 1]];        
    }
};
```