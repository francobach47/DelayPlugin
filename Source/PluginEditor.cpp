#include "PluginProcessor.h"
#include "PluginEditor.h"

DelayAudioProcessorEditor::DelayAudioProcessorEditor (DelayAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    addAndMakeVisible(gainKnob);
    addAndMakeVisible(mixKnob);
    addAndMakeVisible(delayTimeKnob);

    setSize (500, 330);
}

DelayAudioProcessorEditor::~DelayAudioProcessorEditor()
{
}

//==============================================================================
void DelayAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::darkgrey);
}

void DelayAudioProcessorEditor::resized()
{
    delayTimeKnob.setTopLeftPosition(20, 10);
    mixKnob.setTopLeftPosition(delayTimeKnob.getRight() + 20, 10);
    gainKnob.setTopLeftPosition(mixKnob.getRight() + 20, 10);
}
