---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: lc-20
judul_DEATH: Valid Parentheses
teori_DEATH: validitas bracket, cukup pakai stack
sumber:
  - leetcode.com
rating: 1
ada_tips: true
date_learned: 2025-11-20T14:20:00
tags:
  - string
  - stack
---
Sumber: [Valid Parentheses - LeetCode](https://leetcode.com/problems/valid-parentheses/)

```ad-tip
title:⚔️ Teori Death Ground
Jika menemui soal yang meminta untuk mengecek validitas bracket, maka tidak ada yang lebih mudah digunakan selain menggunakan struktur data stack.

Bisa juga digunakan string, atau vector, lalu kita hanya perlu melakukan penambahan dan penghapusan dibagian paling belakang, tapi ini hanya referensi saja.
```

<br/>

---
# 1 | Valid Parentheses

Diberikan sebuah string $s$ yang terdiri dari karakter seperti `(`, `)`, `[`, `]`, `{`, dan `}`. Tugasmu adalah menentukan, apakah input string tersebut valid.

Sebuah string disebut valid, jika:
1. Braket terbuka harus tertutup oleh jenis braket yang sama.
2. Braket terbuka harus tertutup diurutan yang sesuai.
3. Setiap braket tertutup bertangguna jawab untuk satu braket terbuka.
<br/>

---
# 2 | Sesi Death Ground ⚔️

Well, solusi dari soal ini sebenarnya sangat mudah, karena bentuk soal seperti ini kerap digunakan untuk latihan pengenalan struktur data stack.

Berikut adalah solusiku:

```cpp
class Solution {
public:
  bool isValid(string s) {
        stack<char> brack;
        for (char& c : s) {
          if (c=='(' || c=='[' || c=='{') {
            brack.push(c);
          } else {
            if (brack.empty()) return false;
            if (c==')' && brack.top()=='(') brack.pop();
            else if (c==']' && brack.top() == '[') brack.pop();
            else if (c=='}' && brack.top() == '{') brack.pop();
            else return false;
          }
        }

    if (!brack.empty()) return false;
    return true;
  }
};
```

Dan ini adalah solusi yang lebih pendek:

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> input;
        for(char c : s){
            if(c=='[' || c=='{' || c=='(') input.push(c);
            else {
                if(input.empty()) return false;
                char a = input.top();
                if((c==')' && a != '(') || 
                   (c=='}' && a != '{') ||
                   (c==']' && a != '[')
                ) return false;
                else {
                    input.pop();
                }
            }
        }
        return input.empty();
    }
};
```

Kedua cara diatas sudah termasuk efisien.

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Tidak ada editorial untuk pengguna gratis.

## 3.2 | Analisis Pribadi

Aku rasa soal ini tidak perlu dianalisis terlalu jauh.
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s) {
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if(st.empty()) return false;
                if(c == ')' && st.top() != '(') return false;
                if(c == '}' && st.top() != '{') return false;
                if(c == ']' && st.top() != '[') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
```
### 2 | Jawaban Kedua

```cpp
class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st;
        unordered_map<char,char> match={
            {')','('},
            {'}','{'},
            {']','['}
        };

        for(auto& ch: s)
        {
            if( ch=='[' || ch=='{' || ch=='(')
                st.push(ch);
            else
            {
                if(st.empty() || st.top() != match[ch])
                    return false;
                else
                    st.pop();
            }
        }
        return st.empty();
        
    }
};
```
### 3 | Jawaban Ketiga

```cpp
class Solution {
 public:
  bool isValid(string s) {
    stack<char> stack;

    for (const char c : s)
      if (c == '(')
        stack.push(')');
      else if (c == '{')
        stack.push('}');
      else if (c == '[')
        stack.push(']');
      else if (stack.empty() || pop(stack) != c)
        return false;

    return stack.empty();
  }

 private:
  int pop(stack<char>& stack) {
    const int c = stack.top();
    stack.pop();
    return c;
  }
};
```