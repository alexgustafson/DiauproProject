/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "DiauproVCAProcessor.h"
#include "DiauproVCOProcessor.h"
#include "DiauproNullProcessor.h"
#include "DiauproAsyncProcessor.h"
#include "GUI.h"

//==============================================================================
/**
*/
class DiauproPluginAudioProcessor  : public AudioProcessor, public AsyncUpdater
{
public:
    //==============================================================================
    DiauproPluginAudioProcessor();
    ~DiauproPluginAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    int getNumParameters() override;
    float getParameter (int index) override;
    void setParameter (int index, float newValue) override;

    const String getParameterName (int index) override;
    const String getParameterText (int index) override;

    const String getInputChannelName (int channelIndex) const override;
    const String getOutputChannelName (int channelIndex) const override;
    bool isInputChannelStereoPair (int index) const override;
    bool isOutputChannelStereoPair (int index) const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool silenceInProducesSilenceOut() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    double vcoProcessTime;
    double vcoRtTime;
    double vcoRtMaxTime;
    double vcoRtMinTime;
    bool vcoNetStatus;
    
    double vcaProcessTime;
    double vcaRtTime;
    double vcaRtMaxTime;
    double vcaRtMinTime;
    bool vcaNetStatus;
    
    double nullProcessTime;
    double nullRtTime;
    double nullRtMaxTime;
    double nullRtMinTime;
    bool nullNetStatus;
    
    double audioLatency;
    
    void handleAsyncUpdate () override;
    
    void setNullAsyncMode(bool async);
    void setVCOAsyncMode(bool async);
    void setVCAAsyncMode(bool async);
    double getLatency();
    
    bool nullAsync;
    bool vcoAsync;
    bool vcaAsync;

private:
    DiauproVCOProcessor diauproVCOProcessor;
    DiauproVCAProcessor diauproVCAProcessor;
    DiauproNullProcessor diauproNullProcessor;
    Monitor monitor;
    Synthesiser synth;
    AudioProcessorEditor *editor;
    bool editorReady;
    File file;
    ScopedPointer<FileOutputStream> logfile;
    double startTime;
    
    int tagCountdown;
        //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DiauproPluginAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED