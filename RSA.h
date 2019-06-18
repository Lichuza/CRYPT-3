#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
class RSA
{
public:
	
	//Для подписи
	long int encryptSignRSA(const long int h);
	long int decryptSignRSA(const long int h);

	//Для RSA(сообщения)
	void encryptRSA();
	void decryptRSA();

	//Проверка, создание ключа
	bool createKey();

	//Конструктор
	RSA(const string msg, const int P, const int Q) { s = msg; p = P; q = Q; setMsg(msg); }

	//Установка сообщения
	void setMsg(const string msg) { s = msg; }

private:
	//Сообщение
	string s;

	//Вектор шифра и вектор с расшифровкой 
	vector<long int> encrypt;
	vector<char> decrypt;

	int p , q, n, f, e, d;	
};

