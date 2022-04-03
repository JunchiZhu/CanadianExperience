/**
 * @file WorkingMachine.cpp
 * @author Junchi Zhu
 */

#include "WorkingMachine.h"
#include "pch.h"

using namespace std;

WorkingMachine::WorkingMachine(int machine)
{

}

void WorkingMachine::AddComponent(std::shared_ptr<Component> component)
{
    mComponents.push_back(component);
    component->SetWorkingMachine(this);
}


//void WorkingMachine::SetWorkingMachine(MachineActual *machine)
//{
//    mMachineActual = machine;
//}


void WorkingMachine::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    for (auto component : mComponents)
    {
        component->Draw(graphics, x, y);
    }
}

void WorkingMachine::SetTime(double time)
{
    for (auto component : mComponents)
    {
        component->SetTime(time);
    }
}

