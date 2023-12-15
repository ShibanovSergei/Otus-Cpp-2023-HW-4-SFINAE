cmake_minimum_required (VERSION 3.2)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("HW_04_SFINAE")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (hw_04cli "main.cpp" "main.h" "print_ip.h" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET hw_04cli PROPERTY CXX_STANDARD 20)
endif()


