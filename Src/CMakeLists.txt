cmake_minimum_required(VERSION 3.16)
project(Insight VERSION 1.0 LANGUAGES CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 指定 Qt 路径
set(Qt6_DIR "C:/Qt/6/6.9.3/msvc2022_64/lib/cmake/Qt6")

# 查找 Qt 组件
find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick Sql Mqtt Charts Concurrent)

# 启用 Qt 工具链
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

qt_standard_project_setup(REQUIRES 6.5)

# 收集源文件
file(GLOB SOURCES
    "main.cpp"
    "Config/*.cpp"
    "Global/*.cpp"
    "Model/*.cpp"
    "Model/ModelImpl*.cpp"
    "Service/*.cpp"
    "Service/ServiceImpl/*.cpp"
    "Utils/*.cpp"
)

qt_add_executable(Insight ${SOURCES})

qt_add_qml_module(Insight
    URI Insight
    VERSION 1.0
    QML_FILES
    Qml/Main.qml
    RESOURCES Qml/qml.qrc
)

# 设置目标属性
set_target_properties(Insight PROPERTIES
    AUTOMOC ON
    AUTORCC ON
    AUTOUIC ON
    OUTPUT_NAME "HOIEditor"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)

# 链接 Qt 库
target_link_libraries(Insight PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::Sql
    Qt6::Mqtt
    Qt6::Charts
    Qt6::Concurrent
)

# 包含目录
target_include_directories(Insight PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Config
    ${CMAKE_CURRENT_SOURCE_DIR}/Global
    ${CMAKE_CURRENT_SOURCE_DIR}/Model
    ${CMAKE_CURRENT_SOURCE_DIR}/Service
    ${CMAKE_CURRENT_SOURCE_DIR}/Utils
)

# 解决 Vulkan 警告
target_compile_definitions(Insight PRIVATE QT_QUICK_BACKEND=software)