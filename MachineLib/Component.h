/**
 * @file Component.h
 * @author Junchi Zhu
 * Class that represents a Component.
 *
 */

#ifndef CANADIANEXPERIENCE_COMPONENT_H
#define CANADIANEXPERIENCE_COMPONENT_H

#include "Polygon.h"

class WorkingMachine;
class Sink;
/**
 * Class that represents a Component.
 */
class Component : public Polygon{
private:
    /// The Machine this Component is associated with
    WorkingMachine *mWorkingMachine = nullptr;

    /// The Position of a Component
    wxPoint mPosition = wxPoint(0, 0);

    /// The machine Time
    double mTime;

    double mX = 0.0; ///< The x location of item
    double mY = 0.0; ///< The y location of item

public:
    /// Constructor
    Component();

    /// Copy Constructor (Disabled)
    Component(const Component &) = delete;

    /// Assignment Operator (Disabled)
    void operator=(const Component &) = delete;

    /**
    * Set machine
    * @param machine
    */
    void SetWorkingMachine(WorkingMachine *machine);

    /**
     * The Component position
     * @return The Component position as a point
     * */
    wxPoint GetPosition() const { return mPosition; }

     /**
     * The Component position
     * @param x,y
     */
     virtual void SetPosition(double x,double y);

    /**
    * Draw this Component
    * @param graphics The Graphics object we are drawing on
    * @param x object's x position
    * @param y object's y position
    */
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);

    /**
    * The Component time
    * @param time The new Component time
    */
    virtual void SetTime(double time){mTime = time;}

    /**
    * The Component rotation
    * @param rotation The new Component rotation
    */
    void SetRotation(double rotation) override;

    /**
     * The X location of the item
     * @return X location in pixels
     */
    double GetX() const { return mX; }

    /**
     * The Y location of the item
     * @return Y location in pixels
     */
    double GetY() const { return mY; }

    /**
     * Set the item location
     * @param x X location in pixels
     * @param y Y location in pixels
     */
    virtual void SetLocation(double x, double y) { mX = x; mY = y; }


};

#endif //CANADIANEXPERIENCE_COMPONENT_H
