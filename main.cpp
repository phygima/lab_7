#define _CRT_SECURE_NO_DEPRECATE
#include "Command.hpp"
#include "Adapter.hpp"
#include "Singleton.hpp"


using namespace std;



int main()
{
    //Command
    cout<<"-------COMMAND-------"<<endl;
    // Receiver
    Light *light = new Light;

    // concrete Command objects
    LightOnCommand *lightOn = new LightOnCommand(light);
    LightOffCommand *lightOff = new LightOffCommand(light);

    // invoker objects
    RemoteControl *control = new RemoteControl;

    // execute
    control->setCommand(lightOn);
    control->buttonPressed();
    control->setCommand(lightOff);
    control->buttonPressed();

    delete light,lightOn,lightOff,control;
    
    cout << "\n\n";
    //Adapter
    cout<<"-------ADAPTER-------"<<endl;
    
    Sparrow sparrow;
    PlasticToyDuck toyDuck;
 
    ToyDuck &birdAdapter = *(new BirdAdapter(sparrow));
 
    cout << "Sparrow..." <<endl;
    sparrow.fly();
    sparrow.makeSound();
 
    cout << "ToyDuck..." <<endl;
    toyDuck.squeak();
 
    cout << "BirdAdapter..." <<endl;
    birdAdapter.squeak();
    
    
    cout << "\n\n";
    //SINGLETON
    cout<<"-------SINGLETON-------"<<endl;
    Singleton* obj1 = Singleton::Instance();

      if (obj1 != nullptr)
      {
        obj1->Set(255);
        obj1->Print();
      }
      Singleton* obj2 = Singleton::Instance();

      if (obj2 != nullptr)
      {
        obj2->Set(300);
        obj2->Print();
      }


    return 0;
}

