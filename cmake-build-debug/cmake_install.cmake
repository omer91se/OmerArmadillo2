# Install script for directory: /home/labkinetic/catkin_ws/src/Planning

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
        file(MAKE_DIRECTORY "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
      endif()
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin")
        file(WRITE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin" "")
      endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/_setup_util.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local" TYPE PROGRAM FILES "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/catkin_generated/installspace/_setup_util.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/env.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local" TYPE PROGRAM FILES "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/catkin_generated/installspace/env.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/setup.bash")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local" TYPE FILE FILES "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/catkin_generated/installspace/setup.bash")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/setup.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local" TYPE FILE FILES "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/catkin_generated/installspace/setup.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/setup.zsh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local" TYPE FILE FILES "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/catkin_generated/installspace/setup.zsh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/.rosinstall")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local" TYPE FILE FILES "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/catkin_generated/installspace/.rosinstall")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/armadillo2_bgu/msg" TYPE FILE FILES
    "/home/labkinetic/catkin_ws/src/Planning/msg/ActionDispatch.msg"
    "/home/labkinetic/catkin_ws/src/Planning/msg/ActionFeedback.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/armadillo2_bgu/srv" TYPE FILE FILES "/home/labkinetic/catkin_ws/src/Planning/srv/ReturnJointStates.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/armadillo2_bgu/action" TYPE FILE FILES
    "/home/labkinetic/catkin_ws/src/Planning/action/Operation.action"
    "/home/labkinetic/catkin_ws/src/Planning/action/VocalCmd.action"
    "/home/labkinetic/catkin_ws/src/Planning/action/SimplePick.action"
    "/home/labkinetic/catkin_ws/src/Planning/action/SimplePlace.action"
    "/home/labkinetic/catkin_ws/src/Planning/action/SimpleTarget.action"
    "/home/labkinetic/catkin_ws/src/Planning/action/Data_base.action"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/armadillo2_bgu/msg" TYPE FILE FILES
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/OperationAction.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/OperationActionGoal.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/OperationActionResult.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/OperationActionFeedback.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/OperationGoal.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/OperationResult.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/OperationFeedback.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/armadillo2_bgu/msg" TYPE FILE FILES
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/VocalCmdAction.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/VocalCmdActionGoal.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/VocalCmdActionResult.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/VocalCmdActionFeedback.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/VocalCmdGoal.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/VocalCmdResult.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/VocalCmdFeedback.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/armadillo2_bgu/msg" TYPE FILE FILES
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/SimplePickAction.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/SimplePickActionGoal.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/SimplePickActionResult.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/SimplePickActionFeedback.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/SimplePickGoal.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/SimplePickResult.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/SimplePickFeedback.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/armadillo2_bgu/msg" TYPE FILE FILES
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/SimplePlaceAction.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/SimplePlaceActionGoal.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/SimplePlaceActionResult.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/SimplePlaceActionFeedback.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/SimplePlaceGoal.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/SimplePlaceResult.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/SimplePlaceFeedback.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/armadillo2_bgu/msg" TYPE FILE FILES
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/SimpleTargetAction.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/SimpleTargetActionGoal.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/SimpleTargetActionResult.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/SimpleTargetActionFeedback.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/SimpleTargetGoal.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/SimpleTargetResult.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/SimpleTargetFeedback.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/armadillo2_bgu/msg" TYPE FILE FILES
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/Data_baseAction.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/Data_baseActionGoal.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/Data_baseActionResult.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/Data_baseActionFeedback.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/Data_baseGoal.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/Data_baseResult.msg"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/armadillo2_bgu/msg/Data_baseFeedback.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/armadillo2_bgu/cmake" TYPE FILE FILES "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/catkin_generated/installspace/armadillo2_bgu-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/include/armadillo2_bgu")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/roseus/ros/armadillo2_bgu")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/common-lisp/ros/armadillo2_bgu")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/share/gennodejs/ros/armadillo2_bgu")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/lib/python2.7/dist-packages/armadillo2_bgu")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/devel/lib/python2.7/dist-packages/armadillo2_bgu")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/catkin_generated/installspace/armadillo2_bgu.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/armadillo2_bgu/cmake" TYPE FILE FILES "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/catkin_generated/installspace/armadillo2_bgu-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/armadillo2_bgu/cmake" TYPE FILE FILES
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/catkin_generated/installspace/armadillo2_bguConfig.cmake"
    "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/catkin_generated/installspace/armadillo2_bguConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/armadillo2_bgu" TYPE FILE FILES "/home/labkinetic/catkin_ws/src/Planning/package.xml")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/gtest/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/labkinetic/catkin_ws/src/Planning/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
