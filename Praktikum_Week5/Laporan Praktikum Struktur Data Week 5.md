## 1. Nama, NIM, Kelas
- **Nama**: Ichya Ulumiddiin
- **NIM**: 103112400076
- **Kelas**: Teknik Informatika 12-05

## 2. Motivasi Belajar Struktur Data

Belajar struktur data itu sebenarnya bukan cuma soal menghafal teori atau koding semata, tapi tentang melatih cara berpikir kita supaya lebih runtut, efisien, dan logis. Bayangkan saja kalau data itu seperti barang di gudang kalau ditata sembarangan pasti susah dicari, tapi kalau disusun pakai sistem, semua jadi cepat, mudah, dan teratur. Dengan menguasai struktur data, kita jadi punya bekal penting buat menyelesaikan masalah dalam pemrograman maupun kehidupan sehari-hari, karena pola pikirnya terbawa untuk mencari solusi paling efektif. Jadi, meskipun kadang terasa rumit di awal, anggap saja setiap materi adalah investasi kecil yang nantinya bikin kita lebih siap menghadapi tantangan di dunia teknologi.

## 3. Dasar Teori

Struktur data adalah cara untuk menyimpan dan mengorganisir data dalam komputer agar dapat digunakan secara efisien. Berikut adalah teori dasar mengenai **Single Linked List** dan **Double Linked List**:

- **Linked List**: adalah sebuah struktur data dinamis yang digunakan untuk menyimpan sekumpulan data. Berbeda dengan _array_ yang menyimpan elemen-elemennya di lokasi memori yang berdekatan (kontigu), _linked list_ terdiri dari serangkaian _node_ (simpul) yang tersebar di memori. Setiap _node_ dalam _linked list_ setidaknya memiliki dua bagian:
	1. **Data** (`info`): Menyimpan nilai dari elemen (misalnya: integer, string, dll).
	2. **Pointer** (`next`): Sebuah penunjuk alamat yang menunjuk ke _node_ berikutnya dalam rangkaian.
	_Node_ terakhir dalam _linked list_ akan memiliki _pointer_ `next` yang menunjuk ke **NULL** (atau `Nil` dalam implementasi ini), yang menandakan akhir dari senarai.
	
- **Double Linked List**: **Doubly Linked List (DLL)** adalah pengembangan dari _Singly Linked List_. Perbedaan utamanya adalah setiap _node_ pada DLL memiliki **dua pointer**:
	1. **`next`**: Pointer yang menunjuk ke _node_ setelahnya.
	2. **`prev`**: Pointer yang menunjuk ke _node_ sebelumnya.

- **Header List**: Untuk mengelola _linked list_ secara efisien, sebuah struktur _header_ (`List`) digunakan. Struktur ini tidak menyimpan data, melainkan hanya dua _pointer_ yang sangat penting:
	1. **`first`**: Pointer yang _selalu_ menunjuk ke _node_ pertama dalam list.
	2. **`last`**: Pointer yang _selalu_ menunjuk ke _node_ terakhir dalam list.

- **Manajemen Memori Dinamis**: _Linked list_ bersifat dinamis, artinya ukurannya dapat bertambah atau berkurang saat program berjalan. Ini dicapai dengan alokasi dan dealokasi memori di _heap_.
	- **Alokasi (`alokasi(x)`)**: Fungsi ini menggunakan operator `new` di C++ untuk meminta sepotong memori dari sistem operasi yang cukup untuk sebuah _node_ baru (`elmlist`). Setelah memori didapat, fungsi ini mengisi `info` _node_ dengan data `x` dan menginisialisasi _pointer_ `next` dan `prev` ke `Nil`.
	- **Dealokasi (`dealokasi(P)`)**: Fungsi ini menggunakan operator `delete` untuk mengembalikan memori yang ditunjuk oleh _pointer_ `P` ke sistem operasi. Ini adalah langkah krusial untuk mencegah **kebocoran memori** (_memory leak_), di mana memori yang sudah tidak terpakai tetap "dipesan" dan tidak dapat digunakan oleh bagian lain dari program.

