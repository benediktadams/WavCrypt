/*
  ==============================================================================

 Copyright 2019 Benedikt Sailer - mail@benediktsailer.com
 
 Idea by Daniel Walz
 
 Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    addAndMakeVisible(&generateKeyButton);
    generateKeyButton.setButtonText("Generate Key");
    generateKeyButton.onClick = [&]()
    {

        noiseKeyGen.generateKey();
        
    };
    
    addAndMakeVisible(&encryptWavFilesButton);
    encryptWavFilesButton.setButtonText("Encrypt .wav Files");
    encryptWavFilesButton.onClick = [&]()
    {
        wavEncryptor.encryptWavFiles();
    };
    wavEncryptor.reportProgress = [&](float progress)
    {
        loadingBar.setProgress(progress);
       
    };
    
    addAndMakeVisible(&decryptWavFilesButton);
    decryptWavFilesButton.setButtonText("Decrypt .wav Files");
    decryptWavFilesButton.onClick = [&]()
    {
        wavDecryptor.decryptWavFiles();
    };
    wavDecryptor.reportProgress = [&](float progress)
    {
        loadingBar.setProgress(progress);        
    };
    
    addChildComponent(&loadingBar);
    loadingBar.setAlwaysOnTop(true);
    
    setSize (600, 400);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setFont (Font (16.0f));
    g.setColour (Colours::white);
    g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
}

void MainComponent::resized()
{
    auto area = getLocalBounds();
    
    auto centerArea = area.reduced(jmin (getHeight() * 0.2f, getWidth() * 0.2f));
    auto buttonPadding = centerArea.getHeight() * 0.1f;
    auto buttonHeight = centerArea.getHeight() / 3.0f - buttonPadding;
    
    generateKeyButton.setBounds(centerArea.removeFromTop(buttonHeight));
        centerArea.removeFromTop(buttonPadding);
    
    encryptWavFilesButton.setBounds(centerArea.removeFromTop(buttonHeight));
        centerArea.removeFromTop(buttonPadding);
   
    decryptWavFilesButton.setBounds(centerArea.removeFromTop(buttonHeight));
        centerArea.removeFromTop(buttonPadding);
    
    loadingBar.setBounds(area);
    
    
}
