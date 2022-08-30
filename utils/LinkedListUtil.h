#include <iostream>
#include <vector>
#define devlog(x) { std::cout << x << std::endl;}


namespace outback{

  struct ListNode{
          int val;
          struct ListNode* next;
  };


  class LinkedListUtil{
  private:
          ListNode* m_head = nullptr;
          ListNode* m_tail = nullptr;
          int m_size = 0;

          ListNode* createNode(const int& val){
                  ListNode* node = new ListNode();
                  node->val = val;
                  return node;
          }

          void linkedListOutOfVector(const std::vector<int>& vec, const int size){
                  m_size += size;
                  if(size==0) return;
                  m_head = createNode(vec[0]);
                  ListNode* ptr = m_head;

                  for(int i=1; i<size; i++){
                          ptr->next = createNode(vec[i]);
                          ptr = ptr->next;
                  }

                  m_tail = ptr;
                  ptr->next = nullptr;
          }


  public:
          LinkedListUtil(){
          }

          LinkedListUtil(const std::vector<int>& vec){
                  linkedListOutOfVector(vec, vec.size());
          }

          ListNode* head(){
                  return m_head;
          }

          ListNode* tail(){
                  return m_tail;
          }

          void push(const int x){
                  ListNode* temp = new ListNode();
                  temp->val = x;
                  temp->next = nullptr;
                  m_tail->next = temp;
                  m_tail = temp;
                  m_size++;
          }

          void pop(){
                  ListNode* ptr = m_head;
                  m_head = m_head->next;
                  m_size--;
                 delete ptr;
          }



          int size(){
            return m_size;
          }

          void print(){
            ListNode* temp = m_head;
            while(temp){
              std::cout << temp->val << " ";
              temp = temp->next;
            }
            std::cout << "\n";
          }


          ~LinkedListUtil(){
          }

  };
}


/*
  Utility to use quickly and effectively make a vector to perform Linked List like operations.
  Simplest way to spin up a linked list out of a std::vector<int>;

  Each node is an outback::ListNode with val and ListNode* next attributes

  The class provides 6 basic Methods
    i) push();
    ii) pop();
    iii) size():
    iv)  head();
    v) tail();
    vi) print();


*/
