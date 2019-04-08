#include <iostream>
#include <iomanip>

#define MAX 100
using namespace std;

int X[MAX], n, k, dem = 0;
bool OK = true;

void Init(){
	cout<<"Nhap vao n, k:";
	cin>> n>>k;
	
	for(int i = 1;i <= k; i++){
		X[i] = i;
	}
}

void Result(){
	cout << "\nKet qua "<< ++dem << ":";
	for(int i = 1; i <= k; i++){
//		dua ra cau hinh
		cout << X[i] <<setw(3);
	}
}

void next_Combination(){
	int i = k; //duyet tu ben phai nhat cua tap con
	while( i > 0 && X[i] == n-k+i)
		 //tim i sao cho xi # n-k-i vi i chua phai cau hinh cuoi
		 
		 i--;
		 if(i > 0){
//		 	neu chua phai tap con cuoi cung 
			X[i] = X[i] + 1;
			for(int j = i +1; j <= k; j++){
				X[j] = X[i] + j - i;
			}
		 }
		 else{
		 	OK =  false;
		 }
		
	
}

int main(){
	Init();
	while(OK){
		Result();
		next_Combination();
	}
}
