#pragma once
#include<stdlib.h>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
class DES
{
public:
	DES(const string msg, const string key);
	//Преобразование в двоичный код
	void transformationBit(const string m,string &bitOrder);
	//Перестановка
	void transposition1();
	//Разбиение на подблоки
	void split();
	//Расширение блока R
	void expansionR();
	//Сложение по модулю 2
	void xorRe();
	//Подстановка
	void permutation();
	//Сложение по модулю 2
	void xorRL();
	//Соединение блоков
	void linkRL();
	//Вторая перестановка
	void transposition2();

private:
	//Вектор битовой последовательности
	string bitOrderMsg;
	string bitOrderKey;
	//Вектор переставленных битов
	vector<char> bitOrderTransposition;

	//Левый и правый блок
	vector<char> L;
	vector<char> R;

	//Расширенный блок R
	vector<char> Re;

	//Вектор после сложения по модулю 2(1)
	vector<int> RXor;

	//Вектор 10-ых чисел после подстановки
	vector<int> permutationV10;

	//Строка 2-ых чисел после подстановки
	vector<char>bitOrderPermutation;

	//Вектор после сложения по модулю 2(2)
	vector<int> newR;

	//Вектор L+R
	vector<int> newLR;

	//Финальный вектор после второй перестановки
	vector<int> finalLR;

	//Вектор с позициями для первой перестановки
	vector<int>transpositionV1 = { 58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 
	38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8, 57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 
	11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7 };

	int permutationV[4][16] = { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
	{0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8 },
	{4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
	{15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 3} };

	//Вектор с позициями для второй перестановки
	vector<int>transpositionV2 = { 40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 
		54, 22, 6, 39, 37, 5, 45, 13, 53, 21, 61, 29, 36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 1, 59, 
		27, 34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25 };
};

