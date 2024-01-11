QT       += core gui sql network
QT += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    achat.cpp \
    achatlistes.cpp \
    actif.cpp \
    authen.cpp \
    authen1.cpp \
    authen2.cpp \
    authen3.cpp \
    benefice.cpp \
    compteachat.cpp \
    comptedepense.cpp \
    comptemarchandise.cpp \
    comptevente.cpp \
    connexion.cpp \
    depense1.cpp \
    fichevente.cpp \
    listeachat.cpp \
    listedepense.cpp \
    listemarchandise.cpp \
    listeuser.cpp \
    listevente.cpp \
    main.cpp \
    accueil.cpp \
    main2.cpp \
    marchandise.cpp \
    modifierachat.cpp \
    modifierdepense.cpp \
    modifiermarchandise.cpp \
    modifiervente.cpp \
    rapportdachat.cpp \
    rapportdepense.cpp \
    recherche.cpp \
    redigerrapportachat.cpp \
    redigerrapportdepense.cpp \
    reseau.cpp \
    same.cpp \
    server.cpp \
    start.cpp \
    tabwidget.cpp \
    test.cpp \
    test2.cpp \
    utilisateur.cpp \
    vente.cpp

HEADERS += \
    accueil.h \
    achat.h \
    achatlistes.h \
    actif.h \
    authen.h \
    authen1.h \
    authen2.h \
    authen3.h \
    benefice.h \
    compteachat.h \
    comptedepense.h \
    comptemarchandise.h \
    comptevente.h \
    connexion.h \
    depense1.h \
    fichevente.h \
    listeachat.h \
    listedepense.h \
    listemarchandise.h \
    listeuser.h \
    listevente.h \
    main2.h \
    marchandise.h \
    modifierachat.h \
    modifierdepense.h \
    modifiermarchandise.h \
    modifiervente.h \
    rapportdachat.h \
    rapportdepense.h \
    recherche.h \
    redigerrapportachat.h \
    redigerrapportdepense.h \
    reseau.h \
    same.h \
    server.h \
    start.h \
    tabwidget.h \
    test.h \
    test2.h \
    utilisateur.h \
    vente.h

FORMS += \
    accueil.ui \
    achat.ui \
    achatlistes.ui \
    actif.ui \
    authen.ui \
    authen1.ui \
    authen2.ui \
    authen3.ui \
    benefice.ui \
    compteachat.ui \
    comptedepense.ui \
    comptemarchandise.ui \
    comptevente.ui \
    connexion.ui \
    depense1.ui \
    fichevente.ui \
    listeachat.ui \
    listedepense.ui \
    listemarchandise.ui \
    listeuser.ui \
    listevente.ui \
    main2.ui \
    marchandise.ui \
    modifierachat.ui \
    modifierdepense.ui \
    modifiermarchandise.ui \
    modifiervente.ui \
    rapportdachat.ui \
    rapportdepense.ui \
    recherche.ui \
    redigerrapportachat.ui \
    redigerrapportdepense.ui \
    reseau.ui \
    same.ui \
    server.ui \
    start.ui \
    tabwidget.ui \
    test.ui \
    test2.ui \
    utilisateur.ui \
    vente.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../../Documents/Menu/design.qrc \
    ../../Documents/Menu/fond.qrc \
    ../../Documents/Menu/fond2.qrc \
    ../../Documents/Menu/lgo2.qrc \
    ../../Documents/Menu/logen.qrc \
    ../../Documents/Menu/login.qrc \
    ../../Documents/Menu/logo.qrc \
    ../../Documents/Menu/logo.qrc \
    ../../Documents/Menu/logo1.qrc \
    ../../Documents/Menu/logo2.qrc \
    ../../Documents/Menu/marchan.qrc \
    ../Menu/image10.qrc \
    ../Menu/image10.qrc \
    ../Menu/image11.qrc \
    ../Menu/image2.qrc \
    ../Menu/image2.qrc \
    ../Menu/image2.qrc \
    ../Menu/image4.qrc \
    ../Menu/image4.qrc \
    ../Menu/image5.qrc \
    ../Menu/image6.qrc \
    ../Menu/image6.qrc \
    ../Menu/image7.qrc \
    ../Menu/image7.qrc \
    ../Menu/image8.qrc \
    ../Menu/image8.qrc \
    ../Menu/image9.qrc \
    ../Menu/image9.qrc






win32: LIBS += -L$$PWD/../../Desktop/lib/ -llibmysql

INCLUDEPATH += $$PWD/../../Desktop
DEPENDPATH += $$PWD/../../Desktop

win32: LIBS += -L$$PWD/../../Downloads/mysql-connector-c-6.1.11-winx64/mysql-connector-c-6.1.11-winx64/lib/ -llibmysql

INCLUDEPATH += $$PWD/../../Downloads/mysql-connector-c-6.1.11-winx64/mysql-connector-c-6.1.11-winx64/include
DEPENDPATH += $$PWD/../../Downloads/mysql-connector-c-6.1.11-winx64/mysql-connector-c-6.1.11-winx64/include
