#include "YourPluginName/PluginEditor.h"
#include "YourPluginName/PluginProcessor.h"

namespace audio_plugin {
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor(
    AudioPluginAudioProcessor& p)
    : AudioProcessorEditor(&p), processorRef(p) {
  juce::ignoreUnused(processorRef);
  // Make sure that before the constructor has finished, you've set the
  // editor's size to whatever you need it to be.

  // set window size
  setSize(800, 400);

  // ------- configure sliders ------ //
  // drive slider
  driveSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
  driveSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 40);
  addAndMakeVisible(driveSlider);
  // mix slider
  mixSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
  mixSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 40);
  addAndMakeVisible(mixSlider);

  // attach sliders to APVTS ID parameters
  driveAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
    processorRef.getValueTreeState(),
    "drive",
    driveSlider
    );
  mixAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
    processorRef.getValueTreeState(),
    "mix",
    mixSlider
    );
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor() {}

void AudioPluginAudioProcessorEditor::paint(juce::Graphics& g) {
  // (Our component is opaque, so we must completely fill the background with a
  // solid colour)
  g.fillAll(juce::Colours::darkgrey);
  g.setColour(juce::Colours::whitesmoke);
  g.setFont(30.0f);
  g.drawFittedText("Soft-Clip", getLocalBounds(),
                   juce::Justification::centred, 1);
}

void AudioPluginAudioProcessorEditor::resized() {
  // This is generally where you'll want to lay out the positions of any
  // subcomponents in your editor..
  driveSlider.setBounds(getLocalBounds());
  mixSlider.setBounds(getLocalBounds());
}
}  // namespace audio_plugin
