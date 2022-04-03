/**
 * @file RotationSink.cpp
 * @author Junchi Zhu
 */

#include "RotationSink.h"
#include "pch.h"

RotationSink::RotationSink(Component *component):Sink(component)
{

}

void RotationSink::SetRotate(double rotation)
{
    GetComponent()->SetRotation(rotation * mSpeed + mPhase);
}

void RotationSink::SetSpeed(double speed)
{
    mSpeed = speed;
}

void RotationSink::SetPhase(double phase)
{
    mPhase = phase;
}

