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
 * Command line was: qdbusxml2cpp -c ShortcutDbus -p shortcutdbus file
 *
 * qdbusxml2cpp is Copyright (C) 2015 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef SHORTCUTDBUS_H_1440551625
#define SHORTCUTDBUS_H_1440551625

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface com.deepin.daemon.Keybinding
 */

struct ShortcutInfo{
    qint16 listType;
    qint32 type;
    qint32 id;
    QString strId;
    QString title;
    QString shortcut;

    bool operator==(const ShortcutInfo& info){
        return id == info.id;
    }
};

typedef QList<ShortcutInfo> ShortcutInfoList;

class ShortcutDbus: public QDBusAbstractInterface
{
    Q_OBJECT

public:
    static inline const char *staticServerPath()
    { return "com.deepin.daemon.Keybinding"; }
    static inline const char *staticInterfacePath()
    { return "/com/deepin/daemon/Keybinding"; }
    static inline const char *staticInterfaceName()
    { return "com.deepin.daemon.Keybinding"; }

    enum ListType{
        SystemList,
        WindowList,
        WorkspaceList,
        CustomList
    };

public:
    ShortcutDbus(QObject *parent = 0);

    ~ShortcutDbus();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<QString, bool> Add(const QString &in0, const QString &in1, const QString &in2)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2);
        return asyncCallWithArgumentList(QStringLiteral("Add"), argumentList);
    }
    inline QDBusReply<QString> Add(const QString &in0, const QString &in1, const QString &in2, bool &out1)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2);
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("Add"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 2) {
            out1 = qdbus_cast<bool>(reply.arguments().at(1));
        }
        return reply;
    }

    inline QDBusPendingReply<bool, QString> CheckAvaliable(const QString &in0)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0);
        return asyncCallWithArgumentList(QStringLiteral("CheckAvaliable"), argumentList);
    }
    inline QDBusReply<bool> CheckAvaliable(const QString &in0, QString &out1)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0);
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("CheckAvaliable"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 2) {
            out1 = qdbus_cast<QString>(reply.arguments().at(1));
        }
        return reply;
    }

    inline QDBusPendingReply<> Delete(const QString &in0, int in1)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1);
        return asyncCallWithArgumentList(QStringLiteral("Delete"), argumentList);
    }

    inline QDBusPendingReply<> Disable(const QString &in0, int in1)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1);
        return asyncCallWithArgumentList(QStringLiteral("Disable"), argumentList);
    }

    inline QDBusPendingReply<> GrabScreen()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("GrabScreen"), argumentList);
    }

    inline QDBusPendingReply<QString> List()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("List"), argumentList);
    }

    inline QDBusPendingReply<bool, QString> ModifiedAccel(const QString &in0, int in1, const QString &in2, bool in3)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2) << QVariant::fromValue(in3);
        return asyncCallWithArgumentList(QStringLiteral("ModifiedAccel"), argumentList);
    }
    inline QDBusReply<bool> ModifiedAccel(const QString &in0, int in1, const QString &in2, bool in3, QString &out1)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2) << QVariant::fromValue(in3);
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("ModifiedAccel"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 2) {
            out1 = qdbus_cast<QString>(reply.arguments().at(1));
        }
        return reply;
    }

    inline QDBusPendingReply<> ModifiedAction(const QString &in0, int in1, const QString &in2)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2);
        return asyncCallWithArgumentList(QStringLiteral("ModifiedAction"), argumentList);
    }

    inline QDBusPendingReply<> ModifiedName(const QString &in0, int in1, const QString &in2)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2);
        return asyncCallWithArgumentList(QStringLiteral("ModifiedName"), argumentList);
    }

    inline void Reset()
    {
        call(QStringLiteral("Reset"));
        updateShortcutList("", -1);
    }

    inline QDBusPendingReply<QString> Query(const QString &in0, int in1)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1);
        return asyncCallWithArgumentList(QStringLiteral("Query"), argumentList);
    }

    inline const ShortcutInfoList& customList() const
    {
        return m_customList;
    }

    inline const ShortcutInfoList& systemList() const
    {
        return m_systemList;
    }

    inline const ShortcutInfoList windowList() const
    {
        return m_windowList;
    }

    inline const ShortcutInfoList workspaceList() const
    {
        return m_workspaceList;
    }

    inline QString CheckShortcutConflict(const QString &in0)
    {
        QString tmp;
        bool result = CheckAvaliable(in0, tmp).value();

        if(result)
            return "Valid";

        return "Conflict";
    }

    inline bool AddCustomShortcut(const QString &in0, const QString &in1)
    {
        bool result = true;
        Add(in0, in1, "", result);

        return !result;
    }

    inline void ModifyShortcut(int in0, const QString &in1)
    {
        const ShortcutInfo *info = m_intIdToInfoMap[in0];
        if(!info)
            return;

        QString str;

        if(info->shortcut != tr("None")){
            ModifiedAccel(info->strId, info->type, info->shortcut, false, str).value();//remove
        }

        if(!in1.isEmpty() && in1 != tr("None"))
            ModifiedAccel(info->strId, info->type, in1, true, str).value();

    }

    inline void DeleteCustomShortcut(int in0)
    {
        const ShortcutInfo *info = m_intIdToInfoMap[in0];
        if(!info)
            return;

        Delete(info->strId, info->type);
    }

Q_SIGNALS: // SIGNALS
    void Added(const QString &in0, qint32);
    void Changed(const QString &in0, qint32);
    void Deleted(const QString &in0, qint32);
    void KeyEvent(bool in0, const QString &in1);
// begin property changed signals
    void KeyPressEvent(const QString &in0);
    void KeyReleaseEvent(const QString &in0);
    void customListChanged(const ShortcutInfoList &CustomList);
    void systemListChanged(const ShortcutInfoList &SystemList);
    void windowListChanged(const ShortcutInfoList &WindowList);
    void workspaceListChanged(const ShortcutInfoList &WorkspaceList);

private:
    ShortcutInfoList m_systemList;
    ShortcutInfoList m_windowList;
    ShortcutInfoList m_workspaceList;
    ShortcutInfoList m_customList;
    QHash<QString, ShortcutInfo*> m_idToInfoListHash;
    QMap<QString, ShortcutInfo*> m_strIdAndTypeToInfoMap;
    QMap<int, ShortcutInfo*> m_intIdToInfoMap;
    int m_intId = 0;

    int getId();
    QString getId(int type, const QString &id) const;
    Q_SLOT void updateShortcutList(const QString &in0, qint32 type);
    Q_SLOT void onAdded(const QString &id, qint32 type);
    Q_SLOT void onDeleted(const QString &id, qint32 type);
    Q_SLOT void getListFinished(QDBusPendingCallWatcher *call);
};

namespace com {
  namespace deepin {
    namespace daemon {
      typedef ::ShortcutDbus Keybinding;
    }
  }
}
#endif
