#include<vector>   
#include<iostream> 
using namespace std; 
   
vector<vector<string> > result; // 每个元素是一个字符串向量，表示棋盘上的一行  
int m = 0; // m 记录找到的解的数  
   
// isValid 函数用于检查在给定的位置 (row, col) 是否可以放置皇后
bool isValid(int row, int col, vector<string>& chessboard, int n) 
{  
    // 检查列上是否有皇后  
    for (int i = 0; i < row; i++) 
	{  
        if (chessboard[i][col] == 'Q') 
		{  
            return false;  
        }  
    }  
    // 检查左上方是否有皇后  
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) 
	{  
        if (chessboard[i][j] == 'Q') 
		{  
            return false;  
        }  
    }  
    // 检查右上方是否有皇后  
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) 
	{  
        if (chessboard[i][j] == 'Q') 
		{  
            return false;  
        }  
    }  
    return true; // 如果以上检查都通过，那么证明有效的  
}  
   
// backtracking 函数是一个递归函数，用于在棋盘上放置皇后并寻找所有可能的解决方案  
void backtracking(int n, int row, vector<string>& chessboard) 
{  
    if (n == row) 
	{ // 如果已经放置了 n 个皇后，找到了一个解，将其保存到 result 中  
        m++;  
        result.push_back(chessboard);  
        return;  
    }  
    for (int col = 0; col < n; col++) 
	{ // 对每一列尝试放置皇后  
        if (isValid(row, col, chessboard, n)) 
		{ // 如果这个位置有效  
            chessboard[row][col] = 'Q'; // 在这个位置放置皇后  
            backtracking(n, row + 1, chessboard); // 对下一行进行递归搜索  
            chessboard[row][col] = '.'; // 回溯，将皇后移回原来的位置，以便尝试其他位置  
        }  
    }  
}  
   
// solveNQueens 初始化棋盘，开始递归搜索 
void solveNQueens(int n) 
{  
    result.clear(); // 清空 result 
    vector<string> chessboard(n, string(n, '.')); // 初始化棋盘，所有位置都是空的（'.' 表示空）  
    backtracking(n, 0, chessboard); // 从第一行开始搜索，调用 backtracking 函数开始递归搜索过程  
    // 打印所有找到的解  
    for (int i = 0; i < m; i++) 
	{  
        cout << "-------------" << endl;  
        cout << "第" << i + 1 << "种情况：" << endl; // 打印当前解的序号  
        for (int j = 0; j < n; j++) 
		{   
            cout << result[i][j] << endl; // 如果当前位置有皇后，打印 'Q'，否则打印 '.'  
        }  
        cout << "-------------" << endl; 
    }  
}  
   
// 主函数 
int main() 
{  
    int n;  
    cout << "请输入皇后的个数：";  
    cin >> n;  
    solveNQueens(n);
    return 0; 
}
