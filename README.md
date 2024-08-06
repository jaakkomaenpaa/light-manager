# Light manager

A command line tool to manage WiZ and Tuya smart bulbs on my desk. Made for personal use, so configuring the tool for other environments probably requires editing the source code.

## Setting up

- Clone this repository
- Rename config.txt.example -> config.txt and change its content to real data
  - WiZ IP address can be found on the WiZ mobile app
  - WiZ port is usually 38899 or 38900, according to https://cycling74.com/forums/controlling-wiz-wifi-led-rgb-lightbulbs
  - Tuya IP address can be found through your router's admin interface
  - Tuya device ID can be found on Tuya Developer Platform: Cloud -> Development -> *Project* -> Devices. Creating a project and adding devices may require reading Tuya's documentation
  - Tuya local key can be found through tuya-cli wizard: https://github.com/codetheweb/tuyapi/blob/master/docs/SETUP.md
- Run build.bat
- Run lights.exe

## Commands

Shorthand commands inside braces.

- **help (h)**
  - Print usage guide
- **quit (q)**
  - Exit program
- **config (c)**
  - Print current config (contents of config.txt)
- **tuya on|off (tn|tf)**
  - Change status of the Tuya light
- **wiz on|off (wn|wf)**
  - Change status of the WiZ light
- **both on|off (bn|bf)**
  - Change status of both lights
- **tuya scene 1|2.. (ts 1|2..)**
  - Set scene for WiZ light
- **wiz scene 1|2.. (ws 1|2..)**
  - Set scene for WiZ light
- **both scene 1|2.. (bs 1|2..)**
  - Set scene for both lights
