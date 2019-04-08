#include <iostream>
#include <iomanip>

using namespace std;

int power(int x, unsigned int n){
	if(n == 0) return 1;
	else if(n % 2 == 0 ) return power(x,n/2) * power(x,n/2);
	else return x * power(x,n/2) * power(x,n/2); 
}

int main(){
	int x =2;
	unsigned int n =5;
	cout << power(x,n) << setw(3);
}
