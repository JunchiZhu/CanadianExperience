/**
 * @file MachineDrawable.cpp
 * @author Junchi Zhu
 */

#include "MachineDrawable.h"
#include "Timeline.h"
#include <machine-api.h>
#include "pch.h"

MachineDrawable::MachineDrawable(const std::wstring& name, const std::wstring imagesDir,int num):Drawable(name)
{
    MachineFactory factory(imagesDir);
    std::shared_ptr<Machine> machine = factory.CreateMachine();
    if(num == 1){
        machine->SetMachineNumber(1);
    }
    else{
        machine->SetMachineNumber(2);
    }
    mNum = num;
    mMachine = machine;
}


void MachineDrawable::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{

    if(mNum == 1){
        mMachine->SetFrameRate(30);
        mMachine->SetSpeed(1);
        mMachine->SetMachineFrame(mTimeline->GetCurrentFrame());
        double scale = 0.75f;
        graphics->PushState();
        graphics->Translate(mPlacedPosition.x, mPlacedPosition.y);
        graphics->Scale(scale, scale);
        mMachine->SetLocation(wxPoint(1500, 400));
        mMachine->DrawMachine(graphics);
        graphics->PopState();
    }
    else{
        mMachine->SetFrameRate(30);
        mMachine->SetSpeed(1);
        mMachine->SetMachineFrame(mTimeline->GetCurrentFrame());
        double scale = 0.55f;
        graphics->PushState();
        graphics->Translate(mPlacedPosition.x, mPlacedPosition.y);
        graphics->Scale(scale, scale);
        mMachine->SetLocation(wxPoint(2000, 1000));
        mMachine->DrawMachine(graphics);
        graphics->PopState();
    }


}

/**
 * Test to see if we clicked on the image.
 * @param pos Position to test
 * @return True if clicked on
 */
bool MachineDrawable::HitTest(wxPoint pos)
{
    return false;
}

void MachineDrawable::SetTimeline(Timeline* timeline)
{
    Drawable::SetTimeline(timeline);
    mTimeline = timeline;
}

void MachineDrawable::ShowDigBox(wxWindow* parent)
{
    MachineDialog dlg(parent, mMachine);
    if (dlg.ShowModal() == wxID_OK)
    {
        // A machine has been selected
    }
}
