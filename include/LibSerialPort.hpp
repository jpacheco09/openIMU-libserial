#ifndef LIBSERIALPORT_HPP
#define LIBSERIALPORT_HPP
#include <libserial/SerialStream.h>

#include <string>

//#include "ISerialPort.hpp"
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
    LibSerialPort(const std::string& port = "/dev/ttyUSB0") : port_address_{port} {};
    ~LibSerialPort() override;
    bool Open(const std::string& port, const PortSettings& settings) override;
    bool Open();
    void Close() override;
    std::vector<uint8_t> Read() override;
    void Write(const std::vector<uint8_t>& data) override;

private:
    LibSerial::SerialStream serial_stream_;
    PortSettings port_settings_{};
    std::string port_address_;
};

}  // namespace open_imu

#endif  // LIBSERIALPORT_HPP