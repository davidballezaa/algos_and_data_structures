#include <iostream>

using namespace std;

int sum_prev_recursion(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return n+sum_prev_recursion(n - 1);
}

int sum_prev_iterativo(int n){
    int res = 0;
    while(n > 0){
	res += n;
	n--;
    }
    return res;
}

int sum_prev_formulazo(int n){
    return (n*(n+1))/2;
}


int main() {
    int n;
    cout << "Suma de 1 a N" << '\n';
    cout << "Ingresa N: ";
    cin >> n;
    cout << "Recursivo: " << sum_prev_recursion(n) << '\n';
    cout << "Iterativo: " << sum_prev_iterativo(n) << '\n';
    cout << "Formulazo: " << sum_prev_formulazo(n) << '\n';
    return 0;
}

