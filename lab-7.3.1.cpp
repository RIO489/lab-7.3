#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n, const int k, const int Low, const int High);
void Print(int** a, const int n, const int k);
int SumElements(int** a, const int n, const int k);
void SumDiag1(int** a, const int n, const int k,int& result);
void SumDiag2(int** a, const int n, const int k, int& result);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -5;
	int High = 47;
	int n;
	cout << "n = "; cin >> n;
	int k;
	cout << "k = "; cin >> k;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[k];
	int S = -2;
	int S1 = -1;
	Create(a, n, k, Low, High);
	Print(a, n, k);
	cout << "Sum Min Element = " << SumElements(a, n, k) << endl;
	int R1;
	int R2;
	SumDiag1(a, n, k,R1);
	cout << endl;
	SumDiag2(a, n, k,R2);
	if (R1 > R2)
	{
		cout << "MinSum = " << R2 << endl;
	}
	else
	{
		cout << "MinSum = " << R1 << endl;
	}
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void Create(int** a, const int n, const int k, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int n, const int k)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

/*int SumElements(int** a, const int n, const int k)
{
	int S = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (a[i][j] < 0)
			{
				S = 0;
				break;
			}
			else
			{
				S += a[i][j];
			}
		}
		cout << "S[" << i << "] =" << S << endl;
	}
	return S;
}*/
int SumElements(int** a, const int n, const int k)
{
	int S = 0;
	int count = 0;
	int i = 0;
	for (int j = 0; j < k; j++)
	{
		count = 0;
		for (i = 0; i < n; i++)
		{
			if (a[i][j] < 0)
			{
				count += 1;
				break;
			}
		}
		if (count == 0)
		{
			for (i = 0; i < n; i++)
			{
					S += a[i][j];
			}
		}
	}
	return S;
}
void SumDiag1(int** a, int n, int k,int& result)
{
	int S1 = 0;
	int S = 0;
	int j = 0;
	int i = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	int tmpS = n*5+k*5;
	int z = k;
		for (int g = 0; g < k; g++)
		{
			S = 0;
			tmp1 = z;
			if (tmp2 == 0)
			{
				for (i = tmp2; i < n; i++)//tmp2 = 0
				{
					j = tmp1 - 1;
					if (j > -1)
					{
						cout <<" "<< a[i][j];
						S += abs(a[i][j]);
						tmp1--;
					}
				}
			}
			for (i = tmp2; i < n; i++)// 0 < tmp2 < 5
			{
				j = tmp1 - 1;
				if (j > -1)
				{
					cout <<" "<< a[i][j];
					S += abs(a[i][j]);
					tmp1--;
				}
			}
			z--;
			if (tmpS > S)
			{
				tmpS = S;
			}
			cout << "		SumModul = " << S << endl;
		}
		result = tmpS;
}

void SumDiag2(int** a, int n, int k,int& result)
{
	int S1 = 0;
	int j = 0;
	int i = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	int tmpS = n*5 + k*5;
	int z = k;
		for (int g = 0; g < n; g++)
		{
			S1 = 0;
			tmp1 = z;
			if (tmp2 == 0)
			{
				for (i = 0; i < n; i++)//tmp2 = 0
				{
					j = tmp1 - 1;
					if (j > -1)
					{
						cout << " " << a[i][j];
						S1 += abs(a[i][j]);
						tmp1--;
					}
				}
			}
			for (i = tmp2; i < n; i++)// 0 < tmp2 < 5
			{
				j = tmp1 - 1;
				if (j > -1)
				{
					cout << " " << a[i][j];
					S1 += abs(a[i][j]);
					tmp1--;
				}
			}

			if (tmpS > S1)
			{
				tmpS = S1;
			}
			cout << "		SumModul = " << S1 << endl;
			tmp2++;
		}
		result = tmpS;
}