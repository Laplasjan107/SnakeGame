cmake_minimum_required(VERSION 3.0)
project(SnakeGame)

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Release")
    set(CMAKE_BUILD_TYPE "Release")
endif ()

# Turn off compilation progress bar.
set_property(GLOBAL PROPERTY RULE_MESSAGES OFF)

# Show executed commands.
set(CMAKE_VERBOSE_MAKEFILE OFF)

# Set compilation flags.
set(CMAKE_CXX_FLAGS " -Wall -Wextra")

link_libraries(ncurses)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED True)

# Source files path.
set(SOURCE_FILES
        src/main.cpp
        src/Board.cpp
        src/Board.h
        src/Snake.cpp
        src/Snake.h
        src/Coordinates.cpp
        src/Coordinates.h
        src/Food.cpp
        src/Food.h
        src/Direction.cpp
        src/Direction.h
        src/Game.cpp
        src/Game.h
    )

# Wskazujemy plik wykonywalny.
add_executable(snake ${SOURCE_FILES})


# Dodajemy obsługę Doxygena: sprawdzamy, czy jest zainstalowany i jeśli tak to:
#find_package(Doxygen)
#if (DOXYGEN_FOUND)
    # Wskazujemy lokalizacją pliku konfiguracyjnego i podajemy jego docelową lokalizację w folderze, gdzie następuje kompilacja.
 #   configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    # Dodajemy cel doc: użycie make doc spowoduje wywołanie doxygena z odpowiednim plikiem konfiguracyjnym w folderze kompilacji.
    # Na wyjście zostanie wypisany odpowiedni komentarz.
  #  add_custom_target(doc
   #     ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    #    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
     #   COMMENT "Generating API documentation with Doxygen"
  #  )
#endif (DOXYGEN_FOUND)
