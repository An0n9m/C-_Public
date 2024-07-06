// Copyright (C) 2024 An0n9m. All rights reserved.

# Strong Password Generator

This project is a simple C++ application to generate strong, random passwords. The password generator ensures that the generated password does not include any blacklisted characters and is of a specified length.

## Features

- Generates a password of specified length (between 4 and 66 characters).
- Ensures no character repeats within the password.
- Excludes blacklisted characters from the password.

## Requirements

- C++11 or later.

## Usage

### Compilation

To compile the project, use the following command:

g++ -o pass PasswordGenerator.cpp
