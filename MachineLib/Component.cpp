/**
 * @file Component.cpp
 * @author Junchi Zhu
 */

#include "Component.h"
#include "pch.h"

void Component::SetWorkingMachine(WorkingMachine *machine)
{
    mWorkingMachine = machine;
}

void Component::SetPosition(double x,double y)
{
    mPosition.x = x;
    mPosition.y = y;
    mX = x;
    mY = y;
}

void Component::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    DrawPolygon(graphics, x+mPosition.x, y+mPosition.y);
}

void Component::SetRotation(double rotation) {
    Polygon::SetRotation(rotation);
}

Component::Component()
{

}
