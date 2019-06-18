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
	//�������������� � �������� ���
	void transformationBit(const string m,string &bitOrder);
	//������������
	void transposition1();
	//��������� �� ��������
	void split();
	//���������� ����� R
	void expansionR();
	//�������� �� ������ 2
	void xorRe();
	//�����������
	void permutation();
	//�������� �� ������ 2
	void xorRL();
	//���������� ������
	void linkRL();
	//������ ������������
	void transposition2();

private:
	//������ ������� ������������������
	string bitOrderMsg;
	string bitOrderKey;
	//������ �������������� �����
	vector<char> bitOrderTransposition;

	//����� � ������ ����
	vector<char> L;
	vector<char> R;

	//����������� ���� R
	vector<char> Re;

	//������ ����� �������� �� ������ 2(1)
	vector<int> RXor;

	//������ 10-�� ����� ����� �����������
	vector<int> permutationV10;

	//������ 2-�� ����� ����� �����������
	vector<char>bitOrderPermutation;

	//������ ����� �������� �� ������ 2(2)
	vector<int> newR;

	//������ L+R
	vector<int> newLR;

	//��������� ������ ����� ������ ������������
	vector<int> finalLR;

	//������ � ��������� ��� ������ ������������
	vector<int>transpositionV1 = { 58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 
	38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8, 57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 
	11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7 };

	int permutationV[4][16] = { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
	{0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8 },
	{4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
	{15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 3} };

	//������ � ��������� ��� ������ ������������
	vector<int>transpositionV2 = { 40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 
		54, 22, 6, 39, 37, 5, 45, 13, 53, 21, 61, 29, 36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 1, 59, 
		27, 34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25 };
};

