#include "Tempo.h"

void Tempo::reset() noexcept
{
	bpm = 120.0;
}

void Tempo::update(const juce::AudioPlayHead* playhead) noexcept
{
	void reset();

	if (playhead == nullptr) { return; }

	const auto opt = playhead->getPosition();

	if (!opt.hasValue()) { return; }

	const auto& pos = *opt;

	if (pos.getBpm().hasValue()) {
		bpm = *pos.getBpm();
	}
}