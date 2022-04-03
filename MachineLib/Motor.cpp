/**
 * @file Motor.cpp
 * @author Junchi Zhu
 */

#include "Motor.h"
#include "pch.h"

Motor::Motor(std::wstring imagesDir,std::wstring type): mImagesDir(imagesDir)
{
    mSource.SetComponent(this);
    if(type == L"/images"){
        mMode = Mode::Image;
    }
    else{
        mMode = Mode::Color;
    }
    CenteredSquare(50);
    SetImage(mImagesDir + L"/shaft.png");
}


void Motor::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    switch (mMode) {
    case Mode::Color:
        mColorBody = std::make_shared<Polygon>();
        mColorBody->SetColor(*wxBLACK);
        mColorBody->Rectangle(-50, 0, 100, 100);
        mColorBody->DrawPolygon(graphics, x+GetPosition().x,y+GetPosition().y);

        Component::Draw(graphics, x, y-50);
        break;

    case Mode::Image:
        mImageBody = std::make_shared<Polygon>();
        mImageBody->Rectangle(-50, 0, 100, 100);
        mImageBody->SetImage(mImagesDir + L"/motor2.png");
        mImageBody->DrawPolygon(graphics, x+GetPosition().x, y+GetPosition().y);

        Component::Draw(graphics, x, y-50);
        break;

    case Mode::Unset:
        break;
    }
}

void Motor::SetTime(double time)
{
    double rotation = mSpeed*time;
    SetRotation(rotation);
}

void Motor::SetRotation(double rotation)
{
    Component::SetRotation(rotation);
    mSource.SetRotation(rotation);
}

