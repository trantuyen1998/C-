#include<iostream>
#include<iomanip>

#define MAX 100
using namespace std;

int X[MAX],n,dem=0;
bool OK = true;

void Init(void){
	cout<<"Nhap n:";
	cin>> n;
	for(int i=1;i <= n; i++){
		X[i] = 0;
	}
}

void Result(void){
//	dua ra xau nhi phan hien tai
	cout<< "\nXau thu "<< ++dem<<":";
	for(int i=1; i <=n; i++){
		cout<< X[i] <<setw(3);
	}
}

void Next_Bits_String(void){
	int i = n;
	while(i > 0 && X[i]){
//		duyt tu vi tri ben phai nhat 
		X[i] = 0;//neu gap X[i] = 1 chuyen thanh 0
		i--;
	}
	if(i > 0) X[i] = 1; // gap X[i] =  0 dau tien chuyen thanh 1
	else OK = false;
	
}

int main(){
	Init();
	while(OK){
		Result();
		Next_Bits_String();//sinh ra cau hinh tiep theo
	}
}
