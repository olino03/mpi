#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>
#include <chrono>

using namespace std;

void generare()
{
    srand(time(0));
    ofstream fout;
    fout.open("10.out");
    fout << "10" << '\n';
    for(int i = 0; i < 10; i++)
    {
        fout << rand() << ' ';
    }
    fout.close();
    fout.open("100.out");
    fout << "100" << '\n';
    for(int i = 0; i < 100; i++)
    {
        fout << rand() << ' ';
    }
    fout.close();
    fout.open("1000.out");
    fout << "1000" << '\n';
    for(int i = 0; i < 1000; i++)
    {
        fout << rand() << ' ';
    }
    fout.close();
    fout.open("10000.out");
    fout << "10000" << '\n';
    for(int i = 0; i < 10000; i++)
    {
        fout << rand() << ' ';
    }
    fout.close();
    fout.open("100000.out");
    fout << "100000" << '\n';
    for(int i = 0; i < 100000; i++)
    {
        fout << rand() << ' ';
    }
    fout.close();
    fout.open("1000000.out");
    fout << "1000000" << '\n';
    for(int i = 0; i < 1000000; i++)
    {
        fout << rand() << ' ';
    }
    fout.close();
    fout.open("10000000.out");
    fout << "10000000" << '\n';
    for(int i = 0; i < 1000000; i++)
    {
        fout << rand() << ' ';
    }
    fout.close();
}

void bubble_sort(int arr[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0 ; j < size - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void selection_sort(int arr[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        int index = i;
        for(int j = i + 1; j < size; j++)
        {
            if(arr[index] > arr[j])
            {
                index = j;
            }
        }
        swap(arr[i], arr[index]);
    }
}

void insertion_sort(int arr[], int size)
{
    for(int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) 
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quick_sort(int arr[], int low, int high)
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void merge(int array[], int const left, int const mid,
           int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
  
    auto *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];
  
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;    
    int indexOfMergedArray = left;
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void merge_sort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;
  
    auto mid = begin + (end - begin) / 2;
    merge_sort(array, begin, mid);
    merge_sort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void count_sort(int arr[], int size)
{
    int *output = new int[size];
    int count[100000], i;
    memset(count, 0, sizeof(count));
    for (i = 0; arr[i]; ++i)
        ++count[arr[i]];
     for (i = 1; i <=100000; ++i)
        count[i] += count[i - 1];
    for (i = 0; arr[i]; ++i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }
    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
    delete[] output;
}

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int *output = new int[n + 1];
    int i, count[10] = { 0 };
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
    delete[] output;
}

void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
 

void shell_sort(int arr[], int n)
{
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

int lista[10000000];
int marime;

int main()
{
    
    auto begin = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < 100; i++)
    {
        ifstream fin("100.out");
        fin >> marime;
        for(int j = 0; j < marime; j++)
        {
            fin >> lista[j];
        }
        merge_sort(lista, marime);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cout << elapsed.count() << '\n';
    return 0;
}