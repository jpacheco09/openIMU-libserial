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
    LibSerial::SerialPort serial_port;
    LibSerial::SerialStream serial_stream;

    // open serial SerialPort
    const std::string file_name("/dev/ttyUSB0");

    /* serial_port.Open(file_name);
     // configure serial port
     serial_port.SetBaudRate(LibSerial::BaudRate::BAUD_115200);
     serial_port.SetCharacterSize(LibSerial::CharacterSize::CHAR_SIZE_8);
     serial_port.SetFlowControl(LibSerial::FlowControl::FLOW_CONTROL_NONE);
     serial_port.SetParity(LibSerial::Parity::PARITY_NONE);
     serial_port.SetStopBits(LibSerial::StopBits::STOP_BITS_1);
 */
    // open serial SerialPort
    serial_stream.Open(file_name);
    // configure serial port
    serial_stream.SetBaudRate(LibSerial::BaudRate::BAUD_115200);
    serial_stream.SetCharacterSize(LibSerial::CharacterSize::CHAR_SIZE_8);
    serial_stream.SetFlowControl(LibSerial::FlowControl::FLOW_CONTROL_NONE);
    serial_stream.SetParity(LibSerial::Parity::PARITY_NONE);
    serial_stream.SetStopBits(LibSerial::StopBits::STOP_BITS_1);

    // check for opened port
    /*if (serial_port.IsOpen()) {
        std::cout << "Port " << file_name << " opened Successfully\n";
    } else {
        std::cerr << "Error opening " << file_name << std::endl;
        return EXIT_FAILURE;
    }*/
    size_t timeout_milliseconds = 25;
    std::string rx_buffer;
    const uint8_t BUFFER_SIZE = 55;
    char input_buffer[BUFFER_SIZE];
    memset(input_buffer, 0, sizeof(input_buffer));
    // input_buffer.reserve(static_cast<size_t>(BUFFER_SIZE));
    // serial_port.Read(input_buffer, BUFFER_SIZE, timeout_milliseconds);

    uint32_t time_ms = 0;
    uint8_t time_idx = 0;
    float roll = 0;
    float pitch = 0;
    float heading = 0;
    float attitude_data[3] = {0.0, 0.0, 0.0};
    float linear_rate[3];
    float linear_accel[3];

    uint8_t payload_data_init_idx = 0;
    while (true) {
        if (serial_stream.IsDataAvailable()) {
            serial_stream.read(input_buffer, BUFFER_SIZE);
            if (((input_buffer[0] << 8) | (input_buffer[1])) == 0x5555) {
                /* debug print buffer 
                for (char &it : input_buffer) printf("0x%02X ", (uint8_t)(it));
                printf("\n");
               */ 

                payload_data_init_idx = 17;

                time_idx = 5;
                /*
                roll = unpackFloat(&attitude_idx, &input_buffer[attitude_idx]);
                pitch = unpackFloat(&attitude_idx, &input_buffer[attitude_idx]);
                heading = unpackFloat(&attitude_idx, &input_buffer[attitude_idx]);
                */
                // retrive time_ms
                unpackU4<uint32_t>(&time_idx, &input_buffer[time_idx], time_ms);
                // retrive attitude_data
                for (int j = 0; j < 3; j++)
                    unpackU4<float>(&payload_data_init_idx, &input_buffer[payload_data_init_idx], attitude_data[j]);
                // retrive linear_rate
                for (int j = 0; j < 3; j++)
                    unpackU4<float>(&payload_data_init_idx, &input_buffer[payload_data_init_idx], linear_rate[j]);
                // retrive linear_accel_rate
                for (int j = 0; j < 3; j++)
                    unpackU4<float>(&payload_data_init_idx, &input_buffer[payload_data_init_idx], linear_accel[j]);

                /* print data debug */
                printf("time[ms]: %u\t", time_ms);
                printf("Roll: %f\t Pitch: %f \t Heading: %f\n", attitude_data[0], attitude_data[1], attitude_data[2]);
                printf("xrate: %f\t yrate: %f \t zrate: %f\n", linear_rate[0], linear_rate[1],linear_rate[2]);
                printf("xaccel: %f\t yaccel: %f \t zaccel: %f\n", linear_accel[0], linear_accel[1], linear_accel[2]);
                                
            }

        } else {
            continue;
        }
    }
    serial_stream.Close();
    return 0;
}
