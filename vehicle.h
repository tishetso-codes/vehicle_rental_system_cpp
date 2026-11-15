#ifndef VEHICLE_H
#define VEHICLE_H

#include <QString>

class Vehicle
{
protected:
    QString id;
    QString brand;
    QString model;
    double pricePerDay;
    bool isRented;

public:
    Vehicle();

    Vehicle(QString id,
            QString brand,
            QString model,
            double pricePerDay,
            bool isRented);

    virtual ~Vehicle();

    QString getId() const;
    QString getBrand() const;
    QString getModel() const;
    double getPricePerDay() const;
    bool getIsRented() const;

    void setId(QString id);
    void setBrand(QString brand);
    void setModel(QString model);
    void setPricePerDay(double price);
    void setIsRented(bool rented);

    virtual QString typeName() const = 0;

    virtual QString toDisplayString() const;
};

#endif
