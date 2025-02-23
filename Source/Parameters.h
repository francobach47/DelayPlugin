#pragma once

#include <JuceHeader.h>

const juce::ParameterID gainParamID{ "gain", 1 };

class Parameters
{
public:
	Parameters(juce::AudioProcessorValueTreeState& apvts);

	static juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();

	void update() noexcept;

	float gain = 0.0f;

private:
	juce::AudioParameterFloat* gainParam;
};