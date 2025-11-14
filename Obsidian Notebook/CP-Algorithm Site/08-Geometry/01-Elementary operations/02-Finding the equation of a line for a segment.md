---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Finding the equation of a line for a segment
sumber:
  - CP handbook by Antti Laaksonen
date_learned: 2025-11-05T22:28:00
tags:
  - geometry
  - cp-algorithms
---
Link Sumber: [Finding the equation of a line for a segment - Algorithms for Competitive Programming](https://cp-algorithms.com/geometry/segment-to-line.html)

---
# Finding the equation of a line for a segment

Tugasnya adalah: diberikan koordinat ujung-ujung segmen, konstruksi garis (_construct a line_) yang melaluinya.

Kita mengasumsikan bahwa segmen (_segment_) tersebut non-degeneratif (_non-degenerate_), yaitu memiliki panjang lebih besar dari nol (jika tidak, tentu saja, tak terhingga banyaknya garis berbeda yang melaluinya).

## 1 | Two-dimensional case

Misalkan segmen yang diberikan adalah $PQ$, yaitu koordinat ujungnya yang diketahui adalah $P_x$, $P_y$, $Q_x$, $Q_y$.

Kita perlu mengkonstruksi persamaan garis di bidang (_equation of a line in the plane_) yang melewati segmen ini, yaitu menemukan koefisien $A$, $B$, $C$ dalam persamaan garis:
$$A x + B y + C = 0.$$

Perhatikan bahwa untuk tripel (_triples_) $(A, B, C)$ yang diperlukan, terdapat tak terhingga banyaknya solusi (_infinitely many solutions_) yang mendeskripsikan segmen yang diberikan: Anda dapat mengalikan ketiga koefisien dengan bilangan non-nol sembarang dan mendapatkan garis lurus yang sama. Oleh karena itu, tugas kita adalah menemukan salah satu dari tripel ini.

Mudah untuk diverifikasi (dengan substitusi ekspresi ini dan koordinat titik $P$ dan $Q$ ke dalam persamaan garis lurus) bahwa rangkaian koefisien berikut cocok:

$$\begin{align} A &= P_y - Q_y, \\ B &= Q_x - P_x, \\ C &= - A P_x - B P_y. \end{align}$$

## 2 | Integer case

Keuntungan penting dari metode mengkonstruksi garis lurus (_constructing a straight line_) ini adalah bahwa jika koordinat ujung-ujung segmen adalah integer (_integer_), maka koefisien yang diperoleh juga akan berupa integer. Dalam beberapa kasus, hal ini memungkinkan seseorang untuk melakukan operasi geometris (_geometric operations_) tanpa perlu menggunakan bilangan riil (_real numbers_) sama sekali.

Namun, ada sedikit kekurangan (_drawback_): untuk garis lurus yang sama, dapat diperoleh tripel koefisien yang berbeda. Untuk menghindari hal ini, namun tetap tidak menjauhi koefisien integer, Anda dapat menerapkan teknik (_technique_) berikut, yang sering disebut rasionalisasi (_rationing_):

1. Temukan pembagi persekutuan terbesar (_greatest common divisor_ atau GCD) dari bilangan $|A|$, $|B|$, $|C|$.
2. Kita bagi ketiga koefisien tersebut dengan GCD tersebut.
3. Kemudian kita lakukan normalisasi tanda (_normalization of the sign_): jika $A < 0$ atau $A = 0$ dan $B < 0$, maka kalikan ketiga koefisien dengan $-1$.

Sebagai hasilnya, kita akan sampai pada kesimpulan bahwa untuk garis lurus yang identik (_identical straight lines_), akan diperoleh tripel koefisien yang identik (_identical triples of coefficients_), yang mempermudah pemeriksaan kesamaan garis lurus.

## 3 | Real case

Ketika bekerja dengan bilangan riil (_real numbers_), Anda harus selalu menyadari adanya galat (_errors_).

Koefisien $A$ dan $B$ akan memiliki urutan yang sama dengan koordinat asli, sedangkan koefisien $C$ memiliki urutan kuadrat (_square_) dari koordinat tersebut. Ini sudah bisa menjadi bilangan yang cukup besar, dan, misalnya, ketika kita memotong garis lurus (_intersect straight lines_), mereka akan menjadi lebih besar lagi. Hal ini dapat menyebabkan galat pembulatan (_rounding errors_) yang besar, bahkan ketika koordinat titik ujung hanya berorde $10^3$.

Oleh karena itu, ketika bekerja dengan bilangan riil, disarankan untuk melakukan apa yang disebut normalisasi (_normalization_). Caranya mudah: yaitu, membuat koefisien sedemikian rupa sehingga $A^2 + B^2 = 1$. Untuk melakukan ini, hitung bilangan $Z$:

$$Z = \sqrt{A^2 + B^2},$$

dan bagi ketiga koefisien $A$, $B$, $C$ dengan $Z$.

Dengan demikian, urutan koefisien $A$ dan $B$ tidak akan bergantung pada urutan koordinat masukan (_input coordinates_), dan koefisien $C$ akan memiliki urutan yang sama dengan koordinat masukan. Dalam praktiknya, ini menghasilkan peningkatan signifikan dalam akurasi perhitungan (_significant improvement in the accuracy of calculations_).

Terakhir, kita menyebutkan perbandingan garis lurus (_comparison of straight lines_): pada dasarnya, setelah normalisasi semacam ini, untuk garis lurus yang sama, hanya dua tripel koefisien yang dapat diperoleh: hingga perkalian dengan $-1$. Oleh karena itu, jika kita melakukan normalisasi tambahan (_additional normalization_) dengan mempertimbangkan tanda (jika $A < -\varepsilon$ atau $|A| < \varepsilon$, $B < -\varepsilon$ maka kalikan dengan $-1$), koefisien yang dihasilkan akan unik (_unique_).
## 4 | Three-dimensional and multidimensional case

Sudah dalam kasus tiga dimensi (_three-dimensional case_), tidak ada persamaan sederhana (_no simple equation_) yang mendeskripsikan garis lurus (_straight line_) (garis tersebut dapat didefinisikan sebagai perpotongan dua bidang, yaitu sebuah sistem dua persamaan (_system of two equations_), tetapi ini adalah metode yang tidak nyaman).

Akibatnya, dalam kasus tiga dimensi dan multi dimensi (_multidimensional case_) kita harus menggunakan metode parametrik untuk mendefinisikan garis lurus (_parametric method of defining a straight line_), yaitu sebagai titik (_point_) $p$ dan vektor (_vector_) $v$:

$$p + v t, \quad t \in \mathbb{R}.$$

Artinya, sebuah garis lurus adalah semua titik yang dapat diperoleh dari titik $p$ dengan menambahkan vektor $v$ dengan koefisien (_coefficient_) sembarang.

Konstruksi (_construction_) garis lurus dalam bentuk parametrik (_parametric form_) berdasarkan koordinat ujung-ujung segmen adalah trivial (_trivial_): kita cukup mengambil salah satu ujung segmen sebagai titik $p$, dan vektor dari ujung pertama ke ujung kedua sebagai vektor $v$.
