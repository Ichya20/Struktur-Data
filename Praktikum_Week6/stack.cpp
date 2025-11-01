#include "stack.h"
#include <iostream>
using namespace std;

// Membuat stack kosong
void CreateStack(Stack &S) {
    S.TOP = Nil; // Nil = -1
}

// Memeriksa apakah stack kosong
bool IsEmpty(Stack S) {
    return S.TOP == Nil;
}

// Memeriksa apakah stack penuh
bool IsFull(Stack S) {
    return S.TOP == MaxEl - 1;
}

// Menambahkan elemen ke stack
void Push(Stack &S, infotype X) {
    if (!IsFull(S)) { // Hanya push jika TIDAK penuh
        if (IsEmpty(S)) {
            S.TOP = 0; // Jika kosong, mulai dari indeks 0
        } else {
            S.TOP++;
        }
        S.info[S.TOP] = X; // Simpan elemen
    } else {
        cout << "Stack penuh" << endl;
    }
}

// Menghapus elemen dari stack
infotype Pop(Stack &S) {
    infotype X = -999; // Nilai default jika kosong
    if (!IsEmpty(S)) {
        X = S.info[S.TOP];
        S.TOP--;
        if (S.TOP < 0) {
            S.TOP = Nil; // Tandai kosong lagi
        }
    } else {
        cout << "Stack kosong" << endl;
    }
    return X;
}

// Menampilkan isi stack
void printInfo(Stack S) {
    if (IsEmpty(S)) {
        cout << "Stack kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.TOP; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

// Membalik urutan elemen stack
void balikStack(Stack &S) {
    if (!IsEmpty(S)) {
        Stack temp;
        CreateStack(temp);
        while (!IsEmpty(S)) {
            Push(temp, Pop(S));
        }
        S = temp;
    }
}

// Menambahkan elemen secara ascending
void pushAscending(Stack &S, infotype X) {
    if (IsFull(S)) {
        cout << "Stack penuh" << endl;
        return;
    }

    Stack temp;
    CreateStack(temp);

    // Pindahkan elemen yang lebih kecil dari X ke stack sementara
    while (!IsEmpty(S) && S.info[S.TOP] < X) {
        Push(temp, Pop(S));
    }

    // Push X ke stack utama
    Push(S, X);

    // Kembalikan elemen dari stack sementara ke stack utama
    while (!IsEmpty(temp)) {
        Push(S, Pop(temp));
    }
}

// Membaca input stream dari user dan masukkan ke stack
void getInputStream(Stack &S) {
    cout << "Masukkan angka (tekan Enter untuk selesai): ";
    string input;
    cin >> input; // membaca seluruh string angka tanpa spasi (misal: 4729601)

    for (char c : input) {
        if (isdigit(c)) { // hanya karakter angka yang valid
            int value = c - '0';
            Push(S, value);
        }
    }
}

