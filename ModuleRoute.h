#ifndef __MODULEROUTE_H__
#define __MODULEROUTE_H__

/**
 * @the brief:this interface mainly manager all business module interface.
 * recieve all wetbsocket message and parse it then dispatch to special business module
 */

namespace moduleroute {

    //enum all business module type.
    typedef enum {
        eModuleType_NULL = -1,
        eModuleType_Print,
        eModuleType_Scale,
        eModuleType_Scan,
        eModuleType_Speech,
        eModuleType_Video,
        eModuleType_SkyMachine,

        eModuleType_UNKNOWN = 0xff,
    } eModuleType;

    class CModuleRouteBase {
    public:
        virtual ~CModuleRouteBase(){;}
        virtual bool getDeviceCount(eModuleType eType,int nCount) = 0;
        virtual bool getDeviceName(eModuleType eType,int nIndex,char* const pStrName) = 0;
        virtual bool isUseable(eModuleType eType) = 0;
    };

    class CModuleRoutePrint:public CModuleRouteBase {
    public:
        virtual ~CModuleRoutePrint(){;}
        virtual bool print(const char *pStr);
    };

    class CModuleRouteScale:public CModuleRouteBase {
    public:
        virtual ~CModuleRouteScale(){;}
        virtual bool scale();
    };

    class CModuleRouteScan:public CModuleRouteBase {
    public:
        virtual ~CModuleRouteScan(){;}
        virtual bool scan();
    };

    class CModuleRouteVideo:public CModuleRouteBase {
    public:
        virtual ~CModuleRouteVideo(){;}
        virtual bool startRecord(const char* pDestPath) = 0;
        virtual bool stopRecord() = 0;
    };

    class CModuleRouteSpeech:public CModuleRouteBase {
    public:
        virtual ~CModuleRouteSpeech(){;}
        virtual bool speak(const char* pStrContext) = 0;
    };

    class CModuleRouteSKyMachine:public CModuleRouteBase {
    public:
        virtual ~CModuleRouteSKyMachine(){;}
        virtual bool weighing(double &dWeight) = 0 ;
        virtual bool measureSize(double &dVolume) = 0 ;
    };

    class CModuleCallBack {
    public:
        virtual ~CModuleCallBack(){;}
        virtual void onPrint(const char* pActionTag,bool bUseAble) ;
        virtual void onScale(const char* pActionTag,double dScale) ;
        virtual void onVideoStart(const char* pActionTag,bool bResult) ;
        virtual void onVideoBuffer(unsigned char* pBufferVideo,long lTimeStmp,int nWidth,int nHeight) ;
        virtual void onVideoStop(const char* pActionTag,bool bResult) ;
        virtual void onSpeech(const char* pActionTag,bool bResult) ;
        virtual void onSkyMachineWeight(const char* pActionTag,double dWeight) ;
        virtual void onSkyMachineVolume(const char* pActionTag,double dVolume) ;
        virtual void onWarning(const char* pActionTag,int nWarnCode,const char* pStrWarnMsg);
        virtual void onError(const char* pActionTag,int nErrorCode,const char* pStrErrorMsg);
    };

    extern "C" {
        void* createModuleHandle(eModuleType eType,CModuleCallBack* pObserver);
        bool  releaseModuleHandle(void* pHandle);
    }

} //namespace moduleroute

#endif //__MODULEROUTE_H__
