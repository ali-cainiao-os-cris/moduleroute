#ifndef __MODULEROUTEIMPL_H__
#define __MODULEROUTEIMPL_H__

#include "singletonimpl.h"

namespace moduleroute {

    class CModuleRoutePrint : public singleton<CModuleRoutePrint> {
        public:
        
        private:

        SINGLETON_TEMPLATE_DECLARE(CModuleRoutePrint)
    };

    class CModuleRouteScale : public singleton<CModuleRouteScale> {
        public:

        private:

        SINGLETON_TEMPLATE_DECLARE(CModuleRouteScale)
    };

    class CModuleRouteScan : public singleton<CModuleRouteScan> {
        public:

        private:

        SINGLETON_TEMPLATE_DECLARE(CModuleRouteScan)
    };

    class CModuleRouteSkyMachine : public singleton<CModuleRouteSkyMachine> {
        public:

        private:

        SINGLETON_TEMPLATE_DECLARE(CModuleRouteSkyMachine)
    };

    class CModuleRouteVideo : public singleton<CModuleRouteVideo> {
        public:

        private:

        SINGLETON_TEMPLATE_DECLARE(CModuleRouteVideo)
    };

    class CModuleRouteSpeech : public singleton<CModuleRouteSpeech> {
        public:

        private:

        SINGLETON_TEMPLATE_DECLARE(CModuleRouteSpeech)
    };
}//namespace moduleroute

#endif // __MODULEROUTEIMPL_H__