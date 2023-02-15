//
//  Adapter.hpp
//  7
//
//  Created by Виктория Гладкова on 12.02.2023.
//

#ifndef Adapter_hpp
#define Adapter_hpp

#include <stdio.h>

class Bird
{
  public:
    virtual void fly() = 0;
    virtual void makeSound() = 0;
};
 
class Sparrow : public Bird
{
  public:
    void fly() override
    {
        std::cout << "Flying" << std::endl;
    }
    void makeSound() override
    {
        std::cout << "Chirp Chirp" << std::endl;
    }
};
 
class ToyDuck
{
  public:
    virtual void squeak() = 0;
};
 
class PlasticToyDuck : public ToyDuck
{
  public:
    void squeak() override
    {
        std::cout << "Squeak" << std::endl;
    }
};
 
class BirdAdapter : public ToyDuck
{
  public:
    BirdAdapter(Bird &bird) : bird_(bird) {}
    void squeak() override
    {
        bird_.makeSound();
    }
 
  private:
    Bird &bird_;
};
#endif /* Adapter_hpp */
