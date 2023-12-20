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
s
## Function Descriptions

### `char *get_next_line(int fd)`

- Reads a line from the specified file descriptor.
- Returns a dynamically allocated string containing the line.
- Returns `NULL` upon reaching the end of the file or encountering an error.

### `static char *ft_strjoin(char *s1, char *s2)`

- Concatenates two strings (`s1` and `s2`) into a new string.
- Frees the memory allocated for `s1`.

### `static char *rest(char *str)`

- Extracts the remaining content after a newline character in the string.
- Frees the original string.

### `static char *read_line(int fd, char *content)`

- Reads lines from the file descriptor until a newline character is found.
- Dynamically allocates memory to store the content.
- Returns the content as a string.

### `static char *extract_line(char *content)`

- Extracts a line from the content.
- Allocates exactly the required space for the line.

## Building and Running

To build the project, you can use a standard compilation command. For example:

```bash
gcc -o your_executable_name your_source_file.c get_next_line.c -Wall -Wextra -Werror -D BUFFER_SIZE=32
