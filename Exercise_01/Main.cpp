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
	* [출력]
	*
	* 홍길동
	* 국어점수 : 1
	* 영어점수 : 2
	* 수학점수 : 3
	*
	* 임꺽정
	* 국어점수 : 10
	* 영어점수 : 20
	* 수학점수 : 30
	*
	* 이몽룡
	* 국어점수 : 100
	* 영어점수 : 200
	* 수학점수 : 300
	* 
	**************************************************************/

	StudentScore tmp;
	StudentScore tmp2;
	StudentScore tmp3;
	
	for (int i = 0; i < 3; ++i) {
		switch (i)
		{
		case 0 :
			tmp.Name = "홍길동";
			tmp.Kor = 1;
			tmp.Eng = 2;
			tmp.Math = 3;
			StudentScoreList.push_back(&tmp);
			break;
		case 1:
			tmp2.Name = "임꺽정";
			tmp2.Kor = 10;
			tmp2.Eng = 20;
			tmp2.Math = 30;
			StudentScoreList.push_back(&tmp2);
			break;
		case 2:
			tmp3.Name = "이몽룡";
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
		cout <<"*"<<"국어점수: "<< (*iter)->Kor << endl;
		cout <<"*"<<"영어점수: "<< (*iter)->Eng << endl;
		cout <<"*"<<"수학점수: "<< (*iter)->Math << endl;
		cout << "*" << endl;
	}
}