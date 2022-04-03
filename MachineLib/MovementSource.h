/**
 * @file MovementSource.h
 * @author Junchi Zhu
 *
 *  Class that represents a MovementSource.
 */
#include "Source.h"
#include "MovementSink.h"
#include "Component.h"

#ifndef CANADIANEXPERIENCE_MOVEMENTSOURCE_H
#define CANADIANEXPERIENCE_MOVEMENTSOURCE_H
/**
 *  Class that represents a MovementSource.
 */
class MovementSource : public Source{
private:
    /// a list of Move Components
    std::vector<std::shared_ptr<Component>> mMoveComponents;
    /// the position of a MovementSource
    wxPoint mPosition;
public:
    /// Constructor
    MovementSource(){};

    /// add  Move Components
    ///@param component
    void AddMoveComponent(std::shared_ptr<Component> component);

    /**
    * The MovementSink position
    * @param x The new MovementSink position
    * @param y The new MovementSink position
    */
    void SetPosition(double x,double y);

    /**
    * The MovementSink position
    * @return  The new MovementSink position
    */
    wxPoint GetPosition(){return mPosition;}

    /**
    * The MovementSink position
    * @param x The new MovementSink position
    * @param y The new MovementSink position
    */
    void SetMovePosition(double x,double y);

};

#endif //CANADIANEXPERIENCE_MOVEMENTSOURCE_H
