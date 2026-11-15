#include "car.h"

Car::Car()
{
}

Car::Car(QString id,
         QString brand,
         QString model,
         double pricePerDay,
         bool isRented,
         int numberOfDoors,
         int numberOfSeats)
    : Vehicle(id, brand, model, pricePerDay, isRented)
{
    this->numberOfDoors = numberOfDoors;
    this->numberOfSeats = numberOfSeats;
}

int Car::getNumberOfDoors() const
{
    return numberOfDoors;
}

int Car::getNumberOfSeats() const
{
    return numberOfSeats;
}

void Car::setNumberOfDoors(int doors)
{
    numberOfDoors = doors;
}

void Car::setNumberOfSeats(int seats)
{
    numberOfSeats = seats;
}

QString Car::typeName() const
{
    return "Car";
}

QString Car::toDisplayString() const
{
    return Vehicle::toDisplayString() +
           " | Doors: " + QString::number(numberOfDoors) +
           " | Seats: " + QString::number(numberOfSeats);
}
