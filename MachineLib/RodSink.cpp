/**
 * @file RodSink.cpp
 * @author Junchi Zhu
 */

#include "RodSink.h"
#include "INegotiator.h"
#include "pch.h"


RodSink::RodSink(Component *component, INegotiator *negotiator):
        Sink(component), mNegotiator(negotiator)
{

}

void RodSink::Negotiate(Rod* rod)
{
    mNegotiator->Negotiate(rod);
}


