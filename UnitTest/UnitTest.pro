TEMPLATE = app
CONFIG += console c++11

QT += sql
QT += widgets

SOURCES += \
        main.cpp\
        ../../gtest/googletest/src/gtest-all.cc

HEADERS += ../Application/DataBase/UserInfo/adopter.h\
           ../Application/DataBase/UserInfo/user.h\
           ../Application/project/all.h\
           ../Application/DataBase/database.h\
           ../Application/DataBase/animal.h\
           ../Application/DataBase/searchengine.h\
           ../Application/Dam/adopterdam.h\
           ../Application/Dam/wishlistdam.h\
           ../Application/Dam/animaldam.h\
           ../Application/Dam/orderdam.h\
           ../Application/Dam/postdam.h\
           ../Application/Dam/shelterdam.h\
           ../Application/Dam/tagdam.h\
           ../Application/Dam/traitdam.h\
           ../Application/DataBase/UserInfo/employee.h \
           ../Application/DataBase/recommendedlist.h \
           ../Application/DataBase/shelter.h \
           ../Application/DataBase/tag.h \
           ../Application/DataBase/wishlist.h \
           ../Application/DataBase/trait.h \
           ../Application/DataBase/UserInfo/adopter.h \
           ../Application/DataBase/UserInfo/user.h \
           ../Application/DataBase/order.h \
           ../Application/DataBase/livesin.h \
           ../Application/DataBase/community.h \
           ../Application/DataBase/post.h\
           ../Application/Dam/employeedam.h



SOURCES += ../Application/DataBase/UserInfo/adopter.cpp\
           ../Application/DataBase/UserInfo/user.cpp\
           ../Application/DataBase/database.cpp\
           ../Application/DataBase/animal.cpp\
           ../Application/DataBase/searchengine.cpp\
           ../Application/Dam/animaldam.cpp\
           ../Application/Dam/adopterdam.cpp\
           ../Application/Dam/wishlistdam.cpp\
           ../Application/Dam/orderdam.cpp\
           ../Application/Dam/postdam.cpp\
           ../Application/Dam/shelterdam.cpp\
           ../Application/Dam/tagdam.cpp\
           ../Application/Dam/traitdam.cpp\
           ../Application/DataBase/UserInfo/employee.cpp \
           ../Application/DataBase/Location/filereader.cpp \
           ../Application/DataBase/recommendedlist.cpp \
           ../Application/DataBase/shelter.cpp \
           ../Application/DataBase/tag.cpp \
           ../Application/DataBase/wishlist.cpp \
           ../Application/DataBase/trait.cpp \
           ../Application/DataBase/UserInfo/adopter.cpp \
           ../Application/DataBase/order.cpp \
           ../Application/DataBase/community.cpp \
           ../Application/DataBase/post.cpp\
           ../Application/Dam/employeedam.cpp

INCLUDEPATH += ../../gtest \
 ../../gtest/googletest \
 ../../gtest/googletest/include \
 ../../gtest/googletest/include/gtest
