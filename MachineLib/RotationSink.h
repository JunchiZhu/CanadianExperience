/**
 * @file RotationSink.h
 * @author Junchi Zhu
 *
 * Class that represents a RotationSink.
 */

#pragma once
#include "Sink.h"

/**
 *  Class that represents a RotationSink.
 */
class RotationSink : public Sink{
private:
    /// speed of RotationSink
    double mSpeed = 1;
    /// phase of RotationSink
    double mPhase = 0;
    /// rotation of RotationSink
    double mRotation;

public:
    /// Constructor
    /// @param component
    RotationSink(Component* component);

    RotationSink()= delete;
    /// Copy Constructor (Disabled)

    RotationSink(const RotationSink &) = delete;

    /// Assignment Operator (Disabled)
    void operator=(const RotationSink &) = delete;

    /**
    * The RotationSink rotation
    * @param rotation The new RotationSink rotation
    */
    void SetRotate(double rotation);

    /**
    * The RotationSink rotation
    * @return  The new RotationSink rotation
    */
    double GetRotation(){ return mRotation;}

    /**
    * The RotationSink speed
    * @param speed The new RotationSink speed
    */
    void SetSpeed(double speed);

    /**
    * The RotationSink Speed
    * @return  The new RotationSink Speed
    */
    double GetSpeed(){return mSpeed;}


    /**
    * The RotationSink phase
    * @param phase The new RotationSink phase
    */
    void SetPhase(double phase);

    /**
    * The RotationSink Speed
    * @return  The new RotationSink Speed
    */
    double GetPhase(){return mPhase;}

};

