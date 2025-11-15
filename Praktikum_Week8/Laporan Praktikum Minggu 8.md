## 1. Nama, NIM, Kelas
- **Nama**: Ichya Ulumiddiin
- **NIM**: 103112400076
- **Kelas**: Teknik Informatika 12-05

## 2. Motivasi Belajar Struktur Data

Belajar struktur data itu sebenarnya bukan cuma soal menghafal teori atau koding semata, tapi tentang melatih cara berpikir kita supaya lebih runtut, efisien, dan logis. Bayangkan saja kalau data itu seperti barang di gudang kalau ditata sembarangan pasti susah dicari, tapi kalau disusun pakai sistem, semua jadi cepat, mudah, dan teratur. Dengan menguasai struktur data, kita jadi punya bekal penting buat menyelesaikan masalah dalam pemrograman maupun kehidupan sehari-hari, karena pola pikirnya terbawa untuk mencari solusi paling efektif. Jadi, meskipun kadang terasa rumit di awal, anggap saja setiap materi adalah investasi kecil yang nantinya bikin kita lebih siap menghadapi tantangan di dunia teknologi.

## 3. Dasar Teori

Struktur data adalah cara untuk menyimpan dan mengorganisir data dalam komputer agar dapat digunakan secara efisien. Berikut adalah teori dasar mengenai **Queue**:

Antrean, atau **Queue**, merupakan sebuah struktur data linier yang bekerja berdasarkan prinsip **FIFO (First-In, First-Out)** . Prinsip ini bisa diibaratkan seperti antrean di loket, di mana orang yang pertama kali datang akan menjadi yang pertama dilayani . Dalam implementasinya, elemen baru selalu ditambahkan ke satu sisi yang disebut **Tail** (ekor) melalui operasi **Enqueue**, sementara elemen dihapus dari sisi berlawanan yang disebut **Head** (kepala) melalui operasi **Dequeue**.

Salah satu cara untuk mengimplementasikan antrean adalah dengan menggunakan **Array** (disebut juga "Tabel"). Implementasi ini memerlukan sebuah array untuk menyimpan data dan dua variabel integer, `head` dan `tail`, untuk melacak posisi depan dan belakang antrean . Metode paling sederhana, yang kita lihat pada **Alternatif 1** (`unguided1.cpp`), adalah metode "naif" di mana `head` selalu dianggap berada di indeks 0 (selama tidak kosong) . Meskipun `enqueue` (menambah data) mudah, operasi `dequeue` (menghapus data) menjadi sangat **tidak efisien**. Hal ini dikarenakan setiap kali elemen di `head` dihapus, semua elemen lain di belakangnya harus **digeser (shift)** satu per satu ke kiri untuk mengisi kekosongan.

Untuk mengatasi ketidakefisienan tersebut, **Alternatif 2** (`unguided2.cpp`) diperkenalkan. Pada metode ini, `dequeue` menjadi efisien karena elemen tidak lagi digeser; sebaliknya, penunjuk `head` yang digerakkan maju. Namun, ini menciptakan masalah baru yang disebut **"Penuh Semu" (Pseudo-Full)** . Ini adalah kondisi di mana `tail` sudah mencapai akhir array, namun `head` sudah bergeser maju, meninggalkan slot kosong di awal array yang tidak dapat digunakan lagi. Solusi paling efisien dan umum untuk masalah ini adalah **Alternatif 3** (`unguided3.cpp`), yang dikenal sebagai **Circular Queue** atau "circular buffer" . Metode ini memperlakukan array seolah-olah "berputar" (melingkar). Ketika `head` atau `tail` mencapai indeks maksimum, posisi berikutnya akan "melompat" kembali ke indeks 0. Ini dicapai secara cerdas menggunakan operasi aritmatika **modulo (`%`)** . Implementasi ini sangat efisien untuk `enqueue` dan `dequeue` serta secara tuntas menyelesaikan masalah "penuh semu".

## 4. Guided
### 4.1 Guided 1

<img width="848" height="1204" alt="queueH new" src="https://github.com/user-attachments/assets/fc2822eb-ee55-4278-961a-b7d68dc32a77" />

**Penjelasan**:

**file header `queue.h`** yang berfungsi sebagai cetak biru untuk struktur data Antrean (Queue). File ini menetapkan ukuran antrean maksimal 5 elemen (`MAX_QUEUE 5`) dan membuat alias `infotype` untuk tipe data `int`. Intinya, ia mendefinisikan `struct Queue` yang berisi array `info` untuk menyimpan data, serta integer `head` dan `tail` untuk melacak posisi. Terakhir, file ini mendaftarkan semua **prototipe fungsi** (seperti `createQueue`, `enqueue`, `dequeue`, dll.) yang akan digunakan untuk memanipulasi antrean tersebut , sementara implementasi atau logika dari fungsi-fungsi itu akan ada di file `.cpp` terpisah.

