/**
 * @file MovementSink.h
 * @author Junchi Zhu
 *
 *  Class that represents a MovementSink.
 */

#pragma once
#include "Sink.h"
/**
 *  Class that represents a MovementSink.
 */
class MovementSink: public Sink{
private:
    /// the position of a MovementSink
    wxPoint mPosition;
public:
    /// Constructor
    /// @param component
    MovementSink(Component* component);

    /// Constructor (Disabled)
    MovementSink()= delete;

    /// Copy Constructor (Disabled)
    MovementSink(const MovementSink &) = delete;

    /// Assignment Operator (Disabled)
    void operator=(const MovementSink &) = delete;

    /**
    * The MovementSink position
    * @param position The new MovementSink position
    */
    void SetPosition(wxPoint position);

    /**
    * The MovementSink position
    * @return  The new MovementSink position
    */
    wxPoint GetPosition(){return mPosition;}
};

