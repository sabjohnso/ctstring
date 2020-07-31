configure_file(config.hpp.in config.hpp)

add_library(ctstring INTERFACE)
target_include_directories(ctstring
  INTERFACE
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<INSTALL_INTERFACE:${ctstring_INSTALL_INCLUDEDIR}>)

add_library(ctstring::ctstring ALIAS ctstring)
  
install(TARGETS ctstring
  EXPORT ctstring_EXPORTS
  RUNTIME DESTINATION ${ctstring_INSTALL_BINDIR}
  LIBRARY DESTINATION ${ctstring_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${ctstring_INSTALL_LIBDIR})

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/config.hpp
  DESTINATION ${ctstring_INSTALL_INCLUDEDIR})
