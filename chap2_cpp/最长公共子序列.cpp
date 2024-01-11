#include<iostream> 
#include <string>
#include <algorithm>
using namespace std;

string s1, s2;
// �����ά�������ڸ�����¼
int record[1000][1000];

//��ӡ������Ӵ��Ӵ�
void PrintLCS(int m, int n)
{
    if(n == 0 || m == 0)
	{
        return;
    }
    if(record[n][m] == 1)
	{
        PrintLCS(m-1, n-1);
        cout << s1[m-1];
    }
	else if(record[n][m] == 2)
	{
        PrintLCS(m-1, n);
    }
	else
	{
        PrintLCS(m, n-1);
    }
}

int main() {
	cout<<"������A����"<<endl; 
    cin >> s1;
    cout<<"������B����"<<endl; 
    cin >> s2;
   
    int m = s1.size();
    int n = s2.size();
    
    int dp[n+1][m+1];

    for(int i = 0; i < n+1; i++){dp[i][0] = 0;}
    for(int i = 0; i < m+1; i++){dp[0][i] = 0;}

    for(int i = 1; i < n+1; i++)
	{
        for(int j = 1; j < m+1; j++)
		{
            if(s1[j-1] == s2[i-1])
			{
                dp[i][j] = dp[i-1][j-1] + 1;
                // ��dp[i][j]��ֵ��Դ��dp[i-1][j-1]+1�����ͬλ�õ�record���鸳ֵΪ1
                record[i][j] = 1;
            }else if(dp[i][j-1] > dp[i-1][j])
			{
                dp[i][j] = dp[i][j-1];
                //����Դ��dp[i][j-1]�����ͬλ�õ�record���鸳ֵΪ2
                record[i][j] = 2;
            }else
			{
                dp[i][j] = dp[i-1][j];
                //����Դ��dp[i-1][j]�����ͬλ�õ�record���鸳ֵΪ3
                record[i][j] = 3;
            }
        }
    }
    PrintLCS(m, n);

    return 0;
}
