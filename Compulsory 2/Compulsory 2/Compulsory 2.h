#pragma once
#include <iostream>
#include <vector>

class Compulsory2 {

};
int partition(std::vector<int>& arr, int low, int high);
void quickSort(std::vector<int>& arr, int low, int high);
void merge(std::vector<int>& arr, int left, int middle, int right);
void mergeSort(std::vector<int>& arr, int left, int right);
void countingSort(std::vector<int>& arr);