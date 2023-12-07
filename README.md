# PLIB

## What is PLIB :

PLIB is a project in C to create a library of functions that are easy to use, easy to understand, easy to read and easy to work with. Performance is not the primary concern of that library. The goal is to provide all the necessary building blocks that you would get in high level language like python, without all the usual fluff that comes with C libraries in general.

On top of that this library is made by 42's students, for 42's students. This means that the code has to comply and respect the NORME of 42's school. This is the most important aspect of it. As this library is supposed to be the basis for any 42's project.

## How to use it :

First you need to clone the repo :
```Bash
git clone https://github.com/pierrelgol/plib.git
```
Then you need to go in the directory :
```Bash
cd plib
```

Finally just build it :
```Bash
make release
```

Once this is done you can copy the plib.h and the libplib.a and build your project with it.

```Bash
gcc my_project.c -libplib.a
```

# Contributing to plib

Welcome to plib! We appreciate your interest in contributing to this simple
C library. Please take a moment to review this guide before making any
contributions.

## Getting Started

  - Ensure you have a GitHub account. 
  - Fork the repository on GitHub. 
  - Clone your forked repository locally: `git clone https://github.com/your-username/plib.git` 
  - Create a new branch for your work: `git checkout -b feature-name`  

## How to Contribute

1. **Bug Fixes or Feature Requests**: -

Check the issue tracker for existing issues or create a new one if necessary.

- Fork the repository and create a new branch. 
- Make changes and ensure proper testing.
- Submit a pull request referencing the related issue.  

2. **Code Style**: 

- Follow the project's coding style and guidelines.
- Ensure code readability and maintainability. 
- Document code changes where necessary.

3. **Documentation**: 

- Help improve the project documentation if required. 
- Provide clear and concise explanations.

4. **Testing**: 

- Include relevant tests for new features or bug fixes. 
- Ensure all existing tests pass.  

## Pull Requests  

- Submit pull requests against the `main` branch. 
- Provide a descriptive title and clear description of the changes made. 
- Mention any related issues in the pull request.  

Thank you for contributing to plib!


# Code Style

## Module naming

- Module's name should be descriptive concise, and simple. (eg. string/list/bit)
- Module's name must be lowercase letters only.
- Each module should have a it's own section in the plib.h file
```C
/*############################################################################*/
/*                                [PlibModuleName]                                */
/*############################################################################*/
```
## File naming

- File's name must match the function's definition in the plib.h file.

- For example this functions must be in the folder string, and in the file string_append_back.c :
```C
char         *string_append_back(char *str1, char *str2);
```

## Function naming

- Function's naming should always start with the prefix of their module. so all functions that operates on string should start with : 
```C
//[type]	[module]_[verb]_[complement](args)
char         *string_append_back(char *str1, char *str2);
```
- Function's should use only this lists of verbs with the intended meaning :
-
```C
/*
create       : instantiate and do memory allocation
destroy      : deinstantiate and release memory allocation
copy         : put src into dst without memory allocation.
clone        : create a clone of src without affecting it.
count        : count the number of occurence of something.
compare      : compare two instances of something.
concat       : put the content of src after dst no allocations.
contains     : return a boolean if something is into something else.
join         : create memory and concat two elements.
length       : returns the length of something. (length == within)
size         : returns the size of something. (size == container)
ends_with    : something must end with something.
starts_with  : something must start with something.
index_of     : returns the index of something within something.
assert       : returns a boolean if something conform to something.
slice        : returns a duplicate of a subset of something.
search       : search something within something.
map          : map always apply a function to something.
filter       : returns a filtered clone of something.
pad          : returns a padded clone of something.
trim         : remove something from something's both ends.
random       : pseudo random thing.
reverse      : take something and reverse it.
strip        : remove something if that something exists.
sort         : perform a sort of something.
split        : take something and produce more things.
set          : take something and change it to something.
get          : ask to get something.
apply        : use functions to apply a modification on something.
is           : for boolean evaluation must return (0 or 1).
to           : take something and transform it to something else.
insert       : create a new element and put it into something.
remove       : destroy an element from something.
append       : adds something to something.
push         : insert an already existing element into something.
pop          : remove an element without destruction from something.
rotate       : moves something into a shiffted version of self.
*/
```

- Function's argument should have a descriptive name too :

```C
/*
i,j,k,l        -> usually for counters.
temp/tmp       -> usually for temporary variables.
str_xxx        -> usually for string.
src/dst        -> usually for indicating a sender and a receiver.
xxx_length     -> usually stores the length of something.
total_xxx      -> usually has the total of something.
self           -> placeholder for the instance of something.
ptr_xxx/p_xxx  -> usually a pointer to something. 
*/
```

## General principles

- Code should be as simple as possible.
- Code should be DRY when it makes sense.
- Code should not have any comments.
- Code should have variants when it makes sense (eg. left/right/front/back/etc.)
- Code should focus on readability and ease of use before performance concerns.

## Priority for contribution

- 1 -> improving the test coverage.
- 2 -> adding new features, functions, and data structures.
- 3 -> improving the consistency of the naming / refactoring.
- 4 -> providing good documentation.
- 5 -> improving the build system.
