//
#include <iostream>  
using namespace std;
  
int binarySearch(int a[], int x, int n) 
{  
    int left = 0;  
    int right = n - 1;  
      
    while (left <= right) 
	{  
        int middle = (left + right) / 2;  
        if (x == a[middle]) return middle;  
        if (x > a[middle]) left = middle + 1;  
        else right = middle - 1;  
    }  
    return -1;  
}  
  
int main() 
{  
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};  
    int x = 7;  
    int n = 10;  
    cout << binarySearch(a, x, n) <<endl;  
    return 0;  
}
