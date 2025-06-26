---
obsidianUIMode: preview
note_type: problem set
id_problem: 04PS-DSST-PS02
judul_problem: Valid parentheses
sumber: leetcode.com
kategori_problem: 📊 problem_statement
kesulitan: 🥉 easy
time_complexity: 🟠 O(n)
memory_complexity: 🟠 O(n) ✅ → Stable
status: 🏆 solved
date_solved: 2025-03-07T02:00:00
pendekatan: stack data structure
tags:
  - data-structure
  - stack
---
Link problem: [Valid Parentheses - LeetCode](https://leetcode.com/problems/valid-parentheses/description/)

---
# Valid Parentheses
Time limit: -
Memory limit: -

Diberikan sebuah string `s` yang hanya berisi karakter `'('`, `')'`, `'{'`, `'}'`, `'['`, dan `']'`, tentukan apakah string masukan tersebut valid.

Sebuah string masukan dianggap valid jika:

- Tanda kurung buka harus ditutup dengan tanda kurung yang memiliki jenis yang sama.
- Tanda kurung buka harus ditutup dalam urutan yang benar.
- Setiap tanda kurung tutup memiliki tanda kurung buka yang sesuai dengan jenis yang sama.

### Input
Karakter kurung yang terdiri dari `'('`, `')'`, `'{'`, `'}'`, `'['`, dan `']'`.
#### Input constraints
- $1 \leq s.length \leq 10^{4}$
- `s` hanya terdiri dari tanda kurung `'()[]{}'`.
### Output
- Jika pasangan sesuai, outputkan `true`.
- Jika pasangan tidak sesuai, outputkan `false`.
### Examples
```
Input: s = "()"
Output: true
```

```
Input: s = "()[]{}"
Output: true
```

```
Input: s = "(]"
Output: false
```

```
Input: s = "([])"
Output: true
```

### Note
\-
# Jawaban
Berikut jawaban lengkapnya:

```cpp
#include<iostream>
#include<stack>
using namespace std;

bool kurungValid(string s){
    stack<char> st;
    for(char c : s){
        if(c=='(' || c=='{' || c=='['){
            st.push(c);
        } else {
            if(st.empty()) return false;
            char top=st.top();
            if((c==')' && top==')') ||
                (c=='{' && top=='}') ||
                (c=='[' && top==']')){
                    st.pop();
                } else {
                    return false;
                }
        } 
    }
    return st.empty();
}

int main(){
    string s;
    cin >> s;

    if(kurungValid(s)){
        cout << "true" << "\n";
    } else {
        cout << "false" << "\n";
    }

    return 0;
}
```

Time complexity: $O(n)$
Memory complexity: $O(n)$
## Jawaban efektif
Karena kita hanya diminta untuk langsung mengisi solusinya di class `solution` yang sudah disediakan dari leetcode, maka:

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s){
            if(c=='(' || c=='{' || c=='['){
                st.push(c);
            } else {
                if(st.empty()) return false;
                char top=st.top();
                if((c==')' && top=='(') ||
                    (c=='}' && top=='{') ||
                    (c==']' && top=='[')){
                        st.pop();
                    } else {
                        return false;
                    }
            } 
        }
    return st.empty();
    }
};

```

Time complexity: $O(n)$
Memory complexity: $O(n)$
# Editorial 
## Pendekatan pertama
Kita menggunakan **HashMap** dan **Stack**. Karena kita mengetahui kombinasi tanda kurung yang valid, kita dapat menginisialisasi pemetaan kombinasi menggunakan **HashMap** sebelum melakukan iterasi pada string masukan.

```cpp
mapping = { ")":"(", "}":"{", "]":"[" }
````

**Stack** hanya akan menyimpan tanda kurung buka. Ketika tanda kurung tutup ditemukan, kita menggunakannya sebagai kunci untuk mencari tanda kurung buka yang sesuai dalam **mapping**. Jika dua tanda kurung tersebut (tanda kurung saat ini dan tanda kurung terakhir di **Stack**) bukan kombinasi yang valid, kita harus mengembalikan `false`.

Pada akhirnya, jika **Stack** kosong, kita mengembalikan `true`.
### Kompleksitas

- **Waktu:** $O(n)$
- **Ruang:** $O(n)$

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> mapping = {{')', '('}, {']', '['}, {'}', '{'}};

        for (char c : s) {
            if (mapping.find(c) == mapping.end()) {
                stack.push(c);
            } else if (!stack.empty() && mapping[c] == stack.top()) {
                stack.pop();
            } else {
                return false;
            }
        }

        return stack.empty();        
    }
};
```

---

## Solusi 2

Kita juga dapat menyelesaikan masalah ini hanya dengan menggunakan **Stack**. Jika **Stack** sudah memiliki tanda kurung, kita dapat memeriksa apakah tanda kurung terakhir dalam **Stack** dan tanda kurung saat ini membentuk pasangan yang valid.

- Jika valid, kita cukup **pop** tanda kurung dari **Stack** dan lanjut ke iterasi berikutnya.
- Jika tidak valid, kita **push** tanda kurung saat ini ke dalam **Stack**.

Pada akhirnya, jika **Stack** kosong, kita mengembalikan `true`.

### Kompleksitas

- **Waktu:** $O(n)$
- **Ruang:** $O(n)$

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char cur : s) {
            if (!st.empty()) {
                char last = st.top();
                if (isPair(last, cur)) {
                    st.pop();
                    continue;
                }
            }
            st.push(cur);
        }

        return st.empty();        
    }

private:
    bool isPair(char last, char cur) {
        return (last == '(' && cur == ')') ||
               (last == '{' && cur == '}') ||
               (last == '[' && cur == ']');
    }
};
```
# Informasi tambahan
Problem ini terbilang cukup mudah, anda hanya perlu memahami struktur data **stack**. Jika belum memahaminya, pelajari terlebih dahulu. 




