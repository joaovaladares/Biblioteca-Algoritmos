void swap(int arr[], int i, int j) {
    int aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

void selectionSort(int arr[], int arrSize) {
    for (int i = 0; i < arrSize - 1; i++){
        int min = i;
        for (int j = i + 1; j < arrSize; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr, i, min);
    }
}