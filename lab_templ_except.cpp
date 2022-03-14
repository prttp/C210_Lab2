//Исключения

//Шаблоны: 
	//		шаблоны функций,
	//		шаблоны классов,

#include "lab2\Swap.h"
#include "lab2\myString.h"
#include <tchar.h>
#include "lab2\Lab2\MyStack.h"
#include "lab2\Lab2\MyStack2.h"
#include <stdexcept>

#define _CRT_SECURE_NO_WARNINGS

#define stop __asm nop

int _tmain(int argc, _TCHAR* argv[])
{
	


////////////////////////////////////////////////////////////////////////////
	//Тема. Шаблоны функций.
	//Создайте шаблон функции перестановки местами двух
	//значений - Swap(). Проверьте работоспособность созданного
	//шаблона с помощью приведенного ниже фрагмента кода.
	//Подсказка 1: объявление шаблона корректнее поместить в .h-файл.

	int iX = 1, iY = -1;
	Swap(iX, iY);

	double dX = 0.5, dY = -5.5;
	Swap(dX, dY);
	stop

	//Подсказка 2: подумайте, что нужно реализовать, для того,
	//			чтобы следующий вызов работал с объектами MyString
	//			не только корректно, но и эффективно
	MyString str1("One"), str2("Two");
	Swap(str1, str2);
	stop

/////////////////////////////////////////////////////////////////////
	
	//Тема. Шаблоны классов.
	//Задание 1.
	//Создайте шаблон класса MyStack для хранения элементов любого типа T.
	//Подсказка: 1.элементы нужно где-то хранить - простым и удобным средством
	//			для хранения последовательно расположенных в памяти элементов
	//			является массив, 
	//			2.для задания максимального размера стека может быть использован
	//			параметр-константа шаблона
	//			3.обязательными операциями со стеком являются "push" и "pop". Для
	//			того, чтобы гарантировать корректное выполнение этих операций 
	//			хорошо было бы генерировать исключение в аварийной ситуации
	//			4. дополнительно реализуйте operator[] таким образом, чтобы пользователь
	//			мог читать/изменять значения только тех элементов, которые он формировал


	
	//С помощью шаблона MyStack создайте стек из 5 элементов int - iStack и
	//стек из 10 элементов MyString - strStack и поэкспериментируйте с функциями
	//push() и pop(), operator[]
	{
	MyStack<int, 5> iStack(3, 2);
	MyStack<MyString, 10> strStack(2);

	iStack.push(5);
	iStack.push(3);
	try
	{
		iStack.push(1);
	}
	catch (std::out_of_range e)
	{
		std::cerr << e.what() << std::endl;
	}

	strStack.push(MyString("abc"));
	{
		MyString str1("Hello");
		MyString* str2 = new MyString("world");
		strStack.push(str1);
		strStack.push(*str2);
		delete str2;
	}
	strStack.push(MyString("yyy"));
	MyString tmp = strStack[2];
	strStack[0] = "xxx";

	stop

}

	//Задание 2. Реализуйте шаблон стека - MyStack2 таким образом, чтобы 
	//для хранения элементов использовался ОДНОСВЯЗНЫЙ список.
	//Реализуйте возможность распечатать элементы стека в том порядке, в котором их заносил (push())
	//пользователь
{
	MyStack2<MyString> s;
	{
		s.push(MyString("abc "));
		s.push(MyString("def"));
		s.push(MyString("ghi"));
		MyString str = s.last();
		s.pop();
		str = MyString("xyz");
		s.push(str);
	}
	std::cout << std::endl << s;

	MyStack2<MyString> s2;
	s2.push(MyString("2222 "));
	s2.push(MyString("2222 "));
	s2.push(MyString("2222 "));
	s2.push(MyString("2222 "));
	s2.push(MyString("2222 "));
	s2 = s;
	std::cout << std::endl << s2;

	s2.pop();
	std::cout  << "\ns2: " << s2;
	MyStack2<MyString> s3;
	s3.push(MyString("12"));
	s3.push(MyString("34"));
	s3.push(MyString("56"));
	s3.push(MyString("78"));
	std::cout << "\ns3: " << s3;
	s2 = s3;
	std::cout  << "\ns2: " << s2;

}
stop





	

	return 0;
}

