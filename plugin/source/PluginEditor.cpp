#include "YourPluginName/PluginEditor.h"
#include "YourPluginName/PluginProcessor.h"
#include <juce_gui_basics/juce_gui_basics.h> // needed for FlexBox

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
  g.fillAll(juce::Colours::darkgreen);
  g.setColour(juce::Colours::bisque);
  g.setFont(30.0f);
  g.drawFittedText("Soft-Clip", getLocalBounds(),
                   juce::Justification::centred, 1);
}

void AudioPluginAudioProcessorEditor::resized() {
  using namespace juce;

  FlexBox layout; // Instantiating a FlexBox
  layout.flexDirection = FlexBox::Direction::row;
  layout.justifyContent = FlexBox::JustifyContent::spaceAround;

  // tells each slider to take up 40% of the width, and flex height
  layout.items.add (FlexItem (driveSlider).withFlex(.4f).withMinHeight(200));
  layout.items.add (FlexItem (mixSlider).withFlex(.4f).withMinHeight(200));

  layout.performLayout(getLocalBounds().reduced(20));
}
}  // namespace audio_plugin
