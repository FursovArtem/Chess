#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>
using namespace std;

string multistring(string str, int times)
{
	string result;
	while (times > 0)
	{
		result += str;
		times--;
	}
	return result;
}
void chess_v1(int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++)
			{
				for (int l = 0; l < size; l++)
				{
					//cout << (i + k & 1 ^ 0 ? "  " : "* ");
					//то же самое что и
					//cout << (i + k & 1 ? "  " : "* ");
					//или
					cout << (i & 1 ^ k & 1 ? "  " : "* ");
				}
			}
			cout << endl;
		}
	}
}
void chess_v2(int size)
{
	for (int i = 0; i < size * size; i++)
	{
		for (int j = 0; j < size * size; j++)
		{
			if (i % (size << 1) < size && j % (size << 1) < size ||
				i % (size << 1) >= size && j % (size << 1) >= size)
			{
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}
}
void chess_v3(int size)
{
	string stars = multistring("* ", size), spaces = multistring("  ", size);
	string odd, even; int i = size;
	while (i > 0)
	{
		i > 0 ? even += stars, odd += spaces, i-- : NULL;
		i > 0 ? even += spaces, odd += stars, i-- : NULL;
	}
	for (; i < size * size; i++)
	{
		cout << (i % (size << 1) < size ? even + "\xA" : odd + "\xA");
	}
}

void main()
{
	setlocale(LC_ALL, "");
	int size;
	cout << "Введите размер доски: "; cin >> size;
	clock_t start; double duration;
	start = clock();
	//chess_v1(size);
	//chess_v2(size);
	chess_v3(size);
	duration = (clock() - start) / static_cast<double>(CLOCKS_PER_SEC);
	cout << "Время выполнения: " << duration << '\xA';
}

//test
//size = 30
//chess_v1	:	73 sec
//chess_v2	:	73 sec
//chess_v3	:	40 sec