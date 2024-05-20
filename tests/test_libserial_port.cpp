#include <catch2/catch_all.hpp>
#include <catch2/catch_test_macros.hpp>

#include "LibSerialPort.hpp"
TEST_CASE("Libserial can open a port correctly", "[LibSerialPort]") {
    open_imu::LibSerialPort serial_port;

    REQUIRE(serial_port.Open() == false);

    // serial_port.Close();
}  // TEST_CASE open port