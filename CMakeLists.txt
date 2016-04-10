CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
PROJECT(MATLABFILTERING)

SET(HEADERS
  src/smoothing_filter.hpp
  )

SET(SOURCES
  src/main.cpp
  src/smoothing_filter.cpp
  )

ADD_EXECUTABLE(main
  ${HEADERS}
  ${SOURCES}
  )