Compile-time Strings
====================

## Notice
This library provides functionality for compile-time strings: strings
that are lifted into the template parameters of a type. The
recommendation is to **never** use this library or other libraries that
provide similar functionality. Compile-time strings provide a
slightly improved convienience compared to tag types.  However, the
use of compile-time strings leads to bloated symbols that can
seriously slow and even prevent complitation, create unreasonable
memory requirements during compilation and make C++ compiler error
messages even more difficult to read.
