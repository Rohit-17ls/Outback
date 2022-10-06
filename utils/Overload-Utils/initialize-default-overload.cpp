#include <iostream>
#include <climits>




// Overload
template <typename type>
void* operator new [](size_t size, type defaultValue){
  type* memoryBlock = (type*) malloc(size);
  int count = size/sizeof(type);
  
  while(count) memoryBlock[--count] = defaultValue;  // Calls copy constructor
  
  return (void*)(memoryBlock);
}

int main(){

    // Initializing an array with all INT_MAX;
    int* arr = new(INT_MAX) int[10];
    
   
    
    return 0;
 }
