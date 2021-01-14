#include <iostream>
#include <queue>

using namespace std;

int map[501][501];
int chk[501][501];

int main(void)
{
	int n, m, count, max;
	int x[4] = {0, 1, 0, -1};
	int y[4] = {1, 0, -1, 0};
	
	max = -1;
	queue<pair<int, int>> q;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			cin >> map[i][j];
	}
	
	count = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if (map[i][j] == 1 && chk[i][j] == 0)
			{

				count++;
				q.push({i, j});
				chk[i][j] = 1;
				int num = 0;
				while(!q.empty())
				{
					pair<int, int> temp = q.front();
					q.pop();
					for(int k = 0; k < 4; k++)
					{
						int tmpx = temp.first + x[k];
						int tmpy = temp.second + y[k];
						if (tmpx < 0 || tmpx >= n || tmpy < 0 || tmpy >= m) continue;
						if (chk[tmpx][tmpy] || map[tmpx][tmpy] != 1) continue;
						chk[tmpx][tmpy] = 1;
						
						q.push({tmpx, tmpy});
					}
					num++;
				}
				if (max < num)
					max = num;
			}
		}
	}
	cout << count << "\n" << max;
		
	return (0);
}
