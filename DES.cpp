#include "DES.h"

DES::DES(const string msg, const string key)
{
	//Вызов метода преобразования в 2-ый код
	transformationBit(msg, bitOrderMsg);
	
	//Добавление ключа в вектор и его вывод
	cout << "Ключ: " << endl;
	for (int i = 0; i < key.length(); i++) 
	{
		bitOrderKey.push_back(key[i]);
		cout << bitOrderKey[i];
		if ((i+1) % 4 == 0) cout << ".";
	}
	cout << endl << endl;
}

//Преобразование в двоичный код
void DES::transformationBit(const string m, string &bitOrder)
{
	vector<string>temp;
	for (int i = 0; i < m.length(); i++)
	{
		//Символ '_' - для пробела(двоичный код из методички)
		if (m[i] == '_')
		{
			temp.push_back("00010000");
			cout << temp[i] << endl;
			continue;
		}
		char binCode[64];
		unsigned char tempCh = m[i];
		_itoa_s(tempCh, binCode, 2);
		temp.push_back(binCode);
		cout << temp[i] << endl;
	}

	for (int i = 0; i < temp.size(); i++)
	{
		bitOrder += temp[i];
	}
	cout << endl;
}

//Перестановка
void DES::transposition1()
{
	for (int i = 0; i < bitOrderMsg.size(); i++)
	{
		int k = transpositionV1[i];
		bitOrderTransposition.push_back(bitOrderMsg[k-1]);
		cout << bitOrderTransposition[i];
		if ((i + 1) % 4 == 0) cout << ".";
	}	
	cout << endl;
}

//Разбиение на подблоки
void DES::split()
{
	for (int i = 0; i < bitOrderTransposition.size()/2; i++) 
	{
		L.push_back(bitOrderTransposition[i]);
		R.push_back(bitOrderTransposition[i + (bitOrderTransposition.size() / 2)]);
	}

	cout << "L: ";
	for (int i = 0; i < L.size(); i++)
	{
		cout << L[i];
		if ((i + 1) % 4 == 0) cout << ".";
	}

	cout << endl<<"R: ";

	for (int i = 0; i < R.size(); i++)
	{
		cout << R[i];
		if ((i + 1) % 4 == 0) cout << ".";
	}
	cout << endl;
}

//Расширение блока R
void DES::expansionR()
{
	//Для превого блока
	Re.push_back(R.back());
	for (int i = 0; i < 5; i++)
	{
		Re.push_back(R[i]);
	}

	int l = 0;
	for (int g = 0; g < (R.size() / 4) - 2 ; g++) 
	{
		for (int i = 3 + l; i < 9 + l; i++)
		{
			Re.push_back(R[i]);
		}
		l += 4;
	}

	//Для последнего блока
	for (int i = 3 + l; i < R.size(); i++)
	{
		Re.push_back(R[i]);
	}
	Re.push_back(R.front());

	//Вывод
	int k = 0;
	for (int i = 0; i < Re.size(); i++)
	{
		cout << Re[i];
		if ((i + 1) % 6 == 0) cout << ".";
	}
	cout << endl;
}

//Сложение по модулю 2
void DES::xorRe()
{
	for(int i=0;i<Re.size();i++)
	{
		RXor.push_back(Re[i] ^ bitOrderKey[i]);
		cout<<RXor[i];
		if ((i + 1) % 6 == 0) cout << ".";
	}
	cout << endl;
}

//Подстановка
void  DES::permutation() 
{
	//Подстановка
	for (int i = 0; i < RXor.size(); i++) 
	{
		int g = RXor[i]*pow(2,1) + RXor[i+5] * pow(2, 0);
		int k = RXor[i+1] * pow(2, 3) + RXor[i + 2] * pow(2, 2)+RXor[i + 3] * pow(2, 1) + RXor[i + 4] * pow(2, 0);
		i += 5;
		permutationV10.push_back(permutationV[g][k]);
	}

	//Вывод
	for (int i = 0; i < permutationV10.size(); i++) 
	{
		cout << permutationV10[i]<<" ";
	}
	cout << endl;

	//Преобразование в 2-ый вид
	vector<string>temp;
	for (int i = 0; i < permutationV10.size(); i++)
	{
		int tempCh = permutationV10[i];
		char binCode[16];
		_itoa_s(tempCh, binCode, 2);
		temp.push_back(binCode);
	}
	
	//Дополнение "0"
	string temp1;
      for (int i = 0; i < temp.size(); i++)
      {
		  if (temp[i].size() < 4) 
		  {
			  int t = 4 - temp[i].size();

			  for (int i = 0; i < t; i++)
			  {
				  temp1 += "0";
			  }
			  temp1+=temp[i];
		  }
		  else temp1+=temp[i];
      }
   

	  //Вывод
	  for (int i = 0; i < temp1.size(); i++)
	  {
		  char ch = temp1[i];
		  bitOrderPermutation.push_back(ch);
		  cout<<bitOrderPermutation[i];
		  if ((i + 1) % 4 == 0) cout << ".";
	  }
	  cout << endl;
}

//Сложение по модулю 2
void DES::xorRL()
{
	for (int i = 0; i < bitOrderPermutation.size(); i++)
	{
		newR.push_back(bitOrderPermutation[i] ^ L[i]);
		cout << newR[i];
		if ((i + 1) % 4 == 0) cout << ".";
	}
	cout << endl;
}

//Соединение блоков
void DES::linkRL()
{
	for (int i = 0; i < R.size(); i++)
	{
		newLR.push_back(R[i]-48);
	}

	//Вывод
	for (int i = 0; i < newR.size(); i++)
	{
		newLR.push_back(newR[i]);
	}

	for (int i = 0; i < newLR.size(); i++)
	{
		cout << newLR[i];
		if ((i + 1) % 4 == 0) cout << ".";
	}
	cout << endl;
}

//Вторая перестановка
void DES::transposition2()
{
	for (int i = 0; i < newLR.size(); i++)
	{
		int k = transpositionV2[i];
		finalLR.push_back(newLR[k - 1]);
		cout << finalLR[i];
		if ((i + 1) % 4 == 0) cout << ".";
	}
	cout << endl;
}