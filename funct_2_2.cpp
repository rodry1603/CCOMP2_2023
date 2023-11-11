#include <iostream>
using namespace std;

template <class T>
struct nodo {
    T valor;
    nodo<T>* next;
    nodo(T v, nodo<T>* n = NULL) {
        valor = v;
        next = n;
    }
};

template <class T, class O>
class LE {
    nodo<T>* head = NULL;
    O funtor;

public:
    void add(T valor);
    void del(T valor);
    bool find(T valor, nodo<T>*& Pos);
    void print();
};

template <class T>
struct Asc {
    bool operator()(const T& a, const T& b) {
        return a < b;
    }
};

template <class T>
struct Desc {
    bool operator()(const T& a, const T& b) {
        return a > b;
    }
};

template <class T, class O>
bool LE<T, O>::find(T valor, nodo<T>*& Pos) {
    Pos = NULL;
    nodo<T>* p = head;

    for (; p && funtor(p->valor, valor); Pos = p, p = p->next);

    if (p && p->valor == valor) {
        return true;
    } else {
        return false;
    }
}

template <class T, class O>
void LE<T, O>::add(T valor) {
    nodo<T>* Pos;
    if (!find(valor, Pos)) {
        if (!Pos) {
            head = new nodo<T>(valor, head);
        } else {
            Pos->next = new nodo<T>(valor, Pos->next);
        }
    }
}

template <class T, class O>
void LE<T, O>::del(T valor) {
    nodo<T>* Pos, *tmp;
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

template <class T, class O>
void LE<T, O>::print() {
    nodo<T>* actual = head;
    while (actual != NULL) {
        cout << actual->valor << " ";
        actual = actual->next;
    }
    cout << endl;
}

int main() {
    LE<int, Asc<int>> lista1;
    lista1.add(5);
    lista1.add(2);
    lista1.add(8);
    lista1.add(1);

    cout << "Ascendente: ";
    lista1.print();

    LE<int, Desc<int>> lista2;
    lista2.add(5);
    lista2.add(2);
    lista2.add(8);
    lista2.add(1);

    cout << "Descendente: ";
    lista2.print();

    return 0;
}