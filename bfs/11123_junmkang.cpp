// 양 한마리... 양 두마리...
#include <iostream>
#include <queue>

using namespace std;

char map[101][101];
char chk[101][101];

int main(void)
{
	int t, h, w;
	
	int nx[4] = {0, 1, 0, -1};
	int ny[4] = {1, 0, -1, 0};
	
	cin >> t;
	for(int nt = 0; nt < t; nt++)
	{
		cin >> h >> w;
		char map[101][101] = {0,};
		char chk[101][101] = {0,};
		for(int i = 0; i < h; i++)
			for(int j = 0; j < w; j++)
				cin >> map[i][j];
		int count = 0;
		for(int i = 0; i < h; i++)
		{
			for(int j = 0; j < w; j++)
			{
				if (map[i][j] == '#' && chk[i][j] == 0)
				{
					count++;
					queue<pair<int, int> > q;
					q.push({i, j});
					chk[i][j] = 1;
					while(!q.empty())
					{
						pair<int, int> temp =  q.front();
						q.pop();
						for(int k = 0; k < 4; k++)
						{
							int x = temp.first + nx[k];
							int y = temp.second + ny[k];
							if (x < 0 || x >= h || y < 0 || y >= w) continue;
							if (chk[x][y] || map[x][y] != '#') continue;
							chk[x][y] = 1;
							q.push({x, y});
						}
					}
				}
			}
		}
		cout << count << "\n";
	}
	
	return (0);
}
