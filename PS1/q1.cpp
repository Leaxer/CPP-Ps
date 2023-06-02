#include <iostream>

using namespace std;

int main()
{
   bool is_prime;
   for(int i = 3;i < 100;++i) {
      is_prime = true;
      for(int j = 2;j < i;++j) {
         if(i%j == 0) is_prime = false;
      }
      if(is_prime) {
         cout<<i<<endl;
      }
   }
   return 0;
}