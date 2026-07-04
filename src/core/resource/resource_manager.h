#pragma once

#include "resource_loader.h"

namespace dawn::core {
    class ResourceManager {
    public:
        ResourceManager() = delete;

        static void init();

        template <detail::ResourceID T>
        [[nodiscard]]
        static const auto& getResource(T id) noexcept {
            return detail::cacheSlot(id);
        }
    };
}