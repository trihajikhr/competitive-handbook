---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: lc-66
judul_DEATH: Plus One
teori_DEATH:
sumber:
  - leetcode.com
rating: 1
ada_tips:
date_learned: 2025-11-20T20:14:00
tags:
  - array
  - math
---
Sumber: [Plus One - LeetCode](https://leetcode.com/problems/plus-one/description/)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | Plus One

Diberikan sebuah array, dimana array ini merepresentasikan sebuah angka. Setiap elemen pada array ini, menunjukan nilai digit tertentu, misal elemen ke-$i$ artinya adalah digit ke-$i$ pada angka tersebut. Angka ini tidak diawali oleh $0$, sehingga tenang saja, angka yang diberikan adalah angka yang valid.

Tambahkan satu, ke angka ini, dan kembalikan array hasilnya.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Seharusnya soal ini sederahan. Kita hanya perlu melakukan traversal dari array yang paling belakang, lalu increment atau tambahkan dengan 1. Ketika nilai elemen tersebut awalnya 9, maka sekarang elemen tersebut menjadi 10. Ketika hal ini terjadi, pada angka yang sebenarnya, digit dibagian kiri akan ikut naik sebanyak 1, dan digit sekarang akan menjadi 0.

Jika digit paling kiri adalah 9, dan digit kananya mengalami increment sehingga membuat nilainya menjadi 10, otomatis digit paling kiri ini akan ikut dinaikan. Ketika hal ini terjadi, maka khusus pada bagian paling kiri array, kita perlu menambahkan elemen baru, yaitu elemen 1.

Beriktu kodeku yang sudah cukup efisien.

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       bool next = true;
       for(int i=digits.size()-1; i>=0; i--){
            if(next) digits[i]++;
            if(digits[i]==10){
                digits[i]=0;
                next = true;
                if(i==0){
                    digits.insert(digits.begin(), 1);
                }
                continue;
            }
        return digits;
       }

       return digits;
    }
};
```

Well, kode diatas sudah cukup efisien, `bool` digunakan untuk melakukan pengecekan, apakah masih perlu melakukan increment. Jika tidak, maka perulangan akan langsung berhenti dengan menggunakan `return`, tapi jika tidak, semisal ada kasus angka yang diberikan adalah 999999, maka increment akan terus dilakukan hingga akhir.


<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Tidak ada editorial untuk member non-premium.

## 3.2 | Analisis Pribadi

Well, pendekatan orang lain tidak jauh berbeda, penulisanya sedikit berbeda, namun kebanyakan algoritmanya sama saja, jadi aku tidak akan membuat analisis terlalu jauh. Kodeku juga sudah cukup efisien, karena berjalan dengan kompleksitas waktu $O(n)$ dan kompleksitas ruang $O(n)$ juga.
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size() - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        if(carry) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
```
### 2 | Jawaban Kedua

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i = n - 1; i >= 0; i--) {
            if(digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
```
### 3 | Jawaban Ketiga

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Traverse from last digit to first
        for(int i = n - 1; i >= 0; i--) {
            if(digits[i] < 9) {
                digits[i]++;     // simple increment
                return digits;   // no carry, return result
            }
            digits[i] = 0;       // 9 becomes 0, carry continues
        }
        
        // If we are here, all digits were 9 (e.g. 999 -> 1000)
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
```