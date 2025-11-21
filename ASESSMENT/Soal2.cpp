#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

bool isEmpty() {
    return head == NULL;
}

void insertLast(int nilai) {
    Node* newNode = new Node();
    newNode->data = nilai;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;     
        newNode->prev = tail;    
        tail = newNode;           
    }
}

void deleteLast() {
    if (isEmpty()) {
        return; 
    }
    Node* delNode = tail;
    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;       
        tail->next = NULL;
        delete delNode;
    }
}

void view() {
    if (isEmpty()) {
        cout << "(List Kosong)" << endl;
        return;
    }
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void reverseListView() {
    if (isEmpty()) {
        cout << "(List Kosong)" << endl;
        return;
    }
    Node* current = head;
    Node* temp = NULL;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        temp = head;
        head = tail;
        tail = temp;
    }
    cout << "List setelah di-reverse: ";
    view();
}

int main() {
    int pilihan, nilai;
    do {
        cout << "Menu: 1 insert (end), 2 delete (last), 3 view (depan), 4 reverse & view (depan), 0 exit" << endl;
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                insertLast(nilai);
                break;
            case 2:
                deleteLast();
                break;
            case 3:
                view();
                break;
            case 4:
                reverseListView();
                break;
            case 0:
                break;
            default:
                cout << "Pilihan salah" << endl;
        }
    } while (pilihan != 0);
    return 0;
}