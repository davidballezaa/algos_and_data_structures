#include <iostream>
#include <cstdlib>
#include <vector>

using std::cin;
using std::cout;
using std::endl;



int busquedaBinariaRec(int A[], int l, int r, int x)
{	
	if(r < l) return -1;
	int mid_point = l + (r - l) / 2;
	if(A[mid_point] == x) return mid_point;
	else if(x > A[mid_point]){
		l = mid_point + 1;
	} 
	else {
		r = mid_point - 1;
	}
	return busquedaBinariaRec(A, l, r, x);
}

//	Busqueda binaria iterativa
int busquedaBinaria(int A[], int n, int x)
{   
	int left = 0;
	int right = n - 1;
	while(left <= right){
		int mid_point = left + (right - left)/2;
		if(A[mid_point] == x){
			return mid_point;
		} else {
			if(A[mid_point] > x){
				right = mid_point - 1;
			} else {
				// A[mid_point] < x
				left = mid_point + 1;
			}
		}
	}
	return -1;
}


int busquedaSecuencial(int *A, int n, int x)
{	
	for(int i=0; i<n; i++){
		if(A[i] == x){
			return i;
		}
	}
	return -1;
}


int main(int argc, char* argv[]) 
{	
	const int n = 10;		//	Elementos totales
	int x;					//	Elemento a buscar
	
	int indexSeq, indexBin, indexBinRec;

	//	Arreglos: ordenado y desornado
	int sorted [n] =  { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };	
	int asorted [n] = { 8, 4, 1, 7, 9, 3, 5, 2, 10, 6 };

	x = atoi(argv[1]);		//	Valor a buscar, leido desde consola
	//cin >> x;
	//x = 4;


	//	Imprimir los arreglos donde se buscara
	
	int i;
	cout<<"Desordenado:\t";
	for (i = 0; i < n; i++){
		cout<<asorted[i]<<' '; 
	} 
	cout<<'\n';
	
	cout<<"Ordenado:\t";
	for (i = 0; i < n; i++){
		cout<<sorted[i]<<' '; 
	} 
	cout<<'\n';

	cout<<"\nBuscando:\t"<< x <<'\n';
	cout<< "Buscando x = " << x << " en asorted con busq. secuencial: "<< '\n';
	indexSeq = busquedaSecuencial(asorted, n, x);
	cout << "Encontrado en: " << indexSeq << " " << '\n' << '\n';


	cout << "Buscando x = " << x << " en sorted con busq. secuencial: "<< '\n';
	indexSeq = busquedaSecuencial(sorted, n, x);
	cout << "Encontrado en: " << indexSeq <<'\n'<< '\n';



	cout << "Buscando x = " << x << " en sorted con busq. binaria: " << '\n' ;
	indexBin = busquedaBinaria(sorted, n, x);
	cout << "Encontrado en:  " << indexBin << '\n'<<'\n';



	cout << "Buscando x = " << x << " en sorted con busq. binaria recursiva: " ;
	indexBinRec = busquedaBinariaRec(sorted, 0, n-1 , x);	
	cout << "Encontrado en:  " << indexBinRec << '\n'<< '\n';

}
