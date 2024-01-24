/**
 * @file main.cpp
 * @author jebus (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-01-16
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <bits/stdint-uintn.h>
#include <libserial/SerialPort.h>
#include <libserial/SerialPortConstants.h>
#include <libserial/SerialStream.h>

#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ios>
#include <iostream>

template <typename T>
void unpackU4(uint8_t *idx, const void *buffer, T &package) {
    const unsigned char *b = (const unsigned char *)buffer;
    // printf("| 0x%02X | 0x%02X | 0x%02X | 0x%02X |\n", b[3], b[2], b[1], b[0]);
    uint32_t U4_buffer = 0;
    *idx += 4;
    U4_buffer = ((b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0]);
    package = *((T *)&U4_buffer);
}

int main() {
    LibSerial::SerialStream serial_stream;
    // define device path
    const std::string file_name("/dev/ttyUSB0");
    // open serial SerialPort
    serial_stream.Open(file_name);
    // configure serial port
    serial_stream.SetBaudRate(LibSerial::BaudRate::BAUD_115200);
    serial_stream.SetCharacterSize(LibSerial::CharacterSize::CHAR_SIZE_8);
    serial_stream.SetFlowControl(LibSerial::FlowControl::FLOW_CONTROL_NONE);
    serial_stream.SetParity(LibSerial::Parity::PARITY_NONE);
    serial_stream.SetStopBits(LibSerial::StopBits::STOP_BITS_1);

    // check for opened port
    if (serial_stream.IsOpen()) {
        std::cout << "Port " << file_name << " opened Successfully\n";
    } else {
        std::cerr << "Error opening " << file_name << std::endl;
        return EXIT_FAILURE;
    }

    std::string rx_buffer;
    const uint8_t BUFFER_SIZE = 55;
    char input_buffer[BUFFER_SIZE];
    std::memset(input_buffer, 0, sizeof(input_buffer));

    uint32_t time_ms = 0;
    uint32_t packet_header = 0;
    uint8_t buffer_idx = 0;

    float attitude_data[3] = {0.0, 0.0, 0.0};
    float linear_rate[3];
    float linear_accel[3];

    while (true) {
        if (serial_stream.IsDataAvailable()) {
            serial_stream.read(input_buffer, BUFFER_SIZE);
            unpackU4<uint32_t>(&buffer_idx, &input_buffer[buffer_idx], packet_header);
            printf("Header: %04X\n", packet_header);
            if (packet_header == 0x32615555) {
                buffer_idx++;
                /* debug print buffer
                for (char &it : input_buffer) printf("0x%02X ", (uint8_t)(it));
                printf("\n");
               */
                // unpack time_ms
                unpackU4<uint32_t>(&buffer_idx, &input_buffer[buffer_idx], time_ms);
                buffer_idx += 8;  // skip time_s
                                  // upack RP"Y" attitude
                for (auto it : attitude_data) {
                    unpackU4<float>(&buffer_idx, &input_buffer[buffer_idx], it);
                }
                // unpack linear rate
                for (auto it : attitude_data) {
                    unpackU4<float>(&buffer_idx, &input_buffer[buffer_idx], it);
                }
                // unpack linear rate
                for (auto it : linear_rate) {
                    unpackU4<float>(&buffer_idx, &input_buffer[buffer_idx], it);
                }
                // unpack linear accel
                for (auto it : linear_accel) {
                    unpackU4<float>(&buffer_idx, &input_buffer[buffer_idx], it);
                }
                // I know, that's a repeated pattern... we shall be able to refactor it

                /* print data debug */
                printf("time[ms]: %u\t", time_ms);
                printf("Roll: %f\t Pitch: %f \t Heading: %f\n", attitude_data[0], attitude_data[1], attitude_data[2]);
                printf("xrate: %f\t yrate: %f \t zrate: %f\n", linear_rate[0], linear_rate[1], linear_rate[2]);
                printf("xaccel: %f\t yaccel: %f \t zaccel: %f\n", linear_accel[0], linear_accel[1], linear_accel[2]);
            }

        } else {  // not needed, however we could admin cpu time by setting a timeout
            continue;
        }
    }
    serial_stream.Close();
    return 0;
}
