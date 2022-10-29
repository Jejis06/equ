#include <iostream>
#include <math.h>

typedef long long ull;

using namespace std;

//global pointer for convinience
ull** mem = nullptr;

//recursive part of equasion
template<typename INT> INT eq(INT x,INT k, INT n){
	

	if (k == 0) return 0;

	INT sum = 0;
	

	if(mem[n][k] != -1) {
		return mem[n][k];
	}

	if (k == 1){
		sum = pow(n,2) - n;
		for(INT i=1;i<n;i++){
		       	sum -= i;
		}
		mem[n][k] = sum;
		return sum;
	}	

	for(int i=1;i<n;i++){
		sum += (n-i) * eq<INT>(x,k-1,n-i) * pow(x,n - (n - (i-1)));
	}

	mem[n][k] = sum;
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

		ull** t= new ull*[m+1];
		for(int i=0;i<m+1;i++) t[i] = new ull[m +1];	
		mem = &t[0];

		for(int i=0;i<m+1;i++){
			for(int j=0;j<m+1;j++) mem[i][j] = -1;
		}

		for(int i=0;i<m;i++){
			display_and_compute<ull>(1,n+i);
		}
		delete[] t;
		return 0;
	}

	ull** t= new ull*[n+1];
	for(int i=0;i<n+1;i++) t[i] = new ull[n+1];	
	mem = &t[0];

	for(int i=0;i<n+1;i++){
		for(int j=0;j<n+1;j++) mem[i][j] = -1;
	}

	cout << compute<ull>(1,n) << '\n'; 
	cout << verify<ull>(1,n) << '\n'; 
	
	delete[] t;
}
