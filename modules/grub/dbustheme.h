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
 * Command line was: qdbusxml2cpp -c GrubThemeDbus -p dbustheme.h:dbustheme.cpp dbus.xml
 *
 * qdbusxml2cpp is Copyright (C) 2015 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef DBUSTHEME_H_1438827234
#define DBUSTHEME_H_1438827234

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
#include <QColor>

/*
 * Proxy class for interface com.deepin.daemon.Grub2.Theme
 */
class GrubThemeDbus: public QDBusAbstractInterface
{
    Q_OBJECT

    Q_SLOT void __propertyChanged__(const QDBusMessage& msg)
    {
        QList<QVariant> arguments = msg.arguments();
        if (3 != arguments.count())
            return;
        QString interfaceName = msg.arguments().at(0).toString();
        if (interfaceName !="com.deepin.daemon.Grub2.Theme")
            return;
        QVariantMap changedProps = qdbus_cast<QVariantMap>(arguments.at(1).value<QDBusArgument>());
        QStringList keys = changedProps.keys();
        foreach(const QString &prop, keys) {
        const QMetaObject* self = metaObject();
            for (int i=self->propertyOffset(); i < self->propertyCount(); ++i) {
                QMetaProperty p = self->property(i);
                if (p.name() == prop) {
                    QVariant v = p.read(this);
                    Q_EMIT p.notifySignal().invoke(this, QGenericArgument(v.typeName(), v.data()));
                }
            }
        }
    }
public:
    static inline const char *staticServerPath()
    { return "com.deepin.daemon.Grub2"; }
    static inline const char *staticInterfacePath()
    { return "/com/deepin/daemon/Grub2/Theme"; }
    static inline const char *staticInterfaceName()
    { return "com.deepin.daemon.Grub2.Theme"; }

public:
    GrubThemeDbus(QObject *parent = 0);

    ~GrubThemeDbus();

    Q_PROPERTY(QString Background READ background NOTIFY backgroundChanged)
    inline QString background() const
    { return qvariant_cast< QString >(property("Background")); }

    Q_PROPERTY(QString ItemColor READ itemColor WRITE setItemColor NOTIFY itemColorChanged)
    inline QString itemColor() const
    { return qvariant_cast< QString >(property("ItemColor")); }
    inline void setItemColor(const QColor &value)
    { setProperty("ItemColor", QVariant::fromValue(value.name())); }

    Q_PROPERTY(QString SelectedItemColor READ selectedItemColor WRITE setSelectedItemColor NOTIFY selectedItemColorChanged)
    inline QString selectedItemColor() const
    { return qvariant_cast< QString >(property("SelectedItemColor")); }
    inline void setSelectedItemColor(const QColor &value)
    { setProperty("SelectedItemColor", QVariant::fromValue(value.name())); }

    Q_PROPERTY(bool Updating READ updating  NOTIFY updatingChanged)
    inline bool updating() const
    { return qvariant_cast< bool >(property("Updating")); }

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<bool> SetBackgroundSourceFile(const QString &in0)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0);
        return asyncCallWithArgumentList(QStringLiteral("SetBackgroundSourceFile"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void backgroundChanged(QString Background);
    void itemColorChanged(QString ItemColor);
    void selectedItemColorChanged(QString SelectedItemColor);
    void updatingChanged(bool Updating);
};

namespace com {
  namespace deepin {
    namespace daemon {
      namespace Grub2 {
        typedef ::GrubThemeDbus Theme;
      }
    }
  }
}
#endif
