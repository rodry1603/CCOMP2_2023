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

    int size() const {
        if (!head) {
            return 0;
        }

        Nodo<T, Functor>* current = head;
        int count = 0;
        do {
            count++;
            current = current->next;
        } while (current != head);

        return count;
    }

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
        } while (current != head && current->next != head);
    }

    void josephus(int paso) {
        if (!head || size() == 1) {
            cout << "La lista está vacía o tiene solo un elemento." << endl;
            return;
        }

        if (paso >= size()) {
            cout << "El valor de 'paso' es mayor o igual al tamaño de la lista." << endl;
            return;
        }

        Nodo<T, Functor>* current = head;
        while (current->next != current) {
            for (int i = 0; i < paso - 1; ++i) {
                current = current->next;
            }

            cout << "Eliminado: " << current->data << endl;
            Nodo<T, Functor>* temp = current->next;
            current->prev->next = current->next;
            current->next->prev = current->prev;
            if (current == head) {
                head = current->next;
            }
            delete current;
            current = temp;

            cout << "Lista actual: ";
            imprime();
        }

        cout << "Eliminado: " << current->data << endl;
        if (current == head) {
            head = nullptr;
        }
        delete current;
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

    cout << "Lista: ";
    lista_asc.imprime();
    /*
    cout << "Ascendente: ";
    lista_asc.find();
    
    lista_asc.imprime();
    */
    
    cout << "\nEliminación Josephus " << endl;
    lista_asc.josephus(2);
    lista_asc.imprime();

    return 0;
}