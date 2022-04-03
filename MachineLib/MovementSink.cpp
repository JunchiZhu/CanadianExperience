/**
 * @file MovementSink.cpp
 * @author Junchi Zhu
 */

#include "MovementSink.h"
#include "pch.h"

MovementSink::MovementSink(Component* component)
        :Sink(component)
{

}

void MovementSink::SetPosition(wxPoint position)
{
    mPosition = position;
}
