#ifndef _VIDEO_WIDGET_H
#define _VIDEO_WIDGET_H

#include <QWidget>

class QLabel;
class VideoWidget: public QWidget
{
public:
    VideoWidget(QWidget* parent = nullptr);
    ~VideoWidget();

public:
    // ��ȡ���ھ��
    void* GetVideoHwnd();

    // �����Ƿ������û�����
    const bool IsJoin();

    // ����״̬
    void SetJoinStatus(const bool    &state);

    void SetCenterName(const QString &name);

    // ��ȡuid
    const QString GetUserId();

private:
    void setUi();

private:
    QLabel* center_name_label_;
    bool    is_join_ = false;
};

#endif //_VIDEO_WIDGET_H
