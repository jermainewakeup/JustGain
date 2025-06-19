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
  setSize(600, 200);

  // configure slider
  gainSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
  gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 40);
  addAndMakeVisible(gainSlider);

  // attach the slider to APVTS "gain" parameter
  gainAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
    processorRef.getValueTreeState(),
    "gain",
    gainSlider
    );
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor() {}

void AudioPluginAudioProcessorEditor::paint(juce::Graphics& g) {
  // (Our component is opaque, so we must completely fill the background with a
  // solid colour)
  g.fillAll(
      getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

  g.setColour(juce::Colours::white);
  g.setFont(15.0f);
  g.drawFittedText("Hello World!", getLocalBounds(),
                   juce::Justification::centred, 1);
}

void AudioPluginAudioProcessorEditor::resized() {
  // This is generally where you'll want to lay out the positions of any
  // subcomponents in your editor..
  gainSlider.setBounds(getLocalBounds());
}
}  // namespace audio_plugin
