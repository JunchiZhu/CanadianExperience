/**
 * @file Gear.h
 * @author Junchi Zhu
 *
 * Class that represents a Gear.
 */

#ifndef CANADIANEXPERIENCE_GEAR_H
#define CANADIANEXPERIENCE_GEAR_H

#include "Component.h"
#include "RotationSink.h"
#include "RotationSource.h"
/**
 * Class that represents a Gear.
 *
 */
class Gear : public Component{
private:
    RotationSink mSink;    ///< The rotation sink for this component

    RotationSource mSource;    ///< The rotation source for this component

    double mNumTeeth;     ///< The number of teeth for a gear
public:
    ///  constructor
    ///  @param radius
    ///  @param numTeeth
    Gear(int radius,int numTeeth);

    /// Copy Constructor (Disabled)
    Gear(const Gear &) = delete;

    /// Assignment Operator (Disabled)
    void operator=(const Gear &) = delete;

    /**
    * Get a pointer to the RotationSink object
    * @return Pointer to RotationSink object
    */
    RotationSink *GetSink() { return &mSink; }

    /**
    * make one Gear push another Gear
    * @param gear
    * @param phase
    */
    void Drive(std::shared_ptr<Gear> gear, double phase);

    /**
    * The Component rotation
    * @param rotation The new Component rotation
    */
    void SetRotation(double rotation) override;

    /**
    * Get a pointer to the RotationSource object
    * @return Pointer to RotationSource object
    */
    RotationSource *GetSource() { return &mSource; }

};

#endif //CANADIANEXPERIENCE_GEAR_H
