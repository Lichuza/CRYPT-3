#include"RSA.h"
#include<windows.h>
#include "Hash.h"
#include "DES.h"
#include "gost.h"

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	//Help
	cout << "***********************************************************************************************************************"<<endl;
	cout << "В данной программе идет процесс шифрования, начиная от: DES -> GOST89 -> RSA,"<< endl<< "далее идет подсчет хэш-образа "<<
		"введеного сообщения, далее процесс создания ЭЦП и проверка ЭЦП."<<endl<<"1) DES - Нужно ввести сообщение для шифрования(в символьном формате - 6 буквы)"<<
		" и будет предложенно ввести ключ "<<
		"(в двоичной системе-48 символов)"<<endl<<"(если не вводить ключ - будет использован ключ по умолчанию)"<<endl<<
		"2) GOST89 - Нужно ввести сообщение для шифрования(в символьном формате - 6 буквы) и подключ(в символьном формате - 4 буквы)"<<endl<<
		"3) RSA - Требуется ввести сообщение для шифрования, а также числа 'p' и 'q' "<<endl<<
		"4) Для подсчета хэш-образа - необходимо ввести сообщение"<<endl<<
		"5) Для создания ЭЦП - необходимо ввести сообщение, также для проверки еще раз ввести сообщение"<<endl;
	cout << "***********************************************************************************************************************"<<endl<<endl;
	//Шифрование DES
	cout << "Введите сообщение для DES шифрования: ";
	string msgDES, keyDES= "001011101000100110000111011010110011011111100001";
	cin >> msgDES;

	cout << "Ввести ключ? 1-да, 2-нет: ";
	int l;
	cin >> l;
	if(l==1) cin >> keyDES;

	cout << "Сообщение: " << endl;
	DES des(msgDES,keyDES);
	cout << "Последовательность после первой перестановки: "<<endl;
	des.transposition1();
	cout << endl;
	cout << "Блоки: " << endl;
	des.split();
	cout << endl;
	cout << "Последовательность после расширения: " << endl;
	des.expansionR();
	cout << endl;
	cout << "Последовательность после XOR(ключ): " << endl;
	des.xorRe();
	cout << endl;
	cout << "Последовательность после подстановки: " << endl;
	des.permutation();
	cout << endl;
	cout << "Последовательность после XOR(L)" << endl;
	des.xorRL();
	cout << endl;
	cout << "Последовательность после соединения: " << endl;
	des.linkRL();
	cout << endl;
	cout << "Последовательность после финальной перестановки: " << endl;
	des.transposition2();
	cout << endl;

	//Шифрование GOST89

	string msgGOST, keyGOST;
	cout << "Введите сообщение для ГОСТ шифрование: ";
	cin >> msgGOST;
	cout << "Введите ключ для ГОСТ шифрование: ";
	cin >> keyGOST;
	gost GOST(msgGOST, keyGOST);
	GOST.Run();
	cout << endl;


	//Шифрование RSA
	string msg1;
	int p, q;
	cout<<"Введите сообщение для RSA шифрования: " << endl;
	cin >> msg1;
	cout << endl;

skip1:
	cout << "Введите p: " << endl;
	cin >> p;
	cout << endl;

    cout << "Введите q: " << endl;
	cin >> q;
	cout << endl;

	RSA rsa(msg1, p, q);
	if (rsa.createKey() == false)
	{
		cout << endl;
		goto skip1;
	}
	cout << "RSA: " << endl;
	cout << "Шифрование с помощь открытого ключа"<<endl;
	rsa.encryptRSA();
	cout << "Расшифровка с помощь закртыого ключа" << endl;
	rsa.decryptRSA();

	cout << endl;

	string msg2;
	cout << "Введите сообщение для подсчета хэш-образа: " << endl;
	cin >> msg2;
	cout << endl;

	Hash h(msg2, p, q);
	cout << "Хэш: " << endl;
	h.hash();
	
	cout << endl;

	cout << "Подпись RSA: " << endl;

	string msg3;
	cout << "Введите сообщение для подсчета подписи: " << endl;
	cin >> msg3;
	cout << endl;

	h.setMsg(msg3);
	h.hash();
	long int tempHash = h.getHash();
	cout << endl;

	cout << "Шифрования хэш-образа = ";
	long int tempHashEn=rsa.encryptSignRSA(tempHash);
	cout << tempHashEn << endl<<endl;

	cout << "Проверка подписи RSA: " << endl;

	cout << "Введите сообщение для проверки подписи: " << endl;
	cin >> msg3;
	cout << endl;

	cout << "Расшифровка хэш-образа подписи = ";
	long int tempHashDe = rsa.decryptSignRSA(tempHashEn);
	cout << tempHashDe << endl<<endl;

	h.setMsg(msg3);
	h.hash();
	long int tempHashMsg = h.getHash();
	cout << endl;

	cout << "Сравнение хэш-образов сообщения и подписи: " << endl;
	if(tempHashDe== tempHashMsg) cout << "Хэш-образы совпадают" << endl<<endl;
	else  cout << "Хэш-образы не совпадают" << endl<< endl;

	system("pause");
	return 0;
}