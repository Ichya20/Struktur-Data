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
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) { if (P != Nil) { delete P; P = Nil; } }

void insertFirst(List &L, address P) {
    P->next = L.first;
    P->prev = Nil;
    if (L.first != Nil) L.first->prev = P;
    else L.last = P;
    L.first = P;
}

void insertLast(List &L, address P) {
    P->prev = L.last;
    P->next = Nil;
    if (L.last != Nil) L.last->next = P;
    else L.first = P;
    L.last = P;
}

void insertAfter(List &L, address P, address R) {
    P->next = R->next;
    P->prev = R;
    if (R->next != Nil) R->next->prev = P;
    else L.last = P;
    R->next = P;
}

void deleteFirst(List &L, address &P) {
    P = L.first; L.first = L.first->next;
    if (L.first != Nil) L.first->prev = Nil;
    else L.last = Nil;
    P->next = Nil;
    P->prev = Nil;
}

void deleteLast(List &L, address &P) {
    P = L.last; L.last = L.last->prev;
    if (L.last != Nil) L.last->next = Nil;
    else L.first = Nil;
    P->prev = Nil;
    P->next = Nil;
}

void deleteAfter(List &L, address &P, address R) {
    P = R->next;
    R->next = P->next;
    if (P->next != Nil) P->next->prev = R;
    else L.last = R;
    P->prev = Nil;
    P->next = Nil;
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
    address Pdel;
    if (P == L.first) {
        deleteFirst(L, Pdel);
    } else if (P == L.last) {
        deleteLast(L, Pdel);
    } else {
        address R = P->prev;
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

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void printReverse(List L) {
    address P = L.last;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->prev;
    }
    cout << endl;
}

void smartInsert(List &L, infotype x) {
    address P = alokasi(x);
    
    if (L.first == Nil) {
        cout << "Smart Insert: List kosong, insert " << x << " di first" << endl;
        insertFirst(L, P);
    
    } else if (x < L.first->info) {
        cout << "Smart Insert: " << x << " < first, insert di first" << endl;
        insertFirst(L, P);
    
    } else if (x % 2 == 0) {
        cout << "Smart Insert: " << x << " genap, insert di last" << endl;
        insertLast(L, P);
    
    } else if (L.first->next != Nil) {
        cout << "Smart Insert: " << x << " di antara " << L.first->next->info << " dan " << L.first->next->next->info << endl;
        insertAfter(L, P, L.first->next);
    
    } else {
        cout << "Smart Insert: " << x << " (default), insert di last" << endl;
        insertLast(L, P);
    }
}

void conditionalDelete(List &L, int &count) {
    count = 0;
    address P = L.first;
    while (P != Nil) {
        address nextNode = P->next; // Simpan node berikutnya        
        if (P->info % 2 != 0) {
            address Pdel;
            if (P == L.first) {
                deleteFirst(L, Pdel);
            } else if (P == L.last) {
                deleteLast(L, Pdel);
            } else {
                address R = P->prev;
                deleteAfter(L, Pdel, R);
            }
            dealokasi(Pdel);
            count++;
        }
        P = nextNode; // Pindah ke node berikutnya yang sudah disimpan
    }
}

int main() {
    List L;
    L.first = Nil;
    L.last = Nil;

    cout << "ADVANCED OPERATIONS" << endl;
    
    cout << "SMART INSERT DEMO" << endl;
    smartInsert(L, 5);  // List kosong -> insertFirst
    smartInsert(L, 3);  // 3 < 5 -> insertFirst
    smartInsert(L, 8);  // 8 genap -> insertLast
    smartInsert(L, 6);  // 6 genap -> insertLast
    smartInsert(L, 4);  // 4 genap -> insertLast
    smartInsert(L, 7);  // Default -> insertAfter(L.first->next) / setelah 5
    
    cout << "\nHasil Smart Insert:" << endl;
    cout << "Forward: ";
    printInfo(L); // Output: 3 5 7 8 6 4
    cout << "Backward: ";
    printReverse(L); // Output: 4 6 8 7 5 3
    
    cout << "\nCONDITIONAL DELETE" << endl;
    cout << "Sebelum Conditional Delete: ";
    printInfo(L); // Output: 3 5 7 8 6 4
    
    int deletedCount = 0;
    conditionalDelete(L, deletedCount); // Hapus semua yg ganjil (3, 5, 7)
    
    cout << "Conditional Delete: " << deletedCount << " elemen ganjil dihapus" << endl;
    cout << "Setelah Conditional Delete: ";
    printInfo(L); // Output: 8 6 4

    cout << "\nDELETE BY VALUE DEMO" << endl;
    if (deleteByValue(L, 6)) {
        cout << "Nilai 6 berhasil dihapus" << endl;
    } else {
        cout << "Nilai 6 tidak ditemukan" << endl;
    }

    if (deleteByValue(L, 10)) {
        cout << "Nilai 10 berhasil dihapus" << endl;
    } else {
        cout << "Nilai 10 tidak ditemukan" << endl;
    }
    
    cout << "List akhir: ";
    printInfo(L);
    cout << "\nDELETE ALL DEMO" << endl;
    int allCount = deleteAll(L);
    cout << "Semua elemen (" << allCount << ") berhasil dihapus" << endl;

    return 0;
}