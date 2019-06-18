#include "gost.h"
    //Перевод в двоичную систему счисления
	void gost::dvoich(unsigned char ch)
	{
		int a;
		int b = ch;
		for (int i = 7; i >= 0; i--)
		{
			kodb[i] = b % 2;
			b = (b / 2);
		}
	}

	//Вывод на экран двоичного кода
	void gost::display(int mas[], int a, int b)
	{
		int asd = 0;
		for (int i = a; i < b; i++)
		{

			if (asd != 4)
			{
				cout << mas[i];
				asd++;
			}
			else
			{
				cout << ".";
				asd = 0;
				i--;
			}
		}
		asd = 0;
		cout << endl;
	}

	//Вывод массива чисел строки для перестановки
	void gost::display2(int mas[])
	{
		for (int i = 0; i < 8; i++)
		{
			cout << mas[i] << " | ";
		}
		cout << endl;
	}
	//Перевод в 10 систему счисления
	void gost::inDec(int mas1[], int mas2[])
	{
		int p = 0;
		for (int i = 0; i < 32; i = i + 4)
		{
			mas1[p] = mas2[i] * pow(2, 3) + mas2[i + 1] * pow(2, 2) + mas2[i + 2] * pow(2, 1) + mas2[i + 3] * pow(2, 0);
			p++;
		}
	}
	//Сложение по модулю 2 в степени 32
	void gost::mod232(int mas1[], int mas2[], int mas3[], int j)
	{
		int r = 0;
		for (int i = 31; i >= 0; i--)
		{
			if (mas1[j] == 1 && mas2[i] == 0 && r == 0)
			{
				mas3[i] = 1;
				r = 0;
			}
			else if (mas1[j] == 0 && mas2[i] == 1 && r == 0)
			{
				mas3[i] = 1;
				r = 0;
			}
			else if (mas1[j] == 1 && mas2[i] == 1 && r == 0)
			{
				mas3[i] = 0;
				r = 1;
			}
			else if (mas1[j] == 1 && mas2[i] == 0 && r == 1)
			{
				mas3[i] = 0;
				r = 1;
			}
			else if (mas1[j] == 0 && mas2[i] == 1 && r == 1)
			{
				mas3[i] = 0;
				r = 1;
			}
			else if (mas1[j] == 1 && mas2[i] == 1 && r == 1)
			{
				mas3[i] = 1;
				r = 1;
			}
			else if (mas1[j] == 0 && mas2[i] == 0 && r == 1)
			{
				mas3[i] = 1;
				r = 0;
			}
			else if (mas1[j] == 0 && mas2[i] == 0 && r == 0)
			{
				mas3[i] = 0;
				r = 0;
			}
			j--;
		}
	}
	//Сложение по модулю 2
