
## 1. Nama, NIM, Kelas

- **Nama**: Ichya Ulumiddiin

- **NIM**: 103112400076

- **Kelas**: 12-IF-05

  
## 2. Motivasi Belajar Struktur Data

	Belajar struktur data itu sebenarnya bukan cuma soal menghafal teori atau koding semata, tapi tentang melatih cara berpikir kita supaya lebih runtut, efisien, dan logis. Bayangkan saja kalau data itu seperti barang di gudang kalau ditata sembarangan pasti susah dicari, tapi kalau disusun pakai sistem, semua jadi cepat, mudah, dan teratur. Dengan menguasai struktur data, kita jadi punya bekal penting buat menyelesaikan masalah dalam pemrograman maupun kehidupan sehari-hari, karena pola pikirnya terbawa untuk mencari solusi paling efektif. Jadi, meskipun kadang terasa rumit di awal, anggap saja setiap materi adalah investasi kecil yang nantinya bikin kita lebih siap menghadapi tantangan di dunia teknologi.


## 3. Dasar Teori

	Struktur data adalah cara untuk menyimpan dan mengorganisir data dalam komputer agar dapat digunakan secara efisien. Berikut adalah teori dasar mengenai Loop, Increment, dan If:

- **Operasi Aritmetika pada Bilangan Float**
	Dalam pemrograman, operasi aritmetika seperti penjumlahan, pengurangan, perkalian, dan pembagian merupakan konsep paling dasar yang hampir selalu digunakan. Di C++, operasi tersebut dapat dilakukan menggunakan operator bawaan `+`, `-`, `*`, dan `/` baik pada bilangan bulat maupun pecahan (float). Tipe data `float` memungkinkan komputer menyimpan dan mengolah bilangan desimal dengan presisi tertentu sehingga hasil perhitungan lebih akurat. *"Pemahaman konsep aritmetika ini menjadi fondasi untuk membangun algoritma yang lebih kompleks, seperti perhitungan keuangan, simulasi, maupun aplikasi sains*" (_Alliana & Yahfizham, 2024_).

- **Konversi Angka ke Bentuk Kata (Number to Words)**
	Konversi angka ke kata merupakan implementasi dari pemetaan data (mapping) dan percabangan logika. Proses ini biasanya dilakukan dengan mengelompokkan angka dalam satuan, belasan, puluhan, hingga ratusan, kemudian diterjemahkan ke dalam teks sesuai aturan bahasa. "*Teknik ini banyak diterapkan dalam kehidupan nyata, misalnya pada pembuatan kwitansi, sistem akuntansi, hingga aplikasi perbankan yang membutuhkan representasi angka dalam bentuk tulisan agar lebih jelas dan tidak ambigu*" (_Bagus & Udayana, 2018_).
	
- **Pola Mirror dan Perulangan Bersarang (Nested Loop)**
	Konsep ini mengasah kemampuan mahasiswa untuk menggunakan struktur perulangan bersarang (nested loop) dengan tepat, sekaligus melatih ketelitian dalam mengatur spasi, urutan angka, dan simbol agar pola sesuai dengan yang diharapkan. Selain itu, pembuatan pola juga meningkatkan keterampilan berpikir algoritmik, karena "*mahasiswa harus mampu memetakan hubungan antara iterasi baris dan kolom untuk menghasilkan bentuk tertentu*" (_Majemuk, 2021_).

## 4. Guided

### 4.1 Guided 1

![[Pasted image 20250928170925.png]]

  **Penjelasan :**
	  Program di atas dibuat untuk menghitung diskon dari total belanja yang dimasukkan oleh pengguna. Pertama, program meminta input berupa nilai total pembelian, lalu menyimpannya ke dalam variabel `total_pembelian`. Setelah itu dilakukan pengecekan dengan struktur `if-else`, yaitu jika nilai pembelian lebih besar atau sama dengan Rp30.000, maka pengguna berhak mendapat diskon sebesar 10% dari total belanja. Nilai diskon ini dihitung menggunakan rumus `diskon = 0.1 * total_pembelian` dan hasilnya langsung ditampilkan. Namun, jika pembelian kurang dari Rp30.000, program akan menampilkan pesan bahwa belanjanya masih kurang untuk mendapatkan diskon. 
	  
**Output** :

![[Pasted image 20250928172913.png]]
### 4.2 Guided 2

![[Pasted image 20250928173056.png]]

**Penjelasan :**
	Program di atas dibuat untuk mengonversi suhu dari satuan Celcius ke Fahrenheit. Pertama, program mendeklarasikan dua variabel bertipe `float`, yaitu `celcius` untuk menyimpan input dari pengguna dan `fahrenheit` untuk menyimpan hasil konversi. Program kemudian menampilkan pesan ke layar untuk meminta input suhu dalam Celcius, lalu membaca nilai yang dimasukkan melalui `cin`. Setelah itu, program melakukan perhitungan konversi menggunakan rumus `(9.0/5.0) * celcius + 32`, yang memang merupakan rumus standar untuk mengubah suhu dari Celcius ke Fahrenheit. Hasil perhitungan disimpan dalam variabel `fahrenheit`, kemudian ditampilkan kembali ke layar dengan pesan yang menyebutkan nilai dalam derajat Fahrenheit. 

**Output :**

![[Pasted image 20250928173255.png]]

### 4.3 Guided 3

![[Pasted image 20250928173436.png]]

