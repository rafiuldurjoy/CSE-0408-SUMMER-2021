#include <bits/stdc++.h>
using namespace std;
int z,l;
int parent[100];
int cost [1000][10000];
int find(int i)
{

	while (parent[i] != i)
        i = parent[i];
    return i;
}


void union1(int i, int j)
{
	int f = find(i);
	int h = find(j);
	parent[f] = h;
}


void BFsMST()
{
	int mincost = 0;
	int edge_count = 0;
	while (edge_count < z - 1)
    {
		int min = INT_MAX, f = -1, h = -1;
		for (int i = 0; i < z; i++) {
			for (int j = 0; j < z; j++)
            {
				if (find(i) != find(j) && cost[i][j] < min)
				{
					min = cost[i][j];
					f = i;
					h = j;
				}
			}
		}

		union1(f,h);
        cout<<"Edge "<<edge_count++<<":("<<f<<" "<<h<<") cost:"<<min<<endl;
		mincost += min;
	}
	cout<<endl<<"Minimum cost= "<<mincost;
}


int main()
{

	z=8;
	l=9;
    for(int i=0;i<z;i++)
    {
        for(int j=0; j<z; j++)
        {
            cost[i][j]= INT_MAX;
        }
    }
cost[0][1]=1;
cost[0][2]=2;
cost[2][3]=3;
cost[3][4]=4;
cost[3][5]=5;
cost[5][4]=100;
cost[5][6]=7;
cost[6][7]=101;
cost[4][7]=8;
    for (int i = 0; i < z; i++)
        parent[i] = i;
	BFsMST();
	return 0;
}
