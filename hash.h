#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
class Hash
{
public:
	//�����������
	Hash(const string msg, const int P, const int Q) { s = msg; p = P; q = Q; n = p * q; setMsg(msg); }

	//����� ��������� ���-�������
	void hash();

	//�������� ��� � ���������� ���������
	int getHash() { return H; }
	void setMsg(const string msg) { s = msg; }

private:

	//���������
	string s;

	long int p, q, n, H;
};

