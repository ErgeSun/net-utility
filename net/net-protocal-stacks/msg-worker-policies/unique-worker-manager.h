/**
 * This work copyright Chao Sun(qq:296449610) and licensed under
 * a Creative Commons Attribution 3.0 Unported License(https://creativecommons.org/licenses/by/3.0/).
 */

#ifndef NET_CORE_NETSTACKWORKERPOLICY_H
#define NET_CORE_NETSTACKWORKERPOLICY_H

#include <unordered_map>

#include "../inet-msg-worker-manager.h"

namespace netty {
    namespace net {
        /**
         * 两个节点间复用同一连接的管理器。
         */
        class GCC_INTERNAL UniqueWorkerManager : public INetStackWorkerManager {
        public:
            ~UniqueWorkerManager() {}

            /**
             * 获取一个worker。
             * @param npit
             * @return
             */
            virtual INetMessageWorker *GetWorker(net_peer_info_t &npit) override;

            /**
             * 销毁一个worker。
             * @param worker
             */
            virtual void PutWorker(INetMessageWorker *worker) override;

        private:
            INetMessageWorker *lookup_conn(net_peer_info_t &npt);

        private:
            std::unordered_map<net_peer_info_t, INetMessageWorker *> m_hmap_workers;
        }; // class UniqueWorkerManager
    }  // namespace net
}  // namespace netty
#endif //NET_CORE_NETSTACKWORKERPOLICY_H