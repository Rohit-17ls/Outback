#include <iostream>
#include <vector>
#include "../utils/TemplatedLinkedList.h"

struct City{
  int latitude;
  int longitude;
  std::string name;
};


int main(){


  std::vector<char> vc = {'a','b','c','d'};
  std::vector<int> vi = {1,2,3,4,5};
  std::vector<double> vd = {1.43, 2.23, 3.345, 4.23, 5.344};
  std::vector<std::string> vs = {"hello", "and", "welcome", "to another", "video"};
  // std::vector
  outback::linkedlist<char> charlinkedlist(vc);
  charlinkedlist.print();


  std::vector<City> vobj(5, {23, 102, "Phoenix"});
  outback::linkedlist<City> structlinkedlist(vobj);

  // Printing out a linked list of struct entities using a lambda function as argument

  structlinkedlist.print([](outback::ListNode<City>* ele){
    std::cout << ele->entity.latitude << '\n';
    std::cout << ele->entity.longitude << '\n';
    std::cout << ele->entity.name << '\n';
  });



  return 0;
}
