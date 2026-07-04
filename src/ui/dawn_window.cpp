#include "dawn_window.h"

#include "themes.h"
#include "../core/resource/resource_manager.h"
#include "core/logger.h"

namespace dawn::ui {
    DawnGUIWindow::DawnGUIWindow (const juce::String& name) : DocumentWindow(
            name,
            juce::Colour(theme::Dark.backgroundColour),
            allButtons)
    {
        core::Logger::Debug("Initializing GUI Window");

        setOpaque(true);
        setUsingNativeTitleBar(false);

        setTitleBarHeight(0);

        setResizable(true, false);
        setFullScreen(true);

        setDraggable(false);

        Component::setVisible(true);

        addAndMakeVisible(&titleBar_);

        core::Logger::Debug("GUI Window initialized and running");
    }

    void DawnGUIWindow::closeButtonPressed() {
        core::Logger::Debug("Exiting GUI Window");
        juce::JUCEApplication::getInstance()->systemRequestedQuit();
    }

    void DawnGUIWindow::resized() {
        titleBar_.setBounds(getLocalBounds().removeFromTop(40.0f));
    }
}
