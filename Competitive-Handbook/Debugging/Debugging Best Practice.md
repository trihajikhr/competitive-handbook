# Debugging Best Practice

## Pencegahan

1. Setiap kali menulis kode, lakukan pengujian secara bertahap pada bagian-bagian kecil dari program. Pastikan setiap bagian sudah berjalan dengan benar sebelum melanjutkan ke bagian berikutnya.
   
   Error yang ditemukan setelah seluruh kode selesai ditulis biasanya jauh lebih sulit dilacak dibandingkan error yang muncul segera setelah suatu bagian kode ditambahkan. Dengan menguji kode secara bertahap, sumber error dapat diidentifikasi lebih cepat dan proses debugging menjadi lebih mudah.

## Debugging

1. Semua bug bermula dari sebuah premis sederhana: Sesuatu yang Anda kira benar, ternyata tidak. Cukup tahu saja bahwa menemukan letak kesalahan tersebut sebenarnya bisa menjadi tantangan tersendiri.
2. Coba cek variabel indexing untuk perulangan, terutama perulangan bersarang! Sering terjadi lahan penggunaan variabel index disana!
3. Jika menggunakan fungsi yang memiliki banyak parameter, pastikan untuk mengecek apakah urutan parameter fungsi tersebut sudah benar. Pastikan juga untuk menyamakanya dengan argumen yang dimasukan kedalam fungsi tersebut ketika fungsi tersebut dipanggil.