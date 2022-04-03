/**
 * @file Source.h
 * @author Junchi Zhu
 *
 *  Class that represents a Sink.
 */

#ifndef CANADIANEXPERIENCE_SOURCE_H
#define CANADIANEXPERIENCE_SOURCE_H
#include "Component.h"
/**
 *  Class that represents a Sink.
 */
class Source{
private:
    /// Component which connect with Sink
    Component *mComponent = nullptr;

public:
    /// Constructor
    Source();

    /**
    * Component Connect with Sink
    * @param  component
    */
    void SetComponent(Component *component);

    /**
    * Component Connect with Sink
    * @return  Component
    */
    Component *GetComponent() { return mComponent; }

};

#endif //CANADIANEXPERIENCE_SOURCE_H
