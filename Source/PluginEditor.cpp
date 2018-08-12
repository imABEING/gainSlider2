/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
GainSliderAudioProcessorEditor::GainSliderAudioProcessorEditor (GainSliderAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 400);
    
    //Make Vertical Slider
    gainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    
    //Set Text box below slider, make read only, with width of 100 and heigh of 25
    gainSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 25);
    
    //Set range
    gainSlider.setRange(0.0, 5.0);
    
    //Set default value
    gainSlider.setValue(1.0);
    
    //Listen for changes in slider value
    gainSlider.addListener(this);
    
    //Make Visable
    addAndMakeVisible(gainSlider);
}

GainSliderAudioProcessorEditor::~GainSliderAudioProcessorEditor()
{
}

//==============================================================================
void GainSliderAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

}

void GainSliderAudioProcessorEditor::resized()
{
    gainSlider.setBounds(getLocalBounds());
}

//processing change in gain
void GainSliderAudioProcessorEditor::sliderValueChanged (Slider *slider)
{
    if (slider == &gainSlider)
    {
        processor.rawVolume = gainSlider.getValue();
    }
    
}
