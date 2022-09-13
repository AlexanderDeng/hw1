/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
using namespace std;


int main(int argc, char* argv[])
{
  cout << "Hello grader. These are my test cases. To find out more about what each aims to test, look at the comments" << endl; 
  cout <<"in the code. Thanks for your hard work! :)" << endl; 
  cout << endl; 
  cout << "output | expected" << endl; 
  ULListStr test;

  test.push_back("1"); //tests base case 
  test.push_front("2"); //tests new node at the front and push front on empty
  cout << test.get(0) << " " << test.get(1) << " | 2 1" << endl; 

  test.pop_back(); //tests pop back and node deletion
  test.push_back("3"); //tests new node at the back
  cout << test.get(0) << " " << test.get(1) << " | 2 3" << endl; 
  
  test.pop_front(); //tests pop front and node deletion
  test.push_front("2");
  test.push_front("1");
  test.push_back("4");
  cout << test.get(0) << " " << test.get(1) << " " << test.get(2) << " " << test.get(3) << " | 1 2 3 4" << endl;
  //tests getValAtLoc too with all these calls of get

  test.push_back("5"); //tests if new node spawns once prev is filled
  test.push_back("6");
  test.push_back("7");
  test.push_back("8");
  test.push_back("9");
  test.push_back("10");
  test.push_back("11");
  test.push_back("12");
  test.push_back("13");
  for (int i = 0; i < 13; i++)
  {
    cout << test.get(i) << " "; 
  }
  cout << " | 1 2 3 4 5 6 7 8 9 10 11 12 13" << endl; 

  cout << test.size() << " | 13" << endl;  //tests size function
  cout << test.front() << " " << test.back() << " | 1 13 " << endl; //tests front and back
  test.clear();
  //test.get(1); commented out because it should return an error message! 


  return 0;
}
