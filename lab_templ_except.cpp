//����������

//�������: 
	//		������� �������,
	//		������� �������,

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
	//����. ������� �������.
	//�������� ������ ������� ������������ ������� ����
	//�������� - Swap(). ��������� ����������������� ����������
	//������� � ������� ������������ ���� ��������� ����.
	//��������� 1: ���������� ������� ���������� ��������� � .h-����.

	int iX = 1, iY = -1;
	Swap(iX, iY);

	double dX = 0.5, dY = -5.5;
	Swap(dX, dY);
	stop

	//��������� 2: ���������, ��� ����� �����������, ��� ����,
	//			����� ��������� ����� ������� � ��������� MyString
	//			�� ������ ���������, �� � ����������
	MyString str1("One"), str2("Two");
	Swap(str1, str2);
	stop

/////////////////////////////////////////////////////////////////////
	
	//����. ������� �������.
	//������� 1.
	//�������� ������ ������ MyStack ��� �������� ��������� ������ ���� T.
	//���������: 1.�������� ����� ���-�� ������� - ������� � ������� ���������
	//			��� �������� ��������������� ������������� � ������ ���������
	//			�������� ������, 
	//			2.��� ������� ������������� ������� ����� ����� ���� �����������
	//			��������-��������� �������
	//			3.������������� ���������� �� ������ �������� "push" � "pop". ���
	//			����, ����� ������������� ���������� ���������� ���� �������� 
	//			������ ���� �� ������������ ���������� � ��������� ��������
	//			4. ������������� ���������� operator[] ����� �������, ����� ������������
	//			��� ������/�������� �������� ������ ��� ���������, ������� �� ����������


	
	//� ������� ������� MyStack �������� ���� �� 5 ��������� int - iStack �
	//���� �� 10 ��������� MyString - strStack � ������������������� � ���������
	//push() � pop(), operator[]
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

	//������� 2. ���������� ������ ����� - MyStack2 ����� �������, ����� 
	//��� �������� ��������� ������������� ����������� ������.
	//���������� ����������� ����������� �������� ����� � ��� �������, � ������� �� ������� (push())
	//������������
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

