# #####################################################################
# Automatically generated by qmake (2.01a) ?? ???. 16 12:09:27 2009
# #####################################################################
TEMPLATE = lib
TARGET = sparkle
DEPENDPATH += . \
	crypto \
	headers \
	headers/crypto
INCLUDEPATH += . \
	headers \
	headers/crypto
CONFIG += staticlib
QT -= gui
QT += network
contains(QMAKESPEC,g++):QMAKE_CFLAGS += -Wconversion
contains(QMAKESPEC,msvc):DEFINES += CRT_SECURE_NO_WARNINGS
# Input
HEADERS += headers/BlowfishKey.h \
	headers/LinkLayer.h \
	headers/Log.h \
	headers/PacketTransport.h \
	headers/random.h \
	headers/Router.h \
	headers/RSAKeyPair.h \
	headers/SHA1Digest.h \
	headers/SparkleNode.h \
	headers/UdpPacketTransport.h \
	headers/crypto/bignum.h \
	headers/crypto/bn_mul.h \
	headers/crypto/havege.h \
	headers/crypto/rsa.h \
	headers/crypto/sha1.h \
	headers/crypto/timing.h \
	headers/ApplicationLayer.h \
	headers/SparkleAddress.h
SOURCES += BlowfishKey.cpp \
	LinkLayer.cpp \
	Log.cpp \
	random.cpp \
	Router.cpp \
	RSAKeyPair.cpp \
	SHA1Digest.cpp \
	SparkleNode.cpp \
	UdpPacketTransport.cpp \
	crypto/bignum.c \
	crypto/blowfish.c \
	crypto/havege.c \
	crypto/rsa.c \
	crypto/sha1.c \
	crypto/timing.c \
	SparkleAddress.cpp
