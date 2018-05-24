#include <iostream>
#include <fstream>


int main()
{
   std::ifstream in;
   in.open("input.txt");

   int cases, number;
   int num;
   
   int result = 1;
   in >> cases;
   
   for (int i = 0; i < cases; ++i)
   {
      in >> number;
      for (int j = 0; j < number; ++j)
      {
         
         in >> num;
         result = (result*(num%10))%10; 
      }
          
            std::cout << result << std::endl;
          result = 1; 
   }
   return 0;
}