#include "pch.h"
#include "CppUnitTest.h"
#include "D:\Навчання\ІПЗ\ЛР\3\ІПЗ 3\ІПЗ 3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(MultiplicationTests)
	{
		public:

			TEST_METHOD(Test1_calculate1)		//оголошуєм перший метод тесту
			{
				int x = -2;
				int n = 2;
				int result = 1;
				int actresult = calculate1(n);		//перевіряємо розрахунок якщо х<0
				Assert::AreEqual(result, actresult);	//результат перевірки
			}
			TEST_METHOD(Test1_calculate2)		//оголошуєм другий метод тесту
			{
				int x = 1;
				int n = 2;
				int result = 12;
				int actresult = calculate2(x,n);	//перевіряємо розрахунок якщо х>0
				Assert::AreEqual(result, actresult);	//результат перевірки
			}
			TEST_METHOD(Test_audit1)		//оголошуєм третій метод тесту
			{
				int x1 = 5;
				int x2 = 7;
				try
				{
					audit1(x1, x2);
					Assert::IsTrue(true);	//результат перевірки якщо дані вірні
				}
				catch(...)
				{
					Assert::Fail();	//результат перевірки якщо дані не вірні
				}
			}
			TEST_METHOD(Test_audit2)		//оголошуєм четвертий метод тесту
			{
				int x1 = 5;
				int x2 = 7;
				int h = 2;
				try
				{
					audit2(x1, x2, h);
					Assert::IsTrue(true);	//результат перевірки якщо дані вірні
				}
				catch (...)
				{
					Assert::Fail();	//результат перевірки якщо дані не вірні
				}
			}
	};
}