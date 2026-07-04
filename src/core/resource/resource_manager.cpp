#include "resource_manager.h"

#include "../logger.h"

namespace dawn::core {

    void ResourceManager::init() {
        Logger::Debug("Loading and initializing resources cache");

        for (const auto& asset : resources::asset_manifest) {
            std::visit([](const auto& concreteAsset) {
                detail::loadAndCacheResource(concreteAsset);
            }, asset);
        }
        Logger::Debug("Resources initialized");
    }
}