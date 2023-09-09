#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void orden(int *ini, int *mid){
    int *fin=mid + (mid-ini);

    while(mid<fin){
        for(int *m=ini;m<mid;m++){
            if(*m>*mid){
                swap(*m,*mid);
            }
        }
        mid++;
        ini++;
    }
}

int main(){
    int a[12]={9,11,12,24,31,44,1,18,20,23,41,45};
    orden(&a[0],&a[6]);
    for(int i = 0; i < 12; ++i){
        cout << a[i] << " ";
    }
}