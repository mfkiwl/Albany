#*****************************************************************//
#    Albany 3.0:  Copyright 2016 Sandia Corporation               //
#    This Software is released under the BSD license detailed     //
#    in the file "license.txt" in the top-level Albany directory  //
#*****************************************************************//

get_filename_component(parentPath ${CMAKE_CURRENT_SOURCE_DIR} PATH)
get_filename_component(parentDirName ${parentPath} NAME)
get_filename_component(dirName ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set (testNameRoot ${parentDirName}_${dirName})

#################################################
#          Omega_h Discretization tests         #
#################################################

create_unit_test (NAME    ExtrudedMesh
                  PREFIX  ${testNameRoot}
                  SOURCES ExtrudedMesh.cpp)

create_unit_test (NAME    ExtrudedConnManager
                  PREFIX  ${testNameRoot}
                  SOURCES ExtrudedConnManager.cpp
                          DummyConnManager.cpp)
