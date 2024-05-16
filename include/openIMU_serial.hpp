
#include <bits/stdint-uintn.h>
#include <libserial/SerialPortConstants.h>

#include <array>
#include <string>
#include <vector>
namespace open_imu {
class Description {
public:
    Description(const std::string& device_route) : deviceRoute(device_route){};
    Description() = default;
    ~Description() = default;

public:
    std::string deviceRoute{"/dev/ttyUSB0"};
    const LibSerial::BaudRate baudRate{LibSerial::BaudRate::BAUD_115200};
    const LibSerial::CharacterSize characterSize{LibSerial::CharacterSize::CHAR_SIZE_8};
    const LibSerial::FlowControl flowControl{LibSerial::FlowControl::FLOW_CONTROL_NONE};
    const LibSerial::StopBits stopBits{LibSerial::StopBits::STOP_BITS_1};
};
class Device {
public:
    Device(const std::string& device_route) : device_description_{device_route}, DataBuffer_(kBufferSize_, 0) {
        OpenDevice();
    };
    ~Device() { CloseDevice(); };

public:
    [[nodiscard]] bool IsOpen() const;
    void GetNewPackage();

private:
    void OpenDevice() const;
    void CloseDevice() const;
    void GetData();
    void ReadData();
    template <typename T>
    UnpackRawData();

private:
    const unsigned long kBufferSize_ = 255;
    Description device_description_;
    std::vector<uint8_t> DataBuffer_;
};

enum class PACKAGE_TYPE : uint16_t { A1 = 0x6131, A2 = 0x6132, Z1 = 0x7A31, S1 = 0x7331 };
constexpr uint16_t HEADER = 0x5555;  // NOLINT
}  // namespace open_imu
