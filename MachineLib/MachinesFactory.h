/**
 * @file MachinesFactory.h
 * @author Junchi Zhu
 *
 *
 */

#ifndef CANADIANEXPERIENCE_MACHINESFACTORY_H
#define CANADIANEXPERIENCE_MACHINESFACTORY_H
#include <memory>

class WorkingMachine;
/// Class which used to install each component
class MachinesFactory {
private:
    /// image directory for the machine
    std::wstring mImagesDir;

public:
    MachinesFactory(std::wstring imagesDir);

    std::shared_ptr<WorkingMachine> Create1();

    std::shared_ptr<WorkingMachine> Create2();

    std::shared_ptr<WorkingMachine> Create(int machine);


};

#endif //CANADIANEXPERIENCE_MACHINESFACTORY_H
