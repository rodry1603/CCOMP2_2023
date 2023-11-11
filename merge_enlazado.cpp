#include <iostream>
#include <string>
using namespace std;

template <class T>
struct nodo {
    T valor;
    nodo<T> *next;
    nodo(T v, nodo<T> *n = NULL) {
        valor = v;
        next = n;
    }
};

template <class T>
class LE {
  public:
    nodo<T> *head = NULL;
    void add(T valor);
    void del(T valor);
    bool find(T valor, nodo<T> *&Pos);
    ~LE();
    void print();
};

template <class T>
bool LE<T>::find(T valor, nodo<T> *&Pos) {
    Pos = NULL;
    nodo<T> *p = head;

    for (; p && p->valor < valor; Pos = p, p = p->next);
    return (p && p->valor == valor);
}

template <class T>
void LE<T>::add(T valor) {
    nodo<T> *Pos;
    if (!find(valor, Pos)) {
        if (!Pos) {
            head = new nodo<T>(valor, head);
        } else {
            Pos->next = new nodo<T>(valor, Pos->next);
        }
    }
}

template <class T>
void LE<T>::del(T valor) {
    nodo<T> *Pos, *tmp;
    if (find(valor, Pos)) {
        if (!Pos) {
            tmp = head;
            head = head->next;
            delete tmp;
        } else {
            tmp = Pos->next;
            Pos->next = Pos->next->next;
            delete tmp;
        }
    }
}

template <class T>
void LE<T>::print() {
    nodo<T> *act = head;
    while (act != NULL) {
        cout << act->valor << " ";
        act = act->next;
    }
}

template <class T>
LE<T>::~LE() {
    nodo<T> *actual = head;
    while (actual != NULL) {
        nodo<T> *front = actual->next;
        delete actual;
        actual = front;
    }
}

template <class T>
void merge(LE<T> &h1, LE<T> &h2) {
    nodo<T> *p = h1.head;
    nodo<T> *q = h2.head;
    nodo<T> *r = nullptr;

    if (p && q) {
        if (p->valor < q->valor) {
            r = p;
            p = p->next;
        } else {
            r = q;
            q = q->next;
        }

        h1.head = r;

        while (p && q) {
            if (p->valor < q->valor) {
                r->next = p;
                r = p;
                p = p->next;
            } else {
                r->next = q;
                r = q;
                q = q->next;
            }
        }

        if (p) {
            r->next = p;
        } else if (q) {
            r->next = q;
        }

        h2.head = nullptr;
    }
}

int main() {
    LE<int> h1, h2;

    h1.add(1);
    h1.add(9);
    h1.add(5);
    h1.add(3);
    h1.add(11);
    h2.add(2);
    h2.add(4);
    h2.add(6);
    h2.add(7);

    cout << "h1: ";
    h1.print();
    cout << endl;

    cout << "h2: ";
    h2.print();
    cout << endl;

    merge(h1, h2);

    cout << "Merged h1: ";
    h1.print();
    cout << endl;

    cout << "Merged h2: ";
    h2.print();
    cout << endl;

    return 0;
}