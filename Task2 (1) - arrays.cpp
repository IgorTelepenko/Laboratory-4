#include <iostream>
#include <cmath>
using namespace std;

void insertion_sort(int arr[], int n); //сортування

void all_triangle_sides(int numbers[], int n); //знаходження всіх можливих сторін гострокутного трикутника


int main()
{
	int n;
	cout << "enter the quantity of numbers: ";
	cin >> n;

	int* the_numbers = new int[n];
	for (int i = 0;i < n;i++)
	{
		cin >> the_numbers[i];
	}
	
	insertion_sort(the_numbers, n); //відсортуємо масив чисел для подальшого
	all_triangle_sides(the_numbers, n);
	return 0;
}

void insertion_sort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void all_triangle_sides(int numbers[], int n)
{
	int temp_side1 = -1, temp_side2 = -1, temp_side3 = -1;
	cout << "the sides of an acute triangle: " << endl;
	for (int i1 = 0;i1 < n;i1++)
	{
		if (numbers[i1] != temp_side1) //для запобігання кількох однакових відповідей
			for (int i2 = i1 + 1;i2 < n;i2++)
			{
				if (numbers[i2] != temp_side2) //для запобігання кількох однакових відповідей
					for (int i3 = i2 + 1;i3 < n;i3++)
					{
						if (numbers[i3] != temp_side3) //для запобігання кількох однакових відповідей
							if (!((numbers[i1] + numbers[i2] < numbers[i3]) || (numbers[i1] + numbers[i3] < numbers[i2]) || (numbers[i3] + numbers[i2] < numbers[i1]))) //перевіряємо чи такий трикутник може існувати
							{ //первіряємо чи трикутник гострокутний:
								if (((pow(numbers[i1], 2) + pow(numbers[i2], 2) > pow(numbers[i3], 2)) && (numbers[i1], 2) + pow(numbers[i3], 2) > pow(numbers[i2], 2)) && (pow(numbers[i3], 2) + pow(numbers[i2], 2) > pow(numbers[i1], 2)))
								{
									cout << numbers[i1] << " " << numbers[i2] << " " << numbers[i3] << endl;
									temp_side1 = numbers[i1];
									temp_side2 = numbers[i2];
									temp_side3 = numbers[i3];
								}

							}
					}
			}
	}
	/*int* new_array_without_reps;
	int quantity_of_diff_numbers = n;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (i != j && numbers[i] == numbers[j])
			{
				numbers[i] = -1;
				quantity_of_diff_numbers--;
				cout << "-1 will be nr " << i << endl;
			}
		}
	}
	new_array_without_reps = new int[quantity_of_diff_numbers];

	int new_ind = -1;
	for (int i = 0;i < n;i++)
	{
		if (numbers[i] != -1)
		{
			new_ind++;
			new_array_without_reps[new_ind] = numbers[i];
		}
	}
	cout << "the result: " << endl;
	for (int i1 = 0;i1 < quantity_of_diff_numbers;i1++)
	{
		for (int i2 = 0;i2 < quantity_of_diff_numbers;i2++)
		{
			if(i1!=i2)
			for (int i3 = 0;i3 < quantity_of_diff_numbers;i3++)
			{
				if(i2!=i3 && i1!=i3)
				if (!((new_array_without_reps[i1] + new_array_without_reps[i2] < new_array_without_reps[i3]) || (new_array_without_reps[i1] + new_array_without_reps[i3] < new_array_without_reps[i2]) || (new_array_without_reps[i3] + new_array_without_reps[i2] < new_array_without_reps[i1])))
				{
					if ((pow(new_array_without_reps[i1], 2) + pow(new_array_without_reps[i2], 2) > pow(new_array_without_reps[i3], 2)) && (pow(new_array_without_reps[i1], 2) + pow(new_array_without_reps[i3], 2) > pow(new_array_without_reps[i2], 2)) && (pow(new_array_without_reps[i3], 2) + pow(new_array_without_reps[i2], 2) > pow(new_array_without_reps[i1], 2)))
					{
						cout << new_array_without_reps[i1] << " " << new_array_without_reps[i2] << " " << new_array_without_reps[i3] << endl;
					}

				}
			}
		}
	}*/
}
