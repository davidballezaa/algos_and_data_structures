// O(nlogn) => merge sort
#include <iostream>

using namespace std;

void merge(int *A, int l, int midpoint, int r){
    int s1 = m-l + 1;
    int s2 = r-m;

    int L[s1];
    int R[s2];
    // copy L, R
    for(int ic = 0; ic < s1; ic++){
        L[ic] = A[l + ic];
    }

    for(int jc = 0; jc < s2; jc++){
        R[jc] = A[m + l + jc];
    }
    int i = 0, j = 0;
    int k = l;
    while(i < s1 && j < s2){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i += 1;
        } else {
            A[k] = R[j];
            j += 1;
        }
        k += 1;
    }
    while(i < s1){
        A[k] = L[i];
        i += 1;
        k += 1;
    }
    while(j < s2){
        A[k] = L[j];
        j += 1;
        k += 1;
    }

}

void mergeSort(int *A, int l, int r){
    if(l < r){
        int midpoint = l+(r-l)/2;
        mergeSort(l, midpoint);
        mergeSort(midpoint+1, r);
        merge(A, l, r);
    }
}

int main(int argc, char* argv[]){
    return 0;
}