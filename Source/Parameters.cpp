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
	//auto* param = apvts.getParameter(gainPramID.getParamID());
	//gainParam = dynamic_cast<juce::AudioParameterFloat*>(param);
	castParameter(apvts, gainParamID, gainParam);
}

void Parameters::update() noexcept
{
	gain = juce::Decibels::decibelsToGain(gainParam->get());
}