- **Operasi Pada Double Linked List**:  Operasi dasar pada DLL melibatkan manipulasi _pointer_ `next` dan `prev` untuk menjaga integritas dan urutan _list_.
	#### 1. Operasi Penyisipan (Insertion)
	1. **`insertFirst(L, P)`**: Menyisipkan _node_ `P` di awal _list_. Ini melibatkan pembaruan `L.first` dan _pointer_ `prev` dari _node_ pertama yang lama (jika ada).
	2. **`insertLast(L, P)`**: Menyisipkan _node_ `P` di akhir _list_. Ini melibatkan pembaruan `L.last` dan _pointer_ `next` dari _node_ terakhir yang lama (jika ada).
	3. **`insertAfter(L, P, R)`**: Menyisipkan _node_ `P` tepat _setelah_ _node_ `R`. Ini adalah operasi "sambung" yang melibatkan 4 pembaruan _pointer_ untuk menghubungkan `P` di antara `R` dan _node_ setelah `R`.
	4. **`insertBefore(L, P, R)`**: Menyisipkan _node_ `P` tepat _sebelum_ _node_ `R`. Logikanya mirip dengan `insertAfter`, namun menggunakan `R->prev`.
	#### 2. Operasi Penghapusan (Deletion)
	5. **`deleteFirst(L, P)`**: Menghapus _node_ pertama dari _list_. `L.first` digeser ke elemen kedua, dan _pointer_ `prev` elemen kedua tersebut diatur ke `Nil`. _Node_ yang dihapus disimpan di `P` untuk didelokasi.
	6. **`deleteLast(L, P)`**: Menghapus _node_ terakhir dari _list_. `L.last` digeser ke elemen kedua dari belakang, dan _pointer_ `next` elemen tersebut diatur ke `Nil`.
	7. **`deleteAfter(L, P, R)`**: Menghapus _node_ yang berada _setelah_ _node_ `R`. Ini adalah operasi "lompat" di mana `R->next` diatur untuk menunjuk ke _node_ setelah _node_ yang dihapus.
	#### 3. Operasi Lanjutan (Advanced)
	Fungsi-fungsi dasar di atas dapat dikombinasikan untuk menciptakan logika yang lebih kompleks.
	- **`findElm(L, x)`**: Melakukan pencarian linear (Sequential Search) dari `L.first` untuk menemukan _node_ pertama yang memiliki `info` sama dengan `x`.
	- **`deleteByValue(L, x)`**: Menggabungkan `findElm` dengan operasi _delete_. Setelah _node_ dengan nilai `x` ditemukan, fungsi ini menentukan apakah akan menggunakan `deleteFirst`, `deleteLast`, atau `deleteAfter` berdasarkan posisi _node_ tersebut.
	- **`deleteAll(L)`**: Mengosongkan seluruh _list_ dengan cara memanggil `deleteFirst` secara berulang dalam sebuah _loop_ hingga `L.first` menjadi `Nil`.
	- **Operasi Kondisional (`smartInsert`, `conditionalDelete`)**: Ini adalah contoh bagaimana struktur _linked list_ dapat diintegrasikan dengan logika pemrograman (seperti `if-else`). Operasi ini memungkinkan penyisipan atau penghapusan elemen berdasarkan aturan atau kondisi tertentu (misalnya: nilai ganjil/genap, posisi, atau perbandingan dengan elemen lain). Saat menghapus elemen dalam sebuah _loop_ (seperti pada `conditionalDelete`), penting untuk menyimpan _pointer_ ke _node_ berikutnya (`nextNode = P->next`) sebelum menghapus `P`, agar iterasi tidak terputus.
## 4. Guided
### 4.1 Guided 1

![[dll insert.png]]

