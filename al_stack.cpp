#include <iostream>
#include <iomanip>
#define MAXSIZE 5

using namespace std;

typedef struct STK{
	int top;
	int node[MAXSIZE];
};

class STACK{
	public:
		STK s;
		void push(){
//			kiem tra stack push phan tu vao stack
			int value;
			if(s.top == (MAXSIZE -1)){
				cout <<"Tran stack:"<<endl;
				return;
			}else{
				cout<<"\nNhap phan tu:";
				cin>> value;
				s.top = s.top +1;
				s.node[s.top] = value;
			}
		}
		int  pop(){
			int value;
			if(s.top == -1){
//				neu stack rong 
				cout<<"Stack rong:"<<endl;
				return(INT_MIN);
			}
			else{
				value =  s.node[s.top];
				cout<<"Phan tu bi loai:"<< s.node[s.top] <<endl;
				s.top = s.top -1;
			}
			return value;
		}
		void display(){
			if(s.top == -1){
				cout<<"khong co j de duyet";
				
			}else{
				cout<<"noi dung cua stack:"<<endl;
				for(int i = s.top; i >=0 ;i--) cout << s.node[i] <<setw(3);
			}
		}
		STACK(){
//			contructor
			s.top = -1; //rong
		}
};

int main(){
	STACK X;
	int choice;
	cout <<"Cac thao tac tren stack:";
	do{
		cout<<"-------------------------\n";
		cout<< "1-PUSH\n";
		cout<< "2-POP\n";
		cout<< "3- DISPLAY\n";
		cout<<"0- EXIT\n";
		cout<<"\n Dua vao lua chon cua ban";
		cin >> choice;
		switch(choice){
			case 1: X.push();
			        break;
			case 2: X.pop();
					break;
			case 3:
					X.display();
					break;
			default:
				cout<<"Lua chon sai:";break;
		}
	}while(choice!=0);
}
