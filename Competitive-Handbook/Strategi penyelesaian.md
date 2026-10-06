
## Pemahaman Problem Statement
1. Baca secara perlahan problem statement! Bangun pemahaman dengan lambat tapi pasti, ingat ini, lambat tapi pasti! *Slow is Smooth. Smooth is Fast!*
2. Identifikasi apakah problem merupakan tipe Ad Hoc, jika iya, maka [penyelesaian problem Ad Hoc](Ad%20Hoc%20Problem.md) perlu digunakan!
3. Identifikasi apakah problem tersebut membutuhkan penyelesaian *casework*. Jika iya, maka [penyelesaian casework](Casework.md) dibutuhkan disini.
4. Pahami batasan input $N$! Jika nilainya kecil, maka algoritma dengan kompleksitas yang lebih tinggi bisa digunakan. Selalu amati *constraints* sebelum memutuskan algoritma apa yang akan digunakan untuk menyelesaikan problem.
5. Sederhanakan pernyataan masalah. Ambil kesimpulan dan data yang diberikan tanpa kesalahan sedikitpun! Fokus pada mengetahui semua detail pernyataan masalah sebelum mulai melakukan pemecahan masalah.

## Problem Solving

1. Antisipasi berbagai *edge case*! Tentukan semua kemungkinan *case* (variasi input) atau bentuk-bentuk input yang mungkin! Amati dengan teliti, dan buat penanganan yang sesuai untuk setiap kemungkinan tersebut!
2. Simulasikan perubahan data pada problem yang bisa disimulasikan, dan lakukan observasi pada data tersebut, barangkali terdapat sebuah pola!
3. Perhatikan mana data yang *fixed* atau tidak berubah, dan mana yang akan berubah selama proses berjalanya program.
4. Gunakan metode Polya Problem Solving Method! 

## Implementasi

1. Jika data yang diberikan berpasangan, pastikan untuk berhati-hati saat menggunakan sorting secara terpisah. Pastikan data tetap berpasangan dan tidak kehilangan koneksi.
2. Jika dalam algoritma menggunakan *nested loop*, pastikan untuk SANGAT MEMPERHATIKAN VARIABEL INDEX! Sangat sering kesalahan dan bug kritis terjadi akibat kesalahan pada variabel indexing loop. Perhatikan penggunaan $i$, $j$, dan juga $k$, yang biasanya digunakan sebagai variabel indexing.
3. Jika menggunakan rekursi—terutama pada algoritma *backtracking* atau generatif yang bercabang—pastikan untuk selalu mengubah nilai parameter **langsung di dalam argumen pemanggilan fungsi** (misal: `fn(cur + '(')`). Hindari mengubah variabel lokal terlebih dahulu (misal: `cur += '('`), karena mutasi *in-place* tersebut akan menyebabkan *state pollution* (pencemaran variabel), di mana perubahan nilai dari satu cabang rekursi akan bocor dan merusak eksekusi di cabang rekursi lainnya.

### Debugging

