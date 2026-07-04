#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

namespace dawn::ui::theme::style {
    struct ButtonStyle {
        juce::Colour background;
        juce::Colour foreground;
        juce::Colour hover;
        juce::Colour pressed;
        juce::Colour border;

        float cornerRadius;
        float borderWidth;

        juce::Font font;
    };
}