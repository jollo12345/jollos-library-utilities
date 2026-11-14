cmake_minimum_required(VERSION 3.21)

project(
  JLU
  VERSION 0.1.0
  LANGUAGES C)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

option(${PROJECT_NAME}_BUILD_TESTS "Build tests" OFF)
option(${PROJECT_NAME}_STATIC_SDL "Link SDL3 statically" OFF)

if(${PROJECT_NAME}_STATIC_SDL)
  find_package(SDL3 REQUIRED CONFIG COMPONENTS SDL3-static)
  set(SDL3_TARGET SDL3::SDL3-static)
else()
  find_package(SDL3 REQUIRED CONFIG COMPONENTS SDL3-shared)
  set(SDL3_TARGET SDL3::SDL3-shared)
endif()

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} INTERFACE ${SDL3_TARGET})

target_compile_features(${PROJECT_NAME} INTERFACE c_std_23)

target_include_directories(
  ${PROJECT_NAME}
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}Targets)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

set(${PROJECT_NAME}_INSTALL_CMAKEDIR
    ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

install(
  EXPORT ${PROJECT_NAME}Targets
  FILE ${PROJECT_NAME}Targets.cmake
  NAMESPACE ${PROJECT_NAME}::
  DESTINATION ${${PROJECT_NAME}_INSTALL_CMAKEDIR})

configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
  INSTALL_DESTINATION ${${PROJECT_NAME}_INSTALL_CMAKEDIR})

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMinorVersion ARCH_INDEPENDENT)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
        DESTINATION ${${PROJECT_NAME}_INSTALL_CMAKEDIR})

if(${PROJECT_NAME}_BUILD_TESTS)
  enable_testing()
  add_subdirectory(test)
endif()