### 4.2 Guided 2

<img width="1680" height="2572" alt="queueCPP" src="https://github.com/user-attachments/assets/8ac76b54-64b1-4710-a895-4c843238b88b" />

**Penjelasan**:

Kode ini adalah implementasi dari **Circular Queue (Antrean Melingkar)** yang menggunakan variabel `count` untuk melacak jumlah elemen. Ini adalah implementasi yang sangat efisien dan merupakan **variasi dari Alternatif 3** yang disebutkan dalam modul . Penggunaan `count` sangat menyederhanakan logika untuk menentukan apakah antrean kosong atau penuh.

Fungsi `createQueue` menginisialisasi antrean dengan mengatur `head`, `tail`, dan `count` ke `0`. Berkat variabel `count`, fungsi `isEmpty` dan `isFull` menjadi sangat sederhana: `isEmpty` hanya perlu memeriksa apakah `Q.count == 0`, dan `isFull` hanya perlu memeriksa apakah `Q.count == MAX_QUEUE`.

Fungsi `enqueue` (menambah elemen) pertama-tama memeriksa apakah antrean _tidak_ penuh. Jika tidak, ia memasukkan elemen `x` ke posisi `Q.tail` saat ini. Kemudian, ia memajukan `tail` ke posisi berikutnya secara melingkar menggunakan operasi modulo (`Q.tail = (Q.tail + 1) % MAX_QUEUE`). Terakhir, ia menambah `Q.count`.

Fungsi `dequeue` (menghapus elemen) bekerja secara serupa. Ia memeriksa apakah antrean _tidak_ kosong. Jika tidak, ia mengambil elemen di posisi `Q.head` dan menyimpannya ke variabel `x`. Kemudian, ia memajukan `head` secara melingkar (`Q.head = (Q.head + 1) % MAX_QUEUE`), mengurangi `Q.count`, dan mengembalikan nilai `x`. Jika antrean kosong, ia akan mencetak pesan dan mengembalikan `-1`.

Terakhir, `printInfo` adalah fungsi yang cerdas. Ia mulai mencetak dari `Q.head`. Daripada mencoba mencari tahu di mana `tail` berada, ia hanya berputar (looping) sebanyak `Q.count` kali. Di setiap putaran, ia mencetak elemen di indeks `i` saat ini, lalu memajukan `i` secara melingkar (`i = (i + 1) % MAX_QUEUE`) sampai jumlah elemen yang dicetak sama dengan `Q.count`.

### 4.3 Guided 3

<img width="956" height="1888" alt="queueMAIN" src="https://github.com/user-attachments/assets/d98f6ce9-6341-4099-b1c2-8cb36fb1f506" />

**Penjelasan**:

Kode `main.cpp` itu adalah program utama untuk menguji implementasi Antrean (Queue) kamu. Program ini dimulai dengan mencetak _header_ tabel (`H - T : Queue Info`), kemudian memanggil `createQueue` untuk menginisialisasi antrean `Q`, dan langsung mencetaknya dalam keadaan kosong.

Setelah itu, program mensimulasikan penambahan tiga elemen berturut-turut: `enqueue(5)`, `enqueue(2)`, dan `enqueue(7)`. Program kemudian menguji skenario "campuran": ia memanggil `dequeue` dua kali (mengeluarkan 5 dan 2), lalu `enqueue` satu kali (memasukkan 4), dan akhirnya mengosongkan antrean dengan memanggil `dequeue` tiga kali lagi. Fitur utamanya adalah pemanggilan `printInfo` setelah _setiap_ operasi, sehingga kamu bisa melacak status (isi, head, dan tail) antrean langkah demi langkah.

**Hasil Output main.cpp**:

<img width="863" height="479" alt="Screenshot 2025-11-14 083106" src="https://github.com/user-attachments/assets/a230882a-2f7a-4a7e-8575-3700e871d6b2" />

## 5. Unguided
### 5.1 Unguided 1

<img width="1048" height="2496" alt="unguided1QUEUE" src="https://github.com/user-attachments/assets/485692ee-3b16-46f4-a3e7-dda46f0bbb24" />

**Penjelasan**:

Kode ini adalah implementasi dari **Alternatif 1** (Antrean Naif) yang dideskripsikan di modul 8. Ini adalah metode di mana `head` (kepala) antrean selalu diam di indeks 0 dan `dequeue` (pengambilan elemen) menyebabkan semua elemen lain bergeser ke kiri.

