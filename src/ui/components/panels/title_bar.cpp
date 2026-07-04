#include "title_bar.h"
#include "ui/theme/dark.h"

namespace dawn::ui::component {
    TitleBar::TitleBar()
    {
        setOpaque(true);

        titleBarFlexBox_.flexDirection  = juce::FlexBox::Direction::row;
        titleBarFlexBox_.flexWrap       = juce::FlexBox::Wrap::noWrap;
        titleBarFlexBox_.justifyContent = juce::FlexBox::JustifyContent::flexEnd;
        titleBarFlexBox_.alignContent   = juce::FlexBox::AlignContent::center;
        titleBarFlexBox_.alignItems     = juce::FlexBox::AlignItems::center;

        winControlsContainer_.flexDirection  = juce::FlexBox::Direction::row;
        winControlsContainer_.flexWrap       = juce::FlexBox::Wrap::noWrap;
        winControlsContainer_.justifyContent = juce::FlexBox::JustifyContent::flexStart;
        winControlsContainer_.alignContent   = juce::FlexBox::AlignContent::center;
        winControlsContainer_.alignItems     = juce::FlexBox::AlignItems::center;

        minimizeButtonDrawablePath_ = std::make_unique<juce::DrawablePath>();
        maximizeButtonDrawablePath_ = std::make_unique<juce::DrawablePath>();
        closeButtonDrawablePath_ = std::make_unique<juce::DrawablePath>();

        juce::Path minimizeButtonPath;
        juce::Path maximizeButtonPath;
        juce::Path closeButtonPath;

        minimizeButtonPath.addLineSegment(juce::Line(3.0f, 5.0f, 7.0f, 5.0f), 1.0f);
        maximizeButtonPath.addRectangle(3.0f, 3.0f, 6.0f, 6.0f);
        closeButtonPath.addLineSegment(juce::Line(3.0f, 3.0f, 7.0f, 7.0f), 1.0f);
        closeButtonPath.addLineSegment(juce::Line(3.0f, 7.0f, 7.0f, 3.0f), 1.0f);

        minimizeButtonDrawablePath_->setPath(minimizeButtonPath);
        maximizeButtonDrawablePath_->setPath(maximizeButtonPath);
        closeButtonDrawablePath_->setPath(closeButtonPath);

        maximizeButtonDrawablePath_->setStrokeThickness(1.0f);

        minimizeButton_ = std::make_unique<juce::ShapeButton>("minimize", juce::Colour(theme::Dark.primaryColour), juce::Colour(theme::Dark.accentColour), juce::Colour(theme::Dark.primaryColour));
        maximizeButton_ = std::make_unique<juce::ShapeButton>("maximize", juce::Colour(theme::Dark.primaryColour), juce::Colour(theme::Dark.accentColour), juce::Colour(theme::Dark.primaryColour));
        closeButton_ = std::make_unique<juce::ShapeButton>("close", juce::Colour(theme::Dark.primaryColour), juce::Colour(theme::Dark.accentColour), juce::Colour(theme::Dark.primaryColour));

        minimizeButton_->setShape(minimizeButtonPath, false, true, false);
        maximizeButton_->setShape(maximizeButtonPath, false, true, false);
        closeButton_->setShape(closeButtonPath, false, true, false);

        addAndMakeVisible(minimizeButton_.get());
        addAndMakeVisible(maximizeButton_.get());
        addAndMakeVisible(closeButton_.get());

        minimizeButton_->addListener(this);
        maximizeButton_->addListener(this);
        closeButton_->addListener(this);
    }

    void TitleBar::buttonClicked(juce::Button *button) {
        if (auto* topWindow = findParentComponentOfClass<juce::DocumentWindow>()) {
            if          (button == minimizeButton_.get())   topWindow->minimiseButtonPressed();
            else if     (button == maximizeButton_.get())   topWindow->maximiseButtonPressed();
            else if     (button == closeButton_.get())      topWindow->closeButtonPressed();
        }
    }

    void TitleBar::paint(juce::Graphics& g) {
        g.fillAll(juce::Colour(theme::Dark.secondaryColour));
    }

    void TitleBar::resized() {
        titleBarFlexBox_.items.clear();
        winControlsContainer_.items.clear();

        constexpr float btnWidth  = 15.0f;
        constexpr float btnHeight = 15.0f;
        constexpr float margin    = 5.0f;

        winControlsContainer_.items.add(juce::FlexItem(*minimizeButton_).withWidth(btnWidth).withHeight(btnHeight).withMargin(margin));
        winControlsContainer_.items.add(juce::FlexItem(*maximizeButton_).withWidth(btnWidth).withHeight(btnHeight).withMargin(margin));
        winControlsContainer_.items.add(juce::FlexItem(*closeButton_).withWidth(btnWidth).withHeight(btnHeight).withMargin(margin));

        constexpr float totalControlsWidth = (btnWidth + (margin * 2.0f)) * 3.0f;

        titleBarFlexBox_.items.add(juce::FlexItem(winControlsContainer_).withWidth(totalControlsWidth).withHeight(btnHeight).withMargin(margin));

        titleBarFlexBox_.performLayout(getLocalBounds().toFloat());
    }

    void TitleBar::mouseDown(const juce::MouseEvent &event) {
        if (auto* topWindow = findParentComponentOfClass<juce::DocumentWindow>()) {
            dragger_.startDraggingComponent(topWindow, event);
        }
    }

    void TitleBar::mouseDrag(const juce::MouseEvent& event) {
        if (auto* topWindow = findParentComponentOfClass<juce::DocumentWindow>()) {
            dragger_.dragComponent(topWindow, event, &constrainer_);
        }
    }
}
