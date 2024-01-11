#include <iostream>  
#include <cmath>  
  
using namespace std;  

int SIGN(int A) 
{  
    return (A > 0) ? 1 : -1;  
}

int divideConquer(int X, int Y, int n) {  
    int sign = SIGN(X) * SIGN(Y);  
    int x = abs(X);  
    int y = abs(Y);  
    if (x == 0 || y == 0) 
	{  
        return 0;  
    } 
	else if (n == 1) 
	{  
        return sign * x * y;  
    } 
	else 
	{  
        int A = (int) (x / pow(10, n / 2));  
        int B = x - A * (int) pow(10, n / 2);  
        int C = (int) (y / pow(10, n / 2));  
        int D = y - C * (int) pow(10, n / 2);  
        int AC = divideConquer(A, C, n / 2);  
        int BD = divideConquer(B, D, n / 2);  
        int ABDC = divideConquer((A - B), (D - C), n / 2) + AC + BD;  
        return sign * (AC * (int) pow(10, n) + ABDC * (int) pow(10, n / 2) + BD);  
    }  
}  
  
int main() 
{  
    int x, y, n;  
    cout << "请输入大整数A"<<endl;  
    cin >> x;  
    cout << "请输入大整数B"<<endl;  
    cin >> y;  
    cout << "请输入大整数A,B的位数"<<endl;  
    cin >> n;  
    cout << "A和B的乘积为：" << divideConquer(x, y, n)<<endl;  
    return 0;  
}  
  
