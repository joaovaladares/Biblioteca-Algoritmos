#include <iostream>

using namespace std;

void merge(int arr[], int left, int middle, int right){
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    //criando arrays temporarios
    int arr1[n1], arr2[n2];

    //copiando data pros arrays temporarios
    for (i = 0; i < n1; i++) {
        arr1[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        arr2[j] = arr[middle + 1 + j];
    }

    //merge dos array temporarios de volta pro original
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    //copie os elementos restantes de arr1[], se houver
    while (i < n1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    //copie os elementos restantes de arr2[], se houver
    while (j < n2) {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (right > left) {
        int middle = (left + right)/2; //encontre o meio do array para poder dividi-lo em dois
        mergeSort(arr, left, middle); //dividindo o array pro lado esquerdo
        mergeSort(arr, middle + 1, right); //dividing o array pro lado direito
        merge(arr, left, middle, right); //merge nas duas metades que foram ordenadas nos dois passos anteriores
    }
}
