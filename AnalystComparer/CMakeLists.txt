cmake_minimum_required(VERSION 3.6)
project(AnalystComparer)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Utils.cpp Utils.h Comparer.cpp Comparer.h Constants.h PurchaseSale.cpp PurchaseSale.h History.cpp History.h Analyst.cpp Analyst.h)
add_executable(AnalystComparer ${SOURCE_FILES})