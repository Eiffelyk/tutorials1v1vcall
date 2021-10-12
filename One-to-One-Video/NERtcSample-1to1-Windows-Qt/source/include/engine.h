#ifndef _ENGINE_H
#define _ENGINE_H

#include <string>
#include <memory>
#include <QObject>

#include "nertc_engine_ex.h"


class EventHandler;
class Engine:public QObject,
             public nertc::IRtcEngineEventHandlerEx
{
    Q_OBJECT

public:
    Engine(QObject *parent = nullptr);
    ~Engine();

public:
    bool Init(const char* log_dir_path);
    int EnableVideo(const bool &enabled);
    int EnableAudio(const bool &enabled);
    int JoinChannel(const std::string &channel_name, const std::string &uid);
    int SetupLocalVideo(void* hwnd);
    int SetupRemoteVideo(quint64 uid, void* hwnd);
    int SubscribeRemoteVideoStream(nertc::uid_t uid, nertc::NERtcRemoteVideoStreamType type, bool subscribe);
    int SetParameters(const char* parameters);

private:
    // �ͷ�Rtc
    void uninit();

public:
    virtual void onJoinChannel(nertc::channel_id_t   cid,
                               nertc::uid_t          uid,
                               nertc::NERtcErrorCode result,
                               uint64_t              elapsed) override;

    virtual void onUserJoined(nertc::uid_t uid,
                              const char * user_name) override;

    virtual void onUserVideoStart(nertc::uid_t                 uid,
                                  nertc::NERtcVideoProfileType max_profile) override;

    virtual void onLeaveChannel(nertc::NERtcErrorCode result) override;

    virtual void onUserLeft(nertc::uid_t                   uid,
                            nertc::NERtcSessionLeaveReason reason) override;


Q_SIGNALS:
    // ����Ƶ�����
    void sigJoinChannel(const int &result);

    // �û�����Ƶ��
    void sigUserJoined(const quint64& uid, const QString& name);

    // �û�������Ƶ
    void sigUserVideoStart(const quint64& uid, const int& profile);

    // �û��뿪
    void sigUserLeft(const quint64& uid, const int& result);


private:
    const std::string app_key_ = "";

private:
    nertc::IRtcEngineEx* rtc_engine_ = nullptr;
};

#endif //_ENGINE_H
