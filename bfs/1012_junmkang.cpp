#include <iostream>
#include <queue>
​
using namespace std;
​
int m, n;
int map[51][51];
​
void chk_count(int i, int j)
{
	int nx[4] = {1, 0, -1, 0};
	int ny[4] = {0, 1, 0, -1};
	
	queue<pair<int, int>> q;
	q.push({i, j});
	map[i][j] = 0;
	while(!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		
		for(int k = 0; k < 4; k++)
		{
			int y = temp.first + nx[k];
			int x = temp.second + ny[k];
			if (x < 0 || x >= m || y < 0 || y >= n) continue;
			if (map[y][x] != 1) continue;
			map[y][x] = 0;
			q.push({y, x});
		}
	}
}
​
void cin_map(int m, int n, int k)
{
	int x, y, count;
	map[51][51] = {0,};
	
	for(int i = 0; i < k; i++)
	{
		cin >> x >> y;
		map[y][x] = 1;
	}
	
	count = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if (map[i][j] == 1)
			{
				chk_count(i, j);
				count++;
			}
		}
	}
	cout << count << "\n";
}
​
int main(void)
{
	int t, k;
	
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> m >> n >> k;
		cin_map(m, n, k);
	}
	
	return (0);
