---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: lc-26
judul_DEATH: Remove Duplicates from Sorted Array
teori_DEATH: seleksi angka unik secara in-place
sumber:
  - leetcode.com
rating: 1
ada_tips: true
date_learned: 2025-11-20T15:51:00
tags:
  - array
  - two-pointer
---
Sumber: [Remove Duplicates from Sorted Array - LeetCode](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)

```ad-tip
title:⚔️ Teori Death Ground
Tidak perlu menggunakan set, kita bisa mengecek banyaknya dan mana saja elemen yang unik pada sebuah array secara *in-place*.
```

<br/>

---
# 1 | Remove Duplicates from Sorted Array

Diberikan array bilangan bulat yaitu `nums` yang terurut. Singkirkan elemen duplicate secara *langsung*, menghasilkan array yang hanya terdiri dari elemen-elemen unik. Urutan dari semua elemen yang ada harus tetap sama.

Setelah itu, outputkan nilai $k$, yaitu jumlah angka unik yang tersisa setelah operasi tersebut.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Solusinya mudah, kita tidak perlu membuat array bantuan, ini bisa dilakukan secara *in-place* atau secara langsung:

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[idx] != nums[i]){
                nums[++idx] = nums[i];
            }
        }

        return idx+1;
    }
};
```

Index $idx$ akan memantau berapa banyak elemen unik yang ada pada array, sedangkan index $i$ digunakan untuk melakukan traversal dari awal hingga akhir. Jika ditemukan beberapa elemen yang sama, maka $idx$ hanay diperbarui sekali, sehingga semua elemen unik dari array akan terkumpul di sisi kiri array. Total elemen unik adalah $idx+1$, karena jika semua angka sama, maka pasti hanya ada satu elemen unik.

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Tidak ada editorial untuk pengguna gratis.

## 3.2 | Analisis Pribadi

Soal terlalu mudah untuk perlu dianalis!
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int i = 0;
        int j = 1;

        while(j < nums.size())  //1,
        {
            if(nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }

            //if(nums[i] == nums[j])
            j++;
            
        }

        return i+1;
    }
};
```
### 2 | Jawaban Kedua

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     int n = nums.size();
     int i=0,j=1;
     
     while(j<nums.size())
     {
         if(nums[i]!=nums[j])
         {
             i++;
             nums[i]=nums[j];
         }
         
         j++;
     }
      
        return i+1;
        
    }
};
```
### 3 | Jawaban Ketiga

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int cnt = 1;
        for(int i = 1; i<n; i++)
        {
            if(nums[i] != nums[i-1])
            {
                nums[cnt] = nums[i];
                cnt++;
            }
        }
        return cnt;
    }
};
```