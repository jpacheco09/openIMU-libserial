#ifndef OPENIMU_CONSTANTS_HPP
#define OPENIMU_CONSTANTS_HPP

#include <bits/stdint-uintn.h>
namespace open_imu {
enum class PACKAGE_TYPE : uint16_t { A1 = 0x6131, A2 = 0x6132, Z1 = 0x7A31, S1 = 0x7331 };  // NOLINT
enum class COMMANDS : uint16_t { ping = 0x7047, get_parameter = 0x6750 };
constexpr uint16_t kHeader = 0x5555;  // NOLINT
enum class BAUD_RATE : unsigned int { BR_38400 = 38400, BR_57600 = 57600, BR_115200 = 115200, BR_230400 = 230400 };  //
}  // namespace open_imu

#endif  // OPENIMU_CONSTANTS_HPP