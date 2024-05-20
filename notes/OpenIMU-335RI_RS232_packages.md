| Byte Offset | Name     | Format | Units | Description                           |
|-------------|----------|--------|-------|---------------------------------------|
| 0           | Time_ms  | U4     | ms    | System Timer at the moment of sensors sampling |
| 4           | Time_s   | D      | s     | System Timer at the moment of sensors sampling |
| 12          | Roll     | F4     | °     | Roll angle                            |
| 16          | Pitch    | F4     | °     | Pitch angle                           |
| 20          | Heading  | F4     | °     | Yaw/Heading angle                     |
| 24          | xRate    | F4     | °/sec | Rotation speed for axis X             |
| 28          | yRate    | F4     | °/sec | Rotation speed for axis Y             |
| 32          | zRate    | F4     | °/sec | Rotation speed for axis Z             |
| 36          | xAccel   | F4     | m/s^2 | Acceleration value for axis X         |
| 40          | yAccel   | F4     | m/s^2 | Acceleration value for axis Y         |
| 44          | zAccel   | F4     | m/s^2 | Acceleration value for axis Z         |

Data types

| Descriptor | Description        | Size (bytes) | Comment                     | Range               |
|------------|--------------------|--------------|-----------------------------|---------------------|
| U1         | Unsigned Char      | 1            | n/a                         | 0 to 255            |
| U2         | Unsigned Short     | 2            | n/a                         | 0 to 65535          |
| U4         | Unsigned Int       | 4            | n/a                         | 0 to 2^32-1         |
| I2         | Signed Short       | 2            | 2’s Complement              | -2^15 to 2^15-1     |
| I2*        | Signed Short       | 2            | Shifted 2’s                 | -2^31 to 2^31-1     |
| I4         | Signed Int         | 4            | 2’s Complement              | -1*2^127 to 2^127   |
| F4         | Floating Point     | 4            | IEEE754 Single Precision    | 2.23^-308 to        |
| D          | Double             | 8            | IEEE-754 Double Precision   | 1.80^308            |
| SN         | String             | N            | ASCII                       | n/a                 |
