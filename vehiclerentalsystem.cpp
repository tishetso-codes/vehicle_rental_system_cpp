#include "vehiclerentalsystem.h"
#include "car.h"
#include "motorcycle.h"

#include <QTextStream>
#include <QFile>
#include <QStringList>

VehicleRentalSystem::VehicleRentalSystem()
{
}

VehicleRentalSystem::~VehicleRentalSystem()
{
    for(Vehicle* v : vehicles)
    {
        delete v;
    }
}

Vehicle* VehicleRentalSystem::findVehicleById(QString id)
{
    for(Vehicle* v : vehicles)
    {
        if(v->getId() == id)
        {
            return v;
        }
    }

    return nullptr;
}

void VehicleRentalSystem::loadFromFile()
{
    QFile file("vehicles.txt");

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream input(&file);

    while(!input.atEnd())
    {
        QString line = input.readLine();

        QStringList parts = line.split("|");

        if(parts[0] == "Car")
        {
            Car* car = new Car(
                parts[1],
                parts[2],
                parts[3],
                parts[4].toDouble(),
                parts[5].toInt(),
                parts[6].toInt(),
                parts[7].toInt()
            );

            vehicles.append(car);
        }
        else if(parts[0] == "Motorcycle")
        {
            Motorcycle* bike = new Motorcycle(
                parts[1],
                parts[2],
                parts[3],
                parts[4].toDouble(),
                parts[5].toInt(),
                parts[6].toInt()
            );

            vehicles.append(bike);
        }
    }

    file.close();
}

void VehicleRentalSystem::saveToFile()
{
    QFile file("vehicles.txt");

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream output(&file);

    for(Vehicle* v : vehicles)
    {
        if(v->typeName() == "Car")
        {
            Car* car = dynamic_cast<Car*>(v);

            output << "Car|"
                   << car->getId() << "|"
                   << car->getBrand() << "|"
                   << car->getModel() << "|"
                   << car->getPricePerDay() << "|"
                   << car->getIsRented() << "|"
                   << car->getNumberOfDoors() << "|"
                   << car->getNumberOfSeats()
                   << "\n";
        }
        else if(v->typeName() == "Motorcycle")
        {
            Motorcycle* bike = dynamic_cast<Motorcycle*>(v);

            output << "Motorcycle|"
                   << bike->getId() << "|"
                   << bike->getBrand() << "|"
                   << bike->getModel() << "|"
                   << bike->getPricePerDay() << "|"
                   << bike->getIsRented() << "|"
                   << bike->getEngineCapacityCC()
                   << "\n";
        }
    }

    file.close();
}

void VehicleRentalSystem::addVehicle()
{
    QTextStream input(stdin);
    QTextStream output(stdout);

    int choice;

    output << "\n1. Car\n";
    output << "2. Motorcycle\n";
    output << "Enter choice: ";
    output.flush();

    input >> choice;

    QString id, brand, model;
    double price;

    output << "Enter ID: ";
    output.flush();
    input >> id;

    if(id.isEmpty())
    {
        output << "ID cannot be empty.\n";
        return;
    }

    if(findVehicleById(id) != nullptr)
    {
        output << "Duplicate ID not allowed.\n";
        return;
    }

    output << "Enter Brand: ";
    output.flush();
    input >> brand;

    output << "Enter Model: ";
    output.flush();
    input >> model;

    output << "Enter Price Per Day: ";
    output.flush();
    input >> price;

    if(choice == 1)
    {
        int doors, seats;

        output << "Enter Number of Doors: ";
        output.flush();
        input >> doors;

        output << "Enter Number of Seats: ";
        output.flush();
        input >> seats;

        Car* car = new Car(id, brand, model, price, false, doors, seats);

        vehicles.append(car);

        output << "Car added successfully.\n";
    }
    else if(choice == 2)
    {
        int engineCC;

        output << "Enter Engine Capacity CC: ";
        output.flush();
        input >> engineCC;

        Motorcycle* bike = new Motorcycle(id, brand, model, price, false, engineCC);

        vehicles.append(bike);

        output << "Motorcycle added successfully.\n";
    }
    else
    {
        output << "Invalid choice.\n";
    }
}

void VehicleRentalSystem::searchVehicle()
{
    QTextStream input(stdin);
    QTextStream output(stdout);

    QString id;

    output << "Enter Vehicle ID: ";
    output.flush();

    input >> id;

    Vehicle* v = findVehicleById(id);

    if(v == nullptr)
    {
        output << "Vehicle not found.\n";
    }
    else
    {
        output << v->toDisplayString() << "\n";
    }
}

void VehicleRentalSystem::displayAllVehicles()
{
    QTextStream output(stdout);

    if(vehicles.isEmpty())
    {
        output << "No vehicles available.\n";
        return;
    }

    for(Vehicle* v : vehicles)
    {
        output << v->toDisplayString() << "\n";
    }
}

void VehicleRentalSystem::displayAvailableVehicles()
{
    QTextStream output(stdout);

    bool found = false;

    for(Vehicle* v : vehicles)
    {
        if(!v->getIsRented())
        {
            output << v->toDisplayString() << "\n";
            found = true;
        }
    }

    if(!found)
    {
        output << "No available vehicles.\n";
    }
}

void VehicleRentalSystem::rentVehicle()
{
    QTextStream input(stdin);
    QTextStream output(stdout);

    QString id;

    output << "\nEnter Vehicle ID to rent: ";
    output.flush();

    input >> id;

    Vehicle* v = findVehicleById(id);

    if(v == nullptr)
    {
        output << "Vehicle not found.\n";
        return;
    }

    if(v->getIsRented())
    {
        output << "Vehicle is already rented.\n";
        return;
    }

    v->setIsRented(true);

    saveToFile();

    output << "Vehicle rented successfully.\n";
}

void VehicleRentalSystem::returnVehicle()
{
    QTextStream input(stdin);
    QTextStream output(stdout);

    QString id;

    output << "\nEnter Vehicle ID to return: ";
    output.flush();

    input >> id;

    Vehicle* v = findVehicleById(id);

    if(v == nullptr)
    {
        output << "Vehicle not found.\n";
        return;
    }

    if(!v->getIsRented())
    {
        output << "Vehicle is not rented.\n";
        return;
    }

    v->setIsRented(false);

    saveToFile();

    output << "Vehicle returned successfully.\n";
}

void VehicleRentalSystem::run()
{
    QTextStream input(stdin);
    QTextStream output(stdout);

    int choice = 0;

    while(choice != 7)
    {
        output << "\n===== VEHICLE RENTAL SYSTEM =====\n";
        output << "1. Add Vehicle\n";
        output << "2. Search Vehicle\n";
        output << "3. Display All Vehicles\n";
        output << "4. Display Available Vehicles\n";
        output << "5. Rent Vehicle\n";
        output << "6. Return Vehicle\n";
        output << "7. Exit\n";
        output << "Enter choice: ";
        output.flush();

        input >> choice;

        switch(choice)
        {
            case 1:
                addVehicle();
                break;

            case 2:
                searchVehicle();
                break;

            case 3:
                displayAllVehicles();
                break;

            case 4:
                displayAvailableVehicles();
                break;

            case 5:
                rentVehicle();
                break;

            case 6:
                returnVehicle();
                break;

            case 7:
                output << "Program exited.\n";
                break;

            default:
                output << "Invalid option.\n";
        }
    }
}
