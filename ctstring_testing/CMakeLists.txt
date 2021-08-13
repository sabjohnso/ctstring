find_package(GTest)

macro(ctstring_add_test test_name exe_name)
  add_executable(${exe_name} ${ARGN})
  target_link_libraries(${exe_name} PRIVATE
    ctstring::header
    GTest::gtest_main
    type_utility::type_utility)
  set_target_properties(${exe_name} PROPERTIES CXX_STANDARD 20)
  add_test(${test_name} ${exe_name})
endmacro()

ctstring_add_test(static_string static_string_test static_string_test.cpp)
ctstring_add_test(lifted_string lifted_string_test lifted_string_test.cpp)
ctstring_add_test(hoist hoist_test hoist_test.cpp)
ctstring_add_test(constants constants_test constants_test.cpp)
ctstring_add_test(literals literals_test literals_test.cpp)
