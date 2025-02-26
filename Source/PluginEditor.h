#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Parameters.h"
#include "RotaryKnob.h"

class DelayAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    DelayAudioProcessorEditor (DelayAudioProcessor&);
    ~DelayAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    DelayAudioProcessor& audioProcessor;

    RotaryKnob gainKnob{ "Gain" , audioProcessor.apvts, gainParamID };
    RotaryKnob mixKnob{ "Mix", audioProcessor.apvts, mixParamID};
    RotaryKnob delayTimeKnob{ "Time", audioProcessor.apvts, delayTimeParamID};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DelayAudioProcessorEditor)
};
