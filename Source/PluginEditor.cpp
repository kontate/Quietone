/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
QuietoneAudioProcessorEditor::QuietoneAudioProcessorEditor (QuietoneAudioProcessor& p,juce::AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), audioProcessor (p), valueTreeState(vts)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    volume_slider.reset(new juce::Slider("volume slider"));
    addAndMakeVisible(volume_slider.get());
    volume_slider->setRange(-60.0f, 12.0f, 0.1f);
    volume_slider->setSliderStyle(juce::Slider::LinearVertical);
    volume_slider->setTextBoxStyle(juce::Slider::TextBoxAbove, false, 80, 20); 
    volume_slider->setTextValueSuffix(" dB");
    volume_slider->addListener(this);

    volume_slider->setBounds(36, 16, 125, 430);

    volume_slider->setValue(valueTreeState.getRawParameterValue("volume")->load(), juce::dontSendNotification);

    //volumeSliderAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(valueTreeState, "volume", *volume_slider)) ;

    setSize (200, 500);
}

QuietoneAudioProcessorEditor::~QuietoneAudioProcessorEditor()
{
}

//==============================================================================
void QuietoneAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::aqua);

    juce::Image background = juce::ImageCache::getFromMemory(BinaryData::Quietone_png, BinaryData::Quietone_pngSize);
    g.drawImageWithin(background, 0,0,
        getWidth(),getHeight(),
        juce::RectanglePlacement::centred | juce::RectanglePlacement::onlyReduceInSize,
        false);
}

void QuietoneAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void QuietoneAudioProcessorEditor::sliderValueChanged(juce::Slider* sliderThatWasMoved) {
    if (sliderThatWasMoved == volume_slider.get())
    {
        valueTreeState.getParameterAsValue("volume").setValue(volume_slider->getValue());
    }
}
