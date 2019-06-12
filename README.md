# WavCrypt

WavCrypt is a small C++ / JUCE tool, which can generate a unique “Noise Key” and “encrypt/decrypt” .wav Files by adding/substracting the noise key from the signal. 


## Usage:
1. Set number of key channels in Encryptor.h (#define KeyChannels n)
    - Currently this has to match the number of channels the wav files you want to encrypt have    
    - If a .wav file is being encrypted with a key file and the channels don’t match an assertion triggers on line 186 or 317 in Encryptor.h

2. Build project, run app

3. Click “Generate Key” button - select save location for key .wav file

4. Click “Encrypt .wav Files” button
    - a. First file chooser - select directory containing samples to encrypt
    - b. Second file chooser - select key .wav file for encryption

5. Click “Decrypt .wav Files” button
    - a. First file chooser - select directory containing encrypted samples
    - b. Second file chooser - select key .wav file for decryption (ideally the same one used for encryption :) )

The resulting Encrypted/Decrypted directories will be placed next to their originals
