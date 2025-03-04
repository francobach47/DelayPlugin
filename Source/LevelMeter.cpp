#include <JuceHeader.h>
#include "LevelMeter.h"

//==============================================================================
LevelMeter::LevelMeter(std::atomic<float>& measurementL_, 
                       std::atomic<float>& measurementR_) 
    : measurementL(measurementL_), measurementR(measurementR_)
{
    setOpaque(true);
    startTimerHz(1);
}

LevelMeter::~LevelMeter()
{
}

void LevelMeter::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);

    g.setColour (juce::Colours::white);
    g.setFont (juce::FontOptions (14.0f));
    g.drawText ("LevelMeter", getLocalBounds(),
                juce::Justification::centred, true); 
}

void LevelMeter::resized()
{


}

void LevelMeter::timerCallback()
{
    DBG("left: " << measurementL.load() << ", right: " << measurementR.load());
}