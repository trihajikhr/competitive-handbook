---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: lc-1
judul_DEATH: Two Sum
teori_DEATH: hitung pasangan indeks yang jumlahnya sama dengan target secara efisien
sumber:
  - leetcode.com
rating: 1
ada_tips: true
date_learned: 2025-11-20T12:16:00
tags:
  - array
  - hashtable
---
Sumber: [Two Sum - LeetCode](https://leetcode.com/problems/two-sum/description/)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | Two Sum

Diberikan sebuah array bilangna bulat yaitu `nums`, dan sebuah angka integer yaitu `target`. Tugasmu mudah, return 2 indeks pada array `nums`, yang jika kedua elemen dari indeks tersebut dijumlahkan, maka hasilnya adalah sama dengan `target`, atau $nums[i] + nums[j] \equiv target$.

Dipastikan akan ada satu solusi dari problem ini, dan urutan indek yang direturn dibebaskan.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Well, mudah mengatasi problem ini dengan menggunakan algoritma brute force, yaitu dengan menggunakan 2 nested loops. Solusi ini bisa digunakan:

```cpp
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> rest (2);
    for (int i=0; i<nums.size()-1; i++) {
        for (int j=i+1; j<nums.size(); j++) {
          if (nums[i] + nums[j] == target) {
            rest[0] = i, rest[1] = j;
            return rest;
          }
        }
      }
    return rest;
  }
};
```

Namun, masih ada solusi yang lebih efisien.

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

### 1. Brute Force

Pendekatan brute force sangatlah simple. Lakukan loop untuk setiap elemen, dan cari nilai dimana $nums[i]+nums[j] \equiv target$.

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == target - nums[i]) {
                    return {i, j};
                }
            }
        }
        // Return an empty vector if no solution is found
        return {};
    }
};
```

Kompleksitas waktu: $O(n^2)$, kompleksitas ruang: $O(1)$.

### 2. Two-pass Hash Table

**Intuisi**

Untuk meningkatkan kompleksitas waktu, kita membutuhkan cara yang lebih efisien untuk memeriksa apakah suatu _complement_ ada di dalam array. Jika _complement_ tersebut ada, kita perlu mengetahui indeksnya. Apa cara terbaik untuk menyimpan pemetaan antara setiap elemen dalam array dengan indeksnya? Sebuah _hash table_.

Kita dapat mengurangi waktu pencarian dari $O(n)$ menjadi $O(1)$ dengan menukar ruang dengan kecepatan. _Hash table_ sangat cocok untuk tujuan ini karena ia mendukung pencarian yang cepat dalam waktu yang hampir konstan. Saya mengatakan “hampir” karena jika terjadi _collision_, pencarian bisa memburuk menjadi $O(n)$. Namun, pencarian dalam _hash table_ seharusnya tetap $O(1)$ secara _amortized_ selama fungsi hash yang digunakan dipilih dengan baik.

**Algoritma**

Implementasi sederhana menggunakan dua iterasi. Pada iterasi pertama, kita menambahkan nilai setiap elemen sebagai _key_ dan indeksnya sebagai _value_ ke dalam _hash table_. Lalu, pada iterasi kedua, kita memeriksa apakah _complement_ dari setiap elemen ($target − nums[i]$) ada dalam _hash table_. Jika ada, kita mengembalikan indeks elemen saat ini dan indeks _complement_-nya. Perhatikan bahwa _complement_ tersebut tidak boleh merujuk pada $nums[i]$ itu sendiri.

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            int comple = target - nums[i];
            if (hash.find(comple) != hash.end() && hash[comple] != i) {
                return {i, hash[comple]};
            }
        }
        // If no valid pair is found, return an empty vector
        return {};
    }
};
```

Komplesitas waktu: $O(n)$, kompleksitas ruang: $O(n)$.

### 3. One-pass Hash Table

**Algorithm**

Ternyata kita dapat melakukannya dalam satu kali iterasi. Saat kita melakukan iterasi dan memasukkan elemen ke dalam _hash table_, kita juga sekaligus memeriksa ke belakang apakah _complement_ dari elemen saat ini sudah ada di dalam _hash table_. Jika sudah ada, berarti kita telah menemukan solusinya dan dapat langsung mengembalikan indeks-indeks tersebut.

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (hash.find(complement) != hash.end()) {
                return {hash[complement], i};
            }
            hash[nums[i]] = i;
        }
        // Return an empty vector if no solution is found
        return {};
    }
};
```

## 3.2 | Analisis Pribadi

Well, ternyata hash table sangat efisien, sehingga aku menggunakan solusi ini:

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (hash.find(complement) != hash.end()) {
                return {hash[complement], i};
            }
            hash[nums[i]] = i;
        }
        // Return an empty vector if no solution is found
        return {};
    }
};
```
## 3.3 | Analisis Jawaban User Lain
### 1 | Jawaban Pertama

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;

        for(int i = 0; i < nums.size(); i++)
        {
            int val = target - nums[i];
            if(umap.find(val) != umap.end())
            {
                return {umap[val], i};
            }
            umap[nums[i]] = i;
        }

        return {-1, -1};
    }
};
```
### 2 | Jawaban Kedua

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> t;
        for(int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int y = target - x;
            if(t.count(y))
                return {t[y], i};
            t[x] = i;
        }
        return {}; 
    }
};
```
### 3 | Jawaban Ketiga

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> pairs;
        for (int i = 0; i < nums.size(); i++) {
            if (pairs.contains(nums[i])) {
                return {pairs[nums[i]], i};
            }
            pairs[target - nums[i]] = i;
        }
        return {0,0};
    }
};
```