cmake_minimum_required(VERSION 3.28)
project(kursus CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Alle exe'er samlet ét sted, opdelt per lektion
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Hjælper: én .cpp bliver til ét target med navnet <mappe>_<fil>
function(add_opgave src)
  get_filename_component(navn ${src} NAME_WE)
  get_filename_component(mappe ${CMAKE_CURRENT_SOURCE_DIR} NAME)
  add_executable(${mappe}_${navn} ${src})
endfunction()

# Hjælper: en hel mappe med flere filer bliver til ét target
function(add_opgave_dir dir)
  file(GLOB kilder CONFIGURE_DEPENDS ${dir}/*.cpp)
  get_filename_component(mappe ${CMAKE_CURRENT_SOURCE_DIR} NAME)
  add_executable(${mappe}_${dir} ${kilder})
  target_include_directories(${mappe}_${dir} PRIVATE ${dir})
endfunction()

add_subdirectory(lektion01)
add_subdirectory(lektion02)
add_subdirectory(lektion03)
add_subdirectory(lektion04)
add_subdirectory(lektion05)
add_subdirectory(lektion06)
add_subdirectory(lektion07)
add_subdirectory(lektion08)
add_subdirectory(lektion09)
add_subdirectory(lektion10)
add_subdirectory(lektion11)
add_subdirectory(lektion12)