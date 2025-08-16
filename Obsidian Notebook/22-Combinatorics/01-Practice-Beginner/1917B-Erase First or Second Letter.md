---
obsidianUIMode: preview
note_type: STRIKE
kode_soal: 1917B
judul_STRIKE: Erase First or Second Letter
teori_STRIKE: 
sumber:
  - codeforces
ada_tips?: 
date_learned: 2025-08-14T20:51:00
tags:
  - STRIKE
  - combinatorics
---
Sumber: [Problem - 1917B - Codeforces](https://codeforces.com/problemset/problem/1917/B)

> [!tip] ⚔️ Teori STRIKE:
> 

<br/>

---
# 1 | Erase First or Second Letter

Diberikan sebuah string **s** dengan panjang **n**.  
Kita mendefinisikan dua operasi yang dapat dilakukan pada string tersebut:

1. Hapus karakter **pertama** dari string.
    
2. Hapus karakter **kedua** dari string.
    

Tugas Anda adalah mencari **jumlah string tak kosong yang berbeda** yang dapat dihasilkan dengan menerapkan operasi-operasi tersebut pada string awal **seberapa pun banyaknya kali** (termasuk nol kali), dalam urutan apa pun.

#### Input:  
Setiap pengujian terdiri dari beberapa _test case_. Baris pertama berisi sebuah bilangan bulat **t** (1 ≤ t ≤ 10⁴) — banyaknya _test case_. Deskripsi tiap _test case_ diberikan berikutnya.

- Baris pertama setiap _test case_ berisi sebuah bilangan bulat **n** (1 ≤ n ≤ 10⁵) — panjang string.
    
- Baris kedua setiap _test case_ berisi string **s**. Dipastikan string ini hanya terdiri dari huruf kecil alfabet bahasa Inggris.
    

Dipastikan bahwa jumlah seluruh **n** pada semua _test case_ tidak melebihi 2 × 10⁵.

#### Output:  
Untuk setiap _test case_, keluarkan sebuah bilangan bulat: jumlah string tak kosong yang berbeda yang dapat diperoleh.
<br/>

---
# 2 | Sesi STRIKE ⚔️

#tips-trick 
<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

### Hint
**Hint 1**
Apakah kita perlu menggunakan operasi pertama setelah operasi kedua?

**Hint 2**
Cobalah untuk memfiksasi jumlah operasi pertama yang diterapkan. Berapa banyak string berbeda yang bisa diperoleh?

**Hint 3**
Kapan dua string hasil yang diperoleh bisa sama?

**Hint 4**
Coba perhatikan kemunculan pertama untuk setiap huruf.
### Solusi

Pertama, mari kita lihat bahwa melakukan **operasi kedua** lalu **operasi pertama** itu setara dengan melakukan **operasi pertama** dua kali. Pada kasus pertama, string akan menjadi

$$
s_1 s_2 s_3 \dots s_n \ \rightarrow\ s_1 s_3 \dots s_n \ \rightarrow\ s_3 \dots s_n
$$

dan pada kasus kedua:

$$
s_1 s_2 s_3 \dots s_n \ \rightarrow\ s_2 s_3 \dots s_n \ \rightarrow\ s_3 \dots s_n
$$

Karena kita hanya peduli pada jumlah string berbeda yang dihasilkan, kita bisa mengasumsikan bahwa **operasi kedua tidak pernah dilakukan sebelum operasi pertama**. Ini berarti kita melakukan $op_1$ kali operasi pertama (bisa nol kali) lalu $op_2$ kali operasi kedua (bisa nol kali).

Sekarang mari kita cari hasil dari melakukan $i$ kali operasi pertama lalu $j$ kali operasi kedua. Mudah dilihat bahwa hasilnya adalah

$$
s_{i+1} \ s_{i+j+2} \ s_{i+j+3} \dots s_n
$$

Satu-satunya pertanyaan yang tersisa adalah: dalam kasus apa dua urutan operasi — di mana operasi pertama selalu dilakukan sebelum operasi kedua — menghasilkan string yang sama? Misalkan untuk pasangan $(i_1, j_1)$, string hasilnya sama seperti untuk pasangan $(i_2, j_2)$. Kita bisa melihat bahwa

$$
i_1 + j_1 = i_2 + j_2
$$

karena jumlah huruf yang dihapus harus sama untuk mendapatkan panjang string yang sama. Selanjutnya,

$$
s_{i_1+1} = s_{i_2+1}
$$

karena itu adalah huruf pertama dari dua string hasil yang sama. Mudah dilihat bahwa kedua kondisi ini sudah cukup untuk memastikan hasilnya sama.

Jika setelah melakukan $op_1$ kali operasi pertama huruf pertama yang muncul **bukan kemunculan pertamanya**, maka hasil apa pun berikutnya bisa dicapai juga dengan lebih sedikit operasi pertama: cukup hapus huruf pertama sampai mencapai huruf tersebut, lalu hapus huruf kedua hingga total operasi yang dilakukan sama dengan $op_1$. Ini berarti kita hanya perlu mempertimbangkan penggunaan operasi kedua **pada kemunculan pertama** dari huruf tersebut.

Solusi akhirnya dapat seperti ini: untuk setiap huruf $a \dots z$, temukan kemunculan pertamanya. Jika huruf itu ditemukan, maka setiap jumlah operasi kedua yang valid akan menghasilkan string berbeda. Jadi kita cukup menghitung jumlah operasi kedua yang valid tersebut, lalu menambahkannya ke jawaban.

Implementasi:

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, t;

int main() {
    cin >> t;
    
    while (t--) {
        cin >> n;
        string s;
        cin >> s;
        
        vector<long long> ans(n, 0);
        vector<int> nxt(26, n);
        ans[n - 1] = 1;
        nxt[s[n - 1] - 'a'] = n - 1;
    
        for (int i = n - 2; i >= 0; i--) {
            ans[i] = ans[i + 1] + (nxt[s[i] - 'a'] - i);
            nxt[s[i] - 'a'] = i;
        }
    
        cout << ans[0] << endl;
    }
    return 0;
}
```

## 3.2 | Analisis Pribadi
## 3.3 | Analisis Jawaban User Lain