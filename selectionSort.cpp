#include <iostream>

void selectionSort(int arr[], int n);

int main()
{
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    selectionSort(arr, n);
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = arr[i];
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                minIndex = j;
            }
        }
        const int temp = arr[i];
        arr[i] = min;
        arr[minIndex] = temp;
    }
}