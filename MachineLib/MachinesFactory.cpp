/**
 * @file MachinesFactory.cpp
 * @author Junchi Zhu
 */

#include "MachinesFactory.h"
#include "WorkingMachine.h"
#include "Shape.h"
#include "pch.h"
#include "Motor.h"
#include "Gear.h"
#include "Arm.h"
#include "Rod.h"
#include "Lever.h"
#include "Piston.h"

using namespace std;


/**
 * Constructor
 * @param imagesDir Directory to load images from
 */
MachinesFactory::MachinesFactory(std::wstring imagesDir) : mImagesDir(imagesDir)
{

}


/**
 * Create a machine
 * @param machine Machine number to create
 * @return Pointer to newly created machine
 */
std::shared_ptr<WorkingMachine> MachinesFactory::Create(int machine)
{
    switch (machine) {
    case 1:
    default:
        return Create1();
    case 2:
        return Create2();
    }
}

/**
 * Create Machine #1
 * @return Newly created machine
 */
std::shared_ptr<WorkingMachine> MachinesFactory::Create1()
{
    // The machine itself
    // In this solution the machine number is passed
    // to the working machine constructor so it knows
    // its number.
    auto machine = make_shared<WorkingMachine>(1);

    // The base
    auto base = make_shared<Shape>();
    int wid = 550;
    base->Rectangle(-wid/2, -1, wid, 40);
    base->SetImage(mImagesDir + L"/base.png");
    machine->AddComponent(base);

    // The motor
    wstring type = L"/images";
    auto motor = make_shared<Motor>(mImagesDir,type);

    motor->SetPosition(50, -38);
    motor->SetSpeed(1.0);
    machine->AddComponent(motor);

    // The gear driven by the motor
    // Radius=20pixels, 10 teeth
    auto gear1 = make_shared<Gear>(20, 10);
    gear1->SetImage(mImagesDir + L"/iron.png");
    gear1->SetPosition(110, -100);
    machine->AddComponent(gear1);

    motor->GetSource()->AddSink(gear1->GetSink());

    // A post that holds the larger gear
    auto gear2post = make_shared<Shape>();
    gear2post->Rectangle(-10, 0, 20, 30);
    gear2post->SetPosition(gear1->GetX() + 55, -40);
    gear2post->SetColor(wxColour(0, 128, 0));
    machine->AddComponent(gear2post);

    // The second gear
    // Radius=40pixels, 20 teeth
    auto gear2 = make_shared<Gear>(40, 20);
    gear2->SetImage(mImagesDir + L"/hammered-copper.png");
    gear2->SetPosition(gear1->GetX() + 55, gear1->GetY());
    machine->AddComponent(gear2);

    gear1->Drive(gear2, 0.1);

    // The arm attached to the second gear
    // 50 pixels long
    auto arm = make_shared<Arm>(55);
    arm->SetImage(mImagesDir + L"/arm2.png");
    arm->SetPosition(gear2->GetPosition().x,gear2->GetPosition().y);


    gear2->GetSource()->AddSink(arm->GetSink());

    // The column that holds the lever
    auto column = make_shared<Shape>();
    column->Rectangle(-20, -40, 40, 260);
    column->SetImage(mImagesDir + L"/column.png");

    // The lever
    auto lever = make_shared<Lever>(400);
    lever->SetPosition(0, -272);
    lever->SetImage(mImagesDir + L"/lever.png");
    lever->SetDriveEnd(185);
    machine->AddComponent(lever);

    // The flag attached to the lever
    // Adding the points allows (0,0) be at the end
    // of the flagpole, so it rotates around that point.
    auto flag = make_shared<Shape>();
    flag->AddPoint(-50, 0);
    flag->AddPoint(-50, -100);
    flag->AddPoint(5, -100);
    flag->AddPoint(5, 0);
    flag->SetImage(mImagesDir + L"/flag.png");
    flag->SetPosition(lever->GetPosition().x,lever->GetPosition().y);
    machine->AddComponent(flag);
    lever->GetRotationSource()->AddSink(flag->GetSink());

    // Column is added after the lever so it is in front
    machine->AddComponent(column);

    // Rod from arm to lever
    // 150 pixels long, 6 pixels wide
    auto rod1 = make_shared<Rod>(150,6);
    int gray = 50;
    rod1->SetColor(wxColour(gray, gray, gray));
    machine->AddComponent(rod1);
    machine->AddComponent(arm);
    arm->GetMoveSource()->AddMoveComponent(rod1);
    rod1->SetRodSink(lever->GetRodSink());

    // Rod from lever to Piston
    // 50 pixels long, 5 pixels wide
    auto rod2 = make_shared<Rod>(70, 5);
    rod2->SetColor(wxColour(gray, gray, gray));

    lever->GetMovementSource()->AddMoveComponent(rod2);

    // Piston
    // The points are added so that (0,0) is
    // the attachment point for the rod.
    auto piston = make_shared<Piston>();
    double pistonH = 90;
    double pistonW = 0.386 * pistonH;
    double pistonC = 13.0 / 215.0 * pistonH;
    piston->AddPoint(-pistonW / 2, -pistonC);
    piston->AddPoint(pistonW / 2, -pistonC);
    piston->AddPoint(pistonW / 2, -pistonC + pistonH);
    piston->AddPoint(-pistonW / 2, -pistonC + pistonH);
    piston->SetImage(mImagesDir + L"/piston.png");
    piston->SetPosition(-175, -150);
    machine->AddComponent(piston);
    rod2->SetRodSink(piston->GetRodSink());

    machine->AddComponent(rod2);

    // Cylinder
    auto cylinder = make_shared<Shape>();
    cylinder->Rectangle(-30, 0, 60, 120);
    cylinder->SetPosition(-175, -38);
    cylinder->SetImage(mImagesDir + L"/cylinder.png");
    machine->AddComponent(cylinder);


    machine->AddComponent(base);
    return machine;
}
/**
 * Create Machine #2
 * @return Newly created machine
 */
