#include <iostream>
#include <iomanip>

#define MAX 100
using namespace std;

class Queue{
	public:
		int node[MAX];
		int inp;//dua phan tu vao hang doi
		int out;//lay phan tu ra hang doi
		void Push(){
			int value;
			if(inp == MAX -1)
				cout <<"Tran hang doi"<<endl;
			else{
//				neu hang doi chua day
				if(out == -1)//hang doi rong
					out = 0;
				cout<< "gia tri node:";
				cin>> value;
				inp = inp +1;
				node[inp] = value;//luu tru trong node
			}
		}
		void Pop(){
//			lay gia tri ra khoi hang doi
			if(out == -1 || out > inp){
				cout<< "Queue rong"<<endl;
				return;
			}else{
				cout<<"Node duoc lay ra:"<<node[out]<<endl;
				out = out +1;
			}
		}
	    void display(){
	    	if(out== -1){
	    		cout<<"Queue isEmpty"<<endl;
	    		
			}else{
				cout<<"noi dung hang doi:";
				for(int i =out;i<= inp;i++){
					cout<< node[i] <<setw(3);
					cout<<endl;
				}
			}
		}
		Queue(){
			inp = -1;
			out = -1;
		}
};

int main(){
	int choice;
	Queue X;
	do{
		cout<<"1.dua phan tu vao hang doi"<<endl;
		cout<<"2.lay phan tu ra khoi hang doi"<<endl;
		cout<<"3.duyet not hang doi"<<endl;
		cout<<"0.thoat";
		cout<<"\nNhap vao lua chon:";
		cin >> choice;
		switch(choice){
			case 1: X.Push();
					break;
			case 2: X.Pop();
					break;
			case 3: X.display();
					break;
			default: 
					cout<<"lua chon sai:"<<endl;
					break;
		}
	}while(choice != 0);
}