**Penjelasan :**
	Program di atas digunakan untuk menunjukkan perbedaan penggunaan operator **increment prefix (`++r`)** pada variabel. Pertama, variabel `r` diinisialisasi dengan nilai 20, kemudian variabel `s` dideklarasikan tanpa nilai awal. Pada baris berikutnya, dilakukan operasi `s = 20 + ++r;`. Karena menggunakan operator prefix (`++r`), nilai `r` akan dinaikkan terlebih dahulu menjadi 21, baru kemudian dipakai dalam perhitungan. Artinya, ekspresi tersebut sama dengan `s = 20 + 21;`, sehingga `s` bernilai 41, sementara `r` menjadi 21. Program kemudian menampilkan kedua nilai itu ke layar menggunakan `cout`. 

**Output :**

![[Pasted image 20250928173640.png]]

## 5. Unguided

### 5.1 Unguided 1

![[Pasted image 20250928173807.png]]

**Penjelasan :**
	Program di atas merupakan contoh sederhana operasi aritmetika dasar menggunakan dua bilangan bertipe `float`. Pertama, program mendeklarasikan dua variabel `a` dan `b`, lalu meminta pengguna untuk memasukkan dua bilangan melalui `cin`. Setelah nilai dimasukkan, program langsung menampilkan hasil penjumlahan (`a+b`), pengurangan (`a-b`), dan perkalian (`a*b`). Untuk operasi pembagian, program menggunakan percabangan `if-else` untuk mengantisipasi kemungkinan pembagian dengan nol. Jika nilai `b` tidak sama dengan nol, maka hasil pembagian `a/b` akan ditampilkan. Namun, jika `b` bernilai nol, program akan menampilkan pesan "Error" agar tidak terjadi kesalahan perhitungan (division by zero). 

**Output :**

![[Pasted image 20250928173946.png]]
  

### 5.2 Unguided 2

![[Pasted image 20250928174054.png]]

**Penjelasan :**
	Program pada gambar tersebut merupakan implementasi konversi bilangan bulat ke bentuk teks dalam bahasa Indonesia. Pertama, program mendefinisikan tiga array string, yaitu `satuan` untuk angka 0–9, `belasan` untuk angka 10–19, dan `puluhan` untuk kelipatan 10 dari 20 hingga 90. Setelah itu, program meminta input bilangan `n` dari pengguna. Jika bilangan bernilai 0 atau lebih dari 100, program menampilkan pesan “error”. Jika `n` kurang dari 10, angka diambil dari array `satuan`. Jika `n` kurang dari 20, maka teks diambil dari array `belasan` dengan indeks `n-10`. Untuk bilangan antara 20 hingga 99, program mencetak nilai dari array `puluhan[n/10]` dan, jika ada sisa pembagian (`n%10`), program juga menambahkan angka dari array `satuan[n%10]`. Sedangkan untuk angka 100, program langsung mencetak teks “seratus”. 

**Output :**

![[Pasted image 20250928174251.png]]
  

### 5.3 Unguided 3

![[Pasted image 20250928174328.png]]

**Penjelasan :**
	Program pada gambar tersebut bertujuan untuk menampilkan pola berbentuk segitiga simetris dengan kombinasi angka dan simbol bintang (`*`). Pertama, program meminta input bilangan bulat `n` dari pengguna sebagai tinggi segitiga. Bagian utama program menggunakan perulangan bersarang (`for`) untuk mengatur tata letak angka dan bintang. Perulangan luar (`for(int i=n; i>=1; i--)`) mengontrol jumlah baris dari `n` sampai `1`. Di dalamnya, ada tiga perulangan: yang pertama mencetak spasi agar pola tetap rata di tengah, yang kedua mencetak angka menurun dari `i` hingga `1`, lalu program menampilkan simbol `*` sebagai pemisah di tengah, dan perulangan ketiga mencetak angka naik dari `1` sampai `i`. Setelah selesai, program menutup setiap baris dengan `endl`. Pada bagian akhir, terdapat perulangan tambahan untuk mencetak spasi sebanyak `n` diikuti dengan satu simbol bintang di baris paling bawah sebagai dasar dari segitiga. 

**Output :**

![[Pasted image 20250928174618.png]]

## 6. Kesimpulan

	Kesimpulannya, dari keseluruhan program yang sudah dibuat dan dipelajari di atas, saya jadi lebih memahami bagaimana dasar-dasar pemrograman C++ bisa diterapkan untuk menyelesaikan berbagai permasalahan sederhana. Mulai dari program perhitungan diskon, konversi suhu, operasi aritmatika, penggunaan increment, sampai pengolahan angka menjadi teks dan pola bintang, semuanya menunjukkan bahwa logika pemrograman itu sebenarnya saling berhubungan. Struktur seperti input-output, percabangan `if-else`, perulangan `for`, dan penggunaan array menjadi kunci utama dalam menyusun solusi. Dengan latihan-latihan ini, saya semakin yakin bahwa penguasaan konsep dasar sangat penting sebelum masuk ke materi yang lebih kompleks seperti struktur data atau algoritma. Selain itu, saya juga menyadari bahwa kreativitas dalam menyusun logika bisa membuat program lebih menarik dan mudah dipahami. Jadi, secara keseluruhan materi ini bukan hanya melatih teknis penulisan kode, tetapi juga cara berpikir sistematis dan terstruktur dalam memecahkan masalah.


## 7. Referensi

1. Alliana, A., & Yahfizham, Y. (2024). Analisis Penerapan Dan Fungsi Algoritma Pemrograman Pada Komputer. Jurnal Riset Rumpun Matematika dan Ilmu Pengetahuan Alam, 3(1).

2. Bagus, I., & Udayana, I. (2018). Pengantar dan Pengenalan Konsep Dasar Algoritma Pemrograman. Jurnal Ilmiah Pendidikan Teknik Informatika, 9(1).

3. Majemuk. (2021). Penggunaan Bahasa C++ dalam Perkuliahan. Jurnal Ilmiah Majemuk, 4(2).