//
//  Command.hpp
//  7
//
//  Created by Виктория Гладкова on 12.02.2023.
//

#ifndef Command_hpp
#define Command_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

// Command Interface
class Command
{
public:
    virtual void execute() = 0;
};
 
// Receiver Class
class Light
{
public:
    void on() {
        cout << "The light is on\n";
    }
    void off() {
        cout << "The light is off\n";
    }
};

// Command for turning on the light
class LightOnCommand : public Command
{
public:
        LightOnCommand(Light *light) : mLight(light) {}
    void execute(){
        mLight->on();
    }
private:
    Light *mLight;
};
 
// Command for turning off the light
class LightOffCommand : public Command
{
public:
        LightOffCommand(Light *light) : mLight(light) {}
    void execute(){
        mLight->off();
    }
private:
    Light *mLight;
};

// Invoker
// Stores the ConcreteCommand object
class RemoteControl
{
public:
    void setCommand(Command *cmd) {
        mCmd = cmd;
    }

    void buttonPressed() {
        mCmd->execute();
    }
private:
    Command *mCmd;
};

#endif /* Command_hpp */
