#include <iostream>
#include <iomanip>

#define MAX 100
int X[MAX], n, dem =0;
bool chuaxet[MAX];

using namespace std;

void Init(){
	cout <<"Nhap vao so n:";
	cin>> n;
	
	for(int i =1;i <=n;i++){
		chuaxet[i] = true;
	}
}

void Result(){
	cout<< "\nKet qua "<< ++dem <<":";
	for(int i = 1; i <= n; i++){
		
	
		cout << X[i] << setw(3);
	}
}

void Try(int i){
	for(int j = 1; j <= n; j++){
		if(chuaxet[j]){
			X[i] = j;
			chuaxet[j] = false;
			if(i == n)
				Result();
			else
				Try(i+1);
				chuaxet[j] =  true;
		}
	}
}

int main(){
	Init();
	Try(1);
}
