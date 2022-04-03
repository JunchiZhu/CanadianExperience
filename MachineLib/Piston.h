/**
 * @file Piston.h
 * @author Junchi Zhu
 *
 * Class that represents a Gear.
 */

#ifndef CANADIANEXPERIENCE_PISTON_H
#define CANADIANEXPERIENCE_PISTON_H

#include "Component.h"
#include "INegotiator.h"
#include "RodSink.h"
/**
 * Class that represents a Gear.
 *
 */
class Piston : public Component, INegotiator{
private:
    RodSink mRodSink;///< The rod Sink for this component
public:
    ///  constructor
    Piston();

    /// Copy Constructor (Disabled)
    Piston(const Piston &) = delete;

    /// Assignment Operator (Disabled)
    void operator=(const Piston &) = delete;

    /**
    * Get a pointer to the RodSink object
    * @return Pointer to RodSink object
    */
    RodSink *GetRodSink() { return &mRodSink; }

    /**
    * Negotiation between rod and lever
    * @param rod
    */
    void Negotiate(Rod *rod) override;


};

#endif //CANADIANEXPERIENCE_PISTON_H
