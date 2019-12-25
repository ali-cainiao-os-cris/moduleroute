#ifndef __SINGLETONIMPL_H__
#define __SINGLETONIMPL_H__

#include <mutex>

namespace moduleroute {

    template<typename T>
    class singleton {
        public:
            virtual ~singleton(){;}
            static T* getInstance(void* param = nullptr) {
                if(nullptr == pInstance) {
                    std::lock_guard<std::mutex> autolock(&mutex);
                    if(nullptr == pInstance) {
                        pInstance = new T(param);
                    }
                }

                return pInstance;
            }

            static void releaseInstance() {
                if(pInstance) {
                    std::lock_guard<std::mutex> autolock(&mutex);
                    if(nullptr != pInstance) {
                        delete pInstance;
                        pInstance = nullptr;
                    }
                }

                pCallBack = nullptr;
            }

        protected:
            singleton(void* param = nullptr):pInstance(nullptr) {
                if(nullptr == pCallBack)
                    pCallBack = param;
            }

        public:
            void* pCallBack;

        private:
            static T* pInstance;
            static std::mutex  mutex;
    };

    template<typename T> T* singleton<T>::pInstance = nullptr;  
    template<typename T> std::mutex singleton<T>::mutex;

    #define SINGLETON_TEMPLATE_DECLARE(classname)\
    protected:\
    classname();\
    ~classname();

    #define SINGLETON_TEMPLATE_IMPLEMENT(classname)\
    template<typename classname> classname* singleton<classname>::pInstance = nullptr;\
    template<typename classname> std::mutex singleton<classname>::mutex;

}//namespace moduleroute

#endif