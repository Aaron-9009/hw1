#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;
//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr testList;
  for(int i=48;i<58;i++){
    string test ="";
    test = static_cast<char>(i);
    cout << test << endl;
    testList.push_front(test);

  }
  string loc_1 = testList.get(9);
  cout << "Empty: " << testList.empty() << endl;
  cout << "Size: " << testList.size() << endl;
  cout << "Loc #1: " <<  loc_1 << endl;
  testList.push_back("1");
  cout << "push_back Loc #10: " << testList.get(10) << endl;
  testList.pop_back();
  cout << "pop_back Loc#9: " << testList.get(9) << endl;
  testList.pop_front();
  cout << "pop_front Loc #0: " << testList.get(0) << endl;
  return 0;  
}
