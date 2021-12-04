// doitjustdoit	- 1112KB, 16ms
#include <stdio.h>

int check(int x)
{
	if(x<1000)
	{
		return x == 666;
	}
	else
	{
		if (x%1000 == 666)
			return 1;
		else
			return check(x/10);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	
	for(int i=666;;i++)
	{
		if(check(i) == 1)
		{
			--n;
		}
		
		if(n == 0)
		{
			printf("%d\n", i);
			return 0;
		}
	}
}