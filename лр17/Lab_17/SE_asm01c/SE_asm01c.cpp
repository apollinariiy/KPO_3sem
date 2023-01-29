#include <iostream>

extern "C"
{
    int __stdcall getMin(int*, int);
    int __stdcall getMax(int*, int);
}

int main()
{
    int arr[10] = { 0, 2, 3, 4, 5, 6, 8, 4, 3, 2 };

    std::cout << "getmax + getmin = " << getMin(arr, 10) + getMax(arr, 10) << std::endl;
}