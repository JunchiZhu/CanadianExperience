/**
 * @file RodSink.h
 * @author Junchi Zhu
 *
 * Class that represent RodSink
 */

#pragma once
#include "Sink.h"
#include "INegotiator.h"

class Lever;
/**
* Class that represent RodSink
*/
class RodSink: public Sink{

private:
    /// pointer to a Negotiator
    INegotiator* mNegotiator = nullptr;

public:
    /**
     * Constructor
     * @param component Component we are connected to.
     * @param negotiator The negotiator we will negotiate with
     */
    RodSink(Component *component, INegotiator *negotiator);

    RodSink() = delete;
    /// Copy Constructor (Disabled)
    RodSink(const RodSink &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const RodSink &) = delete;

    /// negotiation between rod and other component
    /// @param rod
    void Negotiate(Rod *rod);

};
