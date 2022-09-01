#include <iostream>
#include <vector>

namespace outback{

  template<typename type>
  struct ListNode{
    type entity;
    ListNode<type>* next;
  };

  template<typename type>

  class linkedlist{


    private:
        ListNode<type>* m_head = nullptr;
        ListNode<type>* m_tail = nullptr;
        int m_size = 0;

        ListNode<type>* createNode(const type& entity){
                ListNode<type>* node = new ListNode<type>();
                node->entity = entity;
                return node;
        }

        void linkedListOutOfVector(const std::vector<type>& vec, const int size){
                m_size += size;
                if(size==0) return;
                m_head = createNode(vec[0]);
                ListNode<type>* ptr = m_head;

                for(int i=1; i<size; i++){
                        ptr->next = createNode(vec[i]);
                        ptr = ptr->next;
                }

                m_tail = ptr;
                ptr->next = nullptr;
        }


public:
        linkedlist(){
        }

        linkedlist(const std::vector<type>& vec){
                linkedListOutOfVector(vec, vec.size());
        }

        ListNode<type>* head(){
                return m_head;
        }

        ListNode<type>* tail(){
                return m_tail;
        }

        void push(const type x){
                ListNode<type>* temp = new ListNode<type>();
                temp->entity = x;
                temp->next = nullptr;
                m_tail->next = temp;
                m_tail = temp;
                m_size++;
        }

        void pop(){
                ListNode<type>* ptr = m_head;
                m_head = m_head->next;
                m_size--;
               delete ptr;
        }



        int size(){
          return m_size;
        }

        // print() method for primitive data types
        void print(){
          ListNode<type>* temp = m_head;
          while(temp){
            std::cout << temp->entity << " ";
            temp = temp->next;
          }
          std::cout << "\n";
        }

        // print() for non-primitive structs and objects
        void print(void(*func)(ListNode<type>*)){
          ListNode<type>* temp = m_head;
          while(temp){
            func(temp);
            std::cout << "\n";
            temp = temp->next;
          }
          std::cout << "\n";
        }


        ~linkedlist(){
        }

  };
}
