#pragma once

//
// ... CTString header files
//
#include <ctstring/ctstring.hpp>

#define HOIST_STRING(str) ::CTString::hoist([]{ return ::CTString::static_string(str); })
