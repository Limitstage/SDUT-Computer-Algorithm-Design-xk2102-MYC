#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

const int N = (1 << 20) + 10;
int n,m;
int v[N],w[N];
int res = -1;
int s[N]; // s[i]�洢���Ǵӵ�1����Ʒ����i����Ʒ�ļ�ֵ�ܺ� 

struct good{
    int idx,c,r,tv; // idx��ʾѡ���±꣬c��ʾ��ѡ���ĵ�ǰ�ܼ�ֵ��r��ʾ��ǰѡ����ʣ���ܼ�ֵ��tv��ʾ��ѡ���ĵ�ǰ�����
    bool operator > (const good& W) const{
        return W.c + W.r > c + r;
    }
}goods[N];

int bfs(){
    goods[1] = {1,0,0,0};
    priority_queue<good,vector<good>,greater<good>> q;
    q.push(goods[1]);

    while(q.size()){
        auto t = q.top();
//        cout << t.idx << endl;
        q.pop();
        int idx = t.idx << 1;
        goods[idx] = {idx,goods[t.idx].c,s[n] - s[(int)log2(idx)],goods[t.idx].tv};
        goods[idx + 1] = {idx + 1,goods[t.idx].c + w[(int)log2(idx)],s[n] - s[(int)log2(idx)],goods[t.idx].tv + v[(int)log2(idx)]};
        if((int)log2(t.idx) == n) { // �����Ѿ����ӽڵ㣬����´�
            res = max(res,t.c);
            continue;
        }

        if(goods[idx].tv <= m && goods[idx].c + goods[idx].r > res) q.push(goods[idx]); // ���統ǰѡ��������������������������ҵ�ǰ��ֵ+ʣ���ֵ > ��ǰ���Ž⣬��װ�뱳��
        if(goods[idx + 1].tv <= m && goods[idx + 1].c + goods[idx + 1].r > res) q.push(goods[idx + 1]);
    }

    return res;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> v[i] >> w[i],s[i] = s[i - 1] + w[i];
	cout << bfs() << endl;
    return 0;
}

//4 5
//1 2
//2 4
//3 4
//4 5
