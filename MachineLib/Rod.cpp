/**
 * @file Rod.cpp
 * @author Junchi Zhu
 */

#include "Rod.h"
#include "pch.h"

Rod::Rod(int length, int wide):mSink(this)
{
    mLength = length;
    mWide = wide;
    Rectangle((-wide/2),length-2, wide, length);
}

void Rod::SetPosition(double x, double y)
{
    Component::SetPosition(x,y);
    if (mRodSink != nullptr)
    {
        mRodSink->Negotiate(this);
    }
}

void Rod::SetRodSink(RodSink* sink)
{
    mRodSource.AddSink(sink);
    mRodSink = sink;
}



