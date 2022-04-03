/**
 * @file Arm.cpp
 * @author Junchi Zhu
 */

#include "Arm.h"
#include "pch.h"

Arm::Arm(int length):mSink(this)
{
    mLength = length;
    Rectangle(-5,5,int(mLength), 10);
}

void Arm::SetRotation(double rotation)
{
    Component::SetRotation(rotation);
    double endRodX = GetX() + (mLength-8) * cos(rotation * M_PI * 2);
    double endRodY = GetY() + (mLength-12) * sin(rotation * M_PI * 2);
    UpdateMovePosition(endRodX,endRodY);
}

void Arm::UpdateMovePosition(double endX,double endY){
    mMoveSource.SetMovePosition(endX,endY);
}

