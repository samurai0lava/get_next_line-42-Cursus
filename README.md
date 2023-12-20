# get_next_line Project

This project provides an implementation of the `get_next_line` function, which reads a line from a file descriptor.

## Table of Contents

- [Introduction](#introduction)
- [Usage](#usage)
- [Function Descriptions](#function-descriptions)
- [Building and Running](#building-and-running)
- [Testing](#testing)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The `get_next_line` function reads a line from a file descriptor and returns it as a string. It is useful for reading and processing files line by line.

## Usage

To use this function, include the `get_next_line.h` header file in your project and call the `get_next_line` function as needed.

```c
#include "get_next_line.h"

int main(void) {
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        // Process the line as needed
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}
