---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: lc-83
judul_DEATH: Remove Duplicates from Sorted List
teori_DEATH: seleksi value duplikat pada linkedlist
sumber:
  - leetcode.com
rating: 1
ada_tips: true
date_learned: 2025-11-21T14:04:00
tags:
  - linked-list
---
Sumber: [Remove Duplicates from Sorted List - LeetCode](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | Remove Duplicates from Sorted List

Diberikan sebuah head dari linked list, hapus duplikat pada linked list tersebut, dan hanya menyisakan elemen unik. Linked list yang diberikan sudah dalam keadaan terurut. Return head dari linked list yang sudah diseleksi tadi.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Solusinya mudah, jika semisal suatu node memiliki elemen yang sama dengan node disampingnya, lakukan penghapusan pada note tengah tersebut. Jika kamu sudah belajar penghapusan pada linkedlist, tepatnya pada bagian tengah, seharusnya ini tidak terlalu sulit untuk dibayangkan.

Penghapusan pada node kedua tersebut diikuti dengan reconnect pada node disebelahnya lagi. Lakukan pengecekan lagi, apakah node disampingnya sama atau tidak. Jika tidak sama, maka manjukan node traversal, sehingga node dengan elemen unik akan terkumpul di bagian kiri linked list, menghapus semua node duplikat secara *in-place*.

```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* temp = head;

        while (temp && temp->next) {
            if (temp->val == temp->next->val) {
                ListNode* del = temp->next;
                temp->next = temp->next->next;
                delete del;
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};
```

Tapi entah kenapa, program diatas sepertinya masih belum efisien, karena ada kode lain yang lebih cepat.

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Tidak ada editorial untuk pengguna gratis!
## 3.2 | Analisis Pribadi
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while (curr && curr->next) {
            while (curr->val==curr->next->val) {
                if (!curr->next->next) {
                    curr->next = nullptr;
                    break;
                }
                else curr->next = curr->next->next;
            }
            curr = curr->next;
        }
        return head;
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* slow = head, *fast = head;

        while(fast != nullptr){
            if(fast->val != slow->val){
                slow = slow->next;
                slow->val = fast->val;
            }
            fast = fast->next;
        }
        slow->next = nullptr;

        return head;
    }
};
```
### 3 | Jawaban Ketiga

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* tmp = head;
        if (!head || !head->next) return head;
        while (tmp && tmp->next) {
            if (tmp->val == tmp->next->val) {
                ListNode* del = tmp->next;
                tmp->next = tmp->next->next;
                delete del;
            }
            else {
                tmp = tmp->next;
            }
        }
        return head;
    }
};
```