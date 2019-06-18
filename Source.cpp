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
	cout << "� ������ ��������� ���� ������� ����������, ������� ��: DES -> GOST89 -> RSA,"<< endl<< "����� ���� ������� ���-������ "<<
		"��������� ���������, ����� ������� �������� ��� � �������� ���."<<endl<<"1) DES - ����� ������ ��������� ��� ����������(� ���������� ������� - 6 �����)"<<
		" � ����� ����������� ������ ���� "<<
		"(� �������� �������-48 ��������)"<<endl<<"(���� �� ������� ���� - ����� ����������� ���� �� ���������)"<<endl<<
		"2) GOST89 - ����� ������ ��������� ��� ����������(� ���������� ������� - 6 �����) � �������(� ���������� ������� - 4 �����)"<<endl<<
		"3) RSA - ��������� ������ ��������� ��� ����������, � ����� ����� 'p' � 'q' "<<endl<<
		"4) ��� �������� ���-������ - ���������� ������ ���������"<<endl<<
		"5) ��� �������� ��� - ���������� ������ ���������, ����� ��� �������� ��� ��� ������ ���������"<<endl;
	cout << "***********************************************************************************************************************"<<endl<<endl;
	//���������� DES
	cout << "������� ��������� ��� DES ����������: ";
	string msgDES, keyDES= "001011101000100110000111011010110011011111100001";
	cin >> msgDES;

	cout << "������ ����? 1-��, 2-���: ";
	int l;
	cin >> l;
	if(l==1) cin >> keyDES;

	cout << "���������: " << endl;
	DES des(msgDES,keyDES);
	cout << "������������������ ����� ������ ������������: "<<endl;
	des.transposition1();
	cout << endl;
	cout << "�����: " << endl;
	des.split();
	cout << endl;
	cout << "������������������ ����� ����������: " << endl;
	des.expansionR();
	cout << endl;
	cout << "������������������ ����� XOR(����): " << endl;
	des.xorRe();
	cout << endl;
	cout << "������������������ ����� �����������: " << endl;
	des.permutation();
	cout << endl;
	cout << "������������������ ����� XOR(L)" << endl;
	des.xorRL();
	cout << endl;
	cout << "������������������ ����� ����������: " << endl;
	des.linkRL();
	cout << endl;
	cout << "������������������ ����� ��������� ������������: " << endl;
	des.transposition2();
	cout << endl;

	//���������� GOST89

	string msgGOST, keyGOST;
	cout << "������� ��������� ��� ���� ����������: ";
	cin >> msgGOST;
	cout << "������� ���� ��� ���� ����������: ";
	cin >> keyGOST;
	gost GOST(msgGOST, keyGOST);
	GOST.Run();
	cout << endl;


	//���������� RSA
	string msg1;
	int p, q;
	cout<<"������� ��������� ��� RSA ����������: " << endl;
	cin >> msg1;
	cout << endl;

skip1:
	cout << "������� p: " << endl;
	cin >> p;
	cout << endl;

    cout << "������� q: " << endl;
	cin >> q;
	cout << endl;

	RSA rsa(msg1, p, q);
	if (rsa.createKey() == false)
	{
		cout << endl;
		goto skip1;
	}
	cout << "RSA: " << endl;
	cout << "���������� � ������ ��������� �����"<<endl;
	rsa.encryptRSA();
	cout << "����������� � ������ ��������� �����" << endl;
	rsa.decryptRSA();

	cout << endl;

	string msg2;
	cout << "������� ��������� ��� �������� ���-������: " << endl;
	cin >> msg2;
	cout << endl;

	Hash h(msg2, p, q);
	cout << "���: " << endl;
	h.hash();
	
	cout << endl;

	cout << "������� RSA: " << endl;

	string msg3;
	cout << "������� ��������� ��� �������� �������: " << endl;
	cin >> msg3;
	cout << endl;

	h.setMsg(msg3);
	h.hash();
	long int tempHash = h.getHash();
	cout << endl;

	cout << "���������� ���-������ = ";
	long int tempHashEn=rsa.encryptSignRSA(tempHash);
	cout << tempHashEn << endl<<endl;

	cout << "�������� ������� RSA: " << endl;

	cout << "������� ��������� ��� �������� �������: " << endl;
	cin >> msg3;
	cout << endl;

	cout << "����������� ���-������ ������� = ";
	long int tempHashDe = rsa.decryptSignRSA(tempHashEn);
	cout << tempHashDe << endl<<endl;

	h.setMsg(msg3);
	h.hash();
	long int tempHashMsg = h.getHash();
	cout << endl;

	cout << "��������� ���-������� ��������� � �������: " << endl;
	if(tempHashDe== tempHashMsg) cout << "���-������ ���������" << endl<<endl;
	else  cout << "���-������ �� ���������" << endl<< endl;

	system("pause");
	return 0;
}