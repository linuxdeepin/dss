/*
 * Copyright (C) 2011 ~ 2019 Deepin Technology Co., Ltd.
 *
 * Author:     lq <longqi_cm@deepin.com>
 *
 * Maintainer: lq <longqi_cm@deepin.com>
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

#include "soundwidget.h"
#include "window/utils.h"
#include "modules/sound/soundworker.h"
#include "widgets/multiselectlistview.h"
#include <DStyleOption>

#include <QVBoxLayout>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QListView>
#include <QMargins>

using namespace DCC_NAMESPACE::sound;

SoundWidget::SoundWidget(QWidget *parent)
    : QWidget(parent)
    , m_menuList(new dcc::widgets::MultiSelectListView)
{
    setObjectName("Display");
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(0);

    m_menuList->setAccessibleName("List_soundmenulist");
    m_menuList->setEditTriggers(DListView::NoEditTriggers);
    m_menuList->setFrameShape(QFrame::NoFrame);
    m_menuList->setViewportMargins(ScrollAreaMargins);
    layout->addWidget(m_menuList, 1);
    initMenuUI();

   // layout->addStretch(1);
    setLayout(layout);
}

int SoundWidget::showPath(const QString &path)
{
    for (int i = 0; i < m_menuMethod.size(); ++i) {
        auto menu = m_menuMethod[i];
        if (tr(path.toStdString().c_str()) == menu.menuText) {
            menu.method.invoke(this);
            m_currentIdx = m_menuList->model()->index(i, 0);
            m_menuList->setCurrentIndex(m_currentIdx);
            return 0;
        }
    }

    return -1;
}

void SoundWidget::initMenuUI()
{
    m_menuMethod = {
        //~ contents_path /sound/Speaker
        { tr("Speaker"), "dcc_speaker", QMetaMethod::fromSignal(&SoundWidget::requsetSpeakerPage)},
        //~ contents_path /sound/Microphone
        { tr("Microphone"), "dcc_noun", QMetaMethod::fromSignal(&SoundWidget::requestMicrophonePage)},
///        //~ contents_path /sound/Advanced
        { tr("Advanced"), "dcc_setting", QMetaMethod::fromSignal(&SoundWidget::requestAdvancedPage)},
        //~ contents_path /sound/Sound Effects
        { tr("Sound Effects"), "dcc_sound_effect", QMetaMethod::fromSignal(&SoundWidget::requsetSoundEffectsPage)}
    };

    QStandardItemModel *listModel = new QStandardItemModel(this);
    for (auto mm : m_menuMethod) {
        DStandardItem *item = new DStandardItem(mm.menuText);
        item->setData(VListViewItemMargin, Dtk::MarginsRole);
        item->setIcon(QIcon::fromTheme(mm.iconName));
        listModel->appendRow(item);
    }

    m_menuList->setModel(listModel);
    m_menuList->setCurrentIndex(listModel->index(0, 0));
    m_currentIdx = m_menuList->currentIndex();
    connect(m_menuList, &QListView::clicked, [ = ](const QModelIndex & idx) {
        if (idx == m_currentIdx)
            return;

        m_currentIdx = idx;
        m_menuMethod[idx.row()].method.invoke(this);
        m_menuList->resetStatus(idx);
    });
    connect(m_menuList, &DListView::activated, m_menuList, &QListView::clicked);
}
