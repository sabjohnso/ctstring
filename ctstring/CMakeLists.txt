configure_file(config.hpp.in config.hpp)

add_library(ctstring_header INTERFACE)
set_target_properties(ctstring_header PROPERTIES EXPORT_NAME header)
target_include_directories(ctstring_header
  INTERFACE
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<INSTALL_INTERFACE:${ctstring_INSTALL_INCLUDEDIR}>)
target_link_libraries(ctstring_header
  INTERFACE
    type_utility::type_utility)

add_library(ctstring::header ALIAS ctstring_header)
  
install(TARGETS ctstring_header
  EXPORT ctstring_EXPORTS
  RUNTIME DESTINATION ${ctstring_INSTALL_BINDIR}
  LIBRARY DESTINATION ${ctstring_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${ctstring_INSTALL_LIBDIR})

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/config.hpp
  ctstring.hpp
  macros.hpp
  DESTINATION ${ctstring_INSTALL_INCLUDEDIR}/ctstring)

install(DIRECTORY
  details
  DESTINATION ${ctstring_INSTALL_INCLUDEDIR}/ctstring
  FILES_MATCHING PATTERN "*.hpp")
