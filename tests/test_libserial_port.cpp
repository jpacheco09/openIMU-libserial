#include <catch2/catch_all.hpp>
#include <catch2/catch_test_macros.hpp>

#include "LibSerialPort.hpp"
TEST_CASE("open_imu::Libserial can interface with the serial device", "[LibSerialPort]") {
    SECTION("Initialize providing a Port") { open_imu::LibSerialPort serial_port("/dev/ttyUSB0"); }
    SECTION("Initialize empty constructor") { open_imu::LibSerialPort serial_port; }
    SECTION("Open method works for correct port") {
        open_imu::LibSerialPort serial_port("/dev/ttyUSB0");
        REQUIRE(serial_port.Open() == true);
    }
}  // TEST_CASE open port