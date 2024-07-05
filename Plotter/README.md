// Copyright (C) 2024 An0n9m. All rights reserved.
# Drawable Project

This project demonstrates a simple C++ application for drawing graphs and histograms using a base `Drawable` class and its derived classes `Graph` and `Histo`.

## Classes

### Drawable

`Drawable` is a base class providing common functionality for drawing objects. It includes methods for printing, drawing, and managing data points.

### Graph

`Graph` is a derived class from `Drawable` that allows for adding, setting, and sorting data points, and provides functionality for drawing graphs.

### Histo

`Histo` is a derived class from `Drawable` that represents histograms. It provides methods for filling histogram bins, clearing data, and calculating statistical properties such as the integral, mean, and RMS.

## Usage

### Graph

To create and draw a graph:
```cpp
Graph gr("graph");

for (double i = 0; i < 10; i += 0.001) {
    gr.AddPoint(i, std::sin(i), std::sqrt(std::sin(i)));
}

gr.Draw();

