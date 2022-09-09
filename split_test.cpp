#include "split.h" 
#include <cstddef> 
#include <iostream> 

using namespace std; 

void print(Node* n); 

void print(Node* n) 
{
  cout << n->value << endl;
  if(n->next) print(n->next);
}

int main()
{ 
  Node* six = new Node (6, nullptr); 
  Node* five = new Node(5, six); 
  Node* four = new Node(4, five); 
  Node* three = new Node(3, four); 
  Node* two = new Node(2, three); 
  Node* one = new Node(1, two); 

  Node* odds = nullptr; 
  Node* evens = nullptr; 

  split(one, odds, evens); 

  print(odds);
  print(evens); 

  delete one; 
  delete two; 
  delete three; 
  delete four;
  delete five;
  delete six; 
  
}

