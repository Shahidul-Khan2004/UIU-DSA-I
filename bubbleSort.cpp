#include <iostream>

void bubbleSort(int arr[], int n);

int main()
{
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                const int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}