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
	//����� ������� ����� ������ ��� ������������
	void display2(int mas[]);
	//����� �� ����� ��������� ����
	void display(int mas[], int a, int b);
	//������� � �������� ������� ���������
	void dvoich(unsigned char ch);
	//������� � 10 ������� ���������
	void inDec(int mas1[], int mas2[]);
	//�������� �� ������ 2 � ������� 32
	void mod232(int mas1[], int mas2[], int mas3[], int j);
	//�������� �� ������ 2 
	void mod2(int mas1[], int mas2[], int mas3[]);
	//����������� ������� �������� ��������� ���� ����
	void pris(int mas1[], int mas2[], int j);
	//������� �������� ��� ����
	void display3(int mas[]);
	//����������� ������� �������� ��������� ���� ����
	void pris2(int mas1[], int mas2[]);
	//���������� ����������
	void Run();
	//�����������
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

