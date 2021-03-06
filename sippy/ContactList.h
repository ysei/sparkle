/*
 * Sippy - zero-configuration fully distributed self-organizing encrypting IM
 * Copyright (C) 2010 Peter Zotov
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

#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include <QObject>
#include <QList>

class Contact;
class ConfigurationStorage;

namespace Sparkle {
	class SparkleAddress;
}

class ContactList : public QObject
{
	Q_OBJECT
public:
	ContactList();

	QList<Contact*> contacts();
	bool addContact(Contact*);
	bool removeContact(Contact*);

	Contact* findByAddress(Sparkle::SparkleAddress address);
	bool hasAddress(Sparkle::SparkleAddress address);

public slots:
	void load();
	void save();

signals:
	void contactAdded(Contact*);
	void contactRemoved(Contact*);

private:
	void clear();

	QList<Contact*> _contacts;
	ConfigurationStorage* config;
};

#endif // CONTACTLIST_H
