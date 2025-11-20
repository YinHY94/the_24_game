# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\The_24_Game_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\The_24_Game_autogen.dir\\ParseCache.txt"
  "The_24_Game_autogen"
  )
endif()
