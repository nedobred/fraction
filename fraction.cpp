
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

	int getTest_num() const { return m_numerator; }
	int getTest_den() const { return m_denominator; }
	
	/////////////////////////////////////////////////////////////////////////////
	
	
	
	friend Fraction operator/(Fraction value1, Fraction value2); // объявление дружественной функции перегрузки оператора деление
	friend Fraction operator*(Fraction value1, Fraction value2); // объявление дружественной функции перегрузки оператора умножение
	friend Fraction operator-(Fraction value1, Fraction value2); // объявление дружественной функции перегрузки оператора вычитание
	friend Fraction operator+(Fraction value1, Fraction value2); // объявление дружественной функции перегрузки оператора сложение


	//friend Fraction operator<<(Fraction value1, Fraction value2); // дружественная функция перегрузки оператора вывода на экран

private:
	int m_numerator;		// переменная член класса - числитель
	int m_denominator;		// переменная член класса - знаменатель
};
// конец класса


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Fraction operator/(Fraction value1, Fraction value2)		// перегрузка оператора деление
{
	Fraction f_result;	// создаем переменную для хранение значений

	f_result.m_numerator = (value1.m_numerator *value2.m_denominator);	// считаем значение числителя
	f_result.m_denominator = (value1.m_denominator * value2.m_numerator);	// считаем значение знаменателя
	if (f_result.m_numerator == f_result.m_denominator)
	return f_result;
}
//------------------------------------------------------------------------------------------------------------------------------------
Fraction operator*(Fraction value1, Fraction value2)		// перегрузка оператора умножение
{
	Fraction f_result;	// создаем переменную для хранение значений

	f_result.m_numerator = (value1.m_numerator * value2.m_numerator);
	f_result.m_denominator = (value1.m_denominator * value2.m_denominator);
	return f_result;
}
//------------------------------------------------------------------------------------------------------------------------------------
Fraction operator-(Fraction value1, Fraction value2)		// перегрузка оператора вычитание
{
	Fraction f_result;	// создаем переменную для хранение значений

	f_result.m_numerator = (value1.m_numerator * value2.m_denominator - value2.m_numerator * value1.m_denominator); // числитель
	f_result.m_denominator = (value1.m_denominator * value2.m_denominator); // знаменатель
	return f_result;
}
//------------------------------------------------------------------------------------------------------------------------------------
Fraction operator+(Fraction value1, Fraction value2)		// перегрузка оператора сложение
{
	Fraction f_result;	// создаем переменную для хранение значений

	f_result.m_numerator = (value1.m_numerator * value2.m_denominator + value2.m_numerator * value1.m_denominator); // числитель
	f_result.m_denominator = (value1.m_denominator * value2.m_denominator);		// знаменатель
	return f_result;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL, ""); 
	
	
	int numerator1;
	int denominator1;
	
	int numerator2;
	int denominator2;

	// блок ввода значений для перовой дроби
	cout << "Введите числитель первой дроби: ";
	cin >> numerator1;
	cout << "Введите знаменатель первой дроби: ";
	cin >> denominator1;
	Fraction drob1 (numerator1, denominator1);	// uniform-инициализация, вызывается конструктор Fraction(int, int)
	cout << "Первая дробь: " << drob1.getNumerator() << "/" << drob1.getDenominator() << '\n';

	// блок ввода значений для второй дроби
	cout << "Введите числитель второй дроби: ";
	cin >> numerator2;
	cout << "Введите знаменатель второй дроби: ";
	cin >> denominator2;
	Fraction drob2 (numerator2, denominator2);	// uniform-инициализация, вызывается конструктор Fraction(int, int)
	cout << "Вторая дробь: " << drob2.getNumerator() << "/" << drob2.getDenominator() << '\n';
	// блок запроса арифметического действия
	cout << endl;
	cout << "Выберите арифметическое действие:\n1 - деление\n2 - умножение\n3 - вычитание\n4 - сложение" << endl;
	int action;
	cin >> action;
	
	if (action == 1) //деление
	{
		Fraction result = drob1 / drob2;
		cout << endl;
		cout << result.getTest_num() << "/" << result.getTest_den() << '\n';
	}
	else if (action == 2) //умножение
	{
		Fraction result = drob1 * drob2;
		cout << endl;
		cout << result.getTest_num() << "/" << result.getTest_den() << '\n';
	}

	else if (action == 3) //вычитание
	{
		Fraction result = drob1 - drob2;
		cout << endl;
		cout << result.getTest_num() << "/" << result.getTest_den() << '\n';
	}

	else if (action == 4) //сложение
	{
		Fraction result = drob1 + drob2;
		cout << endl;
		cout << result.getTest_num() << "/" << result.getTest_den() << '\n';
	}
	
	return 0;
}


