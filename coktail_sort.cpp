#include <iostream>
using namespace std;

void coktail(int *ini,int *fin ){
    while(ini<fin){
        for(int *brbja=ini;brbja<fin; brbja++){
            if(*brbja>*(brbja+1)){
                int temp=*(brbja+1);
                *(brbja+1)=*brbja;
                brbja++;
                *(brbja-1)=temp;
                brbja--;
            }
        }
        fin--;
        for(int *brbja=fin; brbja>ini;brbja--){
            if(*brbja<*(brbja-1)){
                int temp=*(brbja-1);
                *(brbja-1)=*brbja;
                brbja--;
                *(brbja+1)=temp;
                brbja++;
            }
        }
        ini++;
    }

}


int main(){
    int a[10]={10,13,15,20,26,30,28,19,21,12};
    coktail(&a[0],&a[9]);
    for(int i = 0; i <= 9; ++i){
        cout << a[i] << " ";
    }
}