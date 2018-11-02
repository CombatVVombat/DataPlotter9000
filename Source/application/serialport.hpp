#ifndef SERIALPORT_HPP_INCLUDED
#define SERIALPORT_HPP_INCLUDED

/*
* Author: Manash Kumar Mandal
* Modified Library introduced in Arduino Playground which does not work
* This works perfectly
* LICENSE: MIT
*/

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

class cSerialPort
{
private:
    HANDLE handler;
    bool connected;
    COMSTAT status;
    DWORD errors;
    std::vector<std::string> portsAvailable;
    std::string portName;
    DCB dcbSerialParameters;
public:
    cSerialPort();
    ~cSerialPort();

    void connect();
    void disconnect();
    void queryPorts();
    int read(char *buffer, unsigned int buf_size);
    bool write(char *buffer, unsigned int buf_size);

    // Getter Spam
    const std::vector<std::string>& getAvailablePorts() const;
    bool isConnected() const;

    // Setter Spam
    void setPortName(const std::string &name);
    void setBaudRate(uint32_t baudrate);
    void setByteSize(uint32_t bytesize);
    void setParity(uint32_t parity);
    void setStopBits(uint32_t stopbits);
    void setDTR(uint32_t dtr);

};

#endif // SERIALPORT_HPP_INCLUDED
