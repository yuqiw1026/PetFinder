TEMPLATE = app
CONFIG += console c++11

QT += core
QT += sql
QT += gui
QT += widgets
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../Dam/adopterdam.cpp \
    ../Dam/employeedam.cpp \
    ../Dam/recommendedlistdam.cpp \
    ../Dam/shelterdam.cpp \
    ../Dam/tagdam.cpp \
    ../Dam/traitdam.cpp \
    ../Dam/wishlistdam.cpp \
    ../Dam/animaldam.cpp \
    ../Dam/orderdam.cpp \
    ../Dam/postdam.cpp \
    ../DataBase/UserInfo/employee.cpp \
    ../DataBase/Location/filereader.cpp \
    ../DataBase/recommendedlist.cpp \
    ../DataBase/searchengine.cpp \
    ../DataBase/shelter.cpp \
    ../DataBase/tag.cpp \
    ../DataBase/wishlist.cpp \
    ../DataBase/trait.cpp \
    ../GUI/accountinfo.cpp \
    ../GUI/aftersignout.cpp \
    ../GUI/cat.cpp \
    ../GUI/display.cpp \
    ../GUI/dog.cpp \
    ../GUI/guicontroller.cpp \
    ../GUI/logind.cpp \
    main.cpp \
    ../DataBase/UserInfo/adopter.cpp \
    ../DataBase/UserInfo/user.cpp \
    ../DataBase/database.cpp \
    ../DataBase/animal.cpp \
    ../DataBase/order.cpp \
    ../DataBase/community.cpp \
    ../DataBase/post.cpp \
    ../GUI/newmenu.cpp \
    ../GUI/newpost.cpp \
    ../GUI/other.cpp \
    ../GUI/questionaire.cpp \
    ../GUI/regispage.cpp \
    ../GUI/communitypage.cpp \
    ../GUI/epypage.cpp \
    ../GUI/aboutpage.cpp \
    ../GUI/mypreference.cpp \
    ../GUI/mywishlist.cpp \
    ../GUI/animalinfos.cpp \
    ../GUI/specificanimal.cpp \
    ../GUI/payment.cpp \
    ../GUI/resultanimal.cpp \
    ../GUI/adopterorder.cpp \
    ../GUI/employeeorder.cpp \
    ../GUI/detailorder.cpp

HEADERS += \
    ../DataBase/Location/filereader.h \
    ../DataBase/searchengine.h \
    ../project/all.h \
    ../Dam/adopterdam.h \
    ../Dam/employeedam.h \
    ../Dam/recommendedlistdam.h \
    ../Dam/shelterdam.h \
    ../Dam/tagdam.h \
    ../Dam/traitdam.h \
    ../Dam/wishlistdam.h \
    ../Dam/animaldam.h \
    ../Dam/orderdam.h \
    ../Dam/postdam.h \
    ../DataBase/UserInfo/employee.h \
    ../DataBase/recommendedlist.h \
    ../DataBase/shelter.h \
    ../DataBase/tag.h \
    ../DataBase/wishlist.h \
    ../DataBase/trait.h \
    ../GUI/accountinfo.h \
    ../GUI/aftersignout.h \
    ../GUI/cat.h \
    ../GUI/display.h \
    ../GUI/dog.h \
    ../GUI/guicontroller.h \
    ../GUI/logind.h \
    ../DataBase/UserInfo/adopter.h \
    ../DataBase/UserInfo/user.h \
    ../DataBase/database.h \
    ../DataBase/animal.h \
    ../DataBase/order.h \
    ../DataBase/livesin.h \
    ../DataBase/community.h \
    ../DataBase/post.h \
    ../GUI/newmenu.h \
    ../GUI/newpost.h \
    ../GUI/other.h \
    ../GUI/questionaire.h \
    ../GUI/regispage.h \
    ../GUI/communitypage.h \
    ../GUI/epypage.h \
    ../GUI/aboutpage.h \
    ../GUI/mypreference.h \
    ../GUI/mywishlist.h \
    ../GUI/animalinfos.h \
    ../GUI/specificanimal.h \
    ../GUI/payment.h \
    ../GUI/resultanimal.h \
    ../GUI/adopterorder.h \
    ../GUI/employeeorder.h \
    ../GUI/detailorder.h
FORMS += \
    ../GUI/accountinfo.ui \
    ../GUI/aftersignout.ui \
    ../GUI/cat.ui \
    ../GUI/display.ui \
    ../GUI/dog.ui \
    ../GUI/logind.ui \
    ../GUI/newmenu.ui \
    ../GUI/newpost.ui \
    ../GUI/other.ui \
    ../GUI/questionaire.ui \
    ../GUI/regispage.ui \
    ../GUI/communitypage.ui \
    ../GUI/epypage.ui \
    ../GUI/aboutpage.ui \
    ../GUI/mypreference.ui \
    ../GUI/mywishlist.ui \
    ../GUI/animalinfos.ui \
    EmployeeNewMenu.ui \
    ../GUI/specificanimal.ui \
    ../GUI/payment.ui \
    ../GUI/resultanimal.ui \
    ../GUI/adopterorder.ui \
    ../GUI/employeeorder.ui \
    ../GUI/detailorder.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
