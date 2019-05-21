cmake_minimum_required(VERSION 3.14)

set(PROJECT_NAME "Part2")

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)

set(GTEST_DIR "../lib/googletest-release-1.8.1/googletest")

include_directories(${GTEST_DIR}/include)
link_directories(${GTEST_DIR}/lib)

set(BASE_SOURCE "base/Deque.h" "base/Queue.h" "base/Stack.h")
set(ARRAY_SOURCE "arrays/DequeArray.tpp" "arrays/DequeArray.h" "arrays/QueueArray.tpp" "arrays/QueueArray.h" "arrays/StackArray.tpp" "arrays/StackArray.h")
set(LIST_SOURCE "lists/structural/Node.tpp" "lists/structural/Node.h" "lists/structural/DoubleNode.tpp" "lists/structural/DoubleNode.h" "lists/structural/List.tpp" "lists/structural/List.h" "lists/structural/DoubleList.tpp" "lists/structural/DoubleList.h" "lists/DequeList.tpp" "lists/DequeList.h" "lists/QueueList.tpp" "lists/QueueList.h" "lists/StackList.tpp" "lists/StackList.h")
set(STD_SOURCE "std/DequeStd.tpp" "std/DequeStd.h" "std/QueueStd.tpp" "std/QueueStd.h" "std/StackStd.tpp" "std/StackStd.h")
set(PART2_SOURCE ${BASE_SOURCE} ${ARRAY_SOURCE} ${LIST_SOURCE} ${STD_SOURCE} "empty.tpp" "empty.h" "empty.cpp" "print.tpp" "print.h" "print.cpp" "arrays.h" "lists.h" "std.h" "dice.h" "dice.cpp" "random.tpp" "random.h" "random.cpp" "test.tpp" "test.h" "test.cpp" "unittests.cpp")

add_executable(${PROJECT_NAME} main.cpp ${PART2_SOURCE})
target_link_libraries(${PROJECT_NAME} gtestd gtest_maind)