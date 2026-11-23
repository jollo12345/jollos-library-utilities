cmake_minimum_required(VERSION 3.21)

project(
  JLU
  VERSION 0.1.0
  LANGUAGES C)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

option(JLU_BUILD_SHARED "Build the shared library" ON)
option(JLU_BUILD_STATIC "Build the static library" OFF)
option(JLU_STATIC_SDL "Link SDL3 statically" OFF)

option(JLU_BUILD_TESTS "Build tests" OFF)
option(JLU_ENABLE_COVERAGE "Enable coverage" OFF)

if(NOT JLU_BUILD_SHARED AND NOT JLU_BUILD_STATIC)
  message(
    FATAL_ERROR "Enable at least one of JLU_BUILD_SHARED / JLU_BUILD_STATIC")
endif()

if(JLU_STATIC_SDL)
  find_package(SDL3 REQUIRED CONFIG COMPONENTS SDL3-static)
  set(JLU_SDL3_TARGET SDL3::SDL3-static)
else()
  find_package(SDL3 REQUIRED CONFIG COMPONENTS SDL3-shared)
  set(JLU_SDL3_TARGET SDL3::SDL3-shared)
endif()

file(GLOB_RECURSE JLU_HEADERS CONFIGURE_DEPENDS
     "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE JLU_SOURCES CONFIGURE_DEPENDS
     "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")

set(JLU_INSTALL_CMAKEDIR ${CMAKE_INSTALL_LIBDIR}/cmake/JLU)

if(JLU_BUILD_SHARED)
  add_library(JLU-shared SHARED ${JLU_HEADERS} ${JLU_SOURCES})
  add_library(JLU::JLU-shared ALIAS JLU-shared)

  target_link_libraries(JLU-shared PUBLIC ${JLU_SDL3_TARGET})
  target_compile_features(JLU-shared PUBLIC c_std_23)
  target_include_directories(
    JLU-shared PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                      $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

  set_target_properties(
    JLU-shared
    PROPERTIES OUTPUT_NAME JLU
               VERSION ${PROJECT_VERSION}
               SOVERSION ${PROJECT_VERSION_MAJOR}
               WINDOWS_EXPORT_ALL_SYMBOLS ON)

  install(TARGETS JLU-shared EXPORT JLU-shared-targets)
  install(
    EXPORT JLU-shared-targets
    FILE JLU-shared-targets.cmake
    NAMESPACE JLU::
    DESTINATION ${JLU_INSTALL_CMAKEDIR})
endif()

if(JLU_BUILD_STATIC)
  add_library(JLU-static STATIC ${JLU_HEADERS} ${JLU_SOURCES})
  add_library(JLU::JLU-static ALIAS JLU-static)

  target_link_libraries(JLU-static PUBLIC ${JLU_SDL3_TARGET})
  target_compile_features(JLU-static PUBLIC c_std_23)
  target_include_directories(
    JLU-static PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                      $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

  set_target_properties(JLU-static PROPERTIES POSITION_INDEPENDENT_CODE ON)
  target_compile_definitions(JLU-static PUBLIC JLU_STATIC)
  if(WIN32)
    set_target_properties(JLU-static PROPERTIES OUTPUT_NAME JLU-static)
  else()
    set_target_properties(JLU-static PROPERTIES OUTPUT_NAME JLU)
  endif()

  install(TARGETS JLU-static EXPORT JLU-static-targets)
  install(
    EXPORT JLU-static-targets
    FILE JLU-static-targets.cmake
    NAMESPACE JLU::
    DESTINATION ${JLU_INSTALL_CMAKEDIR})
endif()

if(JLU_BUILD_SHARED)
  add_library(JLU::JLU ALIAS JLU-shared)
else()
  add_library(JLU::JLU ALIAS JLU-static)
endif()

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/JLUConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/JLUConfig.cmake
  INSTALL_DESTINATION ${JLU_INSTALL_CMAKEDIR})

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/JLUConfigVersion.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMinorVersion ARCH_INDEPENDENT)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/JLUConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/JLUConfigVersion.cmake
        DESTINATION ${JLU_INSTALL_CMAKEDIR})

if(JLU_BUILD_TESTS)
  enable_testing()
  add_subdirectory(test)
endif()

if(JLU_ENABLE_COVERAGE)
  if(JLU_BUILD_SHARED)
    target_compile_options(JLU-shared PRIVATE --coverage -O0 -g)
    target_link_options(JLU-shared PUBLIC --coverage)
  endif()
  if(JLU_BUILD_STATIC)
    target_compile_options(JLU-static PRIVATE --coverage -O0 -g)
    target_link_options(JLU-static PUBLIC --coverage)
  endif()
endif()
