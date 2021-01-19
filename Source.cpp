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
	std::cout << "��������� ������ �� " << length << " �����\t\t-\t";
	// ������ ��� ����������� ������� �� ��������� ����� �� 1 �� 100
	for (int i = 0; i < length; ++i)
	{
		mas[i] = 1 + rand() % 100;
		masSecond[i] = mas[i];
		masThird[i] = mas[i];
		std::cout << mas[i] << " ";
	}
	std::cout << std::endl;

	// /��������� ������ ������ - mas � ������ ������� sort()
//	std::sort(mas, mas + length, std::greater<int>());
	std::sort(mas, mas + length);
	// ����� ���������������� � ������ �������� sort() ������� mas
	std::cout << "��������������� ������ �������� sort\t-\t";
	for (int i = 0; i < length; ++i)
	{
		std::cout << mas[i] << " ";
	}
	std::cout << std::endl;

	// ���������� ������� ������� - masSecond ������� ������
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
	// ����� ��������������� � ������ ������ ������ ������� masSecond
	std::cout << "��������������� ������ ������� ������\t-\t";
	for (int i = 0; i < length; ++i)
	{
		std::cout << masSecond[i] << " ";
	}
	std::cout << std::endl;

	// ���������� ������� ������� - masThird � ������ ������� ��������
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
			//			std::cout << "\n������� ���� ���������� �� " << iteration + 1 << "-� ���������\n";
			break;
		}
	}
	// ����� ��������������� � ������� ������ �������� ������� masThird
	std::cout << "��������������� ������ ������� ��������\t-\t";
	for (int i = 0; i < length; ++i)
	{
		std::cout << masThird[i] << " ";
	}
	std::cout << std::endl;
	system("pause");
}
