#include "vehiclerentalsystem.h"

int main()
{
    VehicleRentalSystem system;

    system.loadFromFile();

    system.run();

    system.saveToFile();

    return 0;
}
