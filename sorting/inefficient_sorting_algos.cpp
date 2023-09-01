// Bubble sort, swap sort, selection sort => O(n^2)

#include <iostream>

using namespace std;

void bubbleSort( int *A, int n)
{	
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

void swapSort (int *A, int n)
{	
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

void selectionSort(int *A, int n)
{	
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

void printArray (int *A, int n)
{	
	cout<<"\nArreglo:\t";
	for (int i = 0; i < n; i++)
	{	
		cout<<' '<<A[i];	
	}
	cout<<'\n';
}

int main(int argc, char* argv[]) 
{	
	int n = 10;						//	Elementos totales

	int asorted1 [n] = { 8, 4, 1, 7, 9, 3, 5, 2, 10, 6 };
	int asorted2 [n] = { 8, 4, 1, 7, 9, 3, 5, 2, 10, 6 };
	int asorted3 [n] = { 8, 4, 1, 7, 9, 3, 5, 2, 10, 6 };
	
	printArray(names, n);

	// bubbleSort(asorted1, n);
	// printArray(asorted1, n);


	// selectionSort(asorted2, n);
	// printArray(asorted2, n);

	// swapSort(asorted1, n);
	// printArray(asorted1, n);

}








