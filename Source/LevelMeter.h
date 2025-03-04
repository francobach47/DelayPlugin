#pragma once

#include <JuceHeader.h>

class LevelMeter  : public juce::Component, private juce::Timer
{
public:
    LevelMeter(std::atomic<float>& measurementL,
               std::atomic<float>& measurementR);
    ~LevelMeter() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    void timerCallback() override;

    std::atomic<float>& measurementL;
    std::atomic<float>& measurementR;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LevelMeter)
};
