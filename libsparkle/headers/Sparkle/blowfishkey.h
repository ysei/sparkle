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

#ifndef __BLOWFISH__H__
#define __BLOWFISH__H__

#include <Sparkle/Sparkle>

#include <QObject>

namespace Sparkle {

class BlowfishKeyPrivate;

class SPARKLE_DECL BlowfishKey: public QObject
{
	Q_OBJECT
	Q_DECLARE_PRIVATE(BlowfishKey)
	
protected:
	BlowfishKey(BlowfishKeyPrivate &d, QObject *parent);
	
public:
	explicit BlowfishKey(QObject *parent = 0);
	virtual ~BlowfishKey();

	void generate();

	QByteArray bytes() const;
	void setBytes(QByteArray raw);

	QByteArray encrypt(QByteArray data) const;
	QByteArray decrypt(QByteArray data) const;

protected:
	BlowfishKeyPrivate * const d_ptr;
};

}

#endif
