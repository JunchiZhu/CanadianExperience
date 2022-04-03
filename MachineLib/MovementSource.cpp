/**
 * @file MovementSource.cpp
 * @author Junchi Zhu
 */

#include "MovementSource.h"
#include "pch.h"



void MovementSource::AddMoveComponent(std::shared_ptr<Component> component)
{
    mMoveComponents.push_back(component);
}

void MovementSource::SetMovePosition(double x,double y)
{
    for (auto component : mMoveComponents){
        component->SetPosition(x,y);
    }
}

void MovementSource::SetPosition(double x,double y)
{
    mPosition.x = x;
    mPosition.y = y;
}
