#pragma once

#include "resource_cache.h"

#include <juce_gui_basics/juce_gui_basics.h>

namespace dawn::core::detail {
    template<typename T>
    concept ResourceID =
    requires
    {
        ResourceCache<T>::cache;
    };

    template <ResourceID T>
    auto& cacheSlot(const T& id) noexcept {
        jassert(std::to_underlying(id) <
            ResourceCache<T>::cache.size());

        return ResourceCache<T>::cache[std::to_underlying(id)];
    }

    inline void loadAndCacheResource (const resources::ImageResource& resource) {
        cacheSlot(resource.id) =
            juce::ImageFileFormat::loadFrom(
                resource.bytes,
                resource.size);
    }
}