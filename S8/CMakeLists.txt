set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(S8 employee.h lecturer.h researcher.h employee.cpp lecturer.cpp main.cpp researcher.cpp lecturerresearcher.h lecturerresearcher.cpp)
add_executable(S8dynamiccast employee.h lecturer.h researcher.h employee.cpp lecturer.cpp dynamiccast.cpp researcher.cpp lecturerresearcher.h lecturerresearcher.cpp)
add_executable(S8staticcast employee.h lecturer.h researcher.h employee.cpp lecturer.cpp staticcast.cpp researcher.cpp lecturerresearcher.h lecturerresearcher.cpp)
add_executable(S8constcast constcast.cpp)
