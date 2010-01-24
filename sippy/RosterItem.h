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

#ifndef ROSTERITEM_H
#define ROSTERITEM_H

#include <QWidget>
#include "SparkleAddress.h"

class Contact;
class QLabel;
class QVBoxLayout;
class QListWidgetItem;
class MessagingApplicationLayer;
class SparkleNode;

class RosterItem : public QWidget {
	Q_OBJECT
public:
	RosterItem(MessagingApplicationLayer &appLayer, Contact* contact, QListWidgetItem* listItem);

	QListWidgetItem *listItem() const;
	void setSelected(bool selected);
	void setDetailed(bool detailed);

protected:
	void contextMenuEvent(QContextMenuEvent *e);

signals:
	void menuRequested(QPoint point);

private slots:
	void update();
	void processStateChange(SparkleAddress node);

private:
	Contact* contact;

	QLabel *name, *info;
	QVBoxLayout *layout;
	QListWidgetItem *_listItem;
	MessagingApplicationLayer &appLayer;
	bool selected;
};

#endif // ROSTERITEM_H
