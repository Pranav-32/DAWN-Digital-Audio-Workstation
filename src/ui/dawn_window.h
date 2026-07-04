#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

#include "components/panels/title_bar.h"

namespace dawn::ui {
    class DawnGUIWindow : public juce::DocumentWindow {
        public:
        ~DawnGUIWindow() override = default;

        explicit DawnGUIWindow(const juce::String& name);
        void closeButtonPressed() override;

        void resized() override;
    private:
        component::TitleBar titleBar_;

        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DawnGUIWindow)
    };
}