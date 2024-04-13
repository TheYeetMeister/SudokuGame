QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../source/sudoku.cpp \
    ../../source/sudoku_generator.cpp \
    game.cpp \
    main.cpp \
    sudokumainwindow.cpp \
    victoryscreen.cpp

HEADERS += \
    ../../source/sudoku.h \
    ../../source/sudoku_generator.h \
    game.h \
    sudokumainwindow.h \
    victoryscreen.h

FORMS += \
    game.ui \
    sudokumainwindow.ui \
    victoryscreen.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../imgs/win_imgs/confetti.gif \
    ../../imgs/win_imgs/crown.png \
    ../../imgs/win_imgs/datboi.gif \
    ../../imgs/win_imgs/frog_dance.gif \
    ../../imgs/win_imgs/golden-star.png \
    ../../imgs/win_imgs/med-evil-winimg.png \
    ../../imgs/win_imgs/north-star.png \
    ../../imgs/win_imgs/rainbow-star.png \
    ../../imgs/win_imgs/veryeasy-easy.winimg.png \
    ../../imgs/win_imgs/veryeasy_star.png \
    win_imgs/confetti.gif \
    win_imgs/crown.png \
    win_imgs/datboi.gif \
    win_imgs/frog_dance.gif \
    win_imgs/golden-star.png \
    win_imgs/med-evil-winimg.png \
    win_imgs/north-star.png \
    win_imgs/rainbow-star.png \
    win_imgs/veryeasy-easy.winimg.png \
    win_imgs/veryeasy_star.png
