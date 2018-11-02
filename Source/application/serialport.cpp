/*
* Author: Manash Kumar Mandal
* Modified Library introduced in Arduino Playground which does not work
* This works perfectly
* LICENSE: MIT
*/

#include "serialPort.hpp"

cSerialPort::cSerialPort()  :
    connected(false), portName(""), dcbSerialParameters({0})
{
    dcbSerialParameters.BaudRate = 9600;
    dcbSerialParameters.ByteSize = 8;
    dcbSerialParameters.StopBits = ONESTOPBIT;
    dcbSerialParameters.Parity = NOPARITY;
    dcbSerialParameters.fDtrControl = DTR_CONTROL_DISABLE;
}

void cSerialPort::connect()
{
    connected = false;

    const char *cstrPortName = portName.c_str();
    handler = CreateFileA(static_cast<LPCSTR>(cstrPortName), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (handler == INVALID_HANDLE_VALUE)
    {
        auto error = GetLastError();
        switch (error)
        {
        case ERROR_FILE_NOT_FOUND:
            std::cout << "ERROR: Handle was not attached. Reason: " << portName << " not available.\n";
            break;
        case ERROR_ACCESS_DENIED:
            std::cout << "Error: Handle was not attached." << portName << " already opened.\n";
            break;
        default:
            std::cout << "ERROR\n";
            break;
        }
        return;
    }
    else
    {
        if (!GetCommState(handler, &dcbSerialParameters))
        {
            std::cout << "Failed to get current serial parameters.\n";
        }
        else
        {
            if (!SetCommState(handler, &dcbSerialParameters))
            {
                std::cout << "ALERT: could not set Serial port parameters\n";
            }
            else
            {
                std::cout << "Connected on " << portName << "\n";
                connected = true;
                PurgeComm(handler, PURGE_RXCLEAR | PURGE_TXCLEAR);
            }
        }
    }
}

void cSerialPort::disconnect()
{
    connected = false;
    CloseHandle(handler);
}

cSerialPort::~cSerialPort()
{
    if(connected)
    {
        connected = false;
        CloseHandle(handler);
    }
}

void cSerialPort::setPortName(const std::string &name)
{
    portName = name;
}

bool cSerialPort::isConnected() const
{
    return connected;
}

void cSerialPort::queryPorts()
{
    std::cout << "Query Ports\n";
    TCHAR buffer[500];

    portsAvailable.clear();
    for(int i = 0; i<16; i++)
    {
        std::string portToTry = "COM" + std::to_string(i);
        DWORD test = QueryDosDevice(portToTry.c_str(), (LPSTR)buffer, 500);

        if(test != 0)
        {
            portsAvailable.push_back(portToTry);
        }
        if(::GetLastError()==ERROR_INSUFFICIENT_BUFFER)
        {
            std::cout << "queryPorts insufficient buffer\n";
        }
    }
}

const std::vector<std::string>& cSerialPort::getAvailablePorts() const
{
    return portsAvailable;
}

int cSerialPort::read(char *buffer, unsigned int buf_size)
{
    DWORD bytesRead;
    unsigned int toRead = 0;

    ClearCommError(handler, &errors, &status);

    if (status.cbInQue > 0)
    {
        if (status.cbInQue > buf_size)
            toRead = buf_size;
        else
            toRead = status.cbInQue;
    }

    if (ReadFile(handler, buffer, toRead, &bytesRead, NULL))
        return bytesRead;

    return 0;
}

bool cSerialPort::write(char *buffer, unsigned int buf_size)
{
    DWORD bytesSend;

    if (!WriteFile(handler, (void*) buffer, buf_size, &bytesSend, 0))
    {
        ClearCommError(handler, &errors, &status);
        return false;
    }
    else
        return true;
}

void cSerialPort::setBaudRate(uint32_t baudrate)
{
    dcbSerialParameters.BaudRate = baudrate;
}

void cSerialPort::setByteSize(uint32_t bytesize)
{
    dcbSerialParameters.ByteSize = bytesize;
}

void cSerialPort::setParity(uint32_t parity)
{
    dcbSerialParameters.Parity = parity;
}

void cSerialPort::setStopBits(uint32_t stopbits)
{
    dcbSerialParameters.StopBits = stopbits;
}

void cSerialPort::setDTR(uint32_t dtr)
{
    dcbSerialParameters.fDtrControl = dtr;
}
