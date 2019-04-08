#include <iostream>
#include <iomanip>

#define MAX 100

using namespace std;

int X[MAX], n, dem = 0;

void Init(){
	cout<< "\nNhap n= ";
	cin>> n;
}

void Result(){
     cout << "\nKet qua "<< ++dem<<":";
     for(int i = 1; i <= n; i++){
     	cout<< X[i]<< setw(3);
	 }
}

void Try(int i){
	for(int j = 0; j <= 1; j++){
		X[i] = j;
		if(i == n) Result();
		else{
			Try(i+1);
		}
	}
}

int main(){
	Init();
	Try(1);
}
