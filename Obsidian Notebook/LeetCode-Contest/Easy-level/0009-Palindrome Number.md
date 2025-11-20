---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: lc-9
judul_DEATH: Palindrome Number
teori_DEATH:
sumber:
  - leetcode.com
rating: 1
ada_tips:
date_learned: 2025-11-20T12:45:00
tags:
  - math
---
Sumber: [Palindrome Number - LeetCode](https://leetcode.com/problems/palindrome-number/description/)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | Palindrome Number

Diberikan sebuah angka $x$, kembalikan `true` jika angka tersebut polindrome, dan `false` jika tidak.

> Polindrome adalah susunan karakter, yang jika dibaca dari depan atau belakang sama. Contoh polindrome: makam, natan, 10501.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Well, cara yang paling mudha menurutku, adalah dengan mengkonversi angka tersebut menjadi string, dan melakukan pencarian dengan cara mengindeks dari depan dan belakang, dan menurutku ini adalah cara anti ribet:

```cpp
bool isPalindrome(int x) {  
  string s = to_string(x);  
  for(int i=0; i<s.length()/2; i++){  
    if(s[i] != s[s.length()-i-1]){  
      return false;  
    }  
  }  
  return true;  
}
```

Cara diatas bukan cara tercepat, jadi aku berpikir bahwa pendekatan yang lebih baik mungkin dengan tidak melakukan konversi, seperti ini:

```cpp
  bool isPalindrome2(int x) {
    if (x < 0) return false;
    vector<int> data;
    while (x > 0) {
      int temp = x % 10;
      data.push_back(temp);
      x /= 10;
    }

    for (int i=0; i<data.size()/2; i++) {
      if (data[i] != data[data.size()-i-1]) {
        return false;
      }
    }
    return true;
  }
```

Tapi ternyata tidak membantu, justru lebih buruk. Oke, kedua solusi diatas bisa digunakan, tapi ada cara yang lebih efektif.

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Dikunci, karena bukan member premium.

## 3.2 | Analisis Pribadi

Oke, aku menggunakan jawaban orang lain yang lebih efisien sebagai bahan analisis. Jadi, analisisku aku pindah kebawah.
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) 
            return false;

        int rev = 0;

        while (x > rev) {
            int digit = x % 10;
            rev = rev * 10 + digit;
            x /= 10;
        }

        return (x == rev || x == rev / 10);
    }
};
```

Jika $x$ negatif, maka otomatis dia bukan palindrome, karena terdapat tanda `-` dibagian depan. Jika $x$ habis dibagi dengan 10, maka jelas dia bukan polindrome, karena hanya angka yang memiliki digit terakhir 0 yang bisa dibagi habis oleh 10. Dan jika angka tersebut memiliki digit belakang 0, otomatis digit pertama juga harus 0, yang mana ini tidak mungkin valid untuk sebuah angka. Satu-satunya angka yang palindrome jika ada digit terakhirnya adalah 0, adalah jika angka tersebut adalah 0 itu sendiri.

Ada hal yang menarik dari kode ini:

```cpp
rev = rev * 10 + digit;
```

Kode ini akan membangun ulan angka tersebut, tapi dengan urutan yang terbalik. Misal aku memiliki angka $123$, maka algoritma ini akan menyusun angka tersebut menjadi $321$. Lalu jika angka tersebut palindrome, maka operasi berikut:

```cpp
int rev = 0;

while (x > rev) {
	int digit = x % 10;
	rev = rev * 10 + digit;
	x /= 10;
}
```

akan berhenti tepat di digit tengah angka. Dan jika $rev \equiv x$, maka jelas dia palindrome. Kondisi $x \equiv rev / 10$, terjadi ketika angka $x$ memiliki susunanan seperti $232$. Ketika angka ini dioperasikan dengan algoritma diatas, maka $rev$ akan menyimpan angka $23$, dan $x$ adalah $2$. Ketika $23/10$, maka hasilnya adalah $2$, karena angka yang dibagi adalah integer. Sehingga operasi $x \equiv \frac{rev}{10}$.
### 2 | Jawaban Kedua

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) 
            return false;

        int rev = 0;

        while (x > rev) {
            int digit = x % 10;
            rev = rev * 10 + digit;
            x /= 10;
        }

        return (x == rev || x == rev / 10);
    }
};
```
### 3 | Jawaban Ketiga

```cpp
class Solution {
public:
    long int palindrome(int x){
        long int rev=0;
        int dig;
        while(x!=0){
            dig=x%10;
            x/=10;
            rev=rev*10+dig;
        }
        return rev;
    }
    bool isPalindrome(int x) {
        if (x<0||x%10==0&&x>=10){
            return 0;
        }
        if (x==palindrome(x)){
            return 1;
        }
        else{
            return 0;
        }
        
    }
};
```