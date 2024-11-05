#include <iostream>
#include <string>
#include "Company.hpp"

Company::Company() {
    this->_numberOfBuses = 0;
    for (int i = 0; i < 20; i++) {
        this->_buses[i] = nullptr;
    }
}

Company::~Company() {
    for (int i = 0; i < _numberOfBuses; i++) {
        delete _buses[i];
        _buses[i] = nullptr;
    }
}

Bus* Company::addBus(std::string licensePlate, int maximumCapacity) {
    if (_numberOfBuses >= 20) return nullptr; 
    
    for (int i = 0; i < this->_numberOfBuses; i++) {
        if (this->_buses[i]->_licensePlate == licensePlate) return nullptr;
    }

    Bus* bus = new Bus(licensePlate, maximumCapacity);
    this->_buses[_numberOfBuses] = bus;
    this->_numberOfBuses++;

    return bus;
}

Bus* Company::searchBus(std::string licensePlate) const {
    for (int i = 0; i < this->_numberOfBuses; i++) {
        if (_buses[i]->_licensePlate == licensePlate) return _buses[i];
    }

    return nullptr;
}

void Company::printStatus() const {
    for (int i = 0; i < this->_numberOfBuses; i++) {
        std::cout 
            << _buses[i]->_licensePlate 
            << "(" << _buses[i]->_currentCapacity 
            << "/" << _buses[i]->_maximumCapacity 
            << ")" << std::endl;
    }
}