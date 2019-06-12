/*
  ==============================================================================

    LoadingBar.h
    Created: 12 Jun 2019 2:48:10pm
    Author:  Benedikt Sailer

 ==============================================================================
 
 Copyright 2019 Benedikt Sailer - mail@benediktsailer.com
 
 Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 ==============================================================================
  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

#define FrameRate 30

class LoadingBar : public Component, public Timer
{
public:
    LoadingBar()
    {
        
    }
    
    void timerCallback() override
    {
        
        if (progress.get()  < 1.0f && !isVisible())
        {
            setVisible(true);
            setBounds(getBounds());
        }
        
        else if (progress.get()  >= 1.0f && isVisible())
        {
            Timer::stopTimer();
            setVisible(false);
        }
        
        repaint();
        
     
        
    }
    
    void paint(Graphics& g) override
    {
        g.fillAll(Colours::grey.withAlpha(0.8f));
        
        const auto barWidth = getWidth() * 0.9f;
        const auto barHeight = barWidth * (0.06f);
        Rectangle<float> barRect;
        barRect.setSize(barWidth, barHeight);
        barRect.setCentre(getLocalBounds().getCentre().toFloat());
        
        
        auto filledArea = barRect;
        filledArea = filledArea.removeFromLeft(barRect.getWidth() * progress.get());
        
        g.setColour(Colours::red);
        g.fillRect(filledArea);
        
        g.setColour(Colours::black);
        g.drawRect(barRect, 2.5f);
    }
    
    
    void setProgress(float newVal)
    {
        progress.set(newVal);
        
        if (!Timer::isTimerRunning())
            startTimer(FrameRate);
        
   
    }
private:
    Atomic<float> progress;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LoadingBar)
};
