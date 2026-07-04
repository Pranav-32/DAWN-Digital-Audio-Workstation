#pragma once
#include "resources.h"

#include <juce_gui_basics/juce_gui_basics.h>

namespace dawn::core::detail {
    template <typename T>
    struct ResourceCache;

    template <>
    struct ResourceCache<resources::ImageID> {
        using ValueType = juce::Image;
        inline static std::array<ValueType, std::to_underlying(resources::ImageID::Count)> cache;
    };
}
