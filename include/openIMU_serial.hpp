
#ifndef OPENIMU_SERIAL_HPP
#define OPENIMU_SERIAL_HPP

#include <bits/stdint-uintn.h>
#include <libserial/SerialStream.h>

#include <array>
#include <memory>
#include <string>
#include <vector>

#include "openIMU_types.hpp"

namespace open_imu {

class ISerialPort {
public:
    virtual ~ISerialPort() = default;

    virtual bool Open(const std::string& port, const PortSettings& settings) = 0;
    virtual void Close() = 0;
    virtual std::vector<uint8_t> Read() = 0;
    virtual void Write(const std::vector<uint8_t>& data) = 0;
};

class LibSerialPort : public ISerialPort {
public:
    LibSerialPort();
    ~LibSerialPort() override;

    bool Open(const std::string& port, const PortSettings& settings) override;
    void Close() override;
    std::vector<uint8_t> Read() override;
    void Write(const std::vector<uint8_t>& data) override;

private:
    LibSerial::SerialStream serial_stream_;
};

class OpenIMU {
public:
    OpenIMU(std::unique_ptr<ISerialPort> serial_port);  // constructor
    ~OpenIMU();                                         // destructor

    // Connect to the OpenIMU device
    bool Connect(const std::string& port, const PortSettings& settings);

    // Disconnect from the OpenIMU device
    void Disconnect();

    // Read data from the OpenIMU device
    std::unique_ptr<DataPacket> ReadData();

private:
    // Handle to the serial port
    std::unique_ptr<ISerialPort> serial_port_;
};

}  // namespace open_imu
#endif  // OPENIMU_SERIAL_HPP