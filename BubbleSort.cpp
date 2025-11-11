#include <iostream>

int main ()
{
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
}