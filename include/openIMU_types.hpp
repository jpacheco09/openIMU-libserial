#ifndef OPENIMU_TYPES_HPP
#define OPENIMU_TYPES_HPP

#include <bits/stdint-uintn.h>

#include "openIMU_constants.hpp"
namespace open_imu {
struct Attitude {
    float Roll_deg;
    float Pitch_deg;
    float Heading_deg;
};

struct Rate {
    float xRate_deg_s;
    float yRate_deg_s;
    float zRate_deg_s;
};

struct Acceleration {
    float xAccel_m_s2;
    float yAccel_m_s2;
    float zAccel_m_s2;
};

struct VGAHRSData {
    uint32_t Time_ms;
    double Time_s;
    Attitude attitude;
    Rate rate;
    Acceleration acceleration;
};

struct PortSettings {
    BAUD_RATE baud_rate{BAUD_RATE::BR_115200};
    bool parity{false};
    int stop_bits{1};
    bool flow_control{false};
    uint8_t data_bits{8};
};

class DataPacket {
public:
    virtual ~DataPacket() = default;

    // Add common methods for all data packets here
};

class VGAHRSDataPacket : public DataPacket {
public:
    VGAHRSData data;
    // Add methods specific to VGAHRSDataPacket here
};

}  // namespace open_imu
#endif  // OPENIMU_TYPES_HPP
