---
obsidianUIMode: preview
note_type: book theory
judul_materi: Algoritma Exhange Rate atau Pertukaran
sumber:
  - codeforces.com
date_learned: 2026-02-09T00:36:00
tags:
  - number-theory
  - math
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Algoritma Exhange Rate atau Pertukaran
Dalam analisis algoritma, kita sering menjumpai masalah diskret yang melibatkan siklus pertukaran sumber daya: sebuah kondisi di mana konsumsi sejumlah unit akan memberikan pengembalian dalam jumlah yang lebih kecil. Misalkan tersedia $n$ unit sumber daya sebagai modal awal, di mana setiap iterasi proses mengonsumsi $k$ unit namun menghasilkan kembali $r$ unit sisa, dengan batasan bahwa proses hanya dapat berjalan jika unit tersedia tidak kurang dari $k$. Masalah utama yang muncul adalah menentukan batas atas iterasi sebelum sumber daya mencapai titik kritis di bawah ambang batas konsumsi.

Secara intuitif, proses ini dapat dipahami melalui konsep kehilangan bersih (_net loss_). Setiap kali satu siklus dijalankan, sistem tidak kehilangan $k$ unit secara permanen, melainkan hanya selisih antara konsumsi dan pengembalian, yakni $k - r$. Inilah invarian utama dalam sistem tersebut. Namun, batasan krusialnya terletak pada fakta bahwa untuk memulai iterasi ke-$t$, sistem harus memiliki modal minimal $k$ unit, bukan sekadar nilai selisihnya. Secara formal, jika $n_t$ adalah jumlah unit setelah $t$ iterasi, maka berlaku hubungan linear:

$$n_t = n - t(k - r)$$

Iterasi maksimum, $t_{\max}$, tercapai selama unit yang tersisa pada langkah sebelumnya masih mencukupi untuk membiayai satu siklus penuh, atau $n_{t-1} \ge k$. Dengan mensubstitusikan persamaan sebelumnya, kita mendapatkan pertidaksamaan $n - (t-1)(k-r) \ge k$, yang jika disusun ulang akan menghasilkan formula batas atas iterasi sebagai berikut:

$$t_{\max} = \left\lfloor \frac{n - r}{k - r} \right\rfloor$$

Sebagai ilustrasi penerapan formula ini, pertimbangkan skenario mengenai produksi lilin. Jika seseorang memiliki 15 lilin ($n=15$) dan setiap 3 lilin yang terbakar habis dapat diolah kembali menjadi 1 lilin baru ($k=3, r=1$), maka jumlah proses pembuatan ulang yang dapat dilakukan adalah:

$$t_{\max} = \left\lfloor \frac{15 - 1}{3 - 1} \right\rfloor = 7$$

Dengan demikian, total lilin yang terbakar selama seluruh proses adalah jumlah awal ditambah seluruh hasil konversi, yakni $15 + 7 = 22$ lilin. Variasi lain muncul dalam domain ekonomi, seperti pada permasalahan belanja dengan _cashback_. Misalkan sebuah sistem memberikan pengembalian sebesar 1 koin untuk setiap pembelanjaan 10 koin ($k=10, r=1$). Jika seorang pembeli memiliki modal awal 100 koin, maka total daya beli efektifnya dihitung melalui akumulasi modal awal dan jumlah transaksi tambahan:

$$Total = n + \left\lfloor \frac{n - 1}{k - 1} \right\rfloor = 100 + \left\lfloor \frac{100 - 1}{10 - 1} \right\rfloor = 111$$

Angka $n - r$ pada pembilang menunjukkan bahwa nilai pengembalian terakhir $r$ bersifat statis—ia tidak bisa digunakan untuk membiayai dirinya sendiri di muka, sehingga harus dikurangkan dari total kapasitas sebelum dibagi dengan kehilangan bersihnya. Penerapan formula ini juga krusial dalam menentukan residu akhir dari sebuah proses pertukaran. Jika ditanyakan berapa sisa unit yang tidak dapat diproses lagi setelah semua kemungkinan pertukaran dilakukan, kita dapat menggunakan hubungan:

$$n_{\text{akhir}} = n - t_{\max}(k - r)$$

Menggunakan contoh lilin sebelumnya, sisa akhirnya adalah $15 - 7(2) = 1$ lilin. Hasil ini secara konsisten selalu lebih kecil dari nilai ambang batas $k$, yang menandakan bahwa sistem telah mencapai titik henti alami. Pemahaman terhadap invarian $(k - r)$ ini memungkinkan penyelesaian masalah pertukaran dalam kompleksitas waktu konstan $O(1)$, memberikan landasan matematis yang jauh lebih kokoh dan efisien dibandingkan metode simulasi konvensional.