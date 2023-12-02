#include <iostream>
using namespace std;

template <typename T, typename Functor>
class Nodo {
public:
    T data;
    Nodo<T, Functor>* next;
    Nodo<T, Functor>* prev;

    Nodo(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T, typename Functor>
class Lista_doble_enlazada {
    private:
        Nodo<T, Functor>* head;
    public:
        Lista_doble_enlazada() : head(nullptr) {}
        
        void insertar(T value) {
            Nodo<T, Functor>* newNodo = new Nodo<T, Functor>(value);
            if (!head) {
                head = newNodo;
                head->next = head;
                head->prev = head;
            } else {
                Nodo<T, Functor>* last = head->prev;
                newNodo->next = head;
                newNodo->prev = last;
                head->prev = newNodo;
                last->next = newNodo;
            }
        }
        void imprime() const {
            if (!head) {
                cout << "La lista está vacía." << endl;
                return;
            }
            Nodo<T, Functor>* current = head;
            do {
                cout << current->data << " ";
                current = current->next;
            } while (current != head);
            cout << endl;
        }

        void imprimeInverso() const {
        if (!head) {
            cout << "La lista está vacía." << endl;
            return;
        }
        Nodo<T, Functor>* current = head->prev;
        do {
            cout << current->data << " ";
            current = current->prev;
        } while (current != head->prev);
        cout << endl;
    }   

        void find() {
            if (!head) {
                return;
            }
            Nodo<T, Functor>* current = head;
            Nodo<T, Functor>* index = nullptr;
            T temp;
            do {
                index = current->next;
                do {
                    if (Functor()(index->data, current->data)) {
                        temp = current->data;
                        current->data = index->data;
                        index->data = temp;
                    }

                    index = index->next;
                } while (index != head);

                current = current->next;
            }
            while (current != head && current->next != head);
        }
};

struct asc {
    template <typename T>
    bool operator()(const T& a, const T& b) const {
        return a < b;
    }
};

struct des {
    template <typename T>
    bool operator()(const T& a, const T& b) const {
        return a > b;
    }
};

int main() {
    Lista_doble_enlazada<int, asc> lista_asc;
    lista_asc.insertar(5);
    lista_asc.insertar(2);
    lista_asc.insertar(8);
    lista_asc.insertar(1);
    lista_asc.insertar(3);
    lista_asc.insertar(4);
    lista_asc.insertar(7);

    cout << "Lista en orden: ";
    lista_asc.imprime();

    cout << "Lista en orden inverso: ";
    lista_asc.imprimeInverso();

    lista_asc.find();

    cout << "Lista ascendente:  ";
    lista_asc.imprime();


    Lista_doble_enlazada<int, des> lista_des;
    lista_des.insertar(5);
    lista_des.insertar(2);
    lista_des.insertar(8);
    lista_des.insertar(1);
    lista_des.insertar(3);
    lista_des.insertar(4);
    lista_des.insertar(7);

    cout << "\nLista descendente antes de ordenar: ";
    lista_des.imprime();

    cout << "Lista en orden inverso: ";
    lista_des.imprimeInverso();

    lista_des.find();

    cout << "Lista descendente después de ordenar: ";
    lista_des.imprime();

    return 0;
}