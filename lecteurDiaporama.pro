TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        diaporama.cpp \
        image.cpp \
        lecteur.cpp \
        main.cpp \
        sousProgrammes.cpp

HEADERS += \
    diaporama.h \
    image.h \
    lecteur.h \
    sousProgrammes.h

DISTFILES += \
    .gitignore
