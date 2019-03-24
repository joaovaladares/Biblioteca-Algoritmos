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