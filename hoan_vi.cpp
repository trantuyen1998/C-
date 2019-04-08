#include <iostream>
#include <iomanip>

#define MAX 100
using namespace std;

int X[MAX], n, dem = 0;
bool OK = true;

void Init(){
	cout<<"Nhap gia tri cua n:";
	cin>> n;
	for(int i = 1; i <= n; i++){
		X[i] = i;
	}
}

void Result(){
	cout<<"\nKet qua "<<++dem << ":";
	for(int i = 1; i <= n; i++){
		cout<< X[i] << setw(3);
	}
}

void next_Permutation(){
	int j = n-1;
	while(j > 0 && X[j] > X[j+1])
			j--;
		if(j > 0){
//			neu chua phai cau hinh cuoi
			int k = n;
			while(X[j] > X[k]) // tim chi so k sao cho X[j] < X[k]
				k--;
			int t = X[j];
			    X[j] = X[k];
			    X[k] = t;
			int r = j+1, s = n;
			while(r <= s){
//				lat nguoc 
			t = X[r];
			X[r] = X[s];
			X[s] = t;
			r++;
			s--;
			}
		}else{
			OK = false;
		}
}

int main(){
	Init();
	while(OK){
		Result();
		next_Permutation();
	}
}
