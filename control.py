import tinytuya
import sys

def turn_on(device):
    try:
        device.set_status(True, 20, nowait=True) 
    except Exception as e:
        print("Failed to turn on:", e)

def turn_off(device):
    try:
        device.set_status(False, 20, nowait=True)
    except Exception as e:
        print("Failed to turn off:", e)

def set_colour(device, r, g, b):
    device.set_colour(r, g, b, nowait=True)
    device.set_status(True, 20, nowait=True) 

def main():
    if len(sys.argv) < 5:
        print("Usage: python control.py <id> <ip> <key> <command> ")
        sys.exit(1)

    device_id = sys.argv[1]
    device_ip = sys.argv[2]
    local_key = sys.argv[3]
    command = sys.argv[4]

    d = tinytuya.BulbDevice(device_id, device_ip, local_key)
    d.set_version(3.4)

    baseCmd = command.split(" ")[0]

    if baseCmd == 'on':
        turn_on(d)
    elif baseCmd == 'off':
        turn_off(d)
    elif baseCmd == 'scene':
        colors = command.split(" ")[1:]
        r = int(colors[0])
        g = int(colors[1])
        b = int(colors[2])
        set_colour(d, r, g, b)
    else:
        print("Unknown command:", command)

if __name__ == "__main__":
    main()

    