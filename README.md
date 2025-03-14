A simple wrapper that intercepts and logs malloc/free function calls for debugging purposes.

### Requirements

- `libdl.so` (requires dynamic linking library for dlsym functionality)
- CMake 3.30 or newer
- C Compiler with C11 standard support

### Installation

```
mkdir build
cd build
cmake ..
make
```
