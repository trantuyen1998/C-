#include <iostream>
#include <cstring>
#include <iomanip>

#define MAX 100
using namespace std;
typedef struct Tanxuat{
	char kytu;
	int solan;
};

int Search(Tanxuat X[], int n,char t){
	for(int i =0;i <= n;i++){
		if(X[i].kytu ==  t)
		   return i;
	}
	return n+1;
}

int Tack_Kitu(char S[], Tanxuat X[], int n){
	int k = strlen(S);
	for(int i = 0; i < k; i++){
		int p = Search(X,n,S[i]);
		if(p <= n) X[p].solan++;
		else{
			n = p;
			X[p].kytu = S[i];
			X[p].solan = 1;
		}
	}
	return n;
}

void Sort(Tanxuat X[],int n){
	Tanxuat t;
	for(int i = 0; i<n;i++){
		for(int j = i +1;j <= n ; j++){
			if(X[i].solan < X[j].solan){
				t = X[i];
				X[i] = X[j];
				X[j] = t;
			}
		}
	}
}

void Greendy_Solution(){
	char S[MAX];
	cout<<"Nhap sau S:";
	cin>> S;
	int d;
	cout<<"\nNhap khoang cach d:";
	cin >> d;
	int m = -1,n = strlen(S), chuaxet[MAX];
	 Tanxuat X[255];
	char STR[MAX];
	for(int i = 0; i<n;i++)
		chuaxet[i] =  true;
//		xac dinh ki tu can dat
//		b1.tim ki tu va so lan xuat hien moi ki tu
		m = Tack_Kitu(S,X,m);
//		b2.sap xep giam dan theo so lan xuat hien
		Sort(X,m);
		for(int i =0; i <= m;i++){
			int k =X[i].solan; //lay ki tu xua hien nhieu nhat
			int t = 0;
			while(!chuaxet[t]) t++;
			for(int q = 0; q < k; q++){
				if((t+ q*d) >= n){
					cout <<"No solution";
					return;
				} 
				STR[t + q*d] = X[i].kytu;//dat lai vi tri t + q*d la ok
				chuaxet[t +q*d] = false;// danh dau vi tri nay da duoc dat
				
			}
		
		}
			STR[n] = '\0';
			cout<< STR;// dua ra phuong an
	
}

int main(){
	Greendy_Solution();
}
