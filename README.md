Absolutely, let's refine and enhance the readability of the `README.md`.

---

# PLIB

## Overview:

PLIB is a C project designed to create a user-friendly library of functions. Its primary goal is ease of use, comprehension, and readability rather than prioritizing performance. The aim is to offer essential building blocks akin to those found in high-level languages like Python, without the typical complexities associated with C libraries.

Developed by students of 42, PLIB adheres strictly to the school's NORME, serving as the foundation for 42's projects.

## Usage:

To get started:

1. Clone the repository:
    ```bash
    git clone https://github.com/pierrelgol/plib.git
    ```

2. Navigate to the directory:
    ```bash
    cd plib
    ```

3. Build the library:
    ```bash
    make release
    ```

Once built, copy `plib.h` and `libplib.a` to your project directory, and compile using:
```bash
gcc my_project.c -libplib.a
```

# Contribution Guidelines

## Getting Started:

- Ensure you have a GitHub account.
- Fork the repository on GitHub.
- Clone your forked repository locally: `git clone https://github.com/your-username/plib.git`
- Create a new branch for your work: `git checkout -b feature-name`

## How to Contribute:

1. **Bug Fixes or Feature Requests**:
   - Check the issue tracker for existing issues or create a new one if necessary.
   - Fork the repository, create a new branch, make changes, test thoroughly, and submit a pull request referencing the related issue.

2. **Code Style**:
   - Adhere to the project's coding style and guidelines.
   - Ensure code readability and maintainability, along with necessary documentation.

3. **Documentation**:
   - Enhance the project's documentation, providing clear and concise explanations as needed.

4. **Testing**:
   - Include relevant tests for new features or bug fixes and ensure all existing tests pass.

## Pull Requests:

- Submit pull requests against the `main` branch.
- Provide a descriptive title and a clear description of the changes made.
- Mention related issues in the pull request.

Thank you for considering contributing to PLIB!

# Code Styling Guide

## Module Naming:

- Descriptive, concise, and simple module names in lowercase letters only.
- Each module should have its own section in `plib.h`.

Example:
```c
/*############################################################################*/
/*                                [PlibModuleName]                                */
/*############################################################################*/
```

## File Naming:

- File names must match the function's definition in `plib.h`.

Example:
```c
// Functions within the string module should reside in string_append_back.c
char *string_append_back(char *str1, char *str2);
```

## Function Naming:

- Functions should start with the prefix of their module.
- Use only prescribed verbs for function names to maintain consistency and clarity.
- Descriptive argument names are encouraged.

```c
/*
create       : Instantiate and perform memory allocation.
destroy      : Deinstantiate and release memory allocation.
copy         : Place the content of 'src' into 'dst' without memory allocation.
clone        : Generate a duplicate of 'src' without altering the original.
count        : Determine the number of occurrences of something.
compare      : Compare two instances of something.
concat       : Append the content of 'src' after 'dst' without additional memory allocations.
contains     : Return a boolean indicating if something exists within something else.
join         : Create memory and concatenate two elements.
length       : Retrieve the length of something (where length signifies within).
size         : Obtain the size of something (where size signifies the container's size).
ends_with    : Verify if something ends with something else.
starts_with  : Verify if something starts with something else.
index_of     : Retrieve the index of something within another something.
assert       : Return a boolean indicating if something conforms to specified criteria.
slice        : Return a duplicate subset of something.
search       : Look for something within another something.
map          : Apply a function to something consistently.
filter       : Return a filtered duplicate of something.
pad          : Return a padded duplicate of something.
trim         : Remove something from both ends of another something.
random       : Generate a pseudo-random value or object.
reverse      : Reverse the order of elements within something.
strip        : Remove something if it exists.
sort         : Arrange elements within something in a specific order.
split        : Divide something and produce additional entities.
set          : Alter something to become something else.
get          : Retrieve or obtain something.
apply        : Use functions to enact modifications on something.
is           : Provide a boolean evaluation (returns 0 or 1).
to           : Transform something into something else.
insert       : Create a new element and place it within something.
remove       : Eliminate an element from something.
append       : Add something to another something.
push         : Insert an existing element into something.
pop          : Remove an element without destroying it from something.
rotate       : Move something into a shifted version of itself.
*/
```

## General Principles:

- Code simplicity is key.
- DRY (Don't Repeat Yourself) principle is encouraged where applicable.
- Comments are omitted in favor of code readability.
- Variants are welcome when logical (e.g., left/right/front/back, etc.).
- Prioritize readability and usability over performance.

## Priority for Contribution:

- 1 -> Enhancing test coverage.
- 2 -> Introducing new features, functions, and data structures.
- 3 -> Ensuring naming consistency and refactoring.
- 4 -> Providing comprehensive documentation.
- 5 -> Enhancing the build system.

---

This revised version aims for clearer sections, concise instructions, and a more structured presentation of guidelines and conventions. Feel free to adjust or expand upon any section to better fit the project's needs!
