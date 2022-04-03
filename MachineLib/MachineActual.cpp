/**
 * @file MachineActual.cpp
 * @author Junchi Zhu
 */

#include "MachineActual.h"
#include "MachinesFactory.h"
#include "pch.h"

MachineActual::MachineActual(std::wstring imagesDir):mImagesDir(imagesDir)
{
    SetMachineNumber(1);
}

void MachineActual::SetMachineNumber(int machine)
{
    if(machine == 1)
    {
        MachinesFactory factory(mImagesDir);
        mMachine = factory.Create1();
        mNumber = machine;
    }
    else{
        MachinesFactory factory2(mImagesDir);
        mMachine = factory2.Create2();
        mNumber = machine;
    }
}



void MachineActual::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
    mMachine->Draw(graphics, mLocation.x, mLocation.y);
}

void MachineActual::SetMachineFrame(int frame)
{
    mTime = frame / mFrameRate * mSpeed;
    mMachine->SetTime(mTime);
}


void MachineActual::SetLocation(wxPoint loc) { mLocation = loc; }