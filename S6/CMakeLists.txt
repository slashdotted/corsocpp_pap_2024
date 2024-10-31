set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(S6 employee.h lecturer.h researcher.h employee.cpp lecturer.cpp main.cpp researcher.cpp)
add_executable(S6derivation derivationtypes.cpp)
