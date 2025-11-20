---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: lc-67
judul_DEATH: Add Binary
teori_DEATH:
sumber:
  - leetcode.com
rating: 1
ada_tips:
date_learned: 2025-11-20T20:49:00
tags:
  - math
  - string
  - bit-manipulation
  - simulation
---
Sumber: [Add Binary - LeetCode](https://leetcode.com/problems/add-binary/description/)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | Add Binary

Diberikan sebuah binary string $a$ dan binary string $b$. Tambahkan keduanya, dan tentukan binary string dari hasilnya.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Well, aku memiliki sulosi yang sayangnya bukan solusi yang paling efisien. Kenaap aku bisa tahu? Karena solusi ini menggunakan string ketiga, dan mengharuskan proses reverse untuk membangun string hasil:

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        string rest = "";
        int carry = 0, l = a.length()-1, r = b.length()-1;
        while (l >= 0 || r >= 0 ) {
            if (l >=0) {
                if (a[l] == '1') carry++;

                l--;
            }

            if (r >= 0) {
                if (b[r] == '1') carry++;

                r--;
            }

            if (carry == 0) {
                rest += '0';
            } else if (carry == 1) {
                rest += '1', carry = 0;
            } else if (carry == 2) {
                rest += '0', carry = 1;
            } else if (carry == 3) {
                rest += '1', carry = 1;
            }
        }

        if (carry) rest += '1';
        reverse(rest.begin(), rest.end());
        return rest;
    }
};
```

Aku akan melakukan optimalisasi nanti, tapi algoritma yang digunakan adalah sesimple menyimpan nilai dari `carry` saat ini. Ketika nilai 1 dan 1 bertemu, maka akan menambahkan digit kebagian kiri sebelahnya, atau meng-*carry* 1 digit, sehingga digit sekarang menjadi 0. Tapi jika digit sekarang adalah 1 dan 1, mengcarry 1, dan ternyata digit disebealhanya juga terdiri dari 1 dan 1, maka maka digit disebelahnya akan menjadi 1, dan masih membawa carry lagi.

Intinya pahami bagaimana penjumlaha biner bekerja. Ini seperti penjumlahan pada umumnya, kita hanya bermain dengan pinter, bagaimana cara memainkan angka yang *dicarry* ini.

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Tidak ada editorial untuk member non-premium.

## 3.2 | Analisis Pribadi

Setelah aku coba pikirkan kembali, ada beberapa bagian kode program sebelumnya yang bisa ditingkatkan lagi, menjadi seperti ini:

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        if (a.length() < b.length()) swap(a,b);
        for (int i = 0; i < static_cast<int>(max(a.length(), b.length())); i++) {

            if (static_cast<int>(a.length())-1-i >= 0) {
                if (a[a.length()-1-i] == '1') carry++;
            }

            if (static_cast<int>(b.length())-1-i >= 0 ) {
                if (b[b.length()-1-i] == '1') carry++;
            }

            if (carry == 0) {
                a[a.length()-1-i] = '0';
            } else if (carry == 1) {
                a[a.length()-1-i] = '1', carry = 0;
            } else if (carry == 2) {
                a[a.length()-1-i] = '0', carry = 1;
            } else if (carry == 3) {
                a[a.length()-1-i] = '1', carry = 1;
            }
        }

        if (carry) a.insert(a.begin(), '1');
        return a;
    }
};
```

