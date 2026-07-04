#pragma once

#include <juce_graphics/juce_graphics.h>

namespace dawn::ui::theme {
    struct ThemeData {
        juce::uint32 backgroundColour = 0xFF12141C;
        juce::uint32 primaryColour = 0xFFE2E8F0;
        juce::uint32 secondaryColour = 0xFF1E2230;
        juce::uint32 accentColour = 0xFF00F0FF;
    };
}