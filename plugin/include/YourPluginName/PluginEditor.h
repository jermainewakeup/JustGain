#pragma once

#include "PluginProcessor.h"

namespace audio_plugin {

class AudioPluginAudioProcessorEditor : public juce::AudioProcessorEditor {
public:
  explicit AudioPluginAudioProcessorEditor(AudioPluginAudioProcessor&);
  ~AudioPluginAudioProcessorEditor() override;

  void paint(juce::Graphics&) override;
  void resized() override;

private:
  // This reference is provided as a quick way for your editor to
  // access the processor object that created it.
  AudioPluginAudioProcessor& processorRef;

  // Sliders
  juce::Slider driveSlider;
  juce::Slider mixSlider;

  // Slider Attachments
  std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> driveAttach;
  std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mixAttach;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AudioPluginAudioProcessorEditor)
};
}  // namespace audio_plugin
