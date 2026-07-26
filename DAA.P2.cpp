#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Linear Search Function
int linearSearch(vector<int> arr, int key) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Binary Search Function
int binarySearch(vector<int> arr, int key) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n, key;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    // Linear Search
    auto start = high_resolution_clock::now();
    int index = linearSearch(arr, key);
    auto stop = high_resolution_clock::now();

    cout << "\nLinear Search:\n";
    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found.\n";

    cout << "Time: "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds\n";

    // Sort array for Binary Search
    sort(arr.begin(), arr.end());

    start = high_resolution_clock::now();
    index = binarySearch(arr, key);
    stop = high_resolution_clock::now();

    cout << "\nSorted Array: ";
    for (int x : arr)
        cout << x << " ";

    cout << "\n\nBinary Search:\n";
    if (index != -1)
        cout << "Element found at index " << index << " (in sorted array)\n";
    else
        cout << "Element not found.\n";

    cout << "Time: "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds\n";

    return 0;
}