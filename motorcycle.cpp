#include "motorcycle.h"

Motorcycle::Motorcycle()
{
}

Motorcycle::Motorcycle(QString id,
                       QString brand,
                       QString model,
                       double pricePerDay,
                       bool isRented,
                       int engineCapacityCC)
    : Vehicle(id, brand, model, pricePerDay, isRented)
{
    this->engineCapacityCC = engineCapacityCC;
}

int Motorcycle::getEngineCapacityCC() const
{
    return engineCapacityCC;
}

void Motorcycle::setEngineCapacityCC(int cc)
{
    engineCapacityCC = cc;
}

QString Motorcycle::typeName() const
{
    return "Motorcycle";
}

QString Motorcycle::toDisplayString() const
{
    return Vehicle::toDisplayString() +
           " | Engine Capacity: " +
           QString::number(engineCapacityCC) + "cc";
}
