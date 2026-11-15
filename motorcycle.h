#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "vehicle.h"

class Motorcycle : public Vehicle
{
private:
    int engineCapacityCC;

public:
    Motorcycle();

    Motorcycle(QString id,
               QString brand,
               QString model,
               double pricePerDay,
               bool isRented,
               int engineCapacityCC);

    int getEngineCapacityCC() const;

    void setEngineCapacityCC(int cc);

    QString typeName() const override;

    QString toDisplayString() const override;
};

#endif
