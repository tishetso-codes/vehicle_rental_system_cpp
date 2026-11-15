#include "vehicle.h"

Vehicle::Vehicle()
{
}

Vehicle::Vehicle(QString id,
                 QString brand,
                 QString model,
                 double pricePerDay,
                 bool isRented)
{
    this->id = id;
    this->brand = brand;
    this->model = model;
    this->pricePerDay = pricePerDay;
    this->isRented = isRented;
}

Vehicle::~Vehicle()
{
}

QString Vehicle::getId() const
{
    return id;
}

QString Vehicle::getBrand() const
{
    return brand;
}

QString Vehicle::getModel() const
{
    return model;
}

double Vehicle::getPricePerDay() const
{
    return pricePerDay;
}

bool Vehicle::getIsRented() const
{
    return isRented;
}

void Vehicle::setId(QString id)
{
    this->id = id;
}

void Vehicle::setBrand(QString brand)
{
    this->brand = brand;
}

void Vehicle::setModel(QString model)
{
    this->model = model;
}

void Vehicle::setPricePerDay(double price)
{
    this->pricePerDay = price;
}

void Vehicle::setIsRented(bool rented)
{
    this->isRented = rented;
}

QString Vehicle::toDisplayString() const
{
    QString status;

    if(isRented)
    {
        status = "Rented";
    }
    else
    {
        status = "Available";
    }

    return "ID: " + id +
           " | Brand: " + brand +
           " | Model: " + model +
           " | Price Per Day: R" + QString::number(pricePerDay) +
           " | Status: " + status;
}
