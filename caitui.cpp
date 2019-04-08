#include <iostream>
#include <iomanip>
#include <fstream>

#define MAX 100

using namespace std;

int X[MAX];
int n;
float b,weight = 0;
float cost = 0;

int XOPT[MAX]; //phuong an toi uu cua bai toan
float FOPT = 0; //gia tri toi uu cua bai taon

float A[MAX], C[MAX];//vector trong luong va gia tri su dung

void Init(){
	ifstream fp("Caitui.in"); 
	fp>> n;
	fp>>b;
	for(int i = 1;i<= n;i++){
		fp >> A[i] >> C[i];
	}
	fp.close();
}


void Result(){
	cout<<"Gia tri toi uu:"<<FOPT<<endl;
	cout<< "Phuong an toi uu:";
	for(int i =1;i<=n;i++){
		cout<< XOPT[i]<<" ";
	}
}

void update(){
	if(cost > FOPT){
		FOPT = cost;
		for(int i = 1;i<= n;i++)
				XOPT[i] = X[i];
	}
}

void Back_Track(int i){
	int j, t=(int)(b-weight)/A[i];
	for(int j = t; j >= 0; j--){
		X[i] = j;
		weight = weight + A[i] * X[i];
		cost = cost + C[i] * X[i];
		if(i == n) update();
		else if(cost + (C[i +1] *((b-weight)/A[i+1]))> FOPT)
				Back_Track(i+1);
			weight = weight - A[i]* X[i];
			cost = cost -C[i] *X[i];
	}
}

int main(){
	Init();
	Back_Track(1);
	Result();
}

