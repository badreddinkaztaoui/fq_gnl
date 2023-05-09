# get_next_line

`get_next_line` is a custom implementation of the C standard library function `getline`. It allows you to read and parse a text file line by line, regardless of the line length. This is useful when working with large files or when you need to process a file line by line.

## Table of Contents

- [Getting Started](#getting-started)
- [Usage](#usage)
- [Function Documentation](#function-documentation)
- [Contributing](#contributing)
- [License](#license)

## Getting Started

To use `get_next_line`, you'll need to download the source code and compile it into a library. Here's how to get started:

1. Clone the repository: `git clone https://github.com/badreddinkaztaoui/get_next_line`
2. Compile the code: `cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c`

## Usage

Once you've linked the library to your project, you can use `get_next_line` to read and parse text files line by line. Here's an example of how to use `get_next_line`:

```c
#include "get_next_line.h"

int main() {
  int fd = open("example.txt", O_RDONLY);
  char *line;

  while (get_next_line(fd, &line)) {
    printf("%s\n", line);
    free(line);
  }

  close(fd);

  return 0;
}
```

This will read the file `example.txt` line by line and print each line to the console.

`get_next_line` supports reading from multiple file descriptors at the same time, so you can use it to process multiple files in parallel. See the [Function Documentation](#function-documentation) section for a full list of functions and their parameters.

## Function Documentation

`get_next_line` consists of several functions that work together to read and parse text files. Here's a brief overview of each function:

- `get_next_line`: The main function that reads a line of text from a file descriptor and returns it as a string. It takes a file descriptor and a         pointer to a string as parameters, and returns 1 if a line was read, 0 if the end of the file was reached, or -1 if an error occurred.

- `read_file`:  A helper function that reads a file from a given file descriptor fd and stores its contents in a string called stash. It reads the file                   in chunks of BUFFER_SIZE bytes at a time and concatenates each chunk to the stash string until it finds a newline character or reaches                   the end of the file.
                The function uses a helper function called newline_exist to check if the stash string contains a newline character. If it does, the                       function stops reading the file and returns the stash string. If not, it continues reading the file until it finds a newline or reaches                   the end of the file.
                The function returns a pointer to the stash string, which contains the contents of the file up to the first newline character.

- `ft_get_line`: A helper function takes a string called stash as input and extracts the next line from it. The stash string is assumed to contain one or                  more lines of text, separated by newline characters (\n).
                 The function first calculates the length of the next line by searching for the first newline character in the stash string. It then                      allocates a new string called line that is one character longer than the next line, to accommodate the newline character and the null                    terminator.
                 The function then copies the next line from stash to line, character by character, until it reaches the newline character or the end of                  stash. If the next line ends with a newline character, the function copies it to line and increments the index i to skip over the n                      newline character.
                 Finally, the function adds a null terminator to the end of line and returns a pointer to the new string.

- `ft_get_rest`: A helper function that takes two strings as input: stash, which contains the remaining text in a file after a line has been extracted                    using ft_get_line, and line, which contains the line that was just extracted.
                 The function first calculates the length of the extracted line using the ft_strlen function. It then checks if there is any remaining                    text in stash after the line has been extracted. If there isn't, the function frees the stash string and returns NULL.
                 If there is remaining text in stash, the function calculates the length of the remaining text and allocates a new string called rest to                  store it. rest is one character longer than the remaining text to accommodate the null terminator.

- `ft_strjoin`: A helper function that concatenates two strings into a new string.

- `ft_strjoin`: A helper function that concatenates two strings into a new string.

- `ft_strjoin`: A helper function that concatenates two strings into a new string.

- `ft_strlen`: A helper function that returns the length of a string.

- `ft_calloc`: A helper function that create a string with a choosen length and fill it with '\0'.

- `newline_exist`: A helper function that searches a string for a new line character '\n'.

See the [get_next_line.h](https://github.com/badreddinkaztaoui/get_next_line/blob/main/get_next_line.h) header file for a full list of functions and their parameters.

## Bonus part

...

## Contributing

If you'd like to contribute to `get_next_line`, you can open a pull request on GitHub. Please make sure your code follows the [Coding Standards](https://github.com/badreddinkaztaoui/get_next_line/blob/master/docs/coding_standards.md) and includes tests for any new features or bug fixes.

## License

`get_next_line` is released under the [MIT License](https://github.com/badreddinkaztaoui/get_next_line/blob/master/LICENSE).
