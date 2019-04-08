#include <iostream> 
#include <iomanip>

#define MAX 100

using namespace std;

int X[MAX], n , dem = 0;

bool COT[MAX], DCXUOI[MAX], DCNGUOC[MAX];

void Init(){
	cout<<"\nNhap n= ";
	cin>> n;
	for(int i = 1; i <= n; i++){
		COT[i] = true;
	}
	for(int i = 1; i < 2*n; i++){
//		thiet lap duong cheo
		DCNGUOC[i] = true;
		DCXUOI[i] = true;
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
		if(COT[j] && DCXUOI[i -j + n] && DCNGUOC[i + j -1]){
//			neu chua co con hau nao
			X[i] = j; //ta dat duoc con hay vao
			COT[j] = false;
			DCNGUOC[i + j -1] = false;
			DCXUOI[i - j + n] = false;
			if( i == n)Result();
			else Try(i+1);
			COT[j] = true;
				DCNGUOC[i + j -1] = true;
			DCXUOI[i - j + n] = true;
			
 		}
	}
}

int main(){
	Init();
	Try(1);
}