**Penjelasan**:
Kode ini mendefinisikan struktur data **Doubly Linked List (DLL)**, yang terdiri dari _node_ (`elmlist`) dengan _pointer_ `next` dan `prev`, serta _header_ `List` yang melacak `first` dan `last`. Program ini menyediakan fungsi esensial untuk **menyisipkan** _node_ di tiga lokasi: `insertFirst` (di awal), `insertLast` (di akhir), dan `insertAfter` (di tengah, setelah _node_ tertentu). Fungsi `main` kemudian mendemonstrasikan operasi ini: pertama memasukkan 10 (ke awal), lalu 20 (ke akhir), dan terakhir 30 (setelah 10). Hasil akhir dari urutan sisipan ini, yang ditampilkan oleh fungsi `printInfo`, adalah `10 30 20`.

**Output**:
![[Pasted image 20251025121459.png]]
### 4.2 Guided 2

![[dll delete.png]]

**Penjelasan**:
Kode ini adalah implementasi **Doubly Linked List (DLL)** yang berfokus pada operasi **penghapusan**. Fungsi `main` pertama-tama membuat _list_ `3 <-> 2 <-> 1` dengan tiga kali memanggil `insertFirst`. Panggilan `printInfo` pertama kemudian mencetak `3 2 1`. Selanjutnya, program memanggil `deleteFirst` (yang menghapus `3`), lalu memanggil `deleteAfter(L.first)` (yang menghapus elemen _setelah_ _node_ `2`, yaitu `1`). Panggilan `printInfo` kedua akhirnya mencetak elemen tunggal yang tersisa: `2`.

**Output**:
![[Pasted image 20251025122026.png]]

## 5. Unguided
### 5.1 Unguided 1

![[unguided1.png]]

**Penjelasan**:
Kode ini adalah implementasi dari **Doubly Linked List (DLL)** yang menambahkan dua fungsionalitas baru yang penting. Selain fungsi penyisipan standar (`insertFirst`, `insertLast`, `insertAfter`), kode ini memperkenalkan `insertBefore(L, P, R)`, sebuah fungsi untuk menyisipkan _node_ `P` tepat _sebelum_ _node_ target `R`. Fungsi ini juga secara cerdas menangani kasus khusus jika `R` adalah elemen pertama (`L.first`) dengan memanggil `insertFirst`. Fungsi baru kedua adalah `printReverse(L)`, sebuah utilitas untuk mencetak isi _list_ dari belakang ke depan, dengan menelusuri _pointer_ `prev` mulai dari `L.last`.

Fungsi `main` mendemonstrasikan alur kerja ini. Pertama, _list_ awal dibuat menjadi `1 <-> 3 <-> 2`. `printInfo` dan `printReverse` mencetak _list_ awal ini (`1 3 2` dan `2 3 1`). Kemudian, `insertBefore` dipanggil untuk menyisipkan `4` _sebelum_ _node_ `2`, menghasilkan `1 <-> 3 <-> 4 <-> 2`. Setelah itu, `insertBefore` dipanggil lagi untuk menyisipkan `5` _sebelum_ _node_ `1`, yang merupakan kasus khusus yang memanggil `insertFirst`. Hasil akhirnya, _list_ menjadi `5 <-> 1 <-> 3 <-> 4 <-> 2`, yang kemudian dicetak lagi secara forward (`5 1 3 4 2`) dan reverse (`2 4 3 1 5`).

**Output**:
![[Pasted image 20251025122412.png]]

### 5.2 Unguided 2

![[unguided2.png]]

**Penjelasan**:
Kode ini adalah implementasi **Doubly Linked List (DLL)** yang telah dilengkapi dengan fungsionalitas pencarian dan penghapusan tingkat lanjut.  Selain fungsi dasar seperti `insertFirst` dan `deleteFirst`, tiga fungsi baru yang krusial telah ditambahkan. Pertama, fungsi `findElm(L, x)` bertindak sebagai mesin pencari; ia berjalan dari `L.first` ke akhir _list_, memeriksa setiap `info` _node_. Jika ia menemukan _node_ pertama yang nilainya sama dengan `x`, ia akan mengembalikan alamat _node_ tersebut, jika tidak, ia mengembalikan `Nil`.

