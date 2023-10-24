# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

# Optionally glob, but only for CMake 3.12 or later:
set(HEADER_LIST
    "${Freesynd_SOURCE_DIR}/utils/include/fs-utils/common.h"
    "${Freesynd_SOURCE_DIR}/utils/include/fs-utils/log/log.h"

    )

set(SOURCE_LIST
    "${Freesynd_SOURCE_DIR}/utils/src/log.cpp"

    )

# Make an automatic library - will be static or dynamic based on user setting
add_library(fs_utils ${SOURCE_LIST} ${HEADER_LIST})

# We need this directory, and users of our library will need it too
target_include_directories(fs_utils PUBLIC include)

# All users of this library will need at least C++11
#target_compile_features(modern_library PUBLIC cxx_std_11)

# IDEs should put the headers in a nice place
source_group(
  TREE "${PROJECT_SOURCE_DIR}/utils/include"
  FILES ${HEADER_LIST})


