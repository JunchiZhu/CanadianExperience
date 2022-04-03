/**
 * @file Rod.h
 * @author Junchi Zhu
 *
 * Class that represents a Rod.
 */

#ifndef CANADIANEXPERIENCE_ROD_H
#define CANADIANEXPERIENCE_ROD_H
#include "Component.h"
#include "RotationSink.h"
#include "RodSink.h"
#include "RodSource.h"
#include "MovementSource.h"
/**
 * Class that represents a Rod.
 *
 */
class Rod : public Component{
private:
    double mLength; ///< The length of the Rod

    double mWide; ///< The width of the Rod

    RodSink* mRodSink = nullptr; ///< The rod Sink for this component

    RodSource mRodSource; ///< The rod Source for this component

    RotationSink mSink; ///< The rod rotation Sink for this component

    MovementSource mMovementSource; ///< The movement Source for this component

public:
    /// Constructor
    ///@param length,wide
    Rod(int length, int wide);

    /// Copy Constructor (Disabled)
    Rod(const Rod &) = delete;

    /// Assignment Operator (Disabled)
    void operator=(const Rod &) = delete;

    /**
    * Get a pointer to the RotationSink object
    * @return Pointer to RotationSink object
    */
    RotationSink *GetSink() { return &mSink; }

    /**
    * Get a pointer to the MovementSource object
    * @return Pointer to MovementSource object
    */
    MovementSource *GetMoveSource() { return &mMovementSource; }

    /**
    * Get the length of rod
    * @return mLength
    */
    double GetLength(){return mLength;}

    /**
    * Set Rod Sink
    * @param sink
    */
    void SetRodSink(RodSink* sink);

    /**
    * The Component position
    * @param x,y The new Component position
    */
    void SetPosition(double x, double y) override;

};


#endif //CANADIANEXPERIENCE_ROD_H
