---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Math Fun Fact
sumber:
tags:
---
---
# Math Fun Fact

Pada materi kali ini, aku akan menjabarkan berbagai macam fakta menarik seputar teori angka dan konsep matematika. Fakta menarik ini hanya menyimpan teori singkat yang mampu dijelaskan dan mudah dipahami dalam waktu singkat. Jika terdapat fakta matematika lain, tapi terlalu panjang atau rumit untuk dijelaskan, maka akan dibuat satu file tersendiri yang menjelaskan konsep tersebut.

## 1. Fakta menarik seputar angka

#### Angka 2
Angka $2$ adalah satu-satunya bilangan genap terkecil yang jika dibagi $2$ menghasilkan bilangan ganjil terkecil dan bilangan tersebut adalah $1$.

#### Produk perkalian array
Untuk mengecek apakah hasil kali sebuah array bisa habis dibagi $k$, kita tidak perlu menghitung produknya (total semua perkalianya). Cukup lihat faktor prima kecil dari $k$ dan apakah faktor-faktor itu sudah “terkumpul” dari elemen-elemen array.

Contoh ringkas:
- $k = 2 →$ cukup ada **satu bilangan genap**
- $k = 3 →$ cukup ada **satu kelipatan 3**
- $k = 5 →$ cukup ada **satu kelipatan 5**
- $k = 4 = 2 \times 2 →$ butuh **dua faktor 2** (entah dari satu bilangan kelipatan 4, atau dari dua bilangan genap)

**Insight CP:**  
Kadang masalah “produk besar” bisa diselesaikan hanya dengan aritmetika modulo dan faktorisasi kecil, tanpa benar-benar menghitung produknya.

#### Angka T Prime
Angka prima adalah angka yang hanya memiliki 2 pembagi, yaitu angka $1$ dan bilangan prima itu sendiri. Contoh angka prima adalah $2,3,5,7,11,13,17,19,23,29,\dots$ dan seterusnya.

Tapi dalam beberapa problem, ada yang disebut dengan angka T Prime, yaitu angka yang hampir seperti angka prima, namun sebenarnya dia masih memiliki tepat satu pembagi. Atau, bisa dibilang, angka T Prime adalah angka yang hanya memiliki $3$ pembagi.

Ciri-ciri dari angka ini adalah:
- Memiliki kuadrat sempurna
- Angka dari kuadrat sempurna tersebut adalah angka prima

Contoh angka T Prime, adalah seperti $4,9,25,49,121,\dots$ dan seterusnya. Kenapa angka ini bisa disebut T Prime, karena angka-angka ini memiliki pembagi berupa angka $1$, dirinya sendiri, dan yang ketiga adalah angka hasil kuadrat. Dari sampel diatas, angka hasil kuadrat yang dimaksud adalah $2,3,5,7,11$. 

Lihat kan... bahwa angka T Prime memiliki 3 pembagi, dan salah satu pembaginya adalah angka hasil kuadrat dari angka tersebut yang ternyata angka tersebut adalah angka prima.