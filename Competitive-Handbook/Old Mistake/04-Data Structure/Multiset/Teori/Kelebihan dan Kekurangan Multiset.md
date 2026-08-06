---
obsidianUIMode: preview
note_type: book theory
judul_materi: Kelebihan dan Kekurangan Multiset
sumber:
  - myself
date_learned: 2026-07-27T20:54:00
tags:
  - data-structures
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Kelebihan dan Kekurangan Multiset

## Kelebihan (_Advantages_)

- Pengelolaan _duplicates_: `std::multiset` secara natif mengizinkan penyimpanan _duplicate elements_, sehingga kita tidak perlu repot mengelola _frequency map_ manual menggunakan `std::map` untuk kasus tertentu.    
- Otomatis terurut: Semua _elements_ selalu berada dalam keadaan _sorted_ secara _default_ saat proses _insertion_, memudahkan pengambilan data terurut tanpa perlu memanggil algoritma `std::sort` terpisah.    
- Kompleksitas waktu yang efisien: Operasi _search_, _insertion_, dan _deletion_ dijamin berjalan dalam kompleksitas waktu $O(\log n)$ berbasis _Balanced Binary Search Tree_.    
- Dukungan _range queries_: Menyediakan _member functions_ yang sangat optimal untuk pencarian batas seperti `lower_bound()`, `upper_bound()`, dan `equal_range()` guna mendeteksi rentang _elements_ yang bernilai sama.    

## Kekurangan (_Disadvantages_)

- _Overhead_ memori: Implementasi _node-based_ memerlukan tambahan memori untuk penunjuk _pointer_ ke _parent_, _children_, dan metadata _Red-Black Tree_ di setiap _node_, yang jauh lebih boros dibanding _contiguous storage_ seperti `std::vector`.
- Tidak ada _random access_: _Elements_ tidak dapat diakses secara langsung menggunakan _index_ dalam waktu $O(1)$. Akses memerlukan _traversal_ iterator atau pencarian logaritmik.
- Buruk untuk _cache locality_: Karena _nodes_ tersebar di berbagai alokasi memori _heap_, performa pembacaan data sering kali mengalami _cache misses_ yang tinggi dibandingkan struktur data berbasis _array_.
- _Immutability_ nilai: _Values_ dari _elements_ tidak dapat dimodifikasi langsung karena akan merusak properti _sorting_. Mengubah _value_ wajib melalui prosedur _erase_ diikuti _insert_.