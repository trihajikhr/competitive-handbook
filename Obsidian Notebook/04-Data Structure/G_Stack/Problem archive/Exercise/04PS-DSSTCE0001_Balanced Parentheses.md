---
obsidianUIMode: preview
note_type: problem set
id_problem: 04PS-DSSTCE0001
judul_problem: Balanced Parentheses
sumber: chatgpt.com
kategori_problem: 🎯 exercise
kesulitan: 🥈 medium
time_complexity: 🟠 O(n)
memory_complexity: 🟠 O(n) ✅ → Stable
status: 🏆 solved
date_solved: 2025-03-07T01:06:00
pendekatan: stack data structure
tags:
  - array
  - data-structure
  - stack
---
Link problem: 

#array #data-structure #stack 

---
# Balanced Parentheses
Time limit: -
Memory limit: -

Diberikan sebuah string yang hanya berisi karakter `'('`, `')'`, `'{'`, `'}'`, `'['`, dan `']'`, tentukan apakah string tersebut memiliki tanda kurung yang seimbang (_balanced_).

### Input
Karakter berupa `'('`, `')'`, `'{'`, `'}'`, `'['`, dan `']'`.
#### Input constraints
\-
### Output
Jika semua tanda kurung memiliki pasangan, maka outputkan `YES`, jika tidak maka `NO`. 
### Examples
Input 1:
```
{[()]}
```

Output 1:
```bash
YES
```

Input 2:
```
{[(])}
```

Output 2:
```bash
NO
```

### Note
\-
# Jawaban
Dengan menggunakan struktur data stack, kita bisa menemukan jawabanya:

```cpp
#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char top = st.top();
            if ((c == ')' && top == '(') ||
                (c == '}' && top == '{') ||
                (c == ']' && top == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string s;
    cout << "Masukkan string: ";
    cin >> s;
    
    if (isBalanced(s)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
```

Time complexity: $O(n)$
Memory complexity: $O(n)$
## Jawaban efektif
// penjelasan singkat

```cpp

```

Time complexity: $O()$
Memory complexity: $O()$
# Editorial 

- Gunakan stack untuk menyimpan karakter `'('`, `'{'`, `'['` saat ditemukan.
- Jika menemukan `')'`, `'}'`, atau `']'`:
    - Periksa apakah stack kosong (jika iya, maka tidak seimbang).
    - Periksa apakah elemen teratas stack adalah pasangan yang benar.
    - Jika tidak cocok, langsung kembalikan **"NO"**.
- Setelah semua karakter diproses, periksa apakah stack kosong. Jika kosong, berarti seimbang (**"YES"**), jika tidak kosong berarti tidak seimbang (**"NO"**).

## Penjelasan dengan Contoh

Misalkan **input** adalah `{[()]}`

- `{` → Masukkan ke stack
- `[` → Masukkan ke stack
- `(` → Masukkan ke stack
- `)` → `(` ada di top stack, jadi hapus `(`
- `]` → `[` ada di top stack, jadi hapus `[`
- `}` → `{` ada di top stack, jadi hapus `{`
- Stack kosong → **"YES"**

Misalkan **input** adalah `{[(])}`

- `{` → Masukkan ke stack
- `[` → Masukkan ke stack
- `(` → Masukkan ke stack
- `]` → **`(` tidak cocok dengan `]`**, langsung return **"NO"**

---

Kode ini bekerja dalam **O(n)** karena kita hanya melakukan operasi push dan pop pada stack satu kali untuk setiap karakter dalam string. 🚀
# Informasi tambahan