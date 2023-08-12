#include <iostream>

using namespace std;

int factorial(int n){
	if(n == 0) return 1;
	return n*factorial(n-1);
}

int factorial_iterativa(int n){
	int res = 1;
	while(n > 0){
		res *= n;
		n--;
	}
	return res;
}

int fibonacci(int n){
	if(n == 0) return 0;
	if(n == 1) return 1;
	return fibonacci(n-1) + fibonacci(n - 2);
}

int pow2(int n){
	if(n == 0) return 1;
	return 2*pow2(n-1);
}

int pow2_iterativo(int n){
	int res = 2;
	for(int i=1; i<=n; i++){
		res = i;
	}
	return res;
}

int pow(int a, int b){
	if(b == 0) return 1;
	return a*pow(a, b-1);
}

int main() {
	int n;
	cin >> n;
	// int a = factorial(n);
	// int b = factorial_iterativa(n);
	// int c = fibonacci(n);
	int d = pow2(n);
	int e = pow2_iterativo(n);
	cout << d << '\n';
	cout << e << '\n';
}
	