Fungsi kedua, `deleteByValue(L, x)`, adalah fungsi "cari dan hapus" yang cerdas. Ia pertama-tama memanggil `findElm` untuk menemukan _node_ (`P`) yang ingin dihapus. Jika `findElm` mengembalikan `Nil`, `deleteByValue` berhenti dan mengembalikan `false` (gagal). Namun, jika `P` ditemukan, fungsi ini harus menangani tiga skenario untuk menjaga integritas _list_: (1) Jika `P` adalah `L.first`, ia memanggil `deleteFirst`. (2) Jika `P` adalah `L.last`, ia memanggil `deleteLast`. (3) Jika `P` berada di tengah, ia akan mengambil _node_ _sebelumnya_ (`R = P->prev`) dan memanggil `deleteAfter(L, Pdel, R)` untuk menghapus _node_ _setelah_ `R` (yaitu `P` sendiri). Setelah _node_ berhasil dilepas dari _list_, `dealokasi` dipanggil untuk membebaskan memorinya.

Fungsi ketiga adalah `deleteAll(L)`, yang bertugas mengosongkan seluruh _list_. Ini bekerja dengan cara yang sangat efisien: ia terus-menerus memanggil `deleteFirst` dalam sebuah _loop_ `while` hingga `L.first` menjadi `Nil`, sambil menghitung setiap elemen yang dihapus.

Fungsi `main` mendemonstrasikan semua ini:
1. _List_ `L` diisi dengan empat kali `insertFirst`, menghasilkan urutan: `2 <-> 3 <-> 2 <-> 1`.
2. Panggilan `deleteByValue(L, 2)` berhasil. `findElm` menemukan _node_ `2` yang pertama (yang kebetulan adalah `L.first`), sehingga `deleteFirst` dieksekusi, menyisakan _list_ `3 <-> 2 <-> 1`.
3. Panggilan `deleteByValue(L, 5)` gagal karena `findElm` mengembalikan `Nil`.
4. Dua `insertFirst` lagi (4 dan 5) dipanggil, mengubah _list_ menjadi `5 <-> 4 <-> 3 <-> 2 <-> 1`.
5. Terakhir, `deleteAll(L)` dipanggil, yang menghapus semua 5 elemen yang tersisa satu per satu dari depan, dan mencetak jumlah elemen yang dihapus.

**Output**:
![[Pasted image 20251025122813.png]]

### 5.3 Unguided 3

![[unguided3.png]]

**Penjelasan**:
Kode ini adalah puncak dari semua latihan sebelumnya, menggabungkan semua fungsi (`insert`, `delete`, `print`) dan menambahkan dua operasi kondisional yang canggih: `smartInsert` dan `conditionalDelete`.
1. **`smartInsert(List &L, infotype x)`**
    - Ini adalah fungsi penyisipan "cerdas" yang tidak hanya menyisipkan, tetapi pertama-tama **memutuskan ke mana** harus menyisipkan berdasarkan serangkaian aturan `if-else`:
        
        - **Aturan 1 (List Kosong):** Jika `L.first == Nil`, ia memanggil `insertFirst`.
        - **Aturan 2 (Lebih Kecil dari Awal):** Jika nilai `x` lebih kecil dari elemen pertama (`x < L.first->info`), ia memanggil `insertFirst`.
        - **Aturan 3 (Genap):** Jika `x` adalah bilangan genap (`x % 2 == 0`), ia memanggil `insertLast`.
        - **Aturan 4 (Lainnya, di Tengah):** Jika aturan di atas tidak terpenuhi dan _list_ memiliki setidaknya dua elemen (`L.first->next != Nil`), ia akan menyisipkan `x` _setelah_ elemen kedua (`insertAfter(L, P, L.first->next)`).
        - **Aturan 5 (Fallback):** Jika hanya ada 1 elemen dan aturan lain tidak cocok, ia memanggil `insertLast`.
            
