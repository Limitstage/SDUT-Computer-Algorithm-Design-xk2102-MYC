#include<vector>   
#include<iostream> 
using namespace std; 
   
vector<vector<string> > result; // ÿ��Ԫ����һ���ַ�����������ʾ�����ϵ�һ��  
int m = 0; // m ��¼�ҵ��Ľ����  
   
// isValid �������ڼ���ڸ�����λ�� (row, col) �Ƿ���Է��ûʺ�
bool isValid(int row, int col, vector<string>& chessboard, int n) 
{  
    // ��������Ƿ��лʺ�  
    for (int i = 0; i < row; i++) 
	{  
        if (chessboard[i][col] == 'Q') 
		{  
            return false;  
        }  
    }  
    // ������Ϸ��Ƿ��лʺ�  
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) 
	{  
        if (chessboard[i][j] == 'Q') 
		{  
            return false;  
        }  
    }  
    // ������Ϸ��Ƿ��лʺ�  
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) 
	{  
        if (chessboard[i][j] == 'Q') 
		{  
            return false;  
        }  
    }  
    return true; // ������ϼ�鶼ͨ������ô֤����Ч��  
}  
   
// backtracking ������һ���ݹ麯���������������Ϸ��ûʺ�Ѱ�����п��ܵĽ������  
void backtracking(int n, int row, vector<string>& chessboard) 
{  
    if (n == row) 
	{ // ����Ѿ������� n ���ʺ��ҵ���һ���⣬���䱣�浽 result ��  
        m++;  
        result.push_back(chessboard);  
        return;  
    }  
    for (int col = 0; col < n; col++) 
	{ // ��ÿһ�г��Է��ûʺ�  
        if (isValid(row, col, chessboard, n)) 
		{ // ������λ����Ч  
            chessboard[row][col] = 'Q'; // �����λ�÷��ûʺ�  
            backtracking(n, row + 1, chessboard); // ����һ�н��еݹ�����  
            chessboard[row][col] = '.'; // ���ݣ����ʺ��ƻ�ԭ����λ�ã��Ա㳢������λ��  
        }  
    }  
}  
   
// solveNQueens ��ʼ�����̣���ʼ�ݹ����� 
void solveNQueens(int n) 
{  
    result.clear(); // ��� result 
    vector<string> chessboard(n, string(n, '.')); // ��ʼ�����̣�����λ�ö��ǿյģ�'.' ��ʾ�գ�  
    backtracking(n, 0, chessboard); // �ӵ�һ�п�ʼ���������� backtracking ������ʼ�ݹ���������  
    // ��ӡ�����ҵ��Ľ�  
    for (int i = 0; i < m; i++) 
	{  
        cout << "-------------" << endl;  
        cout << "��" << i + 1 << "�������" << endl; // ��ӡ��ǰ������  
        for (int j = 0; j < n; j++) 
		{   
            cout << result[i][j] << endl; // �����ǰλ���лʺ󣬴�ӡ 'Q'�������ӡ '.'  
        }  
        cout << "-------------" << endl; 
    }  
}  
   
// ������ 
int main() 
{  
    int n;  
    cout << "������ʺ�ĸ�����";  
    cin >> n;  
    solveNQueens(n);
    return 0; 
}
