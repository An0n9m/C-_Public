// Copyright (C) 2024 An0n9m. All rights reserved.

# ShellCodeConverter

ShellCodeConverter is a C++ program designed to convert raw byte sequences into shellcode and vice versa. It also provides an option to handle little-endian and big-endian formats.

## Features

- **Raw to Shellcode Conversion**: Converts a raw byte sequence into shellcode format with optional endianness.
- **Shellcode to Raw Conversion**: Converts shellcode format back into raw byte sequence with optional endianness.
- **Endianness Handling**: Supports both little-endian and big-endian formats.

## Requirements

- C++ Compiler (e.g., `g++`)

## Usage

./ShellCodeConverter [-s|-r] [-l]

### Compilation

To compile the program, use the following command:

```sh
g++ -o ShellCodeConverter ShellCodeConverter.cpp

P.S. Quite useful for CTF challenges
