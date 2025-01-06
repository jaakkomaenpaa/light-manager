# Light manager

A command line tool to manage WiZ and Tuya smart bulbs on my desk. Made for personal use, so configuring the tool for other environments most likely requires editing the source code.

## Setting up

Gcc is required. Note that this has only been tested on windows.

On Command Prompt:

1. Clone this repository:
  ```bash
  git clone https://github.com/jaakkomaenpaa/light-manager.git
  ```
2. Rename config.txt.example -> config.txt and change its content to real data
    - WiZ IP address can be found on the WiZ mobile app
    - WiZ port is usually 38899 or 38900, according to https://cycling74.com/forums/controlling-wiz-wifi-led-rgb-lightbulbs
    - Tuya IP address can be found through your router's admin interface
    - Tuya device ID can be found on Tuya Developer Platform: Cloud -> Development -> *Project* -> Devices. Creating a project and adding devices may require reading Tuya's documentation
    - Tuya local key can be found via tuya-cli wizard: https://github.com/codetheweb/tuyapi/blob/master/docs/SETUP.md

3. Build
 ```bash
 build.bat
 ```

4. Run 
 ```bash
 lights.exe
 ```
   
## Commands

Shorthand commands inside braces.
- Print usage guide (h)
  ```bash
  help
  ```
- Exit program (q)
  ```bash
  quit
  ```
- Print current config (contents of config.txt) (c)
  ```bash
  config
  ```
- Change status of the Tuya light (tn | tf)
  ```bash
  tuya <on|off>
  ```
- Change status of the WiZ light (wn | wf)
  ```bash
  wiz <on|off>
  ```
- Change status of both lights (bn | bf)
  ```bash
  both <on|off>
  ```
- Set scene for Tuya light (ts 1 | 2..)
  ```bash
  tuya scene <1|2.. >
  ```
- Set scene for WiZ light (ws 1 | 2..)
  ```bash
  wiz scene <1|2..>
  ```
- Set scene for both lights (bs 1 | 2..)
  ```bash
  both scene <1|2..>
  ```