2. **`conditionalDelete(List &L, int &count)`**
    - Ini adalah fungsi penghapusan massal yang sangat penting. Ia mengiterasi (menjelajahi) seluruh _list_ dari awal hingga akhir (`while (P != Nil)`).
    - **Logika Kritis:** Di dalam _loop_, ia harus menyimpan _pointer_ ke _node_ berikutnya (`address nextNode = P->next;`) **sebelum** melakukan apa pun.
    - **Mengapa?** Karena jika _node_ `P` saat ini dihapus, kita akan kehilangan "jejak" ke sisa _list_. Dengan `nextNode`, kita tahu ke mana harus melompat selanjutnya.
    - Untuk setiap _node_ `P`, ia memeriksa kondisi: `if (P->info % 2 != 0)` (apakah nilainya ganjil?).
    - Jika ganjil, ia memanggil fungsi hapus yang sesuai (`deleteFirst`, `deleteLast`, atau `deleteAfter`) dan menambah `count`.
    - Di akhir _loop_, ia pindah ke _node_ berikutnya menggunakan `P = nextNode;`.
        
**Fungsi `main`**
Berikut adalah apa yang terjadi langkah demi langkah:

1. **`List L` dibuat** (kosong).    
2. **SMART INSERT DEMO:**
    - `smartInsert(L, 5)`: List kosong. Aturan 1. `insertFirst(5)`.
        - List: `5`
    - `smartInsert(L, 3)`: `3 < 5`. Aturan 2. `insertFirst(3)`.
        - List: `3 <-> 5`
    - `smartInsert(L, 8)`: `8` tidak `< 3`. `8` genap. Aturan 3. `insertLast(8)`.
        - List: `3 <-> 5 <-> 8`
    - `smartInsert(L, 6)`: `6` tidak `< 3`. `6` genap. Aturan 3. `insertLast(6)`.
        - List: `3 <-> 5 <-> 8 <-> 6`
    - `smartInsert(L, 4)`: `4` tidak `< 3`. `4` genap. Aturan 3. `insertLast(4)`.
        - List: `3 <-> 5 <-> 8 <-> 6 <-> 4`
    - `smartInsert(L, 7)`: `7` tidak `< 3`. `7` tidak genap. Aturan 4 (masuk `else if (L.first->next != Nil)`). `insertAfter(L, P(7), L.first->next)` (yaitu, sisipkan `7` _setelah_ _node_ `5`).
        - List: `3 <-> 5 <-> 7 <-> 8 <-> 6 <-> 4`
    - **Hasil** `printInfo` (Forward) adalah `3 5 7 8 6 4` dan `printReverse` (Backward) adalah `4 6 8 7 5 3`.
3. **CONDITIONAL DELETE DEMO:**
    - `conditionalDelete(L, deletedCount)` dipanggil pada _list_ `3 <-> 5 <-> 7 <-> 8 <-> 6 <-> 4`.
    - _Loop 1:_ `P` menunjuk `3` (ganjil). `deleteFirst` dipanggil. `deletedCount = 1`. _List_ menjadi: `5 <-> 7 <-> 8 <-> 6 <-> 4`. `P` pindah ke `nextNode` (yaitu `5`).
    - _Loop 2:_ `P` menunjuk `5` (ganjil). `deleteFirst` dipanggil. `deletedCount = 2`. _List_ menjadi: `7 <-> 8 <-> 6 <-> 4`. `P` pindah ke `nextNode` (yaitu `7`).
    - _Loop 3:_ `P` menunjuk `7` (ganjil). `deleteFirst` dipanggil. `deletedCount = 3`. _List_ menjadi: `8 <-> 6 <-> 4`. `P` pindah ke `nextNode` (yaitu `8`).
    - _Loop 4:_ `P` menunjuk `8` (genap). Tidak ada yang dihapus. `P` pindah ke `nextNode` (yaitu `6`).
    - _Loop 5:_ `P` menunjuk `6` (genap). Tidak ada yang dihapus. `P` pindah ke `nextNode` (yaitu `4`).
    - _Loop 6:_ `P` menunjuk `4` (genap). Tidak ada yang dihapus. `P` pindah ke `nextNode` (yaitu `Nil`).
    - _Loop_ berhenti. Fungsi mencetak `3 elemen ganjil dihapus`.
    - **Hasil** `printInfo` adalah `8 6 4`.
