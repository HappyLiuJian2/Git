#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> g_vec;

#define VEC_ITER vector<int>::iterator

#define TRAVE_G_VEC \
	for (VEC_ITER iter = g_vec.begin(); iter != g_vec.end(); ++iter)

int local_com(int a, int b)
{
	return a > b;
}

int main()
{
	g_vec.push_back(12);
	g_vec.push_back(20);
	g_vec.push_back(18);
	g_vec.push_back(10);

	sort(g_vec.begin(), g_vec.end(), local_com);

	TRAVE_G_VEC
	{
		cout << *iter << endl;
	}

	system("pause");
	return 0;
}
