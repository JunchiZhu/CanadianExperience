/**
 * @file RodSource.cpp
 * @author Junchi Zhu
 */

#include "RodSource.h"
#include "pch.h"

RodSource::RodSource()
{

}

void RodSource::AddSink(RodSink* sink)
{
    mRodSinks.push_back(sink);
}



