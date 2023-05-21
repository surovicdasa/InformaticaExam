
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define tab "\t"
#define delimiter "\n--------------------------------------------\n"

//const string NAME = "liczby.txt";

void import(const char NAME[], int nums[], const int SIZE)
{
	//cin - ConsoleIn
	//fin - FileIn
	ifstream fin(NAME);	//1) Stream creation
	if (fin.is_open())
	{
		//2) Stream reading:
		for (int i = 0; i < SIZE; i++)
		{
			fin >> nums[i];
		}
		//3) All streams have to be closed!!!
		fin.close();
	}
	else
	{
		//cerr - Console errors ()
		std::cerr << "Error: file not found" << endl;
	}
}
void Print(const int arr[], const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
int count_prime_factors(int number)
{
	int count = 1;
	for (int i = 2; i < number; i++)
	{
		while (number % i == 0)
		{
			number /= i;
			count++;
		}
	}
	return count;
}
int count_unique_prime_factors(int number)
{
	int count = 1;
	for (int i = 2; i < number; i++)
	{
		bool unique = true;
		while (number % i == 0)
		{
			number /= i;
			if (unique)count++;
			unique = false;
		}
	}
	return count;
}

void find_three(const int arr[], const int SIZE)
{
	std::ofstream fout("trojki.txt");
	int count = 0;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (arr[j] % arr[i] == 0 && arr[j] != arr[i])
			{
				for (int k = 0; k < SIZE; k++)
				{
					if (arr[k] % arr[j] == 0 && arr[j] != arr[k])
					{
						count++;
						cout << count << tab << arr[i] << "\t" << arr[j] << "\t" << arr[k] << endl;
						fout << count << tab << arr[i] << "\t" << arr[j] << "\t" << arr[k] << endl;
					}
				}
			}
		}
	}

	/*for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (arr[i] % arr[j] == 0 && arr[j] != arr[i])
			{
				for (int k = 0; k < SIZE; k++)
				{
					if (arr[j] % arr[k] == 0 && arr[j] != arr[k])
					{
						cout << ++count << tab << arr[k] << tab << arr[j] << tab << arr[i] << endl;
					}
				}
			}
		}
	}*/
	fout.close();
	system("notepad trojki.txt");
}


//#define ZADANIE_4_2

int main()
{
	const int SIZE = 200;
	int nums[SIZE];
	import("liczby.txt", nums, SIZE);
	Print(nums, SIZE);
	cout << delimiter << endl;
	cout << 88 << endl;
	cout << count_prime_factors(88) << endl;
	cout << count_unique_prime_factors(88) << endl;
	cout << delimiter << endl;

#ifdef ZADANIE_4_2
	int first_number = 0;
	int counter = 0;
	for (int i = 0; i < SIZE; i++)
	{
		string s_number = to_string(nums[i]);
		//https://legacy.cplusplus.com/reference/string/to_string/
		if (s_number.front() == s_number.back())
		{
			if (first_number == 0)first_number = nums[i];
			//cout << s_number << tab;
			counter++;
		}
	}
	cout << endl;
	cout << "First number:\t" << first_number << endl;
	cout << "Count of numbers: " << counter << endl;
#endif // ZADANIE_4_2

	int counter = 0;
	int max_factor = 0;
	int max_unique_factor = 0;
	int max_factor_number = 0;
	int max_unique_factor_number = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (count_prime_factors(nums[i]) >= max_factor)
		{
			//cout << nums[i] << tab;
			max_factor_number = nums[i];
			max_factor = count_prime_factors(nums[i]);
		}
		if (count_unique_prime_factors(nums[i]) >= max_unique_factor)
		{
			max_unique_factor = count_unique_prime_factors(nums[i]);
			max_unique_factor_number = nums[i];
		}
	}
	cout << endl;
	for (int i = 0; i < SIZE; i++)
	{
		if (count_prime_factors(nums[i]) == max_factor)counter++;
	}
	int* max_factor_numbers = new int[counter];
	for (int i = 0, j = 0; i < SIZE; i++)
	{
		if (count_prime_factors(nums[i]) == max_factor)
		{
			max_factor_numbers[j++] = nums[i];
		}
	}
	cout << "Max factor numbers: ";// << max_factor_number << endl;
	for (int i = 0; i < counter; i++)
	{
		cout << max_factor_numbers[i] << tab;
	}
	cout << endl;
	cout << "Number of factors: " << max_factor << endl;
	delete[] max_factor_numbers;

	cout << delimiter << endl;
	cout << "Max unique factor number: " << max_unique_factor_number << endl;
	cout << "Number of factors:\t\t" << count_prime_factors(max_unique_factor_number) << endl;
	cout << "Number of unique factors:\t\t" << count_unique_prime_factors(max_unique_factor_number) << endl;

	cout << delimiter << endl;
	cout << "\n=================================================\n";
	find_three(nums, SIZE);
}
