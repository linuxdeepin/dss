
include(../../common.pri)

TEMPLATE        = lib
CONFIG         += plugin c++11 link_pkgconfig
QT             += widgets dbus
INCLUDEPATH    += ../../frame/ ../../widgets ../../helper
PKGCONFIG += dui
LIBS += -L../../widgets -lwidgets -L../../helper -lhelper

HEADERS         = defaultapps.h \
    dbus/dbusdefaultmedia.h \
    dbus/dbusdefaultapps.h
SOURCES         = defaultapps.cpp \
    dbus/dbusdefaultmedia.cpp \
    dbus/dbusdefaultapps.cpp
TARGET          = $$qtLibraryTarget(defaultapps)
DESTDIR         = $$_PRO_FILE_PWD_/../

DISTFILES += default_applications.json

target.path = $${PREFIX}/lib/dde-control-center/modules/
INSTALLS += target
