# Commands to create UTS Namespace
In your first terminal:
```
uname -n
sudo ushare -u /bin/bash
uname -n
sudo hostname ubuntu.example.com
uname -n
echo $$
```
In the second terminal:
```
uname -n
sudo nsenter -t <PID> -u /bin/bash
uname -n
```
