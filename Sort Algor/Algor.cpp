#include <iostream>
using namespace std;

class simpAlgor {
    public:
        // int n = sizeof(arr)/sizeof(arr[0]);
        // Worst case when reverse sorted, best case when already sorted
        void bubbleSort(int arr[], int n) {
            int i, j;
            for (i = 0; i < n - 1; i++)
                // Last i elements are already
                // in place
                for (j = 0; j < n - i - 1; j++)
                    if (arr[j] > arr[j + 1])
                        swap(arr[j], arr[j + 1]);
        }

        void optbubbleSort(int arr[], int n) {
            int i, j;
            bool swapped;
            for (i = 0; i < n - 1; i++) {
                swapped = false;
                for (j = 0; j < n - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        swap(arr[j], arr[j + 1]);
                        swapped = true;
                    }
                }
                // IF no two elements were swapped
                // by inner loop, then break
                if (swapped == false)
                    break;
            }
        }

        //no best or worst case
        void selectionSort(int arr[], int n) {
            int i, j, min_idx;
            // One by one move boundary of
            // unsorted subarray
            for (i = 0; i < n - 1; i++) {
                // Find the minimum element in
                // unsorted array
                min_idx = i;
                for (j = i + 1; j < n; j++)
                    if (arr[j] < arr[min_idx])
                        min_idx = j;
                // Swap the found minimum element
                // with the first element
                if (min_idx != i)
                    swap(arr[min_idx], arr[i]);
            }
        }

        void insertionSort(int arr[], int n) {
            int i, key, j;
            for (i = 1; i < n; i++) {
                key = arr[i];
                j = i - 1;
                // Move elements of arr[0..i-1],that are greater than key,
                // to one position ahead of their current position
                while (j >= 0 && arr[j] > key) {
                    arr[j + 1] = arr[j];
                    j = j - 1;
                }
                arr[j + 1] = key;
            }
        }

        void merge(int array[], int const left, int const mid, int const right) {
            auto const subArrayOne = mid - left + 1;
            auto const subArrayTwo = right - mid;
            // Create temp arrays
            auto* leftArray = new int[subArrayOne],
                * rightArray = new int[subArrayTwo];
            // Copy data to temp arrays leftArray[] and rightArray[]
            for (auto i = 0; i < subArrayOne; i++)
                leftArray[i] = array[left + i];
            for (auto j = 0; j < subArrayTwo; j++)
                rightArray[j] = array[mid + 1 + j];
            auto indexOfSubArrayOne = 0, // Initial index of first sub-array
                indexOfSubArrayTwo = 0; // Initial index of second sub-array
            int indexOfMergedArray = left; // Initial index of merged array
            // Merge the temp arrays back into array[left..right]
            while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
                if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
                    array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                    indexOfSubArrayOne++;
                }
                else {
                    array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                    indexOfSubArrayTwo++;
                }
                indexOfMergedArray++;
            }
            // Copy the remaining elements of left[], if there are any
            while (indexOfSubArrayOne < subArrayOne) {
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
                indexOfMergedArray++;
            }
            // Copy the remaining elements of right[], if there are any
            while (indexOfSubArrayTwo < subArrayTwo) {
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
                indexOfMergedArray++;
            }
            delete[] leftArray;
            delete[] rightArray;
        }
        void mergeSort(int array[], int const begin, int const end) {
            if (begin >= end)
                return; // Returns recursively
            auto mid = begin + (end - begin) / 2;
            mergeSort(array, begin, mid);
            mergeSort(array, mid + 1, end);
            merge(array, begin, mid, end);
        }

        // This function takes last element as pivot, places the pivot element at its correct position in sorted
        //array, and places all sm8=aller (smaller than pivot) to left of pivot and all greater elements to right of pivot
        int partition(int arr[], int low, int high)
        {
            int pivot = arr[high]; // pivot
            int i = (low - 1); // Index of smaller element and indicatesthe right position of pivot found so far
            for (int j = low; j <= high - 1; j++) {
                // If current element is smaller than the pivot
                if (arr[j] < pivot) {
                    i++; // increment index of smaller element
                    swap(arr[i], arr[j]);
                }
            }
            swap(arr[i + 1], arr[high]);
            return (i + 1);
        }
        void quickSort(int arr[], int low, int high) {
            if (low < high) {
                /* pi is partitioning index, arr[p] is now at right place */
                int pi = partition(arr, low, high);
                ;// Separately sort elements before partition and after partition
                quickSort(arr, low, pi - 1);
                quickSort(arr, pi + 1, high);
            }
        }

        int getMax(int arr[], int n) {
            int mx = arr[0];
            for (int i = 1; i < n; i++)
                if (arr[i] > mx)
                    mx = arr[i];
            return mx;
        }
        void countSort(int array[], int size) {
            // The size of count must be at least the (max+1) but we cannot assign declare it as int count(max+1) in C++ as
            // it does not support dynamic memory allocation. So, its size is provided statically.
            int output[40000]; int count[40000];
            // Find the largest element of the array
            int max = getMax(array, size);
            // Initialize count array with all zeros.
            for (int i = 0; i <= max; ++i)
                count[i] = 0;
            // Store the count of each element
            for (int i = 0; i < size; i++)
                count[array[i]]++;
            // Store the cummulative count of each array
            for (int i = 1; i <= max; i++)
                count[i] += count[i - 1];
            // Find the index of each element of the original array in count array, and
            // place the elements in output array
            for (int i = size - 1; i >= 0; i--) {
                output[count[array[i]] - 1] = array[i];
                count[array[i]]--;
            }
            // Copy the sorted elements into original array
            for (int i = 0; i < size; i++)
                array[i] = output[i];
        }

        // A function to do counting sort of arr[] according to the digit represented by exp. Specific for Radix Sort
        void countSort(int arr[], int n, int exp) {
            int* output = new int[n]; // output array
            int i, count[10] = { 0 };
            // Store count of occurrences in count[]
            for (i = 0; i < n; i++)
                count[(arr[i] / exp) % 10]++;
            // Change count[i] so that count[i] now contains actual position of this digit in output[]
            for (i = 1; i < 10; i++)
                count[i] += count[i - 1];
            // Build the output array
            for (i = n - 1; i >= 0; i--) {
                output[count[(arr[i] / exp) % 10] - 1] = arr[i];
                count[(arr[i] / exp) % 10]--;
            }
            // Copy the output array to arr[], so that arr[] now contains sorted numbers according to current digit
            for (i = 0; i < n; i++)
                arr[i] = output[i];
        }
        void radixsort(int arr[], int n) {
            // Find the maximum number to know number of digits
            int m = getMax(arr, n);
            // Do counting sort for every digit. Note that instead of passing digit number, exp is passed.
            // exp is 10^i where i is current digit number
            for (int exp = 1; m / exp > 0; exp *= 10)
                countSort(arr, n, exp);
        }

        // For measuring computational time
        static double get_cpu_time() {
            FILETIME a, b, c, d;
            if (GetProcessTimes(GetCurrentProcess(), &a, &b, &c, &d) != 0) {
                //  Returns total user time.
                //  Can be tweaked to include kernel times as well.
                return
                    (double)(d.dwLowDateTime |
                        ((unsigned long long)d.dwHighDateTime << 32)) * 0.0000001;
            }
            else {
                //  Handle error
                return 0;
            }
        }
};

