# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/cypri/OneDrive/Pulpit/projekt 3/tp_projekt_3/build/_deps/eigen-src"
  "C:/Users/cypri/OneDrive/Pulpit/projekt 3/tp_projekt_3/build/_deps/eigen-build"
  "C:/Users/cypri/OneDrive/Pulpit/projekt 3/tp_projekt_3/build/_deps/eigen-subbuild/eigen-populate-prefix"
  "C:/Users/cypri/OneDrive/Pulpit/projekt 3/tp_projekt_3/build/_deps/eigen-subbuild/eigen-populate-prefix/tmp"
  "C:/Users/cypri/OneDrive/Pulpit/projekt 3/tp_projekt_3/build/_deps/eigen-subbuild/eigen-populate-prefix/src/eigen-populate-stamp"
  "C:/Users/cypri/OneDrive/Pulpit/projekt 3/tp_projekt_3/build/_deps/eigen-subbuild/eigen-populate-prefix/src"
  "C:/Users/cypri/OneDrive/Pulpit/projekt 3/tp_projekt_3/build/_deps/eigen-subbuild/eigen-populate-prefix/src/eigen-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/cypri/OneDrive/Pulpit/projekt 3/tp_projekt_3/build/_deps/eigen-subbuild/eigen-populate-prefix/src/eigen-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/cypri/OneDrive/Pulpit/projekt 3/tp_projekt_3/build/_deps/eigen-subbuild/eigen-populate-prefix/src/eigen-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
