#include<iostream>
#include<string>
using namespace std;

const string vacio=" ";
const string x[]={vacio, "uno", "dos","tres","cuatro","cinco","seis","siete","ocho","nueve",
                "diez","once","doce","trece","catorce","quince","diesiseis","diesisiete",
                "diesiocho","diesinueve","veinte","veintiuno","veintidos","veintitres","veinticuatro",
                "veinticinco","veintiseis","veintisiete","veintiocho","veintinueve"};
const string y[]={vacio,vacio,vacio,"treinta","cuarenta","cincuenta","sesenta","setenta","ochenta","noventa"};
const string especiales[]={vacio, vacio , vacio, vacio,"quinientos",vacio,"sete",vacio,"nove"};

string convierte_digito(unsigned long long n, string sufijo){
    if(n==0){
        return vacio;
    }

    if(n>29&&(n%10)==0){
        return y[n/10]+ sufijo;
    }else if(n>29&&(n%10)!=0){
        return y[n/10]+ vacio + "y" + vacio + x[n%10]+vacio+ sufijo;
    }else{
        return x[n] + sufijo;
    }
}

string centenas(unsigned long long n){
    string x;
    switch ((n/100)%10)
    {
    case 1:
        if((n%100)==0){
            x="cien";
        }else if((n%100)!=0){
            x= "ciento" + vacio;
        }
        break;
    case 5:
        x="quinientos"+ vacio;
        break;
    case 7:
        x="setecientos"+ vacio;
        break;
    case 9:
        x="novecientos"+ vacio;
        break;
    default:
        x=convierte_digito(((n/100)%10),"cientos") + vacio ;
        break;
    }

    return x;
}

string convertir(unsigned long long n){

    string res;
    res =(convierte_digito((n%100),""));
    if(((n/100)%10)){
        res=centenas(n) + res;
    }

    if(((n/1000)%100)==1){
        res="mil"+ vacio + res;
    }else{
        res=convierte_digito(((n/1000)%100),"mil") + vacio + res;
    } 
    
    if((n/1000)>=100){
        string x=convierte_digito(((n/1000)%100),"");
        res=centenas(n/1000)+x+vacio+"mil"+vacio+res;
    }

    if((n/1000000)==1){
        res="un millon";
    }

    return res;



}

int main(){
    int x;
    cout<<"ingrese un numero entre 1 a 1000000"<<endl;
    cin>>x;
    cout<< convertir(x);
}