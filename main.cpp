#include <iostream>
#include <math.h>
using namespace std;

//recursive parto fo equasion
template<typename INT> INT eq(INT x,INT k, INT n){

	if (k == 0) return 0;

	INT sum = 0;
	
	if (k == 1){
		sum = pow(n,2) - n;
		for(INT i=1;i<n;i++){
		       	sum -= i;
		}
		return sum;
	}	

	for(int i=1;i<n;i++){
		sum += (n-i) * eq<INT>(x,k-1,n-i) * pow(x,n - (n - (i-1)));
	}

	return sum;

}

//compute equasion for given `n` and `x`
template<typename INT> INT compute(INT x,INT n){
	
	INT sum = 0;
	for(int i=1;i<=(n-1);i++)
		sum += eq<INT>(x,i,n);

	return sum + pow(x,n);
}

//TODO: unspagettize
template<typename INT> void display_and_compute(INT x, INT n){
	INT sum = 0;
	cout << "x";
	if(n-1) cout <<'^'<<n;
	if (n-1) cout << " + ";

	for(int i=1;i<=(n-1);i++){
		INT mul = eq<INT>(x,i,n);
		if(mul-1){
			cout << mul; 
		}
		cout << 'x';
		if(n-i-1) cout << '^'<<n-i;

		if(i < (n-1)) cout << " + ";
	}
	cout << '\n';
	
	return;

}

//verrify if equasion is working
template<typename INT> INT verify(INT x,INT n){
	
	INT sum = 1;
	for(int i=0;i<=(n-1);i++)
		sum *= (x+i);

	return sum;
}

int main(int argc, const char* argv[]){
	
	cout.tie();
	ios_base::sync_with_stdio(0);

	if (argc < 2) return 0;

	/*
	 * ./name_of_program 1 4 - prints equasion in math format without computing them for n 1 through 4
	 * ./name_of_program 4 - calculates a value using a value and compares it to normal way
	 *
	 */
		
	int n = atoi(argv[1]);	

	if (argc >= 3){
		int m = atoi(argv[2]);
		for(int i=0;i<m;i++){
			display_and_compute<unsigned long long int>(1,n+i);
		}
		return 0;
	}
	cout << compute<unsigned long long int>(1,n) << '\n'; 
	cout << verify<unsigned long long int>(1,n) << '\n'; 
}
