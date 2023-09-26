#include "Compulsory 2.h"
#include <cstdlib>
#include <ctime>
#include <chrono>


int main() {

    const int n = 10000;

    std::vector<int> randomQuick(n);
    std::vector<int> randomMerge(n);
    std::vector<int> randomCount(n);
     

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    std::srand(std::time(nullptr));
       
    for (int i = 0; i < n; i++) {
        randomQuick[i] = randomMerge[i] = randomCount[i] = std::rand() % 1000;
    }
  

        // quick sort
        std::cout << "Quick Original array: ";
        for (int i = 0; i < n; i++) {
            std::cout << randomQuick[i] << " ";
        }
        std::cout << std::endl;

        auto startTimeQuick = std::chrono::high_resolution_clock::now();

        quickSort(randomQuick, 0, n - 1); 

        auto endTimeQuick = std::chrono::high_resolution_clock::now();

        std::cout << "Sorted array: ";
        for (int i = 0; i < n; i++) {
            std::cout << randomQuick[i] << " ";
        }
        std::cout << std::endl;
        // Merge sort
        std::cout << "Merge Original array: ";
        for (int num : randomMerge) {
            std::cout << num << " ";
        }

        auto startTimeMerge = std::chrono::high_resolution_clock::now();

        mergeSort(randomMerge, 0, n - 1);

        auto endTimeMerge = std::chrono::high_resolution_clock::now();

        std::cout << "\nSorted array: ";
        for (int num : randomMerge) {
            std::cout << num << " ";
        }

        //Counting sort
        std::cout << "\n Counting Original array: ";
        for (int num : randomCount) {
            std::cout << num << " ";
        }

        auto startTimeCounting = std::chrono::high_resolution_clock::now();

        countingSort(randomCount);

        auto endTimeCounting = std::chrono::high_resolution_clock::now();

        std::cout << "\nSorted array: ";
        for (int num : randomCount) {
            std::cout << num << " ";
        }

        auto durationQuickSort = std::chrono::duration_cast<std::chrono::milliseconds>(endTimeQuick - startTimeQuick);
        std::cout << "\n Quick sort " << durationQuickSort.count() << " milsec" << std::endl;

        auto durationMergeSort = std::chrono::duration_cast<std::chrono::milliseconds>(endTimeMerge - startTimeMerge);
        std::cout << " Merge sort " << durationMergeSort.count() << " milsec" << std::endl;

        auto durationCountingSort = std::chrono::duration_cast<std::chrono::milliseconds>(endTimeCounting - startTimeCounting);
        std::cout << " Count sort " << durationCountingSort.count() << " milsec" << std::endl;

        return 0;
}

int partition(std::vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void merge(std::vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[middle + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

void countingSort(std::vector<int>& arr) {
    if (arr.empty()) {
        return; 
    }

    int max_val = arr[0];
    int min_val = arr[0];
    for (int num : arr) {
        if (num > max_val) {
            max_val = num;
        }
        if (num < min_val) {
            min_val = num;
        }
    }

    int range = max_val - min_val + 1;

    std::vector<int> count(range, 0);

    for (int num : arr) {
        count[num - min_val]++;
    }

    int i = 0; 
    int j = 0; 

    while (i < arr.size()) {
        while (count[j] == 0) {
            j++;
        }

        arr[i] = j + min_val;
        count[j]--;
        i++;
    }
}