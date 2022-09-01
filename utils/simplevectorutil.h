#include <iostream>
#include <vector>

namespace outback{
  template <typename type>
  class Simplevectorutil{
  private:
    std::vector<type> m_vec;
    char m_separatorChar = ',';
  public:




    Simplevectorutil(const std::vector<type>& vec){
      m_vec = vec;
    }

     void setSeparator(char separator){
       m_separatorChar = separator;
     }

    void logVector(){
      int i = 0;
      for(i = 0; i < m_vec.size()-1; i++){
        std::cout << m_vec[i] << " " << m_separatorChar << " ";
      }
      std::cout << m_vec[i] << std::endl;
    }

    // Add special indices vector as a default argument to this method
    void logVector(char separator, const std::vector<int>& specialIndices = {}){
      setSeparator(separator);

      if(specialIndices.size()){
        std::unordered_map<int, int> hashmap;
        for(int ind : specialIndices) hashmap[ind] = 1;

        int i = 0;
        for(i = 0; i<m_vec.size()-1; i++){
          if(hashmap[i]) std::cout << "[" << m_vec[i] << "] " << m_separatorChar << " ";
          else std::cout << m_vec[i] << " " << m_separatorChar << " ";
        }

        if(hashmap[i]) std::cout << " [" << m_vec[i] << "]" << std::endl;
        else std::cout << m_vec[i] << std::endl;

      }else{
        int i = 0;
        for(i = 0; i < m_vec.size()-1; i++){
          std::cout << m_vec[i] << " " << m_separatorChar << " ";
        }
        std::cout << m_vec[i] << std::endl;
      }
    }



    void logVector(const std::vector<int>& specialIndices){
      logVector(m_separatorChar, specialIndices);
    }

    ~Simplevectorutil(){}


  };
}


/*
  Methods:
    i) logVector()
        - Logs the array out to the console in a single line separated by a character
        - Two Optional arguments , a separation character and a special indices vector
        - Default separation character is comma ','
        - Special Indices vector takes in a bunch of indices which will be printed with a [] around them

    ii) setSeparator()
        - Another way to set the separation character (using a method)

*/
