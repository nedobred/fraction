
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
	Fraction(int k_numerator, int k_denominator = 1) // Конструктор с одним параметром, один из которых имеет значение по умолчанию
	{
		if (k_denominator != 0)
		{
			m_numerator = k_numerator;
			m_denominator = k_denominator;
		}

	}
	/////////////////////////////////////////////////////////////////////////////
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

	
	/////////////////////////////////////////////////////////////////////////////
	
	
	
	friend Fraction operator/(Fraction value1, Fraction value2); // дружественная функция перегрузки оператора деление
	friend Fraction operator*(Fraction value1, Fraction value2); // дружественная функция перегрузки оператора умножение
	friend Fraction operator-(Fraction value1, Fraction value2); // дружественная функция перегрузки оператора вычитание
	friend Fraction operator+(Fraction value1, Fraction value2); // дружественная функция перегрузки оператора сложение


	//friend Fraction operator<<(Fraction value1, Fraction value2); // дружественная функция перегрузки оператора вывода на экран

private:
	int m_numerator;		// переменная член класса - числитель
	int m_denominator;		// переменная член класса - знаменатель
};
// конец класса

Fraction operator/(Fraction value1, Fraction value2)		// перегрузка оператора деление
{
	Fraction f_result;	// создаем переменную для хранение значений

	f_result = (value1.m_denominator*value2.m_numerator)/(value1.m_numerator*value2.m_denominator);
	return f_result;
}

Fraction operator*(Fraction value1, Fraction value2)		// перегрузка оператора умножение
{
	Fraction f_result;	// создаем переменную для хранение значений

	f_result = (value1.m_denominator * value2.m_denominator) / (value1.m_numerator * value2.m_numerator);
	return f_result;
}

Fraction operator-(Fraction value1, Fraction value2)
{
	Fraction f_result;	// создаем переменную для хранение значений

	f_result = (value1.m_numerator * value2.m_denominator + value2.m_numerator * value1.m_denominator) / (value1.m_denominator * value2.m_denominator);
	return f_result;
}



Fraction operator+(Fraction value1, Fraction value2)		// перегрузка оператора сложение
{
	Fraction f_result;	// создаем переменную для хранение значений

	f_result = (value1.m_numerator * value2.m_denominator - value2.m_numerator * value1.m_denominator) / (value1.m_denominator * value2.m_denominator);
	return f_result;
}









int main()
{
	setlocale(LC_ALL, ""); 
	
	
	int numerator1;
	int denominator1;
	
	int numerator2;
	int denominator2;

	// блок ввода значений для перовой дроби
	cout << "Введите числитель и знаменатель первой дроби: ";
	cin >> numerator1;
	cin >> denominator1;
	Fraction drob1 (numerator1, denominator1);	// uniform-инициализация, вызывается конструктор Fraction(int, int)
	//cout << drob1.getNumerator() << "/" << drob1.getDenominator() << '\n';

	// блок ввода значений для второй дроби
	cout << "Введите числитель и знаменатель второй дроби: ";
	cin >> numerator2;
	cin >> denominator2;
	Fraction drob2 (numerator2, denominator2);	// uniform-инициализация, вызывается конструктор Fraction(int, int)
	//cout << drob2.getNumerator() << "/" << drob2.getDenominator() << '\n';
	
	
	// деление дробей
	
	Fraction result = drob1 / drob2;
	cout << endl;
	cout << result.getValue() << '\n';
	
	
	
	return 0;
}


