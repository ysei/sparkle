/*
 * Sparkle - zero-configuration fully distributed self-organizing encrypting VPN
 * Copyright (C) 2009 Sergey Gridassov, Peter Zotov
 *
 * Ths program is free software: you can redistribute it and/or modify
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


#ifndef __SPARKLE_NODE__H__
#define __SPARKLE_NODE__H__

#include <Sparkle/Sparkle>

#include <QObject>
#include <QHostAddress>

namespace Sparkle {

class SparkleAddress;
class SparkleNodePrivate;
class BlowfishKey;
class Router;
class RSAKeyPair;

class SPARKLE_DECL SparkleNode : public QObject
{
	Q_OBJECT
	Q_DECLARE_PRIVATE(SparkleNode)

protected:
	SparkleNode(SparkleNodePrivate &dd, QObject *parent);

public:
	SparkleNode(Router& router, QHostAddress realIP, quint16 realPort);
	virtual ~SparkleNode();
	
	bool operator==(const SparkleNode& another) const;
	bool operator!=(const SparkleNode& another) const;

	const QHostAddress &realIP() const;
	quint16 realPort() const;

	const QHostAddress &phantomIP() const;
	quint16 phantomPort() const;

	const SparkleAddress &sparkleMAC() const;

	bool isBehindNAT() const;
	void setBehindNAT(bool behindNAT);

	void setSparkleMAC(const SparkleAddress& mac);

	void setRealIP(const QHostAddress& ip);
	void setRealPort(quint16 port);

	void setPhantomIP(const QHostAddress& ip);
	void setPhantomPort(quint16 port);

	const BlowfishKey *hisSessionKey() const;
	const BlowfishKey *mySessionKey() const;

	const RSAKeyPair *authKey() const;

	bool setAuthKey(const RSAKeyPair &keyPair);
	bool setAuthKey(const QByteArray &publicKey);

	void configure();
	static SparkleAddress addressFromKey(const RSAKeyPair *keyPair);

	void setHisSessionKey(const QByteArray &keyBytes);
	bool areKeysNegotiated();

	void cloneKeys(SparkleNode* node);

	void setMaster(bool isMaster);
	bool isMaster();

	bool isQueueEmpty();
	void pushQueue(QByteArray data);
	QByteArray popQueue();
	void flushQueue();

public slots:
	void negotiationStart();
	void negotiationFinished();

signals:
	void negotiationTimedOut(SparkleNode*);

private slots:
	void negotiationTimeout();

protected:
	SparkleNodePrivate * const d_ptr;
};

}

#endif
