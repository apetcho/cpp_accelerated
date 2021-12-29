# -- wordCounter
add_executable(wordCounter wordCounter.cpp)

# -- wordCounter using cross-reference
add_executable(XRef xref.cpp ../ch05/split.cpp ../ch05/split.hpp)
