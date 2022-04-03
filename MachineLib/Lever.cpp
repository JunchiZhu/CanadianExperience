/**
 * @file Lever.cpp
 * @author Junchi Zhu
 */

#include "Lever.h"
#include "Rod.h"
#include <cmath>
#include "pch.h"
using namespace std;

Lever::Lever(int length):mRodSink(this,this)
{
    mLength = length;
    int height = 50;
    int width = mLength;
    Rectangle(-width/2,height/2, width, height);
}

void Lever::Negotiate(Rod* rod)
{
    double a = mDriveEnd;
    double b = rod->GetLength();
    double x1 = rod->GetX();
    double y1 = rod->GetY();
    double x2 = GetX();
    double y2 = GetY();
    double c = sqrt(pow((y2-y1), 2) + pow((x2-x1), 2));
    double delta = atan2(-(y2-y1),x2-x1);
    double alpha = acos((pow(b, 2)+pow(c, 2)-pow(a, 2))/(2*b*c));
    double theta = delta-alpha;

    double PI_2 = M_PI*2;
    double x3 = x1+b*cos(-theta);
    double y3 = y1+b*sin(-theta);
    double phi = atan2(y3-y2,x3-x2);
    double x4 = x2 + (-a*cos(phi));
    double y4 = y2 + (-a*sin(phi));

    Component::SetRotation(phi/PI_2);
    mRotateSource.SetRotation(phi/PI_2);
    rod->SetRotation((-(theta)/PI_2)+0.75);
    mMoveSource.SetMovePosition(x4,y4);
}


void Lever::SetDriveEnd(double driveEnd)
{
    mDriveEnd = driveEnd;
}

void Lever::SetRotation(double rotation)
{
    Component::SetRotation(rotation);
    mRotateSource.SetRotation(rotation);
}

void Lever::SetPosition(double x,double y)
{
    Component::SetPosition(x,y);
    mMoveSource.SetPosition(x,y);
}