Fungsi `createQueue` menginisialisasi antrean kosong dengan mengatur `head` dan `tail` ke `-1`. Ini sesuai dengan _trace table_ di modul .

Fungsi `isEmptyQueue` dan `isFullQueue` bekerja berdasarkan `tail`. Antrean dianggap kosong (`isEmptyQueue`) jika `tail` masih `-1`, dan dianggap penuh (`isFullQueue`) jika `tail` sudah mencapai indeks maksimum (`MAX_QUEUE - 1`).

Fungsi `enqueue` (menambah elemen) pertama-tama memeriksa apakah antrean penuh. Jika tidak, ia memeriksa apakah antrean _baru_ akan diisi (jika `isEmptyQueue` benar). Jika ya, ia mengatur `head` ke `0`. Setelah itu, ia selalu menaikkan `tail` terlebih dahulu, lalu memasukkan elemen `x` di posisi `tail` yang baru.

Fungsi `dequeue` (menghapus elemen) adalah bagian yang paling khas dari Alternatif 1. Setelah memeriksa antrean tidak kosong, ia mengambil elemen di `head` (yang selalu `Q.info[0]`). Kemudian, ia menjalankan _loop_ `for` untuk **menggeser** semua elemen lain (dari `i = 1` sampai `tail`) satu posisi ke kiri. Setelah menggeser, ia mengurangi `tail`. Jika `tail` menjadi `-1` (artinya antrean jadi kosong), ia juga mereset `head` ke `-1`. Terakhir, ia mengembalikan elemen `x` yang tadi diambil.

Fungsi `printInfo` mencetak status `head` dan `tail` saat ini. Jika antrean kosong, ia mencetak "empty queue". Jika tidak, ia mencetak semua elemen satu per satu, mulai dari `head` (0) hingga `tail`, dan memberi spasi di antara elemen-elemen tersebut.

**Output**:

<img width="276" height="341" alt="Screenshot 2025-11-15 150445" src="https://github.com/user-attachments/assets/86ab0fe2-9e8e-4257-8581-f8f877a81ce7" />

### 5.2 Unguided 2

<img width="1140" height="2382" alt="unguided2QUEUE" src="https://github.com/user-attachments/assets/d1df2c97-9b29-4fdb-8fdb-13ce1866a806" />

**Penjelasan**:

Kode ini mengimplementasikan **Alternatif 2** (Antrean Geser) dari modul 8. Metode ini lebih efisien daripada Alternatif 1 karena `dequeue` tidak perlu menggeser elemen, melainkan hanya menggeser `head`.

Fungsi `createQueue` sama dengan Alternatif 1, yaitu menginisialisasi `head` dan `tail` ke `-1`.

Fungsi `isEmptyQueue` sedikit lebih kompleks. Antrean dianggap kosong jika `tail == -1` (kondisi awal) ATAU jika `head` telah bergerak melewati `tail` (`Q.head > Q.tail`) setelah beberapa kali `dequeue`.

Fungsi `isFullQueue` hanya memeriksa jika `tail` sudah mencapai akhir array (`MAX_QUEUE - 1`). Ini penting karena metode ini dapat mengalami **"Penuh Semu" (Pseudo-Full)** .

Fungsi `enqueue` (menambah elemen) sama persis dengan Alternatif 1. Ia akan menolak elemen baru jika `isFullQueue` benar (termasuk jika penuh semu). Jika tidak, ia mengatur `head` ke `0` saat elemen pertama masuk, lalu menaikkan `tail` dan menyisipkan elemen.

Fungsi `dequeue` (menghapus elemen) adalah bagian yang berbeda secara fundamental. Setelah antrean dipastikan tidak kosong, ia mengambil elemen di `Q.head`. Alih-alih menggeser array, ia **hanya memajukan `head`** (`Q.head++`). Ini membuatnya jauh lebih cepat. Jika pemanggilan `dequeue` ini menyebabkan `head` melewati `tail` (yang berarti antrean menjadi kosong), ia akan mereset `head` dan `tail` kembali ke `-1`.

Fungsi `printInfo` mencetak status `head` dan `tail`. Saat mencetak isi antrean, ia hanya mencetak elemen dari `Q.head` hingga `Q.tail`, mengabaikan slot-slot kosong yang mungkin ditinggalkan di awal array.

**Output**:

<img width="261" height="337" alt="Screenshot 2025-11-15 150812" src="https://github.com/user-attachments/assets/68bc1e08-baef-408e-99e8-085bab18adc1" />

### 5.3 Unguided 3

