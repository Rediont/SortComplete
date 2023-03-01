#include "iostream"
#include "cmath"

using namespace std;

//Сортування вставками

void Insert_Sort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i != (size - 1))
		{
			for (int j = (i + 1); 0 < j; j--) 
			{
				if (arr[j] < arr[j-1])
				{
					swap(arr[j-1], arr[j]);
				}
			}
		}
		else
		{
			for (int j = i; 0 < j; j--)
			{
				if (arr[j] < arr[j-1])
				{
					swap(arr[j-1], arr[j]);
				}
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

//Тести до сортування вставками

bool Test1()
{
	const int size = 6;
	int test_arr[size] = { 2,6,1,8,-20,4 };
	int predicted_arr[size] = { -20,1,2,4,6,8 };
	Insert_Sort(test_arr, size);

	if (std::equal(std::begin(test_arr), std::end(test_arr), std::begin(predicted_arr)))
	{
		cout << "True" << endl;
		return true;
	}
	else
	{
		cout << "False" << endl;
		return false;
	}
}
bool Test2()
{
	const int size = 6;
	int test_arr[size] = { -2,-6,-1,-8,-20,-4 };
	int predicted_arr[size] = { -20,-8,-6,-4,-2,-1 };
	Insert_Sort(test_arr, size);

	if (std::equal(std::begin(test_arr), std::end(test_arr), std::begin(predicted_arr)))
	{
		cout << "True" << endl;
		return true;
	}
	else
	{
		cout << "False" << endl;
		return false;
	}
}
bool Test3()
{
	const int size = 10;
	int test_arr[size] = { 0,-25,22,100,7,25,25,-1,12,2 };
	int predicted_arr[size] = { -25,-1,0,2,7,12,22,25,25,100 };
	Insert_Sort(test_arr, size);

	if (std::equal(std::begin(test_arr), std::end(test_arr), std::begin(predicted_arr)))
	{
		cout << "True" << endl;
		return true;
	}
	else
	{
		cout << "False" << endl;
		return false;
	}
}

//Сортування за рангом (на основі сортування вставками)

void Rank_Sort(int arr[], int size, int max_rank) 
{
	double* rank_arr = new double[size];
	int a = 0;

	for (int rank = 1; rank <= max_rank; rank++)
	{
		a = pow(10, rank);
		for (int j = 0; j < size; j++)
		{
			rank_arr[j] = arr[j] % a;
		}
		//основа
		for (int i = 0; i < size; i++)
		{
			if (i != (size - 1))
			{
				for (int j = (i + 1); 0 < j; j--)
				{
					if (rank_arr[j] < rank_arr[j - 1])
					{
						swap(rank_arr[j - 1], rank_arr[j]);
						swap(arr[j - 1], arr[j]);
					}
				}
			}
			else
			{
				for (int j = i; 0 < j; j--)
				{
					if (rank_arr[j] < rank_arr[j - 1])
					{
						swap(rank_arr[j - 1], rank_arr[j]);
						swap(arr[j - 1], arr[j]);
					}
				}
			}
		}
		//основа
	}
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

//Тести до сортування за розрядами

bool Test4()
{
	const int size = 6;
	int max_rank = 2;
	int test_arr[size] = { 22,63,11,82,-20,47 };
	int predicted_arr[size] = { -20,11,22,47,63,82 };
	Rank_Sort(test_arr, size,max_rank);

	if (std::equal(std::begin(test_arr), std::end(test_arr), std::begin(predicted_arr)))
	{
		cout << "True" << endl;
		return true;
	}
	else
	{
		cout << "False" << endl;
		return false;
	}
}
bool Test5()
{
	const int size = 6;
	int max_rank = 3;
	int test_arr[size] = { 112,636,124,821,-200,468 };
	int predicted_arr[size] = { -200,112,124,468,636,821 };
	Rank_Sort(test_arr, size, max_rank);

	if (std::equal(std::begin(test_arr), std::end(test_arr), std::begin(predicted_arr)))
	{
		cout << "True" << endl;
		return true;
	}
	else
	{
		cout << "False" << endl;
		return false;
	}
}
bool Test6()
{
	const int size = 6;
	int max_rank = 5;
	int test_arr[size] = { 112,600,124,821,-2,468 };
	int predicted_arr[size] = { -2,112,124,468,600,821 };
	Rank_Sort(test_arr, size, max_rank);

	if (std::equal(std::begin(test_arr), std::end(test_arr), std::begin(predicted_arr)))
	{
		cout << "True" << endl;
		return true;
	}
	else
	{
		cout << "False" << endl;
		return false;
	}
}

int main() 
{
	Test1();
	Test2();
	Test3();

	Test4();
	Test5();
	Test6();

	system("pause");
	return 0;
}