/**
 * @file MachineActual.h
 * @author Junchi Zhu
 *
 * Class that represents a machine.
 */

#ifndef CANADIANEXPERIENCE_MACHINEACTUAL_H
#define CANADIANEXPERIENCE_MACHINEACTUAL_H

#include "Machine.h"
#include "WorkingMachine.h"
#include "Component.h"
#include "RotationSource.h"
#include "MovementSource.h"
#include "INegotiator.h"
#include "RodSink.h"
/**
 * Class that represents a machine.
 */
class MachineActual : public Machine{
private:
    ///imagesDir Directory containing the machine images
    std::wstring mImagesDir;

    ///workingMachine which is used to install each component
    std::shared_ptr<WorkingMachine> mMachine = nullptr;

    ///position of the machine
    wxPoint mLocation = wxPoint(0, 0);

    ///machine time
    double mTime=0;

    ///machine FrameRate
    double mFrameRate=0;

    ///machine Speed
    double mSpeed=0;

    ///machine Number
    int mNumber;

public:
    /// Constructor
    ///@param imagesDir
    MachineActual(std::wstring imagesDir);

    ///  Default constructor (disabled)
    MachineActual() = delete;

    ///  Copy constructor (disabled)
    MachineActual(const MachineActual &) = delete;

    /**
    * Draw the machine at the currently specified location
    * @param graphics Graphics object to render to
    */
    void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
     * The Number of Machine
     * @return The Number of Machine
     */
    virtual int GetMachineNumber() override {return mNumber;}

    /**
     * The Number of Machine
     * @param machine The Number of Machine
     */
    virtual void SetMachineNumber(int machine) override;

    /**
     * The Machine Location
     * @return The Machine Location as a point
     */
    virtual wxPoint GetLocation() override {return mLocation;}

    /**
     * The Machine Location
     * @param loc The new Machine Location
     */
    virtual void SetLocation(wxPoint loc)override;

    /**
     * Set Machine Frame
     * @param frame Machine Frame
     */
    void SetMachineFrame(int frame) override;

    /**
     * The Machine Time
     * @param time The new Machine time
     */
    void SetTime(double time){mTime=time;}

    /**
     * The Machine Time
     * @return time The new Machine time
     */
    double GetTime() {return mTime;}

    /**
     * The Machine Location
     * @param frameRate The new Machine Location
     */
    void SetFrameRate(double frameRate) override {mFrameRate=frameRate;}

    /**
     * Get Frame Rate
     * @return Frame Rate
     */
    double GetFrameRate() {return mFrameRate;}

    /**
     * Set Machine Speed
     * @param speed The speed of Machine
     */
    void SetSpeed(double speed) override {mSpeed=speed;}

    /**
     * Get Machine Speed
     * @return The speed of Machine
     */
    double GetSpeed() {return mSpeed;}

};

#endif //CANADIANEXPERIENCE_MACHINEACTUAL_H
