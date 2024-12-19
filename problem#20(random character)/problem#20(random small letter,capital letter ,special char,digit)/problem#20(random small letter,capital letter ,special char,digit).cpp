
#include <iostream>
#include<cstdlib>
using namespace std;

enum enCharType
{
SmallLetter=1,CapitalLetter,SpecialChar,Digit
};


int RandomNumber(int From, int To) {
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

char GetRandomCharacter(enCharType CharType) {
    switch (CharType) {
    case SmallLetter:
      return  char(RandomNumber(97, 122));
    case CapitalLetter:
      return  char(RandomNumber(65, 90));
    case SpecialChar:
        return char(RandomNumber(33, 47));
    default:
        return char(RandomNumber(48, 57));
   }

}
int main()
{
    srand((unsigned)time(NULL));
    cout<<GetRandomCharacter(SmallLetter)<<endl;
    
    cout<<GetRandomCharacter(CapitalLetter)<<endl;
   
    cout<<GetRandomCharacter(SpecialChar)<<endl;
   
   cout<< GetRandomCharacter(Digit)<<endl;
}