Mari kita perpendek penggunaan syntax `length()` menjadi `len` dengan menggunakan macro:

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        #define len length()
        int carry = 0;
        if (a.len < b.len) swap(a,b);
        for (int i = 0; i < static_cast<int>(max(a.len, b.len)); i++) {

            if (static_cast<int>(a.len)-1-i >= 0) {
                if (a[a.len-1-i] == '1') carry++;
            }

            if (static_cast<int>(b.len)-1-i >= 0 ) {
                if (b[b.len-1-i] == '1') carry++;
            }

            if (carry == 0) {
                a[a.len-1-i] = '0';
            } else if (carry == 1) {
                a[a.len-1-i] = '1', carry = 0;
            } else if (carry == 2) {
                a[a.len-1-i] = '0', carry = 1;
            } else if (carry == 3) {
                a[a.len-1-i] = '1', carry = 1;
            }
        }

        if (carry) a.insert(a.begin(), '1');
        return a;
    }
};
```

Kita melakukan pembacaan dari belakang dengan menggunakan trik sederhana, yaitu $a[a.len-1-i]$. Selama nilai dari $a.len-1-i \geq 0$ , maka artinya traversal dari belakang secara tidak langsung tersebut masih berada didalam rentang index array. 

Selain itu, peningkatan lain adalah dengan mebangun jawaban secara *in-place*, dengan menggunakan string $a$. Pastikan string $a$ menampung string terpanjang, lakukan operasi pada baris ke 6 untuk memastikan bahwa string $a$ hanya menampung string terpanjang, dan siap untuk digunakan.

Solusi diatas adalah solusi yang efisien, karena *in-place*, tidak ada reverse, tidak ada string bantu, dan algoritmanya sesuai.
## 3.3 | Analisis Jawaban User Lain

Jawaban dari user lain yang masuk ke kategori jawaban yang efisien benar-benar panjang-panjang. Aku pusing lihatnya. Beruntungya jawabanku sudah efisien.

### 1 | Jawaban Pertama

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
string add;
bool append = false;
size_t retlen;
if (a.length() > b.length())
{
	ret = a;
	add = b;
	retlen = a.length();
}
else
{
	ret = b;
	add = a;
	retlen = b.length();
}
for (size_t index = 0; index < add.length(); index++)
{
	if (add.c_str()[add.length() - (index + 1)] == '1')
	{
		ret[retlen - (index + 1)] = ret.c_str()[retlen - (index + 1)] + 1;
	}
	if (ret.c_str()[retlen - (index + 1)] >= '2')
	{
		ret[retlen - (index + 1)] = ret.c_str()[retlen - (index + 1)] - 2;
		if (retlen == (index + 1))
		{
			append = true;
		}
		else
		{
			ret[retlen - (index + 2)] = ret.c_str()[retlen - (index + 2)] + 1;
		}
	}
}
for (size_t index = add.length(); index < ret.length(); index++)
{
	if (ret.c_str()[retlen - (index + 1)] >= '2')
	{
		ret[retlen - (index + 1)] = ret.c_str()[retlen - (index + 1)] - 2;
		if (retlen == (index + 1))
		{
			append = true;
		}
		else
		{
			ret[retlen - (index + 2)] = ret.c_str()[retlen - (index + 2)] + 1;
		}
	}
	else
	{
		break;
	}
}
if (append)
{
	ret = string("1") + ret;
}

return ret;
    }
};
```
### 2 | Jawaban Kedua

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        int previousSum=0;
        int currentIndex=0;
        string finalResult="";
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        while(currentIndex<a.size()&&currentIndex<b.size()){
            int currentSum=(a[currentIndex]=='1'?1:0)+(b[currentIndex]=='1'?1:0)+previousSum;
            if(currentSum==1){
                finalResult.push_back('1');
                previousSum=0;
            }else if(currentSum==2){
                finalResult.push_back('0');
                previousSum=1;
            }else if(currentSum==3){
                finalResult.push_back('1');
                previousSum=1;
            }else{
                finalResult.push_back('0');
                previousSum=0;
            }
            currentIndex++;
        }

        string remainStr=currentIndex==a.size()?b:a;
        while(currentIndex<remainStr.size()){       
            int currentSum=(remainStr[currentIndex]=='1'?1:0)+previousSum;
            if(currentSum==1){
                finalResult.push_back('1');
                previousSum=0;
            }else if(currentSum==2){
                finalResult.push_back('0');
                previousSum=1;
            }else{
                finalResult.push_back('0');
                previousSum=0;
            }
            currentIndex++;
        }

        if(previousSum==1){
            finalResult.push_back('1');
        }
        reverse(finalResult.begin(),finalResult.end());
        return finalResult;
        
    }
};
```
### 3 | Jawaban Ketiga

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
bool append = false;
if (a.length() > b.length())
{
	ret = a;
}
else
{
	ret = b;
	b = a;
}
for (size_t index = 0; index < b.length(); index++)
{
	if (b.c_str()[b.length() - (index + 1)] == '1')
	{
		ret[ret.length() - (index + 1)] = ret.c_str()[ret.length() - (index + 1)] + 1;
	}
	if (ret.c_str()[ret.length() - (index + 1)] >= '2')
	{
		ret[ret.length() - (index + 1)] = ret.c_str()[ret.length() - (index + 1)] - 2;
		if (ret.length() == (index + 1))
		{
			append = true;
		}
		else
		{
			ret[ret.length() - (index + 2)] = ret.c_str()[ret.length() - (index + 2)] + 1;
		}
	}
}
for (size_t index = b.length(); index < ret.length(); index++)
{
	if (ret.c_str()[ret.length() - (index + 1)] >= '2')
	{
		ret[ret.length() - (index + 1)] = ret.c_str()[ret.length() - (index + 1)] - 2;
		if (ret.length() == (index + 1))
		{
			append = true;
		}
		else
		{
			ret[ret.length() - (index + 2)] = ret.c_str()[ret.length() - (index + 2)] + 1;
		}
	}
	else
	{
		break;
	}
}
if (append)
{
	ret = string("1") + ret;
}

return ret;
    }
};
```