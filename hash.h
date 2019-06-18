#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
class Hash
{
public:
	//Конструктор
	Hash(const string msg, const int P, const int Q) { s = msg; p = P; q = Q; n = p * q; setMsg(msg); }

	//Метод получения хэш-функции
	void hash();

	//Получить хэш и установить сообщение
	int getHash() { return H; }
	void setMsg(const string msg) { s = msg; }

private:

	//Сообщение
	string s;

	long int p, q, n, H;
};

