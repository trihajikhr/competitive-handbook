---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: lc-35
judul_DEATH: Search Insert Position
teori_DEATH:
sumber:
  - leetcode.com
rating: 1
ada_tips: false
date_learned: 2025-11-20T16:40:00
tags:
  - array
  - binary-search
---
Sumber: [Search Insert Position - LeetCode](https://leetcode.com/problems/search-insert-position/description/)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | Search Insert Position

Diberikan sebuah sorted array yang memiki beberapa integer berbeda dan sebuah target value. Kembalikan / return sebuah index dimana target terletak pada array. Jika angka target tidak ada pada array, maka berikan index yang tepat, yang mana seadainya angka terget itu dimasukan, maka array tetap terurut.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Solusinya mudah, karena dikatakan angka tersebut unik, dan sudah terurut, maka jelas harus digunakan algoritma binary search. Tapi C++ sudah memiliki fungsi untuk algoritma ini, sehingga jawaban dari problem ini cukup:
`
```cpp
class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    return ranges::lower_bound(nums, target) - nums.begin();
  }
};
```

Tahu apa kegunaan `ranges::`? gunanya adalah supaya kita bis menuliskan fungsi `lower_bound()` dengan lebih singkat. 

Fungsi `lower_bound()` akan melakukan pengecekan di array `nums`, yang mana akan mencari kemunculan `target` pada array tersebut secara binary search, sehingga fungsi ini hanya bisa digunakan pada data atau array yang sudah terurut (jika tidak, maka hasilnya akan salah). Lower bound akan mencari kemunculan target, dan jika tidak ada, maka akan mengembalikan lokasi index yang tepat seadainya target perlu dimasukan kedalam array.

Intinya butuh tahu kegunaan fungsi `lower_bound()` dan `upper_bound()` untuk bisa memahami bagaimana menggunakan kedua fungsi ini dengan baik dan benar.

Karena kembalian dari fungsi `lower_bound()` masih berupa iterator, dan bukan int, rubah menjadi int dengan dikurangi oleh `nums.begin()`. 

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Tidak ada untuk member non-premium.

## 3.2 | Analisis Pribadi

Intinya bisa pakai fungsi bawaan biar cepat, atau implementasi manual jika ingin belajar menggunakan binary search.
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size();

    while (l < r) {
      const int m = (l + r) / 2;
      if (nums[m] == target)
        return m;
      if (nums[m] < target)
        l = m + 1;
      else
        r = m;
    }

    return l;
  }
};
```
### 2 | Jawaban Kedua

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return left;
    }
};
```
### 3 | Jawaban Ketiga

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int high=nums.size()-1;
        int low=0;
        int mid=0;
        while(high>=low){
            mid=(high+low)/2;
            if(nums[mid]>target){
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                return mid;
            }
        }
        return low;
    }
};
```