4. **DELETE BY VALUE DEMO:**
    - `deleteByValue(L, 6)` dipanggil pada _list_ `8 <-> 6 <-> 4`.
    - `findElm(6)` menemukan _node_ `6`. Posisinya di tengah.
    - Fungsi ini memanggil `deleteAfter` pada _node_ _sebelum_ `6` (yaitu `8`).
        - List: `8 <-> 4`
    - `deleteByValue(L, 10)` dipanggil. `findElm(10)` mengembalikan `Nil`. Fungsi mencetak `Nilai 10 tidak ditemukan`.
    - **Hasil** `printInfo` adalah `8 4`.
5. **DELETE ALL DEMO:**
    - `deleteAll(L)` dipanggil pada _list_ `8 <-> 4`.
    - _Loop 1:_ `deleteFirst` menghapus `8`. `count = 1`. _List_ menjadi: `4`.
    - _Loop 2:_ `deleteFirst` menghapus `4`. `count = 2`. _List_ menjadi: (kosong).
    - _Loop_ berhenti. Fungsi mencetak `Semua elemen (2) berhasil dihapus`.

**Output**:
![[Pasted image 20251025123522.png]]

## 6. Kesimpulan

Praktikum ini telah berhasil mengimplementasikan struktur data **Doubly Linked List (DLL)** secara lengkap. Dimulai dari operasi dasar seperti **penyisipan** (`insertFirst`, `insertLast`, `insertAfter`, `insertBefore`) dan **penghapusan** (`deleteFirst`, `deleteLast`, `deleteAfter`), praktikum ini berkembang hingga mencakup fungsionalitas yang lebih canggih.

Tujuan praktikum tercapai dengan diimplementasikannya fungsi pencarian (`findElm`), penghapusan berdasarkan nilai (`deleteByValue`), dan pengosongan _list_ (`deleteAll`). Puncaknya adalah pembuatan fungsi kondisional kompleks seperti `smartInsert` (untuk penyisipan cerdas) dan `conditionalDelete` (untuk menghapus elemen ganjil).

Keseluruhan praktikum ini membuktikan pemahaman mendalam tentang manipulasi _pointer_ `next` dan `prev`, pentingnya manajemen memori (`alokasi`/`dealokasi`), dan penanganan berbagai _edge cases_ (seperti _list_ kosong atau operasi pada elemen pertama/terakhir).

## 7. Referensi

1. Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2022). _Introduction to Algorithms_ (4th ed.). MIT Press.
2. Weiss, M. A. (2014). _Data Structures and Algorithm Analysis in C++_ (4th ed.). Pearson.
3. Wijoyo, A., Prayudi, L. A., Fiqih, M., Santoso, R. D., Putra, R. T., Arifin, T., & Farhan, A. (2024). Penggunaan Algoritma Doubly Linked List Untuk Insertion Dan Deletion. _JRIIN : Jurnal Riset Informatika dan Inovasi_, 1(12), 1329–1331.
4. Sjafari, A. N., & Mulyani, A. (2018). IMPLEMENTASI DOUBLE LINKED LIST PADA APLIKASI ANTRIAN KLINIK. _Jurnal Ilmiah Informatika_, 3(01).