#include <iostream>
#include <algorithm>
#include <ctime>;
int main()
{
	setlocale(LC_ALL, "rus");
	const int length = 10;
	int mas[length] = {};
	int masSecond[length] = {};
	int masThird[length] = {};
	int timeS;
	timeS = static_cast<unsigned int>(time(0));
	srand(timeS);
	std::cout << "Случайный массив из " << length << " чисел\t\t-\t";
	// Создаём три одинаковыйх массива из случайных чисел от 1 до 100
	for (int i = 0; i < length; ++i)
	{
		mas[i] = 1 + rand() % 100;
		masSecond[i] = mas[i];
		masThird[i] = mas[i];
		std::cout << mas[i] << " ";
	}
	std::cout << std::endl;

	// /Сортируем первый массив - mas с помощю функции sort()
//	std::sort(mas, mas + length, std::greater<int>());
	std::sort(mas, mas + length);
	// Вывод отсортированного с помощю фкнкцуии sort() массива mas
	std::cout << "Отсортированный массив функцией sort\t-\t";
	for (int i = 0; i < length; ++i)
	{
		std::cout << mas[i] << " ";
	}
	std::cout << std::endl;

	// Сортировка второго массива - masSecond методом выбора
	for (int index = 0; index < length - 1; ++index)
	{
		int smallerIndex = index;
		for (int nextIndex = index + 1; nextIndex < length; ++nextIndex)
		{
			if (masSecond[nextIndex] < masSecond[smallerIndex])
			{
				smallerIndex = nextIndex;
			}
		}
		std::swap(masSecond[index], masSecond[smallerIndex]);
	}
	// Вывод отсотированного с помощю метода выбора массива masSecond
	std::cout << "Отсортированный массив методом выбора\t-\t";
	for (int i = 0; i < length; ++i)
	{
		std::cout << masSecond[i] << " ";
	}
	std::cout << std::endl;

	// Сортировка треьего массива - masThird с помощю методом пузырька
	for (int iteration = 0; iteration < length - 1; ++iteration)
	{
		int endOfArrayIndex = length - iteration;
		bool swapped = false;

		for (int currentIndex = 0; currentIndex < endOfArrayIndex - 1; ++currentIndex)
		{
			if (masThird[currentIndex] > masThird[currentIndex + 1])
			{
				std::swap(masThird[currentIndex], masThird[currentIndex + 1]);
				swapped = true;
			}
		}
		if (!swapped)
		{
			//			std::cout << "\nПерервём цикл сортировки на " << iteration + 1 << "-й интерации\n";
			break;
		}
	}
	// Вывод отсортированого с помощью метода пузырька массива masThird
	std::cout << "Отсортированный массив методом пузырька\t-\t";
	for (int i = 0; i < length; ++i)
	{
		std::cout << masThird[i] << " ";
	}
	std::cout << std::endl;
	system("pause");
}