std::shared_ptr<WorkingMachine> MachinesFactory::Create2(){
    auto machine = make_shared<WorkingMachine>(2);
    // The base
    auto base = make_shared<Shape>();
    int wid = 1250;
    base->Rectangle(-wid/2, 0, wid, 40);
    base->SetImage(mImagesDir + L"/base.png");
    machine->AddComponent(base);


    // The motor
    wstring type = L"/picture";
    auto motor = make_shared<Motor>(mImagesDir, type);
    motor->SetPosition(100, -38);
    motor->SetSpeed(1.0);
    machine->AddComponent(motor);


    // The gear driven by the motor
    // Radius=20pixels, 10 teeth
    auto gear1 = make_shared<Gear>(20, 10);
    gear1->SetImage(mImagesDir + L"/iron.png");
    gear1->SetPosition(110, -100);
    machine->AddComponent(gear1);

    motor->GetSource()->AddSink(gear1->GetSink());

    // A post that holds the larger gear
    auto gear2post = make_shared<Shape>();
    gear2post->Rectangle(-10, 0, 20, 30);
    gear2post->SetPosition(gear1->GetX() + 55, -40);
    gear2post->SetColor(wxColour(0, 128, 0));
    machine->AddComponent(gear2post);

    // The second gear
    // Radius=40pixels, 20 teeth
    auto gear2 = make_shared<Gear>(40, 20);
    gear2->SetImage(mImagesDir + L"/hammered-copper.png");
    gear2->SetPosition(gear1->GetX() + 55, gear1->GetY());
    machine->AddComponent(gear2);

    gear1->Drive(gear2, 0.1);

    // A post that holds the larger gear
    auto gear3post = make_shared<Shape>();
    gear3post->Rectangle(-10, 0, 20, 60);
    gear3post->SetPosition(gear2->GetX() + 80, -40);
    gear3post->SetColor(wxColour(100, 30, 30));
    machine->AddComponent(gear3post);

//    // The second gear
    // Radius=60pixels, 30 teeth
    auto gear3 = make_shared<Gear>(60, 30);
    gear3->SetImage(mImagesDir + L"/iron.png");
    gear3->SetPosition(gear2->GetX() + 83, gear2->GetY()-47);
    machine->AddComponent(gear3);
    gear2->Drive(gear3, 0.2);

    // The arm attached to the second gear
    // 50 pixels long
    auto arm = make_shared<Arm>(90);
    arm->SetImage(mImagesDir + L"/arm2.png");
    arm->SetPosition(gear3->GetPosition().x,gear3->GetPosition().y);
    machine->AddComponent(arm);

    gear3->GetSource()->AddSink(arm->GetSink());

    // The column that holds the lever
    auto column = make_shared<Shape>();
    column->Rectangle(-20, -40, 40, 350);
    column->SetImage(mImagesDir + L"/column.png");

    // The lever
    auto lever = make_shared<Lever>(600);
    lever->SetPosition(0, -360);
    lever->SetImage(mImagesDir + L"/lever.png");
    lever->SetDriveEnd(280);
    machine->AddComponent(lever);

    machine->AddComponent(column);

    // Rod from arm to lever
    // 150 pixels long, 7 pixels wide
    auto rod1 = make_shared<Rod>(200,6);
    int gray = 50;
    rod1->SetColor(wxColour(gray, gray, gray));
    machine->AddComponent(rod1);

    arm->GetMoveSource()->AddMoveComponent(rod1);
    rod1->SetRodSink(lever->GetRodSink());


    // Rod from lever to Piston
    // 50 pixels long, 5 pixels wide
    auto rod2 = make_shared<Rod>(298, 5);
    rod2->SetColor(wxColour(gray, gray, gray));

    lever->GetMovementSource()->AddMoveComponent(rod2);

    machine->AddComponent(rod2);


    // Cylinder
    auto cylinder = make_shared<Shape>();
    cylinder->Rectangle(-30, 0, 60, 120);
    cylinder->SetPosition(-260, -38);
    cylinder->SetImage(mImagesDir + L"/cylinder.png");
    machine->AddComponent(cylinder);
    machine->AddComponent(base);
    return machine;
}