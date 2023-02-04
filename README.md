# Median Filter

A one-dimensional causal median filter class in C++. Missing values
at the beginning of the signal are replaced with zeroes.

## Installation

### Compilation from source

The build system is `cmake`. Install the library:
```
mkdir build
cd build
cmake ..
cmake --build .
```


## TODO
- [ ] Add non causal filter
- [ ] Add options for handling boundaries
- [ ] Use faster algorithm for real-time applications
- [ ] Write descriptive README with usage and installation instructions
- [ ] Update CMake config to handle multiple OSs and targets
