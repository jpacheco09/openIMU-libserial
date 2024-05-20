#include "LibSerialPort.hpp"

#include <iostream>
//#include <string>

open_imu::LibSerialPort::LibSerialPort(const std::string& port) : port_address_{port} {
    std::cout << " got: " << port_address_ << '\n';
}

open_imu::LibSerialPort::~LibSerialPort() = default;

bool open_imu::LibSerialPort::Open(const std::string& port, const PortSettings& settings) {
    std::cout << "Opening: " << port << "port\n";
    std::cout << "Baudrate: " << int(settings.baud_rate) << '\n'
              << "Data bits: " << settings.data_bits << '\n'
              << "Flow control: " << settings.flow_control << '\n'
              << "Parity: " << settings.parity << '\n'
              << "Stop bits: " << settings.stop_bits << '\n';
    return false;
}

bool open_imu::LibSerialPort::Open() { return open_imu::LibSerialPort::Open(port_address_, port_settings_); }

void open_imu::LibSerialPort::Close() { std::cout << "Closing port: " << port_address_ << '\n'; }

void open_imu::LibSerialPort::Write(const std::vector<uint8_t>& data) {
    std::cout << "Writing to port: " << port_address_ << "n:" << data.size() << "bytes\n";
}
std::vector<uint8_t> open_imu::LibSerialPort::Read() {
    std::cout << "Reading from port: " << port_address_ << '\n';
    return {};
}