<h1 align="center">Library for string manipulation</h1>

## Get string-manip lib
You can download the code from releases page https://github.com/mars-86/string-manip/releases

## Overview
Library for C language to manipulate strings.

## Installation
Clone the library.

#### Install the lib
Just put the **.so** **.h** from bin/release after building the library into the directory of the project in where you want to use the lib.

## Usage
gcc -Wall {**src**}.c -o {**file**}.out -Wl,-rpath={**library_path**} -L{**library_path**} -l:str_manip.so\
    i.e. gcc -Wall main.c -o main.out -Wl,-rpath=. -L. -l:str_manip.so (supposing that the .so lib is in the same directory as main.c )

## Building for source
- Run the command make BUILD={**stage**} where stage must be replaced for **release**, **debug**, **test**, **memtest**\
    i.e. make BUILD=**release** for a release build.

It should generate a relase/bin folder with a library and header file.

## License
MIT
