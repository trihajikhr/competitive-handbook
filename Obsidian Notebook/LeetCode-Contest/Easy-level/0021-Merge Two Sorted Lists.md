---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: lc 21
judul_DEATH: Merge Two Sorted Lists
teori_DEATH: sorting linked list
sumber:
  - leetcode.com
rating: 1
ada_tips: true
date_learned: 2025-11-20T15:39:00
tags:
  - linked-list
  - recursion
---
Sumber: [Merge Two Sorted Lists - LeetCode](https://leetcode.com/problems/merge-two-sorted-lists/)

```ad-tip
title:⚔️ Teori Death Ground

```

<br/>

---
# 1 | Merge Two Sorted Lists

Diberikan 2 buah linked list dengan data yang tidak terurut. Tugasmu adalah membuat sebuah fungsi, yang mana akan menggabungkan dan mengurutkan linked list tersebut menjadi satu, lalu me-return kan head dari linked list yang menampung hasil penggabungan dan pengurutan.

Struktur linked list:

```cpp
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
```

<br/>

---
# 2 | Sesi Death Ground ⚔️

Menurutku, cara yang paling mudah untuk mengurutkan dua linked list adalah dengan memasukan semua data yang ada pada kedua linked list pada sebuah vector, lalu mengurutkan vector tersebut.

Setelah data pada vector diurutkan, maka selanjutnya kita cukup membuat linked list ketiga, yang akan diisi sesuai dengan data yang sudah diurutkan didalam vector, lalu mengembalikan head dari linked list ketiga.

Pendekatan ini ternyata benar, dan berhasil untuk dilakukan:

```cpp
class Solution {
public:
  ListNode * back = nullptr;

  void push_back(ListNode * &list, int value) {
    ListNode * create = new ListNode(value);
    if (list == nullptr) {
      list = create;
      back = create;
      return;
    }

    back->next = create;
    back = create;
  }

  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    vector<int> elem;
    ListNode * temp = list1;
    while (temp) {
      elem.push_back(temp->val);
      temp = temp->next;
    }

    temp = list2;
    while (temp) {
      elem.push_back(temp->val);
      temp = temp->next;
    }

    ranges::sort(elem);
    ListNode * rest = nullptr;
    for (const auto& x : elem) {
      push_back(rest, x);
    }
    return rest;
  }
};
```

Pastikan sudah belajar materi linked list, atau penjelasanku akan tidak bisa dipahami.

Gabungkan dua data yang ada pada dua linked list menjadi satu. Urutkan data tersebut dengan menggunaka fungsi `sort`. Setelah itu aku membuat fungsi `push_back`, yang akan menambahkan data ke ujung dari linked list `rest`. Gunakan juga node bantu yaitu `back`, untuk bisa mengakses ujung dari linkedlist dengan kompleksitas $O(1)$.

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Tidak ada editorial jika bukan pengguna premium.

## 3.2 | Analisis Pribadi

Melihat dari analisis kode pengguna lain, ternyata tidak ada yang menggunakan struktur data bantuan. Justru mereka menggunakan pengecekan, dan melakukan penyisipan data linkedlist kedua ke linkedlist pertama. Jadi kuncinya, mereka mengandalkan penyisipan, dan aku baru sadar, bahwa solusi tersebut ternyata efisien, karena tidak menggunakan memori tambahan.

Oke, noted!

Tapi aku rasa pendekatanku juga tidak terlalu buruk, dan akan kujadikan pendekatan orang lain tersebut sebagai bahan belajar dan referensi kedepanya saja.
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Attach remaining nodes
        if (list1 != nullptr) tail->next = list1;
        else tail->next = list2;

        return dummy->next;
    }
};
```
### 2 | Jawaban Kedua

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        if(list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
```
### 3 | Jawaban Ketiga

```cpp
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1 || !list2)
      return list1 ? list1 : list2;
    if (list1->val > list2->val)
      swap(list1, list2);
    list1->next = mergeTwoLists(list1->next, list2);
    return list1;
  }
};
```