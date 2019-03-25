//simples metodo para troca de valores de posicoes em um array
void swap(int arr[], int i, int j) {
    int aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

/*
 * partiçao utilizando o metodo de Lomuto
 * utilizando tres segmentos (com o pivo no começo)
 *
 * arr[] - array a ser ordendado
 * low - primeiro elemento do array(menor indice)
 * high - ultimo elemento do array(maior indice)
 */
int lomutoPartition(int arr[], int low, int high) {
    int pivot = arr[low];
    int split = low;
    for (int i = low + 1; i < high + 1; i++){
        if (arr[i] < pivot) {
            split++;
            swap(arr, split, i);
        }
    }
    swap(arr, low, split);
    return split;
}

/*
 * particao utilizando o metodo de Hoares
 * varrer o array simultaneamente do inicio e fim
 */
int hoarePartition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high + 1;
    do {
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        swap(arr, i, j);
    } while (i < j);
    swap(arr, i, j);
    swap(arr, low, j);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int split = hoarePartition(arr, low, high); //escolha qual tipo de partition deseja usar
        quickSort(arr, low, split - 1); //chamada recursiva de low ao elemento anterior ao split
        quickSort(arr, split + 1, high); //chamada recursiva do elemento posterior a split a high
    }
}
