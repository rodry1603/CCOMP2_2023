#include<iostream>
using namespace std;

void multi(int(*p)[3][3]){
	int (*res)[3]=*(p+2);
	int (*q)[3]=*(p+1);
	int (*x)[3]=*p;
	while(x<*(p+1)){
	    for(int *z=*x;z<*(x+1);z++){
	      for(int*y=*q,*t=*res ;y<*(q+1)&&t<*(res+1);y++,t++){
	        *t+=(*z)*(*y);
	      }
	      q++;
	    }
	    q=*(p+1);
	    x++;
	    res++;
	}
    res=*(p+2);
    for(int*g=*res;g<*(res+3);g++){
        cout<< *g << " ";
    }
}
	
int main(){
	int A[3][3][3]={{{2,0,1},{3,0,0},{5,1,1}},{{1,0,1},{1,2,1},{1,1,0}},{{0,0,0},{0,0,0},{0,0,0}}};
	multi(A);
}