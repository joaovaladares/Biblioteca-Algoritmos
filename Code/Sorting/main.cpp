#include <iostream>

using namespace std;

int binarySearch(int arr[], int num, int arrSize) {
    int left = 0;
    int right = arrSize - 1;
    while (left <= right) {
        int mid = (left + right)/2;
        if (num == arr[mid]) {
            return mid;
        } else if (num < arr[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

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

int main() {
    int numBooks, money, minDiff, book1, book2;
    while (cin >> numBooks) {
        int *bookPrices = new int[numBooks];
        for (int i = 0; i < numBooks; i++) {
            cin >> bookPrices[i];
        }
        selectionSort(bookPrices, numBooks);
        cin >> money;
        minDiff = money;
        for (int i = 0; i < numBooks; i++) {
            int aux1 = bookPrices[i];
            int aux2 = money - aux1;
            if (aux1 > aux2) {
                break;
            } else {
                int numb = binarySearch(bookPrices, aux2, numBooks);
                if (numb != -1) {
                    if ((aux2 - aux1) < minDiff) {
                        book1 =  aux1;
                        book2 = aux2;
                        minDiff = aux2 - aux1;
                    }
                }
            }
        }
        cout << "Peter should buy books whose prices are " << book1 << " and " << book2 << ".\n\n";
    }
    return 0;
}