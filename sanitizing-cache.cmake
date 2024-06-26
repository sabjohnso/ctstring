# This is an initial cache file for builds with sanitizers: sanitizers for
# undefined behavior and adresses.  Additionally, the typical NDEBUG definition
# is removed from the build to keep asserts.
#
set(CMAKE_BUILD_TYPE Release CACHE STRING "")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Wno-zero-length-array -Werror -fsanitize=undefined -fsanitize=address" CACHE STRING "")
set(CMAKE_CXX_FLAGS_Release -O3 CACHE STRING "")
