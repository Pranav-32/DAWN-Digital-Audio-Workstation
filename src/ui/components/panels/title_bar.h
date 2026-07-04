#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

namespace dawn::ui::component {
    class TitleBar : public juce::Component, juce::Button::Listener {
    public:
        TitleBar();
        ~TitleBar() override = default;

        void paint(juce::Graphics& g) override;
        void resized() override;

        void mouseDown(const juce::MouseEvent &event) override;
        void mouseDrag(const juce::MouseEvent &event) override;

        void buttonClicked(juce::Button *button) override;

    private:
        juce::ComponentDragger dragger_;
        juce::ComponentBoundsConstrainer constrainer_;

        juce::FlexBox titleBarFlexBox_;

        juce::Label titleLabel_;
        juce::FlexBox winControlsContainer_;

        std::unique_ptr<juce::ShapeButton> minimizeButton_;
        std::unique_ptr<juce::ShapeButton> maximizeButton_;
        std::unique_ptr<juce::ShapeButton> closeButton_;

        std::unique_ptr<juce::DrawablePath> minimizeButtonDrawablePath_;
        std::unique_ptr<juce::DrawablePath> maximizeButtonDrawablePath_;
        std::unique_ptr<juce::DrawablePath> closeButtonDrawablePath_;

        juce::Rectangle<float> titleBounds_;
        juce::Rectangle<float> winControlsBounds_;

        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TitleBar)
    };
}
