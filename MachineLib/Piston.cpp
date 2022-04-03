/**
 * @file Piston.cpp
 * @author Junchi Zhu
 */

#include "Piston.h"
#include "Rod.h"
#include <cmath>
#include "pch.h"


Piston::Piston():mRodSink(this,this)
{

}


void Piston::Negotiate(Rod* rod)
{
    double x1 = rod->GetX();
    double y1 = rod->GetY();
    double a = rod->GetLength();
    double x2 = GetX();
    double alpha = asin((x2-x1)/a);
    double beta = M_PI/2-alpha;
    double rotation = beta/(2*M_PI);
    double pistonPosY = sqrt(pow((a), 2) - pow((x2-x1), 2))+y1;

    rod->SetRotation(rotation+1.75);
    Component::SetPosition(x2,pistonPosY);
}

