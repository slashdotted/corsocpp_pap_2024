set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(S7overloading overloading.cpp)
add_executable(S7overriding overriding.cpp)
add_executable(S7hiding hiding.cpp)
add_executable(S7virtualdestructor virtualdestructor.cpp)
add_executable(S7final final.cpp)
add_executable(S7delete delete.cpp)
add_executable(S7default default.cpp)
add_executable(S7ex s7ex.cpp)

