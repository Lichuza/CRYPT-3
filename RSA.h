#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
class RSA
{
public:
	
	//��� �������
	long int encryptSignRSA(const long int h);
	long int decryptSignRSA(const long int h);

	//��� RSA(���������)
	void encryptRSA();
	void decryptRSA();

	//��������, �������� �����
	bool createKey();

	//�����������
	RSA(const string msg, const int P, const int Q) { s = msg; p = P; q = Q; setMsg(msg); }

	//��������� ���������
	void setMsg(const string msg) { s = msg; }

private:
	//���������
	string s;

	//������ ����� � ������ � ������������ 
	vector<long int> encrypt;
	vector<char> decrypt;

	int p , q, n, f, e, d;	
};

