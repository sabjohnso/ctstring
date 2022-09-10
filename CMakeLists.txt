cmake_minimum_required(VERSION 3.12)

project(ctstring VERSION 0.1.0 LANGUAGES C CXX)

option(ctstring_BUILD_TESTING "Build the ctstring tests" ON)
set(ctsstring_CXX_STANDARD 20 CACHE STRING "C++ standard for ctstring")

include(GNUInstallDirs)
set(ctstring_INSTALL_BINDIR ${CMAKE_INSTALL_BINDIR})
set(ctstring_INSTALL_LIBDIR ${CMAKE_INSTALL_LIBDIR})
set(ctstring_INSTALL_INCLUDEDIR ${CMAKE_INSTALL_INCLUDEDIR}/ctstring-${PROJECT_VERSION})
set(ctstring_INSTALL_CONFDIR ${ctstring_INSTALL_LIBDIR}/cmake/ctstring-${PROJECT_VERSION})

list(INSERT CMAKE_MODULE_PATH 0 ${PROJECT_SOURCE_DIR}/cmake)
include(ctstring_deps)

add_subdirectory(ctstring)

if(ctstring_BUILD_TESTING)
  include(CTest)
  if(BUILD_TESTING)
    add_subdirectory(ctstring_testing)
  endif()
endif()

install(EXPORT ctstring_EXPORTS
  NAMESPACE ctstring::
  FILE ctstring-exports.cmake
  DESTINATION ${ctstring_INSTALL_CONFDIR})

configure_file(ctstring-config.cmake.in ctstring-config.cmake)
install(FILES ${PROJECT_BINARY_DIR}/ctstring-config.cmake
  DESTINATION ${ctstring_INSTALL_CONFDIR})
