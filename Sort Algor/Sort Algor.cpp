#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <processthreadsapi.h>
#include "Algor.cpp"

using namespace std;

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main(){
    simpAlgor algor;
    iterAlgor ialgor;
    int* data;
    int const n = 4000;
    int ini[n], arr[n], arr1[n];/* arr[0][0] = 12; arr[0][1] = 32; arr[0][2] = 13; arr[0][3] = 52; arr[0][4] = 3; arr[0][5] = 30; arr[0][6] = 14; arr[0][7] = 5;*/
    for (int i = 0; i < n; i++)
        ini[i] = rand()%40000;
    
    algor.radixsort(ini, n);
    
    for (int i = 0; i < n; i++) {
        arr1[i] = ini[i];
        arr[i] = ini[i];
    }
    double begin = algor.get_cpu_time();
    algor.bubbleSort(arr, n);
    double end = algor.get_cpu_time();
    double elapsed = (end - begin) * pow(10,3);
    data = ialgor.bubbleSort(arr1, n);
    cout << "\t\t BUBBLE SORT \t\t\n";
    printf("Time measured: %.6f ms.\n", elapsed);
    cout << "The number of iterations are " << data[0] << ".\nThe number of swaps are " << data[1] << ".\n";

    for (int i = 0; i < n; i++) {
        arr1[i] = ini[i];
        arr[i] = ini[i];
    }
    begin = algor.get_cpu_time();
    algor.optbubbleSort(arr, n);
    end = algor.get_cpu_time();
    elapsed = (end - begin) * pow(10, 3);
    data = ialgor.optbubbleSort(arr1, n);
    cout << "\t\t OPTIMIZED BUBBLE SORT \t\t\n";
    printf("Time measured: %.6f ms.\n", elapsed);
    cout << "The number of iterations are " << data[0] << ".\nThe number of swaps are " << data[1] << ".\n";

    for (int i = 0; i < n; i++) {
        arr1[i] = ini[i];
        arr[i] = ini[i];
    }
    begin = algor.get_cpu_time();
    algor.selectionSort(arr, n);
    end = algor.get_cpu_time();
    elapsed = (end - begin) * pow(10, 3);
    data = ialgor.selectionSort(arr1, n);
    cout << "\t\t SELECTION SORT \t\t\n";
    printf("Time measured: %.6f ms.\n", elapsed);
    cout << "The number of iterations are " << data[0] << ".\nThe number of swaps are " << data[1] << ".\n";

    for (int i = 0; i < n; i++) {
        arr1[i] = ini[i];
        arr[i] = ini[i];
    }
    begin = algor.get_cpu_time();
    algor.insertionSort(arr, n);
    end = algor.get_cpu_time();
    elapsed = (end - begin) * pow(10, 3);
    data = ialgor.insertionSort(arr1, n);
    cout << "\t\t INSERTION SORT \t\t\n";
    printf("Time measured: %.6f ms.\n", elapsed);
    cout << "The number of iterations are " << data[0] << ".\nThe number of swaps are " << data[1] << ".\n";

    for (int i = 0; i < n; i++) {
        arr1[i] = ini[i];
        arr[i] = ini[i];
    }
    begin = algor.get_cpu_time();
    algor.mergeSort(arr, 0, n-1);
    end = algor.get_cpu_time();
    elapsed = (end - begin) * pow(10, 3);
    data = ialgor.mergeSort(arr1, 0, n-1);
    cout << "\t\t MERGE SORT \t\t\n";
    printf("Time measured: %.6f ms.\n", elapsed);
    cout << "The number of iterations are " << data[0] << ".\nThe number of swaps are " << data[1] << ".\n";

    /*for (int i = 0; i < n; i++) {
        arr1[i] = ini[i];
        arr[i] = ini[i];
    }
    begin = algor.get_cpu_time();
    algor.quickSort(arr, 0, n - 1);
    end = algor.get_cpu_time();
    elapsed = (end - begin) * pow(10, 3);
    data = ialgor.quickSort(arr1, 0, n - 1);
    cout << "\t\t Quick SORT \t\t\n";
    printf("Time measured: %.6f ms.\n", elapsed);
    cout << "The number of iterations are " << data[0] << ".\nThe number of swaps are " << data[1] << ".\n";*/

    for (int i = 0; i < n; i++) {
        arr1[i] = ini[i];
        arr[i] = ini[i];
    }
    begin = algor.get_cpu_time();
    algor.countSort(arr, n);
    end = algor.get_cpu_time();
    elapsed = (end - begin) * pow(10, 3);
    data = ialgor.countSort(arr1, n);
    cout << "\t\t COUNT SORT \t\t\n";
    printf("Time measured: %.6f ms.\n", elapsed);
    cout << "The number of iterations are " << data[0] << ".\nThe number of swaps are " << data[1] << ".\n";

    for (int i = 0; i < n; i++) {
        arr1[i] = ini[i];
        arr[i] = ini[i];
    }
    begin = algor.get_cpu_time();
    algor.radixsort(arr, n);
    end = algor.get_cpu_time();
    elapsed = (end - begin) * pow(10, 3);
    data = ialgor.radixsort(arr1, n);
    cout << "\t\t RADIX SORT \t\t\n";
    printf("Time measured: %.6f ms.\n", elapsed);
    cout << "The number of iterations are " << data[0] << ".\nThe number of swaps are " << data[1] << ".\n";

    printArray(arr, n);

    int x;
    cin >> x;
    return 0;
}