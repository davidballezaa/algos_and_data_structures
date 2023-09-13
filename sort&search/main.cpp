#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>

using namespace std;

/* ALGORITMOS DE ORDENAMIENTO */

// bubbleSort. Time Complexity: O(n^2) Space Complexity: O(1)
void bubbleSort(vector<int> &A){
	int n = A.size();
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(A[j] > A[j+1]){
				int aux = A[j+1];
				A[j+1] = A[j];
				A[j] = aux;
			}
		}
	}
}

// swapSort. Time Complexity: O(n^2) Space Complexity: O(1)
void swapSort(vector<int> &A){
	int n = A.size();
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(A[i] > A[j]){
				int aux = A[i];
				A[i] = A[j];
				A[j] = aux;
			}
		}
	}
}

// selectionSort. Time Complexity: O(n^2) Space Complexity: O(1)
void selectionSort(vector<int> &A){
	int n = A.size();
	for(int i=0; i<n-1; i++){
		int minIndex = i;
		for(int j=i+1; j<n; j++){
			if(A[j] < A[minIndex]) minIndex = j;
		}
		int aux = A[minIndex];
		A[minIndex] = A[i];
		A[i] = aux;
	}
}

// insertionSort. Time Complexity: O(n^2) Space Complexity: O(1)
void insertionSort(vector<int> &A){
	int n = A.size();
	for(int i=0; i<n; i++){
		int element = A[i];
		int j = i - 1;
		while(j >= 0 && A[j] > element){
			A[j+1] = A[j];
			j -= 1;
		}
		A[j+1] = element;
	}
}

// mergeSort. Time Complexity: O(nlogn) Space Complexity: O(n)
void merge(vector<int> &A, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = A[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &A, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);
        merge(A, l, m, r);
    }
}

// quickSort. Time Complexity: O(nlogn) Space Complexity: O(1)
int partition(vector<int> &A, int left, int right) {
    int pivot = A[right];
    int i = (left - 1);

    for (int j = left; j <= right - 1; j++) {
        if (A[j] < pivot) {
            i++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i + 1], A[right]);
    return (i + 1);
}

void quickSort(vector<int> &A, int left, int right) {
    if (left < right) {
        int pi = partition(A, left, right);

        quickSort(A, left, pi - 1);
        quickSort(A, pi + 1, right);
    }
}

// ordenar_arreglo(vector, opcion) => Ordena el vector dado como parametro usando el numero de algoritmo dado en opcion
void ordenar(vector<int> &arreglo, int opcion){
	// Ordenamos arreglo con base en el algoritmo seleccionado
		// 1: bubbleSort
		// 2: swapSort
		// 3: selectionSort
		// 4: insertionSort
		// 5: mergeSort
		// 6: quickSort
	switch(opcion){
		case 1:
			cout << "Usando bubble sort \n";
			bubbleSort(arreglo);
			break;
		case 2:
			cout << "Usando swap sort \n";
		 	swapSort(arreglo);
			break;
		case 3:
			cout << "Usando selection sort \n";
			selectionSort(arreglo);
			break;
		case 4:
			cout << "Usando insertion sort \n";
		 	insertionSort(arreglo);
			break;
		case 5:
			cout << "Usando merge sort \n";
			mergeSort(arreglo, 0, arreglo.size() - 1);
			break;
		case 6:
			cout << "Usando quick sort \n";
			quickSort(arreglo, 0, arreglo.size() - 1);
			break;
		default:
			cout << "Error, algoritmo inexistente\n"; 
			break;
	}
}

// imprimir_arreglo(vector) => Imprime el vector dado como parametro
void imprimir_arreglo(vector<int> &arreglo){
	int n = arreglo.size();
	for(int i=0; i<n; i++){
		cout << arreglo[i] << " ";
	}
	cout << '\n';
}

/* ALGORITMOS DE BUSQUEDA */

