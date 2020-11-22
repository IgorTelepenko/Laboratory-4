#include <iostream>
using namespace std;

int Levenshtein_len(char start_word[], char fin_word[], int start_len, int fin_len);

int main()
{
	int len_of_the_word = 0;
	cout << "enter the number of symbols of the word: ";
	cin >> len_of_the_word;

	cout << "enter the word: ";
	char* the_word = new char[len_of_the_word];
	for (int i = 0;i < len_of_the_word;i++)
	{
		cin >> the_word[i];
	}

	cout << "enter the number symbols in the result word: ";
	int len_of_res_word;
	cin >> len_of_res_word;
	
	cout << "enter the result word: ";
	char* res_word = new char[len_of_res_word];
	for (int i = 0;i < len_of_res_word;i++)
	{
		cin >> res_word[i];
	}

	cout << "the Levenshtein number is: " << Levenshtein_len(the_word, res_word, len_of_the_word, len_of_res_word);

	return 0;
}

int Levenshtein_len(char start_word[], char fin_word[], int start_len, int fin_len)
{
	int numb_of_operations = fin_len + start_len;
	int start_comparing_pos, last_comparing_pos;


	start_comparing_pos = 0 - fin_len + 1;
	last_comparing_pos = start_len - 1;

//преревіряєсо всі можливі варіанти розташування другого слова, порівняно з позицією першого слова
	for (int i = start_comparing_pos;i <= last_comparing_pos;i++)
	{
		int temp_numb_of_operations = 0;
		for (int j = i;j < i + fin_len;j++)
		{

			if (j<0 || j>start_len - 1)
			{
				temp_numb_of_operations++;
			}
			else
			{
				if (fin_word[j - i] != start_word[j])
					temp_numb_of_operations++;
			}
		}
		//далі йде додавання кількості елементів, які видаляються
		if (i >= 0)
		{
			if (i + fin_len - 1 < start_len)
				temp_numb_of_operations += start_len - fin_len;
			else
			{
				temp_numb_of_operations += i;
			}
		}
		else
		{
			temp_numb_of_operations += start_len - (i + fin_len);
		}
		//далі: якщо кількість операцій мінімальніша за попередні варіанти, то запам'ятовуємо її
		if (temp_numb_of_operations < numb_of_operations)
		{
			numb_of_operations = temp_numb_of_operations;

		}
	}


	return numb_of_operations;
}

