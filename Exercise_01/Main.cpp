#include <iostream>
#include <vector>
#include <list>

using namespace std;


/*

int main(void)
{
	list<int> NumberList;

	for (int i = 0; i < 10; i++)
		NumberList.push_back(i);

	

	for (list<int>::iterator iter = NumberList.begin();iter!=NumberList.end(); ++iter)
		cout << (*iter) << endl;
	return 0;
}
*/

struct StudentScore
{
	char* Name;
	int Kor;
	int Eng;
	int Math;
};

int main(void)
{
	list<StudentScore*> StudentScoreList;

	/*************************************************************
	* [���]
	*
	* ȫ�浿
	* �������� : 1
	* �������� : 2
	* �������� : 3
	*
	* �Ӳ���
	* �������� : 10
	* �������� : 20
	* �������� : 30
	*
	* �̸���
	* �������� : 100
	* �������� : 200
	* �������� : 300
	* 
	**************************************************************/

	StudentScore tmp;
	StudentScore tmp2;
	StudentScore tmp3;
	
	for (int i = 0; i < 3; ++i) {
		switch (i)
		{
		case 0 :
			tmp.Name = "ȫ�浿";
			tmp.Kor = 1;
			tmp.Eng = 2;
			tmp.Math = 3;
			StudentScoreList.push_back(&tmp);
			break;
		case 1:
			tmp2.Name = "�Ӳ���";
			tmp2.Kor = 10;
			tmp2.Eng = 20;
			tmp2.Math = 30;
			StudentScoreList.push_back(&tmp2);
			break;
		case 2:
			tmp3.Name = "�̸���";
			tmp3.Kor = 100;
			tmp3.Eng = 200;
			tmp3.Math = 300;
			StudentScoreList.push_back(&tmp3);
			break;
		}
		
	}

	for (list<StudentScore*>::iterator iter = StudentScoreList.begin(); iter != StudentScoreList.end(); ++iter)
	{
		cout << "*" << endl;
		cout <<"*"<< (*iter)->Name << endl;
		cout <<"*"<<"��������: "<< (*iter)->Kor << endl;
		cout <<"*"<<"��������: "<< (*iter)->Eng << endl;
		cout <<"*"<<"��������: "<< (*iter)->Math << endl;
		cout << "*" << endl;
	}
}