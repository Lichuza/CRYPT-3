#include "Hash.h"

void Hash::hash()
{
	H = 1;
	for (int i = 0; i < s.length(); i++) 
	{
		unsigned char ch = s[i];
		long int temp = H + ch;
		H = (temp*temp) % n;
		if(i+1<s.length()) cout << "Промежуточное вычисление хэша номер " << i+1 << " = " << H<<endl;
	}
	cout <<"Хэш-образ сообщения = "<<H;
	cout << endl;
}
