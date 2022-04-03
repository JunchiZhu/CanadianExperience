/**
 * @file Sink.h
 * @author Junchi Zhu
 *
 *  Class that represents a Sink.
 */

#ifndef CANADIANEXPERIENCE_SINK_H
#define CANADIANEXPERIENCE_SINK_H

#include "Component.h"

class Component;
/**
 *  Class that represents a Sink.
 */
class Sink{
private:
    /// Component which connect with Sink
    Component *mComponent = nullptr;
public:
    /// Constructor
    ///@param component
    Sink(Component *component);
    /// DeConstructor
    ~Sink();
    /// Constructor (Disabled)
    Sink() = delete;
    /// Copy Constructor (Disabled)
    Sink(const Sink &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const Sink &) = delete;

    /**
    * Component Connect with Sink
    * @return  Component
    */
    Component *GetComponent() { return mComponent; }

};

#endif //CANADIANEXPERIENCE_SINK_H
