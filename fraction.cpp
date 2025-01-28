
// Задание. Реализуйте класс Дробь.Необходимо хранить числитель 
// и знаменатель в качестве переменных - членов.Реализуйте 
// функции - члены для ввода данных в переменные - члены, 
// для выполнения арифметических операций(сложение, 
// вычитание, умножение, деление, и т.д.).

#include <iostream>
using namespace std;

class Fraction
{
public:
	Fraction()			// конструктор по умолчанию
	{
		m_numerator = 0;
		m_denominator = 1;
	}
	//Fraction(int k_numerator, int k_denominator) // Конструктор с двумя параметрами
	//{
		
		//{
			//m_numerator = k_numerator;
			//m_denominator = k_denominator;
		//}

	//}

	Fraction(int k_numerator, int k_denominator = 1) // Конструктор с одним параметром, один из которых имеет значение по умолчанию
	{
		if (k_denominator != 0)
		{
			m_numerator = k_numerator;
			m_denominator = k_denominator;
		}

	}

	int getNumerator()
	{
		return m_numerator;
	}
	int getDenominator()
	{
		return m_denominator;
	}

	
	double getValue() 
	{ 
		return static_cast<double>(m_numerator) / m_denominator; 
	}

private:
	int m_numerator;		// переменная член класса - числитель
	int m_denominator;		// переменная член класса - знаменатель
};




int main()
{
	setlocale(LC_ALL, ""); 
	
	
	int numerator1;
	int denominator1;
	int numerator2;
	int denominator2;

	// блок ввода значений для перовй дроби
	cout << "Введите числитель и знаменатель первой дроби: ";
	cin >> numerator1;
	cin >> denominator1;
	Fraction drob1 (numerator1, denominator1);	// uniform-инициализация, вызывается конструктор Fraction(int, int)
	cout << drob1.getNumerator() << "/" << drob1.getDenominator() << '\n';

	// блок ввода значений для второй дроби
	cout << "Введите числитель и знаменатель второй дроби: ";
	cin >> numerator2;
	cin >> denominator2;
	Fraction drob2 (numerator2, denominator2);	// uniform-инициализация, вызывается конструктор Fraction(int, int)
	cout << drob2.getNumerator() << "/" << drob2.getDenominator() << '\n';
	
	
	
	return 0;
}