void gost::mod2(int mas1[], int mas2[], int mas3[])
{
		for (int i = 0; i < 32; i++)
		{
			mas3[i] = mas1[i] ^ mas2[i];

		}
}
//Присваиваем массиву значения двоичного кода букв
	void gost::pris(int mas1[], int mas2[], int j)
	{
		for (int i = 0; i < 8; i++)
		{
			mas1[jj] = mas2[i];
			jj++;
		}
	}
	//Выводим двоичный код букв
	void gost::display3(int mas[])
	{
		for (int i = 0; i < 8; i++)
		{
			cout << mas[i];
		}
	}
	
	//Присваиваем массиву значения двоичного кода букв
	void gost::pris2(int mas1[], int mas2[])
	{

		for (int i = 0; i < 8; i++)
		{
			mas1[z] = mas2[i];
			z++;
		}
	}

	//Выполнение шифрования
	void gost::Run()
	{
		
		int prov1 = 0;
		int prov2 = 0;
		int asd = 0;
	
		unsigned char ch;
		for (int i = 0; i < msg1.length(); i++)
		{
			ch = msg1[i];
			cout << "Символ " << msg1[i] << " = " << (int)ch;
			dvoich(ch);
			if (jj < 32 && ch != '_')
			{
				pris(L, kodb, jj);
			}
			else if (jj >= 32 && ch != '_')
			{
				pris(R, kodb, jj);
			}
			else if (jj >= 32 && ch == '_')
			{
				pris(R, kodprob, jj);
			}
			cout << " двоичный код: ";
			if (ch == '_')
			{
				display3(kodprob);
			}
			else
			{
				display3(kodb);
			}
			cout << endl;
		}
	

		for (int i = 0; i < msg2.length(); i++)
		{
			ch = msg2[i];
			cout << "Символ " << msg2[i] << " = " << (int)ch;
			dvoich(ch);
			pris2(X, kodb);
			cout << " двоичный код: ";
			display3(kodb);
			cout << endl;
		}
		cout << endl;
		//Вывод L
		cout << "Блок L= ";
		display(L, 0, 32);
		//Вывод R
		cout << "Блок R=   ";
		display(R, 32, 64);
		//Вывод X
		cout << "Блок X=   ";
		display(X, 0, 32);
		//сумма R+X
		int j = 63;
		mod232(R, X, sumRX, j);
		cout << "Блок R+X= ";
		display(sumRX, 0, 32);
		const int stroki = 16;
		const int stolb = 8;
		int podstanovka[stroki][stolb] = {
			{ 4, 14, 5, 7, 6, 4, 13, 1 }, //0
			{ 10, 11, 8, 13, 12, 11, 11, 15 }, //1
			{ 9, 4, 1, 10, 7, 10, 4, 13 }, //2
			{ 2, 12, 13, 1, 1, 0, 1, 0 }, //3
			{ 13, 6, 10, 0, 5, 7, 3, 5 }, //4
			{ 8, 13, 3, 8, 15, 2, 15, 7 }, //5
			{ 0, 15, 4, 9, 13, 1, 5, 10 }, //6
			{ 14, 10, 2, 15, 8, 13, 9, 4 }, //7
			{ 6, 2, 14, 14, 4, 3, 0, 9 }, //8
			{ 11, 3, 15, 4, 10, 6, 10, 2 }, //9
			{ 1, 8, 12, 6, 9, 8, 14, 3 }, //10
			{ 12, 1, 7, 12, 14, 5, 7, 14 }, //11
			{ 7, 0, 6, 11, 0, 9, 6, 6 }, //12
			{ 15, 7, 0, 2, 3, 12, 8, 11 }, //13
			{ 5, 5, 9, 5, 11, 15, 2, 8 }, //14
			{ 3, 9, 11, 3, 2, 14, 12, 12 } //15
		};
		int strok[8];
		inDec(strok, sumRX);
		cout << endl;
		cout << "Массив для получение строк подстановки: " << endl;
		display2(strok);
		int  peres10[8] = { podstanovka[strok[0]][7], podstanovka[strok[1]][6], podstanovka[strok[2]][5],
			podstanovka[strok[3]][4], podstanovka[strok[4]][3], podstanovka[strok[5]][2], 
			podstanovka[strok[6]][1], podstanovka[strok[7]][0] };
		cout << "Перестановка в 10: " << endl;
		display2(peres10);
		z = 0;
		for (int i = 0; i < 8; i++)
		{
			ch = peres10[i];
			dvoich(ch);
			pris2(peres2, kodb);
		}
		cout << "После перестановки= ";
		for (int i = 4; i < 64; i++)
		{

			if (asd != 4)
			{
				cout << peres2[i];
				asd++;
			}
			else
			{
				cout << ".";
				asd = 0;
				i += 3;
			}
		}
		asd = 0;
		cout << endl;
		int sdvig[32] = { peres2[23], peres2[28], peres2[29], peres2[30],  peres2[31],
			peres2[36], peres2[37], peres2[38],  peres2[39], peres2[44], peres2[45], peres2[46], peres2[47], 
			peres2[52], peres2[53], peres2[54], peres2[55], peres2[60], peres2[61], peres2[62], peres2[63], peres2[4], 
			peres2[5], peres2[6], peres2[7], peres2[12], peres2[13],  peres2[14], peres2[15], peres2[20], peres2[21], peres2[22] };
		cout << "Блок L=                          ";
		display(L, 0, 32);
		cout << "После сдвига на 11 бит=          ";
		display(sdvig, 0, 32);
		//Сумма по мод 2
		mod2(L, sdvig, R1);
		cout << "Блок R1 = L + блок после сдвига: ";
		display(R1, 0, 32);
	}



