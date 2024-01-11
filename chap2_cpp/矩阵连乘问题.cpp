//
#include <iostream>
using namespace std;

#define N 7  

void matrixChain(int *p, int n, int m[][N], int s[][N]) 
{
    for (int i = 1; i <= n; i++) 
	{     
        m[i][i] = 0;
    }
    for (int r = 2; r <= n; r++) 
	{   
        for (int i = 1; i <= n - r + 1; i++) 
		{   
            int j = i + (r - 1);  
            m[i][j] = m[i][i] + m[i + 1][j] + p[i - 1] * p[i] * p[j];   
            s[i][j] = i;
            for (int k = i + 1; k < j; k++) 
			{  
                int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (t < m[i][j]) 
				{
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
}

void traceback(int i, int j, int s[][N]) 
{
    if (i == j) 
	{       // 回归条件
        cout << "A" << i;
    } 
	else
	{       // 按照最佳断点一分为二，接着继续递归
        cout << "(";
        traceback(i, s[i][j], s);
        traceback(s[i][j] + 1, j, s);
        cout << ")";
    }
}

int main() 
{
    int p[N] = {30, 35, 15, 5, 10, 20, 25};
    int m[N][N], s[N][N];

    matrixChain(p, N - 1, m, s);  // N-1因为只有六个矩阵
    traceback(1, 6, s);
    return 0;
}
