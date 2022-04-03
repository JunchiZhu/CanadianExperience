/**
 * @file Arm.h
 * @author Junchi Zhu
 *
 * Class that represents a Lever.
 */

#ifndef CANADIANEXPERIENCE_ARM_H
#define CANADIANEXPERIENCE_ARM_H
#include "Component.h"
#include "RotationSink.h"
#include "RotationSource.h"
#include "MovementSource.h"
#include "Rod.h"
/**
 * Class that represents a Lever.
 */
class Arm : public Component{
private:
    RotationSink mSink;    ///< The rotation sink for this component

    double mLength;     ///< The Length of the arm

    MovementSource mMoveSource;    ///< The rotation source for this component

    double mX = 0.0; ///< The x location of item
    double mY = 0.0; ///< The y location of item

    double mEndX = 0.0; ///< The x location of item
    double mEndY = 0.0; ///< The y location of item
public:
    ///Constructor
    ///@param length
    Arm(int length);

    /// Copy Constructor (Disabled)
    Arm(const Arm &) = delete;

    /// Assignment Operator (Disabled)
    void operator=(const Arm &) = delete;

    /**
    * Get a pointer to the RotationSink object
    * @return Pointer to RotationSink object
    */
    RotationSink *GetSink() { return &mSink; }

    /**
    * Get a pointer to the MovementSource object
    * @return Pointer to MovementSource object
    */
    MovementSource *GetMoveSource() { return &mMoveSource; }

    /**
    * Set SetRotation
    * @param rotation
    */
    void SetRotation(double rotation);

    /**
    * Update the arm end side position
    * @param endRodX,endRodY
    */
    void UpdateMovePosition(double endRodX, double endRodY);
};

#endif //CANADIANEXPERIENCE_ARM_H
