#include <iostream>

using namespace std;

int main(int argc, char* argv[]){

	// log(n)
	int j = 32;
	while(j > 1){
		j /= 2;
	}

	int example(int n){
		if(n < 1) return 1;
		return 5*recursiva(n/2); // n / 2 => log(n)
	}

	// 2^n
	int example2(int n){
		if(n == 0) return 1;
		return example2(n-1) + example2(n-1);

	// n*log(n)
	n = 32;
	for(int i=0; i<n; i++){
		int j = n;
		while(j > 1){
			j /= 2;
		}
	}

	return 0;
}

