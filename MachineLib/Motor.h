/**
 * @file Motor.h
 * @author Junchi Zhu
 *
 * Class that represents a Motor.
 */

#ifndef CANADIANEXPERIENCE_MOTOR_H
#define CANADIANEXPERIENCE_MOTOR_H

#include "Component.h"
#include "RotationSource.h"

class RotationSource;
/**
 * Class that represents a Motor.
 *
 */
class Motor : public Component{
private:
    /// The speed of the Motor
    double mSpeed;

    /// The ImagesDir which is used to access the directory from the list
    std::wstring mImagesDir;

    /// The image base body of the Motor
    std::shared_ptr<Polygon> mImageBody;

    /// The color base body of the Motor
    std::shared_ptr<Polygon> mColorBody;

    /// Rotation source for this component
    RotationSource mSource;

    /// The display mode
    enum class Mode {
        Unset, Color, Image
    };

    /// The current mode
    Mode mMode = Mode::Unset;
public:
    ///  constructor
    ///  @param imagesDir
    ///  @param type
    Motor(std::wstring imagesDir,std::wstring type);

    ///  Default constructor (disabled)
    Motor() = delete;

    ///  Copy constructor (disabled)
    Motor(const Motor &) = delete;
    /**
     * The Motor speed
     * @return The Motor speed
     * */
    double GetSpeed() const { return mSpeed;}

    /**
     * The Motor speed
     * @param speed The Motor speed
     */
    void SetSpeed(double speed){ mSpeed = speed;}

    /**
    * Draw this Motor
    * @param graphics The Graphics object we are drawing on
    * @param x object's x position
    * @param y object's y position
    */
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;

    /**
    * The Component time
    * @param time The new Component time
    */
    void SetTime(double time) override;

    /**
    * The Component rotation
    * @param rotation The new Component rotation
    */
    void SetRotation(double rotation) override;

    /**
    * Get a pointer to the RotationSource object
    * @return Pointer to RotationSource object
    */
    RotationSource *GetSource() { return &mSource; }
};

#endif //CANADIANEXPERIENCE_MOTOR_H
