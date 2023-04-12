[![CI][ci-badge]][ci-link]
[![Coverage][codecov-badge]][codecov-link]

## A Cayenne LPP library written in C

This library provides functions for generating Cayenne LPP compatible payload.
For example, the generated payloads can be used with LoRaWAN devices.

This library is adapted from
[the C++ version from MBED](https://developer.mbed.org/teams/myDevicesIoT/code/Cayenne-LPP/).

See [the Cayenne LPP format documentation](https://docs.mydevices.com/docs/lorawan/cayenne-lpp)
for details on the payload format.

## Build and run the example application

Simply use `make`:

    $ make && ./example/example
    03 67 01 10 05 67 00 FF
    01 67 FF D7 06 71 04 D2 FB 2E 00 00
    01 88 06 76 5E F2 96 0A 00 03 E8

## Reference API

Read the reference API here: https://aabadie.github.io/cayenne-lpp

## License

The library is licensed under LGPLv2.1.

[ci-badge]: https://github.com/aabadie/cayenne-lpp/workflows/CI/badge.svg
[ci-link]: https://github.com/aabadie/cayenne-lpp/actions?query=workflow%3ACI+branch%3Amain
[codecov-badge]: https://codecov.io/gh/aabadie/cayenne-lpp/branch/main/graph/badge.svg
[codecov-link]: https://codecov.io/gh/aabadie/cayenne-lpp
