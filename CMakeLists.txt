﻿# CMakeList.txt : projet CMake pour unordered_multiset, incluez la source et définissez
# la logique spécifique au projet ici.
#

# Ajoutez une source à l'exécutable de ce projet.
add_executable (unordered_multiset "main.cpp" "unordered_multiset.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET unordered_multiset PROPERTY CXX_STANDARD 20)
endif()

# TODO: Ajoutez des tests et installez des cibles si nécessaire.
