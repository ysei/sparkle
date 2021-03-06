/*
 * Sparkle - zero-configuration fully distributed self-organizing encrypting VPN
 * Copyright (C) 2009 Sergey Gridassov
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __TAP_INTERFACE__H__
#define __TAP_INTERFACE__H__

#include <QByteArray>
#include <QObject>
#include <QHostAddress>
#include <Sparkle/SparkleAddress>

class TapInterface: public QObject {
	Q_OBJECT

public:
	TapInterface(QObject *parent = 0) : QObject(parent) { }
	virtual ~TapInterface() { }

public slots:
	virtual void setupInterface(Sparkle::SparkleAddress ha, QHostAddress ip) = 0;
	virtual void sendPacket(QByteArray packet) = 0;

signals:
	void havePacket(QByteArray packet);
};

#endif

