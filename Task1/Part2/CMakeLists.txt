cmake_minimum_required(VERSION 3.14)

set(PROJECT_NAME "Part2")

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(SFML_DIR "../lib/SFML-2.5.1-release")
endif()

if(NOT SFML_DIR)
    set(SFML_DIR "../lib/SFML-2.5.1-debug")
endif()

set(IMGUI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/imgui")

find_package(SFML REQUIRED audio graphics network window system)

include_directories(${IMGUI_DIR}/include)
include_directories(${SFML_DIR}/include)
link_directories(${SFML_DIR}/lib)

set(IMGUI_SOURCE "${IMGUI_DIR}/imgui.cpp" "${IMGUI_DIR}/imgui_draw.cpp" "${IMGUI_DIR}/imgui_demo.cpp" "${IMGUI_DIR}/imgui_widgets.cpp" "${IMGUI_DIR}/imgui_stdlib.cpp" "${IMGUI_DIR}/imgui-SFML.cpp")
set(ARRAY_SOURCE "arrays/DequeArray.tpp" "arrays/DequeArray.h" "arrays/QueueArray.tpp" "arrays/QueueArray.h" "arrays/StackArray.tpp" "arrays/StackArray.h")
set(LIST_SOURCE "lists/Node.tpp" "lists/Node.h" "lists/DoubleNode.tpp" "lists/DoubleNode.h" "lists/List.tpp" "lists/List.h" "lists/DoubleList.tpp" "lists/DoubleList.h" "lists/DequeList.tpp" "lists/DequeList.h" "lists/QueueList.tpp" "lists/QueueList.h" "lists/StackList.tpp" "lists/StackList.h")
set(STD_SOURCE "std/DequeStd.tpp" "std/DequeStd.h" "std/QueueStd.tpp" "std/QueueStd.h" "std/StackStd.tpp" "std/StackStd.h")
set(PART2_SOURCE ${ARRAY_SOURCE} ${LIST_SOURCE} ${STD_SOURCE} "empty.tpp" "empty.h" "empty.cpp" "print.tpp" "print.h" "print.cpp" "arrays.h" "lists.h" "std.h" "dice.h" "dice.cpp" "random.tpp" "random.h" "random.cpp" "test.tpp" "test.h" "test.cpp")

add_executable(${PROJECT_NAME} main.cpp ${IMGUI_SOURCE} ${PART2_SOURCE})
target_link_libraries(${PROJECT_NAME} sfml-audio sfml-graphics sfml-network sfml-window sfml-system opengl32)
