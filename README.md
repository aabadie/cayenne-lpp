## Cayenne LPP library

This library provides functions for generating Cayenne LPP compatible payload.
For example, the generated payloads can be used with LoRaWAN devices.

This library is adapted from
[the C++ version from MBED](https://developer.mbed.org/teams/myDevicesIoT/code/Cayenne-LPP/).

See [the Cayenne LPP documentation](https://github.com/myDevicesIoT/cayenne-docs/blob/master/docs/LORA.md)
for details on the payload format.

## Build and run the test application

Simply use `make`:

    $ cd tests
    $ make
    $ ./test
    Buffer 1:
    01-67-00-E1-02-67-29-E2-03-68-55-04-65-01-2C-05-88-07-FD-D8-00-BE-E1-00-00-C8
    ----------------------------------
    Buffer 2:
    01-00-2A-01-01-7B-01-02-00-01-01-03-00-05
    ----------------------------------
    Buffer 3:
    01-66-01-03-71-01-F4-01-A4-00-64-04-86-00-1E-00-28-00-32
    ----------------------------------
    Empty buffer:

## License

The library is licensed under LGPLv2.1.
