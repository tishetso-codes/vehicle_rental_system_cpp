#ifndef CAR_H
#define CAR_H

#include "vehicle.h"

class Car : public Vehicle
{
private:
    int numberOfDoors;
    int numberOfSeats;

public:
    Car();

    Car(QString id,
        QString brand,
        QString model,
        double pricePerDay,
        bool isRented,
        int numberOfDoors,
        int numberOfSeats);

    int getNumberOfDoors() const;
    int getNumberOfSeats() const;

    void setNumberOfDoors(int doors);
    void setNumberOfSeats(int seats);

    QString typeName() const override;

    QString toDisplayString() const override;
};

#endif
