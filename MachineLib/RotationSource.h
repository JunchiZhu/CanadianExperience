/**
 * @file RotationSource.h
 * @author Junchi Zhu
 *
 *  Class that represents a RotationSource.
 */

#ifndef CANADIANEXPERIENCE_ROTATIONSOURCE_H
#define CANADIANEXPERIENCE_ROTATIONSOURCE_H

#include "Source.h"
#include "RotationSink.h"
/**
 *  Class that represents a RotationSource.
 */
class RotationSource : public Source{
private:
    /// All RotationSink
    std::vector<RotationSink *> mRotationSinks;
    /// rotation for RotationSource
    double mRotation;
public:
    /// Constructor
    RotationSource();

    /// Copy constructor (disabled)
    RotationSource(const RotationSource &) = delete;

    /// Assignment operator (disabled)
    void operator=(const RotationSource &) = delete;

    /// Add RotationSink into list
    /// @param sink
    void AddSink(RotationSink * sink);

    /**
    * The RotationSource rotation
    * @param rotation The new RotationSource rotation
    */
    void SetRotation(double rotation);
    /**
    * The RotationSource rotation
    * @return  The new RotationSource rotation
    */
    double GetRotation(){return mRotation;}
};

#endif //CANADIANEXPERIENCE_ROTATIONSOURCE_H
