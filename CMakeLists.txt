cmake_minimum_required(VERSION 3.27)
project(algorithm)

set(CMAKE_CXX_STANDARD 17)

add_executable(algorithm
        Maze.cpp
        BCA.cpp
        CVR.cpp
        LBS.cpp
        CBUS.cpp
        RMQ.cpp
        cut.cpp
        Tele.cpp
        count.cpp
        MaxDis.cpp
        Inversion.cpp
)

add_executable(new_target Maze.cpp)
add_executable(new_target1 BCA.cpp)
add_executable(new_target2 CVR.cpp)
add_executable(new_target3 LBS.cpp)
add_executable(new_target4 CBUS.cpp)
add_executable(new_target5 RMQ.cpp)
add_executable(new_target6 cut.cpp)
add_executable(new_target7 Tele.cpp)
add_executable(new_target8 count.cpp)
add_executable(new_target9 MaxDis.cpp)
add_executable(new_target10 Inversion.cpp)
