#include "RSA.h"

bool RSA::createKey()
{
	//�������� �� �� ��� ����� p, q - �������
	for (int i = 2; i < sqrt(p); i++)
	{
		if (p%i == 0)
		{
			cout << "p - �� ������� �����" << endl;
			return false;
		}
	}

	for (int i = 2; i < sqrt(q); i++)
	{
		if (q%i == 0)
		{
			cout << "q - �� ������� �����" << endl;
			return false;
		}
	}

	n = p * q;

	//�������� �� �� ��� n - ������ 255
	if (n < 255)
	{
		cout << "n - ������ 255"<<endl;
		return false;
	}

	f = ((p - 1)*(q - 1));

	//����� ����� e
	for (e = 3; e < f; e++)
	{
		if (f%e != 0) break;

	}

	//����� ����� d
	for (int k = 1; k < f; k++)
	{
		d = (1 + (k*f)) / e;

		if ((d*e) % f == 1)	break;
	}

	//����� �����
	cout << "p = " << p << endl;
	cout << "q = " << q << endl;
	cout << "n = " << n << endl;
	cout << "f = " << f << endl;
	cout << "e = " << e << endl;
	cout << "d = " << d << endl<<endl;

	return true;
}

void RSA::encryptRSA()
{
	//���������� RSA
	for (int i = 0; i < s.length(); i++)
	{
		unsigned char ch = s[i];
		int mod = ch % n;
		int temp = 1;
		for (int i = 1; i <= e; i++) 
		{
			temp = (temp*mod) % n;
		}
		encrypt.push_back(temp);
		cout <<ch<<": "<<(int)ch <<"^"<<e<< " mod " << n << " = " << encrypt[i] << endl;
	}
	cout << endl;
}
void RSA::decryptRSA()
{
	//����������� RSA
	for (int i = 0; i < encrypt.size(); i++)
	{
		int mod = encrypt[i] % n, temp = 1;;
		for (int i = 1; i <= d; i++)
		{
			temp = (temp*mod) % n;		
		}
		decrypt.push_back(temp);
		cout << encrypt[i] << "^" << d << " mod " << n << " = " << decrypt[i] << endl;
	}
	cout << endl;
}

long int RSA::encryptSignRSA(const long int h)
{
	//���������� ��� �������� �������
	long int mod = h % n, temp = 1;
	for (int i = 1; i <= d; i++)
	{
		temp = (temp*mod) % n;
	}
	long int hashEncrypt = temp;
	return hashEncrypt;
}

long int RSA::decryptSignRSA(const long int h)
{
	//����������� ����
	long int mod = h % n, temp = 1;
	for (int i = 1; i <= e; i++)
	{
		temp = (temp*mod) % n;
	}
	long int hashDecrypt = temp;
	return hashDecrypt;
}


