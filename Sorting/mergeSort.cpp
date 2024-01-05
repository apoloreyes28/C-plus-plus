#include <iostream>
#include <vector>

using namespace std;

// Función para combinar dos subarreglos ordenados en uno solo
void merge(vector<int>& arr, int left, int middle, int right) {
    // Calcular el tamaño de los subarreglos
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Crear subarreglos temporales
    vector<int> leftSubarray(n1);
    vector<int> rightSubarray(n2);

    // Copiar datos a los subarreglos temporales leftSubarray[] and rightSubarray[]
    for (int i = 0; i < n1; i++)
        leftSubarray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightSubarray[j] = arr[middle + 1 + j];

    // Combinar los subarreglos temporales en el arreglo original arr[]
    int i = 0; // Índice inicial del primer subarreglo
    int j = 0; // Índice inicial del segundo subarreglo
    int k = left; // Índice inicial del arreglo combinado

    while (i < n1 && j < n2) {
        if (leftSubarray[i] <= rightSubarray[j]) {
            arr[k] = leftSubarray[i];
            i++;
        } else {
            arr[k] = rightSubarray[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de leftSubarray[], si los hay
    while (i < n1) {
        arr[k] = leftSubarray[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de rightSubarray[], si los hay
    while (j < n2) {
        arr[k] = rightSubarray[j];
        j++;
        k++;
    }
}

// Función principal para dividir y ordenar recursivamente el arreglo
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // Encuentra el punto medio del arreglo
        int middle = left + (right - left) / 2;

        // Ordena la primera y segunda mitad del arreglo
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Combina las mitades ordenadas
        merge(arr, left, middle, right);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original Array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    // Llama a la función mergeSort para ordenar el arreglo
    mergeSort(arr, 0, arr.size() - 1);

    cout << "Ordered Array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

