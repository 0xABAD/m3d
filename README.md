
M3D
===

A small 3D vector and matrix math library with support for floating
point vectors of sizes 2, 3, and 4, and for 4 by 4 matrices.  As with
all 3D math and vector libraries, everyone has their own, and this one
is mine.

Facts At a Glance
-----------------

* Single file header library
* Compatible with C++03
* No templates
* No extrenal dependencies except for `math.h` which can be overridden
* Vectors overloaded with xyzw, rgba, or stuv representations
* Limited swizzling of vector types (e.g. v.xy, v.zw, v.yz, v.xyz,
  v.yzw, etc.)
* zlib license

Usage
-----

M3D is a single header library.  In one, and only one, source file you
need to define its implementation for the translation unit:

```
#define M3D_IMPLEMENTATION
#include "m3d.h"
```

Afterwards, you can include the header in any other source files you
will call the library from.  As for API usage checkout the
`test_bench.cpp` file.  The unit tests in that file are short and
cover the majority of the library.  The library does provide some
options through preprocessor definitions:

* **M3D_STATIC** You can define this variable to have M3D be
  statically defined to a specific translation unit.

* **M3D_INVERSE_MATRIX_EPSILON** Set this to a value for determination
  of whether a matrix is invertible or not.  The default is 0.00001.

* **M3D_DO_NOT_USE_C_MATH_LIB** Define this variable if you do not
  want to use the C standard math library for various math functions.
  If you do set this variable then you must provide your
  implementation of the various math functions required by M3D which
  must also have the same signature as those defined by `math.h`.  As
  an example:

```
#define M3D_DO_NOT_USE_C_MATH_LIB

// your math function overrides
#define M3D_COSF  my_special_cos
#define M3D_SINF  my_special_sin
#define M3D_TANF  my_special_tan
#define M3D_FABSF my_special_abs
#define M3D_SQRTF my_special_sqrt

#define M3D_IMPLEMENTATION
#include "m3d.h"
```


Test and Benchmarks
-------------------

The `test_bench.cpp` file contains the unit tests and benchmarks for
the library and solely for development purposes.  Currently, the test
and benchmark suite only builds with a recent MSVC compiler as it uses
intrinsics for the x86 `rdtscp` and `cpuid` instructions.
Furthermore, the benchmarks require a processor to support the
`rdtscp` instruction and have an invariant TSC to have any meaningful
results.  However, these features are standard on recent Intel and AMD
processors over the last half decade.

To build the test and benchmarks just run the `test-msvc.bat` script
in the project directory from a command prompt that has loaded the VC
environment variables through the `vsvarsall.bat` script.  Visual
Studio has a command prompt that does this for you, just type `command`
in the Windows start menu search and it should be one of the top
choices on the list.  Once built, a build directory will be in the
project directory that contains a `m3d.exe` executable to run the
tests and benchmarks.

As for the benchmarks themselves, just remember, they're just micro
benchmarks and shouldn't taken as gospel or used for comparison.  They
are merely to get an idea of the runtime performance of individual
operations relative to each other.
