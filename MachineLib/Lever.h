/**
 * @file Lever.h
 * @author Junchi Zhu
 *
 * Class that represents a Lever.
 */

#ifndef CANADIANEXPERIENCE_LEVER_H
#define CANADIANEXPERIENCE_LEVER_H

#include "Component.h"
#include "RotationSource.h"
#include "MovementSource.h"
#include "INegotiator.h"
#include "RodSink.h"
/**
 * Class that represents a Lever.
 *
 */
class Lever : public Component, INegotiator{
private:
    RotationSource mRotateSource;    ///< The rotation source for this component

    MovementSource mMoveSource;    ///< The movement source for this component

    RotationSink* mRotateSink;  ///< The rotation sink for this component

    RodSink mRodSink;         ///< The rod sink for this component

    double mLength;         ///< The length of the lever

    double mDriveEnd;      ///< The distance from rod connected point to the middle point of the lever

    INegotiator* mNegotiator = nullptr; ///< Negotiator
public:
    /// Constructor
    ///@param length
    Lever(int length);

    /// Copy Constructor (Disabled)
    Lever(const Lever &) = delete;

    /// Assignment Operator (Disabled)
    void operator=(const Lever &) = delete;

    /**
    * Get a pointer to the RotationSource object
    * @return Pointer to RotationSource object
    */
    RotationSource *GetRotationSource() { return &mRotateSource; }

    /**
    * Get a pointer to the MovementSource object
    * @return Pointer to MovementSource object
    */
    MovementSource *GetMovementSource() { return &mMoveSource; }

    /**
    * Get a pointer to the rodSink object
    * @return Pointer to rodSink object
    */
    RodSink *GetRodSink() { return &mRodSink; }

    /**
    * Negotiation between rod and lever
    * @param rod
    */
    void Negotiate(Rod *rod) override;

    /**
    * Set distance from rod connected point to the middle point of the lever
    * @param driveEnd
    */
    void SetDriveEnd(double driveEnd);

    /**
    * The Component rotation
    * @param rotation The new Component rotation
    */
    void SetRotation(double rotation) override;

    /**
    * The Component position
    * @param x,y The new Component position
    */
    void SetPosition(double x,double y) override;
};

#endif //CANADIANEXPERIENCE_LEVER_H
