#include <iostream>
#include <fstream>
#include <iomanip>

#define MAX 100

using namespace std;

int S[MAX],F[MAX],n, dem =0;
bool XOPT[MAX];

// doc du lieu tu file

void Read_Data(){
	ifstream fp("data.in");
	fp >> n;
	for(int i =1; i <= n; i++){
		fp >> S[i];
		fp >> F[i];
		XOPT[i] = false;
	}
	fp.close();

}
// sap xep tang dan theo thoi gian

void Sap_xep(){
	for(int i  = 1; i <= n -1; i++){
		for(int j = i +1; j <= n; j++){
			if(F[i] > F[j]){
				int temp = F[i];
				F[i]  = F[j];
				F[i] = temp;
//				temp  = S[i];
//				S[i] = S[j];
//				S[i] = temp;
				
			}
		}
	}
}

//dua ra ket qua

void Result(){
	ofstream fp("ketqua.out");
	fp << dem << endl;
	for(int i =1;i<=n;i++){
		if(XOPT[i]){
			fp<< i <<setw(3);
		}
	}
}
void Greendy_solution(){
	Read_Data();
	Sap_xep();
	int i =1;
	XOPT[i]= true;
	dem = 1;
	for(int j =2; j <= n; j++){
		if(F[i] <= S[j]){
			dem++;
			i = j;
			XOPT[i] = true;
		}
	}
	Result();
}

int main(){
	Greendy_solution();
}
