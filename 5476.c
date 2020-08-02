
int getWinner(int* arr, int arrSize, int k){
    if (arrSize == 0) {
        return -1;
    }
    int max = arr[0];
    int count = 0;
    for (int i = 1; i < arrSize; ++i) {
        if (max < arr[i]) {
            max = arr[i];
            count = 1;
        } else {
            ++count;
        }
        if (count == k) {
            break;
        }
    }
    return max;
}