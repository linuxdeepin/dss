/**
 * Copyright (C) 2015 Deepin Technology Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 **/

/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -c DbusLangSelector -p dbuslangselector.h:dbuslangselector.cpp file
 *
 * qdbusxml2cpp is Copyright (C) 2015 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#include "dbuslangselector.h"
#include <QDataStream>

/*
 * Implementation of interface class DbusLangSelector
 */

DbusLangSelector::DbusLangSelector(QObject *parent)
    : QDBusAbstractInterface(staticServiceName(), staticObjectPath(), staticInterfaceName(), QDBusConnection::sessionBus(), parent)
{
    qDBusRegisterMetaType<LocaleInfo>();
    qDBusRegisterMetaType<LocaleList>();
    QDBusConnection::sessionBus().connect(this->service(), this->path(), "org.freedesktop.DBus.Properties",  "PropertiesChanged","sa{sv}as", this, SLOT(__propertyChanged__(QDBusMessage)));
}

DbusLangSelector::~DbusLangSelector()
{
    QDBusConnection::sessionBus().disconnect(service(), path(), "org.freedesktop.DBus.Properties",  "PropertiesChanged",  "sa{sv}as", this, SLOT(propertyChanged(QDBusMessage)));
}



QDBusArgument &operator<<(QDBusArgument &arg, const LocaleInfo &info)
{
    arg.beginStructure();
    arg << info.id << info.name;
    arg.endStructure();

    return arg;
}


const QDBusArgument &operator>>(const QDBusArgument &arg, LocaleInfo &info)
{
    arg.beginStructure();
    arg >> info.id >> info.name;
    arg.endStructure();

    return arg;
}

QDataStream &operator<<(QDataStream &ds, const LocaleInfo &info)
{
    return ds << info.id << info.name;
}

const QDataStream &operator>>(QDataStream &ds, LocaleInfo &info)
{
    return ds >> info.id >> info.name;
}
