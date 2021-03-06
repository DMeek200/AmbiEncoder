/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.1.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
AmbiEncoderAudioProcessorEditor::AmbiEncoderAudioProcessorEditor (AmbiEncoderAudioProcessor& p)
    : AudioProcessorEditor(p), processor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (sliderPanPosition = new Slider ("new slider"));
    sliderPanPosition->setRange (0, 360, 0);
    sliderPanPosition->setSliderStyle (Slider::LinearHorizontal);
    sliderPanPosition->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    sliderPanPosition->addListener (this);

    addAndMakeVisible (sliderVerticalPosition = new Slider ("new slider"));
    sliderVerticalPosition->setRange (0, 180, 0);
    sliderVerticalPosition->setSliderStyle (Slider::LinearHorizontal);
    sliderVerticalPosition->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    sliderVerticalPosition->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    startTimer(200);//starts timer with interval of 200mS
    //[/Constructor]
}

AmbiEncoderAudioProcessorEditor::~AmbiEncoderAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    sliderPanPosition = nullptr;
    sliderVerticalPosition = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void AmbiEncoderAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void AmbiEncoderAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    sliderPanPosition->setBounds (40, 96, 184, 24);
    sliderVerticalPosition->setBounds (40, 168, 184, 32);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void AmbiEncoderAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == sliderPanPosition)
    {
        //[UserSliderCode_sliderPanPosition] -- add your slider handling code here..
		processor.panPosition = sliderPanPosition->getValue();
        //[/UserSliderCode_sliderPanPosition]
    }
    else if (sliderThatWasMoved == sliderVerticalPosition)
    {
        //[UserSliderCode_sliderVerticalPosition] -- add your slider handling code here..
		processor.verticalPosition = sliderVerticalPosition->getValue();
        //[/UserSliderCode_sliderVerticalPosition]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void AmbiEncoderAudioProcessorEditor::timerCallback()
{
    //exchange any data you want between UI elements and the Plugin "ourProcessor"
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="AmbiEncoderAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="AmbiEncoderAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor(p), processor(p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="new slider" id="666539edebeb6e91" memberName="sliderPanPosition"
          virtualName="" explicitFocusOrder="0" pos="40 96 184 24" min="0"
          max="360" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="new slider" id="ee4ab5b09fc46aa" memberName="sliderVerticalPosition"
          virtualName="" explicitFocusOrder="0" pos="40 168 184 32" min="0"
          max="180" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
