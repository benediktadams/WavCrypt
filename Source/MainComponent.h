/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once
#include "Encryptor.h"
#include "LoadingBar.h"

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
   
     NoiseKeyGenerator noiseKeyGen;
     WavEncryptor wavEncryptor;
     WavDecryptor wavDecryptor;
    
    LoadingBar loadingBar;
    
    TextButton
    generateKeyButton,
    encryptWavFilesButton,
    decryptWavFilesButton;
   
    //==============================================================================
    // Your private member variables go here...


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
