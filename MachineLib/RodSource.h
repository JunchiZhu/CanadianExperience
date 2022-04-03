/**
 * @file RodSource.h
 * @author Junchi Zhu
 *
 * Class that represents a RodSource.
 */

#ifndef CANADIANEXPERIENCE_RODSOURCE_H
#define CANADIANEXPERIENCE_RODSOURCE_H
#include "RodSink.h"
/**
 *  Class that represents a RodSource.
 */
class RodSource {
private:
    /// list of RodSink
    std::vector<RodSink *> mRodSinks;
public:
    /// Constructor
    RodSource();

    /// Copy constructor (disabled)
    RodSource(const RodSource &) = delete;

    /// Assignment operator (disabled)
    void operator=(const RodSource &) = delete;

    //// Add RodSink into List
    /// @param sink
    void AddSink(RodSink* sink);



};

#endif //CANADIANEXPERIENCE_RODSOURCE_H
