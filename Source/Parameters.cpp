#include "Parameters.h"

template<typename T>
static void castParameter(juce::AudioProcessorValueTreeState& apvts,
	const juce::ParameterID& id, T& destination)
{
	destination = dynamic_cast<T>(apvts.getParameter(id.getParamID()));
	jassert(destination); // parameter does not exist or wrong type
}

Parameters::Parameters(juce::AudioProcessorValueTreeState& apvts)
{
	castParameter(apvts, gainParamID, gainParam);
}

void Parameters::prepareToPlay(double sampleRate) noexcept
{
	double duration = 0.02;
	gainSmoother.reset(sampleRate, duration);
}

void Parameters::reset() noexcept
{
	gain = 0.0f;

	gainSmoother.setCurrentAndTargetValue(juce::Decibels::decibelsToGain(gainParam->get()));
}

void Parameters::update() noexcept
{
	gainSmoother.setTargetValue(juce::Decibels::decibelsToGain(gainParam->get()));
}

void Parameters::smoothen() noexcept
{
	gain = gainSmoother.getNextValue();
}