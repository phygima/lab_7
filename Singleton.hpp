//
//  Singleton.hpp
//  7
//
//  Created by Виктория Гладкова on 12.02.2023.
//

#ifndef Singleton_hpp
#define Singleton_hpp

#include <stdio.h>
using namespace std;

class Singleton
{
private:

  static Singleton* _instance;
  int value;

protected:
  Singleton()
  {
    value = 0;
  }

public:
  static Singleton* Instance()
  {
    if (_instance == nullptr)
    {
      
      _instance = new Singleton();
      return _instance;
    }
    else
    {
      return nullptr;
    }
  }

  int Get()
  {
    return value;
  }

  void Set(int _d)
  {
    value = _d;
  }
  void Print()
  {
    cout << "Value = " << value << endl;
  }
  ~Singleton()
  {
    delete _instance;
  }
};

Singleton* Singleton::_instance = nullptr;


#endif /* Singleton_hpp */
