---
obsidianUIMode: preview
note_type: book theory
judul_materi: Apa itu Multiset
sumber:
  - myself
date_learned: 2026-07-27T20:50:00
tags:
  - data-structures
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Apa itu Multiset

## Overview

`std::multiset` adalah sebuah _associative container_ di dalam _C++ Standard Library_ yang dirancang untuk menyimpan _elements_ secara berurutan. Karakteristik utama yang membedakannya dari `std::set` standar adalah kemampuannya untuk mengizinkan adanya _duplicate elements_, artinya beberapa _elements_ dengan _values_ yang identik dapat disimpan secara bersamaan di dalam _container_ yang sama.

## Karakteristik Utama

- Setiap _element_ di dalam _multiset_ selalu tersimpan dalam keadaan terurut (_sorted_), secara default menggunakan _comparator_ `std::less` yang mengurutkan _elements_ dari nilai terkecil ke terbesar.
- Karena dikategorikan sebagai _associative container_, _elements_ tidak diakses menggunakan _index_ numerik seperti pada `std::vector`, melainkan melalui _iterators_ atau _member functions_ khusus untuk pencarian.    
- Operasi dasar seperti _search_, _insertion_, dan _deletion_ pada _multiset_ berjalan dengan kompleksitas waktu $O(\log n)$, di mana $n$ menyatakan jumlah total _elements_ di dalam _container_.    

## Struktur Internal

Secara implementasi di balik layar, `std::multiset` dibangun di atas struktur data _balanced binary search tree_, yang umumnya menggunakan _Red-Black Tree_. Setiap _node_ di dalam _tree_ menyimpan sebuah _element_, penunjuk ke _parent_ dan _children_, serta informasi tambahan untuk menjaga keseimbangan struktur pohon selama proses modifikasi data.

## Mutabilitas _Elements_

_Elements_ di dalam `std::multiset` bersifat _read-only_ setelah berhasil dimasukkan. Kita tidak diperbolehkan mengubah _value_ dari sebuah _element_ secara langsung melalui _iterator_ karena tindakan tersebut berpotensi merusak properti _sorting order_ yang dijaga oleh _tree_. Apabila diperlukan pembaruan data, prosedur yang harus dilakukan adalah menghapus (_erase_) _element_ lama dan menyisipkan kembali (_insert_) _element_ dengan _value_ yang baru.