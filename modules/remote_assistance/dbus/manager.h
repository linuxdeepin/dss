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
 * Command line was: qdbusxml2cpp -p manager /home/liliqiang/workspace/deepin/dbus-factory/xml/com.deepin.daemon.Remoting.Manager.xml
 *
 * qdbusxml2cpp is Copyright (C) 2015 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef MANAGER_H
#define MANAGER_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface com.deepin.daemon.Remoting.Manager
 */
class ComDeepinDaemonRemotingManagerInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "com.deepin.daemon.Remoting.Manager"; }

public:
    ComDeepinDaemonRemotingManagerInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~ComDeepinDaemonRemotingManagerInterface();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<int> CheckNetworkConnectivity()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("CheckNetworkConnectivity"), argumentList);
    }

    inline QDBusPendingReply<int> GetStatus()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("GetStatus"), argumentList);
    }

Q_SIGNALS: // SIGNALS
};

namespace com {
  namespace deepin {
    namespace daemon {
      namespace Remoting {
        typedef ::ComDeepinDaemonRemotingManagerInterface Manager;
      }
    }
  }
}
#endif
