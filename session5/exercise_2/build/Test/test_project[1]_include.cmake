if(EXISTS "C:/Users/meret/Desktop/Softwareingeniør/4. semester/ESW/opgaver/workspace/session5/exercise_2/build/Test/test_project[1]_tests.cmake")
  include("C:/Users/meret/Desktop/Softwareingeniør/4. semester/ESW/opgaver/workspace/session5/exercise_2/build/Test/test_project[1]_tests.cmake")
else()
  add_test(test_project_NOT_BUILT test_project_NOT_BUILT)
endif()
