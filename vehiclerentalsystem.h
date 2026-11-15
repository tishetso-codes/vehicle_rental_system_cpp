#ifndef VEHICLERENTALSYSTEM_H
#define VEHICLERENTALSYSTEM_H

#include <QVector>
#include "vehicle.h"

class VehicleRentalSystem
{
private:
    QVector<Vehicle*> vehicles;

public:
    VehicleRentalSystem();

    ~VehicleRentalSystem();

    void addVehicle();

    void searchVehicle();

    void displayAllVehicles();

    void displayAvailableVehicles();

    void rentVehicle();

    void returnVehicle();

    Vehicle* findVehicleById(QString id);

    void loadFromFile();

    void saveToFile();

    void run();
};

#endif
