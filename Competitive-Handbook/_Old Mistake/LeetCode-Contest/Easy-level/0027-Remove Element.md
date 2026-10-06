---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: lc-27
judul_DEATH: Remove Element
teori_DEATH: seleksi angka non-target
sumber:
  - leetcode.com
rating: 1
ada_tips: true
date_learned: 2025-11-20T16:06:00
tags:
  - array
  - two-pointers
---
Sumber: [Remove Element - LeetCode](https://leetcode.com/problems/remove-element/description/)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | Remove Element

Diberikan sebuah array bilangan bulat `nums`, dan sebuah integer `val`. Singkirkan semua kemunculan angka `val` pada `nums` secara *in-place*, atau langsung. Urutan dari elemen yang ada pada array boleh berubah. Lalu return banyaknya angka pada pada nums yang tidak sesuai dengan `val`.

Tapi, pastikan bahwa semua elemen non-`val` harus berada pada sisi kiri array. Jika ada $k$ elemen pada array yang bukan `val`, maka angka-angka tersebut harus berada di sisi kiri array, dan sisanya tidak terlalu penting.
 
<br/>

---
# 2 | Sesi Death Ground ⚔️

Solusinya mudah, kita hanya perlu melakukan pengecekan dari depan dan belakang array, misal berikut adalah kodeku yang sudah di acc:

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans = 0, r = nums.size()-1;
        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i] == val){
                swap(nums[i], nums[r--]);
                ans++;
            }
        }

        return nums.size()-ans;
    }
};
```

Terdapat dua indexing yaitu $i$ untuk menunjuk elemen depan, dan $r$ untuk menunjuk elemen belakang.

Ketika kita mengecek angka pada awal array (dari depan), dan mendapati angka tersebut adalah sama dengan `val`, maka lakukan swap, atau pemindahan elemen tersebut ke belakang array. Operasi swap dilakukan terhadap pointer $r$, dan setelah operasi dilakukan, majukan pointer $r$ dengan `r--`, ini memastikan elemen terakhir tidak tertimpa oleh pemindahan selanjutnya. Setiap operasi swap, akan menambah nilai dari `ans`, ini adalah variable counter.

Setelah itu, jumlah elemen non-`val` bisa didapat dengan $nums.size() - ans$.

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Tidak ada editorial, hanya untuk member premium.

## 3.2 | Analisis Pribadi

Solusi ini mudah, jadi tidak perlu dianalisis terlalu jauh.
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};
```
### 2 | Jawaban Kedua

```cpp
class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int i = 0;

    for (const int num : nums)
      if (num != val)
        nums[i++] = num;

    return i;
  }
};
```
### 3 | Jawaban Ketiga

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        
        return k;
    }
};
```