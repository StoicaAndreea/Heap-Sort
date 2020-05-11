// HeapSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 

using namespace std;


bool isPrime(int num) {
    bool flag = true;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            flag = false;
            break;
        }
    }
    return flag;
}
// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root 
    int l = 2 * i + 1; // left = 2*i + 1 
    int r = 2 * i + 2; // right = 2*i + 2 

    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root 
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest);
    }
}

// main function to do heap sort 
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap 
    for (int i = n - 1; i > 0; i--)
    {
            // Move current root to end 
            swap(arr[0], arr[i]);

            // call max heapify on the reduced heap 
            heapify(arr, i, 0);
    }
}

void kMinMax(int arr[], int n,int k,int& mins,int& minp,int& maxs,int& maxp) {
    heapSort(arr, n);
    mins = 0;
    minp = 1;
    maxs = 0;
    maxp = 1;
    int i = 0;
    int min = 0;
    int max = 0;
    int nr = k;
    while (i < k) {
        if (isPrime(arr[i]) and isPrime(arr[n - i - 1])) { k++; }
        else {
            if (!isPrime(arr[i]) and isPrime(arr[n - i - 1]) and min<nr) {
                mins += arr[i];
                minp *= arr[i];
                min++;
                k++;
            }
            else {
                if (!isPrime(arr[n - i - 1])and isPrime(arr[i]) and max<nr)
                {
                    maxs += arr[n - i - 1];
                    maxp *= arr[n - i - 1];
                    max++;
                    k++;
                }
                else {
                    if (!isPrime(arr[n - i - 1]) and !isPrime(arr[i])) {
                        if (min < nr) {
                        mins += arr[i];
                        minp *= arr[i];
                        min++;
                        }
                        if (max < nr) {
                            maxs += arr[n - i - 1];
                            maxp *= arr[n - i - 1];
                            max++;
                        }
                         //k++;
                    }
                }
            }

        }
        i++;
    }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver program 
int main()
{
    int mins = 0;
    int minp = 0;
    int maxs = 0;
    int maxp = 0;
    int k = 0;
    int arr[] = { 2, 5, 6, 8, 10, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    kMinMax(arr, n, 2, mins, minp, maxs, maxp);
    cout << "Sorted array is \n";
    printArray(arr, n);
    cout << "min sum: " << mins << endl;
    cout << "max sum: " << maxs<<endl;
    cout << "min prod: " << minp<<endl;
    cout << "max prod: " << maxp<<endl;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
