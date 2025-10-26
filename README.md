# Open Blaster is an open source crossplatform CLI utility for controlling Sound Blaster sound cards from command line

## Getting started

- clone this repository
- install dependencies

openblaster requires hidapi for communicating with the hardware and json-c for parsing EQ presets

both can be installed with Homebrew on macOS and should be available on your distro's package manager of choice.

`brew install json-c hidapi`

- generate build files

`cmake -S . -B build`

- build the executable

`cd build && make`

- run

`./openblaster`

## Usage

When you run `openblaster` without any arguments, help is automatically output

`Usage: openblaster [-r,g,b int value] [-e /path/to/json]`

`-r` `-g` `-b` are color values [0-255] for the LED if available on your soundcard

`-e` is the path to your EQ preset. Right now compatible with the exported presets from the Sound Blaster Command software

### Example EQ

```
{
  "Version": "1.0.0.0",
  "Product": "G6",
  "Id": "some uuid",
  "Name": "Preset name",
  "FilePath": "C:\\Users\\User\\Documents\\example.json",
  "Type": 1,
  "Order": 63894657589675,
  "SpeakerMethod": 1,
  "Settings": [
    {
      "Bands": [
        {
          "Frequency": 31,
          "Value": 0.0
        },
        {
          "Frequency": 62,
          "Value": 0.0
        },
        {
          "Frequency": 125,
          "Value": 0.0
        },
        {
          "Frequency": 250,
          "Value": 0.0
        },
        {
          "Frequency": 500,
          "Value": 0.0
        },
        {
          "Frequency": 1000,
          "Value": 0.0
        },
        {
          "Frequency": 2000,
          "Value": 0.0
        },
        {
          "Frequency": 4000,
          "Value": 0.0
        },
        {
          "Frequency": 8000,
          "Value": 0.0
        },
        {
          "Frequency": 16000,
          "Value": 0.0
        }
      ],
      "Type": "Speaker",
      "Unit": "db",
      "PreAmp": 0.0
    },
    {
      "Bands": [
        {
          "Frequency": 31,
          "Value": 1.9
        },
        {
          "Frequency": 62,
          "Value": 0.7
        },
        {
          "Frequency": 125,
          "Value": -1.8
        },
        {
          "Frequency": 250,
          "Value": -2.0
        },
        {
          "Frequency": 500,
          "Value": 0.7
        },
        {
          "Frequency": 1000,
          "Value": 0.7
        },
        {
          "Frequency": 2000,
          "Value": -3.3
        },
        {
          "Frequency": 4000,
          "Value": 1.6
        },
        {
          "Frequency": 8000,
          "Value": 6.1
        },
        {
          "Frequency": 16000,
          "Value": -2.4
        }
      ],
      "Type": "Headphone",
      "Unit": "db",
      "PreAmp": -6.2
    }
  ],
  "ImageSmall": null,
  "ImageLarge": null,
  "CreatorName": null,
  "CreatorProfession": null,
  "DescriptionShort": null,
  "DescriptionLong": null
}
```

## Plans

- proper CMakeLists.txt
- Crossplatform GUI
