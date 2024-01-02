#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);
    setWantsKeyboardFocus(true);
    


    textEditorTest.setMultiLine(true);
    textEditorTest.setText("hello world");
    textEditorTest.setJustification(juce::Justification::centred);
    addAndMakeVisible(textEditorTest);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    
    //g.setFont (juce::Font (16.0f));
    //g.setColour (juce::Colours::white);
    //g.drawText ("Hello World!", getLocalBounds(), juce::Justification::centred, true);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    textEditorTest.setSize(getWidth(), getHeight() / 4);
}

bool MainComponent::keyPressed(const juce::KeyPress& key)
{
    if (key.isKeyCode(juce::KeyPress::spaceKey))
    {
        textEditorTest.setText(std::to_string(stockData.prices[currentLine]));
        //if (currentLine < data.pri.size())
        //{
        //}
        //else
        //    textEditorTest.setText("No More Data");

        currentLine++;
    }
    if (key.isKeyCode(juce::KeyPress::numberPad1))
    {
        juce::File file("C:\\Users\\prest\\Downloads\\zOther\\SPX Max Mounthly.csv");
        auto fileString = file.loadFileAsString();

        stockData.SetPrices(fileString);
    }

    return false;
}

/*
		if (true)
			DBG("true");
		else
			DBG("false");*/
