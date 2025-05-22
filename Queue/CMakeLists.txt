cmake_minimum_required(VERSION 3.15)

project(QueueProject LANGUAGES CXX)

# خلي C++17 أو أعلى (مطلوب لدعم بعض الميزات مثل std::optional لو تستخدمه)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# اجمع كل ملفات المصدر
set(SOURCES
    src/test.cpp
)

# أضف الـ include directory علشان تلاقي الهيدرز
include_directories(include)

# أنشئ التنفيذية
add_executable(queue_test ${SOURCES})
