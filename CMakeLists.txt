cmake_minimum_required(VERSION 3.0.0)
project(eggin VERSION 0.1.0)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(
  SOURCES
  src/Engine.cpp
  src/Logger.cpp
  src/SceneManager.cpp
  src/render/Render.cpp
  src/render/Mesh.cpp
)

add_library( eggin STATIC ${SOURCES} )
target_link_libraries(eggin ${CONAN_LIBS})
target_link_libraries(eggin opengl32 glu32)