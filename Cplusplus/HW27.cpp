#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <vector>

int Compare_(const void* a, const void* b)
{
	return *(int*)b - *(int*)a;
}

enum Status {
	STRIKE,
	BALL,
	NOTHING
};

class Baseball
{
private:
	int number[4];
	int status[4];
	int strike;
	int ball;

public:
	Baseball()
	{
		status[0] = NOTHING;
		status[1] = NOTHING;
		status[2] = NOTHING;
		status[3] = NOTHING;
	}

	~Baseball()
	{

	}

	int GetNumber(int n)
	{
		return number[n];
	}
	int GetStrike()
	{
		return strike;
	}
	int GetBall()
	{
		return ball;
	}
	int GetStatus(int n)
	{
		return status[n];
	}
	void SetStatus(int strike_, int ball_)
	{
		strike = strike_;
		ball = ball_;
	}
	void SetStatusArr(int n, int status_)
	{
		status[n] = status_;
	}
	void SetNumber(int n, int number_)
	{
		number[n] = number_;
	}

	

};

Baseball InsertValue(std::ifstream& in);
void CheckStrikeBall(Baseball& b, Baseball& myScore);
Baseball ConvertNumber(int n);
void CountStB(Baseball& myScore);

int main()
{
	std::ifstream in;
	in.open("input.txt");
	int cases, n;
	in >> cases;
	int count = 0;

	int number[10001]; //끝자리 -1

	for (int k = 0; k < 10000; k++)
		number[k] = k;  //배열 초기화

	number[10000] = -1;  //끝구분

	for (int c = 0; c < cases; c++)
	{
		in >> n;
		
		for (int i = 0; i < n; i++)
		{
			Baseball b = InsertValue(in);
			Baseball myScore;

			//myScore = ConvertNumber(number[1234]);
			//CheckStrikeBall(b, myScore);
			//CountStB(myScore);
			//std::cout << b.GetStrike() << " " << b.GetBall() << std::endl;
			//std::cout << myScore.GetStrike() << " " << myScore.GetBall() << std::endl;
			//std::cout << myScore.GetStatus(0) << myScore.GetStatus(1) << myScore.GetStatus(2) << myScore.GetStatus(3) << std::endl;
			//
			////볼 스트라잌 판정까지 만듦


			count = 0;

			while (number[count] != -1)
			{
				myScore = ConvertNumber(number[count]);
				CheckStrikeBall(b, myScore);
			//	CountStB(myScore);
		
				if ((myScore.GetStrike() == b.GetStrike()) && (myScore.GetBall() == b.GetBall())) //스트라잌 볼 둘다 동일
				{
					count++;

				}
				else
				{
					number[count] = -1;
					count++;
				}
			}
		qsort(number, sizeof(number) / sizeof(number[0]), sizeof(number[0]), Compare_);

		}
		
		//for test
		for (int i = 0; i < 10000; i++)
		{
			if (number[0] == -1)
			{
				std::cout << "-2" << std::endl;
				break;
			}

			if (number[i] == -1)
				break;

			std::cout << number[i] << std::endl;

		}


		for (int k = 0; k < 10000; k++)
			number[k] = k;  //배열 초기화

		number[10000] = -1;  //끝구분
		count = 0;

	}

	//system("pause");
}

Baseball InsertValue(std::ifstream& in)
{
	Baseball b;
	int number;
	int strike;
	int ball;

	in >> number;
	in >> strike >> ball;
	//std::cout <<"\n"<< number << strike << ball << std::endl;

	b.SetStatus(strike, ball);


	if (number >= 1000)
	{
		b.SetNumber(0, number / 1000);
		number %= 1000;
		b.SetNumber(1, number / 100);
		number %= 100;
		b.SetNumber(2, number / 10);
		number %= 10;
		b.SetNumber(3, number / 1);
	}
	else if (number >= 100)
	{
		b.SetNumber(0, 0);
		b.SetNumber(1, number / 100);
		number %= 100;
		b.SetNumber(2, number / 10);
		number %= 10;
		b.SetNumber(3, number / 1);
	}
	else if(number >= 10)
	{
		b.SetNumber(0, 0);
		b.SetNumber(1, 0);
		b.SetNumber(2, number / 10);
		number %= 10;
		b.SetNumber(3, number / 1);
	}
	else
	{
		b.SetNumber(0, 0);
		b.SetNumber(1, 0);
		b.SetNumber(2, 0);
		b.SetNumber(3, number);
	}
	return b;
}

