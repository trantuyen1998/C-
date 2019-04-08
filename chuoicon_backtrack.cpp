#include<iostream>
#include<iomanip>

#define MAX 100

using namespace std;

int X[MAX],n,k,dem = 0;

void Init(){
	cout<< "Nhap vao n, k:";
	cin>> n >> k;
	
}

void Result(){
	cout<< "\nKet qua "<< ++dem << ":";
	for(int i = 1; i <= k;i++){
		cout<< X[i] << setw(3);
	}
}

void Try(int i){
	for(int j =  X[i-1] +1; j <= n-k + i; j++){
		X[i] = j;
		if(i == k) Result();
		else Try(i+1);
		}
}


int main(){
	 X[0] =0;
	Init();
	Try(1);
}
