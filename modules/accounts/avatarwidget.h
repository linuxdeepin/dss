#ifndef AVATARWIDGET_H
#define AVATARWIDGET_H

#include <QWidget>
#include <QPushButton>

class AvatarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AvatarWidget(QWidget *parent = 0);
    explicit AvatarWidget(const QString &avatar, QWidget *parent = 0);

    void setSelected(const bool selected = true);
    void setDeletable(const bool deletable = true);

    inline QString avatarPath() const { return m_avatarPath; }
    void setAvatarPath(const QString &avatar);

signals:
    void clicked() const;

protected:
    void mouseReleaseEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *e);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void resizeEvent(QResizeEvent *event);

private:
    bool m_hover;
    bool m_deleable;
    bool m_selected;

    QPixmap m_avatar;
    QString m_avatarPath;

    QPushButton *m_delBtn;
};

#endif // AVATARWIDGET_H
