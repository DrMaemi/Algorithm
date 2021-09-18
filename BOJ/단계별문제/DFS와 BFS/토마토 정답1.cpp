#include<iostream>
#include<deque>
#include <cstdio>

using namespace std;

int M, N;
int** myMap;
deque<pair<int, int>> tomatoDeq;

char b[1000][1000];
char buf[1 << 16];
int idx, nidx;
char read()
{
	if (idx == nidx) {
		nidx = fread(buf, 1, 1 << 16, stdin);
		idx = 0;
	}
	return buf[idx++];
}
inline int readInt()
{
	int sum = 0;
	int flg = 0;
	char now = read();

	while (now == ' ' || now == '\n') now = read();
	if (now == '-') flg = 1, now = read();
	while (now >= '0' && now <= '9') {
		sum = sum * 10 + now - 48;
		now = read();
	}

	return flg ? -sum : sum;
}

bool myFunc(int x, int y)
{
	bool change = false;
	if (x + 1 < M)
	{
		if (myMap[y][x + 1] == 0)
		{
			tomatoDeq.push_back(make_pair(y,x+1));
			myMap[y][x + 1] = 1;

			change = true;
		}
	}
	if (x - 1 >= 0)
	{	
		if (myMap[y][x -1] == 0)
		{
			tomatoDeq.push_back(make_pair(y,x - 1));
			myMap[y][x - 1] = 1;
			change = true;
		}
	}
	if (y + 1 < N)
	{
		if (myMap[y+1][x] == 0)
		{
			tomatoDeq.push_back(make_pair(y+1,x));
			myMap[y+1][x] = 1;
			change = true;
		}
	}
	if (y - 1 >= 0)
	{
		if (myMap[y-1][x] == 0)
		{
			tomatoDeq.push_back({ y - 1,x });
			myMap[y-1][x] = 1;
			change = true;
		}
	}

	return  change;
}

int main()
{
	int tomatoNum = 0;
	M = readInt();
	N = readInt();
	
	myMap = new int*[N];
	for (int i = 0; i < N; i++)
	{
		myMap[i] = new int[M];
		for (int j = 0; j < M; j++)
		{
			myMap[i][j] = readInt();
			if (myMap[i][j] != -1)
			{
				tomatoNum++;
			}
			if (myMap[i][j] == 1)
			{
				tomatoDeq.push_back(make_pair(i, j));
			}
		}
	}
	int count = 0;
	bool change = false;
	int temp = 0;
	int oneTomatoNum = 0;
	if (tomatoNum == tomatoDeq.size())
	{
		cout << count;
		return 0;
	}

	while (true)
	{
		change = false;
		temp = tomatoDeq.size();
		oneTomatoNum += temp;
		for (int i = 0; i <  temp; i++)
		{
			auto pos = tomatoDeq.front();
			tomatoDeq.pop_front();
			if (true == myFunc(pos.second, pos.first)) change = true;
		}
		if (change == false) break;

		count++;
	}
	if (oneTomatoNum != tomatoNum)
	{
		cout << -1;
		return 0;
	}

	cout << count;
	return 0;
}