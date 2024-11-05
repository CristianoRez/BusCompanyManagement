#include <iostream>
#include <string>
#include "Bus.hpp"

Bus::Bus(std::string licensePlate, int maximumCapacity) {
    this->_licensePlate = licensePlate;
    this->_maximumCapacity = maximumCapacity;
    this->_currentCapacity = 0;
}

bool Bus::boardPassengers(int numberOfPassengers) {
    if (this->_currentCapacity + numberOfPassengers <= this->_maximumCapacity) {
        this->_currentCapacity += numberOfPassengers;
        return true;
    } else return false;
}

bool Bus::disembarkPassengers(int numberOfPassengers) {
    if (this->_currentCapacity - numberOfPassengers < 0) {
        return false;
    } else {
        _currentCapacity -= numberOfPassengers;
        return true;
    }
}

bool Bus::transferPassengers(Bus* newBus, int connectingPassengers) {
    if (newBus->_currentCapacity + connectingPassengers < newBus->_maximumCapacity) {
        this->_currentCapacity -= connectingPassengers;
        newBus->_currentCapacity += connectingPassengers;
        return true;
    } else return false;
}

void Bus::printStatus() const {
    std::cout << _licensePlate << "(" << _currentCapacity << "/" << _maximumCapacity << ")" << std::endl;
}