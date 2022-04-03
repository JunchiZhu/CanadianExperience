/**
 * @file Shape.h
 * @author Junchi Zhu
 *
 *  Class that represents a Sink.
 */

#ifndef CANADIANEXPERIENCE_SHAPE_H
#define CANADIANEXPERIENCE_SHAPE_H
#include "Component.h"
#include "RotationSink.h"
/**
 *  Class that represents a Sink.
 */
class Shape : public Component{
private:
    RotationSink mSink;    ///< The rotation sink for this component
public:
    /// Constructor
    Shape();

    /// Copy Constructor (Disabled)
    Shape(const Shape &) = delete;

    /// Assignment Operator (Disabled)
    void operator=(const Shape &) = delete;

    /**
    * The RotationSink position
    * @return The new RotationSink position
    */
    RotationSink *GetSink() { return &mSink; }

};

#endif //CANADIANEXPERIENCE_SHAPE_H
