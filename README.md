# Subset Sum Approximation using FPAS (Fully Polynomial-Time Approximation Scheme)

## Author: **Erick Jesús Ríos González**

## **Project Description**

This project implements the **Subset Sum** problem using a Fully Polynomial-Time Approximation Scheme (FPAS) in C++. The goal of the problem is to find a subsequence of a set of positive integers whose sum is as close as possible, without exceeding, a given target value (`t`). The project includes:

- A class-based implementation of the approximation algorithm.
- Validation of the solution using a brute force approach.
- Multiple automated tests to verify the required algorithm conditions.

---

## **Project Structure**

```plaintext
.
├── Makefile                 # File for automatic compilation
├── README.md                # File with project information
├── src/                     # Source code
│   ├── SubsetSum.cpp        # FPAS algorithm implementation
│   ├── SubsetSum.h          # SubsetSum class declaration
│   ├── TestSubsetSum.cpp    # Main file for testing
├── build/                   # Generated binaries after compilation
│   └── test                 # Executable generated by the project
├── captures/                # Screenshots of program executions
│   ├── capture1.png
│   ├── capture2.png
│   ├── capture3.png
│   ├── capture4.png
│   └── capture5.png

```
## Requisites 
- Operative System: Linux or either SO compatible with (`g++`)
- Compiler: `g++` with standar support C++17
- Tools: 
    - make
    - bash

## Compile

To compile the project, executes the followin command in the root of the project:

```bash
usr@~$ make
```
This will create an executable file called `test`in the folder `/build/`. If you want to clear the archives generated during the compilation, use:

```bash
usr@~ make clean
```

## Execute the code

Execute the compiled code using:
```bash
@usr~$ ./build/test
```