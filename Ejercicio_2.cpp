#include <iostream>

// Nodo de la lista enlazada
template <typename T>
struct Node {
    T data;
    Node* next;

    Node(const T& value) : data(value), next(nullptr) {}
};

// Lista enlazada circular
template <typename T, typename Comp>
class Lista_circular {
private:
    Node<T>* head;

public:
    Lista_circular() : head(nullptr) {}
    // insertarar un elemento en la lista
    void insertar(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            Node<T>* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void print() const {
        if (!head) {
            std::cout << "Lista vacía." << std::endl;
            return;
        }

        Node<T>* temp = head;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        std::cout << std::endl;
    }

    // Ordenar la lista utilizando un functor
    void find(Comp comparator) {
        if (!head || !head->next) {
            // La lista está vacía o tiene un solo elemento, ya está ordenada
            return;
        }
        Node<T>* current = head;
        Node<T>* nextNode = head->next;
        do {
            Node<T>* innerCurrent = head;
            do {
                if (comparator(innerCurrent->data, nextNode->data)) {
                    // Intercambiar los valores
                    T temp = innerCurrent->data;
                    innerCurrent->data = nextNode->data;
                    nextNode->data = temp;
                }

                innerCurrent = innerCurrent->next;
            } while (innerCurrent != head);

            current = current->next;
            nextNode = current->next;

        } while (nextNode != head);
    }
};

template <typename T>
struct asc {
    bool operator()(const T& a, const T& b) const {
        return a > b; 
    }
};


template <typename T>
struct des {
    bool operator()(const T& a, const T& b) const {
        return a < b; 
    }
};

int main() {

    Lista_circular<int, asc<int>> lista_asc;
    lista_asc.insertar(5);
    lista_asc.insertar(2);
    lista_asc.insertar(8);
    lista_asc.insertar(1);
    lista_asc.insertar(4);
    lista_asc.insertar(7);
    lista_asc.insertar(6);
    lista_asc.insertar(9);

    std::cout << "Lista desordenada  ";
    lista_asc.print();

    lista_asc.find(asc<int>());
    std::cout << "Lista ordenada ascendente: ";
    lista_asc.print();

    Lista_circular<int, des<int>> lista_des;
    lista_des.insertar(5);
    lista_des.insertar(2);
    lista_des.insertar(8);
    lista_des.insertar(1);
    lista_des.insertar(4);
    lista_des.insertar(7);
    lista_des.insertar(6);
    lista_des.insertar(9);

    std::cout << "Lista desordenada";
    lista_des.print();

    lista_des.find(des<int>());
    std::cout << "Lista ordenada descendente: ";
    lista_des.print();

    return 0;
}