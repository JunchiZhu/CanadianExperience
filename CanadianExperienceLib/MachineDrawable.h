/**
 * @file MachineDrawable.h
 * @author Junchi Zhu
 *
 * A drawable that displays an machine
 */

#ifndef CANADIANEXPERIENCE_MACHINEDRAWABLE_H
#define CANADIANEXPERIENCE_MACHINEDRAWABLE_H

#include "Drawable.h"
#include "AnimChannelPoint.h"
#include <machine-api.h>

class Machine;
/**
 * A drawable that displays an machine
 */
class MachineDrawable : public Drawable{
private:
    /// The machine we are drawing
    std::shared_ptr<Machine> mMachine;

    /// The time used in the machine
    Timeline* mTimeline;

    ///machine number
    int mNum;


public:
    /** Constructor
     * @param name The drawable name
     * @param imagesDir The directory for the machin
     * @param num The Machine Number*/
    MachineDrawable(const std::wstring& name, const std::wstring imagesDir,int num);


    /**
     * Draw the image drawable
     * @param graphics Graphics context to draw on
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;


    /**
     * Test to see if we clicked on the image.
     * @param pos Position to test
     * @return True if clicked on
     */
    bool HitTest(wxPoint pos) override;

    /**
     * Set timeLine which can help us to access time to make sure machine to move
     * @param timeline
     */
    void SetTimeline(Timeline* timeline) override;

    /**
     * Pop up machine digbox which can used to select machine
     * @param parent
     */
    void ShowDigBox(wxWindow* parent);
};

#endif //xCANADIANEXPERIENCE_MACHINEDRAWABLE_H
