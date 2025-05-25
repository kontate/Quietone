/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class QuietoneAudioProcessorEditor  : public juce::AudioProcessorEditor, public juce::Slider::Listener
{
public:
    QuietoneAudioProcessorEditor (QuietoneAudioProcessor&,juce::AudioProcessorValueTreeState&);
    ~QuietoneAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void sliderValueChanged(juce::Slider*) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    QuietoneAudioProcessor& audioProcessor;
    juce::AudioProcessorValueTreeState& valueTreeState;
    std::unique_ptr<juce::Slider> volume_slider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> volumeSliderAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (QuietoneAudioProcessorEditor)
};
