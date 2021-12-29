# set(SPLIT_SRC_LIST )
# list(APPEND ${SPLIT_SRC_LIST}
#     ../ch05/splitMain.cpp
#     split.cpp
#     ../ch05/split.hpp
# )

# function(makeExampleExec exename exesrclist)
#     add_executable(${exename} ${exesrclist})
#     target_compile_options(${exename} PRIVATE -g)
#     target_compile_options(${exename} PRIVATE -Wextra)
# endfunction()


# makeExampleExec(split ${SPLIT_SRC_LIST})

add_executable(mySplit 
    ../ch05/splitMain.cpp
    split.cpp
    ../ch05/split.hpp
)