Baseball ConvertNumber(int n)
{
	Baseball b;
	int number = n;


	if (number >= 1000)
	{
		b.SetNumber(0, number / 1000);
		number %= 1000;
		b.SetNumber(1, number / 100);
		number %= 100;
		b.SetNumber(2, number / 10);
		number %= 10;
		b.SetNumber(3, number / 1);
	}
	else if (number >= 100)
	{
		b.SetNumber(0, 0);
		b.SetNumber(1, number / 100);
		number %= 100;
		b.SetNumber(2, number / 10);
		number %= 10;
		b.SetNumber(3, number / 1);
	}
	else if (number >= 10)
	{
		b.SetNumber(0, 0);
		b.SetNumber(1, 0);
		b.SetNumber(2, number / 10);
		number %= 10;
		b.SetNumber(3, number / 1);
	}
	else
	{
		b.SetNumber(0, 0);
		b.SetNumber(1, 0);
		b.SetNumber(2, 0);
		b.SetNumber(3, number);
	}
	return b;
}

void CheckStrikeBall(Baseball& b, Baseball& myScore)
{

	int strike = 0;
	int ball = 0;
	int temp1, temp2, temp3, temp4;
	int bTemp1, bTemp2, bTemp3, bTemp4;
	temp1 = myScore.GetNumber(0); temp2 = myScore.GetNumber(1); temp3 = myScore.GetNumber(2); temp4 = myScore.GetNumber(3);
	bTemp1 = b.GetNumber(0); bTemp2 = b.GetNumber(1); bTemp3 = b.GetNumber(2); bTemp4 = b.GetNumber(3);


	for (int i = 0; i < 4; i++)
	{
		if (myScore.GetNumber(i) == b.GetNumber(i))
		{
			myScore.SetStatusArr(i, STRIKE);
			myScore.SetNumber(i, -1);
			b.SetNumber(i, -1);   //스트라잌 해당하는 모든 부분을 -1로
			strike++;
		}
	}

	std::map<int, int> myBaseball;
	std::map<int, int> bBaseball;
	std::map<int, int>::iterator iter;
	std::map<int, int>::iterator iter2;

	for (int j = 0; j < 4; j++)
	{
		iter = myBaseball.find(myScore.GetNumber(j));
		if (iter != myBaseball.end())  //있는경우
		{
			myBaseball[iter->first] += 1;  //하나더해주기
		}
		else
		{
			myBaseball.insert(std::pair<int,int>(myScore.GetNumber(j),1));  //1로 새로만들기
		}
	}

	for (int j = 0; j < 4; j++)
	{
		iter = bBaseball.find(b.GetNumber(j));
		if (iter != bBaseball.end())  //있는경우
		{
			bBaseball[iter->first] += 1;  //하나더해주기
		}
		else
		{
			bBaseball.insert(std::pair<int, int>(b.GetNumber(j), 1));  //1로 새로만들기
		}
	}


	for (iter = myBaseball.begin(); iter != myBaseball.end(); iter++)
	{
		for (iter2 = bBaseball.begin(); iter2 != bBaseball.end(); iter2++)
		{
			if ((iter->first == iter2->first) && iter->second >= 1 && iter2->second >= 1)
			{
				while ((iter->second > 0) && (iter2->second > 0) && (iter->first != -1))
				{
					iter->second -= 1;
					iter2->second -= 1;
					ball++;
				}
			}
		}
	}




	myScore.SetNumber(0, temp1); myScore.SetNumber(1, temp2); myScore.SetNumber(2, temp3); myScore.SetNumber(3, temp4);
	b.SetNumber(0, bTemp1); b.SetNumber(1, bTemp2); b.SetNumber(2, bTemp3); b.SetNumber(3, bTemp4);
	myScore.SetStatus(strike, ball);


/*
	for (int j = 0; j < 4; j++)
	{
		if (myScore.GetStatus(j) == STRIKE) //이미 스트라잌 판정
			continue;
		else if (myScore.GetStatus(j) == NOTHING) //아직 아무판정도 안남 
		{
			for (int k = 0; k < 4; k++)
			{
				//같은 숫자가 한 j에 두개 나오면 안되니까, 여기다가 멤버배열인 noExist를 만들면 될 것 같다. 
				std::set<int> noExist;

				if (myScore.GetStatus(k) == STRIKE)  // myScore의 스트라잌 == b의 스트라잌
					continue;
				else if (myScore.GetNumber(j) == b.GetNumber(k))
				{
					std::set<int>::iterator p;
					p = noExist.find(k);
					
					if (p == noExist.end())
					{
						myScore.SetStatusArr(j, BALL);       //스트라잌은 아니지만 같은 숫자가 있을 때는 볼  투볼감지!
						noExist.insert(k);
					}
				}

			}




		}
	}
	*/
}

void CountStB(Baseball& myScore)
{
	int ball = 0;
	int strike = 0;

	for (int i = 0; i < 4; i++)
	{
		if (myScore.GetStatus(i) == STRIKE)
			strike++;
		else if (myScore.GetStatus(i) == BALL)
			ball++;
	}

	myScore.SetStatus(strike, ball);
}