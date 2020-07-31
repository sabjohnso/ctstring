find_package(GTest)

macro(ctstring_add_test test_name exe_name)
  add_executable(${exe_name} ${ARGN})
  target_link_libraries(${exe_name} PRIVATE
    ctstring::ctstring
    GTest::gtest_main)
  add_test(${test_name} ${exe_name})
endmacro()
