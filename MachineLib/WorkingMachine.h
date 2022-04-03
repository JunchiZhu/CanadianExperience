/**
 * @file WorkingMachine.h
 * @author Junchi Zhu
 *
 * Class used for machine
 */

#ifndef CANADIANEXPERIENCE_WORKINGMACHINE_H
#define CANADIANEXPERIENCE_WORKINGMACHINE_H

#include "Component.h"
#include "Motor.h"

class MachineActual;
/**
 * Class used for machine
 */
class WorkingMachine {
private:
    /// All of the Component
    std::vector<std::shared_ptr<Component>> mComponents;

    /// The MachineActual and WorkingMachine associated with
    MachineActual *mMachineActual = nullptr;

    /// number of machine
    int mNumber;

    /// machine's position
    wxPoint mLocation;

public:
    /// constructor
    /// @param machine
    WorkingMachine(int machine);

    ///  Default constructor (disabled)
    WorkingMachine() = delete;

    ///  Copy constructor (disabled)
    WorkingMachine(const WorkingMachine &) = delete;

    /// add component into list which can be used to go through each component and do functionalities like draw
    /// @param component
    void AddComponent(std::shared_ptr<Component> component);

    /**
     * Draw the Machine
     * @param graphics Graphics object to draw on
     * @param x X location to draw in pixels
     * @param y Y location to draw in pixels
     */
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);

    /**
     * Set Machine TIME
     * @param time
     */
    void SetTime(double time);


//    MachineActual *GetMachineActual() { return mMachineActual; }
//
//    void SetWorkingMachine(MachineActual* machine);

};

#endif //CANADIANEXPERIENCE_WORKINGMACHINE_H
