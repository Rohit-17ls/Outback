#include <iostream>
#include "../utils/LinkedListUtil.h"
#include "../utils/TemplatedLinkedList.h"
// #include "../utils/simplevectorutil.h"
#include <vector>
#define devlog(x) { std::cout << x << std::endl;}


int main(){

  // outback::Simplevectorutil<int> vecUtil(v);
  // vecUtil.setSeparator('|');
  // vecUtil.logVector({2,3});

  std::vector<int> v = {1,2,3,4,5};
  outback::LinkedListUtil l(v);


  l.push(6);
  l.push(7);
  l.push(8);

  devlog(l.size());

  outback::ListNode* head = l.head();
  outback::ListNode* tail = l.tail();


  devlog(head->val);
  devlog(tail->val);

  l.pop();

  l.print();









  return 0;
}
