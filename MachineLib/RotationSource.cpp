/**
 * @file RotationSource.cpp
 * @author Junchi Zhu
 */

#include "RotationSource.h"
#include "pch.h"

RotationSource::RotationSource()
{

}

void RotationSource::AddSink(RotationSink * sink)
{
    mRotationSinks.push_back(sink);
}

void RotationSource::SetRotation(double rotation)
{
    for (auto sink : mRotationSinks){
        sink->SetRotate(rotation);
    }
}

