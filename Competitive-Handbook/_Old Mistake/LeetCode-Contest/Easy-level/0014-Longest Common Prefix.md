---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: lc-14
judul_DEATH: Longest Common Prefix
teori_DEATH:
sumber:
  - leetcode.com
rating: 1
ada_tips: false
date_learned: 2025-11-20T13:56:00
tags:
  - array
  - string
  - trie
---
Sumber: [Longest Common Prefix - LeetCode](https://leetcode.com/problems/longest-common-prefix/)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | Longest Common Prefix

Tuliskan sebuah fungsi yang akan menemukan prefix string terpanjang yang ada pada seluruh string. Jika tidak ada, maka outputkan "".

<br/>

---
# 2 | Sesi Death Ground ⚔️

2 bulan sebelum submit ini berhasil, aku gagal berkali-kali. Tapi latihanku tidak sia-sia, entah kenapa soal ini sekarang terlihat sangat mudah.

Berikut adalah implementasiku yang sudah efisien, dan beats 100% user:

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int idx = 0;
        while (true) {
            bool pass = true;
            for (int i=0; i<strs.size(); i++) {
                if (idx == strs[i].length() || strs[0][idx] != strs[i][idx]) {
                    pass = false;
                    break;
                }
            }
            if (!pass) break;
            idx++;
        }
        return strs[0].substr(0,idx);
    }
};
```

Kita ambil salah satu string sebagai patokan, disini aku mengambil elemen pertama, yaitu $strs[0]$. Tetapkan $idx$ sebagai variabel indexing, untuk mendeteksi seberapa jauh traversal yang valid dilakukan.

Perulangan while digunakan untuk memajukan variabel $idx$, sedangkan perulangan didalamnya, yaitu for loop, digunakan untuk mengecek, apakah nilai dari $idx$ belum melebihi panjang dari string $strs[i]$, dan juga mengecek apakah $strs[i][idx] \equiv strs[0][idx]$. Jika salah satu kondisi ini tidak terpenuhi, artinya panjang prefix tidak bisa lagi ditingkatkan, sehingga hentikan perulangan, dan return.

Seharusnya ini tidak terlalu sulit, jadi pahami saja kode diatas dengan seksama.

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Tidak bisa, harus subscription!

## 3.2 | Analisis Pribadi

Aku taruh dibawah aja sekalian!
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string pre = strs[0];
        for(int i=1;i<strs.size();i++){
            while(strs[i].find(pre) != 0)
                pre = pre.substr(0, pre.size() - 1);
            if(pre.empty()) break;
        }
        return pre;
    }
};
```

Kode tersebut mencari **longest common prefix** (LCP) atau awalan terpanjang yang sama dari sebuah daftar string. Caranya adalah dengan menganggap string pertama sebagai kandidat prefix, lalu dibandingkan dengan string berikutnya satu per satu. 

Jika string saat ini tidak diawali dengan prefix tersebut, maka prefix akan dipotong satu karakter dari belakang dan dicek lagi. Proses memotong dan mengecek ini terus berlangsung sampai prefix tersebut benar-benar menjadi awalan string tersebut, atau sampai prefix menjadi kosong. 

Setelah itu, program lanjut membandingkan prefix yang sudah dipangkas ini dengan string-string berikutnya. Jika di suatu titik prefix menjadi kosong, berarti tidak ada awalan yang sama di seluruh daftar. Pada akhir proses, nilai prefix yang tersisa itulah yang menjadi hasil longest common prefix.

Perhatikan kode ini sekarang:

```cpp
for(int i=1;i<strs.size();i++){
	while(strs[i].find(pre) != 0)
```

Bagian kode itu melakukan **pemangkasan prefix** sampai benar-benar menjadi awalan dari string yang sedang dicek. Berikut penjelasannya dalam bentuk paragraf formal.

Pada baris `while(strs[i].find(pre) != 0)`, program memeriksa apakah string `strs[i]` _tidak_ diawali oleh `pre`. Fungsi `find(pre)` mengembalikan indeks pertama kemunculan `pre` di dalam `strs[i]`. Jika hasilnya bukan `0`, berarti `pre` bukan berada di posisi awal, sehingga `pre` bukan prefix dari `strs[i]`. Selama kondisi itu masih terjadi, baris `pre = pre.substr(0, pre.size() - 1);` akan dijalankan. Baris ini memotong `pre` satu karakter dari bagian belakang, sehingga setiap iterasi membuat candidate prefix semakin pendek. Proses pemangkasan ini berulang sampai `pre` akhirnya menjadi prefix yang valid (ditandai dengan `find(pre) == 0`), atau sampai `pre` menjadi kosong. Dengan demikian, loop tersebut bertugas menyesuaikan prefix dengan memotongnya sedikit demi sedikit agar sesuai dengan string yang sedang diperiksa.
### 2 | Jawaban Kedua

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string p = strs[0];
        for(int i=1;i<strs.size();i++){
            while(strs[i].find(p) != 0){
                p = p.substr(0, p.size()-1);
                if(p.empty()) return "";
            }
        }
        return p;
    }
};
```
### 3 | Jawaban Ketiga

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int i=1;i<strs.size();i++){
            while(strs[i].find(ans) != 0)
                ans.pop_back();
        }
        return ans;
    }
};
```