// sequentialSearch. Time Complexity: O(n) Space Complexity: O(1)
// sequentialSearch(vector, valor_a_buscar) => Devuelve indice del valor a buscar
int sequentialSearch(vector<int> &A, int searchValue){
	int n = A.size();
	for(int i=0; i<n; i++){
		if(A[i] == searchValue) return i;
	}
	return -1;
}

// binarySearch. Time Complexity: O(logn) Space Complexity: O(1)
// binarySearch(vector, valor_a_buscar) => Devuelve indice del valor a buscar
int binarySearch(vector<int> &A, int searchValue){
	int n = A.size();
	int left = 0;
	int right = n - 1;
	while(left <= right){
		int mid = left + (right - left)/2;
		if(A[mid] == searchValue) return mid;
		else if(A[mid] < searchValue) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}

// busqueda(vector, opcion, valor_a_buscar) => Busca el valor en el vector dado con base en el algoritmo especificado en opcion 
int busqueda(vector<int> &arreglo, int opcion, int searchValue){
	switch(opcion){
		case 1:
			cout << "Usando sequential search para encontrar: " << searchValue << '\n';
			return sequentialSearch(arreglo, searchValue);
		case 2:
			cout << "Usando binary search para encontrar: " << searchValue << '\n';
		 	return binarySearch(arreglo, searchValue);
		default:
			return -1;
	}
}

int main(int argc, char* argv[])
{
	// Linea leida del archivo
	string sline;
	// Variables auxiliares
	int index, n, indexFound;
	char operacion;
	// Arreglo de enteros
	vector<int> arreglo;

	ifstream inFile("inputFile.txt"); 	    //  input file stream

	//	Verifica que el archivo se haya abierto correctamente
	if (inFile.is_open())
	{	//	Lee linea a linea
		while ( getline(inFile, sline) )
		{	
			// Obtiene linea completa
			string line = sline;

			// Obtiene operacion (1): Ordenamiento, (2) Busqueda y (3) Finalizar
			index = line.find(" ");
			operacion = line.substr(0, index)[0];
			switch(operacion){
				case '1':
					line = sline.substr(index+1);
					index = line.find(" ");
					// Obtenemos numero de elementos "n"
					n = stoi(line.substr(0, index));
					// Llenar arreglo con los n elementos
					for(int i = 0; i < n; i++){
						line = line.substr(index+1);
						index = line.find(" ");
						arreglo.push_back(stoi(line.substr(0, index)));
					}
					cout << "Arreglo original: \n";
					imprimir_arreglo(arreglo);
					cout << "\n";
			
					// Ordenamos arreglo con base en el algoritmo seleccionado
						// 1: bubbleSort
						// 2: swapSort
						// 3: selectionSort
						// 4: insertionSort
						// 5: mergeSort
						// 6: quickSort

					for(int j=0; j<6; j++){
						// Copiamos arreglo para no modificar el original
						vector<int> arregloCpy(arreglo);
						// Ordenamos arreglo copia con los 6 algoritmos posibles de ordenamiento
						ordenar(arregloCpy, j+1);
						cout << "Arreglo ordenado: \n";
						imprimir_arreglo(arregloCpy);
						cout << "\n";
					}

					break;
				case '2':
					line = sline.substr(index+1);
					index = line.find(" ");

					// Obtenemos número a buscar "n"
					n = stoi(line.substr(0, index));
					// Buscamos en arreglo con base a algoritmo seleccionado
						// 1: sequentialSearch
						// 2: binarySearch
					// busqueda(arreglo, opcion, numero_a_buscar)
					for(int j=0; j<2; j++){
						indexFound = busqueda(arreglo, j+1, n);
						if(indexFound != -1){
							cout << "Encontramos el valor: " << n << " en la posicion: " << indexFound << " del arreglo ordenado\n";
						} else {
							cout << "No encontramos el valor: " << n << " en el arreglo ordenado\n";
						}
						cout << "\n";
					}
					break;
				case '3':
				 	cout << "GRACIAS POR USAR EL SISTEMA" << endl;
					return 0;
				default:
				 	cout << "Operacion invalida. Intenta de nuevo. \n";
					return 0;
			}
		}
	}
	inFile.close();
	return 0;
}