#include <iostream>
using namespace std;

// Functor para ordenar de manera ascendente
struct asc {
    bool operator()(int a, int b) const {
        return a < b;
    }
};

// Functor para ordenar de manera descendente
struct des {
    bool operator()(int a, int b) const {
        return a > b;
    }
};

template <typename T, typename ordenar_funtor>
class lista_ordenada {
private:
    struct Node {
        T data;
        Node* next;
        explicit Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    ordenar_funtor comparador;

public:
    lista_ordenada() : head(nullptr) {}

    ~lista_ordenada() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertar(const T& value) {
        Node* newNode = new Node(value);

        if (head == nullptr || comparador(value, head->data)) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr && comparador(current->next->data, value)) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void imprime() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << std::endl;
    }
};

int main() {
    lista_ordenada<int, asc> lista_asc;
    lista_asc.insertar(5);
    lista_asc.insertar(2);
    lista_asc.insertar(8);
    lista_asc.insertar(1);
    lista_asc.insertar(3);
    lista_asc.insertar(12);
    lista_asc.insertar(34);
    lista_asc.insertar(-3);
    lista_asc.insertar(4);
    lista_asc.insertar(7);
    
    cout << "Lista ordenada de manera ascendente: ";
    lista_asc.imprime();

    lista_ordenada<int, des> lista_des;
    lista_des.insertar(5);
    lista_des.insertar(2);
    lista_des.insertar(8);
    lista_des.insertar(1);
    lista_des.insertar(3);
    lista_des.insertar(12);
    lista_des.insertar(34);
    lista_des.insertar(-3);
    lista_des.insertar(4);
    lista_des.insertar(7);

    cout << "Lista ordenada de manera descendente: ";
    lista_des.imprime();

    return 0;