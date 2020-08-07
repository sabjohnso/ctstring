configure_file(config.hpp.in config.hpp)

add_library(ctstring_header INTERFACE)
set_target_properties(ctstring_header PROPERTIES EXPORT_NAME header)
target_include_directories(ctstring_header
  INTERFACE
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  $<INSTALL_INTERFACE:${ctstring_INSTALL_INCLUDEDIR}>)

add_library(ctstring::header ALIAS ctstring_header)
  
install(TARGETS ctstring_header
  EXPORT ctstring_EXPORTS
  RUNTIME DESTINATION ${ctstring_INSTALL_BINDIR}
  LIBRARY DESTINATION ${ctstring_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${ctstring_INSTALL_LIBDIR})

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/config.hpp
  DESTINATION ${ctstring_INSTALL_INCLUDEDIR}/ctstring)

install(FILES
  details/constants.hpp
  details/import.hpp
  details/Lifted_string_fwd.hpp
  details/Lifted_string.hpp
  details/Static_string.hpp
  DESTINATION ${ctstring_INSTALL_INCLUDEDIR}/ctstring/details)
