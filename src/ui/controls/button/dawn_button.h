#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

#include "ui/theme/styles/button_style.h"

namespace dawn::ui::control {

    class DawnButton : public juce::Button {
    public:
        DawnButton(const juce::String& name, const theme::style::ButtonStyle& style):
            juce::Button(name), style_(style) {}

        void paintButton(juce::Graphics &g, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override;
    private:
        std::reference_wrapper<const theme::style::ButtonStyle> style_;

        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DawnButton)
    };
}