<img width="1048" height="2116" alt="unguided3QUEUE" src="https://github.com/user-attachments/assets/72eb9587-d8c2-439b-81e5-4718c5d55e0f" />

**Penjelasan**:

Kode ini mengimplementasikan **Alternatif 3 (Circular Queue)**, yang merupakan metode paling efisien untuk antrean berbasis array . Metode ini memperlakukan array seolah-olah "berputar" (melingkar), sehingga tidak ada elemen yang digeser dan tidak ada masalah "penuh semu".

Fungsi `createQueue` menginisialisasi antrean dengan mengatur `head` dan `tail` ke `0`.

Fungsi `isEmptyQueue` bekerja dengan prinsip bahwa antrean kosong jika `head` dan `tail` menunjuk ke lokasi yang sama (`Q.head == Q.tail`).

Fungsi `isFullQueue` memeriksa apakah antrean penuh dengan mengecek apakah `tail` berada tepat "di belakang" `head` secara melingkar. Logika `(Q.tail + 1) % MAX_QUEUE == Q.head` digunakan untuk "mengorbankan" satu slot agar bisa membedakan antara kondisi penuh dan kosong.

Fungsi `enqueue` (menambah elemen) dan `dequeue` (menghapus elemen) adalah inti dari metode ini. Keduanya menggunakan **operasi modulo (`%`)** untuk memajukan `tail` dan `head` . Saat `enqueue`, `tail` dimajukan dengan `(Q.tail + 1) % MAX_QUEUE`. Saat `dequeue`, `head` dimajukan dengan `(Q.head + 1) % MAX_QUEUE`. Ini membuat kedua penunjuk "berputar" kembali ke 0 secara otomatis saat mencapai akhir array.

Fungsi `printInfo` juga menggunakan logika melingkar. Ia memulai _loop_ dari `Q.head` dan terus berputar (menggunakan `i = (i + 1) % MAX_QUEUE`) sambil mencetak elemen, hingga `i` bertemu kembali dengan `Q.tail`.

**Output**:

<img width="251" height="343" alt="Screenshot 2025-11-15 151016" src="https://github.com/user-attachments/assets/b21bcded-27f3-4e97-853e-eb3cc1156ad6" />

## 6. Kesimpulan

Berdasarkan analisis modul dan implementasi kode, kesimpulan utamanya adalah bahwa terdapat berbagai cara untuk mengimplementasikan struktur data **Antrean (Queue)** menggunakan **Array**, di mana setiap cara memiliki kelebihan dan konsekuensi efisiensi yang berbeda. **Alternatif 1** (`unguided1.cpp`) adalah metode "naif" di mana `head` (kepala) antrean tetap di indeks 0. Meskipun mudah dipahami, metode ini sangat **tidak efisien** untuk operasi `dequeue` (penghapusan) karena setiap elemen yang tersisa di dalam array harus digeser satu per satu ke kiri 

**Alternatif 2** (`unguided2.cpp`) mencoba memperbaiki efisiensi `dequeue` dengan membiarkan `head` bergerak maju tanpa menggeser elemen. Walaupun `dequeue` menjadi cepat, metode ini menciptakan masalah baru yang disebut **"penuh semu" (pseudo-full)**, di mana antrean dianggap penuh saat `tail` (ekor) mencapai akhir array, meskipun masih ada slot kosong di bagian depan. Solusi terbaik untuk kedua masalah ini adalah **Alternatif 3** (`unguided3.cpp`), yang dikenal sebagai **Circular Queue (Antrean Melingkar). Dengan memperlakukan array seolah-olah "berputar" (menggunakan operasi modulo `%`**), `head` dan `tail` dapat kembali ke indeks 0 setelah mencapai akhir. Metode ini secara tuntas menyelesaikan masalah "penuh semu" dan menjaga agar operasi `enqueue` dan `dequeue` tetap efisien
## 7. Referensi

1. Aini, S. N. & Kurniawan R., R. (2025). 'Sistem Antrian Pasien Berbasis Web Dengan Algoritma Circular Queue Pada Klinik Pratama Rawat Inap Ar-Razi'. _CESS (Journal of Computer Engineering, System and Science)_, 10(2).
2. Bollina, S. V. T. (2024). _What is a circular queue, and how does it differ from a regular queue?_
3. Trijayanti, A., Aulia, I., Khairunisa, N., Purba, F. A. H. & Gunawan, I. (2025). 'Implementasi Struktur Data Antrian Queue dalam Sistem Penjadwalan Proses pada Sistem Operasi'. _Jurnal Publikasi Teknik Informatika_, 4(2), hlm. 48–53.
