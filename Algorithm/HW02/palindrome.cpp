#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int huimoon(int num, int jinsoo);

int main(void)
{
   ifstream inStream;
   int T = 0;         // 테스트 데이터 갯수
   int n = 0;         // 임의의 정수 T
   int temp = 0;

   inStream.open("input.txt");
   
      inStream >> T;

      for (int j = 0; j < T; j++)
      {
         inStream >> n;

         // 2진법부터 64진법까지 검증. 중간에 회문인이라고 판단되면 시간 단축을 위해 중단
         for (int k = 2; k <= 64; k++)
         {
            temp = huimoon(n, k);
            if (temp == 1)
               break;
         }

         cout << temp << endl;
         temp = 0;
      }

   inStream.close();
   return 0;
}

int huimoon(int num, int jinsoo)
{
   int temp = 0;
   int arr[100];

   // 10진수 -> jinsoo진수 변환
   while (num >= jinsoo)
   {
      arr[temp] = num % jinsoo;
      num = num / jinsoo;
      temp++;
   }
   arr[temp] = num;

   // 회문인 검증
   for (int i = 0; i <= temp/2; i++)
   {
      if (arr[i] != arr[temp - i])
         return 0;
   }

   return 1;
}
