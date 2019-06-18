#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <locale.h>
#include<windows.h>
using namespace std;
class gost
{
public:
	//Вывод массива чисел строки для перестановки
	void display2(int mas[]);
	//Вывод на экран двоичного кода
	void display(int mas[], int a, int b);
	//Перевод в двоичную систему счисления
	void dvoich(unsigned char ch);
	//Перевод в 10 систему счисления
	void inDec(int mas1[], int mas2[]);
	//Сложение по модулю 2 в степени 32
	void mod232(int mas1[], int mas2[], int mas3[], int j);
	//Сложение по модулю 2 
	void mod2(int mas1[], int mas2[], int mas3[]);
	//Присваиваем массиву значения двоичного кода букв
	void pris(int mas1[], int mas2[], int j);
	//Выводим двоичный код букв
	void display3(int mas[]);
	//Присваиваем массиву значения двоичного кода букв
	void pris2(int mas1[], int mas2[]);
	//Выполнение шифрования
	void Run();
	//Конструктор
	gost(string msg, string key) { msg1=msg, msg2=key; }
	
private:
	int kodb[8];
	int L[32];
	int R[64];
	int R1[32];
	int X[32];
	int sumRX[32];
	int peres2[64];
	int jj = 0;
	int kodprob[8] = { 0, 0, 0, 1, 0, 0, 0, 0 };
	int z = 0;
	string msg1;
	string msg2;
};

