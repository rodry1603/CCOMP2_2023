#include <iostream>
using namespace std;


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void transpuesta(int(*p)[4]) {
    int* limit = *(p + 1);
    int* end = *(p + 4);
    int numerodec = *(p + 1) -  *p;
    
    int* ini = *p ;
  for(; ini < end; ini = (ini+ numerodec+1),limit += numerodec){
    for(int *q = ini, *r = ini; q < limit; q++, r += numerodec){
        swap(q,r);
    }
  }
}


void imprimir (int a[4][4]){
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

}

int main() {
    int array[4][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16} };

    imprimir(array);
    cout << "---------------" << endl;

    transpuesta(array);

    imprimir(array);



}