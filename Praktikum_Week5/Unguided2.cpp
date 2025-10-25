#include <iostream>
using namespace std;
#define Nil NULL

typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

address alokasi(infotype x) {
    address P = new elmlist; // Alokasi memori untuk elemen baru
    P->info = x; // Set info elemen baru
    P->next = Nil; // Inisialisasi next ke Nil
    P->prev = Nil; // Inisialisasi prev ke Nil
    return P; // Kembalikan alamat elemen baru
}

void dealokasi(address &P) { if (P != Nil) { delete P; P = Nil; } }

void insertFirst(List &L, address P) {
    P->next = L.first; // Set pointer next dari P ke elemen pertama saat ini
    P->prev = Nil; // Set pointer prev P ke Nil karena menjadi elemen pertama
    if (L.first != Nil) L.first->prev = P; // Jika list tidak kosong, set prev elemen pertama lama ke P
    else L.last = P; // Jika list kosong, set last juga ke P
    L.first = P; //Update first list menjadi P
}

void printInfo(List &L) {
    address P = L.first; // Set P ke elemen pertama list
    while (P != Nil) { // Loop selama P tidak Nil
        cout << P->info << " "; // Cetak info dari P
        P = P->next; // Pindah ke elemen berikutnya
    }
    cout << endl;
}

void deleteFirst(List &L, address &P) {
    P = L.first; L.first = L.first->next; // Set first list ke elemen kedua
    if (L.first != Nil) L.first->prev = Nil; // Jika list tidak kosong, set prev elemen pertama ke Nil
    else L.last = Nil; // Jika list menjadi kosong, set last ke Nil
    P->next = Nil; // Putuskan hubungan next dari P
    P->prev = Nil; // Putuskan hubungan prev dari P
}

void deleteLast(List &L, address &P) {
    P = L.last; L.last = L.last->prev; // Set last list ke elemen sebelum terakhir
    if (L.last != Nil) L.last->next = Nil; // Jika list tidak kosong, set next elemen terakhir ke Nil
    else L.first = Nil; // Jika list menjadi kosong, set first ke Nil
    P->prev = Nil; // Putuskan hubungan next dari P
    P->next = Nil; // Putuskan hubungan prev dari P
}

void deleteAfter(List &L, address &P, address R) {
    P = R->next; // Set P ke elemen setelah R
    R->next = P->next; // Set next dari R ke elemen setelah P
    if (P->next != Nil) P->next->prev = R; // Jika P bukan elemen terakhir, set prev elemen setelah P ke R
    else L.last = R; // Jika P adalah elemen terakhir, update last list menjadi R
    P->prev = Nil; // Putuskan hubungan next dari P
    P->next = Nil; // Putuskan hubungan prev dari P
}

address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

bool deleteByValue(List &L, infotype x) {
    address P = findElm(L, x);
    if (P == Nil) {
        return false;
    }
    address Pdel; // Penampung node yang akan didealokasi
    if (P == L.first) {
        deleteFirst(L, Pdel);
    } else if (P == L.last) {
        deleteLast(L, Pdel);
    } else {
        address R = P->prev; // R adalah node *sebelum* P
        deleteAfter(L, Pdel, R);
    }
    dealokasi(Pdel);
    return true;
}

int deleteAll(List &L) {
    int count = 0;
    address Pdel;
    while (L.first != Nil) {
        deleteFirst(L, Pdel);
        dealokasi(Pdel);
        count++;
    }
    return count;
}

int main() {
    List L;
    L.first = Nil;
    L.last = Nil;
    insertFirst(L, alokasi(1));
    insertFirst(L, alokasi(2));
    insertFirst(L, alokasi(3));
    insertFirst(L, alokasi(2));
    cout << "TASK 1: DELETE OPERATIONS" << endl;
    cout << "List awal: ";
    printInfo(L);
    if (deleteByValue(L, 2)) {
        cout << "Nilai 2 berhasil dihapus" << endl;
    } else {
        cout << "Nilai 2 tidak ditemukan" << endl;
    }
    cout << "Setelah deleteByValue(2): ";
    printInfo(L);
    if (deleteByValue(L, 5)) {
        cout << "Nilai 5 berhasil dihapus" << endl;
    } else {
        cout << "Nilai 5 tidak ditemukan" << endl;
    }
    cout << "List tetap: ";
    printInfo(L);
    insertFirst(L, alokasi(4));
    insertFirst(L, alokasi(5));
    cout << "List setelah tambah data: ";
    printInfo(L);
    int count = deleteAll(L);
    cout << "Semua elemen (" << count << ") berhasil dihapus" << endl;
    return 0;
}