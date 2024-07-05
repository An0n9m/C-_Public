// Copyright (C) 2024 An0n9m. All rights reserved.
# RootFinder

A C++ program to find the roots of a function using different numerical methods: Bisection, False Position, and Secant. The program allows you to test and compare the efficiency of these methods.

## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Methods](#methods)
- [Code Explanation](#code-explanation)
- [Contributing](#contributing)
- [License](#license)

## Features

- Three root-finding methods: Bisection, False Position, and Secant
- Compare the number of iterations for each method
- Easy to integrate with any continuous function

## Getting Started

### Prerequisites

To compile and run this program, you need:

- A C++ compiler (e.g., `g++`)
- A command-line interface (CLI)
Usage
Define the function you want to find the roots for in the func function.
Set the interval [min, max] where you want to find the root.
Set the precision for the root-finding methods.
Compile and run the program to see the roots and the number of iterations for each method.
Methods
The program implements the following root-finding methods:

Bisection Method: A simple and robust method that repeatedly bisects the interval and selects the subinterval that contains the root.
False Position Method: A method that uses a linear interpolation to approximate the root.
Secant Method: A method that uses the secant line to approximate the root.
The program also includes a combined method that uses Bisection to find a rough estimate and then Secant to refine it.
