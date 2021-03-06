/*
 * Copyright (C) 2011 ~ 2019 Deepin Technology Co., Ltd.
 *
 * Author:     liuhong <liuhong_cm@deepin.com>
 *
 * Maintainer: liuhong <liuhong_cm@deepin.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "systeminfowidget.h"
#include "window/utils.h"
#include "widgets/multiselectlistview.h"

#include <DStandardItem>

#include <QVBoxLayout>
#include <QStandardItemModel>
#include <QIcon>
#include <QList>
#include <QSettings>
#include <QDebug>
#include <QDir>

DWIDGET_USE_NAMESPACE
using namespace DCC_NAMESPACE::systeminfo;

SystemInfoWidget::SystemInfoWidget(QWidget *parent)
    : QWidget(parent)
    , m_mainContentLayout(new QVBoxLayout(this))
    , m_listView(new dcc::widgets::MultiSelectListView(this))
    , m_itemModel(new QStandardItemModel(this))
{
    initWidget();
    initData();
}

void SystemInfoWidget::initWidget()
{
    m_listView->setAccessibleName("List_ systeminfomenulist");
    m_listView->setFrameShape(QFrame::NoFrame);
    m_listView->setEditTriggers(QListView::NoEditTriggers);
    m_listView->setModel(m_itemModel);
    m_listView->setViewportMargins(ScrollAreaMargins);
    m_listView->setIconSize(ListViweIconSize);
    m_listView->setItemSize(ListViweSysItemSize);

    m_mainContentLayout->setMargin(0);
    m_mainContentLayout->addWidget(m_listView);

    setLayout(m_mainContentLayout);
}

void SystemInfoWidget::initData()
{
    m_itemList = {
        //~ contents_path /systeminfo/About This PC
        {"dcc_on_sel", tr("About This PC"), QMetaMethod::fromSignal(&SystemInfoWidget::requestShowAboutNative)},
        //~ contents_path /systeminfo/Edition License
        {"dcc_version", tr("Edition License"), QMetaMethod::fromSignal(&SystemInfoWidget::requestShowVersionProtocol)},
        //~ contents_path /systeminfo/End User License Agreement
        {"dcc_protocol", tr("End User License Agreement"), QMetaMethod::fromSignal(&SystemInfoWidget::requestShowEndUserLicenseAgreement)},
        //~ contents_path /systeminfo/Privacy Policy
        {"dcc_privacy_policy", tr("Privacy Policy"), QMetaMethod::fromSignal(&SystemInfoWidget::requestShowPrivacyPolicy)}
    };

    for (auto m : m_itemList) {
        DStandardItem *item = new DStandardItem;
        item->setIcon(QIcon::fromTheme(m.itemIcon));
        item->setText(m.itemText);
        item->setData(VListViewItemMargin, Dtk::MarginsRole);
        m_itemModel->appendRow(item);
    }

   if(InsertPlugin::instance()->needPushPlugin("systeminfo"))
        InsertPlugin::instance()->pushPlugin(m_itemModel,m_itemList);

    connect(m_listView, &DListView::clicked, this, [&](const QModelIndex & index) {
        if (m_lastIndex == index)
            return;

        m_lastIndex = index;
        m_itemList[index.row()].itemSignal.invoke(m_itemList[index.row()].pulgin ? m_itemList[index.row()].pulgin : this);
        m_listView->resetStatus(index);
    });
    connect(m_listView, &DListView::activated, m_listView, &QListView::clicked);
}

DListView *SystemInfoWidget::getSystemListViewPointer()
{
    return m_listView;
}

void SystemInfoWidget::setCurrentIndex(int index)
{
    QModelIndex mindex = m_itemModel->index(index, 0);
    m_listView->setCurrentIndex(mindex);
    Q_EMIT m_listView->clicked(mindex);
}
