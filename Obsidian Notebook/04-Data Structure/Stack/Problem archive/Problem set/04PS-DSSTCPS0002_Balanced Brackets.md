---
obsidianUIMode: preview
note_type: problem set
id_problem: 04PS-DSSTCPS0002
judul_problem: Balanced Brackets
sumber: hackerrank.com
kategori_problem: 📊 problem_statement
kesulitan: 🥈 medium
time_complexity: 🟠 O(n)
memory_complexity: 🟠 O(n) ✅ → Stable
status: 🏆 solved
date_solved: 2025-03-07T02:30:00
pendekatan: stack data structure
tags:
  - array
  - stack
  - data-structure
---
Link problem: [Balanced Brackets \| HackerRank](https://www.hackerrank.com/challenges/balanced-brackets/problem)

#data-structure #stack #array 

---
# Balanced Brackets
Time limit: -
Memory limit: -

Sebuah tanda kurung dianggap sebagai salah satu dari karakter berikut: `(`, `)`, `{`, `}`, `[`, atau `]`.

Dua tanda kurung dianggap sebagai **pasangan yang cocok** jika tanda kurung buka (yaitu `(`, `[`, atau `{`) muncul di sebelah kiri tanda kurung tutup (yaitu `)`, `]`, atau `}`) dengan jenis yang sama. Terdapat tiga jenis pasangan tanda kurung yang cocok: `[]`, `{}`, dan `()`.

Sebuah **pasangan tanda kurung yang cocok tidak seimbang** jika himpunan tanda kurung yang terdapat di dalamnya tidak cocok. Sebagai contoh, `{[(])}` tidak seimbang karena isi di antara `{` dan `}` tidak seimbang. Pasangan tanda kurung siku `[]` mengapit tanda kurung buka yang tidak cocok `(`, dan pasangan tanda kurung `()` mengapit tanda kurung tutup siku `]` yang tidak cocok.

Berdasarkan logika ini, sebuah rangkaian tanda kurung disebut **seimbang** jika memenuhi kondisi berikut:

1. Tidak ada tanda kurung yang tidak memiliki pasangan.
2. Semua subset tanda kurung yang berada dalam batasan pasangan tanda kurung yang cocok juga merupakan pasangan tanda kurung yang cocok.

Diberikan beberapa string tanda kurung, tentukan apakah setiap urutan tanda kurung tersebut **seimbang**. Jika sebuah string seimbang, kembalikan `"YES"`, jika tidak, kembalikan `"NO"`.
## Deskripsi Fungsi

Lengkapi fungsi `isBalanced` dalam editor di bawah.
#### Parameter
- `string s`: sebuah string yang berisi tanda kurung.
#### Return
- `string`: `"YES"` jika string seimbang, jika tidak, `"NO"`.
### Input
- Baris pertama berisi satu bilangan bulat `n`, yaitu jumlah string.
- Setiap dari `n` baris berikutnya berisi satu string `s`, yaitu urutan tanda kurung.
#### Input constraints
- $(1 \leq n \leq 10^3)$
- $(1 \leq |s| \leq 10^3)$, di mana $(|s|)$ adalah panjang string.
- Semua karakter dalam string termasuk dalam himpunan { **{, }, (, ), [, ]** }.
### Output
Untuk setiap string, kembalikan `"YES"` jika seimbang, dan `"NO"` jika tidak.
### Examples
Input:
```
3 
{[()]} 
{[(])} 
{{[[(())]]}}
```

Output:
```bash
YES 
NO 
YES
```

**Penjelasan:**
1. String `{[()]}` memenuhi kedua kriteria untuk menjadi string yang seimbang.
2. String `{[(])}` **tidak** seimbang karena tanda kurung yang berada di dalam `{` dan `}` tidak seimbang: `[(])`.
3. String `{{[[(())]]}}` memenuhi kedua kriteria untuk menjadi string yang seimbang.
### Note
\-
# Jawaban
Di hackerrank, kita hanya diminta untuk melengkapi fungsi `isBalanced` saja. Tetapi, supaya lebih rapi, hapus semua template yang sudah terpasang di sana, dan kita tulis kembali dari awal.

```cpp
#include<iostream>
#include<stack>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0); cin.tie(0);

bool balancedBrackets(string s){
    stack<char> st;
    for(char c : s){
        if(c=='(' || c=='{' || c=='['){
            st.push(c);
        } else {
            if(st.empty()) return false;
            char top=st.top();
            if((c==')' && top=='(')||
            (c=='}' && top=='{')||
            (c==']' && top=='[')){
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

int main(){
    fastio();
    
    int n; 
    cin >> n;
    string s;
    
    while(n--){
        cin >> s;
        
        if(balancedBrackets(s)){
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
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
Problem set ini hampir sama dengan problem set sebelumnya. 
### Pendekatan
Kode ini memeriksa apakah sebuah string yang berisi tanda kurung `{}`, `[]`, `()` merupakan **balanced brackets** atau tidak. Pendekatan yang digunakan adalah **Stack**, karena sesuai dengan prinsip **LIFO (Last In, First Out)** yang memungkinkan kita melacak pasangan tanda kurung secara efisien.

### Penjelasan Kode
1. **Fungsi `balancedBrackets(string s)`**  
   - Menggunakan `stack<char>` untuk menyimpan tanda kurung yang belum berpasangan.
   - Jika karakter saat ini adalah tanda kurung buka `(`, `{`, atau `[`, maka dimasukkan ke dalam stack.
   - Jika karakter saat ini adalah tanda kurung tutup `)`, `}`, atau `]`:
     - Cek apakah stack kosong, jika iya, berarti **tidak seimbang** → return `false`.
     - Ambil elemen teratas stack (`st.top()`) dan periksa apakah cocok dengan tanda kurung tutup yang bersangkutan.
     - Jika cocok, hapus elemen dari stack (`st.pop()`), jika tidak cocok → return `false`.
   - Setelah iterasi selesai, string valid jika stack kosong (tidak ada tanda kurung tersisa).

2. **Fungsi `main()`**
   - Menggunakan `fastio()` untuk optimasi I/O.
   - Membaca jumlah test case `n`.
   - Untuk setiap string input, memanggil `balancedBrackets(s)`, lalu mencetak `"YES"` jika seimbang, `"NO"` jika tidak.

### Kompleksitas Waktu
- **O(n)** per string, karena setiap karakter hanya diproses sekali (baik dimasukkan atau dihapus dari stack).
- **O(n)** penggunaan ruang (stack) dalam kasus terburuk jika semua tanda kurung buka disimpan.

### Contoh
#### Input
```
3 
{[()]} 
{[(])} 
{{[[(())]]}}
```
#### Output
```
YES 
NO 
YES
```
#### Penjelasan
1. `{[()]}` → **Balanced** ✅
2. `{[(])}` → **Unbalanced** ❌ (karena `[` ditutup oleh `)` bukan `]`)
3. `{{[[(())]]}}` → **Balanced** ✅

Kode ini efisien dan cukup sederhana untuk menangani berbagai kasus dengan pendekatan berbasis **Stack**.
# Informasi tambahan