class iterAlgor {
public:
    // int n = sizeof(arr)/sizeof(arr[0]);
    // Worst case when reverse sorted, best case when already sorted
    int* bubbleSort(int arr[], int n) {
        int i, j;
        int* data = new int[2];
        data[0] = 0; data[1] = 0;
        for (i = 0; i < n - 1; i++)
            // Last i elements are already in place
            for (j = 0; j < n - i - 1; j++) {
                data[0]++;
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    data[1]++;
                }
            }
        return data;
    }

    int* optbubbleSort(int arr[], int n) {
        int i, j;
        int* data = new int[2];
        data[0] = 0; data[1] = 0;
        bool swapped;
        for (i = 0; i < n - 1; i++) {
            swapped = false;
            for (j = 0; j < n - i - 1; j++) {
                data[0]++;
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    data[1]++;
                    swapped = true;
                }
            }
            // IF no two elements were swapped
            // by inner loop, then break
            if (swapped == false)
                break;
        }
        return data;
    }

    //no best or worst case
    int* selectionSort(int arr[], int n) {
        int i, j, min_idx;
        int* data = new int[2];
        data[0] = 0; data[1] = 0;
        // One by one move boundary of unsorted subarray
        for (i = 0; i < n - 1; i++) {
            // Find the minimum element in unsorted array
            min_idx = i;
            for (j = i + 1; j < n; j++) {
                data[0]++;
                if (arr[j] < arr[min_idx])
                    min_idx = j;
            }
            // Swap the found minimum element with the first element
            if (min_idx != i) {
                swap(arr[min_idx], arr[i]);
                data[1]++;
            }
        }
        return data;
    }

    int* insertionSort(int arr[], int n) {
        int i, key, j;
        int* data = new int[2];
        data[0] = 0; data[1] = 0;
        for (i = 1; i < n; i++) {
            key = arr[i];
            j = i - 1;
            data[0] ++ ;
            // Move elements of arr[0..i-1],that are greater than key,
            // to one position ahead of their current position
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
                data[1]++;
                //printArray(arr, 6);
            }
            arr[j + 1] = key;
        }
        return data;
    }

    int* merge(int array[], int const left, int const mid, int const right) {
        int* data = new int[2];
        data[0] = 0; data[1] = 0;
        auto const subArrayOne = mid - left + 1;
        auto const subArrayTwo = right - mid;
        // Create temp arrays
        auto* leftArray = new int[subArrayOne],
            * rightArray = new int[subArrayTwo];
        // Copy data to temp arrays leftArray[] and rightArray[]
        for (auto i = 0; i < subArrayOne; i++) {
            leftArray[i] = array[left + i]; data[0]++;
        }
        for (auto j = 0; j < subArrayTwo; j++){
            rightArray[j] = array[mid + 1 + j]; data[0]++;
        }
        auto indexOfSubArrayOne = 0, // Initial index of first sub-array
            indexOfSubArrayTwo = 0; // Initial index of second sub-array
        int indexOfMergedArray = left; // Initial index of merged array
        // Merge the temp arrays back into array[left..right]
        while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
            if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else {
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
                data[1]++;
            }
            indexOfMergedArray++; data[0]++;
        }
        // Copy the remaining elements of left[], if there are any
        while (indexOfSubArrayOne < subArrayOne) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            indexOfMergedArray++;
            data[0]++;
        }
        // Copy the remaining elements of right[], if there are any
        while (indexOfSubArrayTwo < subArrayTwo) {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            indexOfMergedArray++;
            data[0];
        }
        delete[] leftArray;
        delete[] rightArray;
        return data;
    }
    int* mergeSort(int array[], int const begin, int const end) {
        int* data = new int[2]; int* edit = new int[2];
        data[0] = 0; data[1] = 0;
        if (begin >= end)
            return data; // Returns recursively
        auto mid = begin + (end - begin) / 2;
        edit = mergeSort(array, begin, mid);
        data[0] += edit[0]; data[1] += edit[1];
        edit = mergeSort(array, mid + 1, end);
        data[0] += edit[0]; data[1] += edit[1];
        edit = merge(array, begin, mid, end);
        data[0] += edit[0]; data[1] += edit[1];
        return data;
    }

    //This function takes last element as pivot, places the pivot element at its correct position in sorted
    //array, and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot
    int* partition(int arr[], int low, int high){
        int* data = new int[3]; data[0] = 0; data[1] = 0;
        bool flag = false;
        int pivot = arr[high]; // pivot
        int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
        for (int j = low; j <= high - 1; j++) {
            data[0]++;
            // If current element is smaller than the pivot
            if (arr[j] < pivot) {
                i++; // increment index of smaller element
                swap(arr[i], arr[j]);
                data[1]++; flag = true;
            }
        }
        swap(arr[i + 1], arr[high]);
        if (flag)
            data[1]++;
        flag = false;
        data[2] = (i + 1);
        return data;
    }
    int* quickSort(int arr[], int low, int high) {
        int* data = new int[2], * edit = new int[2], * hmm = new int[3];
        data[0] = 0; data[1] = 0;
        if (low < high) {
            /* pi is partitioning index, arr[p] is now at right place */
            hmm = partition(arr, low, high);
            int pi = hmm[2]; data[0] += hmm[0]; data[1] += hmm[1];
            // Separately sort elements before partition and after partition
            edit = quickSort(arr, low, pi - 1);
            data[0] += edit[0]; data[1] += edit[1];
            edit = quickSort(arr, pi + 1, high);
            data[0] += edit[0]; data[1] += edit[1];
        }
        return data;
    }

    int getMax(int arr[], int n) {
        int mx = arr[0];
        for (int i = 1; i < n; i++)
            if (arr[i] > mx)
                mx = arr[i];
        return mx;
    }
    int* countSort(int array[], int size) {
        // The size of count must be at least the (max+1) but we cannot assign declare it as int count(max+1) in C++ as
        // it does not support dynamic memory allocation. So, its size is provided statically.
        // Find the largest element of the array
        int max = getMax(array, size);
        int output[40000], count[40000], * data = new int[2];
        data[0] = size; data[1] = 0;
        // Initialize count array with all zeros.
        for (int i = 0; i <= max; ++i) {
            count[i] = 0; data[0]++;
        }
        // Store the count of each element
        for (int i = 0; i < size; i++) {
            count[array[i]]++; data[0]++;
        }
        // Store the cummulative count of each array
        for (int i = 1; i <= max; i++) {
            count[i] += count[i - 1]; data[0]++;
        }
        // Find the index of each element of the original array in count array, and place the elements in output array
        for (int i = size - 1; i >= 0; i--) {
            output[count[array[i]] - 1] = array[i];
            count[array[i]]--; data[0]++;
        }
        // Copy the sorted elements into original array
        for (int i = 0; i < size; i++) {
            array[i] = output[i]; data[0]++; data[1]++;
        }
        return data;
    }

    // A function to do counting sort of arr[] according to the digit represented by exp. Specific for Radix Sort
    int* countSort(int arr[], int n, int exp) {
        int* output = new int[n], * data = new int[2];// output array
        int i, count[10] = { 0 }; data[0] = 0; data[1] = 0;
        // Store count of occurrences in count[]
        for (i = 0; i < n; i++) {
            count[(arr[i] / exp) % 10]++; data[0]++;
        }
        // Change count[i] so that count[i] now contains actual position of this digit in output[]
        for (i = 1; i < 10; i++) {
            count[i] += count[i - 1]; data[0]++;
        }
        // Build the output array
        for (i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--; data[0]++;
        }
        // Copy the output array to arr[], so that arr[] now contains sorted numbers according to current digit
        for (i = 0; i < n; i++) {
            arr[i] = output[i]; data[0]++; data[1]++;
        }
        return data;
    }
    int* radixsort(int arr[], int n) {
        int* data = new int[2], *edit = new int[2];
        data[0] = 0; data[1] = 0;
        // Find the maximum number to know number of digits
        int m = getMax(arr, n); data[0] = n;
        // Do counting sort for every digit. Note that instead of passing digit number, exp is passed.
        // exp is 10^i where i is current digit number
        for (int exp = 1; m / exp > 0; exp *= 10) {
            edit = countSort(arr, n, exp); data[0]++;
            data[0] += edit[0]; data[1] += edit[1];
        }
        return data;
    }
};