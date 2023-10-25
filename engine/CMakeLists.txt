
set(HEADER_LIST
    "${Freesynd_SOURCE_DIR}/engine/include/fs-engine/gfx/dirtylist.h"
    )

set(SOURCE_LIST
    "${Freesynd_SOURCE_DIR}/engine/src/gfx/dirtylist.cpp"
    )

add_definitions (-DSYSTEM_SDL)

# Make an automatic library - will be static or dynamic based on user setting
add_library(fs_engine ${SOURCE_LIST} ${HEADER_LIST})
add_library(Freesynd::Engine ALIAS fs_engine)

# We need this directory, and users of our library will need it too
target_include_directories(fs_engine PUBLIC include)

# This depends on (header only) boost
#target_link_libraries(fs_engine PUBLIC SDL::SDL ${SDLIMAGE_LIBRARY} ${SDL_MIXER_LIBRARIES} PNG::PNG)

target_link_libraries(fs_engine PRIVATE Freesynd::Utils)

# All users of this library will need at least C++11
#target_compile_features(modern_library PUBLIC cxx_std_11)

# IDEs should put the headers in a nice place
source_group(
  TREE "${PROJECT_SOURCE_DIR}/engine/include"
  FILES ${HEADER_LIST})


