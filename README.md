<h1 align="center">Library for string manipulation</h1>

## Get string-manip lib
You can download the code from releases page https://github.com/mars-86/string-manip/releases

## Overview
Library for C language to manipulate strings

## Installation
#### Prerequisites
##### Windows subsystem for linux
- turn windows features on or off
- enable windows subsystem for linux
- enable virtual machine platform
- wsl --update
- wsl --set-default-version 2

##### Mingw
You will need to install mingw if you download the docker-cli version without libraries.

#### Install docker CLI
Just run install.bat and it will install docker cli on user's root folder
![Docker CLI for Windows](https://github.com/mars-86/static-assets/raw/main/images/docker-cli/docker-cli-002.jpg)

## Usage
Run docker command from console.
![Docker CLI for Windows](https://github.com/mars-86/static-assets/raw/main/images/docker-cli/docker-cli-001.jpg)

gcc -Wall {src}.c -o {file}.out -Wl,-rpath={library_path} -L{library_path} -l:str_manip.so__
    i.e. gcc -Wall main.c -o main.out -Wl,-rpath=. -L. -l:str_manip.so (supposing that the .so lib is in the same directory as main.c )

## Building for source
- Run the command make BUILD={stage} where stage must be replaced for release, debug, test, memtest__
    i.e. make BUILD=release for a release build.

It should generate a relase/bin folder with a library and header file.

## License
MIT
