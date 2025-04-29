#include <stdio.h>

/**
 * @brief Mengurutkan array dalam urutan menaik.
 */
void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/**
 * @brief Menemukan indeks pertama elemen target dalam array.
 */
int find(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Menghitung rata-rata elemen dalam array.
 */
double calculateAverage(int arr[], int n) {
    int jml = 0;
    for (int i = 0; i < n; i++) {
        jml += arr[i];
    }
    return (double) jml / n;
}

/**
 * @brief Menemukan median dari elemen dalam array.
 */
int findMedian(int arr[], int n) {
    sort(arr, n);
    return (n % 2 == 0) ? (arr[n / 2 - 1] + arr[n / 2]) / 2 : arr[n / 2];
}

/**
 * @brief Menemukan modus dari elemen dalam array.
 */
int findMode(int arr[], int n) {
    int maxCount = 0, mode = arr[0], freq[n];

    for (int i = 0; i < n; i++) {
        freq[i] = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == arr[i]) {
                freq[i]++;
            }
        }

        if (freq[i] > maxCount) {
            maxCount = freq[i];
            mode = arr[i];
        }
    }

    int isSame = 1;
    for (int i = 1; i < n; i++) {
        if (freq[i] != freq[0]) {
            isSame = 0;
            break;
        }
    }
    return (isSame ? arr[0] : mode);
}

/**
 * @brief Membalikkan elemen dalam array.
 */
void reverseArray(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}

int findMin(int arr[], int n){
    int min=arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i]<min){
            min=arr[i];
        }
    }
    return min;
};

int findMax(int arr[], int n){
    int max=arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i]>max){
            max=arr[i];
        }
    }
    return max;
};