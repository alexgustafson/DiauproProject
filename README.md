# DiauproProject

This is a semester project that investigates using single-board-computer devices ( like this bananapi or odroid ) 
connected via ethernet as inexpensive audio co-processing. ARM based single board devices can offer an open alternative
to DSP based audio processing cards.

## DiauproPlugin

The DiauproPlugin can be compiled as an AudioUnit or VST plugin. It is a very simple implementation of a virtual 
synthesizer. It is monophonic. The VCO block produces a sine wave, the VCA block produces an envelope when a midi not
 is triggered. The VCO and VCA blocks can process audio locally in the plugin, or remotely on networked 
 AudioProcessorNodes. The DiauproPlugin will browse the LAN Network for corresponding remote service via 
 Bonjour/Zeroconf. 

## AudioProcessorNode

The AudioProcessorNode can be compiled and run on an OSX, Windows, or Linux device. It is specifically tested on 
Bananapi and Odroid devices running ubuntu. When running it registers it's available processing services via 
Bonjour/Zeroconf on the LAN Network. The DiauproPlugin will connect automatically upon finding the service in the 
Network.

## Documentation

The documentation can be built using the following command:

> $ python /Documentation/build.py

this will produce PDF and HTML files in German and English





