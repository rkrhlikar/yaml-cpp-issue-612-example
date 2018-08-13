## Description

This is a small example project to reproduce [Issue #612](https://github.com/jbeder/yaml-cpp/issues/612) from the yaml-cpp library.

## Steps to reproduce building error

```
mkdir build
cd build
cmake ..
make
```
Which results in the following error when running the cmake command:
>CMake Error at /usr/local/share/cmake-3.11/Modules/ExternalProject.cmake:2525 (message):
>  No download info given for 'googletest_project' and its source directory:
>
>   \*\*PARENT_PROJECT_DIR\*\*/test/gtest-1.8.0
>
>  is not an existing non-empty directory.  Please specify one of:
>
>   * SOURCE_DIR with an existing non-empty directory
>   * DOWNLOAD_COMMAND
>   * URL
>   * GIT_REPOSITORY
>   * SVN_REPOSITORY
>   * HG_REPOSITORY
>   * CVS_REPOSITORY and CVS_MODULE
>Call Stack (most recent call first):
>  /usr/local/share/cmake-3.11/Modules/ExternalProject.cmake:3100 (_ep_add_download_command)
>  yaml-cpp/test/CMakeLists.txt:10 (ExternalProject_Add)

## Workaround

Add the following line:
```
set(YAML_CPP_BUILD_TESTS OFF CACHE BOOL "Enable testing")
```
before the `add_subdirectory` command in CMakeLists.txt.
This disables test building and doesn't execute the problematic build step.

## Fix

Since the issue has been resolved with a revert, you can use the newest commit [c90c08c](https://github.com/jbeder/yaml-cpp/commit/c90c08ccc9a08abcca609064fb9a856dfdbbb7b4) (at the time of writting).
You can achieve this by updating the submodule:
```
cd yaml-cpp
git checkout c90c08ccc9a08abcca609064fb9a856dfdbbb7b4
```
or by removing the submodule and adding it again, which will cause the newly added submodule to point to the newest commit.
